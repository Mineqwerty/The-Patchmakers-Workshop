#include "sm64.h"
#include "game_init.h"
#include "archipelago.h"
#include "area.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "save_file.h"
#include "puppyprint.h"
#include "randomizer.h"

// Aligned so the header starts on a word boundary, which is what the client's search assumes.
volatile u32 gArchipelagoBuffer[AP_END] __attribute__((aligned(16)));
u32 gArchipelagoLastLocationChecked = 0;

// The header, with every character shifted up by one. Storing it plainly would put a second
// copy of "TPW AP BUFFER   " in RAM (this string's own data), and the client gives up when it
// finds more than one match.
static const char sHeaderShifted[16] = "UQX!BQ!CVGGFS!!!";

// Checks waiting for the client. AP_SEND_LOCATION only holds one at a time and the client
// only polls it every 0.1s, so anything collected faster than that waits here.
#define AP_LOCATION_QUEUE_SIZE 32
static u16 sLocationQueue[AP_LOCATION_QUEUE_SIZE];
static u8 sLocationQueueHead = 0;
static u8 sLocationQueueCount = 0;

_Static_assert(AP_WARP_MAP_END - AP_WARP_MAP == WARPS_END, "AP_WARP_MAP must hold one word per LogicWarpEntrances entry");

void archipelago_init(void) {
    volatile char *header = (volatile char *) gArchipelagoBuffer;

    for (s32 i = 0; i < AP_END; i++) {
        gArchipelagoBuffer[i] = 0;
    }
    for (s32 i = 0; i < 16; i++) {
        header[i] = sHeaderShifted[i] - 1;
    }
}

s32 archipelago_found_client(void) {
    return gArchipelagoBuffer[AP_FOUND_CLIENT] != 0;
}

s32 archipelago_connected(void) {
    return gArchipelagoBuffer[AP_CONNECTED] != 0;
}

s32 archipelago_star_count(void) {
    return gArchipelagoBuffer[AP_STAR_TOTAL];
}


s32 archipelago_option(s32 word, s32 notConnected) {
    if (!archipelago_connected()) {
        return notConnected;
    }
    return gArchipelagoBuffer[word];
}


s32 archipelago_final_act_unlocked(s32 finalActItem) {
    if (archipelago_option(AP_FINAL_ACT_ITEMS, FALSE)) {
        return archipelago_item_unlocked(finalActItem) != 0;
    }
    return gCurrActNum == 6;
}


s32 archipelago_final_act_closed_this_visit(void) {
    return !archipelago_option(AP_FINAL_ACT_ITEMS, FALSE) && gCurrActNum != 6;
}

// Whether Trial of Life 1-5 have all been received (AP_TS_LOCKBOX_KEY_STATIC_ONLY).
s32 archipelago_has_all_trials_of_life(void) {
    for (s32 n = 1; n <= AP_ITEM_TRIAL_COUNT; n++) {
        if (!archipelago_item_unlocked(AP_ITEM_TRIAL_OF_LIFE(n))) {
            return FALSE;
        }
    }
    return TRUE;
}

// Send Location
void archipelago_check_location(int id) {
    gArchipelagoLastLocationChecked = id;

    if (sLocationQueueCount < AP_LOCATION_QUEUE_SIZE) {
        sLocationQueue[(sLocationQueueHead + sLocationQueueCount) % AP_LOCATION_QUEUE_SIZE] = id;
        sLocationQueueCount++;
    }
}

static void archipelago_flush_location_queue(void) {
    if (sLocationQueueCount > 0 && gArchipelagoBuffer[AP_SEND_LOCATION] == 0) {
        gArchipelagoBuffer[AP_SEND_LOCATION] = sLocationQueue[sLocationQueueHead];
        sLocationQueueHead = (sLocationQueueHead + 1) % AP_LOCATION_QUEUE_SIZE;
        sLocationQueueCount--;
    }
}

// The client sets bit (id - 1) for item id.
u32 archipelago_item_unlocked(int id) {
    int slot = (id - 1) / 32;
    int bit = (id - 1) % 32;
    return (gArchipelagoBuffer[AP_ITEMS + slot] & (1 << bit));
}

// Check Location
u32 archipelago_location_checked(int id) {
    int slot = id / 32;
    int bit = id % 32;
    return (gArchipelagoBuffer[AP_LOCATIONS_CHECKED + slot] & (1 << bit));
}

/**
 * Asks the client which model to show for the item at location id. Returns 0 until the
 * answer arrives, then the client's model number (see name_to_model_id in mitm_client.py).
 * Only one request can be in flight; other callers get 0 until it's answered.
 */
s32 archipelago_request_model_id(int id) {
    if (gArchipelagoBuffer[AP_REQUEST_MODEL_ID] == 0) {
        gArchipelagoBuffer[AP_RETURN_MODEL_ID] = 0;
        gArchipelagoBuffer[AP_REQUEST_MODEL_ID] = id;
        return 0;
    }

    if (gArchipelagoBuffer[AP_REQUEST_MODEL_ID] != (u32) id || gArchipelagoBuffer[AP_RETURN_MODEL_ID] == 0) {
        return 0;
    }

    s32 model = gArchipelagoBuffer[AP_RETURN_MODEL_ID];
    gArchipelagoBuffer[AP_REQUEST_MODEL_ID] = 0;
    gArchipelagoBuffer[AP_RETURN_MODEL_ID] = 0;
    return model;
}


static void archipelago_apply_items(void) {
    s32 fileIndex = gCurrSaveFileNum - 1;

    // Item k (PATCH_* value k) arrives as bit k - 1; patchFlags wants it at bit k.
    u16 patchFlags = (gArchipelagoBuffer[AP_ITEMS] & ((1 << AP_ITEM_PATCH_COUNT) - 1)) << 1;
    if ((save_file_get_patch_flags(fileIndex) & patchFlags) != patchFlags) {
        save_file_set_patch_flags(fileIndex, patchFlags);
    }

    if (archipelago_item_unlocked(AP_ITEM_LOCKBOX_KEY) && !(save_file_get_flags() & SAVE_FLAG_HAVE_LOCKBOX_KEY)) {
        save_file_set_flags(SAVE_FLAG_HAVE_LOCKBOX_KEY);
    }
}


static void archipelago_update_warps(void) {
    if (archipelago_connected() && gArchipelagoBuffer[AP_WARP_RANDOMIZATION] != AP_WARPS_VANILLA) {
        for (s32 entrance = 1; entrance < WARPS_END; entrance++) {
            u32 destination = gArchipelagoBuffer[AP_WARP_MAP + entrance];
            shuffledWarps[entrance] = vanillaWarpGoals[destination < WARPS_END ? destination : (u32) entrance];
        }
        gWarpShuffleActive = TRUE;
    } else if (gWarpShuffleActive) {
        reset_warp_goals();
    }
}

void archipelago_update(void) {
    if (!archipelago_found_client()) {
        return;
    }

    archipelago_update_warps();

    // Only touch the save once a file is loaded and we're in gameplay, not the file select.
    if (archipelago_connected() && gMarioObject != NULL && gCurrLevelNum != LEVEL_NEW_FILE_SELECT) {
        archipelago_apply_items();
    }

    archipelago_flush_location_queue();

    if (gArchipelagoBuffer[AP_TEXT_TIMER] > 0) {
        gArchipelagoBuffer[AP_TEXT_TIMER]--;
    }
}

void archipelago_render_message(void) {
    if (gArchipelagoBuffer[AP_TEXT_TIMER] == 0) {
        return;
    }

    // Copy out of the buffer so the string is always terminated, even mid-write by the client.
    char message[(AP_MESSAGE_END - AP_MESSAGE) * 4 + 1];
    volatile char *src = (volatile char *) &gArchipelagoBuffer[AP_MESSAGE];
    for (s32 i = 0; i < (s32) sizeof(message) - 1; i++) {
        message[i] = src[i];
    }
    message[sizeof(message) - 1] = '\0';

    print_set_envcolour(0, 0, 0, 255);
    print_small_text(SCREEN_CENTER_X + 1, 201, message, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
    print_set_envcolour(255, 255, 255, 255);
    print_small_text(SCREEN_CENTER_X, 200, message, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
}

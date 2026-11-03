#include "sm64.h"
#include "game_init.h"
#include "archipelago.h"
#include "area.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "save_file.h"
#include "puppyprint.h"
#include "randomizer.h"
#include "cutscene.h"
#include "course_table.h"
#include "ingame_menu.h"

// Aligned so the header starts on a word boundary, which is what the client's search assumes.
volatile u32 gArchipelagoBuffer[AP_END] __attribute__((aligned(16)));
u32 gArchipelagoLastLocationChecked = 0;

// The header, with every character shifted up by one. Storing it plainly would put a second
// copy of "TPW AP BUFFER   " in RAM (this string's own data), and the client gives up when it
// finds more than one match.
static const char sHeaderShifted[16] = "UQX!!BQ!CVGGFS!!";

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

/**
 * Coins Mario starts a main course with: 10 for each "10 Starting Coins" received. Capped just under the 100 coin
 * star's threshold, since that star spawns when the count crosses it.
 */
s32 archipelago_starting_coins(void) {
    if (!archipelago_connected() || !COURSE_IS_MAIN_COURSE(gCurrCourseNum)) {
        return 0;
    }

    s32 coins = gArchipelagoBuffer[AP_STARTING_COINS] * 10;
    if (coins > X_COIN_STAR - 1) {
        coins = X_COIN_STAR - 1;
    }
    return coins;
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

/**
 * Bit in the save's apOtherChecks for a check that leaves nothing else in the save (stars have their star flags),
 * or -1 for one that does: patch pickups 0-11, Lockbox Key 12, Patchmaker 1/2 13/14.
 */
static s32 other_check_bit(int id) {
    if (id >= AP_LOC_PATCH_PICKUP(1) && id <= AP_LOC_PATCH_PICKUP(AP_ITEM_PATCH_COUNT)) {
        return id - AP_LOC_PATCH_PICKUP(1);
    }
    switch (id) {
        case AP_LOC_LOCKBOX_KEY:  return 12;
        case AP_LOC_PATCHMAKER_1: return 13;
        case AP_LOC_PATCHMAKER_2: return 14;
        default:                  return -1;
    }
}

// Send Location
void archipelago_check_location(int id) {
    gArchipelagoLastLocationChecked = id;

    // Remember it in the save so it can be sent again later if the client misses it
    s32 bit = other_check_bit(id);
    if (bit >= 0 && gCurrSaveFileNum > 0) {
        save_file_set_ap_other_checks(gCurrSaveFileNum - 1, 1 << bit);
        save_file_do_save(gCurrSaveFileNum - 1);
    }

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

/**
 * Publishes every location the current save file has collected in AP_LOCATIONS_COLLECTED, so the client can send
 * any the server is missing: checks made before connecting, during a client restart, or that overflowed the send
 * queue. Stars come from the save's star flags; everything else from its apOtherChecks.
 */
static void archipelago_publish_collected_locations(void) {
    u32 collected[AP_LOCATIONS_COLLECTED_END - AP_LOCATIONS_COLLECTED] = { 0 };
    s32 fileIndex = gCurrSaveFileNum - 1;

#define MARK_COLLECTED(id) collected[(id) / 32] |= (1 << ((id) % 32))

    // Course stars: course star flags, bit = star index
    for (s32 course = COURSE_BOB; course <= COURSE_TTM; course++) {
        u32 flags = save_file_get_star_flags(fileIndex, COURSE_NUM_TO_INDEX(course));
        for (s32 star = 0; star < 7; star++) {
            if (flags & (1 << star)) {
                MARK_COLLECTED(AP_LOC_COURSE_STAR(courseToOrderedIndex[course] - 1, star));
            }
        }
    }

    // Secret stars: saved the way save_file_collect_star_or_key does, from COURSE_COTMC on
    for (s32 starIndex = 9; starIndex < 9 + 24; starIndex++) {
        if (save_file_get_star_flags(fileIndex, COURSE_NUM_TO_INDEX(COURSE_COTMC + (starIndex / 7))) & (1 << (starIndex % 7))) {
            MARK_COLLECTED(AP_LOC_SECRET_STAR(starIndex));
        }
    }

    // Patch challenges: challenge k is LEVEL_PSS area k with star index k - 1, saved from COURSE_BITS on
    for (s32 challenge = 1; challenge <= AP_ITEM_PATCH_COUNT; challenge++) {
        s32 starIndex = challenge - 1;
        if (save_file_get_star_flags(fileIndex, COURSE_NUM_TO_INDEX(COURSE_BITS + (starIndex / 7))) & (1 << (starIndex % 7))) {
            MARK_COLLECTED(AP_LOC_PATCH_CHALLENGE(challenge));
        }
    }

    // Patch pickups, Lockbox Key, Patchmakers
    u32 otherChecks = save_file_get_ap_other_checks(fileIndex);
    for (s32 patch = 1; patch <= AP_ITEM_PATCH_COUNT; patch++) {
        if (otherChecks & (1 << other_check_bit(AP_LOC_PATCH_PICKUP(patch)))) {
            MARK_COLLECTED(AP_LOC_PATCH_PICKUP(patch));
        }
    }
    if (otherChecks & (1 << other_check_bit(AP_LOC_LOCKBOX_KEY))) {
        MARK_COLLECTED(AP_LOC_LOCKBOX_KEY);
    }
    if (otherChecks & (1 << other_check_bit(AP_LOC_PATCHMAKER_1))) {
        MARK_COLLECTED(AP_LOC_PATCHMAKER_1);
    }
    if (otherChecks & (1 << other_check_bit(AP_LOC_PATCHMAKER_2))) {
        MARK_COLLECTED(AP_LOC_PATCHMAKER_2);
    }

#undef MARK_COLLECTED

    for (s32 i = 0; i < AP_LOCATIONS_COLLECTED_END - AP_LOCATIONS_COLLECTED; i++) {
        gArchipelagoBuffer[AP_LOCATIONS_COLLECTED + i] = collected[i];
    }
}

// Set while Mario is dying because of a received DeathLink, so that death isn't sent back out.
static s32 sDyingFromDeathLink = FALSE;

/**
 * Kills Mario when another DeathLink player died. Waits while Mario isn't in normal gameplay (story cutscenes,
 * cutscene actions like doors and star dances, patch challenges) and applies it once he is. If he's already
 * dying, that death covers it.
 */
static void archipelago_apply_deathlink(void) {
    if (!gArchipelagoBuffer[AP_DEATHLINK_RECEIVED]) {
        return;
    }

    if (gMarioState->health < 0x100) {
        gArchipelagoBuffer[AP_DEATHLINK_RECEIVED] = 0;
        return;
    }

    if (cCutsceneActive || gCurrLevelNum == LEVEL_PSS
        || (gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_CUTSCENE) {
        return;
    }

    gArchipelagoBuffer[AP_DEATHLINK_RECEIVED] = 0;
    sDyingFromDeathLink = TRUE;
    // Mario's actions start the right death (standing, airborne, underwater...) once health is below 0x100
    gMarioState->health = 0xFF;
}

/**
 * Called by level_trigger_warp for every death warp. Tells the client to send the death to the other DeathLink
 * players, unless a received DeathLink caused it or it happened in a patch challenge.
 */
void archipelago_on_death(void) {
    if (sDyingFromDeathLink) {
        sDyingFromDeathLink = FALSE;
        return;
    }

    // Failing a patch challenge isn't a real death, so it doesn't count for DeathLink either way
    if (archipelago_connected() && gCurrLevelNum != LEVEL_PSS) {
        gArchipelagoBuffer[AP_DEATHLINK_SEND] = 1;
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
        // The game only refreshes numStars when a star is touched or Mario loads, which is before the server
        // sends that star back. Keep it on the AP total so the HUD and star doors see new stars right away.
        gMarioState->numStars = archipelago_star_count();
        archipelago_apply_deathlink();
        archipelago_publish_collected_locations();
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

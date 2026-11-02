#ifndef ARCHIPELAGO_H
#define ARCHIPELAGO_H

#include "types.h"

// Word offsets into gArchipelagoBuffer. These must match mitm_client.py in the AP world,
// which finds the buffer by searching emulator RAM for the header and then reads/writes
// archipelago_buffer_start + 4 * offset.
enum ArchipelagoBufferWords {
    AP_HEADER_1          = 0,  // "TPW AP BUFFER   ", written by archipelago_init
    AP_HEADER_2          = 1,
    AP_HEADER_3          = 2,
    AP_HEADER_4          = 3,
    AP_FOUND_CLIENT      = 4,  // client -> game: 1 once the client has found the buffer
    AP_CONNECTED         = 5,  // client -> game: 1 once the server accepted the slot

    AP_SEND_LOCATION     = 6,  // game -> client: location ID to send; client sets it back to 0

    AP_STAR_TOTAL        = 7,  // client -> game: stars received (Power Stars, Trial of Life and final act items)

    AP_MESSAGE           = 8,  // client -> game: "Got X from Y" text, up to 45 chars
    AP_MESSAGE_END       = 20,

    AP_ITEMS             = 20, // client -> game: bit (id - 1) set for every item received
    AP_ITEMS_END         = 22,

    AP_TEXT_TIMER        = 22, // client -> game: frames to show AP_MESSAGE for
    AP_LOCATIONS_CHECKED = 23, // client -> game: bit (id) set for every location the server has
    AP_LOCATIONS_CHECKED_END = 31,
    AP_REQUEST_MODEL_ID  = 31, // game -> client: location ID to look up
    AP_RETURN_MODEL_ID   = 32, // client -> game: model for the item at AP_REQUEST_MODEL_ID
    AP_GAME_CLEARED       = 33, // game -> client: 1 when the goal is complete

    AP_50_COIN_PACK      = 34, // client -> game: "10 Starting Coins" filler items received (AP_ITEM_50_COINS)
    AP_TS_COMPLETION     = 35, // client -> game: Timeless Shrine Completion option, see enum ArchipelagoTSCompletion

    AP_REQUEST_ITEM_NAME = 36, // game -> client: location ID to look up
    AP_ITEM_NAME         = 37, // client -> game: "Player's Item" text, up to 45 chars
    AP_ITEM_NAME_END     = 49, // exclusive: word 49 is AP_FINAL_ACT_ITEMS

    AP_FINAL_ACT_ITEMS   = 49, // client -> game: Final Act Items option (0 vanilla final acts, 1 final act checks)

    AP_WARP_RANDOMIZATION = 50, // client -> game: Warp Randomizer option, see enum ArchipelagoWarpRandomization
    AP_WARP_MAP          = 51, // client -> game: word AP_WARP_MAP + entrance = destination, both LogicWarpEntrances
    AP_WARP_MAP_END      = 51 + 55, // 55 = WARPS_END, checked in archipelago.c

    AP_SKIP_STORY        = 106, // client -> game: Skip Story Content option (1 skips story cutscenes)

    AP_END,
};

// Values of AP_WARP_RANDOMIZATION, from WarpRandomizer in Options.py. Anything but vanilla means
// AP_WARP_MAP is filled in.
enum ArchipelagoWarpRandomization {
    AP_WARPS_VANILLA        = 0,
    AP_WARPS_STAGE_ENTRANCES = 1, // only the hub warps into courses are shuffled
    AP_WARPS_FULL           = 2, // everything but the GSS graveyard, including hubs and bosses
};

// Values of AP_TS_COMPLETION, from TimelessShrineCompletion in Options.py.
enum ArchipelagoTSCompletion {
    AP_TS_LOCKBOX_KEY_STATIC_ONLY      = 0, // Final Stretch opens once Trial of Life 1-5 are all received
    AP_TS_LOCKBOX_KEY_AND_TRIALS_STATIC = 1, // Final Stretch opens once the five Trials are cleared locally
    AP_TS_LOCKBOX_KEY_SHUFFLE          = 2, // Same as above; the Lockbox Key itself is shuffled
};

// Item IDs, from Items.py. Patches use their PATCH_* value (PATCH_STONE = 1 ... PATCH_SKYBRIDGE = 12).
#define AP_ITEM_PATCH_COUNT  12
#define AP_ITEM_LOCKBOX_KEY  13
// Trial of Life 1-5 (only in AP_TS_LOCKBOX_KEY_STATIC_ONLY). They also count toward AP_STAR_TOTAL.
#define AP_ITEM_TRIAL_OF_LIFE(n) (14 + (n) - 1)
#define AP_ITEM_TRIAL_COUNT  5
#define AP_ITEM_POWER_STAR   20
#define AP_ITEM_50_COINS     21 // "10 Starting Coins" filler
// Final act items (only with AP_FINAL_ACT_ITEMS on). Each unlocks that course's final act content and also
// counts toward AP_STAR_TOTAL.
#define AP_ITEM_PUSHPIN_POKEY_SPAWNER      22 // Thorn Thicket Cliffs
#define AP_ITEM_CLOCK_TOWER_BRIDGE         23 // Stone Terrace City
#define AP_ITEM_AURUMCAEL_PALACE_PATH      24 // Gold Soaked Sky
#define AP_ITEM_PATH_TO_MASTER_DOOR_UNLOCK 25 // Candlelit Chamber
#define AP_ITEM_XODORAP_ARENA_ENTRANCE     26 // Empyrean Abyss
#define AP_ITEM_BURIED_CITY_GATE_OPEN      27 // City of Reconstructed Ruin

// Location IDs, from Locations.py.
// course is the display order index (courseToOrderedIndex - 1), star is 0-6 (6 is 100 coins).
#define AP_LOC_COURSE_STAR(course, star)  (1 + (course) * 7 + (star))
// starIndex is the in-game star index, starting at 9.
#define AP_LOC_SECRET_STAR(starIndex)     (101 + (starIndex) - 9)
// patch is the PATCH_* value.
#define AP_LOC_PATCH_CHALLENGE(patch)     (131 + (patch) - 1)
#define AP_LOC_PATCH_PICKUP(patch)        (151 + (patch) - 1)
#define AP_LOC_LOCKBOX_KEY                170
#define AP_LOC_PATCHMAKER_1              171
#define AP_LOC_PATCHMAKER_2                172

void archipelago_init(void);
void archipelago_update(void);
void archipelago_render_message(void);

s32 archipelago_found_client(void);
s32 archipelago_connected(void);
s32 archipelago_star_count(void);
s32 archipelago_option(s32 word, s32 notConnected);
s32 archipelago_has_all_trials_of_life(void);
s32 archipelago_final_act_unlocked(s32 finalActItem);
s32 archipelago_final_act_closed_this_visit(void);

void archipelago_check_location(int id);
u32 archipelago_item_unlocked(int id);
u32 archipelago_location_checked(int id);
s32 archipelago_request_model_id(int id);

extern volatile u32 gArchipelagoBuffer[];
extern u32 gArchipelagoLastLocationChecked;

#endif

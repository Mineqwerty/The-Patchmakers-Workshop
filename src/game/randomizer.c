#include "types.h"
#include "src/game/randomizer.h"
#include "include/level_table.h"
#include <stdio.h>


const WarpGoal vanillaWarpGoals[] = {
    [WARP_ENTRANCE_NONE]                    = WARP_PAIR(LEVEL_NONE, 0),
    [WARP_ENTRANCE_STAGE_TTC]               = WARP_PAIR(LEVEL_BOB, 1),
    [WARP_ENTRANCE_TTC_STONE_PATCH]         = WARP_PAIR(LEVEL_BOB, 2),
    [WARP_ENTRANCE_TTC_WELL]                = WARP_PAIR(LEVEL_BOB, 3),
    [WARP_ENTRANCE_STAGE_RDR]               = WARP_PAIR(LEVEL_WF, 1),
    [WARP_ENTRANCE_RDR_CHILLSTEP_PATCH]     = WARP_PAIR(LEVEL_WF, 2),
    [WARP_ENTRANCE_RDR_MUDSLIDE]            = WARP_PAIR(LEVEL_WF, 3),
    [WARP_ENTRANCE_STAGE_STC]               = WARP_PAIR(LEVEL_JRB, 1),
    [WARP_ENTRANCE_STC_GRAPPLE_PATCH]       = WARP_PAIR(LEVEL_JRB, 2),
    [WARP_ENTRANCE_STC_CLOCK_TOWER]         = WARP_PAIR(LEVEL_JRB, 3),
    [WARP_ENTRANCE_STAGE_GSS]               = WARP_PAIR(LEVEL_CCM, 1),
    [WARP_ENTRANCE_GSS_GRAVEYARD]           = WARP_PAIR(LEVEL_CCM, 2),
    [WARP_ENTRANCE_GSS_HALO_PATCH]          = WARP_PAIR(LEVEL_CCM, 3),
    [WARP_ENTRANCE_GSS_AURUMCAEL]           = WARP_PAIR(LEVEL_CCM, 4),
    [WARP_ENTRANCE_STAGE_SS]                = WARP_PAIR(LEVEL_HMC, 1),
    [WARP_ENTRANCE_SS_MARINE_PATCH]         = WARP_PAIR(LEVEL_HMC, 2),
    [WARP_ENTRANCE_SS_WATERFALLS]           = WARP_PAIR(LEVEL_HMC, 3),
    [WARP_ENTRANCE_STAGE_CLC]               = WARP_PAIR(LEVEL_LLL, 1),
    [WARP_ENTRANCE_CLC_SHADOWCHOMP_PATCH]   = WARP_PAIR(LEVEL_LLL, 2),
    [WARP_ENTRANCE_CLC_MISTRESS_AREA]       = WARP_PAIR(LEVEL_LLL, 3),
    [WARP_ENTRANCE_CLC_MASTER_PATH]         = WARP_PAIR(LEVEL_LLL, 4),
    [WARP_ENTRANCE_CLC_MASTER_CHAMBER]      = WARP_PAIR(LEVEL_LLL, 5),
    [WARP_ENTRANCE_STAGE_HVH]               = WARP_PAIR(LEVEL_DDD, 1),
    [WARP_ENTRANCE_HVH_TRANSMUTATION_PATCH] = WARP_PAIR(LEVEL_DDD, 2),
    [WARP_ENTRANCE_HVH_WINDMILLS]           = WARP_PAIR(LEVEL_DDD, 3),
    [WARP_ENTRANCE_HVH_CASTLE]              = WARP_PAIR(LEVEL_DDD, 4),
    [WARP_ENTRANCE_HVH_DEMONIC_SOLIDS]      = WARP_PAIR(LEVEL_DDD, 5),
    [WARP_ENTRANCE_STAGE_VTW]               = WARP_PAIR(LEVEL_SSL, 1),
    [WARP_ENTRANCE_VTW_BREEZE_PATCH]        = WARP_PAIR(LEVEL_SSL, 2),
    [WARP_ENTRANCE_VTW_BOOK_SECRET]         = WARP_PAIR(LEVEL_SSL, 4),
    [WARP_ENTRANCE_VTW_TREETOPS]            = WARP_PAIR(LEVEL_SSL, 3),
    [WARP_ENTRANCE_STAGE_TFP]               = WARP_PAIR(LEVEL_BBH, 1),
    [WARP_ENTRANCE_TFP_PORTAL_PATCH]        = WARP_PAIR(LEVEL_BBH, 2),
    [WARP_ENTRANCE_TFP_SHADOWCHOMP_SECRET]  = WARP_PAIR(LEVEL_BBH, 5),
    [WARP_ENTRANCE_TFP_ENDLESS_PIT]         = WARP_PAIR(LEVEL_BBH, 3),
    [WARP_ENTRANCE_TFP_EDGE_OF_REALITY]     = WARP_PAIR(LEVEL_BBH, 4),
    [WARP_ENTRANCE_STAGE_EA]                = WARP_PAIR(LEVEL_SL, 1),
    [WARP_ENTRANCE_EA_MIASMA_PATCH]         = WARP_PAIR(LEVEL_SL, 2),
    [WARP_ENTRANCE_EA_TENTACLE_AREA]        = WARP_PAIR(LEVEL_SL, 3),
    [WARP_ENTRANCE_EA_SKY_SLUG_AREA]        = WARP_PAIR(LEVEL_SL, 4),
    [WARP_ENTRANCE_EA_XODORAP]              = WARP_PAIR(LEVEL_SL, 5),
    [WARP_ENTRANCE_STAGE_CORR]              = WARP_PAIR(LEVEL_WDW, 1),
    [WARP_ENTRANCE_CORR_EXTENSION_PATCH]    = WARP_PAIR(LEVEL_WDW, 2),
    [WARP_ENTRANCE_CORR_ORANGE_BUILDING]    = WARP_PAIR(LEVEL_WDW, 4),
    [WARP_ENTRANCE_CORR_UNDERGROUND]        = WARP_PAIR(LEVEL_WDW, 3),
    [WARP_ENTRANCE_STAGE_TS]                = WARP_PAIR(LEVEL_TTM, 1),
    [WARP_ENTRANCE_TS_FINAL_STRETCH]        = WARP_PAIR(LEVEL_TTM, 2),
    [WARP_ENTRANCE_HUB_2]                   = WARP_PAIR(LEVEL_CASTLE, 2),
    [WARP_ENTRANCE_HUB_3]                   = WARP_PAIR(LEVEL_CASTLE, 3),
    [WARP_ENTRANCE_WORKSHOP_1]              = WARP_PAIR(LEVEL_BITDW, 1),
    [WARP_ENTRANCE_WORKSHOP_2]              = WARP_PAIR(LEVEL_BITFS, 1),
    [WARP_ENTRANCE_THE_BRINK]               = WARP_PAIR(LEVEL_BITS, 1),
    [WARP_ENTRANCE_PM_1]                    = WARP_PAIR(LEVEL_BOWSER_1, 1),
    [WARP_ENTRANCE_PM_2]                    = WARP_PAIR(LEVEL_BOWSER_2, 1),
    [WARP_ENTRANCE_MANTLE_OF_MADNESS]       = WARP_PAIR(LEVEL_BOWSER_3, 2)
};

const u32 reachWarpLogic[] = {
    [WARP_ENTRANCE_NONE]                    = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STAGE_TTC]               = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_TTC_STONE_PATCH]         = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_TTC_WELL]                = LOGIC_PATCH_STONE,
    [WARP_ENTRANCE_STAGE_RDR]               = LOGIC_KEY_STAR_COUNT,
    [WARP_ENTRANCE_RDR_CHILLSTEP_PATCH]     = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_RDR_MUDSLIDE]            = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STAGE_STC]               = LOGIC_KEY_STAR_COUNT,
    [WARP_ENTRANCE_STC_GRAPPLE_PATCH]       = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STC_CLOCK_TOWER]         = LOGIC_KEY_FINAL_ACT,
    [WARP_ENTRANCE_STAGE_GSS]               = LOGIC_KEY_STAR_COUNT,
    [WARP_ENTRANCE_GSS_GRAVEYARD]           = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_GSS_HALO_PATCH]          = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_GSS_AURUMCAEL]           = LOGIC_KEY_FINAL_ACT,
    [WARP_ENTRANCE_STAGE_SS]                = LOGIC_KEY_IN_HUB_2,
    [WARP_ENTRANCE_SS_MARINE_PATCH]         = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_SS_WATERFALLS]           = (LOGIC_PATCH_MARINE | LOGIC_PATCH_STONE),
    [WARP_ENTRANCE_STAGE_CLC]               = (LOGIC_KEY_IN_HUB_2 | LOGIC_KEY_STAR_COUNT),
    [WARP_ENTRANCE_CLC_SHADOWCHOMP_PATCH]   = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_CLC_MISTRESS_AREA]       = LOGIC_PATCH_SHADOWCHOMP,
    [WARP_ENTRANCE_CLC_MASTER_PATH]         = (LOGIC_KEY_FINAL_ACT),
    [WARP_ENTRANCE_CLC_MASTER_CHAMBER]      = (LOGIC_PATCH_SHADOWCHOMP),
    [WARP_ENTRANCE_STAGE_HVH]               = (LOGIC_KEY_IN_HUB_2 | LOGIC_KEY_STAR_COUNT),
    [WARP_ENTRANCE_HVH_TRANSMUTATION_PATCH] = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_HVH_WINDMILLS]           = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_HVH_CASTLE]              = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_HVH_DEMONIC_SOLIDS]      = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STAGE_VTW]               = (LOGIC_KEY_IN_HUB_2 | LOGIC_KEY_STAR_COUNT),
    [WARP_ENTRANCE_VTW_BREEZE_PATCH]        = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_VTW_BOOK_SECRET]         = LOGIC_PATCH_BREEZE,
    [WARP_ENTRANCE_VTW_TREETOPS]            = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STAGE_TFP]               = LOGIC_KEY_IN_HUB_3,
    [WARP_ENTRANCE_TFP_PORTAL_PATCH]        = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_TFP_SHADOWCHOMP_SECRET]  = LOGIC_PATCH_SHADOWCHOMP,
    [WARP_ENTRANCE_TFP_ENDLESS_PIT]         = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_TFP_EDGE_OF_REALITY]     = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_STAGE_EA]                = LOGIC_KEY_IN_HUB_3,
    [WARP_ENTRANCE_EA_MIASMA_PATCH]         = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_EA_TENTACLE_AREA]        = LOGIC_PATCH_STONE,
    [WARP_ENTRANCE_EA_SKY_SLUG_AREA]        = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_EA_XODORAP]              = LOGIC_KEY_FINAL_ACT,
    [WARP_ENTRANCE_STAGE_CORR]              = (LOGIC_KEY_IN_HUB_3 | LOGIC_KEY_STAR_COUNT),
    [WARP_ENTRANCE_CORR_EXTENSION_PATCH]    = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_CORR_ORANGE_BUILDING]    = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_CORR_UNDERGROUND]        = LOGIC_KEY_FINAL_ACT,
    [WARP_ENTRANCE_STAGE_TS]                = (LOGIC_KEY_IN_HUB_3 | LOGIC_KEY_STAR_COUNT),
    [WARP_ENTRANCE_TS_FINAL_STRETCH]        = LOGIC_KEY_TS_STARS,
    [WARP_ENTRANCE_HUB_2]                   = LOGIC_KEY_PM1_CLEAR,
    [WARP_ENTRANCE_HUB_3]                   = LOGIC_KEY_PM2_CLEAR,
    [WARP_ENTRANCE_WORKSHOP_1]              = LOGIC_KEY_STAR_COUNT,
    [WARP_ENTRANCE_WORKSHOP_2]              = (LOGIC_KEY_STAR_COUNT | LOGIC_KEY_IN_HUB_2),
    [WARP_ENTRANCE_THE_BRINK]               = (LOGIC_KEY_IN_HUB_3 | LOGIC_KEY_LOCKBOX),
    [WARP_ENTRANCE_PM_1]                    = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_PM_2]                    = LOGIC_KEY_NONE,
    [WARP_ENTRANCE_MANTLE_OF_MADNESS]       = LOGIC_KEY_NONE
};

const u32 starObtainLogic[][7] = {
    [0] = {LOGIC_KEY_NONE, LOGIC_PATCH_STONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_PATCH_STONE, (LOGIC_KEY_FINAL_ACT | LOGIC_PATCH_STONE), LOGIC_KEY_NONE}, //Thorn thicket cliffs (BOB)
    [1] = {LOGIC_KEY_NONE, (LOGIC_PATCH_CHILLSTEP | LOGIC_PATCH_MARINE | LOGIC_PATCH_GRAPPLE | LOGIC_PATCH_SHADOWCHOMP | LOGIC_PATCH_SKYBRIDGE), LOGIC_KEY_NONE, (LOGIC_PATCH_CHILLSTEP | LOGIC_PATCH_EXTENSION | LOGIC_PATCH_SKYBRIDGE), (LOGIC_PATCH_CHILLSTEP | LOGIC_PATCH_SKYBRIDGE), LOGIC_KEY_NONE, LOGIC_KEY_NONE}, //Rainy Day Roadside (WF)
    [2] = {LOGIC_KEY_NONE, LOGIC_KEY_NONE, (LOGIC_PATCH_GRAPPLE | LOGIC_PATCH_SHADOWCHOMP | LOGIC_PATCH_SKYBRIDGE | LOGIC_PATCH_BREEZE), LOGIC_KEY_NONE, (LOGIC_PATCH_GRAPPLE | LOGIC_PATCH_SKYBRIDGE), (LOGIC_KEY_FINAL_ACT), LOGIC_KEY_NONE}, //Stone Terrace City (JRB)
    [3] = {LOGIC_KEY_NONE, (LOGIC_PATCH_HALO), LOGIC_KEY_NONE, (LOGIC_PATCH_HALO | LOGIC_PATCH_TRANSMUTATION) ,LOGIC_KEY_NONE,  (LOGIC_PATCH_HALO | LOGIC_KEY_FINAL_ACT), LOGIC_KEY_NONE}, //Gold Soaked Sky (CCM)
    [4] = {LOGIC_KEY_NONE, (LOGIC_PATCH_MARINE), (LOGIC_PATCH_MARINE | LOGIC_PATCH_CHILLSTEP), (LOGIC_PATCH_MARINE | LOGIC_PATCH_STONE) ,(LOGIC_PATCH_MARINE | LOGIC_PATCH_STONE),  (LOGIC_PATCH_MARINE), LOGIC_KEY_NONE}, //Subterranean Seaway (SS)

    [0] = {LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE}, //Thorn thicket cliffs (BOB)
};

const u32 difficultStarObtainLogic[][7] = {
    [0] = {0, LOGIC_KEY_NO_PATCH_HARD, 0, 0, 0, 0, 0}, //Thorn thicket cliffs (BOB)
    [1] = {0, 0, 0, LOGIC_KEY_NO_PATCH_HARD, (LOGIC_PATCH_MARINE), 0, 0}, //Rainy Day Roadside (WF)
    [2] = {0, 0, LOGIC_KEY_NO_PATCH_HARD, 0, LOGIC_KEY_NO_PATCH_HARD, 0, 0}, //Stone Terrace City (JRB)
    [3] = {0, 0, 0, 0, 0, 0, 0}, //Gold Soaked Sky (CCM)
    [4] = {0, 0, 0, LOGIC_KEY_NO_PATCH_HARD, LOGIC_KEY_NO_PATCH_HARD, 0, 0}, //Subterranean Seaway (SS)
    
    [0] = {LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE, LOGIC_KEY_NONE}, //Thorn thicket cliffs (BOB)
};

const u8 vanillaWarpEntrances[] = {
    [WARP_ENTRANCE_NONE]                    = 0x0A,
    [WARP_ENTRANCE_STAGE_TTC]               = 0x0A, // bob/1   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TTC_STONE_PATCH]         = 0x0A, // bob/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TTC_WELL]                = 0x0A, // bob/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_RDR]               = 0x0A, // wf/1    bhvSpinAirborneWarp
    [WARP_ENTRANCE_RDR_CHILLSTEP_PATCH]     = 0x0A, // wf/2    bhvSpinAirborneWarp
    [WARP_ENTRANCE_RDR_MUDSLIDE]            = 0x0A, // wf/3    bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_STC]               = 0x0A, // jrb/1   bhvSpinAirborneWarp (0x0D is the clock tower return)
    [WARP_ENTRANCE_STC_GRAPPLE_PATCH]       = 0x0A, // jrb/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STC_CLOCK_TOWER]         = 0x0A, // jrb/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_GSS]               = 0x0A, // ccm/1   bhvSpinAirborneWarp (0x10/0x11 are star gate returns)
    [WARP_ENTRANCE_GSS_GRAVEYARD]           = 0x0A, // ccm/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_GSS_HALO_PATCH]          = 0x0A, // ccm/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_GSS_AURUMCAEL]           = 0x0A, // ccm/4   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_SS]                = 0x0A, // hmc/1   bhvSpinAirborneWarp (0x0D is the waterfalls return)
    [WARP_ENTRANCE_SS_MARINE_PATCH]         = 0x0A, // hmc/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_SS_WATERFALLS]           = 0x0A, // hmc/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_CLC]               = 0x0A, // lll/1   bhvSpinAirborneWarp (0x0E-0x11 are bhvClcDoorWarp pairs)
    [WARP_ENTRANCE_CLC_SHADOWCHOMP_PATCH]   = 0x0A, // lll/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_CLC_MISTRESS_AREA]       = 0x0A, // lll/3   bhvSpinAirborneWarp; doors 0x0E/0x0F are the normal way in
    [WARP_ENTRANCE_CLC_MASTER_PATH]         = 0x0A, // lll/4   bhvSpinAirborneWarp; doors 0x0E-0x11 are the normal way in
    [WARP_ENTRANCE_CLC_MASTER_CHAMBER]      = 0x0A, // lll/5   bhvAirborneWarp;     doors 0x10/0x11 are the normal way in
    [WARP_ENTRANCE_STAGE_HVH]               = 0x0A, // ddd/1   bhvSpinAirborneWarp  NOTE: two objects claim 0x0A, last spawned wins
    [WARP_ENTRANCE_HVH_TRANSMUTATION_PATCH] = 0x0A, // ddd/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_HVH_WINDMILLS]           = 0x0A, // ddd/3   bhvInstantActiveWarp
    [WARP_ENTRANCE_HVH_CASTLE]              = 0x0A, // ddd/4   bhvInstantActiveWarp (0x0F is the demonic solids return)
    [WARP_ENTRANCE_HVH_DEMONIC_SOLIDS]      = 0x0A, // ddd/5   bhvInstantActiveWarp
    [WARP_ENTRANCE_STAGE_VTW]               = 0x0A, // ssl/1   bhvSpinAirborneWarp
    [WARP_ENTRANCE_VTW_BREEZE_PATCH]        = 0x0A, // ssl/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_VTW_BOOK_SECRET]         = 0x0A, // ssl/4   bhvWarp
    [WARP_ENTRANCE_VTW_TREETOPS]            = 0x0A, // ssl/3   bhvWarp
    [WARP_ENTRANCE_STAGE_TFP]               = 0x0A, // bbh/1   bhvSpinAirborneWarp (0x0B is the bhvDoorWarp to bbh/4)
    [WARP_ENTRANCE_TFP_PORTAL_PATCH]        = 0x0A, // bbh/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TFP_SHADOWCHOMP_SECRET]  = 0x0A, // bbh/5   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TFP_ENDLESS_PIT]         = 0x0A, // bbh/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TFP_EDGE_OF_REALITY]     = 0x0A, // bbh/4   bhvSpinAirborneWarp (0x0B is the bhvDoorWarp to bbh/1)
    [WARP_ENTRANCE_STAGE_EA]                = 0x0A, // sl/1    bhvSpinAirborneWarp
    [WARP_ENTRANCE_EA_MIASMA_PATCH]         = 0x0A, // sl/2    bhvSpinAirborneWarp
    [WARP_ENTRANCE_EA_TENTACLE_AREA]        = 0x0A, // sl/3    bhvSpinAirborneWarp
    [WARP_ENTRANCE_EA_SKY_SLUG_AREA]        = 0x0A, // sl/4    bhvSpinAirborneWarp
    [WARP_ENTRANCE_EA_XODORAP]              = 0x0A, // sl/5    bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_CORR]              = 0x0A, // wdw/1   bhvSpinAirborneWarp
    [WARP_ENTRANCE_CORR_EXTENSION_PATCH]    = 0x0A, // wdw/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_CORR_ORANGE_BUILDING]    = 0x0A, // wdw/4   bhvSpinAirborneWarp
    [WARP_ENTRANCE_CORR_UNDERGROUND]        = 0x0A, // wdw/3   bhvSpinAirborneWarp
    [WARP_ENTRANCE_STAGE_TS]                = 0x0A, // ttm/1   bhvSpinAirborneWarp
    [WARP_ENTRANCE_TS_FINAL_STRETCH]        = 0x0A, // ttm/2   bhvSpinAirborneWarp
    [WARP_ENTRANCE_HUB_2]                   = 0x0A, // castle/2 bhvSpinAirborneWarp; 0x10 is the stairway door from hub 1
    [WARP_ENTRANCE_HUB_3]                   = 0x0A, // castle/3 bhvSpinAirborneWarp; 0x11 is the workshop door from hub 2
    [WARP_ENTRANCE_WORKSHOP_1]              = 0x0A, // bitdw/1  bhvSpinAirborneWarp
    [WARP_ENTRANCE_WORKSHOP_2]              = 0x0A, // bitfs/1  bhvSpinAirborneWarp
    [WARP_ENTRANCE_THE_BRINK]               = 0x0A, // bits/1   bhvSpinAirborneWarp
    [WARP_ENTRANCE_PM_1]                    = 0x0A, // bowser_1/1 bhvSpinAirborneWarp
    [WARP_ENTRANCE_PM_2]                    = 0x0A, // bowser_2/1 bhvSpinAirborneWarp
    [WARP_ENTRANCE_MANTLE_OF_MADNESS]       = 0x0A  // bowser_3/2 bhvSpinAirborneWarp
};

WarpGoal shuffledWarps[WARPS_END];

u16 find_warp_entrance(u8 target_level, u8 target_area) {
    int total_entries = sizeof(vanillaWarpGoals) / sizeof(vanillaWarpGoals[0]);
    
    for (int i = 0; i < total_entries; i++) {
        if (vanillaWarpGoals[i].level == target_level && 
            vanillaWarpGoals[i].area == target_area) {
            return i;
        }
    }
    
    return WARP_ENTRANCE_NONE; // Fallback if not found
}

/**
 * Entrance node for a shuffled destination. Falls back to 0x0A, which every
 * area in vanillaWarpGoals declares.
 */
u8 get_warp_entrance_node(u8 target_level, u8 target_area) {
    u16 index = find_warp_entrance(target_level, target_area);

    if (index == WARP_ENTRANCE_NONE) {
        return 0x0A;
    }

    return vanillaWarpEntrances[index];
}

static unsigned int get_next_random(unsigned int *seed) {
    *seed = (*seed * 1103515245U) + 12345U;
    return (*seed / 65536U) % 32768U;
}

/**
 * Locations held out of the shuffle. An excluded slot keeps its vanilla
 * destination and no other location can be shuffled onto it.
 */
static s32 warp_goal_is_shuffled(size_t index) {
    switch (index) {
        case WARP_ENTRANCE_NONE:           // not a real location
        case WARP_ENTRANCE_GSS_GRAVEYARD:  // only entered by falling from ccm/1
            return FALSE;
        default:
            return TRUE;
    }
}

void shuffle_warp_goals(u16 seed) {
    size_t total_entries = sizeof(vanillaWarpGoals) / sizeof(vanillaWarpGoals[0]);
    u8 pool[WARPS_END];
    size_t pool_count = 0;

    for (size_t i = 0; i < total_entries; i++) {
        shuffledWarps[i] = vanillaWarpGoals[i];

        if (warp_goal_is_shuffled(i)) {
            pool[pool_count++] = i;
        }
    }

    // Fisher-Yates over the pool only, so excluded slots are never read or written.
    unsigned int current_seed = seed;
    for (size_t i = pool_count - 1; i > 0; i--) {
        size_t j = get_next_random(&current_seed) % (i + 1);

        WarpGoal temp = shuffledWarps[pool[i]];
        shuffledWarps[pool[i]] = shuffledWarps[pool[j]];
        shuffledWarps[pool[j]] = temp;
    }
}
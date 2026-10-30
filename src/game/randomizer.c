#include "types.h"
#include "src/game/randomizer.h"
#include "include/level_table.h"


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
    [WARP_ENTRANCE_STAGE_TFP]               = WARP_PAIR(LEVEL_HMC, 1),
    [WARP_ENTRANCE_TFP_PORTAL_PATCH]        = WARP_PAIR(LEVEL_HMC, 2),
    [WARP_ENTRANCE_TFP_SHADOWCHOMP_SECRET]  = WARP_PAIR(LEVEL_HMC, 5),
    [WARP_ENTRANCE_TFP_ENDLESS_PIT]         = WARP_PAIR(LEVEL_HMC, 3),
    [WARP_ENTRANCE_TFP_EDGE_OF_REALITY]     = WARP_PAIR(LEVEL_HMC, 4),
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


#include <stdio.h>

static unsigned int get_next_random(unsigned int *seed) {
    *seed = (*seed * 1103515245U) + 12345U;
    return (*seed / 65536U) % 32768U;
}

void shuffle_warp_goals(u16 seed) {
    size_t total_entries = sizeof(vanillaWarpGoals) / sizeof(vanillaWarpGoals[0]);

    for (size_t i = 0; i < total_entries; i++) {
        shuffledWarps[i] = vanillaWarpGoals[i];
    }

    unsigned int current_seed = seed;
    for (size_t i = total_entries - 1; i > 0; i--) {
        size_t j = get_next_random(&current_seed) % (i + 1);
        
        WarpGoal temp = shuffledWarps[i];
        shuffledWarps[i] = shuffledWarps[j];
        shuffledWarps[j] = temp;
    }
}
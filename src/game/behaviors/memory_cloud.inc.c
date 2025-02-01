#include "src/game/save_file.h"

void bhv_memory_cloud_init(void) {
    switch (gCurrAreaIndex) {
        case 1:
            if (!(save_file_get_flags() & (SAVE_FLAG_ENTERED_SECOND_HUB))) {
                obj_mark_for_deletion(o);
            }
        break;
        case 2:
            if (!(save_file_get_flags() & (SAVE_FLAG_ENTERED_THIRD_HUB))) {
                obj_mark_for_deletion(o);
            }
        break;
        case 3:
            if (!(save_file_get_flags() & (SAVE_FLAG_BEAT_GAME))) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}

void bhv_memory_cloud_loop(void) {
    obj_scale_xyz(o, 0.5f + 0.15f*sins(gGlobalTimer*0x222), 0.5f + 0.15f*coss(gGlobalTimer*0x222), 0.5f + 0.15f*sins(gGlobalTimer*0x222));

    switch(o->oAction) {
        case 0:
            if (lateral_dist_between_objects(o, gMarioState->marioObj) < 50) {
                o->oAction = 1;
            }
        break;
        case 1:
            if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
                    create_dialog_box_with_response(DIALOG_ENTER_MEMORY);
                    o->oAction = 2;
                }
        break;
        case 2:

        if (gDialogResponse != DIALOG_RESPONSE_NONE) {
                    set_mario_npc_dialog(MARIO_DIALOG_STOP);
                    if (gDialogResponse == DIALOG_RESPONSE_YES) {
                        o->oAction = 4;
                        
                        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 0, 0, 0);
                    } else {
                        o->oAction = 3;
                    }
                }
            
        break;
        case 3:
            if (o->oDistanceToMario > 350) {
                o->oAction = 0;
            }
        break;
        case 4:
            if (o->oTimer == 18) {
                switch (gCurrAreaIndex) {
                    case 1:
                        initiate_warp(LEVEL_BITDW, 1, 0x0A, 0);
                    break;
                    case 2:
                        initiate_warp(LEVEL_BITFS, 1, 0x0A, 0);
                    break;
                    case 3:
                        initiate_warp(LEVEL_BITS, 1, 0x0A, 0);
                    break;
                }
                
            }
        break;
    }
}


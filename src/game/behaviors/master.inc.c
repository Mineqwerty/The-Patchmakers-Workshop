#include "include/dialog_ids.h"
#include "src/game/ingame_menu.h"
#include "src/game/cutscene.h"


void bhv_master_init(void) {
    if (!((save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_LLL)) & (1 << 5)))) {
        create_automatic_dialog_box(DIALOG_MASTER_WELCOME);
    }
}

void bhv_master_loop(void) {
    if (cCutsceneActive && cExternalCutsceneTrigger == 1) {
            SET_BPARAM1(o->oBehParams, 5);
            spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
            cExternalCutsceneTrigger = 0;
        }

    if (gPageNum == 12) {
        cur_obj_init_animation(1);
    }
}

Gfx *geo_switch_master_eyes(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        if (gCurrAreaIndex != 3) {
            //somehow the facial expressions worked good for the epilogue so im just reusing them
            switch (gPageNum) {
                case 3:
                case 8:
                case 9:
                    switchCase->selectedCase = 1;
                    break;
                case 6:
                case 10:
                case 12:
                case 15:
                case 22:
                    switchCase->selectedCase = 2;
                    break;
                case 16:
                    switchCase->selectedCase = 3;
                    break;
                default:
                    switchCase->selectedCase = 0;
                    break;
            }
        }
        else {
            switchCase->selectedCase = 0;
        }
    }
    return NULL;
}

void bhv_master_epilogue_init(void) {
    if (gCutsceneGameState != CUTSCENE_GAME_STATE_START_EPILOGUE) {
        obj_mark_for_deletion(o);
    }
}

void bhv_master_epilogue_loop(void) {
    if (gCurrAreaIndex == 1) {
        switch (o->oAction) {
            case 0:
                if (cExternalCutsceneTrigger == 1) {
                    o->oFaceAngleYaw = 0;
                    o->oAction++; 
                }
            break;
        }
    }
    if (gCurrAreaIndex == 3) {
        switch (o->oAction) {
            case 0:
                if (cExternalCutsceneTrigger == 3) {
                    o->oPosX = 412;
                    o->oPosZ = -421;
                    cur_obj_init_animation(3);
                    o->oAction++;
                }
            break;
            case 1:
                if (cExternalCutsceneTrigger == 4) {
                    o->oPosX = 600;
                    o->oPosZ = -811;
                    cur_obj_init_animation(4);
                    o->oAction++;
                }
            break;
            case 2:
                if (o->oTimer < 15) {
                    o->oPosZ -= 11;
                    o->oPosX += 11;
                }

                if (cExternalCutsceneTrigger == 5) {
                    cur_obj_init_animation(2);
                    o->oPosX = -648;
                    o->oPosZ = -1269;
                    o->oAction++;
                    o->oFaceAngleYaw = -0x400;
                }
            break;
        }
    }
}


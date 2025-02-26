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
    return NULL;
}
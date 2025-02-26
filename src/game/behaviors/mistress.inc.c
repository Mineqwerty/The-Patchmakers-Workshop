#include "src/game/save_file.h"
#include "src/game/cutscene.h"

void bhv_mistress_init(void) {
   
}

void bhv_mistress_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500) {
                cur_obj_init_animation(1);
            }
            else {
                cur_obj_init_animation(0);
            }
        break;
        case 1:
            if (cExternalCutsceneTrigger == 1) {
                cur_obj_init_animation(1);
            }
        break;
    }

    if (cCutsceneActive) {
        o->oAction = 1;
    }
    else {
        o->oAction = 0;
    }
}

void bhv_mistress_room_manager_init(void) {
    if (!((save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_LLL)) & (1 << 4)))) {
        begin_cutscene_event(CUTSCENE_EVENT_MISTRESS);
    }
    else {
        SET_BPARAM1(o->oBehParams, 4);
        spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
    }
}

void bhv_mistress_room_manager_loop(void) {

}


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

    if (gCutsceneGameState == CUTSCENE_GAME_STATE_START_EPILOGUE && cExternalCutsceneTrigger == 3) {
        obj_mark_for_deletion(o);
    }
}

void bhv_mistress_room_manager_init(void) {
    if (gCutsceneGameState != CUTSCENE_GAME_STATE_START_EPILOGUE) {
        if (!((save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_LLL)) & (1 << 4)))) {
            begin_cutscene_event(CUTSCENE_EVENT_MISTRESS);
        }
        else {
            SET_BPARAM1(o->oBehParams, 4);
            spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
        }
    }
    else {
        obj_mark_for_deletion(o);
    }
}

void bhv_mistress_room_manager_loop(void) {

}

void bhv_mistress_cured_init(void) {

}

void bhv_mistress_cured_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer >= 60) {
                cur_obj_init_animation(1);
                o->oAction++;
        }
        break;
        case 1:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(2);
                o->oAction++;

            }
        break;
        case 2:
            if (cExternalCutsceneTrigger == 4) {
                cur_obj_init_animation(3);
                o->oAction++;

            }
        break;
        case 3:
            if (cExternalCutsceneTrigger == 5) {
                cur_obj_init_animation(2);
                o->oPosX = -748;
                o->oPosZ = -1169;
                o->oAction++;
                o->oFaceAngleYaw = -0x300;
            }


        break;
    }
    
}


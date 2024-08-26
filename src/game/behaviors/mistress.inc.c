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
    //if (!(save_file_get_flags() & (N_SAVE_FLAG_CUTSCENE_MISTRESS))) {
        begin_cutscene_event(CUTSCENE_EVENT_MISTRESS);
    //}
}

void bhv_mistress_room_manager_loop(void) {

}


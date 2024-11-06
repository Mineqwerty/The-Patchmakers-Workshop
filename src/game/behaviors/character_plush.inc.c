#include "src/game/cutscene.h"

void bhv_character_plush_init(void) {
   
}

void bhv_character_plush_loop(void) {
    if (obj_has_model(o, MODEL_MARIO_PLUSH)) {
        if (gCurCutscene == CUTSCENE_EVENT_MEET_SEWNIA) {
            obj_mark_for_deletion(o);
        }
    }
}


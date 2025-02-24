#include "src/game/cutscene.h"
#include "src/game/save_file.h"

void bhv_character_plush_init(void) {
   
}

void bhv_character_plush_loop(void) {
    if (obj_has_model(o, MODEL_MARIO_PLUSH)) {
        if (gCurCutscene == CUTSCENE_EVENT_MEET_SEWNIA 
            || (o->oTimer == 1 && gCurCutscene != CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO)
            || gMarioState->numStars > 0) {
            obj_mark_for_deletion(o);
        }
    }
    if (obj_has_model(o, MODEL_BOWSER_PLUSH)) {
        if (gCurCutscene == CUTSCENE_EVENT_REVIVE_BOWSER || (save_file_get_flags() & SAVE_FLAG_ENTERED_SECOND_HUB)) {
            obj_mark_for_deletion(o);
        }
    }
    if (obj_has_model(o, MODEL_PEACH_PLUSH)) {
        if (gCurCutscene == CUTSCENE_EVENT_REVIVE_PEACH || (save_file_get_flags() & SAVE_FLAG_ENTERED_THIRD_HUB)) {
            obj_mark_for_deletion(o);
        }
    }
}


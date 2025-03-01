#include "src/game/ingame_menu.h"
#include "src/game/cutscene.h"

void bhv_thread_of_life_init(void) {
   
}

void bhv_thread_of_life_loop(void) {

    if (o->oAction == 1) {
        cur_obj_scale(CLAMP(1.0f - (f32)o->oTimer / 10.0f, 0.02f, 1.0f));
        if (o->oTimer == 10) {
            obj_mark_for_deletion(o);
        }
    }
    else {

        if (o->oTimer < 10) {
            cur_obj_scale(CLAMP((f32)o->oTimer / 10.0f, 0.02f, 1.0f));
        }
        else if (gPageNum < 7) {
            cur_obj_scale(1.0f);
        }
        else if (gCurrLevelNum == LEVEL_BOWSER_1) {
            o->oAction = 1;
        }

        if (gCurrLevelNum == LEVEL_BOWSER_2 && cExternalCutsceneTrigger >= 2 && o->oTimer > 3) {
            o->oAction = 1;
        }
    }

    if (o->oTimer > 30 && gCurCutscene == -1) {
        obj_mark_for_deletion(o);
    }

    
}


#include "src/game/cutscene.h"

void bhv_sewnia_body_init(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            cur_obj_init_animation(0);
        break;
    }
}

void bhv_sewnia_body_loop(void) {

}

void bhv_sewnia_head_init(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            cur_obj_init_animation(0);
        break;
    }
}

void bhv_sewnia_head_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            if (cExternalCutsceneTrigger >= 17) {
                cur_obj_init_animation(1);
            }
        break;
    }
}


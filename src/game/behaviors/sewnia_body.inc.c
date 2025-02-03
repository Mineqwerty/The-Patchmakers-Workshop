#include "src/game/cutscene.h"

void bhv_sewnia_body_init(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            cur_obj_init_animation(0);
        break;
        case LEVEL_CASTLE:
            cur_obj_init_animation(1);
        break;
    }

    o->oSewniaFaceState = 0;
}

void bhv_sewnia_body_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_CASTLE:
            if (cExternalCutsceneTrigger >= 1) {
                o->oPosZ = -200;
            }
        break;
    }
}

void bhv_sewnia_head_init(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            cur_obj_init_animation(0);
        break;
        case LEVEL_CASTLE:
            cur_obj_init_animation(2);
        break;
    }
    o->oSewniaFaceState = 0;
}

void bhv_sewnia_head_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_2:
            if (cExternalCutsceneTrigger >= 17) {
                cur_obj_init_animation(1);
            }
        break;
        case LEVEL_CASTLE:
            if (cExternalCutsceneTrigger >= 1) {
                o->oPosZ = -200;
            }
        break;
    }
}


#include "src/game/screen_transition.h"

#define NEW_FILE_SELECT_WINDING_UP    0
#define NEW_FILE_SELECT_CAM_LOGO    1
#define NEW_FILE_SELECT_CAM_FILES   2

void bhv_new_file_select_manager_init(void) {
    gCamera->cutscene = 1;
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
}

void bhv_new_file_select_manager_loop(void) {
    gCamera->cutscene = 1;
    switch (o->oAction) {
        case NEW_FILE_SELECT_WINDING_UP:
            if (o->oTimer == 0) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 40, 0, 0, 0);
            }
            if (o->oTimer == 20) {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 40, 0, 0, 0);
                sTransitionFadeTimer = 20;
            }
            if (o->oTimer == 50) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 40, 0, 0, 0);
            }
            if (o->oTimer == 70) {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 40, 0, 0, 0);
                sTransitionFadeTimer = 20;
            }
            if (o->oTimer == 100) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 40, 0, 0, 0);
            }
            Vec3f goalPos = {-100, 300, 0};
            Vec3f goalFoc = {500, 180, 0};
                approach_vec3f_asymptotic(gLakituState.goalPos, goalPos, 0.2f, 0.2f, 0.2f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalFoc, 0.2f, 0.2f, 0.2f);
        break;
        case NEW_FILE_SELECT_CAM_LOGO:
            {
            Vec3f goalPos = {-100, 300, 0};
            Vec3f goalFoc = {500, 180, 0};
                approach_vec3f_asymptotic(gLakituState.goalPos, goalPos, 0.2f, 0.2f, 0.2f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalFoc, 0.2f, 0.2f, 0.2f);
            }
        break;
        case NEW_FILE_SELECT_CAM_FILES:

        break;
    }
}


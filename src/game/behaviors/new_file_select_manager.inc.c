#include "src/game/screen_transition.h"
#include "src/game/hud.h"
#include "src/game/save_file.h"

#define NEW_FILE_SELECT_WINDING_UP    0
#define NEW_FILE_SELECT_CAM_LOGO    1
#define NEW_FILE_SELECT_CAM_FILES   2
#define NEW_FILE_SELECT_LOADING_FILE   3

void set_initial_game_variables(void) {
    s8 dpadMap[4] = {-1, -1, -1, -1};
    save_file_set_dpad_map(gCurrSaveFileNum - 1, dpadMap);
}

void bhv_new_file_select_manager_init(void) {
    gCamera->cutscene = 1;
    gHudDisplay.flags = 0;
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gSpecialHudElementAlpha = 0;
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
            if (o->oTimer == 40) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 40, 0, 0, 0);
            }
            if (o->oTimer == 60) {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 40, 0, 0, 0);
                sTransitionFadeTimer = 20;
            }
            if (o->oTimer == 80) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 40, 0, 0, 0);
            }

            if (o->oTimer == 130) {
                o->oAction++;
            }
            Vec3f goalPos = {-100, 300, 0};
            Vec3f goalFoc = {500, 180, 0};
                approach_vec3f_asymptotic(gLakituState.goalPos, goalPos, 0.2f, 0.2f, 0.2f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalFoc, 0.2f, 0.2f, 0.2f);
        break;
        case NEW_FILE_SELECT_CAM_LOGO:
            {
                gSpecialHudRender = 1;
                gSpecialHudElementAlpha = CLAMP_U8(o->oTimer * 6);
            Vec3f goalTitlePos = {-100, 300, 0};
            Vec3f goalTitleFoc = {500, 180, 0};
                approach_vec3f_asymptotic(gLakituState.goalPos, goalTitlePos, 0.25f, 0.25f, 0.25f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalTitleFoc, 0.2f, 0.2f, 0.2f);

                if (o->oTimer > 50 && gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                    o->oAction = NEW_FILE_SELECT_CAM_FILES;
                }

            }
        break;
        case NEW_FILE_SELECT_CAM_FILES:
            ;
            gSpecialHudElementAlpha = CLAMP_U8(255 - o->oTimer * 6);
            if (o->oTimer >= 50) {
                gSpecialHudRender = 0;
                if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
                    o->oAction = NEW_FILE_SELECT_CAM_LOGO;
                }
                else if (gPlayer1Controller->buttonPressed & (A_BUTTON)) {
                    if (!save_file_exists(gCurrSaveFileNum - 1)) {
                        set_initial_game_variables();
                    }
                    o->oAction = NEW_FILE_SELECT_LOADING_FILE;
                }
            }
            Vec3f goalFilePos = {634, 280, -175};
            Vec3f goalFileFoc = {638, 0, -175};
            f32 approachSpeed = 0.02f + (((f32)o->oTimer) / 3000.0f);
                approach_vec3f_asymptotic(gLakituState.goalPos, goalFilePos, approachSpeed, approachSpeed, approachSpeed);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalFileFoc, approachSpeed, approachSpeed,approachSpeed);

                
        break;
        case NEW_FILE_SELECT_LOADING_FILE:
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 0, 0, 0);
            if (o->oTimer == 19) {
                initiate_warp(LEVEL_CASTLE, 1, 0x0A, 0);
            }
        break;
    }
}


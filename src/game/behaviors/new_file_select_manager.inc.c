#include "src/game/screen_transition.h"
#include "src/game/hud.h"
#include "src/game/save_file.h"

#define NEW_FILE_SELECT_WINDING_UP    0
#define NEW_FILE_SELECT_CAM_LOGO    1
#define NEW_FILE_SELECT_CAM_FILES   2
#define NEW_FILE_SELECT_LOADING_FILE   3

u8 gSelectedFile = 0;

s16 saveDeletionTimer = 0;

void set_initial_game_variables(void) {
    s8 dpadMap[4] = {-1, -1, -1, -1};
    save_file_set_dpad_map(gCurrSaveFileNum - 1, dpadMap);
    update_dl_dpad_patches();
}

void update_mario_save_file_variables(void) {
    gMarioState->portal1Position[0] = 0;
    gMarioState->portal1Position[1] = 0;
    gMarioState->portal1Position[2] = 0;

    gMarioState->portal2Position[0] = 0;
    gMarioState->portal2Position[1] = 0;
    gMarioState->portal2Position[2] = 0;

    gMarioState->portal1Info[2] = 0;
    gMarioState->portal2Info[2] = 0;

    gMarioState->numCoins = 0;
    gMarioState->numStars = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
    gMarioState->numKeys = 0;
    gMarioState->health = 0x880;
    gMarioState->prevNumStarsForDialog = gMarioState->numStars;
    gHudDisplay.coins = 0;
    gHudDisplay.wedges = 8;
}

void bhv_new_file_select_manager_init(void) {
    gCamera->cutscene = 1;
    gHudDisplay.flags = 0;
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gSpecialHudElementAlpha = 0;
    saveDeletionTimer = 0;
    spawn_object_relative(0, 0,0, 0, o, MODEL_YARN_SELECTOR_CIRCLE,bhvYarnCircleSelector);
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

                handle_menu_scrolling(MENU_SCROLL_BOTH, &gSelectedFile, 0, 3);
                f32 dist;
                struct Object *selector = cur_obj_find_nearest_object_with_behavior(bhvYarnCircleSelector, &dist);

                if (selector) {
                    selector->oF4 = gSelectedFile;
                }

                gSpecialHudRender = 0;
                if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
                    o->oAction = NEW_FILE_SELECT_CAM_LOGO;
                }
                else if (gPlayer1Controller->buttonPressed & (A_BUTTON)) {

                    gCurrSaveFileNum = (s16)gSelectedFile + 1;
                    if (!save_file_exists(gCurrSaveFileNum - 1)) {
                        set_initial_game_variables();
                    }
                    update_mario_save_file_variables();
                    o->oAction = NEW_FILE_SELECT_LOADING_FILE;
                }

                u8 deleteGBColor = 255;

                if (save_file_exists((s16)gSelectedFile) && (gPlayer1Controller->buttonDown & Z_TRIG)) {
                    saveDeletionTimer++;
                    deleteGBColor = 255 - 2*saveDeletionTimer;
                    print_set_envcolour(255, deleteGBColor, deleteGBColor, 255);
                    print_small_text_buffered(SCREEN_WIDTH - 60, SCREEN_HEIGHT - 30, "Deleting File!", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
                    if (saveDeletionTimer == 120) {
                        save_file_erase((s32)gSelectedFile);
                        saveDeletionTimer = 0;
                    }
                    
                }
                else {
                    saveDeletionTimer = 0;
                    if (save_file_exists((s16)gSelectedFile)) {
                        print_set_envcolour(255, 255, 255, CLAMP((o->oTimer - 60)* 17, 1, 255));
                        print_small_text_buffered(SCREEN_WIDTH - 60, SCREEN_HEIGHT - 30, "Hold Z To Delete File", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
                    }
                }
                
                print_set_envcolour(120, 120, 120, CLAMP((o->oTimer - 60)* 17, 1, 255));
                print_small_text_buffered(45, SCREEN_HEIGHT - 30, "Ver. 1.0.1", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            }
            Vec3f goalFilePos = {634, 250, -175};
            Vec3f goalFileFoc = {638, 0, -175};
            f32 approachSpeed = 0.02f + (((f32)o->oTimer) / 3000.0f);
                approach_vec3f_asymptotic(gLakituState.goalPos, goalFilePos, approachSpeed, approachSpeed, approachSpeed);
                approach_vec3f_asymptotic(gLakituState.goalFocus, goalFileFoc, approachSpeed, approachSpeed,approachSpeed);

                
        break;
        case NEW_FILE_SELECT_LOADING_FILE:
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 0, 0, 0);
            if (o->oTimer == 19) {
                initiate_warp(LEVEL_CASTLE, 1, 0x0A, 0, 0);
            }
        break;
    }
}

void bhv_file_controller_init(void) {
    if (save_file_exists(o->oBehParams2ndByte - 1)) {
        s16 starCount = save_file_get_total_star_count(o->oBehParams2ndByte - 1, COURSE_MIN - 1, COURSE_MAX - 1);
        u8 inHundreds = starCount/100;
        u8 inTenths = CLAMP(starCount/10, 0, 1);

        spawn_object_relative(10, 6, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);

        if (inHundreds) {
            spawn_object_relative((starCount/100)%10, 4, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
            spawn_object_relative((starCount/10)%10, 2, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
            spawn_object_relative((starCount)%10, 0, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
        }
        else if (inTenths) {
            spawn_object_relative((starCount/10)%10, 4, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
            spawn_object_relative((starCount)%10, 2, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
        }
        else {
            spawn_object_relative((starCount)%10, 4, 2, 0, o, MODEL_NUMBER, bhvNewFileSelectStarCountNumber);
        }
    }
}

void bhv_file_controller_loop(void) {

}


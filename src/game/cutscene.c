#include <PR/ultratypes.h>

#include "types.h"
#include "cutscene.h"
#include "src/game/level_update.h"
#include "src/game/game_init.h"
#include "audio/external.h"
#include "include/sounds.h"
#include "src/game/camera.h"
#include "src/game/ingame_menu.h"
#include "include/behavior_data.h"
#include "include/seq_ids.h"

#include "levels/bob/header.inc.h"
#include "levels/jrb/header.inc.h"
#include "levels/ccm/header.inc.h"

u8 cCutsceneActive;
int cCutsceneIndex;
u32 cWaitTimer;
u8 cWaiting;
struct CutsceneSplinePoint *posSpline;
struct CutsceneSplinePoint *focusSpline;
u8 cPositionSplineActive;
u8 cFocusSplineActive;
f32 cPositionSplineProgress;
f32 cFocusSplineProgress;
s16 cPositionSplineSegment;
s16 cFocusSplineSegment;
s32 *cEventPointer;

extern s16 sCutsceneSplineSegment;
//extern f32 sCutsceneSplineSegmentProgress;
//extern struct CutsceneSplinePoint jrb_area_1_spline_camfoc[];

enum cutscene_events {
    EVENT_WAIT,
    EVENT_WAIT_FOR_NEXT_DIALOG_PAGE,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE,
    EVENT_WAIT_FOR_TRIGGER,
    EVENT_WAIT_FOR_MARIO_FLOOR,
    EVENT_WAIT_FOR_DIALOG_END,

    EVENT_DIALOG_AUTO,
    EVENT_DIALOG_USER_ADVANCE,

    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_CAMERA_FOCUS,
    EVENT_CAMERA_POSITION,
    EVENT_CAMERA_FOCUS_SPLINE_DATA,
    EVENT_CAMERA_POSITION_SPLINE_DATA,
    EVENT_CAMERA_SHAKE,

    EVENT_DISABLE_MARIO_RENDER,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_SET_MARIO_POSITION,
    EVENT_SET_MARIO_YAW,
    EVENT_SET_MARIO_ACTION,

    EVENT_SPAWN_OBJECT,

    EVENT_SOUND,
    EVENT_SONG_PRIMARY,
    EVENT_SONG_SECONDARY,

    EVENT_HUD_DISABLE,
    EVENT_HUD_ENABLE,
    EVENT_SHOW_BOSS_TITLE,

    EVENT_END_CUTSCENE
};

s32 event_test[] = {
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 0,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 1,
    EVENT_WAIT, 200,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_END_CUTSCENE
};

s32 event_goddess_intro[] = {
    EVENT_HUD_DISABLE,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_SET_MARIO_POSITION, 0, -400, -1700,
    EVENT_SET_MARIO_YAW, 0,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 2,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 3,
    EVENT_DIALOG_USER_ADVANCE, 60,
    EVENT_WAIT_FOR_NEXT_DIALOG_PAGE,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 4,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 5,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 4,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 6,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 7,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 7,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 8,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 8,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 9,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 9,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 10,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 11,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 9,
    EVENT_WAIT, 60,
    EVENT_SONG_PRIMARY, SEQ_LEVEL_BOSS_KOOPA_FINAL,
    EVENT_SHOW_BOSS_TITLE, 2,
    EVENT_WAIT, 120,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_END_CUTSCENE
};

s32 event_pokey_intro[] = {
    EVENT_HUD_DISABLE,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 12,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 13,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_WAIT, 30,
    EVENT_DIALOG_AUTO, 54,
    EVENT_WAIT, 90,
    EVENT_WAIT, 120,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 14,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 15,
    EVENT_WAIT, 100,
    EVENT_SHOW_BOSS_TITLE, 1,
    EVENT_WAIT, 50,
    EVENT_CAMERA_SHAKE, -446, 3563, -1802, 
    EVENT_WAIT, 90,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_END_CUTSCENE
};

s32 event_rosedrift_cliff[] = {
    EVENT_WAIT_FOR_MARIO_FLOOR,
    EVENT_HUD_DISABLE,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_SPAWN_OBJECT, -87, 2640, 1156, 0, 0xA0AA, 0, 23, bhvRosedriftCutscene, MODEL_ROSEDRIFT,
    EVENT_DIALOG_USER_ADVANCE, 56,
    EVENT_WAIT_FOR_NEXT_DIALOG_PAGE,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 16,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 17,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_END_CUTSCENE
};

s32 event_find_stone_patch[] = {
    EVENT_WAIT, 1,
    EVENT_HUD_DISABLE,
    
    EVENT_CAMERA_POSITION_SPLINE_DATA, 18,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 19,
    EVENT_SET_MARIO_ACTION, ACT_COLLECTING_PATCH,
    EVENT_WAIT, 100,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 20,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 21,
    EVENT_WAIT, 200,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_END_CUTSCENE
};

s32 *eventList[] = {
    event_test,
    event_goddess_intro,
    event_pokey_intro,
    event_rosedrift_cliff,
    event_find_stone_patch
    //5
};

s32 *splineList[] = {
    jrb_area_1_spline_STCBridgeExtensionPos,
    jrb_area_1_spline_STCBridgeExtensionFoc,
    ccm_area_4_spline_GoddessIntroCutscene1Pos,
    ccm_area_4_spline_GoddessIntroCutscene1Foc,
    ccm_area_4_spline_GoddessIntroCutscene2Pos,
    //5
    ccm_area_4_spline_GoddessIntroCutscene2Foc,
    ccm_area_4_spline_GoddessIntroCutscene3Pos,
    ccm_area_4_spline_GoddessIntroCutscene3Foc,
    ccm_area_4_spline_GoddessIntroCutscene4Pos,
    ccm_area_4_spline_GoddessIntroCutscene4Foc,
    //10
    ccm_area_4_spline_GoddessIntroCutscene5Pos,
    ccm_area_4_spline_GoddessIntroCutscene5Foc,
    bob_area_1_spline_PokeyIntroCutscene1Pos,
    bob_area_1_spline_PokeyIntroCutscene1Foc,
    bob_area_1_spline_PokeyIntroCutscene2Pos,
    //15
    bob_area_1_spline_PokeyIntroCutscene2Foc,
    bob_area_1_spline_PokeyRosedriftCutscenePos,
    bob_area_1_spline_PokeyRosedriftCutsceneFoc,
    bob_area_2_spline_StonePatchCutscenePos1,
    bob_area_2_spline_StonePatchCutsceneFoc1,
    //20
    bob_area_2_spline_StonePatchCutscenePos2,
    bob_area_2_spline_StonePatchCutsceneFoc2
};

void begin_cutscene_event(s32 event) {
    cCutsceneActive = 1;
    cCutsceneIndex = 0;
    cWaitTimer = 0;
    cWaiting = 0;
    cEventPointer = eventList[event];
}

void event_handler(void) {
    if (cCutsceneActive) {
        s32 eventCommand;
        struct Object *eventObj;



        while (!cWaiting && cCutsceneActive) {
            eventCommand = cEventPointer[cCutsceneIndex];
            s32 param1 = cEventPointer[cCutsceneIndex + 1];
            s32 param2 = cEventPointer[cCutsceneIndex + 2];
            s32 param3 = cEventPointer[cCutsceneIndex + 3];

            switch (eventCommand) {
                case EVENT_WAIT:
                    if (cWaiting == 0) {
                        cWaiting = 1;
                        cWaitTimer = param1;
                    }
                    
                break;
                case EVENT_WAIT_FOR_NEXT_DIALOG_PAGE:
                    if (cWaiting == 0) {
                        cWaiting = 2;
                    }
                    
                break;
                case EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE:
                    if (cWaiting == 0) {
                        cWaiting = 3;
                    }
                    
                break;
                case EVENT_WAIT_FOR_MARIO_FLOOR:
                    if (cWaiting == 0) {
                        cWaiting = 4;
                    }
                    
                break;
                case EVENT_WAIT_FOR_DIALOG_END:
                    if (cWaiting == 0) {
                        cWaiting = 5;
                    }
                    
                break;
                case EVENT_DIALOG_AUTO:
                    create_automatic_dialog_box(param1);
                    cCutsceneIndex += 2;
                break;
                case EVENT_CAMERA_ENABLE_CUTSCENE:
                    gCamera->cutscene = 1;
                    cCutsceneIndex += 1;
                break;
                case EVENT_CAMERA_DISABLE_CUTSCENE:
                    gCamera->cutscene = 0;
                    cCutsceneIndex += 1;
                break;
                case EVENT_DISABLE_MARIO_RENDER:
                    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
                    cCutsceneIndex += 1;
                break;
                case EVENT_ENABLE_MARIO_RENDER:
                    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
                    cCutsceneIndex += 1;
                break;
                case EVENT_CAMERA_FOCUS:
                    cCutsceneIndex += 4;
                break;
                case EVENT_CAMERA_FOCUS_SPLINE_DATA:
                    cFocusSplineActive = 1;
                    cFocusSplineProgress = 0;
                    cFocusSplineSegment = 0;
                    gCamera->cutscene = 1;
                    focusSpline = splineList[cEventPointer[cCutsceneIndex + 1]];
                    cCutsceneIndex += 2;
                break;
                case EVENT_CAMERA_POSITION_SPLINE_DATA:
                    cPositionSplineActive = 1;
                    cPositionSplineProgress = 0;
                    cPositionSplineSegment = 0;
                    gCamera->cutscene = 1;
                    posSpline = splineList[cEventPointer[cCutsceneIndex + 1]];
                    cCutsceneIndex += 2;
                break;
                case EVENT_CAMERA_SHAKE:
                    set_camera_shake_from_point(SHAKE_POS_LARGE, param1, param2, param3);
                    cCutsceneIndex += 4;
                break;
                case EVENT_SET_MARIO_POSITION:
                    gMarioState->pos[0] = param1;
                    gMarioState->pos[1] = param2;
                    gMarioState->pos[2] = param3;
                    cCutsceneIndex += 4;
                break;
                case EVENT_SET_MARIO_YAW:
                    gMarioState->faceAngle[1] = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_SET_MARIO_ACTION:
                    gMarioState->action = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_DIALOG_USER_ADVANCE:
                    create_dialog_box(param1);
                    cCutsceneIndex += 2;
                break;
                case EVENT_SOUND:
                    play_sound(param1, gGlobalSoundSource);
                    cCutsceneIndex += 2;
                break;
                case EVENT_HUD_DISABLE:
                    gHudDisplay.flags = HUD_DISPLAY_NONE;
                    cCutsceneIndex += 1;
                break;
                case EVENT_END_CUTSCENE:
                    gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
                    cCutsceneActive = 0;
                break;
                case EVENT_SHOW_BOSS_TITLE:
                    gHudDisplay.flags |= HUD_DISPLAY_BOSS_INTRO;
                    gHudDisplay.bossIntroTimer = 0;
                    gHudDisplay.bossID = param1;
                    cCutsceneIndex += 2;
                    
                break;
                case EVENT_SPAWN_OBJECT:
                    eventObj = spawn_object_abs_with_rot(gMarioState->marioObj, 0, cEventPointer[cCutsceneIndex + 9], cEventPointer[cCutsceneIndex + 8], 
                        param1, param2, param3, cEventPointer[cCutsceneIndex + 4], cEventPointer[cCutsceneIndex + 5], cEventPointer[cCutsceneIndex + 6]);
                    SET_BPARAM2(eventObj->oBehParams, cEventPointer[cCutsceneIndex + 7]);
                    cCutsceneIndex += 10;
                break;
                case EVENT_SONG_PRIMARY:
                    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, param1), 0);
                    cCutsceneIndex += 2;
                break;
            }
        }

        if (cWaiting == 1) {
            cWaitTimer--;
            if (cWaitTimer == 0) {
                cWaiting = 0;
                cCutsceneIndex += 2;
            }
        }
        else if (cWaiting == 2 && gDialogBoxState == 2) {
            cWaiting = 0;
            cCutsceneIndex += 1;
        }
        else if (cWaiting == 3) {
            s32 param1 = cEventPointer[cCutsceneIndex + 1];
            if (gPageNum == param1) {
                cWaiting = 0;
                cCutsceneIndex += 2;
            }
        }
        else if (cWaiting == 4 && !((gMarioState->action & ACT_GROUP_MASK) >= ACT_GROUP_AIRBORNE && (gMarioState->action & ACT_GROUP_MASK) < (ACT_HOLD_JUMP & ACT_ID_MASK))) {
            cWaiting = 0;
            cCutsceneIndex += 1;
        }
        else if (cWaiting == 5 && gDialogBoxState == 3) {
            cWaiting = 0;
            cCutsceneIndex += 1;
        }

        if (cPositionSplineActive) {
           cPositionSplineActive = !move_point_along_spline(gCamera->pos, segmented_to_virtual(posSpline), &cPositionSplineSegment,
                            &cPositionSplineProgress);
        }

        if (cFocusSplineActive) {
            cFocusSplineActive = !move_point_along_spline(gCamera->focus, segmented_to_virtual(focusSpline), &cFocusSplineSegment,
                            &cFocusSplineProgress);
        }
    }
}




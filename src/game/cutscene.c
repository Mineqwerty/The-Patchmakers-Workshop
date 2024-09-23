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
#include "src/game/fb_effects.h"
#include "src/game/mario.h"
#include "src/game/mario_actions_moving.h"
#include "src/game/hud.h"

#include "levels/bob/header.inc.h"
#include "levels/jrb/header.inc.h"
#include "levels/ccm/header.inc.h"
#include "levels/lll/header.inc.h"

#include "levels/castle_inside/header.inc.h"

s16 gCurCutscene = -1;

u8 cCutsceneActive;
int cCutsceneIndex;
u8 cExternalCutsceneTrigger;
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
s8 cEyeStateOverride = -1;
u8 cMarioFocusSpeed;
s32 cRotateAroundMarioRadius;
u32 cCutsceneTimer;
s16 cCameraDownVel;


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
    EVENT_WAIT_FOR_BUTTON_PRESS,

    EVENT_DIALOG_AUTO,
    EVENT_FAST_DIALOG_AUTO,
    EVENT_DIALOG_USER_ADVANCE,

    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_CAMERA_FOCUS,
    EVENT_CAMERA_POSITION,
    EVENT_CAMERA_FOCUS_SPLINE_DATA,
    EVENT_CAMERA_POSITION_SPLINE_DATA,
    EVENT_CAMERA_SET_MARIO_AS_FOCUS,
    EVENT_CAMERA_ROTATE_AROUND_MARIO,
    EVENT_CANCEL_SPLINE_DATA,
    EVENT_CAMERA_SHAKE,
    EVENT_CAMERA_DOWN_VEL,

    EVENT_DISABLE_MARIO_RENDER,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_SET_MARIO_POSITION,
    EVENT_SET_MARIO_YAW,
    EVENT_SET_MARIO_ROLL,
    EVENT_SET_MARIO_ACTION,
    EVENT_SET_MARIO_ACTION_ARG,
    EVENT_SET_MARIO_EYE_STATE,
    EVENT_SET_MARIO_CUSTOM_ANIMATION,
    EVENT_MARIO_APPROACH_POINT,

    EVENT_SPAWN_OBJECT,

    EVENT_SET_EXTERNAL_TRIGGER,

    EVENT_SOUND,
    EVENT_SONG_PRIMARY,
    EVENT_SONG_SECONDARY,

    EVENT_HUD_DISABLE,
    //EVENT_HUD_ENABLE,
    EVENT_SHOW_BOSS_TITLE,
    EVENT_HUD_SET_EFFECT,

    EVENT_SET_FB_EFFECT,
    EVENT_CLEAR_FB_EFFECT,

    EVENT_STONE_PATCH_PICKED_UP,
    EVENT_STONE_PATCH_EQUIPPED,
    EVENT_STONE_PATCH_BREAK_OUT,

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
    EVENT_SONG_PRIMARY, SEQ_STONE_PATCH_CUTSCENE,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 18,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 19,
    EVENT_SET_MARIO_ACTION, ACT_COLLECTING_PATCH,
    EVENT_WAIT, 23,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 50,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 27, //total time 100
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 20,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 21,
    EVENT_WAIT, 20,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 22,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 32,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 32,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 32,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 32,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 30,  //total time 300
    EVENT_CANCEL_SPLINE_DATA,
    EVENT_SET_MARIO_ACTION_ARG, 2,
    EVENT_WAIT, 2,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_CAMERA_POSITION, -1800, 306, 30,
    EVENT_CAMERA_FOCUS, 500, 40, -40,
    EVENT_WAIT, 40,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_BODY_HIT_GROUND,
    EVENT_WAIT, 22, //total time 362
    EVENT_STONE_PATCH_PICKED_UP,
    EVENT_SOUND, SOUND_ACTION_CLIMB_UP_TREE,
    EVENT_WAIT, 32,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP_TIPTOE,
    EVENT_WAIT, 8,
    EVENT_SOUND, SOUND_ACTION_TERRAIN_STEP,
    EVENT_WAIT, 80,
    EVENT_SET_MARIO_POSITION, -1434, 180, -100,
    EVENT_SET_MARIO_ACTION_ARG, 3,
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION, -1600, 306, -80,
    EVENT_CAMERA_FOCUS, -934, 200, 0,
    EVENT_WAIT, 40,
    EVENT_STONE_PATCH_EQUIPPED,
    EVENT_SOUND, SOUND_ACTION_BRUSH_HAIR,
    EVENT_WAIT, 30,
    EVENT_SOUND, SOUND_MARIO_HAHA,
    EVENT_WAIT, 70,
    EVENT_SET_MARIO_EYE_STATE, 9,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_INVERT,
    EVENT_SET_MARIO_ACTION_ARG, 4,
    EVENT_WAIT, 20,
    EVENT_CLEAR_FB_EFFECT,
    EVENT_WAIT, 40,
    EVENT_SET_MARIO_EYE_STATE, -1,
    EVENT_WAIT, 30,
    EVENT_SET_MARIO_POSITION, -1434, 180, -100,
    EVENT_SET_MARIO_ACTION_ARG, 5,
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 22,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 23,
    EVENT_WAIT, 20,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_INVERT,
    EVENT_SET_MARIO_EYE_STATE, 9,
    EVENT_WAIT, 20,
    EVENT_CLEAR_FB_EFFECT,
    EVENT_SET_MARIO_EYE_STATE, 1,
    EVENT_WAIT, 55,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_INVERT,
    EVENT_SET_MARIO_EYE_STATE, -1,
    EVENT_WAIT, 20,
    EVENT_CLEAR_FB_EFFECT,
    EVENT_SET_MARIO_EYE_STATE, 10,
    EVENT_WAIT, 50,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_INVERT,
    EVENT_SET_MARIO_EYE_STATE, -1,
    EVENT_WAIT, 20,
    EVENT_CLEAR_FB_EFFECT,
    EVENT_WAIT, 56,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_INVERT,
    EVENT_SET_MARIO_EYE_STATE, 1,
    EVENT_WAIT, 20,
    EVENT_CLEAR_FB_EFFECT,
    EVENT_WAIT, 20,
    EVENT_SET_MARIO_ACTION_ARG, 6,
    EVENT_SET_MARIO_POSITION, -1400, 180, -80,
    EVENT_WAIT, 5,
    EVENT_CAMERA_POSITION, -1350, 206, 250,
    EVENT_CAMERA_FOCUS, -1350, 106, -100,
    EVENT_WAIT, 18,
    EVENT_SET_MARIO_ACTION_ARG, 7,
    EVENT_SET_MARIO_POSITION, -1400, -3544, -80,
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION, -1350, -3518, 250,
    EVENT_CAMERA_FOCUS, -1350, -3628, -100,
    EVENT_WAIT, 20,
    EVENT_CAMERA_SET_MARIO_AS_FOCUS, 15,
    EVENT_WAIT, 60,
    EVENT_SET_MARIO_ACTION_ARG, 8,
    EVENT_SET_MARIO_POSITION, 8734, 180, -1670,
    EVENT_CAMERA_POSITION, 8534, 180, -1670,
    EVENT_CAMERA_FOCUS, 8734, 180, -1670,
    EVENT_CAMERA_ROTATE_AROUND_MARIO, 500,
    EVENT_WAIT, 1,
    EVENT_CAMERA_SET_MARIO_AS_FOCUS, 40,
    EVENT_WAIT, 90,
    EVENT_SET_MARIO_ACTION_ARG, 9,
    EVENT_CAMERA_POSITION, 8734, -5000, -1670,
    EVENT_CAMERA_FOCUS, 8734, -7000, -1670,
    EVENT_CAMERA_ROTATE_AROUND_MARIO, 0,
    EVENT_CAMERA_DOWN_VEL, 35,
    EVENT_WAIT, 30,
    EVENT_CAMERA_FOCUS, 8634, -3000, -1650,
    EVENT_CAMERA_POSITION, 8634, -4300, -1650,
    EVENT_CAMERA_DOWN_VEL, 31,
    EVENT_CAMERA_SET_MARIO_AS_FOCUS, 4,
    EVENT_WAIT, 15,
    EVENT_SET_MARIO_EYE_STATE, 10,
    EVENT_WAIT, 25,
    EVENT_CAMERA_POSITION, 8734, -2000, -1670,
    EVENT_CAMERA_FOCUS, 8734, -2000, 1370,
    EVENT_CAMERA_DOWN_VEL, 0,
    EVENT_SET_MARIO_ACTION_ARG, 10,
    EVENT_WAIT, 10,
    EVENT_CAMERA_SHAKE, 8734, -7000, -1370,
    EVENT_SET_MARIO_POSITION, 8734, -9250, 3330,
    EVENT_WAIT, 40,
    EVENT_CAMERA_POSITION, 8734, -9000, 3330,
    EVENT_CAMERA_FOCUS, 8734, -9300, 3330,
    EVENT_CAMERA_DOWN_VEL, -11,
    EVENT_WAIT, 60,
    EVENT_SET_FB_EFFECT, FBE_EFFECT_MULT,
    EVENT_SET_MARIO_POSITION, -1434, 180, -100,
    EVENT_SET_MARIO_ACTION_ARG, 11,
    EVENT_CAMERA_POSITION, -1434, 1050, -100,
    EVENT_CAMERA_FOCUS,  -1434, 100, -100,

    EVENT_WAIT, 90,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_WAIT_FOR_BUTTON_PRESS, L_TRIG,
    EVENT_STONE_PATCH_BREAK_OUT,
    EVENT_END_CUTSCENE
};

s32 event_goddess_death[] = {
    EVENT_HUD_DISABLE,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_CAMERA_POSITION, -1200, 1600, -5000,
    EVENT_CAMERA_FOCUS, 0, 1800, -1600,
    EVENT_FAST_DIALOG_AUTO, 61,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_SET_EXTERNAL_TRIGGER, 1,
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION, -200, 0, -2400,
    EVENT_CAMERA_FOCUS, 0, -400, -1600,
    EVENT_SET_MARIO_POSITION, 0, -380, -2300,
    EVENT_MARIO_APPROACH_POINT, 0, -400, -1900,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_WAIT, 10,
    EVENT_DIALOG_USER_ADVANCE, 62,
    EVENT_WAIT, 50,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 3,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 29,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 30,
    EVENT_WAIT_FOR_DIALOG_END, 
    EVENT_WAIT, 10,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_WAIT, 1,
    EVENT_CANCEL_SPLINE_DATA,
    EVENT_CAMERA_POSITION, 0, -320, -2400,
    EVENT_CAMERA_FOCUS, 0, -300, -1600,
    EVENT_SET_EXTERNAL_TRIGGER, 2,
    EVENT_DIALOG_USER_ADVANCE, 63,
    EVENT_WAIT, 10,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_WAIT, 4,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_WAIT, 4,
    
    EVENT_END_CUTSCENE

};

s32 event_mistress[] = {
    EVENT_HUD_DISABLE,
    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_CAMERA_POSITION, 384, 690, 22,
    EVENT_CAMERA_SET_MARIO_AS_FOCUS, 100,
    EVENT_WAIT, 30,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_WAIT, 20,
    EVENT_CAMERA_FOCUS, 712, 400, -1150,
    EVENT_WAIT, 90,
    EVENT_DIALOG_USER_ADVANCE, 49,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 24,
    EVENT_CAMERA_FOCUS, 912, 500, -1350,
    EVENT_WAIT, 60,
    EVENT_SET_EXTERNAL_TRIGGER, 1,
    EVENT_WAIT, 30,
    EVENT_SET_EXTERNAL_TRIGGER, 0,
    EVENT_SONG_PRIMARY, SEQ_MISTRESS_THEME,
    EVENT_WAIT, 30,
    EVENT_DIALOG_USER_ADVANCE, 50,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_WAIT, 30,
    EVENT_CAMERA_POSITION, 800, 900, -682,
    EVENT_CAMERA_FOCUS, 233, 400, -1250,
    EVENT_DIALOG_USER_ADVANCE, 51,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 3,
    EVENT_CAMERA_POSITION, 427, 700, -1316,
    EVENT_CAMERA_FOCUS, -104, 422, 489,
    EVENT_MARIO_APPROACH_POINT, 270, 422, -669,
    EVENT_SET_EXTERNAL_TRIGGER, 3,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 6,
    EVENT_CAMERA_POSITION, 104, 522, -489,
    EVENT_CAMERA_FOCUS, 427, 550, -1316,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_SET_EXTERNAL_TRIGGER, 4,
    EVENT_WAIT, 1,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_END_CUTSCENE
};

s32 event_meet_sewnia[] = {
    EVENT_HUD_DISABLE,
    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_STORY_CUTSCENE,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_SET_MARIO_POSITION, 0, 166, 1154,
    EVENT_SET_MARIO_YAW, -0x4000,
    EVENT_SET_MARIO_ROLL, 0x4000,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 25,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 26,
    EVENT_HUD_SET_EFFECT, 2,
    EVENT_WAIT, 180,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_CANCEL_SPLINE_DATA,
    EVENT_SET_MARIO_CUSTOM_ANIMATION, MARIO_CUSTOM_ANIM_SCUFFLE_BACK,
    
    EVENT_CAMERA_POSITION, 300, 250, 1120,
    EVENT_CAMERA_FOCUS, 0, 230, 1150,
    EVENT_WAIT, 40,
    EVENT_SET_EXTERNAL_TRIGGER, 100, //sewnia disable render
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION, 0, 250, 1100,
    EVENT_CAMERA_FOCUS, 0, 230, 1250,
    EVENT_WAIT, 80,
    EVENT_CAMERA_POSITION, 0, 250, 1450,
    EVENT_CAMERA_FOCUS, 0, 230, 1230,
    EVENT_SET_EXTERNAL_TRIGGER, 1, //sewnia fall back
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_WAIT, 80,
    EVENT_CAMERA_POSITION, 600, 250, 1200,
    EVENT_CAMERA_FOCUS, 0, 230, 1200,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_SET_EXTERNAL_TRIGGER, 2,
    EVENT_WAIT, 120,
    EVENT_SET_EXTERNAL_TRIGGER, 3, //sewnia stand up
    EVENT_WAIT, 1,
    EVENT_CAMERA_POSITION, 0, 250, 1450,
    EVENT_CAMERA_FOCUS, 0, 230, 1230,
    EVENT_DISABLE_MARIO_RENDER,
    EVENT_WAIT, 70,
    EVENT_DIALOG_USER_ADVANCE, 22,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 4,
    EVENT_ENABLE_MARIO_RENDER,
    EVENT_SET_MARIO_CUSTOM_ANIMATION, MARIO_CUSTOM_ANIM_TEST,
    EVENT_CAMERA_POSITION_SPLINE_DATA, 27,
    EVENT_CAMERA_FOCUS_SPLINE_DATA, 28,
    EVENT_WAIT_FOR_SPECIFIC_DIALOG_PAGE, 6,
    EVENT_CANCEL_SPLINE_DATA,
    EVENT_CAMERA_POSITION, 200, 250, 1450,
    EVENT_CAMERA_FOCUS, 0, 230, 1230,
    EVENT_WAIT_FOR_DIALOG_END,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_END_CUTSCENE
};

s32 event_sewnia_revive_mario[] = {
    EVENT_HUD_DISABLE,
    //EVENT_CAMERA_ENABLE_CUTSCENE,
    //EVENT_SET_MARIO_ACTION, ACT_STORY_CUTSCENE,
    //EVENT_DISABLE_MARIO_RENDER,
    EVENT_WAIT, 70,
    EVENT_SET_EXTERNAL_TRIGGER, 1,
    EVENT_WAIT, 5000,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_END_CUTSCENE
};

s32 event_city_lights_on[] = {
    EVENT_WAIT_FOR_MARIO_FLOOR,
    EVENT_CAMERA_ENABLE_CUTSCENE,
    EVENT_SET_MARIO_ACTION, ACT_WAITING_FOR_DIALOG,
    EVENT_WAIT, 20,
    EVENT_CAMERA_POSITION, -7523, 6800, 6232,
    EVENT_CAMERA_FOCUS, -5000, 6000, 4000,
    EVENT_WAIT, 120,
    EVENT_SET_MARIO_ACTION, ACT_IDLE,
    EVENT_CAMERA_DISABLE_CUTSCENE,
    EVENT_END_CUTSCENE
};

s32 *eventList[] = {
    event_test,
    event_goddess_intro,
    event_pokey_intro,
    event_rosedrift_cliff,
    event_find_stone_patch,
    //5
    event_goddess_death,
    event_mistress,
    event_meet_sewnia,
    event_sewnia_revive_mario,
    event_city_lights_on
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
    bob_area_2_spline_StonePatchCutsceneFoc2,
    bob_area_2_spline_StonePatchCutscenePos3,
    bob_area_2_spline_StonePatchCutsceneFoc3,
    lll_area_3_spline_MistressCutsceneApproachBed,
    //25
    castle_inside_area_1_spline_MeetSewniaPos1,
    castle_inside_area_1_spline_MeetSewniaFoc1,
    castle_inside_area_1_spline_MeetSewniaPos2,
    castle_inside_area_1_spline_MeetSewniaFoc2,
    ccm_area_4_spline_GoddessIntroCutscene6Pos,
    //30
    ccm_area_4_spline_GoddessIntroCutscene6Foc,
};

void begin_cutscene_event(s32 event) {
    gCurCutscene = event;
    cCutsceneActive = 1;
    cCutsceneIndex = 0;
    cWaitTimer = 0;
    cWaiting = 0;
    cCutsceneTimer = 0;
    cExternalCutsceneTrigger = 0;
    gPlayerCameraState[0].cameraEvent = 0;
    cEventPointer = eventList[event];
}

void event_handler(void) {
    if (cCutsceneActive) {
        s32 eventCommand;
        struct Object *eventObj;
        f32 dist;



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
                case EVENT_WAIT_FOR_BUTTON_PRESS:
                    if (cWaiting == 0) {
                        cWaiting = 6;
                    }
                    
                break;
                case EVENT_DIALOG_AUTO:
                    create_automatic_dialog_box(param1);
                    cCutsceneIndex += 2;
                break;
                case EVENT_FAST_DIALOG_AUTO:
                    create_fast_automatic_dialog_box(param1);
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
                case EVENT_CAMERA_POSITION:
                    gCamera->pos[0] = param1;
                    gCamera->pos[1] = param2;
                    gCamera->pos[2] = param3;
                    cCutsceneIndex += 4;
                break;
                case EVENT_CAMERA_FOCUS:
                    gCamera->focus[0] = param1;
                    gCamera->focus[1] = param2;
                    gCamera->focus[2] = param3;
                    cMarioFocusSpeed = 0;
                    cCutsceneIndex += 4;
                break;
                case EVENT_CAMERA_SET_MARIO_AS_FOCUS:
                    cMarioFocusSpeed = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_CAMERA_ROTATE_AROUND_MARIO:
                    cRotateAroundMarioRadius = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_DISABLE_MARIO_RENDER:
                    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
                    cCutsceneIndex += 1;
                break;
                case EVENT_ENABLE_MARIO_RENDER:
                    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
                    cCutsceneIndex += 1;
                break;
                case EVENT_CAMERA_FOCUS_SPLINE_DATA:
                    cFocusSplineActive = 1;
                    cFocusSplineProgress = 0;
                    cFocusSplineSegment = 0;
                    gCamera->cutscene = 1;
                    focusSpline = splineList[cEventPointer[cCutsceneIndex + 1]];
                    cMarioFocusSpeed = 0;
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
                case EVENT_CANCEL_SPLINE_DATA:
                    cPositionSplineActive = 0;
                    cFocusSplineActive = 0;
                    cCutsceneIndex += 1;
                break;
                case EVENT_CAMERA_SHAKE:
                    set_camera_shake_from_point(SHAKE_POS_LARGE, param1, param2, param3);
                    cCutsceneIndex += 4;
                break;
                case EVENT_CAMERA_DOWN_VEL:
                    cCameraDownVel = param1;
                    cCutsceneIndex += 2;
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
                case EVENT_SET_MARIO_ROLL:
                    gMarioState->faceAngle[0] = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_SET_MARIO_ACTION:
                    gMarioState->action = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_SET_MARIO_ACTION_ARG:
                    gMarioState->actionArg = param1;
                    gMarioState->actionTimer = 0;
                    cCutsceneIndex += 2;
                break;
                case EVENT_SET_MARIO_CUSTOM_ANIMATION:
                    set_custom_mario_animation(gMarioState, param1);
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
                case EVENT_HUD_SET_EFFECT:
                    gSpecialHudRender = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_END_CUTSCENE:
                    gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
                    gCurCutscene = -1;
                    cMarioFocusSpeed = 0;
                    cCutsceneActive = 0;
                    cExternalCutsceneTrigger = 0;
                break;
                case EVENT_SHOW_BOSS_TITLE:
                    gHudDisplay.flags |= HUD_DISPLAY_BOSS_INTRO;
                    gHudDisplay.bossIntroTimer = 0;
                    gHudDisplay.bossID = param1;
                    cCutsceneIndex += 2;
                    
                break;
                case EVENT_SET_FB_EFFECT:
                    set_fb_effect_type(param1);
                    set_motion_blur(255);
                    set_fb_effect_col(255, 255, 255);
                    cCutsceneIndex += 2;
                break;
                case EVENT_CLEAR_FB_EFFECT:
                    set_fb_effect_type(FBE_EFFECT_NONE);
                    cCutsceneIndex += 1;
                break;
                case EVENT_SPAWN_OBJECT:
                    eventObj = spawn_object_abs_with_rot(gMarioState->marioObj, 0, cEventPointer[cCutsceneIndex + 9], cEventPointer[cCutsceneIndex + 8], 
                        param1, param2, param3, cEventPointer[cCutsceneIndex + 4], cEventPointer[cCutsceneIndex + 5], cEventPointer[cCutsceneIndex + 6]);
                    SET_BPARAM2(eventObj->oBehParams, cEventPointer[cCutsceneIndex + 7]);
                    cCutsceneIndex += 10;
                break;
                case EVENT_SET_EXTERNAL_TRIGGER:
                    cExternalCutsceneTrigger = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_SONG_PRIMARY:
                    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, param1), 0);
                    cCutsceneIndex += 2;
                break;
                case EVENT_SET_MARIO_EYE_STATE:
                    cEyeStateOverride = param1;
                    cCutsceneIndex += 2;
                break;
                case EVENT_MARIO_APPROACH_POINT:
                    marioCutsceneGoalWalkPos[0] = param1;
                    marioCutsceneGoalWalkPos[1] = param2;
                    marioCutsceneGoalWalkPos[2] = param3;
                    set_mario_action(gMarioState, ACT_MOVE_IN_CUTSCENE, 0);
                    cCutsceneIndex += 4;
                break;







                case EVENT_STONE_PATCH_PICKED_UP:
                    eventObj = obj_find_nearest_object_with_behavior(gMarioState->marioObj, bhvGroundCutscenePatch, &dist);
                    
                    eventObj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
                    eventObj = spawn_object_abs_with_rot(gMarioState->marioObj, 0, MODEL_GROUND_PATCH, bhvGroundPatch, 0, 0, 0, 0, -90, 0);
                    eventObj->oAction = 10;
                    gMarioState->heldObj = eventObj;
                    cCutsceneIndex += 1;
                break;

                case EVENT_STONE_PATCH_EQUIPPED:
                    if (gMarioState->heldObj) {

                        obj_mark_for_deletion(gMarioState->heldObj);
                        gMarioState->heldObj = NULL;
                    }
                    gMarioState->equippedPatch = PATCH_STONE;
                    gMarioState->updatePatch = 1;
                    cCutsceneIndex += 1;
                break;
                case EVENT_STONE_PATCH_BREAK_OUT:
                    gMarioState->forwardVel = 0;
                    gMarioState->curPatch = PATCH_STONE;
                    common_patch_cancel(gMarioState);
                    cCutsceneIndex += 1;
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
        else if (cWaiting == 6) {
            s32 param1 = cEventPointer[cCutsceneIndex + 1];
            if (gPlayer1Controller->buttonPressed & param1) {
                cWaiting = 0;
                cCutsceneIndex += 2;
            }
        }

        if (cPositionSplineActive) {
           cPositionSplineActive = !move_point_along_spline(gCamera->pos, segmented_to_virtual(posSpline), &cPositionSplineSegment,
                            &cPositionSplineProgress);
        }

        if (cFocusSplineActive) {
            cFocusSplineActive = !move_point_along_spline(gCamera->focus, segmented_to_virtual(focusSpline), &cFocusSplineSegment,
                            &cFocusSplineProgress);
        }

        if (cEyeStateOverride != -1) {
            gMarioState->marioBodyState->eyeState = cEyeStateOverride;
        }

        if (cMarioFocusSpeed > 0) {
            camera_approach_f32_symmetric_bool(&gCamera->focus[0], gMarioState->pos[0], cMarioFocusSpeed);
            camera_approach_f32_symmetric_bool(&gCamera->focus[1], gMarioState->pos[1] + 80, cMarioFocusSpeed);
            camera_approach_f32_symmetric_bool(&gCamera->focus[2], gMarioState->pos[2], cMarioFocusSpeed);
        }

        if (cRotateAroundMarioRadius > 0) {
            camera_approach_f32_symmetric_bool(&gCamera->pos[0], gMarioState->pos[0] + (cRotateAroundMarioRadius * sinf((f32)cCutsceneTimer / 10.0f)), 60.f);
            camera_approach_f32_symmetric_bool(&gCamera->pos[1], gMarioState->pos[1] + cRotateAroundMarioRadius / 3, 32.f);
            camera_approach_f32_symmetric_bool(&gCamera->pos[2], gMarioState->pos[2] + (cRotateAroundMarioRadius * cosf((f32)cCutsceneTimer / 10.0f)), 60.f);
        }

        if (cCameraDownVel != 0) {
            gCamera->pos[1] -= cCameraDownVel;
        }
    cCutsceneTimer++;
    }
}




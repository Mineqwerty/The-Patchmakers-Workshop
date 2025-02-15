#include "src/game/cutscene.h"
#include "levels/bowser_3/header.h"
#include "src/game/camera.h"

struct ObjectHitbox sMantleOfMadnessHitbox = {
    /* interactType:      */ INTERACT_MANTLE_OF_MADNESS,
    /* downOffset:        */ 150,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 20,
    /* numLootCoins:      */ 2,
    /* radius:            */ 1000,
    /* height:            */ 3000,
    /* hurtboxRadius:     */ 990,
    /* hurtboxHeight:     */ 2990,
};

#define MANTLE_OF_MADNESS_MAX_HP 300

enum MantleOfMadnessPhases {
    MANTLE_OF_MADNESS_PHASE_BEGINNING_DEFAULT,
    MANTLE_OF_MADNESS_PHASE_LASER_TURRETS,
    MANTLE_OF_MADNESS_PHASE_CRUSHING_HANDS,
    MANTLE_OF_MADNESS_PHASE_PLATFORMING,
    MANTLE_OF_MADNESS_PHASE_HAND_AND_EYES,
    MANTLE_OF_MADNESS_PHASE_BIG_NEEDLE,
};

enum MantleOfMadnessActions {
    MANTLE_OF_MADNESS_ACT_BEGINNING_CUTSCENE,
    MANTLE_OF_MADNESS_ACT_IDLE,
    MANTLE_OF_MADNESS_ACT_NEEDLE_BALL_STORM,
    MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE,
    MANTLE_OF_MADNESS_ACT_RAISE_SPIKE_WALL,
    MANTLE_OF_MADNESS_ACT_APPROACHING_LASER,

    MANTLE_OF_MADNESS_ACT_SPAWN_LASER_TURRETS,
    MANTLE_OF_MADNESS_ACT_SPAWN_MAD_HAND,
    MANTLE_OF_MADNESS_ACT_TRANSITION_TO_PLATFORMING,
    MANTLE_OF_MADNESS_ACT_SPAWN_HAND_AND_EYES,
    MANTLE_OF_MADNESS_ACT_SPAWN_FINAL_NEEDLE,
    MANTLE_OF_MADNESS_ACT_BIG_NEEDLE,
    MANTLE_OF_MADNESS_ACT_GETTING_STABBED
};

void mantle_of_madness_control_face_twitch(void) {

    if (o->oAction == MANTLE_OF_MADNESS_ACT_GETTING_STABBED) {
        return;
    }

    if (random_u16()%10 == 0) {
        o->oTwitchFrames = random_u16()%3 + 1;
    }

    if (o->oTwitchFrames < o->oEnemyInvincibilityTimer) {
        o->oTwitchFrames = o->oEnemyInvincibilityTimer;
    }

    cur_obj_set_model(MODEL_MANTLE_OF_MADNESS);
    if (o->oTwitchFrames > 0) {
        cur_obj_set_model(MODEL_MANTLE_OF_MADNESS_HURT);
        o->oTwitchFrames--;
    }
}

void mantle_of_madness_phase_transition(void) {
    //i might change HP later so i'm making it percentage based for now
    switch (o->oMantleOfMadnessPhase) {
        case MANTLE_OF_MADNESS_PHASE_BEGINNING_DEFAULT:
            if ((f32)o->oHealth / (f32)MANTLE_OF_MADNESS_MAX_HP < 0.98f) {
                o->oAction = MANTLE_OF_MADNESS_ACT_SPAWN_LASER_TURRETS;
                o->oMantleOfMadnessPhase++;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_LASER_TURRETS:
            if ((f32)o->oHealth / (f32)MANTLE_OF_MADNESS_MAX_HP < 0.7f) {
                o->oAction = MANTLE_OF_MADNESS_ACT_SPAWN_MAD_HAND;
                o->oMantleOfMadnessPhase++;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_CRUSHING_HANDS:
            if ((f32)o->oHealth / (f32)MANTLE_OF_MADNESS_MAX_HP < 0.5f) {
                o->oAction = MANTLE_OF_MADNESS_ACT_TRANSITION_TO_PLATFORMING;
                o->oMantleOfMadnessPhase++;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_PLATFORMING:
            if ((f32)o->oHealth / (f32)MANTLE_OF_MADNESS_MAX_HP < 0.25f) {
                o->oAction = MANTLE_OF_MADNESS_ACT_SPAWN_HAND_AND_EYES;
                o->oMantleOfMadnessPhase++;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_HAND_AND_EYES:
            if (o->oHealth <= 1) {
                o->oHealth = 1;
                o->oAction = MANTLE_OF_MADNESS_ACT_BIG_NEEDLE;
                o->oMantleOfMadnessPhase++;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_BIG_NEEDLE:
            if (o->oHealth <= 1) {
                o->oHealth = 1;
            }
        break;
    }
}

void mantle_of_madness_phase_update(void) {
    //i might change HP later so i'm making it percentage based for now
    switch (o->oMantleOfMadnessPhase) {
        case MANTLE_OF_MADNESS_PHASE_BEGINNING_DEFAULT:
            o->oMantleOfMadnessRageLevel = 1;
        break;
        case MANTLE_OF_MADNESS_PHASE_LASER_TURRETS:;
            s32 turretCount = count_objects_with_behavior(bhvMadLaserTurret);
            if (turretCount == 0) {
                o->oMantleOfMadnessRageLevel = 2;
            }
            else if (turretCount <= 2) {
                o->oMantleOfMadnessRageLevel = 1;
            }
            else {
                o->oMantleOfMadnessRageLevel = 0;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_CRUSHING_HANDS:
            if (o->oDistanceToMario < 500.0f) {
                o->oMantleOfMadnessRageLevel = 3;
            }
            else if (o->oHealth < (MANTLE_OF_MADNESS_MAX_HP * 0.6f)) {
                o->oMantleOfMadnessRageLevel = 1;
            }
            else {
                o->oMantleOfMadnessRageLevel = 0;
            }
            
        break;
        case MANTLE_OF_MADNESS_PHASE_PLATFORMING:
            if (o->oDistanceToMario < 3000.0f) {
                o->oMantleOfMadnessRageLevel = 2;
            }
            else {
                o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
                o->oTimer = 0;
            }
        break;
        case MANTLE_OF_MADNESS_PHASE_HAND_AND_EYES:
            if (o->oDistanceToMario < 500.0f) {
                o->oMantleOfMadnessRageLevel = 3;
            }
            else if (o->oHealth < (MANTLE_OF_MADNESS_MAX_HP * 0.1f)) {
                o->oMantleOfMadnessRageLevel = 1;
            }
            else {
                o->oMantleOfMadnessRageLevel = 0;
            }
            
        break;
        case MANTLE_OF_MADNESS_PHASE_BIG_NEEDLE:
            o->oHealth = 1;
        break;
    }
}

void mantle_of_madness_act_idle(void) {
    u16 nextActionTime = 180;
    if (o->oMantleOfMadnessRageLevel >= 1) {
        nextActionTime = 150;
    }
    if (o->oMantleOfMadnessRageLevel >= 3) {
        nextActionTime = 90;
    }

    if (o->oTimer >= nextActionTime) {
        mantle_of_madness_choose_attack();
        o->oMantleOfMadnessAttackCounter = 0;
    }
}

void mantle_of_madness_act_needle_ball_storm(void) {
    if (o->oTimer <= 30 || o->oTimer > 60) {
        if (o->oTimer % 4 == 0) {
            struct Object *needleBall = spawn_object_relative(0, 0, 600, 0, o, MODEL_NEEDLE_BALL, bhvNeedleBall);
            needleBall->oForwardVel = 100;
        }
    }

    if (o->oTimer >= 30 && o->oMantleOfMadnessAttackCounter == 0) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
    if (o->oTimer >= 90) {
        o->oMantleOfMadnessAttackCounter = 0;
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_needle_barrage(void) {
    
    if (o->oTimer <= 30 || o->oTimer > 60) {
        if (o->oTimer % 2 == 0) {
            struct Object *needleBall = spawn_object_relative(0, -1000, 100, random_u16()%300 - 150,  o, MODEL_PM_THROWN_NEEDLE, bhvPmThrownNeedle);
            //needleBall->oTimer = 28;
        }
    }

    if (o->oTimer >= 30 && o->oMantleOfMadnessAttackCounter == 0) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
    if (o->oTimer >= 70) {
        o->oMantleOfMadnessAttackCounter = 0;
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void spawn_spike_wall(struct Object *originObj) {
    s16 randomAngle = random_u16();
    //maybe make mario the parent for difficulty
    struct Object *spikeWall =
        spawn_object_relative(0, -200/*1000 * sins(randomAngle)*/, -1200, 1000 * coss(randomAngle), originObj,
                              MODEL_MAD_SPIKE_WALL, bhvMadSpikeWall);
    spikeWall->oPosY = -50;
}

void mantle_of_madness_act_raise_spike_wall(void) {
    if (o->oTimer == 5) {
        spawn_spike_wall(o);
    }
    
    if (o->oMantleOfMadnessRageLevel >= 2 && o->oTimer == 25) {
        spawn_spike_wall(gMarioState->marioObj);
    }

    if (o->oTimer == 30) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_approaching_laser(void) {
    if (o->oTimer % 4 == 0) {
        cur_obj_shake_screen(SHAKE_POS_MEDIUM);
    }

    if (o->oTimer == 30) {
        struct Object *laser = spawn_object_relative(0, 300, 2000, 0, o, MODEL_MAD_LASER, bhvTrackMarioLaser);
        laser->oFaceAngleYaw -= 0x4000;
        laser->oFaceAnglePitch = 0x3000;
    }
    if (o->oTimer == 150) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_spawn_laser_turrets(void) {
    enable_time_stop_including_mario();
    gCamera->cutscene = 1;
    gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX - 800, 90.0f);
    gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 1200, 90.0f);
    gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ, 90.0f);
    
    gLakituState.goalFocus[0] = approach_f32_symmetric(gLakituState.goalFocus[0], 0, 140.0f);
    gLakituState.goalFocus[1] = approach_f32_symmetric(gLakituState.goalFocus[1], 1200, 130.0f);
    gLakituState.goalFocus[2] = approach_f32_symmetric(gLakituState.goalFocus[2], 0, 140.0f);

    if (o->oTimer == 45) {
        for (int i = 0; i < 4; i++) {
            struct Object *laser = spawn_object_abs_with_rot(o, 0, MODEL_MAD_LASER_TURRET, bhvMadLaserTurret, 
            -400 + 800.0f * (1 - 2*(i%2)), 1250, 800.0f * (1 - 2*(i/2)),
            0, 0, 0);

            laser->oBehParams2ndByte = i;

            spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvMistParticleSpawner, 
            250.0f * (1 - 2*(i%2)), 1250, 250.0f * (1 - 2*(i/2)),
            0, 0, 0);

        }
    }

    if (o->oTimer == 75) {
        gCamera->cutscene = 0;
        disable_time_stop_including_mario();
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_spawn_mad_hand(void) {
    enable_time_stop_including_mario();
    gCamera->cutscene = 1;

    if (o->oTimer < 45) {
        gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX - 800, 90.0f);
        gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 1200, 90.0f);
        gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ, 90.0f);
        
        gLakituState.goalFocus[0] = approach_f32_symmetric(gLakituState.goalFocus[0], 0, 140.0f);
        gLakituState.goalFocus[1] = approach_f32_symmetric(gLakituState.goalFocus[1], 1200, 130.0f);
        gLakituState.goalFocus[2] = approach_f32_symmetric(gLakituState.goalFocus[2], 0, 140.0f);
    }
    else {
        gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX - 1800, 90.0f);
        gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 2800, 90.0f);
        gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ, 90.0f);
        
        gLakituState.goalFocus[0] = approach_f32_symmetric(gLakituState.goalFocus[0], 0, 140.0f);
        gLakituState.goalFocus[1] = approach_f32_symmetric(gLakituState.goalFocus[1], 1100, 130.0f);
        gLakituState.goalFocus[2] = approach_f32_symmetric(gLakituState.goalFocus[2], 0, 140.0f);
    }

    if (o->oTimer == 5) {
            struct Object *madHand = spawn_object_relative(0, -2500, 3000, 0, o, MODEL_MAD_SLAMMING_HAND, bhvMadSlammingHand);

            madHand->oAction = 8;
            madHand->oFaceAngleYaw = -0x4000;
            madHand->oVelY = -20;
    }

    if (o->oTimer == 95) {
        gCamera->cutscene = 0;
        disable_time_stop_including_mario();
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_transition_to_platforming(void) {
    switch (o->oSubAction) {
        case 0:
            begin_cutscene_event(CUTSCENE_EVENT_MANTLE_OF_MADNESS_PLATFORMING);
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger == 1) {
                o->oPosY = -6303;
                o->oPosX = 15277;
                o->oSubAction++;
            }
        break;
        case 2:
            if (gCurCutscene == -1) {
                o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
            }
        break;
    }
}

void mantle_of_madness_act_spawn_hand_and_eyes(void) {

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer == 1) {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 60, 255, 0, 0);
            }
            if (o->oTimer == 60) {
                o->oTimer = 0;
                o->oPosX = o->oHomeX;
                o->oPosY = o->oHomeY;
                gMarioState->pos[0] = -2887;
                gMarioState->pos[1] = 1200;
                gMarioState->pos[2] = 0;
                o->oSubAction++;
            }
        break;
        case 1:
            if (o->oTimer == 1) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 30, 255, 0, 0);
            }

            if (o->oTimer == 45)  {
                o->oTimer = 0;
                o->oSubAction++;
            }

        break;
        case 2:
        enable_time_stop_including_mario();
        gCamera->cutscene = 1;
    
        if (o->oTimer < 45) {
            gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX - 800, 90.0f);
            gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 1200, 90.0f);
            gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ, 90.0f);
            
            gLakituState.goalFocus[0] = approach_f32_symmetric(gLakituState.goalFocus[0], 0, 140.0f);
            gLakituState.goalFocus[1] = approach_f32_symmetric(gLakituState.goalFocus[1], 1200, 130.0f);
            gLakituState.goalFocus[2] = approach_f32_symmetric(gLakituState.goalFocus[2], 0, 140.0f);
        }
        else {
            gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX - 1800, 90.0f);
            gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 2800, 90.0f);
            gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ, 90.0f);
            
            gLakituState.goalFocus[0] = approach_f32_symmetric(gLakituState.goalFocus[0], 0, 140.0f);
            gLakituState.goalFocus[1] = approach_f32_symmetric(gLakituState.goalFocus[1], 1100, 130.0f);
            gLakituState.goalFocus[2] = approach_f32_symmetric(gLakituState.goalFocus[2], 0, 140.0f);
        }
    
        if (o->oTimer == 5) {
                struct Object *madHand = spawn_object_relative(0, -2500, 3000, 0, o, MODEL_MAD_SLAMMING_HAND, bhvMadSlammingHand);
    
                madHand->oAction = 8;
                madHand->oFaceAngleYaw = -0x4000;
                madHand->oVelY = -20;
        }

        if (o->oTimer == 45) {
            for (int i = 0; i < 4; i++) {
                struct Object *laser = spawn_object_abs_with_rot(o, 0, MODEL_MAD_LASER_TURRET, bhvMadLaserTurret, 
                -400 + 800.0f * (1 - 2*(i%2)), 1250, 800.0f * (1 - 2*(i/2)),
                0, 0, 0);
    
                laser->oBehParams2ndByte = i;
    
                spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvMistParticleSpawner, 
                250.0f * (1 - 2*(i%2)), 1250, 250.0f * (1 - 2*(i/2)),
                0, 0, 0);
    
            }
        }
    
        if (o->oTimer == 95) {
            gCamera->cutscene = 0;
            disable_time_stop_including_mario();
            o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
        }
        break;
    }
    
}

void mantle_of_madness_act_spawn_final_needle(void) {
    switch (o->oSubAction) {
        case 0:
            begin_cutscene_event(CUTSCENE_EVENT_MANTLE_OF_MADNESS_FINAL_NEEDLE);
            if (!o->oMantleOfMadnessFinalNeedle) {
                o->oMantleOfMadnessFinalNeedle = spawn_object_relative(0, 0, 0, 0, o, MODEL_FINAL_NEEDLE, bhvFinalNeedle);
            }
            o->oSubAction = 1;
        break;
        case 1:
            if (gCurCutscene == -1) {
                o->oAction = MANTLE_OF_MADNESS_ACT_BIG_NEEDLE;
            }
        break;
    }
}

u8 mario_holding_down_all_needle_inputs(void) {

    u64 inputs = 1;

    if (o->oMantleOfMadnessFinalNeedleProgress >= 1) {
        inputs *= gPlayer1Controller->buttonDown & A_BUTTON;
    }
    if (o->oMantleOfMadnessFinalNeedleProgress >= 2) {
        inputs *= gPlayer1Controller->buttonDown & B_BUTTON;
    }
    if (o->oMantleOfMadnessFinalNeedleProgress >= 3) {
        inputs *= gPlayer1Controller->buttonDown & Z_TRIG;
    }
    if (o->oMantleOfMadnessFinalNeedleProgress >= 4) {
        inputs *= gPlayer1Controller->buttonDown & R_TRIG;
    }

    return (inputs) && (gPlayer1Controller->rawStickY < -6);
}

s16 mmPositionSplineSegment = 0;
f32 mmPositionSplineProgress = 0;

s16 mmFocusSplineSegment = 0;
f32 mmFocusSplineProgress = 0;

void mantle_of_madness_act_big_needle(void) {

    
    gMarioState->action = ACT_PULLING_FINAL_NEEDLE;

    f32 gainFactor = -0.004f;

    if (gFinalNeedleProgress >= 0.15f) {
        if (o->oMantleOfMadnessFinalNeedleProgress < 1) {
            o->oMantleOfMadnessFinalNeedleProgress = 1;
        }
    }
    if (gFinalNeedleProgress >= 0.25f) {
        if (o->oMantleOfMadnessFinalNeedleProgress < 2) {
            o->oMantleOfMadnessFinalNeedleProgress = 2;
        }
    }
    if (gFinalNeedleProgress >= 0.50f) {
        if (o->oMantleOfMadnessFinalNeedleProgress < 3) {
            o->oMantleOfMadnessFinalNeedleProgress = 3;
        }
    }
    if (gFinalNeedleProgress >= 0.75f) {
        if (o->oMantleOfMadnessFinalNeedleProgress < 4) {
            o->oMantleOfMadnessFinalNeedleProgress = 4;
        }
    }

    if (mario_holding_down_all_needle_inputs()) {
        gainFactor = 0.004f;
    }
    gFinalNeedleProgress = CLAMP(gFinalNeedleProgress + gainFactor, 0.0f, 1.0f);

    if (gFinalNeedleProgress == 1) {
        o->oMantleOfMadnessFinalNeedleProgress = 5;
    }

    gFinalNeedleDelta = gainFactor;
    gFinalNeedleStage = o->oMantleOfMadnessFinalNeedleProgress;
    

    gRenderFinalNeedlePrompts = 1;
    gCamera->cutscene = 1;

    
    gCutsceneFOV = 45 + 30*gFinalNeedleProgress;;

    if (gFinalNeedleProgress > 0 && gFinalNeedleProgress < 1 && gFinalNeedleStage < 5) {
        move_point_along_spline_with_direction(gCamera->pos, segmented_to_virtual(bowser_3_area_1_spline_FinalNeedleSplinePos), &mmPositionSplineSegment,
                            &mmPositionSplineProgress, (gainFactor >= 0 ? 1 : -1));
        move_point_along_spline_with_direction(gCamera->focus, segmented_to_virtual(bowser_3_area_1_spline_FinalNeedleSplineFocus), &mmFocusSplineSegment,
                            &mmFocusSplineProgress, (gainFactor >= 0 ? 1 : -1));
    }

    if (gFinalNeedleStage < 5) {
        gLakituState.goalPos[0] = gCamera->pos[0];
        gLakituState.goalPos[1] = gCamera->pos[1];
        gLakituState.goalPos[2] = gCamera->pos[2];
        gLakituState.goalFocus[0] = gCamera->focus[0];
        gLakituState.goalFocus[1] = gCamera->focus[1];
        gLakituState.goalFocus[2] = gCamera->focus[2];
    }
    else {
        if (!mario_holding_down_all_needle_inputs()) {
            o->oMantleOfMadnessFinalNeedleProgress = 6;
            gFinalNeedleStage = 6;
            gMarioState->action = ACT_RELEASED_FINAL_NEEDLE;
            o->oAction = MANTLE_OF_MADNESS_ACT_GETTING_STABBED;
        }
    }
}

void mantle_of_madness_act_getting_stabbed(void) {
    gCamera->cutscene = 1;
    gRenderFinalNeedlePrompts = 0;
    
    if (o->oTimer == 20) {
        cur_obj_shake_screen(SHAKE_POS_MEDIUM);
    }
    if (o->oTimer > 10) {
        gLakituState.goalPos[0] = 100;
        gLakituState.goalPos[1] = 3000;
        gLakituState.goalPos[2] = 500;
        gLakituState.goalFocus[0] = 1200;
        gLakituState.goalFocus[1] = 2900;
        gLakituState.goalFocus[2] = 100;
    }

    if (o->oTimer == 30) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 120, 255, 255, 255);
    }

    if (o->oTimer > 30 && o->oTimer % 10 == 0) {
        struct Object *deathRay = spawn_object_relative(0, 0, 1000, 0, o, MODEL_MANTLE_DEATH_RAY, bhvMantleDeathRay);

        deathRay->oFaceAngleYaw = random_u16();
        deathRay->oFaceAnglePitch = -(random_u16() / 2);
    }
}

void mantle_of_madness_choose_attack(void) {
    u32 attack;
    why_am_i_using_goto:
    switch (random_u16()%4) {
        case 0:
            attack = MANTLE_OF_MADNESS_ACT_NEEDLE_BALL_STORM;
        break;
        case 1:
            attack = MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE;
        break;
        case 2:
            attack = MANTLE_OF_MADNESS_ACT_RAISE_SPIKE_WALL;
        break;
        case 3:
            attack = MANTLE_OF_MADNESS_ACT_APPROACHING_LASER;
        break;

    }

    if (o->oMantleOfMadnessRageLevel >= 2) {
        o->oMantleOfMadnessAttackCounter = 1;
    }

    if (attack == o->oMantleOfMadnessLastAttack) {
        goto why_am_i_using_goto;
    }

    o->oAction = attack;
}


void bhv_mantle_of_madness_init(void) {
    obj_set_hitbox(o, &sMantleOfMadnessHitbox);
    o->oHealth = MANTLE_OF_MADNESS_MAX_HP;
    gBossMaxHealth = MANTLE_OF_MADNESS_MAX_HP;
    gBossHealth = MANTLE_OF_MADNESS_MAX_HP;
    o->oTwitchFrames = 0;
    o->oMantleOfMadnessPhase = MANTLE_OF_MADNESS_PHASE_BEGINNING_DEFAULT;
    o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    o->oMantleOfMadnessRageLevel = 0;
    o->oMantleOfMadnessFinalNeedleProgress = 0;

    o->oMantleOfMadnessPhase = MANTLE_OF_MADNESS_PHASE_BIG_NEEDLE;
    o->oHealth = MANTLE_OF_MADNESS_MAX_HP*0.01f;
    o->oAction = MANTLE_OF_MADNESS_ACT_SPAWN_FINAL_NEEDLE;
}

void bhv_mantle_of_madness_loop(void) {
    
    mantle_of_madness_phase_transition();
    mantle_of_madness_phase_update();
    switch (o->oAction) {
        case MANTLE_OF_MADNESS_ACT_IDLE:
            mantle_of_madness_act_idle();
        break;
        case MANTLE_OF_MADNESS_ACT_NEEDLE_BALL_STORM:
            mantle_of_madness_act_needle_ball_storm();
        break;
        case MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE:
            mantle_of_madness_act_needle_barrage();
        break;
        case MANTLE_OF_MADNESS_ACT_RAISE_SPIKE_WALL:
            mantle_of_madness_act_raise_spike_wall();
        break;
        case MANTLE_OF_MADNESS_ACT_APPROACHING_LASER:
            mantle_of_madness_act_approaching_laser();
        break;


        case MANTLE_OF_MADNESS_ACT_SPAWN_LASER_TURRETS:
            mantle_of_madness_act_spawn_laser_turrets();
        break;
        case MANTLE_OF_MADNESS_ACT_SPAWN_MAD_HAND:
            mantle_of_madness_act_spawn_mad_hand();
        break;
        case MANTLE_OF_MADNESS_ACT_TRANSITION_TO_PLATFORMING:
            mantle_of_madness_act_transition_to_platforming();
        break;
        case MANTLE_OF_MADNESS_ACT_SPAWN_HAND_AND_EYES:
            mantle_of_madness_act_spawn_hand_and_eyes();
        break;
        case MANTLE_OF_MADNESS_ACT_SPAWN_FINAL_NEEDLE:
            mantle_of_madness_act_spawn_final_needle();
        break;
        case MANTLE_OF_MADNESS_ACT_BIG_NEEDLE:
            mantle_of_madness_act_big_needle();
        break;
        case MANTLE_OF_MADNESS_ACT_GETTING_STABBED:
            mantle_of_madness_act_getting_stabbed();
        break;
    }

    mantle_of_madness_control_face_twitch();
    o->oInteractStatus = 0;

    if (o->oAction != MANTLE_OF_MADNESS_ACT_IDLE) {
        o->oMantleOfMadnessLastAttack = o->oAction;
    }

    gBossHealth = o->oHealth;

}


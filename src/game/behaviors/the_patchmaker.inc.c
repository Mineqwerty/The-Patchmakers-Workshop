#include "src/game/cutscene.h"

enum PatchmakerActions {
    PATCHMAKER_ACT_FIRST_CUTSCENE,
    PATCHMAKER_ACT_WALK_TO_MARIO,
    PATCHMAKER_ACT_JUMPS,
    PATCHMAKER_ACT_SLASH_DASH,
    PATCHMAKER_ACT_GRAB_MARIO,
    PATCHMAKER_ACT_THROW_STRING,
    PATCHMAKER_ACT_SLOW_NEEDLE_WALK,
    PATCHMAKER_ACT_SUMMON_NEEDLE_BALL,
    PATCHMAKER_ACT_SHOCKWAVE,
    PATCHMAKER_ACT_NEEDLE_STORM,
    PATCHMAKER_ACT_STONE_FLOWER,
    PATCHMAKER_ACT_ICE_SPIKES,
    PATCHMAKER_ACT_GRAPPLE,
    PATCHMAKER_ACT_HALO,
    PATCHMAKER_ACT_MARINE_BUBBLES,
    PATCHMAKER_ACT_SHADOWCHOMP,
    PATCHMAKER_ACT_TRANSMUTATION_NEEDLE,
    PATCHMAKER_ACT_BREEZE_SPIN,
    PATCHMAKER_ACT_PORTAL_TO_MARIO,
    PATCHMAKER_ACT_EXTENSION,

    PATCHMAKER_ACT_DEFEATED,
    PATCHMAKER_ACT_SECOND_CUTSCENE,
    PATCHMAKER_ACT_THIRD_CUTSCENE
};

enum PatchmakerAnims {
    PATCHMAKER_ANIM_IDLE,
    PATCHMAKER_ANIM_WALK,
    PATCHMAKER_ANIM_SLICE,
    PATCHMAKER_ANIM_JUMP,
    PATCHMAKER_ANIM_JUMP_END,
    PATCHMAKER_ANIM_POINT,
    PATCHMAKER_ANIM_START_GRAB,
    PATCHMAKER_ANIM_GRAB_MISS,
    PATCHMAKER_ANIM_GRAB_MARIO_ATTACK,
    PATCHMAKER_ANIM_STRING_THROW,
    PATCHMAKER_ANIM_START_SLOW_NEEDLE_WALK,
    PATCHMAKER_ANIM_SLOW_NEEDLE_WALK,
    PATCHMAKER_ANIM_END_NEEDLE_WALK,
    PATCHMAKER_ANIM_NEEDLE_WALK_SLASH,
    PATCHMAKER_ANIM_SNAP,
    PATCHMAKER_ANIM_TURN_FIRST_CUTSCENE,
    PATCHMAKER_ANIM_REVERSED_IDLE,
    PATCHMAKER_ANIM_START_HEAD_GRAB,
    PATCHMAKER_ANIM_HEAD_GRAB,
    PATCHMAKER_ANIM_SCREAM_AT_SKY,
    PATCHMAKER_ANIM_START_ARM_SWAY,
    PATCHMAKER_ANIM_ARM_SWAY,
    PATCHMAKER_ANIM_SWERVE_ZOOM_IN,
    PATCHMAKER_ANIM_SWERVE_TWITCHING,
    PATCHMAKER_ANIM_FIRST_FIGHT_SPLASH_SCREEN,
    PATCHMAKER_ANIM_DEFEATED_RUN_AWAY,
    PATCHMAKER_ANIM_FALL_TO_GROUND,
    PATCHMAKER_ANIM_REACH_TO_MARIO,
    PATCHMAKER_ANIM_THROW_MARIO_DOWN,
    PATCHMAKER_ANIM_CURL_UP_SHOCKWAVE,
    PATCHMAKER_ANIM_TURN_TO_CAMERA,
    PATCHMAKER_ANIM_STOMP_TO_SEWNIA,
    PATCHMAKER_ANIM_GRAB_SEWNIA,
    PATCHMAKER_ANIM_GRAB_SEWNIA_IDLE,
    PATCHMAKER_ANIM_FROZEN_ARMS_OUT,
    PATCHMAKER_ANIM_WALK_AWAY_FROM_FIGHT,
    PATCHMAKER_ANIM_GROVEL,
    PATCHMAKER_ANIM_GROVEL_SHAKE,
    PATCHMAKER_ANIM_GROVEL_STAND,
    PATCHMAKER_ANIM_SUMMON_WALL,
    PATCHMAKER_ANIM_THIRD_DEFEAT,
    PATCHMAKER_ANIM_TRANSFORM_TO_MANTLE
};

#define PATCHMAKER_1_MAX_HEALTH 35
#define PATCHMAKER_2_MAX_HEALTH 60
#define PATCHMAKER_3_MAX_HEALTH 80
#define PATCHMAKER_SECOND_FIGHT (gCurrLevelNum == LEVEL_BOWSER_2)
#define PATCHMAKER_THIRD_FIGHT (gCurrLevelNum == LEVEL_BOWSER_3)

u8 firstCutsceneDone = 0;
u8 secondCutsceneDone = 0;
u8 thirdCutsceneDone = 0;

static struct ObjectHitbox sPatchmakerHitbox = {
    /* interactType:      */ INTERACT_PUSH_OUT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ PATCHMAKER_1_MAX_HEALTH,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void patchmaker_transition_to_next_action() {
    u16 randomAction = random_u16();
    u16 nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;

    switch (o->oAction) {
        case PATCHMAKER_ACT_FIRST_CUTSCENE:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_WALK_TO_MARIO:;

            u8 standardAttack = random_u16() % 10;

            if (standardAttack < 6) {
                if (o->oDistanceToMario < 250) {
                    switch (randomAction % 5) {
                        case 0:
                        case 1:
                        case 2:
                            nextAction = PATCHMAKER_ACT_GRAB_MARIO;
                        break;
                        case 3:
                        case 4:
                            nextAction = PATCHMAKER_ACT_SLASH_DASH;
                        break;
                        case 5:
                            nextAction = PATCHMAKER_ACT_SHOCKWAVE;
                        break;
                    }
                }
                else if (o->oDistanceToMario < 900) {
                    switch (randomAction % 4) {
                        case 0:
                            nextAction = PATCHMAKER_ACT_THROW_STRING;
                        break;
                        case 1:
                            nextAction = PATCHMAKER_ACT_SLASH_DASH;
                        break;
                        case 2:
                            nextAction = PATCHMAKER_ACT_SHOCKWAVE;
                        break;
                        case 3:
                            nextAction = PATCHMAKER_ACT_NEEDLE_STORM;
                        break;
                    }
                }
                else {
                    switch (randomAction % 3 + (o->oPatchmakerNeedleBallObj == NULL)) {
                        case 0:
                            nextAction = PATCHMAKER_ACT_JUMPS;
                        break;
                        case 1:
                            nextAction = PATCHMAKER_ACT_THROW_STRING;
                        break;
                        case 2:
                            nextAction = PATCHMAKER_ACT_NEEDLE_STORM;
                        break;
                        case 3:
                            nextAction = PATCHMAKER_ACT_SUMMON_NEEDLE_BALL;
                        break;
                        
                    }
                }
            }
            else {
                switch (gCurrLevelNum) {
                    case LEVEL_BOWSER_1:
                        switch (random_u16()%4) {
                            case 0:
                                nextAction = PATCHMAKER_ACT_STONE_FLOWER;
                            break;
                            case 1:
                                nextAction = PATCHMAKER_ACT_ICE_SPIKES;
                            break;
                            case 2:
                                nextAction = PATCHMAKER_ACT_GRAPPLE;
                            break;
                            case 3:
                                nextAction = PATCHMAKER_ACT_HALO;
                            break;
                        }
                    break;
                    case LEVEL_BOWSER_2:
                        switch (random_u16()%4) {
                            case 0:
                                nextAction = PATCHMAKER_ACT_MARINE_BUBBLES;
                            break;
                            case 1:
                                nextAction = PATCHMAKER_ACT_SHADOWCHOMP;
                            break;
                            case 2:
                                nextAction = PATCHMAKER_ACT_TRANSMUTATION_NEEDLE;
                            break;
                            case 3:
                                nextAction = PATCHMAKER_ACT_BREEZE_SPIN;
                            break;
                        }
                    break;
                    case LEVEL_BOWSER_3:
                        switch (random_u16()%2) {
                            case 0:
                                nextAction = PATCHMAKER_ACT_PORTAL_TO_MARIO;
                            break;
                            case 1:
                                nextAction = PATCHMAKER_ACT_EXTENSION;
                            break;
                        }
                    break;
                }
            }
            
        break;
        case PATCHMAKER_ACT_JUMPS:
            if (o->oDistanceToMario < 250) {
                nextAction = PATCHMAKER_ACT_GRAB_MARIO;
            }
            else {
                nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
            }
            
        break;
        case PATCHMAKER_ACT_SLASH_DASH:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_GRAB_MARIO:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_THROW_STRING:
            if (o->oSubAction == 1) {
                nextAction = PATCHMAKER_ACT_SLOW_NEEDLE_WALK;
            }
            else {
                nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
            }
        break;

        case PATCHMAKER_ACT_SLOW_NEEDLE_WALK:
            switch (randomAction % 2) {
                    case 0:
                        nextAction = PATCHMAKER_ACT_JUMPS;
                    break;
                    case 1:
                        nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
                    break;
                }
        break;

        case PATCHMAKER_ACT_SUMMON_NEEDLE_BALL:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_SHOCKWAVE:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_NEEDLE_STORM:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_STONE_FLOWER:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_ICE_SPIKES:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_GRAPPLE:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_HALO:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_MARINE_BUBBLES:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_SHADOWCHOMP:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_TRANSMUTATION_NEEDLE:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_BREEZE_SPIN:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_PORTAL_TO_MARIO:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_EXTENSION:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
    }

    if (gMarioState->health <= 255) {
        nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
    }

    o->oAction = nextAction;
    o->oSubAction = 0;

    //start at a random jump if the next action is the jumps
    if (nextAction == PATCHMAKER_ACT_JUMPS) {
        o->oSubAction += random_u16()%2;
    }
}

void patchmaker_set_boss_cam(void) {
    gSecondCameraFocus = o;
    gCamera->cutscene = 0;
    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    gCamera->controlBossCameraYaw = 1;
}

void patchmaker_fight_start(void) {
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_BOSS_KOOPA_FINAL), 0);
    o->oAction = PATCHMAKER_ACT_NEEDLE_STORM;
                gBossMaxHealth = (PATCHMAKER_SECOND_FIGHT ? PATCHMAKER_2_MAX_HEALTH : PATCHMAKER_1_MAX_HEALTH);
                gBossHealth = (PATCHMAKER_SECOND_FIGHT ? PATCHMAKER_2_MAX_HEALTH : PATCHMAKER_1_MAX_HEALTH);

                if (PATCHMAKER_THIRD_FIGHT) {
                    gBossMaxHealth = PATCHMAKER_3_MAX_HEALTH;
                    gBossHealth = PATCHMAKER_3_MAX_HEALTH;
                }

                cur_obj_init_animation(1);
                patchmaker_set_boss_cam();

                if (PATCHMAKER_THIRD_FIGHT) {
                    thirdCutsceneDone = 1;
                }
                else if (PATCHMAKER_SECOND_FIGHT) {
                    secondCutsceneDone = 1;
                }
                else {
                    firstCutsceneDone = 1;
                }
}

void patchmaker_act_first_fight_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_FIRST_FIGHT_INTRO);
            o->oSubAction++;
        break;
        case 1:
            if (o->oTimer == 60) {
                cur_obj_init_animation(PATCHMAKER_ANIM_TURN_FIRST_CUTSCENE);
                o->oSubAction++;
            }
        break;
        case 2:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PATCHMAKER_ANIM_REVERSED_IDLE);
            }

            if (cExternalCutsceneTrigger == 1) {
                o->oSubAction++;
                cur_obj_init_animation(PATCHMAKER_ANIM_START_HEAD_GRAB);
                o->oMoveAngleYaw += 0x8000;
                o->oFaceAngleYaw += 0x8000;
            }
        break;
        case 3:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PATCHMAKER_ANIM_HEAD_GRAB);
            }

            if (cExternalCutsceneTrigger == 2) {
                o->oSubAction++;
                cur_obj_init_animation(PATCHMAKER_ANIM_SCREAM_AT_SKY);
            }
        break;
        case 4:
            if (cExternalCutsceneTrigger == 3) {
                o->oSubAction++;
                cur_obj_init_animation(PATCHMAKER_ANIM_START_ARM_SWAY);
            }
        break;
        case 5:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PATCHMAKER_ANIM_ARM_SWAY);
            }
            if (cExternalCutsceneTrigger == 4) {
                o->oSubAction++;
                cur_obj_init_animation(PATCHMAKER_ANIM_SWERVE_ZOOM_IN);
            }
        break;
        case 6:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PATCHMAKER_ANIM_SWERVE_TWITCHING);
            }
            if (cExternalCutsceneTrigger == 5) {
                o->oSubAction++;
                cur_obj_init_animation(PATCHMAKER_ANIM_FIRST_FIGHT_SPLASH_SCREEN);
            }
            break;
        case 7:
            if (gCurCutscene == -1) {
                patchmaker_fight_start();
            }
        break;
    }

    if (cExternalCutsceneTrigger == EXTERNAL_TRIGGER_CUTSCENE_SKIPPED) {
        patchmaker_fight_start();
    }
}

void patchmaker_act_second_fight_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_SECOND_FIGHT_INTRO);
            cur_obj_hide();
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 3) {
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_POINT, 1.0f);
                //o->header.gfx.animInfo.animFrame = 30;
                cur_obj_unhide();
                o->oSubAction++;
            }
        break;
        case 2:
            if (cExternalCutsceneTrigger >= 4) {
                cur_obj_init_animation(PATCHMAKER_ANIM_HEAD_GRAB);
                o->oTimer = 0;
                o->oSubAction++;
            }
        break;
        case 3:
            if (o->oTimer == 60) {
                o->oPosX = 300;
                o->oPosY = 1000;
                o->oPosZ = -40;
                o->oFaceAngleYaw = -0x4000;
                o->oMoveAngleYaw = -0x4000;
            }
            
            if (cExternalCutsceneTrigger >= 5) {
                    cur_obj_shake_screen(SHAKE_POS_LARGE);
                    o->oSubAction++;
                o->oPosX = 300;
                o->oPosY = 1000;
                o->oPosZ = -40;
                o->oFaceAngleYaw = -0x4000;
                o->oMoveAngleYaw = -0x4000;
            }
        break;
        case 4:
            if (gCurCutscene == -1) {
                patchmaker_fight_start();
            }
        break;
    }

    if (cExternalCutsceneTrigger == EXTERNAL_TRIGGER_CUTSCENE_SKIPPED) {
        o->oPosX = 300;
                o->oPosY = 1000;
                o->oPosZ = -40;
                o->oFaceAngleYaw = -0x4000;
                o->oMoveAngleYaw = -0x4000;
                patchmaker_fight_start();
    }
}

void spawn_patchmaker_miasma(void) {
    for (int i = 0; i < 4; i++) {
        struct Object *ribbon = spawn_object_relative(i, 0, 80, 0, o, MODEL_PM_MIASMA, bhvPmMiasma);
        ribbon->oFaceAngleRoll = 0x2000 * i - 0x3000;
    }
}

void patchmaker_act_third_fight_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_THIRD_FIGHT_INTRO);
            cur_obj_init_animation(PATCHMAKER_ANIM_GROVEL);
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                cur_obj_init_animation(PATCHMAKER_ANIM_GROVEL_SHAKE);
                o->oSubAction++;
            }
        break;
        case 2:  
            if (cExternalCutsceneTrigger >= 2) {
                cur_obj_init_animation(PATCHMAKER_ANIM_GROVEL);
                o->oSubAction++;
            }
        break;
        case 3:
        if (cExternalCutsceneTrigger >= 3) {
            cur_obj_init_animation(PATCHMAKER_ANIM_GROVEL_STAND);
            spawn_patchmaker_miasma();
            o->oSubAction++;
        }
        break;
        case 4:
        if (gCurCutscene == -1) {
            patchmaker_fight_start();
        }
        break;
    }

    if (cExternalCutsceneTrigger == EXTERNAL_TRIGGER_CUTSCENE_SKIPPED) {
        spawn_patchmaker_miasma();
        patchmaker_fight_start();
    }
}

void patchmaker_act_walk_to_mario(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    cur_obj_init_animation(PATCHMAKER_ANIM_WALK);
    o->oForwardVel = 0.4f;
    object_step();

    if (o->oTimer >= 45 - (PATCHMAKER_1_MAX_HEALTH - o->oHealth)) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_jumps(void) {

    if (o->oTimer == 12) {
        cur_obj_init_animation(PATCHMAKER_ANIM_JUMP);
    }

    if (o->oTimer == 26) {
        o->oVelY = 25.0f;
        o->oForwardVel = 23.0f;
        if (o->oSubAction == 2) {
            if (random_u16()%2 == 0) {
                o->oMoveAngleYaw = o->oAngleToMario;
                f32 dist;
                vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
                o->oForwardVel = 0.05*dist;
                o->oVelY = 30.0f;
            }
            else {
                o->oMoveAngleYaw = random_u16();
            }
        }
        else {
            o->oMoveAngleYaw = random_u16();
        }
    }

    o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x400);

    s16 collisionFlags = object_step();

    if (((collisionFlags & OBJ_COL_FLAG_GROUNDED) && o->oTimer > 30 ) || o->oTimer >= 85) {
        o->oTimer = 0;
        o->oForwardVel = 0;
        o->oSubAction++;
        cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_JUMP_END, 2.0f);

        if (o->oSubAction == 3) {
            patchmaker_transition_to_next_action();
            o->oMoveAngleYaw = o->oFaceAngleYaw;
        }
    }

}

void patchmaker_act_slash_dash(void) {
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SLICE);
        o->oMoveAngleYaw = o->oAngleToMario;
        if (PATCHMAKER_SECOND_FIGHT) {
            o->oPatchmakerNumAttacksLeft = 2;
        }
    }

    if (o->oTimer < 20) {
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    }

    if (o->oTimer == 20) {
        o->oForwardVel = 30.0f;
        o->oInteractType = INTERACT_DAMAGE;
        cur_obj_play_sound_1(SOUND_NEW_SLASH_AIR);
    }

    if (o->oTimer > 40) {
        o->oForwardVel = CLAMP(o->oForwardVel-1, 0, 30);
    }

    object_step();

    if (cur_obj_check_if_at_animation_end()) {
        if (o->oPatchmakerNumAttacksLeft > 0) {
            o->oTimer = 19;
            o->header.gfx.animInfo.animFrame = 19;
            o->oMoveAngleYaw = o->oAngleToMario;
            o->oPatchmakerNumAttacksLeft--;
        }
        else {
            o->oInteractType = INTERACT_PUSH_OUT;
            patchmaker_transition_to_next_action();
        }
    }
}

void patchmaker_act_grab_mario(void) {
    cur_obj_become_intangible();
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer <= 1) {
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_START_GRAB, (PATCHMAKER_SECOND_FIGHT ? 2.0f : 1.5f));
            }

            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

            if (cur_obj_check_if_near_animation_end()) {
                if ((o->oAngleToMario) < 0x4000 && o->oDistanceToMario < 250) {
                    o->oSubAction = 2;
                }
                else {
                    o->oSubAction = 1;
                }
            }

        break;
        case 1:
            //grab fail
            if (PATCHMAKER_SECOND_FIGHT) {
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_GRAB_MISS, 1.5f);
            }
            else {
                cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_MISS);
            }
            
            cur_obj_become_tangible();
            if (cur_obj_check_if_near_animation_end()) {
                patchmaker_transition_to_next_action();
            }
        break;
        case 2:
            //grab success
            cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_MARIO_ATTACK);

            gCamera->cutscene = 1;
            gLakituState.goalPos[0] = approach_f32_symmetric(gLakituState.goalPos[0], o->oPosX + 800 * -coss(o->oFaceAngleYaw), 50);
            gLakituState.goalPos[1] = approach_f32_symmetric(gLakituState.goalPos[1], o->oPosY + 300, 40);
            gLakituState.goalPos[2] = approach_f32_symmetric(gLakituState.goalPos[2], o->oPosZ + 300 * sins(o->oFaceAngleYaw), 50);

            if (o->oTimer < 66) {
            gMarioState->action = ACT_STORY_CUTSCENE;
            gMarioState->pos[0] = o->oPosX + 70 * sins(o->oFaceAngleYaw);
            gMarioState->pos[2] = o->oPosZ + 70 * coss(o->oFaceAngleYaw);
            gMarioState->pos[1] = o->oPosY + 100;
            gMarioState->faceAngle[1] = o->oFaceAngleYaw;
            set_mario_animation(gMarioState, MARIO_ANIM_DROWNING_PART1);
            }
            else if (o->oTimer == 66) {
                gMarioState->action = ACT_FORWARD_AIR_KB;
                gMarioState->forwardVel  = 30.0f;
                gMarioState->vel[1] = 10.0f;
            }

            if (o->oTimer == 42 || o->oTimer == 54 || o->oTimer == 66) {
                take_damage_from_no_interact_object(gMarioState, 1);
                gMarioState->pos[0] += random_u16()%20 - 10;
                gMarioState->pos[1] += random_u16()%20 - 10;
                gMarioState->pos[2] += random_u16()%20 - 10;
                cur_obj_play_sound_1(SOUND_ACTION_HIT_2);
            }

            if (cur_obj_check_if_at_animation_end()) {
                patchmaker_set_boss_cam();
                cur_obj_become_tangible();
                patchmaker_transition_to_next_action();
            }
        break;
    }

}

void patchmaker_act_throw_string(void) {
    //when above a certain health, the string attack happens less often
    if (o->oTimer == 1 && o->oHealth > 40 && random_u16()%2 == 0) {
        o->oAction = PATCHMAKER_ACT_JUMPS;
        return;
    }

    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_STRING_THROW);
    }

    if (o->oTimer == 50) {
        struct Object *string = spawn_object_relative(0, 0, 300, 0, o, MODEL_THROWN_STRING, bhvThrownString);
        o->oPatchmakerChildObj = string;
    }

    

    if (o->oTimer > 40) {
        o->oAngleVelYaw = approach_s16_symmetric(o->oAngleVelYaw, 450 + (PATCHMAKER_SECOND_FIGHT ? 12 : 6)*o->oTimer, 100);
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);

        o->oForwardVel = (PATCHMAKER_SECOND_FIGHT ? 30.0f : 20.0f);

        if (o->oTimer % 24 == 0) {
            cur_obj_play_sound_1(SOUND_ACTION_SIDE_FLIP_UNK);
        }
    }
    else {
        o->oAngleVelYaw -= 6*o->oTimer;
        if (o->oTimer % 12 == 0) {
            cur_obj_play_sound_1(SOUND_ACTION_SIDE_FLIP_UNK);
        }
    }

    o->oFaceAngleYaw += o->oAngleVelYaw;

    object_step();

    if (o->oSubAction == 1) {
        patchmaker_transition_to_next_action();
    }
    else if (o->oTimer > 240) {
        obj_mark_for_deletion(o->oPatchmakerChildObj);
        patchmaker_transition_to_next_action();
    }
    

    
}

void patchmaker_act_slow_needle_walk(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(PATCHMAKER_ANIM_START_SLOW_NEEDLE_WALK);
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

            if (o->oTimer == 17) {
                cur_obj_play_sound_1(SOUND_NEW_START_SCRAPE);
            }
            
            if (cur_obj_check_if_at_animation_end()) {
                o->oSubAction = 1;
                cur_obj_play_sound_2(SOUND_NEW_LONG_SCRAPE);
            }
        break;
        case 1:
            cur_obj_init_animation(PATCHMAKER_ANIM_SLOW_NEEDLE_WALK);
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            o->oForwardVel = (PATCHMAKER_SECOND_FIGHT ? 7.0f : 5.4f);
            object_step();
            
            if (o->oTimer % 25 == 0) {
                cur_obj_play_sound_1(SOUND_NEW_LONG_SCRAPE);
            }

            struct Object *spark = spawn_object_relative(0, 100*sins(o->oMoveAngleYaw - 0x4000), 0, 100*coss(o->oMoveAngleYaw - 0x4000), o, MODEL_DRAG_SPARK, bhvDragSpark);

            spark->oPosX = o->oPosX + 100*sins(o->oMoveAngleYaw-0x4000);
            spark->oPosZ = o->oPosZ + 100*coss(o->oMoveAngleYaw-0x4000);


            if (o->oDistanceToMario < 200) {
                o->oSubAction = 2;
                o->oTimer = 0;
            }

            if (o->oTimer >= 240) {
                o->oSubAction = 3;
            }

        break;
        case 2:
            cur_obj_init_animation(PATCHMAKER_ANIM_NEEDLE_WALK_SLASH);

            if (o->oTimer == 7) {
                cur_obj_play_sound_1(SOUND_NEW_SLASH_AIR);
            }

            if (o->oTimer == 12 && o->oDistanceToMario < 300 && (o->oAngleToMario) < 0x4000 ) {
                gMarioState->action = ACT_BACKWARD_AIR_KB;
                gMarioState->actionArg = 1001;
                gMarioState->forwardVel = 30.0f;
                gMarioState->vel[1] = 15.0f;
                take_damage_from_no_interact_object(gMarioState, 4);

                
            }

            if (cur_obj_check_if_at_animation_end()) {
                patchmaker_transition_to_next_action();
            }
        break;
        case 3:
            cur_obj_init_animation(PATCHMAKER_ANIM_END_NEEDLE_WALK);
            if (cur_obj_check_if_at_animation_end()) {
                patchmaker_transition_to_next_action();
            }
        break;
    }
    

    
}

void patchmaker_act_summon_needle_ball(void) {
    cur_obj_init_animation(PATCHMAKER_ANIM_SNAP);

    if (o->oTimer == 20) {
        o->oPatchmakerNeedleBallObj = spawn_object_relative(0, 0, 400, 0, o, MODEL_NEEDLE_BALL, bhvNeedleBall);
        cur_obj_play_sound_1(SOUND_NEW_FINGER_SNAP);
    }

    if (cur_obj_check_if_at_animation_end()) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_shockwave(void) {
    cur_obj_init_animation(PATCHMAKER_ANIM_SCREAM_AT_SKY);

    if (o->oTimer == 10) {
        spawn_object_relative(0, 0, 0, 0,  o, MODEL_PM_SHOCKWAVE, bhvPmShockwave);
    }

    if (o->oTimer == 13) {
        gMarioState->action = ACT_BACKWARD_AIR_KB;
        gMarioState->vel[1] = 25;
        gMarioState->forwardVel = (PATCHMAKER_SECOND_FIGHT ? -70.0f : -48.0f);
        gMarioState->faceAngle[1] = o->oAngleToMario + 0x8000;
    }

    if (cur_obj_check_if_at_animation_end()) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_throw_needles(void) {
    cur_obj_init_animation(PATCHMAKER_ANIM_POINT);
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

    if (o->oTimer % (PATCHMAKER_SECOND_FIGHT ? 4 : 8) == 0 && o->oTimer < 40) {
        spawn_object_relative(0, random_u16()%300 - 150, 100, -300,  o, MODEL_PM_THROWN_NEEDLE, bhvPmThrownNeedle);
    }

    if (cur_obj_check_if_at_animation_end()) {
        patchmaker_transition_to_next_action();
    }
    //o->oHealth = 1;
}

void patchmaker_act_stone_flower(void) {

    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_POINT);
        spawn_object_relative(0, 0, 160, 0, o, MODEL_PM_THROWN_FLOWER, bhvPmThrownFlower);
    }

    if (o->oTimer == 50) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SNAP);
    }

    if (o->oTimer == 70) {
        cur_obj_play_sound_1(SOUND_NEW_FINGER_SNAP);
    }

    if (o->oTimer < 70) {
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    }

    if (o->oTimer == 80) {
        patchmaker_transition_to_next_action();
    }
    //o->oHealth = 1;
}

void patchmaker_act_ice_spikes(void) {
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer == 12) {
                cur_obj_init_animation(PATCHMAKER_ANIM_JUMP);
            }
        
            if (o->oTimer == 26) {
                cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
                o->oVelY = 75.0f;
                o->oForwardVel = 0.0f;
                o->oSubAction++;
            }
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
        break;
        case 1:;
            s16 collisionFlags = object_step();
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

            if (((collisionFlags & OBJ_COL_FLAG_GROUNDED) && o->oTimer > 30 ) || o->oTimer >= 125) {
                o->oTimer = 0;
                o->oForwardVel = 0;
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_JUMP_END, 1.0f);
                for (int i = 0; i < 3; i++) {
                    struct Object *iceSpawner = spawn_object_relative(0, 0, 0, 0, o, MODEL_NONE, bhvPmIceSpikeSpawner);
                    iceSpawner->oMoveAngleYaw += -0x2000 + i*0x2000;
                }
                o->oSubAction = 2;
                o->oTimer = 0;
            }
        break;
        case 2:
            if (o->oTimer >= 90) {
                patchmaker_transition_to_next_action();
            }
        break;
    }
}

void patchmaker_act_grapple(void) {
    
    cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_POINT, 0.7f);

    
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

    if (o->oTimer > 30) {
        o->oPosY += 2 * coss(o->oTimer * 0x8000);
    }

    if (o->oTimer == 40) {
        spawn_object_relative(0, 0, 60, 0, o, MODEL_PM_GRAPPLE, bhvPmGrapple);
        cur_obj_play_sound_2(SOUND_GRAPPLE_HOOK_1);
    }

    if (o->oTimer == 59) {
        o->oAction = PATCHMAKER_ACT_GRAB_MARIO;
    }
}

void patchmaker_act_halo(void) {

    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_STRING_THROW);
    }

    if (o->oTimer == 40) {
        spawn_object_relative(0, 0, 80, 0, o, MODEL_PM_HALO, bhvPmHalo);
    }
    else {
        o->oAngleVelYaw -= 60*o->oTimer;
        if (o->oTimer % 12 == 0) {
            cur_obj_play_sound_1(SOUND_HALO_IN);
        }
    }

    o->oFaceAngleYaw += o->oAngleVelYaw;

    if (o->oTimer >= 70) {
        patchmaker_transition_to_next_action();

    }
}

void patchmaker_act_shadowchomp(void) {
    
    cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_POINT, 0.7f);

    
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

    if (o->oTimer > 30) {
        o->oPosY += 2 * coss(o->oTimer * 0x8000);
    }

    if (o->oTimer == 40) {
        spawn_object_relative(0, 0, 60, 0, o, MODEL_PM_SHADOWCHOMP_OPEN, bhvPmGrapple);
        cur_obj_play_sound_2(SOUND_SHADOWCHOMP_APPROACH);
    }

    if (o->oTimer == 63) {
        o->oAction = PATCHMAKER_ACT_GRAB_MARIO;
    }
}

void patchmaker_act_marine_bubbles(void) {
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer == 12) {
                cur_obj_init_animation(PATCHMAKER_ANIM_JUMP);
            }
        
            if (o->oTimer == 26) {
                cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
                o->oVelY = 35.0f;
                o->oForwardVel = 0.0f;
                o->oSubAction++;
            }
        break;
        case 1:;
            s16 collisionFlags = object_step();
            o->oMoveAngleYaw += 0x1020;

            if (o->oTimer % 6 == 0) {
                cur_obj_play_sound_2(SOUND_ACTION_SIDE_FLIP_UNK);
            }

            if (((collisionFlags & OBJ_COL_FLAG_GROUNDED) && o->oTimer > 30 ) || o->oTimer >= 125) {
                o->oTimer = 0;
                o->oForwardVel = 0;
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                cur_obj_play_sound_2(SOUND_NEW_BUBBLE_RUSH);
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_JUMP_END, 1.0f);
                for (int i = 0; i < 6; i++) {
                    struct Object *pmBubble = spawn_object_relative(0, 0, 80, 0, o, MODEL_PM_BUBBLE, bhvPmBubble);
                    pmBubble->oMoveAngleYaw += -0x4000 + i*0x2000;
                }
                o->oSubAction = 2;
                o->oTimer = 0;
            }
        break;
        case 2:
            if (o->oTimer >= 60) {
                patchmaker_transition_to_next_action();
            }
        break;
    }
}

void patchmaker_act_breeze_spin(void) {
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_JUMP);
        o->oGravity = 0.4f;
    }

    if (o->oTimer == 20) {
        cur_obj_init_animation(PATCHMAKER_ANIM_STRING_THROW);
        o->oVelY = 13.0f;
        o->oForwardVel = 44.0f;
        o->oInteractType = INTERACT_DAMAGE;


        for (u8 i = 0; i < 6; i++) {
            spawn_object_relative(0, 0, random_u16()%20, 0, o, MODEL_FLOATING_PETAL, bhvFloatingPetal);
        }
        for (u8 j = 0; j < 6; j++) {
            spawn_object_relative(1, 0, random_u16()%20, 0, o, MODEL_FLOATING_PETAL, bhvFloatingPetal);
        }

        cur_obj_play_sound_1(SOUND_AIR_HOWLING_WIND);
    }

    if (o->oTimer >= 20) {
        s16 collisionFlags = object_step();
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

            if (o->oTimer % 3 == 0) {
                cur_obj_play_sound_2(SOUND_ACTION_SIDE_FLIP_UNK);
            }

            if (((collisionFlags & OBJ_COL_FLAG_GROUNDED) && o->oTimer > 30 ) || o->oTimer >= 125) {
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_JUMP_END, 1.0f);
                patchmaker_transition_to_next_action();
                o->oInteractType = INTERACT_PUSH_OUT;
                o->oGravity = 3.0f;
            }

            o->oFaceAngleYaw += 0x1420;
    }
}

void patchmaker_act_transmutation_needle(void) {
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_POINT);
    }
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

    if (o->oTimer == 20) {
        spawn_object_relative(1, random_u16()%300 - 150, 100, -300,  o, MODEL_PM_THROWN_NEEDLE, bhvPmThrownNeedle);
    }

    if (o->oTimer == 30) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SNAP);
    }

    if (o->oTimer == 60) {
        cur_obj_play_sound_1(SOUND_NEW_FINGER_SNAP);
    }

    if (o->oTimer == 80) {
        patchmaker_transition_to_next_action();
    }
    
}

void patchmaker_act_portal_to_mario(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SNAP);
        spawn_object_relative(0, 0, 120, 0, o, MODEL_PORTAL, bhvPmPortal);
        cur_obj_play_sound_2(SOUND_GENERAL_PAINTING_EJECT);
    }
    if (o->oTimer == 30) {
        cur_obj_play_sound_1(SOUND_NEW_FINGER_SNAP);
        cur_obj_play_sound_2(SOUND_PORTAL_OUT);
        spawn_object_relative(0, 0, 120, 0, gMarioState->marioObj, MODEL_PORTAL, bhvPmPortal);
        o->oPosX = gMarioState->pos[0];
        o->oPosY = gMarioState->floorHeight;
        o->oPosZ = gMarioState->pos[2];
        o->oAction = PATCHMAKER_ACT_GRAB_MARIO;
    }
}

void patchmaker_act_extension_wall(void) {
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SUMMON_WALL);
    }
    if (o->oTimer == 30) {
    s16 randomAngle = random_u16();
    
    struct Object *spikeWall =
        spawn_object_relative(0, -200, -1200, 1000 * coss(randomAngle), gMarioState->marioObj,
                              MODEL_MAD_SPIKE_WALL, bhvMadSpikeWall);
    spikeWall->oPosY = o->oPosY - 1050;
    }

    if (cur_obj_check_if_at_animation_end()) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_first_fight_defeated(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = 0;
            o->oPosZ = 0;
            o->oPosY = 1024;
            o->oFaceAngleYaw = -0x4000;
            o->oMoveAngleYaw = -0x4000;
            cur_obj_init_animation(PATCHMAKER_ANIM_DEFEATED_RUN_AWAY);
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_FIRST_FIGHT_DEFEATED);
            o->oSubAction++;

        break;
    }
    
}

void patchmaker_act_second_fight_defeated(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = 0;
            o->oPosZ = 0;
            o->oPosY = 1000;
            o->oFaceAngleYaw = 0;
            o->oMoveAngleYaw = 0;
            cur_obj_init_animation(PATCHMAKER_ANIM_FALL_TO_GROUND);
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_BREAKING_POINT);
            o->oSubAction++;

        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                cur_obj_init_animation(PATCHMAKER_ANIM_REACH_TO_MARIO);
                o->oSubAction++;
            }
        break;
        case 2:
            if (cExternalCutsceneTrigger >= 3) {
                cur_obj_init_animation(PATCHMAKER_ANIM_THROW_MARIO_DOWN);
                o->oSubAction++;
            }
        break;
        case 3:
            if (cExternalCutsceneTrigger >= 5) {
                cur_obj_init_animation(PATCHMAKER_ANIM_CURL_UP_SHOCKWAVE);
                o->oTimer = 0;
                o->oSubAction++;
            }
        break;
        case 4:
            if (o->oTimer == 10) {
                spawn_object_relative(0, 0, 0, 0,  o, MODEL_PM_SHOCKWAVE, bhvPmShockwave);
                gMarioState->action = ACT_BACKWARD_AIR_KB;
                gMarioState->vel[1] = 25;
                gMarioState->forwardVel = (PATCHMAKER_SECOND_FIGHT ? -70.0f : -48.0f);
                gMarioState->faceAngle[1] = o->oAngleToMario + 0x8000;
            }
            if (o->oTimer == 20) {
                gMarioState->action = ACT_WAITING_FOR_DIALOG;
            }

            if (cExternalCutsceneTrigger >= 6) {
                cur_obj_init_animation(PATCHMAKER_ANIM_TURN_TO_CAMERA);
                o->oTimer = 0;
                o->oSubAction++;
            }
        break;
        case 5:
            if (cExternalCutsceneTrigger >= 8) {
                cur_obj_init_animation(PATCHMAKER_ANIM_STOMP_TO_SEWNIA);
                o->oSubAction++;
            }
        break;
        case 6:
            if (cExternalCutsceneTrigger >= 9) {
                cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_SEWNIA);
                o->oSubAction++;
            }
        break;
        case 7:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_SEWNIA_IDLE);
                o->oSubAction++;
            }
        break;
        case 8:
            if (cExternalCutsceneTrigger >= 15) {
                cur_obj_init_animation(PATCHMAKER_ANIM_FROZEN_ARMS_OUT);
                o->oSubAction++;

            }
        break;
        case 9:;
            extern const u8 patchmaker_face_dma[];
            extern u8 the_patchmaker_patchmakerface_rgba16[];

            u8 *faceTexture = segmented_to_virtual(&the_patchmaker_patchmakerface_rgba16);

            dma_read(faceTexture, patchmaker_face_dma, patchmaker_face_dma + 4096);

            
            if (cExternalCutsceneTrigger >= 16) {
                cur_obj_init_animation(PATCHMAKER_ANIM_WALK_AWAY_FROM_FIGHT);
                o->oSubAction++;

            }
        break;
        case 10:
        if (cExternalCutsceneTrigger >= 17) {
                obj_mark_for_deletion(o);
            }

        break;
    }
    
}

void patchmaker_act_third_fight_defeated(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = 0;
            o->oPosZ = 0;
            o->oPosY = 458;
            o->oFaceAngleYaw = 0;
            o->oMoveAngleYaw = 0;
            cur_obj_init_animation(PATCHMAKER_ANIM_THIRD_DEFEAT);
            begin_cutscene_event(CUTSCENE_EVENT_PATCHMAKER_THIRD_FIGHT_DEFEAT);
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                cur_obj_init_animation(PATCHMAKER_ANIM_TRANSFORM_TO_MANTLE);
                o->oSubAction++;

            }
        break;
    }
}

void bhv_patchmaker_init(void) {
    o->oGravity = 3.0f;
    o->oDragStrength = 5.0f;
    o->oFriction = 1.0f;
    o->oBounciness = 0.0f;
    obj_set_hitbox(o, &sPatchmakerHitbox);
    o->oHealth = (PATCHMAKER_SECOND_FIGHT ? PATCHMAKER_2_MAX_HEALTH : PATCHMAKER_1_MAX_HEALTH);
    if (PATCHMAKER_THIRD_FIGHT) {
        o->oHealth = PATCHMAKER_3_MAX_HEALTH;
    }
    o->oInteractionSubtype = INT_SUBTYPE_PATCHMAKER;
    o->oPatchmakerAttackedVel = 0;
    o->oPatchmakerAttackedAngle = 0;

    if (gInMemoryStage) {
        patchmaker_fight_start();
        return;
    }

    switch (gCurrLevelNum) {
        case LEVEL_BOWSER_1:
        if (firstCutsceneDone) {
            patchmaker_fight_start();
        }
        else {
            o->oAction = PATCHMAKER_ACT_FIRST_CUTSCENE;
        }
        break;
        case LEVEL_BOWSER_2:
        if (secondCutsceneDone) {
            
            o->oPosX = 300;
            o->oPosY = 1000;
            o->oPosZ = -40;
            o->oFaceAngleYaw = -0x4000;
            o->oMoveAngleYaw = -0x4000;
            patchmaker_fight_start();
        }
        else {
            o->oAction = PATCHMAKER_ACT_SECOND_CUTSCENE;
        }
        break;
        case LEVEL_BOWSER_3:
        if (thirdCutsceneDone) {
            spawn_patchmaker_miasma();
            patchmaker_fight_start();
        }
        else {
            o->oAction = PATCHMAKER_ACT_THIRD_CUTSCENE;
        }
        break;
    }
}

void bhv_patchmaker_loop(void) {
    switch (o->oAction) {
        case PATCHMAKER_ACT_FIRST_CUTSCENE:
            patchmaker_act_first_fight_cutscene();
        break;
        case PATCHMAKER_ACT_SECOND_CUTSCENE:
            patchmaker_act_second_fight_cutscene();
        break;
        case PATCHMAKER_ACT_THIRD_CUTSCENE:
            patchmaker_act_third_fight_cutscene();
        break;
        case PATCHMAKER_ACT_WALK_TO_MARIO:
            patchmaker_act_walk_to_mario();
        break;
        case PATCHMAKER_ACT_JUMPS:
            patchmaker_act_jumps();
        break;
        case PATCHMAKER_ACT_SLASH_DASH:
            patchmaker_act_slash_dash();
        break;
        case PATCHMAKER_ACT_GRAB_MARIO:
            patchmaker_act_grab_mario();
        break;
        case PATCHMAKER_ACT_THROW_STRING:
            patchmaker_act_throw_string();
        break;
        case PATCHMAKER_ACT_SLOW_NEEDLE_WALK:
            patchmaker_act_slow_needle_walk();
        break;
        case PATCHMAKER_ACT_SUMMON_NEEDLE_BALL:
            patchmaker_act_summon_needle_ball();
        break;
        case PATCHMAKER_ACT_SHOCKWAVE:
            patchmaker_act_shockwave();
        break;
        case PATCHMAKER_ACT_NEEDLE_STORM:
            patchmaker_act_throw_needles();
        break;
        case PATCHMAKER_ACT_STONE_FLOWER:
            patchmaker_act_stone_flower();
        break;
        case PATCHMAKER_ACT_ICE_SPIKES:
            patchmaker_act_ice_spikes();
        break;
        case PATCHMAKER_ACT_GRAPPLE:
            patchmaker_act_grapple();
        break;
        case PATCHMAKER_ACT_HALO:
            patchmaker_act_halo();
        break;
        case PATCHMAKER_ACT_MARINE_BUBBLES:
            patchmaker_act_marine_bubbles();
        break;
        case PATCHMAKER_ACT_SHADOWCHOMP:
            patchmaker_act_shadowchomp();
        break;
        case PATCHMAKER_ACT_TRANSMUTATION_NEEDLE:
            patchmaker_act_transmutation_needle();
        break;
        case PATCHMAKER_ACT_BREEZE_SPIN:
            patchmaker_act_breeze_spin();
        break;
        case PATCHMAKER_ACT_PORTAL_TO_MARIO:
            patchmaker_act_portal_to_mario();
        break;
        case PATCHMAKER_ACT_EXTENSION:
            patchmaker_act_extension_wall();
        break;
        case PATCHMAKER_ACT_DEFEATED:
            if (PATCHMAKER_THIRD_FIGHT) {
                patchmaker_act_third_fight_defeated();
            }
            else if (PATCHMAKER_SECOND_FIGHT) {
                patchmaker_act_second_fight_defeated();
            }
            else {
                patchmaker_act_first_fight_defeated();
            }

            if (gInMemoryStage) {
                if (o->oTimer == 30) {
                    if (gCurrLevelNum == LEVEL_BOWSER_3) {
                        initiate_warp(LEVEL_BOWSER_3, 1, 10, 0, 0);
                    }
                    else {
                        initiate_warp(LEVEL_CASTLE, PATCHMAKER_SECOND_FIGHT ? 2 : 1, 10, 0, 0);
                    }
                }
            }
            
        break;
    }

    if (gCurrLevelNum == LEVEL_BOWSER_3 && gCurCutscene == -1 && o->oTimer % 4 == 0) {
        struct Object *shadowSmoke = spawn_object_relative(0, random_u16()%200 - 100, random_u16()%10 + 10, random_u16()%200 - 100, 
                            o, MODEL_FIRE_SMOKE, bhvShadowchompParticle);
                            
                            SET_BPARAM1(shadowSmoke->oBehParams, 2);
                            shadowSmoke->oVelY = ((random_u16() % 8));
                            shadowSmoke->oMoveAngleYaw = random_u16();
                            shadowSmoke->oForwardVel = (random_u16() % 8) + 5.0f;
    }

    if (o->oAction != PATCHMAKER_ACT_JUMPS && o->oAction != PATCHMAKER_ACT_THROW_STRING && o->oAction != PATCHMAKER_ACT_BREEZE_SPIN) {
        o->oFaceAngleYaw = o->oMoveAngleYaw;
    }

    gBossHealth = CLAMP(o->oHealth, 0, 255);

    if (o->oHealth <= 0 && o->oAction != PATCHMAKER_ACT_DEFEATED) {
        o->oAction = PATCHMAKER_ACT_DEFEATED;
        o->oSubAction = 0;
        if (gInMemoryStage) {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255);
        }
        
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            o->oPatchmakerAttackedVel = 30.0f;
            o->oPatchmakerAttackedAngle = o->oAngleToMario;
        }
    }

    if (o->oAction != PATCHMAKER_ACT_FIRST_CUTSCENE 
        && o->oAction != PATCHMAKER_ACT_SECOND_CUTSCENE 
        && o->oAction != PATCHMAKER_ACT_THIRD_CUTSCENE
        && o->oAction != PATCHMAKER_ACT_DEFEATED 
        && o->oPatchmakerAttackedVel > 0) {
            if (find_floor_height(o->oPosX - o->oPatchmakerAttackedVel * sins(o->oPatchmakerAttackedAngle), 
            o->oPosY, 
            o->oPosZ - o->oPatchmakerAttackedVel * coss(o->oPatchmakerAttackedAngle)) > -10000) {
                    o->oPosX -= o->oPatchmakerAttackedVel * sins(o->oPatchmakerAttackedAngle);
                    o->oPosZ -= o->oPatchmakerAttackedVel * coss(o->oPatchmakerAttackedAngle);
            }
            
            o->oPatchmakerAttackedVel -= 2;
        }

    o->oInteractStatus = 0;
}

s16 patchmaker_in_needle_action(struct Object *obj) {
    return ((obj->oAction == PATCHMAKER_ACT_SLASH_DASH && (obj->oTimer > 16))
            || (obj->oAction == PATCHMAKER_ACT_BREEZE_SPIN && obj->oTimer > 20)
            || (obj->oAction == PATCHMAKER_ACT_SLOW_NEEDLE_WALK && ((obj->oSubAction == 2 || obj->oTimer > 23))));
}

Gfx *geo_switch_patchmaker_needle(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

            if (patchmaker_in_needle_action(obj)) {
                switchCase->selectedCase = 1;
            }
            else {
                switchCase->selectedCase = 0;
            }
    }
    return NULL;
}
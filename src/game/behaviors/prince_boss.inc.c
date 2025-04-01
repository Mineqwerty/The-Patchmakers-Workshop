#include "src/game/cutscene.h"
#include "src/game/game_init.h"
#include "include/dialog_ids.h"

enum PrinceActions {
    PRINCE_ACT_CUTSCENE,
    PRINCE_ACT_IDLE,
    PRINCE_ACT_TELEPORT,
    PRINCE_ACT_URCHIN_CIRCLE,
    PRINCE_ACT_DASH_FORWARD,
    PRINCE_ACT_BARRAGE,
    PRINCE_ACT_SHOCK_WAVES,
    PRINCE_ACT_LASER,
    PRINCE_ACT_MELT_ATTACK,
    PRINCE_ACT_DEFEATED
};

enum PrinceAnimations {
    PRINCE_ANIM_IDLE,
    PRINCE_ANIM_WAVE,
    PRINCE_ANIM_DASH,
    PRINCE_ANIM_SUMMON,
    PRINCE_ANIM_START_SHOCK_WAVE,
    PRINCE_ANIM_FIRE_SHOCK_WAVE,
    PRINCE_ANIM_END_SHOCK_WAVE,
    PRINCE_ANIM_START_SIDE_FLY,
    PRINCE_ANIM_SIDE_FLY
};

void prince_act_cutscene(void) {
    

    switch (o->oSubAction) {
        case 0:
            if (o->oDistanceToMario < 1000) {
                begin_cutscene_event(CUTSCENE_EVENT_PRINCE_INTRO);
                
                o->oSubAction++;
            }
            
        break;
        case 1:
            if (gCurCutscene == -1) {
                o->oAction = PRINCE_ACT_IDLE;
                o->oHealth = 100;
                gBossMaxHealth = 100;
                gBossHealth = 100;
            }
        break;
    }
}

s16 decide_prince_action() {
    struct Surface *floor;
    f32 height = find_floor(o->oPosX, o->oPosY + 10, o->oPosZ, &floor);

    if (height < 0) {
        return PRINCE_ACT_TELEPORT;
    }

    if (o->oDistanceToMario < 1000) {
        switch (random_u16()%4) {
            case 0:
                return PRINCE_ACT_DASH_FORWARD;
            break;
            case 1:
                return PRINCE_ACT_LASER;
            break;
            case 2:
                return PRINCE_ACT_URCHIN_CIRCLE;
            break;
            case 3:
                return PRINCE_ACT_TELEPORT;
            break;
        }
    }
    else {
        switch (random_u16()%4) {
            case 0:
                return PRINCE_ACT_SHOCK_WAVES;
            break;
            case 1:
                return PRINCE_ACT_BARRAGE;
            break;
            case 2:
                return PRINCE_ACT_DASH_FORWARD;
            break;
            case 3:
                return PRINCE_ACT_TELEPORT;
            break;
        }
    }
    
}

void prince_act_idle(void) {
    cur_obj_init_animation(PRINCE_ANIM_IDLE);
    gSecondCameraFocus = o;
    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    gCamera->controlBossCameraYaw = 1;
    o->oPosY = gMarioState->floorHeight;
    o->oSubAction = 0;
    if (o->oTimer == 30) {
        o->oAction = decide_prince_action();
    }
}

f32 princeTeleportSpots[4][2] = {{4050, 0}, {0, 4050}, {-4050, 0}, {0, -4050}};

void prince_warp_to_teleport_spot(void) {
    o->oPosX = princeTeleportSpots[o->oLastTeleportIndex][0];
    o->oPosZ = princeTeleportSpots[o->oLastTeleportIndex][1];
}

void prince_act_teleport(void) {
    switch(o->oSubAction) {
        case 0:
            obj_scale_xyz(o, CLAMP(1.0f - (f32)o->oTimer/15.0f, 0.02f, 1.0f), 1.0f + (f32)o->oTimer/15.0f, CLAMP(1.0f - (f32)o->oTimer/15.0f, 0.02f, 1.0f));
            if (o->oTimer == 14) {
                cur_obj_hide();
                for (int i = 0; i < 3; i++) {
                    spawn_object_relative(0, random_u16()%500 - 250, random_u16()%250, random_u16()%500 - 250, o, MODEL_JELLYFISH, bhvJellyfish);
                }
                
            }

            if (o->oTimer == 30) {
                o->oTimer = 0;
                o->oLastTeleportIndex = (o->oLastTeleportIndex + 1 + random_u16()%3)%4;
                prince_warp_to_teleport_spot();
                o->oSubAction++;
            }
        break;
        case 1:
            if (o->oTimer > 0) {
                obj_scale_xyz(o, (f32)o->oTimer/15.0f, 2.0f - (f32)o->oTimer/15.0f, (f32)o->oTimer/15.0f);
                cur_obj_unhide();
            }
            if (o->oTimer == 15) {
                o->oAction = PRINCE_ACT_IDLE;
                cur_obj_scale(1.0f);
            }
        break;
    }
}

void prince_act_urchin_circle(void) {

    obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);

    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(PRINCE_ANIM_WAVE);

            if (o->oTimer == 20) {
                for (int i = 0; i < 8; i++) {
                    struct Object *urchin = spawn_object_relative(0, 900*sins(i * 0x1FFF), 0, 900*coss(i * 0x1FFF), gMarioState->marioObj, MODEL_ABYSS_URCHIN, bhvAbyssUrchin);
                    urchin->oPosY = gMarioState->floorHeight;
                    o->oTimer = 0;
                }
                o->oSubAction++;
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
            }
            
        break;
        case 1:
            if (o->oTimer == 10) {
                struct Object *jelly = spawn_object_relative(0, 0, 0, 0, gMarioState->marioObj, MODEL_JELLY_SURROUND_CIRCLE, bhvJellySurroundCircle);
                jelly->oPosY = gMarioState->floorHeight;
                o->oSubAction++;
                o->oTimer = 0;
            }

            
        break;
        case 2:
            o->oPosY += o->oTimer + 10.0f;

            if (o->oTimer == 90) {
                o->oSubAction++;
                cur_obj_hide();
                o->oLastTeleportIndex = (o->oLastTeleportIndex + 1 + random_u16()%3)%4;
                prince_warp_to_teleport_spot();
                o->oPosY = gMarioState->floorHeight + 2000;
            }
        break;
        case 3:;
            f32 dist;
            struct Object *jellyWall = cur_obj_find_nearest_object_with_behavior(bhvJellySurroundCircle, &dist);

            if (!jellyWall) {
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 4:
            cur_obj_unhide();
            o->oPosY -= 100.0f - o->oTimer;
            if (o->oTimer == 75) {
                o->oAction = PRINCE_ACT_IDLE;
            }
        break;
    }
}

void prince_act_dash_forward(void) {

    gSecondCameraFocus = o;
    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    gCamera->controlBossCameraYaw = 1;
    

    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(PRINCE_ANIM_DASH);

            obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);
            o->oMoveAngleYaw = o->oFaceAngleYaw;

            if (o->oTimer == 20)  {
                o->oSubAction++;
            }
            
        break;
        case 1:
            o->oForwardVel = 80 + o->oTimer*2;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oForwardVel > 160) {
                spawn_object_relative(0, 0, 0, 28.0f * o->oForwardVel, o, MODEL_PRINCE_TELEPORT_RIFT, bhvPrinceTeleportRift);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 2:
            cur_obj_move_xz_using_fvel_and_yaw();
            if (o->oTimer > 20) {
                cur_obj_scale(1.0f - (f32)(o->oTimer - 20)/20.0f);
            }
            if (o->oTimer == 30) {
                cur_obj_hide();
                o->oTimer = 0;
                o->oSubAction++;
            }
        break;
        case 3:
        if (o->oTimer == 1) {
            o->oHomeX = o->oPosX * -1;
            o->oHomeZ = o->oPosZ * -1;
            o->oForwardVel = sqrtf(sqr(o->oHomeX - o->oPosX) + sqr(o->oHomeZ - o->oPosZ));
            spawn_object_abs_with_rot(o, 0, MODEL_PRINCE_TELEPORT_RIFT, bhvPrinceTeleportRift, o->oHomeX, o->oPosY, o->oHomeZ, 0, 0, 0);
        }
        if (o->oTimer > 0) {
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, o->oForwardVel / 10);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ, o->oForwardVel / 10);
        }
        if (o->oTimer > 10) {
            o->oPosX = o->oHomeX;
            o->oPosZ = o->oHomeZ;
            cur_obj_unhide();
            o->oAction = PRINCE_ACT_IDLE;
            cur_obj_scale(1.0f);
            o->oForwardVel = 0;
        }

        break;
    }
}

void prince_act_barrage(void) {
    gSecondCameraFocus = o;
    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    gCamera->controlBossCameraYaw = 1;

    switch(o->oSubAction) {
        case 0:
            cur_obj_init_animation(PRINCE_ANIM_SUMMON);
            if (o->oTimer > 10) {
                if (o->oTimer % 4 == 0) {
                    spawn_object_relative(0, random_u16()%1000 - 500, random_u16()%1000, random_u16()%1000 - 500, o, MODEL_PRINCE_BULLET, bhvPrinceBullet);
                }
            }

            if (o->oTimer == 50) {
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 1:

            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PRINCE_ANIM_IDLE);
            }

            if (o->oTimer == 60) {
                o->oAction = PRINCE_ACT_IDLE;
            }
        break;
    }
}

void prince_act_shock_waves(void) {
    obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);
    o->oMoveAngleYaw = o->oFaceAngleYaw;
    gSecondCameraFocus = o;
    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    gCamera->controlBossCameraYaw = 1;

    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(PRINCE_ANIM_START_SHOCK_WAVE);
            if (o->oTimer > 45) {
                o->oAttackCounter = 5;
                o->oSubAction++;
            }
            if (o->oTimer % 2 == 0) {
                struct Object *spark = spawn_object_relative(0, random_u16()%500-250, random_u16()%500, random_u16()%500-250, o, MODEL_BREAKER_SPARK, bhvBreakerSpark);
                    spark->oForwardVel = random_u16()%10;
                    spark->oMoveAngleYaw = random_u16();
                    spark->oVelY = random_u16()%15;
                    switch (random_u16()%3) {
                        case 0:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_1, o);
                        break;
                        case 1:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_2, o);
                        break;
                        case 2:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_3, o);
                        break;
                    }
            }
        break;
        case 1:
            cur_obj_init_animation(PRINCE_ANIM_FIRE_SHOCK_WAVE);
            o->oAttackCounter -= 1;
            struct Object *wave = spawn_object_relative(0, 0, 0, 0, o, MODEL_PRINCE_SHOCK_WAVE, bhvPrinceShockWave);
            wave->oPosY = gMarioState->pos[1] + 80;
            o->oTimer = 0;
            o->oSubAction++;
        break;
        case 2:
            if (o->oTimer == 30) {
                if (o->oAttackCounter <= 0) {
                    o->oSubAction = 3;
                    cur_obj_init_animation(PRINCE_ANIM_END_SHOCK_WAVE);
                }
                else {
                    o->oSubAction = 1;
                    cur_obj_init_animation(PRINCE_ANIM_END_SHOCK_WAVE);
                }
            }
        break;
        case 3:
            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = PRINCE_ACT_IDLE;
            }
        break;
    }
}

void prince_find_laser_shoot_position(void) {
    u16 randomAngle = random_u16();
    o->oPosX = gMarioState->pos[0] + 3000*sins(randomAngle);
    o->oPosZ = gMarioState->pos[2] + 3000*coss(randomAngle);
    o->oFaceAngleYaw = obj_angle_to_object(o, gMarioObject);
    o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
    o->oPosX -= 6000 * sins(o->oMoveAngleYaw);
    o->oPosZ -= 6000 * coss(o->oMoveAngleYaw);

}

void prince_act_laser(void) {
    switch (o->oSubAction) {
        case 0:
            o->oSpawnedCameraFocus = spawn_object_relative(0, 0, 0, 0, o, MODEL_NONE, bhvFocusObject);
            gSecondCameraFocus = o->oSpawnedCameraFocus;
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
            obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x2000);
            o->oSubAction++;
        break;
        case 1:
            cur_obj_init_animation(PRINCE_ANIM_START_SIDE_FLY);
            o->oSubAction++;
        break;
        case 2:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(PRINCE_ANIM_SIDE_FLY);
            }
            o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
            o->oForwardVel = o->oTimer * 5;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer > 70) {
                o->oSubAction++;
                o->oAttackCounter = 3;
            }
        break;
        case 3:
            prince_find_laser_shoot_position();
            //gSecondCameraFocus = o;
            o->oPrinceLaserObject = spawn_object_relative(0, 0, 100, 0, o, MODEL_PRINCE_LASER, bhvPrinceLaser);
            o->oTimer = 0;
            o->oSubAction++;
        break;
        case 4:
            o->oForwardVel = 120.0f;
            
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oPrinceLaserObject->oPosX = o->oPosX;
            o->oPrinceLaserObject->oPosY = o->oPosY + 100;
            o->oPrinceLaserObject->oPosZ = o->oPosZ;

            if (o->oTimer <= 45) {
                o->oSpawnedCameraFocus->oPosX = approach_f32_symmetric(o->oSpawnedCameraFocus->oPosX, o->oPosX, 500);
                o->oSpawnedCameraFocus->oPosZ = approach_f32_symmetric(o->oSpawnedCameraFocus->oPosZ, o->oPosZ, 500);
            }

            if (o->oTimer == 120) {
                //obj_mark_for_deletion(o->oSpawnedCameraFocus);
                //gSecondCameraFocus = o;
                obj_mark_for_deletion(o->oPrinceLaserObject);
                o->oSubAction++;
            }
        break;
        case 5:
            o->oAttackCounter--;
            if (o->oAttackCounter <= 0) {
                    o->oSubAction = 6;
                    o->oTimer = 0;
                    cur_obj_init_animation(PRINCE_ANIM_IDLE);
                }
                else {
                    o->oSubAction = 3;
                }
        break;
        case 6:
        if (o->oTimer == 1) {
            o->oPosX = gMarioState->pos[0] - 2000 * sins(gMarioState->faceAngle[1]);
            o->oPosY = gMarioState->floorHeight;
            o->oPosZ = gMarioState->pos[2] - 2000 * coss(gMarioState->faceAngle[1]);
        }
            o->oSpawnedCameraFocus->oPosX = approach_f32_symmetric(o->oSpawnedCameraFocus->oPosX, o->oPosX, 500);
            o->oSpawnedCameraFocus->oPosZ = approach_f32_symmetric(o->oSpawnedCameraFocus->oPosZ, o->oPosZ, 500);

            if (o->oTimer == 120) {
                obj_mark_for_deletion(o->oSpawnedCameraFocus);
                gSecondCameraFocus = o;
                o->oAction = PRINCE_ACT_IDLE;
            }
        break;
    }
}

void prince_act_defeated(void) {
    switch (o->oSubAction) {
        case 0:
            create_dialog_box(DIALOG_PRINCE_DEFEATED);
            cur_obj_init_animation(PRINCE_ANIM_IDLE);
            
            gMarioState->health = 0x880;
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gMarioState->pos[1] = gMarioState->floorHeight;
            o->oSubAction++;
            gBossMaxHealth = 0;
            gBossHealth = 0;
            gBossDrainHealthDisplay = 0;
            gBossHealthDisplay = 0;
        break;
        case 1:
            if (gDialogID == -1) {
                gMarioState->action = ACT_IDLE;
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
                cur_obj_init_animation(PRINCE_ANIM_SUMMON);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 2:
            if (o->oTimer == 20) {
                for (int i = 0; i < 30; i++) {
                    struct Object *spark = spawn_object_relative(0, random_u16()%500-250, random_u16()%500, random_u16()%500-250, o, MODEL_BREAKER_SPARK, bhvBreakerSpark);
                        spark->oForwardVel = random_u16()%10;
                        spark->oMoveAngleYaw = random_u16();
                        spark->oVelY = random_u16()%15;
                }
                cur_obj_hide();
                
                
            }
            if (o->oTimer >= 21) {
                SET_BPARAM1(o->oBehParams, 5);
                spawn_default_star(o->oPosX + 300, o->oPosY + 300, o->oPosZ);
                obj_mark_for_deletion(o);
            }
        break;
    }
}

void bhv_prince_boss_init(void) {
    o->oLastTeleportIndex = 0;
}

void bhv_prince_boss_loop(void) {
    switch (o->oAction) {
        case PRINCE_ACT_CUTSCENE:
            prince_act_cutscene();
        break;
        case PRINCE_ACT_IDLE:
            prince_act_idle();
        break;
        case PRINCE_ACT_TELEPORT:
            prince_act_teleport();
        break;
        case PRINCE_ACT_URCHIN_CIRCLE:
            prince_act_urchin_circle();
        break;
        case PRINCE_ACT_DASH_FORWARD:
            prince_act_dash_forward();
        break;
        case PRINCE_ACT_BARRAGE:
            prince_act_barrage();
        break;
        case PRINCE_ACT_SHOCK_WAVES:
            prince_act_shock_waves();
        break;
        case PRINCE_ACT_LASER:
            prince_act_laser();
        break;
        case PRINCE_ACT_DEFEATED:
            prince_act_defeated();
        break;
    }
    if (o->oAction != PRINCE_ACT_CUTSCENE && o->oAction != PRINCE_ACT_DEFEATED) {
        gBossHealth = o->oHealth;
    }

    if (o->oHealth < 100 && gGlobalTimer % 150 == 0) {
        o->oHealth += 1;
    }

    if (o->oHealth <= 0 && o->oAction != PRINCE_ACT_DEFEATED) {
        o->oAction = PRINCE_ACT_DEFEATED;
        o->oSubAction = 0;
    }
}


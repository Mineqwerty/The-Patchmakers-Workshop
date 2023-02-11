#define GODDESS_ACT_CUTSCENE    0
#define GODDESS_ACT_IDLE_FLIGHT    1
#define GODDESS_ACT_GOLD_BARRAGE    2
#define GODDESS_ACT_SPEAR_DIVE  3
#define GODDESS_ACT_CLOSE_COMBAT    4
#define GODDESS_ACT_GROUND_SHOT    5
#define GODDESS_ACT_FLY_UP    6
#define GODDESS_ACT_BANISH    7
#define GODDESS_ACT_DEATH    8

#include "src/game/game_init.h"

static struct ObjectHitbox sGoddessHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 600,
    /* height:            */ 1500,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sGoldBlobHitbox = {
    /* interactType:      */ INTERACT_DAMAGE_ENEMY,
    /* downOffset:        */ 25,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 20,
    /* hurtboxHeight:     */ 20,
};

void bhv_goddess_init(void) {
    //create_dialog_box(60);
    o->oGravity = 0;

    obj_set_hitbox(o, &sGoddessHitbox);

    o->oHealth = 100;
    gBossMaxHealth = 100;
    gBossHealth = 100;
    
}

void bhv_goddess_loop(void) {

    print_text_fmt_int(100, 100, "%d", o->oHealth);

    
    switch (o->oAction) {
        case GODDESS_ACT_CUTSCENE: goddess_act_cutscene(); break;
        case GODDESS_ACT_IDLE_FLIGHT: goddess_act_idle_flight(); break;
        case GODDESS_ACT_GOLD_BARRAGE: goddess_act_gold_barrage(); break;
        case GODDESS_ACT_SPEAR_DIVE: goddess_act_spear_dive(); break;
        case GODDESS_ACT_CLOSE_COMBAT: goddess_act_close_combat(); break;
        case GODDESS_ACT_GROUND_SHOT: goddess_act_ground_shot(); break;
        case GODDESS_ACT_FLY_UP: goddess_act_fly_up(); break;
        case GODDESS_ACT_BANISH: goddess_act_banish(); break;
    }

    
    goddess_check_interactions();
    gBossHealth = o->oHealth;
    
}

void goddess_act_idle_flight(void) {
    cur_obj_init_animation(0);
    gCamera->controlBossCameraYaw = 1;
    if (o->oTimer == 90) {
        switch (random_u16() % 2) {
            case 0:
                o->oAction = GODDESS_ACT_GOLD_BARRAGE;
            break;
            case 1:
                o->oAction = GODDESS_ACT_BANISH;
            break;
        }
    }
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    o->oPosY += 20*coss(0x400 * o->oTimer);
    o->oPosX += 10*coss(0x200 * o->oTimer) * sins(o->oMoveAngleYaw + 0x4000);
    o->oPosZ += 10*coss(0x400 * o->oTimer) * coss(o->oMoveAngleYaw + 0x4000);

    o->oForwardVel = 10;
    cur_obj_move_xz_using_fvel_and_yaw();

}

void goddess_act_gold_barrage(void) {
    if (cur_obj_init_animation_and_check_if_near_end(6)) {
                o->oAction = GODDESS_ACT_SPEAR_DIVE;
            }

            if (o->oTimer % 8 == 0) {
                struct Object *bullet = spawn_object_relative(0, 0, 2000, 0, o, MODEL_GOLD_BLOB, bhvGoldBlob);
                bullet->oAction = 2;
                bullet->oHomeX = gMarioState->pos[0];
                bullet->oHomeY = gMarioState->pos[1];
                bullet->oHomeZ = gMarioState->pos[2];
            }
}

void goddess_act_spear_dive(void) {

    gCamera->controlBossCameraYaw = 1;

    switch (o->oSubAction) {
        case 0:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
            if (cur_obj_init_animation_and_check_if_near_end(7)) {
                o->oSubAction++;
            }
        break;
        case 1:
            cur_obj_init_animation(8);

            o->oForwardVel = 20.0f;
            o->oVelY = -90.0f;
            object_step();

            if (o->oTimer == 60) {
                o->oSubAction++;
            }
            
        break;
        case 2:
            if (cur_obj_init_animation_and_check_if_near_end(9)) {
                o->oAction = GODDESS_ACT_CLOSE_COMBAT;
                o->oForwardVel = 0.0f;
            }

            o->oForwardVel -= 1;
        break;
    }
}

void goddess_act_close_combat(void) {
    if (o->oTimer < 90) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    }
    else {
        gCamera->controlBossCameraYaw = 1;
    }
    
    if (cur_obj_init_animation_and_check_if_near_end(10)) {
                o->oAction = GODDESS_ACT_FLY_UP;
            }

    

    o->oVelY = 0;

    if (o->oTimer == 2) {
     o->oForwardVel = 60.0f;
    }

    if (o->oTimer == 25) {
     o->oForwardVel = 60.0f;
     
    }

    if (o->oTimer == 45) {
     o->oForwardVel = 60.0f;
     o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    }



            cur_obj_move_xz_using_fvel_and_yaw();
            if (o->oForwardVel > 0) {
                o->oForwardVel -= 2;
            }
    
}

void goddess_act_ground_shot(void) {

}

void goddess_act_fly_up(void) {
    cur_obj_init_animation(11);
    gCamera->controlBossCameraYaw = 1;

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x240);

    if (o->oTimer == 10) {
        o->oForwardVel = -60.0f;
            o->oVelY = 40.0f;
            
    }

    if (o->oTimer == 60) {
        o->oAction = GODDESS_ACT_IDLE_FLIGHT;
    }

    object_step();
}

void goddess_act_banish(void) {
    switch (o->oSubAction) {
        case 0:
            if (cur_obj_init_animation_and_check_if_near_end(3)) {
                o->oSubAction++;
            }
        break;
        case 1:
            cur_obj_init_animation(4);
            if (o->oTimer == 150) {
                o->oSubAction++;
            }
            
        break;
        case 2:
            if (cur_obj_init_animation_and_check_if_near_end(5)) {
                o->oAction = GODDESS_ACT_SPEAR_DIVE;
            }
        break;
    }
}

void goddess_act_cutscene(void) {

    

    switch (o->oSubAction) {
        case 0:
            gSecondCameraFocus = o;
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
            o->oSubAction = 3;
        break;
        case 1: 
            gCamera->cutscene = 1;
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gLakituState.goalPos[0] = -1495;
    gLakituState.goalPos[1] = 912;
    gLakituState.goalPos[2] = -1726;

    gLakituState.goalFocus[0] = -107;
    gLakituState.goalFocus[1] = 1792;
    gLakituState.goalFocus[2] = 706;
            cur_obj_init_animation(1);
            if (o->oTimer == 6) {
                o->oSubAction = 2;
            }
        break;

        case 2: 
            if (cur_obj_init_animation_and_check_if_near_end(2)) {
                o->oSubAction = 3;
            }

            o->oPosZ -= 20.0f;
            o->oPosY += 5.0f;
        break;

        case 3: 
            cur_obj_init_animation(0);

            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);

            if (o->oTimer == 30) {
                gCamera->cutscene = 0;
                gMarioState->action = ACT_IDLE;
                o->oAction = GODDESS_ACT_IDLE_FLIGHT;
                gCamera->cutscene = 0;
                gMarioState->action = ACT_IDLE;
                o->oAction = GODDESS_ACT_IDLE_FLIGHT;
                cur_obj_init_animation(0);
                o->oPosZ -= 200.0f;
                o->oPosY += 50.0f;
                gSecondCameraFocus = o;
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
            }

        break;
    }

    
}

void goddess_check_interactions(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            
            u8 healthSubtract = 1;
            for (int i = 0; i < (o->oInteractStatus & INT_STATUS_ATTACK_MASK); i++) {
                healthSubtract *= 2;
            }
            o->oHealth -= healthSubtract;

            for (int i = 0; i < 8; i++) {
                struct Object *fragment = spawn_object_relative(0, 0, 1000, 0, o, MODEL_GOLD_FRAGMENT, bhvGoldFragment);
            }
        }
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_gold_bullet_loop(void) {
    switch (o->oAction) {
        case 0: 
            if (o->oTimer == 40) {
                o->oAction = 1;
                o->oHomeX = gMarioState->pos[0];
                o->oHomeY = gMarioState->pos[1];
                o->oHomeZ = gMarioState->pos[2];
            }
        break;
    }
}

void bhv_gold_blob_loop(void) {
    obj_scale_xyz(o, 1.0f + (0.05f * sins((o->oTimer * 0x1000) + 0x4000)), 1.0f + (0.05f * coss(o->oTimer * 0x1000)), 1.0f + (0.05f * sins(o->oTimer * 0x1000)));
    
    if (!obj_has_model(o, MODEL_GOLD_SWORD)) {
    o->oFaceAnglePitch += 0x200;
    o->oFaceAngleRoll += 0x100;
    }

    if (o->oAction == 1)  {
        if (o->oTimer < 30) {
            cur_obj_become_intangible();
        }
        else {
            cur_obj_become_tangible();
        }
        if (gCurrAreaIndex == 4) {
            f32 dist;
            struct Object *goddess = cur_obj_find_nearest_object_with_behavior(bhvGoddessBoss, &dist);
            if (goddess) {
            o->oHomeX = goddess->oPosX;
            o->oHomeY = goddess->oPosY + 1000;
            o->oHomeZ = goddess->oPosZ;

            obj_turn_toward_object(o, goddess, O_MOVE_ANGLE_YAW_INDEX, 0x400);
                    obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ, O_FACE_ANGLE_PITCH_INDEX, 0x400);
                    o->oFaceAngleRoll = 0;
            }
             

            gold_blob_approach_home();

            if (goddess && o->oTimer == 30) {
                    attack_object(goddess, 32);

                    obj_mark_for_deletion(o);
                }
            }
        
        else {
            if (o->oTimer == 0) {
                o->oForwardVel = 50.0f;
                o->oVelY = 20.0f;
                o->oGravity = 2.0f;
                o->oMoveAngleYaw = gMarioState->faceAngle[1];
            }
            object_step();
        }
    }
    else if (o->oAction == 2) {

        gold_blob_approach_home();

        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x1000);


        if (o->oTimer == 40) {
            switch (random_u16() % 3) {
                case 0: o->oAction = 3;
                break;
                default:
                    obj_mark_for_deletion(o);
                break;  
        }
        }
    }
    else if (o->oAction == 3) {
        if (o->oTimer == 0) {
                o->oForwardVel = 10.0f;
                o->oGravity = 5.0f;
            }

            if (o->oTimer < 10) {
            object_step();
            }
            

            if (o->oGoldBlobCount >= 2) {
                obj_set_model(o, MODEL_GOLD_SWORD);

                f32 dist;
                struct Object *goddess = cur_obj_find_nearest_object_with_behavior(bhvGoddessBoss, &dist);

                if (goddess) {
                    obj_turn_toward_object(o, goddess, O_MOVE_ANGLE_YAW_INDEX, 0x400);
                    obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ, O_FACE_ANGLE_PITCH_INDEX, 0x400);
                    o->oFaceAngleRoll = 0;
                }
            }
            
    }
    else {
        o->oMoveAngleYaw += 0x80;
    }
}

void gold_blob_approach_home(void) {
    f32 x = o->oHomeX - o->oPosX;
    f32 y = o->oHomeY - o->oPosY;
    f32 z = o->oHomeZ - o->oPosZ;

    o->oPosX += x * 3.0f * (1.0f - coss(((f32)o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    o->oPosY += y * (1.0f - coss(((f32)o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    o->oPosZ += z * (1.0f - coss(((f32)o->oTimer / 90.0f) * 0x8000)) / 2.0f;
}

void bhv_gold_fragment_loop(void) {
    if (o->oTimer == 0) {
        o->oVelY = (random_u16() / 1024) - 32;
        o->oForwardVel = (random_u16() / 1024) + 20;
        o->oMoveAngleYaw = random_u16();
    }

    o->oGravity = 0;
    object_step();
    cur_obj_scale(1.0f - ((f32) o->oTimer)/30.0f);

    f32 dist;
                struct Object *goddess = cur_obj_find_nearest_object_with_behavior(bhvGoddessBoss, &dist);

                if (goddess) {
                    
                    obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ, O_FACE_ANGLE_PITCH_INDEX, 0x400);
                    
                }

                if (o->oTimer == 29) {
                    obj_mark_for_deletion(o);
                }
}
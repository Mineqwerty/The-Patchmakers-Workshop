#include "src/game/game_init.h"

static struct ObjectHitbox sD4Hitbox = {
    /* interactType:      */ INTERACT_PUSH_OUT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 20,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 140,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sD6Hitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 20,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 140,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sD8Hitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 24,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 140,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sD12Hitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 24,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 140,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sD20Hitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 40,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 140,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sDiceSpearHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 150,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 290,
};

static struct ObjectHitbox sDiceCubeShotHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 90,
};

void bhv_dice_boss_init(void) {
    o->oDiceBossCurrentDie = 0;
}

void bhv_dice_boss_loop(void) {

    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] < o->oPosY + 100) {
                o->oAction = 1;
            }
        break;
        case 1:
            switch (o->oDiceBossCurrentDie) {
                case 0:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 100, 0, o, MODEL_D4, bhvD4);
                break;
                case 1:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 0, 0, o, MODEL_D6, bhvD6);
                break;
                case 2:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 100, 0, o, MODEL_D8, bhvD8);
                break;
                case 3:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 100, 0, o, MODEL_D12, bhvD12);
                break;
                case 4:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 200, 0, o, MODEL_D20, bhvD20);
                break;
                case 5:
                    spawn_default_star(o->oPosX, o->oPosY + 300, o->oPosZ);
                    o->oDiceBossCurrentDie++;
                break;

            }

            o->oAction = 2;
        break;
        case 3:
            if (o->oTimer == 90) {
                o->oAction = 1;
            }
        break;
    }
    
}

void common_dice_death(void) {
    o->parentObj->oDiceBossCurrentDie++;
    o->parentObj->oDiceBossDieObj = NULL;
        o->parentObj->oAction = 3;
        gBossHealth = 0;
        spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        o->oNumLootCoins = 5;
        cur_obj_spawn_loot_blue_coin();
        obj_mark_for_deletion(o);

    
}

void bhv_d4_init(void) {
    obj_set_hitbox(o, &sD4Hitbox);
    gBossMaxHealth = o->oHealth;
    gBossHealth = o->oHealth;
}

void bhv_d4_loop(void) {
    switch (o->oAction) {
        case 0:

            if (o->oTimer == 180) {
                o->oAction = 1;
            }

            if (o->oTimer % 30 == 0) {
                o->oMoveAngleYaw += 0x5555;
            }
            
            o->oFaceAngleYaw += 0x200;

            o->oForwardVel = 20.0f;
            cur_obj_move_xz_using_fvel_and_yaw();
            cur_obj_scale(1.0f);

        break;
        case 1:
            if (o->oTimer == 45) {
                o->oLaser1Obj = spawn_object_relative(0, 0, 50, 0, o, MODEL_DICE_LASER, bhvDiceLaser);
                o->oLaser2Obj = spawn_object_relative(0, 0, 50, 0, o, MODEL_DICE_LASER, bhvDiceLaser);
                o->oLaser3Obj = spawn_object_relative(0, 0, 50, 0, o, MODEL_DICE_LASER, bhvDiceLaser);
                o->oAction = 2;
            }
            cur_obj_scale(1.0f + (((f32)o->oTimer) / 60.0f));
        break;
        case 2:
            cur_obj_scale(CLAMP(1.0f + ((45.0f - (f32)o->oTimer) / 60.0f), 1.0f, 2.0f));
            o->oLaser1Obj->oPosX = o->oPosX + 150 * sins(o->oFaceAngleYaw + 0x2AAA);
            o->oLaser1Obj->oPosZ = o->oPosZ + 150 * coss(o->oFaceAngleYaw + 0x2AAA);
            o->oLaser1Obj->oFaceAngleYaw = o->oFaceAngleYaw + 0x2AAA;

            o->oLaser2Obj->oPosX = o->oPosX + 150 * sins(o->oFaceAngleYaw + 0x5555 + 0x2AAA);
            o->oLaser2Obj->oPosZ = o->oPosZ + 150 * coss(o->oFaceAngleYaw + 0x5555 + 0x2AAA);
            o->oLaser2Obj->oFaceAngleYaw = o->oFaceAngleYaw + 0x5555 + 0x2AAA;

            o->oLaser3Obj->oPosX = o->oPosX + 150 * sins(o->oFaceAngleYaw + 2*0x5555 + 0x2AAA);
            o->oLaser3Obj->oPosZ = o->oPosZ + 150 * coss(o->oFaceAngleYaw + 2*0x5555 + 0x2AAA);
            o->oLaser3Obj->oFaceAngleYaw = o->oFaceAngleYaw + 2*0x5555 + 0x2AAA;

            o->oFaceAngleYaw += 0x200;

            if (o->oTimer == 120) {
                o->oAction = 3;
            }

        break;
        case 3:
            obj_mark_for_deletion(o->oLaser1Obj);
            obj_mark_for_deletion(o->oLaser2Obj);
            obj_mark_for_deletion(o->oLaser3Obj);
            o->oAction = 0;
        break;
    }

    gBossHealth = o->oHealth;

    if (o->oHealth <= 0) {
        common_dice_death();
    }

    
}

void bhv_dice_laser_init(void) {
   
}

void bhv_dice_laser_loop(void) {
    Vec3f pointA;
    Vec3f pointB;
    Vec3f pointC;
    Vec3f pointD;

    s16 laserWidth = 120;
    s16 laserLength = 10000;

    vec3f_set(pointA, o->oPosX + laserWidth * coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointB, o->oPosX + laserWidth * -coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * -sins(o->oFaceAngleYaw + 0x50));

    //vec3f_set(pointA, o->oPosX + 300 * coss(o->oFaceAngleYaw + 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw + 0x50));
    //vec3f_set(pointB, o->oPosX + 300 * coss(o->oFaceAngleYaw - 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw - 0x50));
    vec3f_set(pointC, pointA[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointA[2] + laserLength * coss(o->oFaceAngleYaw));
    vec3f_set(pointD, pointB[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointB[2] + laserLength * coss(o->oFaceAngleYaw));


    if (point_inside_xz_tri(gMarioState->pos, pointA, pointB, pointC) || point_inside_xz_tri(gMarioState->pos, pointA, pointC, pointD)) {
        if (absf(o->oPosY - gMarioState->pos[1] + 60) < 100 && gMarioState->action != ACT_BACKWARD_AIR_KB) {
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            o->oDamageOrCoinValue = 3;
            take_damage_and_knock_back(gMarioState, o);
            gMarioState->vel[1] = 5;
            gMarioState->forwardVel = 0.0f;
            gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
            o->parentObj->oAction = 3;
        }
    }
}

void bhv_d6_init(void) {
    obj_set_hitbox(o, &sD6Hitbox);
    gBossMaxHealth = o->oHealth;
    gBossHealth = o->oHealth;
    o->oWallHitboxRadius = 200.0f;
}

void bhv_d6_loop(void) {
    cur_obj_update_floor_and_walls();
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 90) {
                o->oAction = 1 + random_u16()%2;
            }
        break;
        case 1:
            o->oPosX = approach_f32_symmetric(o->oPosX, gMarioState->pos[0], 80);
            if (o->oTimer == 60) {
                o->oAction += 2;
                if (o->oPosZ > gMarioState->pos[2]) {
                    o->oF4 = -1;
                }
                else {
                    o->oF4 = 1;
                }
            }
        break;
        case 2:
            o->oPosZ = approach_f32_symmetric(o->oPosZ, gMarioState->pos[2], 80);
            if (o->oTimer == 60) {
                o->oAction += 2;
                if (o->oPosX > gMarioState->pos[0]) {
                    o->oF4 = -1;
                }
                else {
                    o->oF4 = 1;
                }
            }
        break;
        
        case 3:
            o->oPosZ += o->oF4 * 80.0f;
            if (o->oTimer == 90) {
                o->oAction = 0;
            }
            if (o->oMoveFlags & (OBJ_MOVE_HIT_WALL)) {
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
                o->oAction = 0;
            }
        break;
        case 4:
            o->oPosX += o->oF4 * 80.0f;
            if (o->oTimer == 90) {
                o->oAction = 0;
            }
            if (o->oMoveFlags & (OBJ_MOVE_HIT_WALL)) {
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
                o->oAction = 0;
            }
        break;
    }

    gBossHealth = o->oHealth;

    if (o->oHealth <= 0) {
        common_dice_death();
    }

    cur_obj_update_floor_and_walls();
    o->oInteractStatus = 0;
    

}

void bhv_d8_init(void) {
    obj_set_hitbox(o, &sD8Hitbox);
    gBossMaxHealth = o->oHealth;
    gBossHealth = o->oHealth;
    o->oWallHitboxRadius = 200.0f;
}

void bhv_d8_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 30) {
                o->oAction = 1;
            }
        break;
        case 1:
            o->oFaceAngleYaw += 0x100 + 20*o->oTimer;
            o->oPosY += 10 + 0.3f * o->oTimer;
            if (o->oTimer == 120) {
                o->oAction = 2;
            } 
        break;
        case 2:
            cur_obj_hide();
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            if (o->oTimer == 30) {
                for (int i = 0; i < 8; i++) {
                    struct Object *stabSpear = spawn_object_relative(0, 0, 0, 0, o, MODEL_DICE_SPEAR, bhvDiceSpear);
                    stabSpear->oMoveAngleYaw = 0x1FFF * i;
                }
                o->oAction = 3;
                o->oVelY = 0;
            }
        break;
        case 3:
            cur_obj_unhide();
            o->oPosY += o->oVelY;
            o->oVelY -= 1.8f;
            f32 floorHeight = find_floor_height(o->oPosX, o->oPosY + 500, o->oPosZ);

            if ((o->oPosY < floorHeight) || o->oTimer == 120) {
                o->oPosY = floorHeight;
                o->oAction = 4;
            }

        break;
        case 4:
            if (o->oTimer == 60) {
                o->oAction = 0;
            }
        break;
    }

    cur_obj_update_floor_and_walls();
    o->oInteractStatus = 0;

    gBossHealth = o->oHealth;

    if (o->oHealth <= 0) {
        common_dice_death();
    }
}

void bhv_d12_init(void) {
    obj_set_hitbox(o, &sD12Hitbox);
    gBossMaxHealth = o->oHealth;
    gBossHealth = o->oHealth;
    o->oWallHitboxRadius = 200.0f;
}

void bhv_d12_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 30) {
                o->oAction = 1;
            }
        break;
        case 1:
            obj_scale_xyz(o, 1.0f + ((f32)o->oTimer / 30), 1.0f - ((f32)o->oTimer / 60), 1.0f + ((f32)o->oTimer / 30));
            if (o->oTimer == 30) {
                o->oAction = 2;
                o->oVelY = 40;
                o->oMoveAngleYaw = random_u16();
                
            }
        break;
        case 2:
            obj_scale_xyz(o, 2.0f - ((f32)o->oTimer / 15), 0.5f + ((f32)o->oTimer / 30), 2.0f - ((f32)o->oTimer / 15));
            o->oPosY += o->oVelY;
            o->oVelY -= 2;
            o->oForwardVel = 20.0f;
            cur_obj_move_xz_using_fvel_and_yaw();
            if (o->oTimer == 15) {
                o->oAction = 3;
            }

        break;
        case 3:
            o->oPosY += o->oVelY;
            o->oVelY -= 2;
            cur_obj_move_xz_using_fvel_and_yaw();
            f32 floorHeight = find_floor_height(o->oPosX, o->oPosY + 500, o->oPosZ);

            if ((o->oPosY < floorHeight) || o->oTimer == 120) {
                o->oPosY = floorHeight;
                for (int i = 0; i < 12; i++) {
                    struct Object *stabSpear = spawn_object_relative(0, 0, 0, 0, o, MODEL_DICE_GROUND_SPIKE, bhvDiceGroundSpike);
                    stabSpear->oMoveAngleYaw = 0x1555 * i;
                }
                o->oAction = 4;
            }
        break;
        case 4:
            if (o->oTimer == 30) {
                o->oAction = 0;
            }
        break;
    }

    cur_obj_update_floor_and_walls();
    o->oInteractStatus = 0;

    gBossHealth = o->oHealth;

    if (o->oHealth <= 0) {
        common_dice_death();
    }
}

void bhv_d20_init(void) {
    obj_set_hitbox(o, &sD20Hitbox);
    gBossMaxHealth = o->oHealth;
    gBossHealth = o->oHealth;
    o->oWallHitboxRadius = 200.0f;
}

void bhv_d20_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 30) {
                o->oAction = 1;
            }
        break;
        case 1:
            for (int i = 0; i < 20; i++) {
                spawn_object_relative(0, 0, 0, 0, o, MODEL_DICE_CUBE_SHOT, bhvDiceCubeShot);
            }
            o->oAction = 2;
            o->oMoveAngleYaw = random_u16();
        break;
        case 2:
            o->oMoveAngleYaw += 0x200;
            o->oForwardVel = 30;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer == 90) {
                o->oAction = 0;
            }
        break;
    }

    o->oFaceAngleYaw += 0x555;

    cur_obj_update_floor_and_walls();
    o->oInteractStatus = 0;

    gBossHealth = o->oHealth;

    if (o->oHealth <= 0) {
        common_dice_death();
    }
}

void bhv_dice_spear_init(void) {
    obj_set_hitbox(o, &sDiceSpearHitbox);
}

void bhv_dice_spear_loop(void) {
    o->oForwardVel = 18.0f;
    o->oFaceAngleYaw = o->oMoveAngleYaw;
    o->oFaceAnglePitch = -0x200;
    o->oPosY += o->oVelY;
    o->oVelY -= 1.4f;
    cur_obj_move_xz_using_fvel_and_yaw();
    if (o->oTimer == 170) {
        obj_mark_for_deletion(o);
    }
}

void bhv_dice_ground_spike_init(void) {
    obj_set_hitbox(o, &sDiceSpearHitbox);
}

void bhv_dice_ground_spike_loop(void) {
    o->oForwardVel = 23.0f;
    o->oFaceAngleYaw = o->oMoveAngleYaw;
    o->oPosY -= 2;
    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oTimer == 180) {
        obj_mark_for_deletion(o);
    }
}

void bhv_dice_cube_shot_init(void) {
    o->oMoveAngleYaw = random_u16();
    obj_set_hitbox(o, &sDiceCubeShotHitbox);
}

void bhv_dice_cube_shot_loop(void) {
    o->oGravity = 0;
    o->oForwardVel = 30.0f;
    object_step();

    o->oFaceAngleYaw += 0x333;
    o->oFaceAnglePitch += 0x233;
    o->oFaceAngleRoll += 0x233;

    if (o->oTimer >= 90) {
        obj_mark_for_deletion(o);
        spawn_object_relative(0, 0, 0, 0, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
    }
}


#define GODDESS_ACT_CUTSCENE 0
#define GODDESS_ACT_IDLE_FLIGHT 1
#define GODDESS_ACT_GOLD_BARRAGE 2
#define GODDESS_ACT_SPEAR_DIVE 3
#define GODDESS_ACT_CLOSE_COMBAT 4
#define GODDESS_ACT_HURT 5
#define GODDESS_ACT_FLY_UP 6
#define GODDESS_ACT_BANISH 7
#define GODDESS_ACT_DEATH 8

#include "src/game/game_init.h"
#include "src/game/cutscene.h"
#include "src/game/ingame_menu.h"
#include "src/game/puppyprint.h"

static struct ObjectHitbox sGoddessHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 4,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 600,
    /* height:            */ 1500,
    /* hurtboxRadius:     */ 500,
    /* hurtboxHeight:     */ 1000,
};

static struct ObjectHitbox sBanishFragmentHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 4,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 50,
};

void goddess_act_idle_flight(void) {
    cur_obj_init_animation(0);
    gCamera->controlBossCameraYaw = 1;
    o->hitboxRadius = 600;
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
    o->oPosY += 20 * coss(0x400 * o->oTimer);
    o->oPosX += 10 * coss(0x200 * o->oTimer) * sins(o->oMoveAngleYaw + 0x4000);
    o->oPosZ += 10 * coss(0x400 * o->oTimer) * coss(o->oMoveAngleYaw + 0x4000);

    o->oForwardVel = 10;
    cur_obj_move_xz_using_fvel_and_yaw();
}

void goddess_act_gold_barrage(void) {
    if (cur_obj_init_animation_and_check_if_near_end(6)) {
        o->oAction = GODDESS_ACT_SPEAR_DIVE;
    }

    if (o->oTimer % 8 == 0) {
        struct Object *bullet = spawn_object_relative(0, 0, 2000, 0, o, MODEL_GOLD_BLOB, bhvGoldBlob);
        bullet->oGoldBlobDirection = random_u16() % 2;
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
                o->oTimer = 0;
            }
            break;
        case 1:
            cur_obj_init_animation(8);
            f32 floorHeight = find_floor_height(o->oPosX, o->oPosY - 100, o->oPosZ);

            o->oPosY = approach_f32_asymptotic(o->oPosY, gMarioState->pos[1] + (500 * (1 + coss(o->oTimer * 0x5B0))), 0.2f);

            if (o->oTimer >= 15) {
                o->oForwardVel = 140.0f;
            }
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer == 53) {
                o->oSubAction++;
            }

            break;
        case 2:
            if (cur_obj_init_animation_and_check_if_near_end(9)) {
                o->oAction = GODDESS_ACT_IDLE_FLIGHT;
                o->oForwardVel = 0.0f;
            }
            break;
    }
}

void goddess_act_close_combat(void) {
    if (o->oTimer < 90) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    } else {
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

void goddess_act_hurt(void) {
    if (cur_obj_init_animation_and_check_if_near_end(10)) {
        o->oAction = GODDESS_ACT_FLY_UP;
        if (gMarioState->equippedPatch == PATCH_HALO && gMarioState->patchChildObj) {
            gMarioState->patchChildObj->oHaloLengthMod = 1.0f;
        }
        o->hitboxRadius = 600;
        return;
    }

    if (o->oTimer == 0) {
        o->oForwardVel = -20.0f;
        // o->oDragStrength = 2.0f;
        o->oVelY = 20.0f;
        f32 startFHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
        if (o->oPosY - startFHeight <= 30.0f) {
            o->oPosY = startFHeight + 40;
        }

        if (gMarioState->equippedPatch == PATCH_HALO && gMarioState->patchChildObj) {
            gMarioState->patchChildObj->oHaloLengthMod = 3.0f;
        }
    }
    o->hitboxRadius = 1200;
    f32 fHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    if (o->oTimer < 60) {
        object_step_without_floor_orient();
        o->oGravity = 2.0f;
        
        if (o->oPosY - fHeight < 100.0f) {
            o->oPosY = fHeight;
            o->oTimer = 60;
            //o->header.gfx.animInfo.animFrame = 53;
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1040);
        }

        if (o->oTimer > 40) {
            o->oGravity += o->oTimer - 40;
        }
    } else {
        o->oPosY = fHeight;
        o->oGravity = 0.0f;
        // o->oDragStrength = 0.0f;
        o->oForwardVel = 0.0f;
    }
}

void goddess_act_fly_up(void) {
    cur_obj_init_animation(11);
    gCamera->controlBossCameraYaw = 1;

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x240);

    if (o->oTimer == 10) {
        o->oForwardVel = -60.0f;
        o->oVelY = 40.0f;
    }

    if (o->oPosY > gMarioState->pos[1] + 2000) {
        o->oAction = GODDESS_ACT_IDLE_FLIGHT;
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
                for (int i = 0; i < 8; i++) {
                    spawn_object_relative(i, 0, 0, 0, o, MODEL_GOLD_FRAGMENT, bhvBanishFragment);
                }
                o->oSubAction++;
            }
            break;
        case 1:
            cur_obj_init_animation(4);

            if (o->oHealth <= 75 && o->oTimer == 40) {
                for (int i = 0; i < 8; i++) {
                    spawn_object_relative(i, 0, 0, 0, o, MODEL_GOLD_FRAGMENT, bhvBanishFragment);
                }
            }
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
            //gSecondCameraFocus = o;
            //set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
            o->oSubAction = 1;
            begin_cutscene_event(1);
            break;
        case 1:
        /*
            gCamera->cutscene = 1;
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gLakituState.goalPos[0] = -1495;
            gLakituState.goalPos[1] = 912;
            gLakituState.goalPos[2] = -1726;

            gLakituState.goalFocus[0] = -107;
            gLakituState.goalFocus[1] = 1792;
            gLakituState.goalFocus[2] = 706;
            */
            cur_obj_init_animation(1);
            if (gPageNum == 9) {
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

            if (cCutsceneActive == 0) {
                o->oAction = GODDESS_ACT_IDLE_FLIGHT;
                cur_obj_init_animation(0);
                gSecondCameraFocus = o;
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
                o->oHealth = 100;
                gBossMaxHealth = 100;
                gBossHealth = 100;
            }
            
            

            break;
    }
}

void keep_goddess_in_range(void) {
    f32 xMax = 2800;
    f32 xMin = -3000;
    f32 yMax = 1840;
    f32 zMax = -1500;
    f32 zMin = -7000;

    if (o->oPosX < xMin) {
        o->oPosX += xMin - o->oPosX;
    }
    if (o->oPosX > xMax) {
        o->oPosX -= o->oPosX - xMax;
    }
    if (o->oPosZ < zMin) {
        o->oPosZ += zMin - o->oPosZ;
    }
    if (o->oPosZ > zMax) {
        o->oPosZ -= o->oPosZ - zMax;
    }
    if (o->oPosY > yMax) {
        o->oPosY -= o->oPosY - yMax;
    }
}

void goddess_check_interactions(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {

            //u8 healthSubtract = 1;
            //for (int i = 0; i < (o->oInteractStatus & INT_STATUS_ATTACK_MASK); i++) {
            //    healthSubtract *= 2;
            //}
            //o->oHealth -= healthSubtract;
            o->oGoddessInvulnerableTimer = 10;

            if (gBossHealth - o->oHealth > 15) {
                o->oAction = GODDESS_ACT_HURT;
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1040);
                for (int i = 0; i < 8; i++) {
                    struct Object *fragment =
                        spawn_object_relative(0, 0, 1000, 0, o, MODEL_GOLD_FRAGMENT, bhvGoldFragment);
                }
            }
        }
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void gold_blob_approach_home(void) {
    f32 x = (o->oHomeX - o->oPosX) * (o->oGoldBlobDirection == 0 ? 3.0f : 1.0f) * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    f32 y = (o->oHomeY - o->oPosY) * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    f32 z = (o->oHomeZ - o->oPosZ) * (o->oGoldBlobDirection == 0 ? 1.0f : 3.0f) * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;

    o->oPosX += x;
    o->oPosY += y;
    o->oPosZ += z;
    o->oVelX = x;
    o->oVelY = y;
    o->oVelZ = z;
}



void bhv_gold_blob_loop(void) {
    obj_scale_xyz(o, 1.0f + (0.05f * sins((o->oTimer * 0x1000) + 0x4000)),
                  1.0f + (0.05f * coss(o->oTimer * 0x1000)), 1.0f + (0.05f * sins(o->oTimer * 0x1000)));

    if (!obj_has_model(o, MODEL_GOLD_SWORD)) {
        o->oFaceAnglePitch += 0x200;
        o->oFaceAngleRoll += 0x100;
    }

    if (o->oAction == 1) {
        if (o->oTimer < 30) {
            cur_obj_become_intangible();
        } else {
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
                obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ,
                                         O_FACE_ANGLE_PITCH_INDEX, 0x400);
                o->oFaceAngleRoll = 0;
            }

            gold_blob_approach_home();

            if (goddess && o->oTimer == 30) {
                attack_object(goddess, 32, 20);

                obj_mark_for_deletion(o);
            }
        }

        else {

            f32 dist;
            struct Object *seraphim = cur_obj_find_nearest_object_with_behavior(bhvSeraphim, &dist);
            if (seraphim && dist < 8000) {
                o->oHomeX = seraphim->oPosX;
                o->oHomeY = seraphim->oPosY;
                o->oHomeZ = seraphim->oPosZ;

                o->oMoveAngleYaw += 0x80;
                 o->oFaceAnglePitch += 0x200;
        o->oFaceAngleRoll += 0x100;

                gold_blob_approach_home();

                if (seraphim && o->oTimer == 30) {
                    attack_object(seraphim, 32, 10);

                    obj_mark_for_deletion(o);
                }
            } else {
                if (o->oTimer == 0) {
                    o->oForwardVel = 50.0f;
                    o->oVelY = 20.0f;
                    o->oGravity = 2.0f;
                    o->oMoveAngleYaw = gMarioState->faceAngle[1];
                }
                object_step();
            }
        }
    } else if (o->oAction == 2) {

        if (o->oTimer == 35) {
            //o->oForwardVel = 70.0f;
            //o->oVelY = -6.0f;
            o->oGravity = 2.0f;
            o->oBounciness = 2.0f;
        }
        if (o->oTimer < 35) {
            gold_blob_approach_home();
            obj_turn_toward_position(o, o->oHomeX, o->oHomeY, o->oHomeZ, O_MOVE_ANGLE_YAW_INDEX, 0x400);
        }
        else {
            object_step();
        }

         
        if (o->oTimer < 20) {
            o->oHomeX = gMarioState->pos[0];
            o->oHomeY = gMarioState->pos[1];
            o->oHomeZ = gMarioState->pos[2];    
        }

        if (o->oTimer == 60) {
            switch (random_u16() % 3) {
                case 0:
                    o->oAction = 3;
                    break;
                default:
                    spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                    obj_mark_for_deletion(o);
                    break;
            }
        }
    } else if (o->oAction == 3) {
        if (o->oTimer == 0) {
            o->oForwardVel = 10.0f;
            o->oGravity = 5.0f;
        }

        if (o->oTimer > 450 && (gMarioState->patchChildObj == NULL || 
            gMarioState->patchChildObj->oHaloCapturedObject == NULL || 
            (gMarioState->patchChildObj && gMarioState->patchChildObj->oHaloCapturedObject && gMarioState->patchChildObj->oHaloCapturedObject != o))) {
            spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
            obj_mark_for_deletion(o);
            
        }

        if (gMarioState->patchChildObj && gMarioState->patchChildObj->oHaloCapturedObject && gMarioState->patchChildObj->oHaloCapturedObject->oAction == 1) {
            spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
            obj_mark_for_deletion(o);
        }

        if (o->oTimer < 20) {
            object_step();
        }

        if (o->oGoldBlobCount >= 2) {
            if (gCurrAreaIndex == 4) {
            obj_set_model(o, MODEL_GOLD_SWORD);
            }
            else {
                obj_set_model(o, MODEL_GOLD_SPIKE_BALL);
            }

            f32 dist;
            struct Object *goddess = cur_obj_find_nearest_object_with_behavior(bhvGoddessBoss, &dist);

            if (goddess) {
                obj_turn_toward_object(o, goddess, O_MOVE_ANGLE_YAW_INDEX, 0x400);
                obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ,
                                         O_FACE_ANGLE_PITCH_INDEX, 0x400);
                o->oFaceAngleRoll = 0;
            }

            f32 dist2;

            struct Object *seraphim = cur_obj_find_nearest_object_with_behavior(bhvSeraphim, &dist2);

            if (seraphim && dist2 < 8000) {
                 o->oMoveAngleYaw += 0x80;
                 o->oFaceAnglePitch += 0x200;
        o->oFaceAngleRoll += 0x100;
            }
        }

    } else {
        o->oMoveAngleYaw += 0x80;
    }
}

void bhv_gold_fragment_loop(void) {
    if (o->oTimer == 0) {
        o->oVelY = (random_u16() / 1024) - 32;
        o->oForwardVel = (random_u16() / 1024) + 20;
        o->oMoveAngleYaw = random_u16();
    }

    o->oGravity = 0;
    object_step();
    cur_obj_scale(1.0f - ((f32) o->oTimer) / 30.0f);

    f32 dist;
    struct Object *goddess = cur_obj_find_nearest_object_with_behavior(bhvGoddessBoss, &dist);

    if (goddess) {

        obj_turn_toward_position(o, goddess->oPosX, goddess->oPosY + 1000, goddess->oPosZ,
                                 O_FACE_ANGLE_PITCH_INDEX, 0x400);
    }

    if (o->oTimer == 29) {
        obj_mark_for_deletion(o);
    }
}

void banish_fragment_descend(f32 y) {
    o->oPosY = approach_f32_asymptotic(o->oPosY, y, 0.1f);
}

void bhv_banish_fragment_loop(void) {
    if (o->oTimer < 120) {
        f32 offsetAngle = o->oBehParams2ndByte * 0x2492;

        o->oPosX = gMarioState->pos[0] + 600.0f * sins(o->oTimer * 0x400 + offsetAngle);

        banish_fragment_descend(gMarioState->pos[1] + 50.0f);

        o->oPosZ = gMarioState->pos[2] + 600.0f * coss(o->oTimer * 0x400 + offsetAngle);

        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
        o->oFaceAnglePitch = 0x4000;

    } else if (o->oTimer > 130) {
            cur_obj_become_tangible();
        obj_set_hitbox(o, &sBanishFragmentHitbox);
        
        o->oGravity = 0.0f;
        o->oForwardVel = 120.0f;
        object_step_without_floor_orient();
    }

    if (o->oTimer == 150) {
        struct Object *blob;
        switch (random_u16() % 5) {
            case 0:
                blob = spawn_object_relative(0, 0, 0, 0, o, MODEL_GOLD_BLOB, bhvGoldBlob);
                blob->oAction = 3;
                break;
        }
        spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
        obj_mark_for_deletion(o);
    }
}


void bhv_goddess_init(void) {
    o->oGravity = 0;
    o->oWallHitboxRadius = 150.0f;

    obj_set_hitbox(o, &sGoddessHitbox);
    //o->oAction = 1;
    //gSecondCameraFocus = o;
    //            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);

    
}

void bhv_goddess_loop(void) {

    switch (o->oAction) {
        case GODDESS_ACT_CUTSCENE:
            goddess_act_cutscene();
            break;
        case GODDESS_ACT_IDLE_FLIGHT:
            goddess_act_idle_flight();
            break;
        case GODDESS_ACT_GOLD_BARRAGE:
            goddess_act_gold_barrage();
            break;
        case GODDESS_ACT_SPEAR_DIVE:
            goddess_act_spear_dive();
            break;
        case GODDESS_ACT_CLOSE_COMBAT:
            goddess_act_close_combat();
            break;
        case GODDESS_ACT_HURT:
            goddess_act_hurt();
            break;
        case GODDESS_ACT_FLY_UP:
            goddess_act_fly_up();
            break;
        case GODDESS_ACT_BANISH:
            goddess_act_banish();
            break;
    }
    if (o->oGoddessInvulnerableTimer == 0) {
        cur_obj_become_tangible();
        goddess_check_interactions();
    }
    else {
        o->oGoddessInvulnerableTimer--;
        cur_obj_become_intangible();
    }
    cur_obj_update_floor_and_walls();

    if (o->oAction != GODDESS_ACT_CUTSCENE) {
        keep_goddess_in_range();
    }
    gBossHealth = o->oHealth;
}

Gfx *geo_switch_goddess_eyes(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

            if (cCutsceneIndex == 26) {
                switchCase->selectedCase = 2;
            } else if (cCutsceneIndex == 28) {
                switchCase->selectedCase = 3;
            } else {
                switchCase->selectedCase = 1;
            }
    }
    return NULL;
}

Gfx *geo_switch_goddess_spear(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

            if (obj->oAction == GODDESS_ACT_SPEAR_DIVE && (obj->oSubAction >= 1 || obj->oTimer > 16)) {
                switchCase->selectedCase = 1;
            }
            else {
                switchCase->selectedCase = 0;
            }
    }
    return NULL;
}

Vec3f goddessRightHandLocation = {0, 0, 0};
Mat4 posMtx;
Gfx *geo_goddess_hand_location_update(s32 callContext, UNUSED struct GraphNode *node, Mat4 *mtx) {

    if (callContext == GEO_CONTEXT_RENDER) {
        create_transformation_from_matrices(posMtx, *mtx, *gCurGraphNodeCamera->matrixPtr);
        vec3f_set(goddessRightHandLocation, posMtx[3][0], posMtx[3][1], posMtx[3][2]);
    }

    return NULL;
}

void bhv_goddess_spear_init(void) {

}

void bhv_goddess_spear_loop(void) {
    
}


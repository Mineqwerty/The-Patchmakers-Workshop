#include "actors/grapple_line/geo_header.h"
#include "src/buffers/framebuffers.h"
#include "src/game/game_init.h"
#include "actors/group0.h"
#include "src/game/level_update.h"

struct SpawnParticlesInfo sMistIce = { 2, 4, MODEL_MIST, 10.0f, -20, 0, 20, 40, 252, 30, 15.0f, 0.0f };
struct SpawnParticlesInfo sSnowflakeFly = { 2, 8,  MODEL_SNOWFLAKE, 10.0f, 40, 10, 0, 0,
                                            0, 30, 13.0f,           6.0f };

static struct ObjectHitbox sIceSpikesHitbox = {
    /* interactType:      */ INTERACT_DAMAGE_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 90,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 20,
    /* hurtboxHeight:     */ 20,
};

static struct ObjectHitbox sGrappleHookHitbox = {
    /* interactType:      */ INTERACT_DAMAGE_ENEMY,
    /* downOffset:        */ 30,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 20,
    /* hurtboxHeight:     */ 20,
};

static struct ObjectHitbox sHaloHitbox = {
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

void bhv_ice_spikes_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
    o->oFaceAngleYaw = 0x2000;
}

void bhv_ice_spikes_loop(void) {
    obj_set_hitbox(o, &sIceSpikesHitbox);
    for (int i = 0; i < o->numCollidedObjs; i++) {
        struct Object *other = o->collidedObjs[i];

        if (other != gMarioObject) {
            // other->oInteractStatus |= INT_STATUS_TOUCHED_MARIO | INT_STATUS_WAS_ATTACKED |
            // INT_STATUS_INTERACTED | INT_STATUS_TOUCHED_BOB_OMB;
            attack_object(other, 8, 8);
        }
    }

    o->oInteractStatus = 0;

    if (o->oTimer < 5) {
        if ((gMarioState->action != ACT_GROUND_POUND_LAND)) {
            obj_mark_for_deletion(o);
        }
    }
    if (o->oTimer <= 9) {
        obj_scale_xyz(o, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f);
    } else if (o->oTimer > 30 && o->oTimer < 35) {
        obj_scale_xyz(o, 1.5f, 4.5f - ((f32) o->oTimer) / 10.0f, 1.5f);
        o->oPosY -= 5.0f;
    } else if (o->oTimer >= 35) {
        obj_scale_xyz(o, 3.5f - ((f32) o->oTimer - 5) / 15.0f, 4.5f - ((f32) o->oTimer) / 10.0f,
                      3.5f - ((f32) o->oTimer - 5) / 15.0f);
    }

    if (o->oTimer == 40) {
        obj_mark_for_deletion(o);
    }
}

void bhv_ice_floor_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
    cur_obj_spawn_particles(&sSnowflakeFly);
    cur_obj_spawn_particles(&sMistIce);
    // obj_orient_graph(o, gMarioState->floor->normal.x, gMarioState->floor->normal.y,
    // gMarioState->floor->normal.z, 1);
    /*
    struct Surface *waterFloor;
    Vec3f position;

    vec3f_copy(position, &o->oPosVec);

    find_water_floor(o->oPosX, o->oPosY + 100, o->oPosZ, &waterFloor);
    if (gMarioState->floor) {
        Vec3f floorNormal;
        surface_normal_to_vec3f(floorNormal, gMarioState->floor);
        mtxf_align_terrain_normal(o->transform, floorNormal, position, o->oFaceAngleYaw);
        o->header.gfx.throwMatrix = &o->transform;

    }
    */
}

void bhv_ice_floor_loop(void) {

    cur_obj_align_gfx_with_floor_ice();

    switch (o->oAction) {
        case 0:
            if (o->oTimer < 2) {
                obj_scale_xyz(o, ((f32) o->oTimer) / 2.0f, 1, ((f32) o->oTimer) / 2.0f);
            } else if (sqr(gMarioState->pos[0] - o->oPosX) + sqr(gMarioState->pos[2] - o->oPosZ)
                       > 20000.0f) {
                o->oAction += 1;
                o->oTimer = 0;
            } else {
                obj_scale_xyz(o, 1.5f, 1.5f, 1.5f);
            }

            if (o->oTimer > 20 && !o->parentObj) {
                o->oAction += 1;
                o->oTimer = 0;
            }
            break;
        case 1:
            obj_scale_xyz(o, 1.0f - ((f32) o->oTimer) / 10.0f, 1, 1.0f - ((f32) o->oTimer) / 10.0f);

            if (o->oTimer >= 10) {
                obj_mark_for_deletion(o);
            }
            break;
    }
}

void bhv_ice_cube_init(void) {
    gMarioState->forwardVel = 0;
    // gMarioState->pos[0] += (o->oPosX - gMarioState->pos[0] / 3.0f);
    // gMarioState->pos[2] += (o->oPosZ - gMarioState->pos[2] / 3.0f);
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[2] = o->oPosZ;
    gMarioState->action = ACT_JUMP_LAND;

    check_ice_cube_corners_and_push();
}

extern s16 gCutsceneTimer;

void bhv_ice_cube_loop(void) {

    if (o->oIsPushingIceCube == 1 && o->oTimer < 10) {
        check_ice_cube_corners_and_push();
    }

    if (o->oTimer <= 3) {

        switch (o->oBehParams2ndByte) {
            case 0:
                obj_scale_xyz(o, 1, CLAMP(((f32) o->oTimer) / 3.0f, 0.1f, 1.0f), 1);
                break;
            case 1:
                obj_scale_xyz(o, 2, CLAMP(((f32) o->oTimer) / 3.0f, 0.1f, 1.0f), 2);
                break;
            case 2:
                obj_scale_xyz(o, 4, CLAMP(((f32) o->oTimer) / 1.5f, 0.1f, 2.0f), 4);
                gMarioState->pos[1] += 50;
                gMarioState->vel[1] = 0;
                break;
        }

        // sinking mud failsafe
        if (gMarioState->action == ACT_SINK_MUD) {
            gMarioState->pos[0] = o->oPosX;
            gMarioState->pos[1] = o->oPosY + 100;
            gMarioState->pos[2] = o->oPosZ;
            gMarioState->action = ACT_JUMP_LAND;

            gCamera->cutscene = 0;
            clear_cutscene_vars(gCamera);
            gCutsceneTimer = 0;
        }
    }

    if ((cur_obj_was_attacked_or_ground_pounded() || o->oAction == 20) && o->oBehParams2ndByte != 2) {
        for (int i = 0; i < o->parentObj->oNumLootCoins; i++) {
            struct Object *coin;
            coin = spawn_object_relative(0, 0, 50, 0, o, MODEL_YELLOW_COIN, bhvMovingYellowCoin);
            coin->oVelY = 20.0f;
            coin->oForwardVel = 3.0f;
            coin->oMoveAngleYaw = random_u16();
        }

        obj_mark_for_deletion(o->parentObj);

        // obj_explode_and_spawn_coins(46.0f, 0);
        spawn_mist_particles();
        spawn_triangle_break_particles(20, MODEL_SL_CRACKED_ICE_CHUNK, 3.0f, 0);
        obj_mark_for_deletion(o);
    }
}

void check_ice_cube_corners_and_push(void) {
    struct Surface *floor;
    Vec3f pushVec;
    pushVec[0] = 0;
    pushVec[2] = 0;
    o->oIsPushingIceCube = 0;
    if (find_floor(o->oPosX + 82, o->oPosY + 150, o->oPosZ + 82, &floor) < -10000) {
        pushVec[0] += -10;
        pushVec[2] += -10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX + 82, o->oPosY + 150, o->oPosZ - 82, &floor) < -10000) {
        pushVec[0] += -10;
        pushVec[2] += 10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX - 82, o->oPosY + 150, o->oPosZ + 82, &floor) < -10000) {
        pushVec[0] += 10;
        pushVec[2] += -10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX - 82, o->oPosY + 150, o->oPosZ - 82, &floor) < -10000) {
        pushVec[0] += 10;
        pushVec[2] += 10;
        o->oIsPushingIceCube = 1;
    }

    if (o->oIsPushingIceCube == 1) {
        o->parentObj->oFreezeObject = 0;
        o->parentObj->oIntangibleTimer = -1;
    } else {
        o->parentObj->oFreezeObject = 1;
    }

    o->oPosX += pushVec[0];
    o->oPosZ += pushVec[2];
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY;
    o->parentObj->oPosZ = o->oPosZ;
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[2] = o->oPosZ;
}

void bhv_grapple_hook_init(void) {
    o->oGrappleLine = spawn_object_relative(0, 0, 0, 0, o, MODEL_NONE, bhvGrappleLine);
    o->oForwardVel = 80.0f + gMarioState->forwardVel;
}

void bhv_grapple_hook_loop(void) {
    Vec3f adjustedPos;

    if (gMarioState->equippedPatch != PATCH_GRAPPLE) {
        obj_mark_for_deletion(o);
        return;
    }

    switch (o->oAction) {
        case 0:

            o->oGravity = 0.0f;
            o->oForwardVel -= 2.0f;

            struct Surface *surf;
            Vec3f originPos;
            Vec3f hitpos;
            Vec3f raydir;

            raydir[0] = sins(o->oMoveAngleYaw) * 100.0f;
            raydir[1] = 0.0f;
            raydir[2] = coss(o->oMoveAngleYaw) * 100.0f;

            vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

            vec3f_set(originPos, o->oPosX - (sins(o->oMoveAngleYaw) * 50.0f), o->oPosY,
                      o->oPosZ - (coss(o->oMoveAngleYaw) * 50.0f));

            find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);
            if (surf != NULL) {
                o->oPosX = hitpos[0];
                o->oPosY = hitpos[1];
                o->oPosZ = hitpos[2];
                play_sound(SOUND_GRAPPLE_HOOK_2, gMarioState->marioObj->header.gfx.cameraToObject);
                return o->oAction = 1;
            } else if (o->oTimer > 1) {
                // perform raycasts down and then up to see if it collides with a floor or ceiling
                raydir[0] = 0.0f;
                raydir[2] = 0.0f;

                raydir[1] = -20.0f;
                find_surface_on_ray(originPos, raydir, &surf, hitpos, 1U, 1);
                if (surf != NULL) {
                    o->oAngleVelPitch = -0x800;
                    o->oVelY = 5.0f;
                    o->oForwardVel = 10.0f;
                    return o->oAction = 2;
                }
                raydir[1] = 90.0f;
                find_surface_on_ray(originPos, raydir, &surf, hitpos, 4U, 1);
                if (surf != NULL) {
                    o->oAngleVelPitch = 0x1000;
                    o->oVelY = -30.0f;
                    o->oForwardVel = 10.0f;
                    return o->oAction = 2;
                }
            }

            obj_move_xyz_using_fvel_and_yaw(o);
             o->oInteractStatus = 0;
             obj_set_hitbox(o, &sGrappleHookHitbox);
            for (int i = 0; i < o->numCollidedObjs; i++) {
                struct Object *other = o->collidedObjs[i];

                if (other != gMarioObject) {
                     other->oInteractStatus |= INT_STATUS_INTERACTED;
                    attack_object(other, 2, 3);

                    if (!obj_has_behavior(other, bhvFortogoo)) {
                        o->oAngleVelPitch = -0x400;
                        o->oVelY = 0.0f;
                         o->oForwardVel = -10.0f;
                        return o->oAction = 2;
                    }
                }
            }

            if (o->oTimer == 15) {
                o->oForwardVel = 10.0f;
                o->oAction = 2;
                o->oAngleVelYaw = 0x400;
                o->oAngleVelPitch = 0x400;
            }
            break;
        case 1:

            if (gMarioState->action == ACT_STAR_DANCE_EXIT
                || gMarioState->action == ACT_STAR_DANCE_NO_EXIT
                || gMarioState->action == ACT_FALL_AFTER_STAR_GRAB) {
                gMarioState->patchChildObj = NULL;
                gMarioState->curPatch = PATCH_NONE;
                obj_mark_for_deletion(o->oGrappleLine);
                obj_mark_for_deletion(o);
                return;
            }

            vec3f_set(adjustedPos, o->oPosX, o->oPosY + 50, o->oPosZ);
            approach_vec3f_asymptotic(gMarioState->pos, adjustedPos, 0.5f, 0.5f, 0.5f);
            if (o->oTimer == 4) {
                gMarioState->faceAngle[1] += 0x8000;
                set_mario_action(gMarioState, ACT_GRAPPLE_WALL, 0);
                gMarioState->patchChildObj = NULL;
                gMarioState->curPatch = PATCH_NONE;
                obj_mark_for_deletion(o->oGrappleLine);
                obj_mark_for_deletion(o);
            }
            break;
        case 2:
            o->oGravity = 2.0f;
            o->oForwardVel = 10.0f;

            cur_obj_rotate_face_angle_using_vel();
            object_step_without_floor_orient();
            if (o->oTimer == 15) {
                gMarioState->patchChildObj = NULL;
                gMarioState->curPatch = PATCH_NONE;
                obj_mark_for_deletion(o->oGrappleLine);
                obj_mark_for_deletion(o);
            }
            break;
    }
}

void bhv_grapple_line_loop(void) {

    if (o->oTimer == 1) {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_GRAPPLE_LINE];
    }

    o->oPosX = o->parentObj->oPosX;
    o->oPosY = o->parentObj->oPosY;
    o->oPosZ = o->parentObj->oPosZ;

    if (o->parentObj->oAction != 2) {

        f32 dx = gMarioObject->header.gfx.pos[0] - o->oPosX;
        f32 dy = gMarioObject->header.gfx.pos[1] - o->oPosY + 90.0f;
        f32 dz = gMarioObject->header.gfx.pos[2] - o->oPosZ;
        s16 targetPitch = atan2s(sqrtf(sqr(dx) + sqr(dz)), dy);

        s16 targetAngle = atan2s(dz, dx);

        o->oMoveAngleYaw = targetAngle;

        o->oMoveAnglePitch = -targetPitch;
        o->oFaceAnglePitch = -targetPitch;

        extern Vtx grapple_line_Plane_002_mesh_layer_1_vtx_0[12];

        Vtx *new = segmented_to_virtual(grapple_line_Plane_002_mesh_layer_1_vtx_0);

        new[0].v.ob[2] = o->oDistanceToMario;
        new[1].v.ob[2] = o->oDistanceToMario;
        new[2].v.ob[2] = o->oDistanceToMario;
        new[5].v.ob[2] = o->oDistanceToMario;
        new[6].v.ob[2] = o->oDistanceToMario;
        new[7].v.ob[2] = o->oDistanceToMario;
    }

    if (gMarioState->equippedPatch != PATCH_GRAPPLE) {
        obj_mark_for_deletion(o);
    }
}

void halo_run_movement(void) {

    struct Surface *surf;
    Vec3f originPos;
    Vec3f hitpos;
    Vec3f raydir;

    raydir[0] = o->oHomeX - gMarioState->pos[0];
    raydir[1] = o->oHomeY - gMarioState->pos[1];
    raydir[2] = o->oHomeZ - gMarioState->pos[2];

    vec3f_copy(originPos, gMarioState->pos);

    find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);
    if (surf != NULL) {
        o->oHomeX = hitpos[0];
        // o->oHomeY = hitpos[1];
        o->oHomeZ = hitpos[2];
    }

    approach_f32_asymptotic_bool(&o->oPosX, o->oHomeX, o->oHaloApproachSpeed);
    approach_f32_asymptotic_bool(&o->oPosY, o->oHomeY, o->oHaloApproachSpeed);
    approach_f32_asymptotic_bool(&o->oPosZ, o->oHomeZ, o->oHaloApproachSpeed);

    o->oWallHitboxRadius = 50.0f;

    cur_obj_resolve_wall_collisions();
}

void halo_perform_circle(void) {

    if (o->oHaloCapturedObject && gMarioState->haloCaptureType == 3 && o->oTimer == 18
        && o->oHaloCapturedObject->oGoldBlobCount >= 2) {
        o->oHaloCapturedObject->oAction = 1;

        o->oHaloCapturedObject = NULL;
        gMarioState->haloCaptureType = 0;
    }

    o->oHaloApproachSpeed = 1;

    if (o->oTimer < 8) {
        o->oHomeX = gMarioState->pos[0] + (37 * o->oTimer) * sins(0x1000 * o->oTimer);
        o->oHomeZ = gMarioState->pos[2] + (37 * o->oTimer) * coss(0x1000 * o->oTimer);
    } else if (o->oTimer > 24) {
        o->oHomeX = gMarioState->pos[0] + (300 - (37 * (o->oTimer - 24))) * sins(0x1000 * o->oTimer);
        o->oHomeZ = gMarioState->pos[2] + (300 - (37 * (o->oTimer - 24))) * coss(0x1000 * o->oTimer);
    } else {
        o->oHomeX = gMarioState->pos[0] + 300 * sins(0x1000 * o->oTimer);
        o->oHomeZ = gMarioState->pos[2] + 300 * coss(0x1000 * o->oTimer);
    }

    halo_run_movement();

    if (o->oTimer == 32) {
        o->oAction = 2;
    }
}

void halo_calculate_and_move_towards_goal(void) {
    o->oHomeX = gMarioState->pos[0] + 300 * o->oHaloLengthMod * sins(o->oMoveAngleYaw);
    o->oHomeY = gMarioState->pos[1] + 70.0f;
    o->oHomeZ = gMarioState->pos[2] + 300 * o->oHaloLengthMod * coss(o->oMoveAngleYaw);

    o->oHaloApproachSpeed = 0.5f;

    Vec3f curPosVec = { o->oPosX, o->oPosY, o->oPosZ };
    Vec3f goalVec = { o->oHomeX, o->oHomeY, o->oHomeZ };
    f32 *dist;

    vec3f_get_dist(curPosVec, goalVec, &dist);

    if (dist > 50) {
        halo_run_movement();
    }
}

void halo_calculate_and_move_back_to_mario(void) {
    o->oHomeX = gMarioState->pos[0];
    o->oHomeY = gMarioState->pos[1] + 170;
    o->oHomeZ = gMarioState->pos[2];

    o->oHaloApproachSpeed = 0.5f;

    Vec3f curPosVec = { o->oPosX, o->oPosY, o->oPosZ };
    Vec3f goalVec = { o->oHomeX, o->oHomeY, o->oHomeZ };
    f32 *dist;

    vec3f_get_dist(curPosVec, goalVec, &dist);

    if (o->oTimer < 5) {
        halo_run_movement();
    } else {
        o->oAction = 0;
    }
}

void halo_apply_knockback(void) {
    cur_obj_move_xz_using_fvel_and_yaw();
    
        o->oForwardVel += 15.0f;

    o->oHaloKnockbackSpeed += 1;

    if (o->oHaloKnockbackSpeed >= 10) {
        o->oForwardVel = 0;
        o->oHaloKnockbackSpeed = 0;
    }
}

void bhv_halo_init(void) {
    o->oHaloLengthMod = 1.0f;
}

void bhv_halo_loop(void) {

    if (gMarioState->action == ACT_SINK_MUD) {
        cur_obj_hide();
    }
    else {
        cur_obj_unhide();
    }

    if (gMarioState->equippedPatch != PATCH_HALO) {
        gMarioState->haloCaptureType = 0;
        if (o->oHaloCapturedObject) {
            obj_mark_for_deletion(o->oHaloCapturedObject);
        }
        if (gMarioState->patchChildObj == o) {
            gMarioState->patchChildObj = NULL;
        }
        obj_mark_for_deletion(o);
    }

    switch (o->oAction) {
        // idle on marios head
        case 0:

            cur_obj_become_intangible();

            if (gPlayer1Controller->buttonPressed & L_TRIG) {
                o->oMoveAngleYaw = gMarioState->faceAngle[1];
                o->oAction = 1;
                play_sound(SOUND_HALO_OUT, gMarioState->marioObj->header.gfx.cameraToObject);
            }

            break;
        // moving forward where mario was looking
        case 1:
            cur_obj_become_tangible();
            halo_calculate_and_move_towards_goal();
            if (o->oHaloKnockbackSpeed > 0) {
                halo_apply_knockback();
            }
            if (o->oTimer > 10 && !(gPlayer1Controller->buttonDown & L_TRIG)) {
                o->oAction = 2;
                play_sound(SOUND_HALO_IN, gMarioState->marioObj->header.gfx.cameraToObject);
            } else if (gPlayer1Controller->buttonPressed & L_TRIG) {
                o->oAction = 3;
                play_sound(SOUND_HALO_CIRCLE, gMarioState->marioObj->header.gfx.cameraToObject);
            }

            break;
        case 2:
            cur_obj_become_tangible();
            halo_calculate_and_move_back_to_mario();
            break;
        case 3:
            cur_obj_become_tangible();
            halo_perform_circle();
            break;
    }

    obj_set_hitbox(o, &sHaloHitbox);
    for (int i = 0; i < o->numCollidedObjs; i++) {
        struct Object *other = o->collidedObjs[i];

        if (other != gMarioObject) {
            // other->oInteractStatus |= INT_STATUS_TOUCHED_MARIO | INT_STATUS_WAS_ATTACKED |
            // INT_STATUS_INTERACTED | INT_STATUS_TOUCHED_BOB_OMB;
            attack_object(other, 2, 1);
            

            if (obj_has_behavior(other, bhvFlame) && !o->oHaloCapturedObject) {
                o->oHaloCapturedObject =
                    spawn_object_relative(1, 0, 0, 0, o, MODEL_NONE, bhvFireSmokeSpawner);
                gMarioState->haloCaptureType = 1;
            }
            else if (obj_has_behavior(other, bhvGoldBlob) && other->oAction != 2) {
                if (!o->oHaloCapturedObject) {
                    other->oIntangibleTimer = -1;
                    o->oHaloCapturedObject = other;
                    gMarioState->haloCaptureType = 3;
                } else {
                    o->oHaloCapturedObject->oGoldBlobCount += 1;
                    obj_mark_for_deletion(other);
                }
            }
            else {
                o->oForwardVel = -110.0f;
                o->oHaloKnockbackSpeed = 1;
            }
        }
    }

    if (o->oAction != 0) {

        f32 dist;

        struct Object *nearCoin = cur_obj_find_nearest_object_with_behavior(bhvYellowCoin, &dist);
        if (dist < 200) {
            if (o->oHaloCapturedObject) {
                if (obj_has_behavior(o->oHaloCapturedObject, bhvFireSmokeSpawner)) {
                    obj_mark_for_deletion(o->oHaloCapturedObject);
                    o->oHaloCapturedObject = spawn_object_relative(
                        0, 0, 0, 0, o, MODEL_YELLOW_COIN_NO_SHADOW, bhvCoinWithValue);
                    gMarioState->haloCaptureType = 2;
                }
                o->oHaloCapturedObject->oHaloCoinValue += 1;
                if (nearCoin->parentObj)
                    nearCoin->parentObj->oCoinRespawnBits |= (1 << nearCoin->oBehParams2ndByte);
                obj_mark_for_deletion(nearCoin);
            } else {
                o->oHaloCapturedObject =
                    spawn_object_relative(0, 0, 0, 0, o, MODEL_YELLOW_COIN_NO_SHADOW, bhvCoinWithValue);
                gMarioState->haloCaptureType = 2;
                o->oHaloCapturedObject->oHaloCoinValue += 1;
                if (nearCoin->parentObj)
                    nearCoin->parentObj->oCoinRespawnBits |= (1 << nearCoin->oBehParams2ndByte);
                obj_mark_for_deletion(nearCoin);
            }
        }

        struct Object *nearRedCoin = cur_obj_find_nearest_object_with_behavior(bhvRedCoin, &dist);
        if (dist < 200) {
            if (o->oHaloCapturedObject) {
                if (obj_has_behavior(o->oHaloCapturedObject, bhvFireSmokeSpawner)) {
                    obj_mark_for_deletion(o->oHaloCapturedObject);
                    o->oHaloCapturedObject = spawn_object_relative(
                        0, 0, 0, 0, o, MODEL_RED_COIN_NO_SHADOW, bhvCoinWithValue);
                    gMarioState->haloCaptureType = 2;
                }
                o->oHaloCapturedObject->oHaloCoinValue += 2;
                if (nearRedCoin->parentObj)
                    nearRedCoin->parentObj->oHiddenStarTriggerCounter++;
                play_sound(SOUND_MENU_COLLECT_RED_COIN
                               + (((u8) nearRedCoin->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                           gGlobalSoundSource);
                nearRedCoin->activeFlags = ACTIVE_FLAG_DEACTIVATED;

                if (nearRedCoin->parentObj->oHiddenStarTriggerCounter != 8) {
                    spawn_orange_number(nearRedCoin->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
                }

            } else {
                o->oHaloCapturedObject =
                    spawn_object_relative(0, 0, 0, 0, o, MODEL_RED_COIN_NO_SHADOW, bhvCoinWithValue);
                gMarioState->haloCaptureType = 2;
                o->oHaloCapturedObject->oHaloCoinValue += 2;
                if (nearRedCoin->parentObj)
                    nearRedCoin->parentObj->oHiddenStarTriggerCounter++;
                play_sound(SOUND_MENU_COLLECT_RED_COIN
                               + (((u8) nearRedCoin->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                           gGlobalSoundSource);
                nearRedCoin->activeFlags = ACTIVE_FLAG_DEACTIVATED;
                if (nearRedCoin->parentObj->oHiddenStarTriggerCounter != 8) {
                    spawn_orange_number(nearRedCoin->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
                }
            }
        }
    }

    o->oInteractStatus = 0;
}

// Width and height of output texture
#define FB_IMAGE__W 32
#define FB_IMAGE__H 32
// Number of pixels to sample for each individual pixel (samples more of the framebuffer)
#define FB_SAMPLE_SIZE__W 3
#define FB_SAMPLE_SIZE__H 3
// Multiple of columns to skip during sampling (1 for every pixel, 2 for every other pixel, etc)
#define FB_SAMPLE_SKIP 1
// Num pixels to sample per pixel
#define FB_SAMPLE_SIZE__TOTAL (FB_SAMPLE_SIZE__W * FB_SAMPLE_SIZE__H)
// Multiplier (for dividing the strength of each sampled pixel)
#define FB_SAMPLE_SIZE__MUL ((1.0f / FB_SAMPLE_SIZE__TOTAL) * FB_SAMPLE_SKIP)
// Distance from center to edge of sample area
#define FB_SAMPLE_OFFSET__W (FB_SAMPLE_SIZE__W * FB_IMAGE__W / 2)
#define FB_SAMPLE_OFFSET__H (FB_SAMPLE_SIZE__H * FB_IMAGE__H / 2)

void portal_sample_fb(void) {
    s32 pixel;
    f32 r, g, b;
    s32 iy, ix, sy, sx;
    static u32 curFrame = 0;
    static s32 xOffset = 0;
    static s32 yOffset = (SCREEN_HEIGHT / 2) - FB_IMAGE__H;

    u16 *fb = gFramebuffers[sRenderingFramebuffer];
    u16 *image = segmented_to_virtual(portal_portal_2_rgba16);
    if (o->oBehParams2ndByte == 1) {
        image = segmented_to_virtual(portal_portal_rgba16);
    }

    if (gMarioState->marioScreenX < 120) {
        xOffset += 160;
    }

    for (iy = 0; iy < FB_IMAGE__H; iy++) {
        for (ix = 0; ix < FB_IMAGE__W; ix++) {
            r = 0;
            g = 0;
            b = 0;

            for (sy = 0; sy < FB_SAMPLE_SIZE__H; sy += FB_SAMPLE_SKIP) {
                for (sx = 0; sx < FB_SAMPLE_SIZE__W; sx += FB_SAMPLE_SKIP) {
                    pixel = SCREEN_WIDTH * (FB_SAMPLE_SIZE__H * iy + sy + yOffset)
                            + (FB_SAMPLE_SIZE__W * ix + xOffset) + sx;

                    r += ((fb[pixel] >> 0xB) & 0x1F);
                    g += ((fb[pixel] >> 0x6) & 0x1F);
                    b += ((fb[pixel] >> 0x1) & 0x1F);
                }
            }

            image[FB_IMAGE__H * iy + ix] =
                ((((u16) ((r * FB_SAMPLE_SIZE__MUL) + 0.5) << 0xB) & 0xF800))
                | ((((u16) ((g * FB_SAMPLE_SIZE__MUL) + 0.5) << 0x6) & 0x7C0))
                | ((((u16) ((b * FB_SAMPLE_SIZE__MUL) + 0.5) << 0x1) & 0x3E)) | 1;
        }
    }
}

void bhv_portal_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            SET_BPARAM1(o->oPrimColorParams, 178);
            SET_BPARAM2(o->oPrimColorParams, 47);
            SET_BPARAM3(o->oPrimColorParams, 235);
            gMarioState->portal1Info[0] = gCurrLevelNum;
            gMarioState->portal1Info[1] = gCurrAreaIndex;
            gMarioState->portal1Position[0] = o->oPosX;
            gMarioState->portal1Position[1] = o->oPosY;
            gMarioState->portal1Position[2] = o->oPosZ;
            break;
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 245);
            SET_BPARAM2(o->oPrimColorParams, 196);
            SET_BPARAM3(o->oPrimColorParams, 34);
            gMarioState->portal2Info[0] = gCurrLevelNum;
            gMarioState->portal2Info[1] = gCurrAreaIndex;
            gMarioState->portal2Position[0] = o->oPosX;
            gMarioState->portal2Position[1] = o->oPosY;
            gMarioState->portal2Position[2] = o->oPosZ;
            break;
    }

    if (o->oPortalSpawnType == 1) {
        portal_sample_fb();
        play_sound(SOUND_GENERAL_PAINTING_EJECT, gMarioState->marioObj->header.gfx.cameraToObject);
    }

    if (gMarioState->specialWarpTransitionOperation == 3) {
        gMarioState->specialWarpTransitionOperation = 0;
    }
}

void bhv_portal_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer > 0 && o->oTimer < 20) {
            cur_obj_unhide();
            obj_scale_xyz(o, ((f32) o->oTimer) / 20.0f, 1.0f, 1.0f);
        } else if (o->oTimer == 20) {
            obj_scale_xyz(o, 1.0f, 1.0f, 1.0f);
            o->oAction = 1;
        }
    } else if (o->oAction < 3) {
        //if mario gets close, get ready to be able to warp him
        if (o->oDistanceToMario > 300 && o->oDistanceToMario < 400) {
            //check if the other portal exists, if it does go to action 2 to wait for mario to get near
            if ((o->oBehParams2ndByte == 0 && gMarioState->portal2Info[0] != 0)
                || (o->oBehParams2ndByte == 1 && gMarioState->portal1Info[0] != 0)) {
                o->oAction = 2;
            }
        } else if (o->oDistanceToMario >= 400) {
            o->oAction = 1;
        }

        if (gMarioState->action == ACT_SPAWN_SPIN_AIRBORNE
            || gMarioState->action == ACT_SPAWN_HOLDING_OBJECT) {
            o->oAction = 1;
        }
    }

    if (o->oAction == 2 && o->oDistanceToMario < 200 && gMarioState->action != ACT_SPAWN_SPIN_AIRBORNE
        && gMarioState->action != ACT_HOLD_CUTSCENE) {
        o->oAction = 3;
        play_sound(SOUND_PORTAL_IN, gMarioState->marioObj->header.gfx.cameraToObject);
    }
    if (o->oAction == 3) {

        if (gMarioState->action == ACT_FALL_AFTER_STAR_GRAB || gMarioState->action == ACT_STAR_DANCE_EXIT || gMarioState->action == ACT_STAR_DANCE_NO_EXIT || gMarioState->action == ACT_STAR_DANCE_WATER) {
            o->oAction = 1;
            return;
        }

        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 55, 200, 18);
        if (o->oTimer == 18) {

            switch (o->oBehParams2ndByte) {
                case 0:

                    initiate_warp(gMarioState->portal2Info[0], gMarioState->portal2Info[1], 0, 0, 2);
                    o->oAction = 1;
                    if (gMarioState->patchChildSecondaryObj) {
                        gMarioState->patchChildSecondaryObj->oAction = 0;
                    }
                    break;
                case 1:
                    initiate_warp(gMarioState->portal1Info[0], gMarioState->portal1Info[1], 0, 0, 1);
                    o->oAction = 1;
                    if (gMarioState->patchChildPortalObj) {
                        gMarioState->patchChildPortalObj->oAction = 0;
                    }
                    break;
            }
            if (gMarioState->heldObj) {

                obj_mark_for_deletion(gMarioState->heldObj);
                gMarioState->heldObj = NULL;
            }
            gMarioState->specialWarpTransitionOperation = 3;
        }

        f32 x = o->oPosX - gMarioState->pos[0];
        f32 y = o->oPosY - gMarioState->pos[1];
        f32 z = o->oPosZ - gMarioState->pos[2];

        gMarioState->pos[0] += x / (1.0f + 10.0f * (1.0f - (f32) (o->oTimer) / 15.0f));
        gMarioState->pos[1] += y / (1.0f + 10.0f * (1.0f - (f32) (o->oTimer) / 15.0f));
        gMarioState->pos[2] += z / (1.0f + 10.0f * (1.0f - (f32) (o->oTimer) / 15.0f));
        if (gMarioState->heldObj) {
            gMarioState->action = ACT_HOLD_CUTSCENE;
        } else {
            gMarioState->action = ACT_SPAWN_SPIN_AIRBORNE;
        }
    }
}

void bhv_shadow_chomp_head_init(void) {

}

void bhv_shadow_chomp_head_loop(void) {

}

#define SHADOW_TAIL_X_AVERAGE 263
#define SHADOW_TAIL_Z_AVERAGE 0

short headVerts[9] = {0, 2, 6, 9, 10, 12, 22, 24, 26};
short tailVerts[14] = {20, 21, 33, 35, 36, 46, 47, 54, 55, 56, 57, 58, 59, 60};
s16 shadowChompXOffsets[61];
s16 shadowChompZOffsets[61];

void bhv_shadow_chomp_tail_init(void) {
    extern Vtx shadow_chomp_tail_Sphere_001_mesh_layer_5_vtx_0[61];
    Vtx *new = segmented_to_virtual(shadow_chomp_tail_Sphere_001_mesh_layer_5_vtx_0);
    for (int i = 0; i < 14; i++) {
            int curVtx = tailVerts[i];
            shadowChompXOffsets[curVtx] = new[curVtx].v.ob[0] + SHADOW_TAIL_X_AVERAGE;
            shadowChompZOffsets[curVtx] = new[curVtx].v.ob[2] + SHADOW_TAIL_Z_AVERAGE;
        }
}

void bhv_shadow_chomp_tail_loop(void) {
    extern Vtx shadow_chomp_tail_Sphere_001_mesh_layer_5_vtx_0[61];

    o->oFaceAngleYaw += 0x100;

    Vtx *new = segmented_to_virtual(shadow_chomp_tail_Sphere_001_mesh_layer_5_vtx_0);

    Vec3f shadowPos = {gMarioState->pos[0], gMarioState->floorHeight, gMarioState->pos[2]};

    f32 dist;
    vec3f_get_dist(&o->oPosVec, shadowPos, &dist);

    f32 bendFactor = dist / 300.0f;

        new[0].v.ob[0] = 0;
        new[2].v.ob[0] = 0;
        new[6].v.ob[0] = 0;
        new[9].v.ob[0] = 0;
        new[10].v.ob[0] = 0;
        new[12].v.ob[0] = 0;
        new[22].v.ob[0] = 0;
        new[24].v.ob[0] = 0;
        new[26].v.ob[0] = 0;

    f32 marioShadowHeight = gMarioState->floorHeight;

    //tail vtx calculation
    for (int i = 0; i < 14; i++) {
        int curVtx = tailVerts[i];
        new[curVtx].v.ob[1] = -o->oPosY + marioShadowHeight;
        new[curVtx].v.ob[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + gMarioState->pos[0] + shadowChompXOffsets[curVtx]) - sins(o->oFaceAngleYaw)*(-o->oPosZ + gMarioState->pos[2] + shadowChompZOffsets[curVtx]);
        new[curVtx].v.ob[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + gMarioState->pos[2] + shadowChompZOffsets[curVtx]) + sins(o->oFaceAngleYaw)*(-o->oPosX + gMarioState->pos[0] + shadowChompXOffsets[curVtx]);
    }

    //Head group: 0, 2, 6, 9, 10, 12, 22, 24, 26

    //Tail group: 20, 21, 33, 35, 36, 46, 47, 54, 55, 56, 57, 58, 59, 60
}

Gfx *geo_switch_portal_texture(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        switchCase->selectedCase = obj->oBehParams2ndByte;
    }
    return NULL;
}

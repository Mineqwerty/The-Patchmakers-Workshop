struct ObjectHitbox sMadSlammingHandHitbox = {
    /* interactType:      */ INTERACT_PUSH_OUT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 30,
    /* numLootCoins:      */ 5,
    /* radius:            */ 50,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 90,
};

void bhv_mad_slamming_hand_init(void) {
    o->oTimer = 200;
    o->oGravity = -3.0f;
    o->oMarioLandedFirstTime = 0;
    o->oMadSlammingHandShadow = spawn_object_relative(0, 0, 0, 0, o, MODEL_MAD_SLAMMING_HAND_SHADOW, bhvMadSlammingHandShadow);
    o->oMadSlammingHandEyeball = spawn_object_relative(0, 0, 0, 0, o, MODEL_MAD_SLAMMING_HAND_EYEBALL, bhvMadSlammingHandEyeball);
    SET_BPARAM1(o->oPrimColorParams, 255);
    SET_BPARAM2(o->oPrimColorParams, 255);
    SET_BPARAM3(o->oPrimColorParams, 255);
}

void bhv_mad_slamming_hand_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o && o->oMarioLandedFirstTime == 0) {
                o->oMarioLandedFirstTime = 1;
                o->oTimer = 100;
            }
            if (o->oTimer == 300) {
                o->oAction++;
            }
            load_object_collision_model();
        break;
        case 1:
        if (o->oTimer % 4 == 0) {
            cur_obj_shake_screen(SHAKE_POS_MEDIUM);
        }
        o->oPosY += 10*(1 - (o->oTimer % 2) * 2);
        u8 bgValue = 255 - absf(100*sins(o->oTimer*0x222));
        SET_BPARAM2(o->oPrimColorParams, bgValue);
        SET_BPARAM3(o->oPrimColorParams, bgValue);

            if (o->oTimer == 90) {
                if (gMarioState->marioObj->platform == o) {
                    //wait for mario to get blasted off, then jump
                    gMarioState->action = ACT_BACKWARD_AIR_KB;
                    o->oDamageOrCoinValue = 2;
                    take_damage_and_knock_back(gMarioState, o);
                    gMarioState->vel[1] = 20;
                    gMarioState->forwardVel = 40.0f;
                    cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                    gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
                    o->oVelY = 15.0f;
                    o->oAction = 2;
                }
                else {
                    //jump
                    o->oVelY = 90.0f;
                    o->oForwardVel = 28.0f;
                    o->oAction = 3;
                }
            }
            load_object_collision_model();
            o->oMarioLandedFirstTime = 0;
        break; 
        case 2:
            
            if ((gMarioState->pos[1] - o->oPosY < 600)) {
                    o->oVelY = 150.0f;
                    o->oForwardVel = 28.0f;
                o->oAction = 3;
            }
        break;
        case 3:
            SET_BPARAM1(o->oPrimColorParams, 255);
            SET_BPARAM2(o->oPrimColorParams, 255);
            SET_BPARAM3(o->oPrimColorParams, 255);
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800); 
            cur_obj_update_floor_and_walls();
            cur_obj_move_using_fvel_and_gravity();
            f32 fHeight;
            fHeight = find_floor_height(o->oPosX, o->oPosY + 1000, o->oPosZ);
            f32 dist;
            vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
            if (dist < 400 && absf(o->oPosY - gMarioState->pos[1] + 80) < 80) {
                gMarioState->action = ACT_BACKWARD_AIR_KB;
                    o->oDamageOrCoinValue = 2;
                    take_damage_and_knock_back(gMarioState, o);
                    gMarioState->vel[1] = 15;
                    gMarioState->forwardVel = 80.0f;
                    gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
            }

            if ((o->oMoveFlags & (OBJ_MOVE_LANDED | OBJ_MOVE_ON_GROUND)) || (o->oPosY < fHeight)) {
                o->oPosY = fHeight;
                    o->oAction = 0;
                    cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                    o->oPosY = o->oFloorHeight;
            }
        break;
        case 4:
            if (o->oTimer % 4 == 0) {
            cur_obj_shake_screen(SHAKE_POS_MEDIUM);
        }
        o->oPosY += 10*(1 - (o->oTimer % 2) * 2);
            if (o->oTimer >= 20) {
                if (gMarioState->marioObj->platform == o) {
                    //wait for mario to get blasted off, then jump
                    gMarioState->action = ACT_FORWARD_ROLLOUT;
                    gMarioState->vel[1] = 20;
                    gMarioState->forwardVel = 0.0f;
                }
                else {
                    for (int i = 0; i < 20; i++) {
                        spawn_object_relative(0, random_u16()%200-100, i*70, -random_u16()%200, o, MODEL_EXPLOSION, bhvDecorativeExplosion);
                    }
                    obj_mark_for_deletion(o);
                }
            }
            load_object_collision_model();
            o->oMarioLandedFirstTime = 0;
        break;

        case 8:
            cur_obj_update_floor_and_walls();
            o->oForwardVel = 0;
            cur_obj_move_using_fvel_and_gravity();
            
            f32 floorHeight;
            floorHeight = find_floor_height(o->oPosX, o->oPosY + 1000, o->oPosZ);

            if ((o->oMoveFlags & (OBJ_MOVE_LANDED | OBJ_MOVE_ON_GROUND)) || (o->oPosY < floorHeight)) {
                o->oPosY = floorHeight;
                    o->oAction = 9;
                    cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                    o->oPosY = o->oFloorHeight;
            }
        break;
        case 9:
            if (o->oTimer == 90) {
                o->oAction = 1;
            }
            load_object_collision_model();
        break;
    }

    o->oMadSlammingHandEyeball->oPosX = o->oPosX + 300;
    o->oMadSlammingHandEyeball->oPosY = o->oPosY + 1170;
    o->oMadSlammingHandEyeball->oPosZ = o->oPosZ + 100;
}

void bhv_mad_slamming_hand_shadow_init(void) {
    
}

void bhv_mad_slamming_hand_shadow_loop(void) {

    f32 floorHeight;
    floorHeight = find_floor_height(o->oPosX, o->oPosY + 10, o->oPosZ);

    o->oPosY = floorHeight;

    o->oPosX = o->parentObj->oPosX;
    o->oPosZ = o->parentObj->oPosZ;

    o->oOpacity = CLAMP(255 - 0.2f*(f32)(o->parentObj->oPosY - o->oPosY), 1, 255);

    if (o->parentObj->oAction == 4) {
        obj_mark_for_deletion(o);
    }
}

void bhv_mad_slamming_hand_eyeball_init(void) {
   obj_set_hitbox(o, &sMadSlammingHandHitbox);
   f32 dist;
    struct Object *mantle = cur_obj_find_nearest_object_with_behavior(bhvMantleOfMadness, &dist);
    o->parentObj = mantle;

    o->oPotogooApproachXZ = 1.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
}

void bhv_mad_slamming_hand_eyeball_loop(void) {
    if (o->oInteractStatus != 0) {
        o->oInteractStatus = 0;
        o->oPotogooApproachXZ = 1.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
    }

    if (o->oTimer == 30 || o->oTimer == 60) {
        o->oInteractStatus = 0;
        o->oPotogooApproachXZ = 1.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
    }

    elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 1.0f, 0.1f, 0.3f);
                    elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, 1.0f, 0.1f, 0.3f);
                    obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);

    if (o->oHealth <= 0) {
        f32 dist;
        struct Object *hand = cur_obj_find_nearest_object_with_behavior(bhvMadSlammingHand, &dist);
        if (hand) {
            hand->oAction = 4;
        }
        spawn_object_relative(0, 0, 100, 0, o, MODEL_EXPLOSION, bhvDecorativeExplosion);
        obj_mark_for_deletion(o);
    }
}


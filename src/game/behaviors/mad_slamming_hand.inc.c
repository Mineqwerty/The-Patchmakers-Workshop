void bhv_mad_slamming_hand_init(void) {
    o->oTimer = 200;
    o->oGravity = -3.0f;
    o->oMadSlammingHandShadow = spawn_object_relative(0, 0, 0, 0, o, MODEL_MAD_SLAMMING_HAND_SHADOW, bhvMadSlammingHandShadow);
}

void bhv_mad_slamming_hand_loop(void) {
    switch (o->oAction) {
        case 0:
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
            if (o->oTimer == 90) {
                if (gMarioState->marioObj->platform == o) {
                    //wait for mario to get blasted off, then jump
                    gMarioState->action = ACT_BACKWARD_AIR_KB;
                    o->oDamageOrCoinValue = 2;
                    take_damage_and_knock_back(gMarioState, o);
                    gMarioState->vel[1] = 20;
                    gMarioState->forwardVel = 40.0f;
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
        break; 
        case 2:
            //cur_obj_update_floor_and_walls();
            //cur_obj_move_using_fvel_and_gravity();
            if ((gMarioState->pos[1] - o->oPosY < 600)) {
                    o->oVelY = 150.0f;
                    o->oForwardVel = 28.0f;
                o->oAction = 3;
            }
        break;
        case 3:
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800); 
            cur_obj_update_floor_and_walls();
            cur_obj_move_using_fvel_and_gravity();
            f32 fHeight;
            fHeight = find_floor_height(o->oPosX, o->oPosY + 1000, o->oPosZ);
            f32 dist;
            vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
            if (dist < 500 && absf(o->oPosY - gMarioState->pos[1] + 80) < 80) {
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
    }
}

void bhv_mad_slamming_hand_shadow_init(void) {
   
}

void bhv_mad_slamming_hand_shadow_loop(void) {
    o->oPosX = o->parentObj->oPosX;
    o->oPosZ = o->parentObj->oPosZ;

    o->oOpacity = CLAMP(255 - 0.2f*(f32)(o->parentObj->oPosY - o->oPosY), 1, 255);
}


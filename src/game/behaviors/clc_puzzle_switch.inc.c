enum CLCPuzzleEyeActions {
    CLC_EYE_ACT_IDLE,
    CLC_EYE_ACT_TURNING,
};

enum CLCPuzzleWallActions {
    CLC_WALL_ACT_IDLE,
    CLC_WALL_ACT_GOING_DOWN,
    CLC_WALL_ACT_DOWN,
    CLC_WALL_ACT_GOING_UP,
};

enum CLCPuzzleSwitchActions {
    CLC_SWITCH_ACT_IDLE,
    CLC_SWITCH_ACT_PRESSING_DOWN,
};

void bhv_clc_puzzle_switch_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            SET_BPARAM1(o->oPrimColorParams, 137);
            SET_BPARAM2(o->oPrimColorParams, 123);
            SET_BPARAM3(o->oPrimColorParams, 140);
            break;
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 146);
            SET_BPARAM2(o->oPrimColorParams, 179);
            SET_BPARAM3(o->oPrimColorParams, 173);
            break;
        case 2:
            SET_BPARAM1(o->oPrimColorParams, 171);
            SET_BPARAM2(o->oPrimColorParams, 142);
            SET_BPARAM3(o->oPrimColorParams, 55);
            break;
    }

    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvClcPuzzleEye, o->oBehParams2ndByte);
}

void bhv_clc_puzzle_switch_loop(void) {
    switch (o->oAction) {
        case CLC_SWITCH_ACT_IDLE:
            if (gMarioState->marioObj->platform && gMarioState->marioObj->platform == o) {
                o->oAction = CLC_SWITCH_ACT_PRESSING_DOWN;
                o->parentObj->oAction = CLC_EYE_ACT_TURNING;
            }
        break;
        case CLC_SWITCH_ACT_PRESSING_DOWN:
            if (o->oTimer < 4) {
                obj_scale_xyz(o, 1.0f, 1.0f - (0.3f * (f32)o->oTimer), 1.0f);
            }
            if (o->oTimer > 60) {
                obj_scale_xyz(o, 1.0f, 0.1f + (0.3f * (f32)(o->oTimer-60)), 1.0f);
            }
            if (o->oTimer == 63) {
                o->oAction = CLC_SWITCH_ACT_IDLE;
                cur_obj_scale(1.0f);
            }
        break;
    }
}

void bhv_clc_puzzle_eye_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            SET_BPARAM1(o->oPrimColorParams, 137);
            SET_BPARAM2(o->oPrimColorParams, 123);
            SET_BPARAM3(o->oPrimColorParams, 140);
            break;
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 146);
            SET_BPARAM2(o->oPrimColorParams, 179);
            SET_BPARAM3(o->oPrimColorParams, 173);
            break;
        case 2:
            SET_BPARAM1(o->oPrimColorParams, 171);
            SET_BPARAM2(o->oPrimColorParams, 142);
            SET_BPARAM3(o->oPrimColorParams, 55);
            break;
    }
}

void bhv_clc_puzzle_eye_loop(void) {
    switch (o->oAction) {
        case CLC_EYE_ACT_IDLE:;
            struct Surface *surf;
            Vec3f originPos;
            Vec3f hitpos;
            Vec3f raydir;

            raydir[0] = sins(o->oMoveAngleYaw) * 6000.0f;
            raydir[1] = 0.0f;
            raydir[2] = coss(o->oMoveAngleYaw) * 6000.0f;

            vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

            vec3f_set(originPos, o->oPosX - (sins(o->oMoveAngleYaw) * 200.0f), o->oPosY + 300,
                      o->oPosZ - (coss(o->oMoveAngleYaw) * 200.0f));

            find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);
            if (surf != NULL && surf->object 
                && obj_has_behavior(surf->object, bhvClcPuzzleWall) 
                && surf->object->oBehParams2ndByte == o->oBehParams2ndByte) {
                    if (surf->object->oAction == CLC_WALL_ACT_IDLE) {
                        surf->object->oAction = CLC_WALL_ACT_GOING_DOWN;
                    }
            }

        break;
        case CLC_EYE_ACT_TURNING:
            o->oFaceAngleYaw += 0x222;
            o->oMoveAngleYaw += 0x222;
            if (o->oTimer == 29) {
                o->oAction = CLC_EYE_ACT_IDLE;
            }
        break;
        
    }
    
}

void bhv_clc_puzzle_wall_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            SET_BPARAM1(o->oPrimColorParams, 137);
            SET_BPARAM2(o->oPrimColorParams, 123);
            SET_BPARAM3(o->oPrimColorParams, 140);
            break;
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 146);
            SET_BPARAM2(o->oPrimColorParams, 179);
            SET_BPARAM3(o->oPrimColorParams, 173);
            break;
        case 2:
            SET_BPARAM1(o->oPrimColorParams, 171);
            SET_BPARAM2(o->oPrimColorParams, 142);
            SET_BPARAM3(o->oPrimColorParams, 55);
            break;
    }

    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvClcPuzzleEye, o->oBehParams2ndByte);
}

void bhv_clc_puzzle_wall_loop(void) {
    switch (o->oAction) {
        case CLC_WALL_ACT_IDLE:

        break;
        case CLC_WALL_ACT_GOING_DOWN:
            o->oPosY -= 20.0f;
            if (o->oTimer == 45) {
                o->oAction = CLC_WALL_ACT_DOWN;
            }
        break;
        case CLC_WALL_ACT_DOWN:
            if (o->parentObj->oAction == CLC_EYE_ACT_TURNING) {
                o->oAction = CLC_WALL_ACT_GOING_UP;
            }
        break;
        case CLC_WALL_ACT_GOING_UP:
            o->oPosY += 20.0f;
            if (o->oTimer == 45) {
                o->oAction = CLC_WALL_ACT_IDLE;
            }
        break;
    }
}


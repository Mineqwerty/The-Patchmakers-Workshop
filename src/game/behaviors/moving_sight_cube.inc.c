void bhv_moving_sight_cube_init(void) {
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}

void bhv_moving_sight_cube_loop(void) {
    switch (GET_BPARAM3(o->oBehParams)) {
        case 0:
            o->oPosY += o->oBehParams2ndByte * sins(o->oTimer * GET_BPARAM1(o->oBehParams) * 4);
            o->oFaceAngleYaw += 10*GET_BPARAM4(o->oBehParams);
        break;
        case 1:
            o->oForwardVel = o->oBehParams2ndByte * sins(o->oTimer * GET_BPARAM1(o->oBehParams) * 4);
            o->oFaceAngleYaw += 10*GET_BPARAM4(o->oBehParams);
            cur_obj_move_xz_using_fvel_and_yaw();
        break;
    }
}


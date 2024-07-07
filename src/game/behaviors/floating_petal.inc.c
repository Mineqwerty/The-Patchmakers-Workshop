void bhv_floating_petal_init(void) {
    o->oMoveAngleYaw = random_u16();
    o->oForwardVel = random_u16() % 10 + 5;
    o->oVelY = random_u16() % 2;

    if (o->oBehParams2ndByte == 1) {
        o->oVelY += 15;
        o->oForwardVel -= 7;
    }
    o->header.gfx.animInfo.animFrame = random_u16() % 30;
    o->oOpacity = 200;

    switch (random_u16() % 6) {
        case 0:
            SET_BPARAM1(o->oPrimColorParams, 200);
            SET_BPARAM2(o->oPrimColorParams, 200);
            SET_BPARAM3(o->oPrimColorParams, 200);
        break;
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 109);
            SET_BPARAM2(o->oPrimColorParams, 49);
            SET_BPARAM3(o->oPrimColorParams, 135);
        break;
        case 2:
            SET_BPARAM1(o->oPrimColorParams, 163);
            SET_BPARAM2(o->oPrimColorParams, 24);
            SET_BPARAM3(o->oPrimColorParams, 122);
        break;
        case 3:
            SET_BPARAM1(o->oPrimColorParams, 123);
            SET_BPARAM2(o->oPrimColorParams, 179);
            SET_BPARAM3(o->oPrimColorParams, 175);
        break;
        case 4:
            SET_BPARAM1(o->oPrimColorParams, 219);
            SET_BPARAM2(o->oPrimColorParams, 210);
            SET_BPARAM3(o->oPrimColorParams, 110);
        break;
        case 5:
            SET_BPARAM1(o->oPrimColorParams, 176);
            SET_BPARAM2(o->oPrimColorParams, 57);
            SET_BPARAM3(o->oPrimColorParams, 39);
        break;
    }
}

void bhv_floating_petal_loop(void) {
    cur_obj_move_xz_using_fvel_and_yaw();
    o->oPosY += o->oVelY;

    o->oOpacity -= 10;
    cur_obj_scale((21.0f - (f32)o->oTimer) / 21.0f);
    if (o->oTimer == 20) {
        obj_mark_for_deletion(o);
    }
}


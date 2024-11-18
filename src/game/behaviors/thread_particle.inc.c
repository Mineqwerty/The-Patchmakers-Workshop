void bhv_thread_particle_init(void) {

    switch(o->oBehParams2ndByte) {
        case 1:
            SET_BPARAM1(o->oPrimColorParams, 0xD3 - (random_u16()%50) + 25);
            SET_BPARAM2(o->oPrimColorParams, 0x78 - (random_u16()%50) + 25);
            SET_BPARAM3(o->oPrimColorParams, 0x3F - (random_u16()%50) + 25);
        break;
        case 2:
            SET_BPARAM1(o->oPrimColorParams, 0x28 - (random_u16()%50) + 25);
            SET_BPARAM2(o->oPrimColorParams, 0xC4 - (random_u16()%50) + 25);
            SET_BPARAM3(o->oPrimColorParams, 0x17 - (random_u16()%30) + 15);
        break;
        case 3:
            SET_BPARAM1(o->oPrimColorParams, 0xED - (random_u16()%50) + 15);
            SET_BPARAM2(o->oPrimColorParams, 0x82 - (random_u16()%50) + 15);
            SET_BPARAM3(o->oPrimColorParams, 0xE6 - (random_u16()%50) + 15);
        break;
    }


    o->oF4 = random_u16()%256;
    o->oFaceAngleRoll = random_u16();
    cur_obj_scale(2.0f + random_f32_around_zero(0.4f));
    o->oMoveAngleYaw = random_u16();
    o->oForwardVel = 4.0f + random_u16() % 20;
    o->oVelY = 10.0f + random_u16()%10;
}

void bhv_thread_particle_loop(void) {
    o->oFaceAngleYaw = gCamera->yaw;

    o->oFaceAngleRoll += 0x222 + o->oF4;

    o->oVelY -= 2.0f;
    o->oPosY += o->oVelY;

    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oTimer == 40) {
        obj_mark_for_deletion(o);
    }
}


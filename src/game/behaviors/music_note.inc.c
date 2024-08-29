void bhv_music_note_init(void) {

    SET_BPARAM1(o->oPrimColorParams, random_u16()%256);
    SET_BPARAM2(o->oPrimColorParams, random_u16()%256);
    SET_BPARAM3(o->oPrimColorParams, random_u16()%256);
    o->oOpacity = 255;
    o->oMoveAngleYaw = random_u16();
    o->oForwardVel = random_u16() % 10;
    o->oVelY = random_u16()%8 + 3;
}

void bhv_music_note_loop(void) {
    if (o->oTimer > 30) {
        o->oOpacity -= 4;
        if (o->oOpacity <= 5) {
            obj_mark_for_deletion(o);
        }
    }

    cur_obj_move_xz_using_fvel_and_yaw();
    o->oPosY += o->oVelY;
}


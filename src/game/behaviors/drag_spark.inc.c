void bhv_drag_spark_init(void) {
    SET_BPARAM1(o->oPrimColorParams, 255);
    SET_BPARAM2(o->oPrimColorParams, 255 - random_u16()%50);
    SET_BPARAM3(o->oPrimColorParams, 125 - random_u16()%50);

    o->oMoveAngleYaw = random_u16();
    o->oForwardVel = random_u16()%10 + 7;
    o->oVelY = random_u16()%5 + 3;
}

void bhv_drag_spark_loop(void) {
    o->oVelY -= 2.0f;
    o->oPosY += o->oVelY;
    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oTimer >= 30) {
        obj_mark_for_deletion(o);
    }
}


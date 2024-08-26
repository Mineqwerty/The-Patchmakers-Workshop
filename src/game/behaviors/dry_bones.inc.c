void bhv_dry_bones_init(void) {
    o->oGravity = 1.0f;
}

void bhv_dry_bones_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1500.0f) {
                o->oAction = 1;
                cur_obj_init_animation(1);
            }
        break;
        case 1:
            if (o->oDistanceToMario > 1800.0f) {
                o->oAction = 0;
                cur_obj_init_animation(0);
            }

            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            o->oForwardVel = 10.0f;
            object_step();
        break;
    }
}


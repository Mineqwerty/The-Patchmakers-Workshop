void bhv_shadow_transition_sphere_init(void) {
    o->oFloatF4 = -2.0f;
}

void bhv_shadow_transition_sphere_loop(void) {

    if (o->oFloatF4 < 0.02f && o->oFloatF4 > -0.02f) {
        o->oFloatF4 = 0.02f;
    }

    

    if (o->oTimer < 15) {
        o->oOpacity = o->oTimer * 16;
        o->oFloatF4 = 2.0f * -coss(o->oTimer * 0x666);
    }
    else if (o->oTimer < 35) {
        o->oOpacity = 255;
        o->oFloatF4 = 2.0f * -coss(o->oTimer * 0x666);
    }
    else {
        o->oOpacity -= 16;
        o->oFloatF4 -= 0.2f;
    }

    if (o->oTimer == 60) {
        obj_mark_for_deletion(o);
    }

    cur_obj_scale(o->oFloatF4);
}


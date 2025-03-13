void bhv_pm_portal_init(void) {
   
}

void bhv_pm_portal_loop(void) {
    if (o->oTimer < 5) {
        obj_scale_xyz(o, CLAMP(((f32)o->oTimer / 5), 0.02f, 1.0f), 1.0f, CLAMP(((f32)o->oTimer / 5), 0.02f, 1.0f));
    }
    else {
        cur_obj_scale(1.0f);
    }

    if (o->oTimer > 55) {
        o->header.gfx.scale[0] -= 0.2f;
        o->header.gfx.scale[2] -= 0.2f;
    }
    if (o->oTimer == 60) {
        obj_mark_for_deletion(o);
    }
}


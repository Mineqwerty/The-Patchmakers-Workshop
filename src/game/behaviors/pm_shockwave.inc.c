void bhv_pm_shockwave_init(void) {
   
}

void bhv_pm_shockwave_loop(void) {
    o->oOpacity = 255 - 10*o->oTimer;
    cur_obj_scale(o->oTimer);
    if (o->oTimer ==  250)  {
        obj_mark_for_deletion(o);
    }
}


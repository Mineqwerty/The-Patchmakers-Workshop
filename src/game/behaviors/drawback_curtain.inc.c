void bhv_drawback_curtain_init(void) {
   
}

void bhv_drawback_curtain_loop(void) {
    if (o->oAction == 0) {
        f32 dist;
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvPatchChallengeMenu, &dist);
        if (o->parentObj) {
            if (o->parentObj->oAction == 3) {
                o->oTimer = 0;
                o->oAction = 1;
            }
        }
    }
    else {
        obj_scale_xyz(o, 1.0f - ((f32)o->oTimer)*0.014f, 1.0f, 1.0f);
    }
}


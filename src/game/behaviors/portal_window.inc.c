void bhv_portal_window_init(void) {
   
}

void bhv_portal_window_loop(void) {
    Vec3f portalPos;
        vec3f_set(portalPos, 0, 1065, 12889);
    
        f32 scale, scaleY;
        f32 dist = 1000;
        vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);

        

        if (dist < 600) {
            scale = 1.0f + 9.0f*(1 - (dist / 600.0f));
            scaleY = 1.0f + 9.0f*(1 - (dist / 600.0f));
            if (scaleY > 1.75f) {
                scaleY = 1.75f;
            }
        }
    else {
       scale = 1.0f; 
       scaleY = 1.0f;
    }

    obj_scale_xyz(o, scale, scaleY, 1.0f);

    if (gMarioState->pos[2] < o->oPosZ - 400.0f) {
        o->oAction = 0;
    }
    else if (gMarioState->pos[2] > o->oPosZ + 100.0f) {
        o->oAction = 1;
    }

    if (o->oAction == 1) {
        load_object_collision_model();
    }

}


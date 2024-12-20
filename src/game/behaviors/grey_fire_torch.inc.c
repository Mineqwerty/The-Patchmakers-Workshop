void bhv_grey_fire_torch_init(void) {
   
}

void bhv_grey_fire_torch_loop(void) {
    if (o->oAction == 0) {
    f32 dist;
    struct Object *haloFire = cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);

    if (haloFire && haloFire->oHaloCapturedObject && obj_has_behavior(haloFire->oHaloCapturedObject, bhvFireSmokeSpawner) && dist < 200) {
        o->oAction = 1;
        spawn_object_relative(0, 0, 0, 0, o, MODEL_GREY_FLAME, bhvFlame);
    }
    }
    else if (o->oAction == 1) {
        if (o->oTimer == 30) {
            spawn_default_star(o->oPosX, o->oPosY, o->oPosZ + 200);
            o->oAction = 2;
        }
    }
}


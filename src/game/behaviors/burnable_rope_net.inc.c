void bhv_burnable_rope_net_init(void) {
   
}

void bhv_burnable_rope_net_loop(void) {
    switch (o->oAction) {
        case 0:;
            f32 dist;
            struct Object *flame = cur_obj_find_nearest_object_with_behavior(bhvFlameMovingForwardGrowing, &dist);

            if (flame && dist < 300) {
                o->oAction = 1;
            }
        break;
        case 1:;
            if (o->oTimer % 4 == 0) {
                spawn_object_relative(0, 0, random_u16()%400 - 200, random_u16()%600 - 300, o, MODEL_RED_FLAME, bhvFlameLargeBurningOut);
            }

            if (o->oTimer == 45) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}


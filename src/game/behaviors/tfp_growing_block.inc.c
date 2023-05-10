void bhv_tfp_growing_block_init(void) {
   
}

void bhv_tfp_growing_block_loop(void) {
    if (o->oAction == 0) {
    f32 dist;
   struct Object *boxSwitch = cur_obj_find_nearest_object_with_behavior(bhvBoxSwitch, &dist); 

   if (boxSwitch && boxSwitch->oAction == 1) {
    o->oAction++;
   }
    }
    else if (o->oAction == 1) {
        cur_obj_scale_over_time(SCALE_AXIS_Y, 15, 1.0f, 4.3f);
        if (o->oTimer == 15) {
            o->oAction++;
        }
    }
}


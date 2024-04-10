void bhv_mistress_init(void) {
   
}

void bhv_mistress_loop(void) {
    if (o->oDistanceToMario < 500) {
        cur_obj_init_animation(1);
    }
    else {
        cur_obj_init_animation(0);
    }
}


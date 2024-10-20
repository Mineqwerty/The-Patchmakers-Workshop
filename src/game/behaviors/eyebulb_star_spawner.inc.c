void bhv_eyebulb_star_spawner_init(void) {

}

void bhv_eyebulb_star_spawner_loop(void) {
    if (o->oAction == 0) {
        struct Object *specialBulb = cur_obj_find_object_with_bparam_2nd_byte(bhvEyebulb, 1);
        if (o->oTimer > 10 && !specialBulb) {
            o->oAction = 1;
            spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
        }
    }
    else {

    }
}


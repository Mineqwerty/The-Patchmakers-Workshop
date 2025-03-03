void bhv_lily_star_manager_init(void) {
   
}

void bhv_lily_star_manager_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer > 10) {
            struct Object *lily = cur_obj_find_object_with_bparam_2nd_byte(bhvLilyPad, 1);

            if (!lily) {
                o->oAction = 1;
                SET_BPARAM1(o->oBehParams, 24);
                spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
                
            }
        }
    }
    }


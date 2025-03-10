void bhv_red_flower_init(void) {
    if (gMarioState->hvhRedsFlags & (1 << o->oBehParams2ndByte)) {
        obj_mark_for_deletion(o);
    }
}

void bhv_red_flower_loop(void) {
    if (o->oAction == 1) {
        if (gMarioState->hvhRedsFlags & (1 << o->oBehParams2ndByte)) {
            obj_mark_for_deletion(o);
        }
        cur_obj_hide();
        cur_obj_become_intangible();
    }
    else {
        load_object_collision_model();
    }
}


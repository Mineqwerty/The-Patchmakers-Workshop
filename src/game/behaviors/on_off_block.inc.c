void bhv_on_off_block_init(void) {
    o->oOnOffBlockType = cur_obj_has_model(MODEL_ON_BLOCK);
}

void bhv_on_off_block_loop(void) {
        if (o->oOnOffBlockType == gMarioState->onOffState) {
            cur_obj_set_model(MODEL_OFF_BLOCK + 2 * (o->oOnOffBlockType));
            load_object_collision_model();
        } else {
            cur_obj_set_model(MODEL_TRANSPARENT_OFF_BLOCK + 2 * (o->oOnOffBlockType));
        }
    
    
}

void bhv_on_off_controller_init(void) {
    
}

void bhv_on_off_controller_loop(void) {
    //dbp(o->oOnOffState);
}

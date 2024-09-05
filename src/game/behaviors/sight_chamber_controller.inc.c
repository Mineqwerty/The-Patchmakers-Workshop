void bhv_sight_chamber_controller_init(void) {
   
}

void bhv_sight_chamber_controller_loop(void) {
    if (o->oAction == 0 && o->oTimer > 10) {
        if (!cur_obj_find_object_with_bparam_2nd_byte(bhvSightSwitch, 0)) {
            spawn_object_relative(0, 0, 0, 0, o, MODEL_SIGHT_CRACKED_PLATFORM, bhvSightCrackedPlatform);
            o->oAction = 1;
        }
    }
}


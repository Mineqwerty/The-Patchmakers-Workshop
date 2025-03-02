void bhv_sub_sea_water_ring_manager_init(void) {
   
}

void bhv_sub_sea_water_ring_manager_loop(void) {
    if (o->oAction == 1) {
        if (o->oF4 < 10) {
            o->oSSNextWaterRing = cur_obj_find_object_with_bparam_2nd_byte(bhvSubSeaWaterRing, o->oF4);
            o->oAction = 2;
        }
        else {
            o->oAction = 3;
        }
    }
    else if (o->oAction == 2) {
        for (int i = 0; i < 2; i++) {
            spawn_object_relative(0, random_u16()%40 - 20, random_u16()%40 - 20, random_u16()%40 - 20, o, MODEL_WHITE_PARTICLE, bhvBubbleMaybe);
            spawn_object_relative(0, random_u16()%40 - 20, random_u16()%40 - 20, random_u16()%40 - 20, o, MODEL_BUBBLE, bhvBubbleMaybe);
        }
        o->oPosX = approach_f32_symmetric(o->oPosX, o->oSSNextWaterRing->oPosX, 60);
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oSSNextWaterRing->oPosY, 60);
        o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oSSNextWaterRing->oPosZ, 60);

        if (o->oTimer == 60) {
            o->oAction = 0;
        }
    }
    else if (o->oAction == 3) {
        SET_BPARAM1(o->oBehParams, 3);
        spawn_water_ring_challenge_star(13964.0f, -3200.0f, -765.0f);
        spawn_mist_particles();
        o->oAction = 4;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}


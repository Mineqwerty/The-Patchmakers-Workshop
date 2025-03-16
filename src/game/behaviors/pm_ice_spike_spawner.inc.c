void bhv_pm_ice_spike_spawner_init(void) {
   
}

void bhv_pm_ice_spike_spawner_loop(void) {
    obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x300);
    o->oForwardVel = 40.0f + (o->oTimer / 10.0f);
    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oTimer % 8 == 0) {
        spawn_object_relative(0, 0, -300, 0, o, MODEL_PM_ICE_SPIKE, bhvPmIceSpike);
        cur_obj_play_sound_2(SOUND_CHILLSTEP_PATCH_FREEZE);
    }

    if (o->oTimer >= 150) {
        obj_mark_for_deletion(o);
    }
}


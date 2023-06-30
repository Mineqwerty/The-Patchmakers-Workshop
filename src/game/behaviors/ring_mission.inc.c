void bhv_ring_mission_init(void) {
   o->parentObj = cur_obj_find_object_with_bparam_1st_byte(bhvFloorSwitchHardcodedModel, 1);
}

void bhv_ring_mission_loop(void) {
    if (o->oAction == 0) {
        if (o->parentObj->oAction == 5) {
            o->oAction++;
            spawn_object_relative(0, 0, 0, 0, o, MODEL_RING_MISSION_TARGET, bhvRingMissionTarget);
        }
    }
    else if (o->oAction == 1) {

        if (o->oTimer < 360) {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                    } else {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                    }

        o->parentObj->oTimer = 0;
        if (o->oTimer == 500) {
            o->oAction = 0;
            o->parentObj->oAction = 4;
            o->oRingMissionCount = 0;
        }
    }
}


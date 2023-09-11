void bhv_ring_mission_ring_init(void) {
    f32 dist;
   o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvRingMission, &dist);
}

void bhv_ring_mission_ring_loop(void) {
   if (o->parentObj->oRingMissionCount == o->oBehParams2ndByte && o->parentObj->oAction == 1) {
    cur_obj_unhide();
    o->oFaceAngleYaw += 0x800;
    if (o->oDistanceToMario < 200) {
        o->parentObj->oRingMissionCount++;
        
        o->parentObj->oTimer = 0;
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
        for (u8 i = 0; i < 4; i++) {
            for (u8 j = 0; j < 3; j++) {
                spawn_object_relative(0, 70 * sins((i * 0x4000) + (j * 0x800)), (j - 1) * 100, 70 * coss((i * 0x4000) + (j * 0x800)), o, MODEL_RING_FRAGMENT, bhvRingFragmentParticle);
            }
        }

        if (o->parentObj->oRingMissionCount == 9) {
            o->parentObj->oAction = 2;
            return;
        }

        spawn_object_relative(o->parentObj->oRingMissionCount, 0, 0, 0, o, MODEL_RING_MISSION_TARGET, bhvRingMissionTarget);
        
    }
   }
   else {
    cur_obj_hide();
   }
}


void bhv_ring_mission_target_init(void) {
   o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvRingMissionRing, o->oBehParams2ndByte);
   o->oHomeX = o->parentObj->oPosX;
   o->oHomeY = o->parentObj->oPosY;
   o->oHomeZ = o->parentObj->oPosZ;
}

void bhv_ring_mission_target_loop(void) {

    if (o->oAction == 0) {
        cur_obj_scale(((f32) o->oTimer) / 15.0f);
        if (o->oTimer == 15) {
            o->oAction = 1;
            cur_obj_scale(1.0f);
        }
    }
    else if (o->oAction == 1) {
        if (o->oTimer < 90) {
            target_approach_curved();
        }
        else {
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;

            if (o->oDistanceToMario < 800) {
                o->oAction = 2;
            }
        }
    }
    else {
        cur_obj_scale(1.0f - (((f32) o->oTimer) / 15.0f));
        if (o->oTimer == 14) {
            obj_mark_for_deletion(o);
        }
    }

    if (o->parentObj->parentObj->oAction == 0) {
        obj_mark_for_deletion(o);
    }
}

void target_approach_curved(void) {
    f32 x = o->oHomeX - o->oPosX;
    f32 y = o->oHomeY - o->oPosY;
    f32 z = o->oHomeZ - o->oPosZ;

    o->oPosX += x * 3.0f * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    o->oPosY += y * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;
    o->oPosZ += z * (1.0f - coss(((f32) o->oTimer / 90.0f) * 0x8000)) / 2.0f;
}
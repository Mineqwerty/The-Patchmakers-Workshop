void bhv_lift_cloud_init(void) {
    
}

void bhv_lift_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvLiftCloudSwitch, o->oBehParams2ndByte);
            if (o->parentObj && o->parentObj->oAction == 1) {
                o->oAction = 1;
            }
        break;
        case 1:
            if (GET_BPARAM1(o->oBehParams) == 0) {
                o->oPosY += 40.0f;
            }
            else {
                o->oPosX += 40.0f;
            }

            if (o->oTimer == 30) {
                o->oAction = 2;
            }
        break;
    }
}

void bhv_lift_cloud_switch_init(void) {
    o->oFaceAnglePitch = -0x2000;
}

void bhv_lift_cloud_switch_loop(void) {
    if (o->oAction == 0) {
        f32 dist = 9999.0f;
        struct Object *halo = cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);
        if (dist < 350.0f && halo && halo->oAction != 0) {
                play_sound(SOUND_GENERAL2_ROTATING_BLOCK_CLICK, gGlobalSoundSource);
                o->oAction = 1;
            

        }
    }
    else if (o->oFaceAnglePitch < 0x2000) {
        o->oFaceAnglePitch += 0x200;
    }
}


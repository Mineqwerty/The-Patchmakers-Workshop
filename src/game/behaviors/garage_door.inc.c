void bhv_garage_door_init(void) {
    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvStarUnlockPlatform, 1);

    
}

void bhv_garage_door_loop(void) {
    if (!o->parentObj) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oAction == 0 && o->parentObj->oAction == 4 && o->parentObj->oTimer >= 90) {
        o->oAction = 1;
        cur_obj_shake_screen(1);
    }

    if (o->oAction == 1) {
        o->oPosY += 4;

        if (o->oTimer % 15 == 0) {
            cur_obj_shake_screen(1);
        }

        if (o->oTimer % 4 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_MOVE_2);
        }

        if (o->oTimer == 90) {
            o->oAction = 2;
        }
    }
}


void bhv_sight_door_init(void) {

}

void bhv_sight_door_loop(void) {
    if (o->oAction == 0) {

    
        f32 dist;
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSightChamberController, &dist);

        if (o->parentObj && o->parentObj->oAction == 1) {
            o->oAction = 1;
        }
    }
    else {
        o->oPosY -= 10.0f;
        if (o->oTimer % 5 == 2) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
        }
        if (o->oTimer == 90) {
            obj_mark_for_deletion(o);
        }
    }
}

void bhv_touch_door_init(void) {

}

void bhv_touch_door_loop(void) {
    if (o->oAction == 0) {
        o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvShrineShadow, o->oBehParams2ndByte);

        if (!o->parentObj && o->oTimer > 5) {
            o->oAction = 1;
        }
    }
    else {
        o->oPosY -= 10.0f;
        if (o->oTimer % 5 == 2) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
        }
        if (o->oTimer == 90) {
            obj_mark_for_deletion(o);
        }
    }
    
}


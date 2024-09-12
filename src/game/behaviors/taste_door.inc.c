void bhv_taste_door_init(void) {
   
}

void bhv_taste_door_loop(void) {
        if (o->oAction == 0) {
        o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvTasteSwitch, 0);

        if (!o->parentObj && o->oTimer > 5) {
            o->oAction = 1;
        }
    }
    else if (o->oTimer > 30) {
        o->oPosY -= 10.0f;
        if (o->oTimer % 5 == 2) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
        }
        if (o->oTimer == 120) {
            obj_mark_for_deletion(o);
        }
    }
    
}


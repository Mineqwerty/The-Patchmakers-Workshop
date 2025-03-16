void bhv_new_file_select_star_count_number_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oFaceAnglePitch = -0x4000;
    o->oFaceAngleYaw = -0x4000;

    if (o->parentObj) {
        SET_BPARAM1(o->oBehParams, o->parentObj->oBehParams2ndByte);
    }
}

void bhv_new_file_select_star_count_number_loop(void) {
    cur_obj_scale(0.035f);
    if (!save_file_exists(GET_BPARAM1(o->oBehParams) - 1)) {
        obj_mark_for_deletion(o);
    }
}


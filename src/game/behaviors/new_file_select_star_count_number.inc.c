void bhv_new_file_select_star_count_number_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oFaceAnglePitch = -0x4000;
    o->oFaceAngleYaw = -0x4000;
}

void bhv_new_file_select_star_count_number_loop(void) {
    cur_obj_scale(0.035f);
}


void bhv_hvh_book_init(void) {

}

void bhv_hvh_book_loop(void) {
    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_HVH) {
        cur_obj_set_model(MODEL_HVH_BOOK_ACTIVE);
    }
}


void bhv_ts_door_init(void) {

}

void bhv_ts_door_loop(void) {
    u8 dontDelete = 0;

    for (int i = 0; i < 5; i++) {
            if (!(save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_TTM)) & (1 << i))) {
                dontDelete = 1;
            }
        
    }

    if (!dontDelete) {
        obj_mark_for_deletion(o);
    }
}


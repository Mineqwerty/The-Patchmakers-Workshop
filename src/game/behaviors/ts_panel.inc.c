void bhv_ts_panel_init(void) {
   
}

void bhv_ts_panel_loop(void) {
    for (int i = 0; i < 5; i++) {
        if (cur_obj_has_model(MODEL_TS_PANEL_SIGHT+i)) {
            if ((save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_TTM)) & (1 << i))) {
                SET_BPARAM1(o->oPrimColorParams, 0);
                SET_BPARAM2(o->oPrimColorParams, 255);
                SET_BPARAM3(o->oPrimColorParams, 255);
            }
            else {
                SET_BPARAM1(o->oPrimColorParams, 255);
                SET_BPARAM2(o->oPrimColorParams, 255);
                SET_BPARAM3(o->oPrimColorParams, 255);
            }
        } 
    }
}


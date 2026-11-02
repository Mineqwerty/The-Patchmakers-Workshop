#include "src/game/archipelago.h"

void bhv_ts_panel_init(void) {
   
}

void bhv_ts_panel_loop(void) {
    for (int i = 0; i < 5; i++) {
        if (cur_obj_has_model(MODEL_TS_PANEL_SIGHT+i)) {

if (archipelago_option(AP_TS_COMPLETION, AP_TS_LOCKBOX_KEY_AND_TRIALS_STATIC) == AP_TS_LOCKBOX_KEY_STATIC_ONLY) {
       

                if (archipelago_item_unlocked(AP_ITEM_TRIAL_OF_LIFE(i))) {
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
else {
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
}


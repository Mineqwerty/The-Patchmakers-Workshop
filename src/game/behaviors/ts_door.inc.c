#include "src/game/archipelago.h"

void bhv_ts_door_init(void) {

}

void bhv_ts_door_loop(void) {
    u8 dontDelete = 0;

    if (archipelago_option(AP_TS_COMPLETION, AP_TS_LOCKBOX_KEY_AND_TRIALS_STATIC) == AP_TS_LOCKBOX_KEY_STATIC_ONLY) {
        if (!archipelago_has_all_trials_of_life()) {
            dontDelete = 1;
        }
    }
    else {

        for (int i = 0; i < 5; i++) {
                if (!(save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_TTM)) & (1 << i))) {
                    dontDelete = 1;
                }
            
        }
    }

    if (!dontDelete) {
        obj_mark_for_deletion(o);
    }
}


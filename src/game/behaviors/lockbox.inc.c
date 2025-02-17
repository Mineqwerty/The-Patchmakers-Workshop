#include "src/game/save_file.h"

void bhv_lockbox_init(void) {
    if ((save_file_get_flags() & (SAVE_FLAG_BEAT_GAME))) {
        //obj_mark_for_deletion(o);
    }
}

void bhv_lockbox_loop(void) {
    cur_obj_scale(2.0f);
}


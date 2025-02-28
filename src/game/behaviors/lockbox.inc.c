#include "src/game/save_file.h"
#include "src/game/cutscene.h"

void bhv_lockbox_init(void) {
    if ((save_file_get_flags() & (SAVE_FLAG_BEAT_GAME))) {
        #ifndef COMPLETE_SAVE_FILE
        obj_mark_for_deletion(o);
        #endif
    }
}

void bhv_lockbox_loop(void) {
    cur_obj_scale(2.0f);

    if (gCurCutscene == CUTSCENE_EVENT_ENTER_BRINK && cExternalCutsceneTrigger == 1) {
        cur_obj_init_animation(1);
    }

    if (gCurCutscene == CUTSCENE_EVENT_POST_MANTLE) {
        cur_obj_init_animation(1);

        if (o->oTimer == 1) {
            spawn_object_relative(0, 0, 0, 0, o, MODEL_ESCAPING_SOULS, bhvEscapingSouls);
        }
    }
}


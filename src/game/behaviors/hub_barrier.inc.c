#include "src/game/save_file.h"

void bhv_hub_barrier_init(void) {
    if (save_file_get_flags() & (SAVE_FLAG_UNLOCKED_HUB_3_DOOR)) {
        obj_mark_for_deletion(o);
    }
}

void bhv_hub_barrier_loop(void) {

}


#include "src/game/archipelago.h"

// The path to Aurumcael's palace: only there once the Aurumcael Palace Path is unlocked.
void bhv_wing_surface_init(void) {
    if (archipelago_final_act_closed_this_visit()) {
        obj_mark_for_deletion(o);
    }
}

void bhv_wing_surface_loop(void) {
    if (archipelago_final_act_unlocked(AP_ITEM_AURUMCAEL_PALACE_PATH)) {
        cur_obj_unhide();
        load_object_collision_model();
    } else {
        cur_obj_hide();
    }
}


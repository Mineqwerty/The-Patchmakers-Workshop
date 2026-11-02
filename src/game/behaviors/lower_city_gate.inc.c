#include "src/game/archipelago.h"

// The gate to the buried city: blocks the way until Buried City Gate Open is unlocked, then disappears.
void bhv_lower_city_gate_init(void) {

}

void bhv_lower_city_gate_loop(void) {
    if (archipelago_final_act_unlocked(AP_ITEM_BURIED_CITY_GATE_OPEN)) {
        obj_mark_for_deletion(o);
        return;
    }

    load_object_collision_model();
}


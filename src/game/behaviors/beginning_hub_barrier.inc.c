u8 gTutorialComplete = 0;

#include "src/game/archipelago.h"

void bhv_beginning_hub_barrier_init(void) {
    if (gMarioState->numStars > 0 || gTutorialComplete != 0) {
        obj_mark_for_deletion(o);
    }
}

void bhv_beginning_hub_barrier_loop(void) {
    f32 dist;
    struct Object *sewnia = cur_obj_find_nearest_object_with_behavior(bhvSewnia, &dist);
    if (sewnia && sewnia->oSewniaApproachSpecificNode == 12) {
        gTutorialComplete = 1;
        obj_mark_for_deletion(o);
    }

    if (archipelago_option(AP_SKIP_STORY, FALSE)) {
        obj_mark_for_deletion(o);

    }
}


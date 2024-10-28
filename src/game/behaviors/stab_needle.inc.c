#include "src/game/cutscene.h"

void bhv_stab_needle_init(void) {
    cur_obj_hide();
}

void bhv_stab_needle_loop(void) {
    if (o->oAction == 0) {
        if (cExternalCutsceneTrigger == 5) {
            o->oAction = 1;
        }

        if (gCurCutscene != CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO && o->oTimer >= 10) {
            obj_mark_for_deletion(o);
        }
    }
    else {
        cur_obj_unhide();
        if (o->oTimer < 10) {
            o->oPosX -= 20;
        }
        else if (o->oTimer > 30 ) {
            o->oPosX += 20;
        }

        if (o->oTimer == 50) {
            obj_mark_for_deletion(o);
        }
    }
}


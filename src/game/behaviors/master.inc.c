#include "include/dialog_ids.h"
#include "src/game/cutscene.h"


void bhv_master_init(void) {
    create_automatic_dialog_box(DIALOG_MASTER_WELCOME);
}

void bhv_master_loop(void) {
    if (cCutsceneActive && cExternalCutsceneTrigger == 1) {
            SET_BPARAM1(o->oBehParams, 5);
            spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
            cExternalCutsceneTrigger = 0;
        }
}


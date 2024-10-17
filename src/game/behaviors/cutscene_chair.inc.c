#include "include/dialog_ids.h"
#include "src/game/cutscene.h"

void bhv_cutscene_chair_init(void) {
   
}

void bhv_cutscene_chair_loop(void) {
    if (o->oAction == 0) {
        if (gMarioObject->platform == o && gDialogID == DIALOG_NONE) {
            o->oAction = 1;
            begin_cutscene_event(10);
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }
    }
}


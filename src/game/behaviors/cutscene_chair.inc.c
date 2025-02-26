#include "include/dialog_ids.h"
#include "src/game/cutscene.h"

void bhv_cutscene_chair_init(void) {
   
}

void bhv_cutscene_chair_loop(void) {
    
    if (o->oAction == 0 && ((save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_LLL)) & (1 << 5)))) {
        o->oAction = 1;
        SET_BPARAM1(o->oBehParams, 4);
        spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
    }

    if (o->oAction == 0) {
        if (gMarioObject->platform == o && gDialogID == DIALOG_NONE) {
            o->oAction = 1;
            begin_cutscene_event(10);
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }
    }
}


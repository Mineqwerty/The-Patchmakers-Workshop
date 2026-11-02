#include "src/game/archipelago.h"

void bhv_ap_xodorap_warp_init(void) {

}

void bhv_ap_xodorap_warp_loop(void) {
    switch (o->oAction) {
        case 0:
            if (!archipelago_final_act_unlocked(AP_ITEM_XODORAP_ARENA_ENTRANCE)) {
                if (archipelago_final_act_closed_this_visit()) {
                    obj_mark_for_deletion(o);
                } else {
                    cur_obj_hide();
                }
                break;
            }
            cur_obj_unhide();

            if (o->oDistanceToMario < 500.0f && (gMarioState->action == ACT_WALKING || gMarioState->action == ACT_IDLE || gMarioState->action == ACT_WAITING_FOR_DIALOG)) {
                if (o->oDialogTrigger == 0) {
                    create_dialog_box_with_response(DIALOG_130);
                    gMarioState->action = ACT_WAITING_FOR_DIALOG;
                    o->oDialogTrigger = 1;
                }
                
            }
            else {
                o->oDialogTrigger = 0;
            }

            if (o->oDialogTrigger == 1 && gDialogResponse == DIALOG_RESPONSE_YES) {
                o->oAction = 10;
                cur_obj_hide();
                gMarioState->action = ACT_IDLE;
                initiate_warp(LEVEL_SL, 5, 0x0A, 0, 0);
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                gMarioState->action = ACT_IDLE;
            }
        break;
    }
}


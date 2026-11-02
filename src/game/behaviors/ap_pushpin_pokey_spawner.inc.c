#include "src/game/archipelago.h"

void bhv_ap_pushpin_pokey_spawner_init(void) {

}

void bhv_ap_pushpin_pokey_spawner_loop(void) {
    switch (o->oAction) {
        //forcefield spawning
        case 0:
            // Final act content: hidden until it opens, gone if it can't open this visit
            if (!archipelago_final_act_unlocked(AP_ITEM_PUSHPIN_POKEY_SPAWNER)) {
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
                    create_dialog_box_with_response(DIALOG_129);
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
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                gMarioState->action = ACT_IDLE;
            }
        break;
    }
}

/**
 * The Pushpin Pokey arena walls only have collision once the AP spawner has been switched on (action 10),
 * the same trigger that starts the Pokey's intro.
 */
void bhv_pokey_boss_walls_loop(void) {
    f32 dist;
    struct Object *apSpawner = cur_obj_find_nearest_object_with_behavior(bhvApPushpinPokeySpawner, &dist);

    if (apSpawner != NULL && apSpawner->oAction == 10) {
        load_object_collision_model();
    }
}


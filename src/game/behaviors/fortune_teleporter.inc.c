#include "include/dialog_ids.h"

void bhv_fortune_teleporter_init(void) {
    
                    o->oPotogooApproachXZ = 1.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
}

void bhv_fortune_teleporter_loop(void) {
    switch (o->oAction) {
        case 0:
            elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 1.0f, 0.1f, 0.3f);
            elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, 1.0f, 0.1f, 0.3f);
            
            obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);

            if (o->parentObj->oAction == 3) {
                o->oPotogooApproachXZ = 1.1f;
                    o->oPotogooApproachY = 1.0f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
                    o->oAction = 1;
            }
        break;
        case 1:
            cur_obj_init_animation(1);
            if (o->oTimer == 30) {
                initiate_warp(gCurrLevelNum, 1, 0x0A, 0, 0);
            }
        break;
    }
}

void bhv_fortune_teleporter_pedestal_init(void) {
   
}

void bhv_fortune_teleporter_pedestal_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o) {
                create_dialog_box_with_response(DIALOG_RETURN_FROM_SUBAREA);
                gMarioState->action = ACT_WAITING_FOR_DIALOG;
                o->oFortuneTeleporterOrigamiObject =
                    spawn_object_relative(0, 0, 0, 0, o, MODEL_FORTUNE_TELEPORTER, bhvFortuneTeleporter);
                o->oAction = 1;
            }
        break;
        case 1:
            if (gDialogResponse == DIALOG_RESPONSE_YES) {
                o->oAction = 3;
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                o->oAction = 2;
                gMarioState->action = ACT_IDLE;
            }
        break;
        case 2:
            if (gMarioState->marioObj->platform != o) {
                o->oAction = 0;
            }
        break;
    }
}


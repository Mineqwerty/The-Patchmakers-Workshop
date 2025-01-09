#include "include/dialog_ids.h"

void bhv_fortune_teleporter_init(void) {
    
                    o->oPotogooApproachXZ = 1.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;

                    if (o->oBehParams2ndByte == 1) {
                        o->oAction = 3;
                        cur_obj_init_animation(1);
                        o->header.gfx.animInfo.animFrame = 20;
                        o->oFaceAngleRoll = 0x8000;
                    }
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
            else if (o->parentObj->oAction != 1) {
                o->oPotogooApproachXZ = 1.1f;
                    o->oPotogooApproachY = 1.0f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
                    o->oAction = 2;
            }
        break;
        case 1:
            cur_obj_init_animation(1);
            if (o->oTimer == 30) {
                initiate_warp(gCurrLevelNum, 1, 0x0A, WARP_FLAG_FORTUNE_TELEPORTER, 0);
            }
        break;
        case 2:
            elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 0.2f, 0.1f, 0.3f);
            elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, 0.2f, 0.1f, 0.3f);
            
            obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);

            if (o->oTimer >= 30) {
                obj_mark_for_deletion(o);
            }

        break;
        case 3:
        if (o->oTimer <= 10) {
            o->oPosX = gMarioState->pos[0];
            o->oPosY = gMarioState->pos[1] + 200;
            o->oPosZ = gMarioState->pos[2];
        }
            elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 1.0f, 0.1f, 0.3f);
            elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, 1.0f, 0.1f, 0.3f);
            
            obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);
            if (o->oTimer == 30) {
                
                cur_obj_init_animation_with_accel_and_sound(1, -1.0f);
                o->header.gfx.animInfo.animFrame = 20;
            }
            if (o->oTimer == 60) {
                o->oPotogooApproachXZ = 1.1f;
                    o->oPotogooApproachY = 1.0f;
                    o->oPotogooVelXZ = 0.2f;
                    o->oPotogooVelY = 0.1f;
                    cur_obj_init_animation(0);
                o->oAction = 2;
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
                gMarioState->action = ACT_WAITING_FOR_DIALOG;
                o->oFortuneTeleporterOrigamiObject =
                    spawn_object_relative(0, 0, 0, 0, o, MODEL_FORTUNE_TELEPORTER, bhvFortuneTeleporter);
                o->oAction = 1;
            }

            spawn_object_relative(0, random_u16()%200 - 100, random_u16()%50 + 100, random_u16()%200 - 100, o, MODEL_NONE, bhvSparkleSpawn);
        break;
        case 1:
            
            create_dialog_box_with_response(DIALOG_RETURN_FROM_SUBAREA);
            if (gDialogResponse == DIALOG_RESPONSE_YES) {
                o->oAction = 3;
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                o->oAction = 2;
                gMarioState->action = ACT_IDLE;
            }

            gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->oPosX, 0.04f);
            gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->oPosZ, 0.04f);
        break;
        case 2:
            if (gMarioState->marioObj->platform != o) {
                o->oAction = 0;
            }
        break;
    }
}


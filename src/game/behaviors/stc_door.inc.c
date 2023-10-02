#include "levels/castle_inside/header.h"

void bhv_stc_door_init(void) {
    switch(o->oBehParams2ndByte) {
        case 0:
            o->collisionData = segmented_to_virtual(&stc_entrance_door_collision);
        break;
        case 1:
            o->collisionData = segmented_to_virtual(&stc_entrance_door2_collision);
        break;
    }

    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvStarUnlockPlatform, 2);
}

void bhv_stc_door_loop(void) {
   if (!o->parentObj) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oAction == 0 && o->parentObj->oAction == 4 && o->parentObj->oTimer >= 90) {
        o->oAction = 1;
        cur_obj_shake_screen(1);
    }

    if (o->oAction == 1) {
        o->oMoveAngleYaw += (o->oBehParams2ndByte == 0 ? 0x100 : -0x100);
        o->oFaceAngleYaw += (o->oBehParams2ndByte == 0 ? 0x100 : -0x100);

        if (o->oTimer % 8 == 0) {
            cur_obj_shake_screen(4);
        }

        if (o->oTimer % 4 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_MOVE_2);
        }

        if (o->oTimer == 90) {
            o->oAction = 2;
        }
    }

    if (o->oAction == 2) {
        if (gMarioState->action == ACT_WARP_STC) {
            o->oAction = 3;
            o->oTimer = 0;
        }
    }

    if (o->oAction == 3) {
        if (o->oTimer < 45) {

            if (o->oTimer % 4 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_MOVE_2);
            }
            cur_obj_shake_screen(1);

            o->oMoveAngleYaw += (o->oBehParams2ndByte == 0 ? -0x200 : 0x200);
            o->oFaceAngleYaw += (o->oBehParams2ndByte == 0 ? -0x200 : 0x200);

            if (o->oTimer == 45) {
                cur_obj_shake_screen(3);
            }
        }

        if (o->oBehParams2ndByte == 1) {
            gCamera->cutscene = 1;
            gLakituState.goalPos[0] = o->oPosX + 400;
            gLakituState.goalPos[1] = o->oPosY + 100;
            gLakituState.goalPos[2] = o->oPosZ - 300;
        }
    }
}


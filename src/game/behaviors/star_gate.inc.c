#include "src/game/ingame_menu.h"

void bhv_star_gate_loop(void) {

    if ((o->oBehParams2ndByte == 0x10) || (GET_BPARAM1(o->oBehParams) == 0x10)) {
        SET_BPARAM1(o->oPrimColorParams, 255);
        SET_BPARAM2(o->oPrimColorParams, 30);
        SET_BPARAM3(o->oPrimColorParams, 30);
    }
    else {
        SET_BPARAM1(o->oPrimColorParams, 200);
        SET_BPARAM2(o->oPrimColorParams, 160);
        SET_BPARAM3(o->oPrimColorParams, 0);
    }

    if (o->oBehParams2ndByte > 0) {

    if (o->oAction == 0) {

        if (o->oTimer == 0 && gMarioState->specialWarpTransitionOperation == 2) {
            gMarioState->specialWarpTransitionOperation = 0;
        }

        if (o->oDistanceToMario < 400.0f) {
            o->oAction = 1;
            if (gDialogID > -1) {
                gDialogBoxState = 3;
            }
        }
    }

    if (o->oAction == 1) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 196, 149, 18);
        if (o->oTimer == 18) {
            initiate_warp(LEVEL_CCM, 1, o->oBehParams2ndByte, 0, 0);
            gMarioState->specialWarpTransitionOperation = 2;
        }

        gMarioState->boostTimer = 0;

        f32 x = o->oPosX - gMarioState->pos[0];
        f32 y = o->oPosY - gMarioState->pos[1];
        f32 z = o->oPosZ - gMarioState->pos[2];

        gMarioState->pos[0] += x / 10;
        gMarioState->pos[1] += y / 2;
        gMarioState->pos[2] += z / 10;
        drop_and_set_mario_action(gMarioState, ACT_SPAWN_SPIN_AIRBORNE, 0);
    }
    }
}
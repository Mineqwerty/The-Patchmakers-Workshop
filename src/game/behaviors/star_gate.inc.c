void bhv_star_gate_loop(void) {

    if (o->oBehParams2ndByte > 0) {

    if (o->oAction == 0) {

        if (o->oTimer == 0 && gMarioState->specialWarpTransitionOperation == 2) {
            gMarioState->specialWarpTransitionOperation = 0;
        }

        if (o->oDistanceToMario < 400.0f) {
            o->oAction = 1;
        }
    }

    if (o->oAction == 1) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 196, 149, 18);
        if (o->oTimer == 18) {
            initiate_warp(LEVEL_CCM, 1, o->oBehParams2ndByte, 0);
            gMarioState->specialWarpTransitionOperation = 2;
        }

        f32 x = o->oPosX - gMarioState->pos[0];
        f32 y = o->oPosY - gMarioState->pos[1];
        f32 z = o->oPosZ - gMarioState->pos[2];

        gMarioState->pos[0] += x / 10;
        gMarioState->pos[1] += y / 2;
        gMarioState->pos[2] += z / 10;
        gMarioState->action = ACT_SPAWN_SPIN_AIRBORNE;
    }
    }
}
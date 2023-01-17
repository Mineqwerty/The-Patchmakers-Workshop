void bhv_star_gate_loop(void) {

    if (o->oBehParams2ndByte > 0) {

    if (o->oAction == 0) {
        if (o->oDistanceToMario < 100.0f) {
            o->oAction = 1;
        }
    }

    if (o->oAction == 1) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 196, 149, 18);
        if (o->oTimer == 19) {
            initiate_warp(LEVEL_CCM, 1, o->oBehParams2ndByte, 0);
        }
    }
    }
}
void bhv_taste_switch_init(void) {
   
}

void bhv_taste_switch_loop(void) {
    switch(o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o) {
                o->oAction = 1;
                o->oBehParams = 0x01010101;
                o->oBehParams2ndByte = 1;
                cur_obj_set_model(MODEL_TASTE_SWITCH_ACTIVE);
            }
        break;
        case 1:
            if (gMarioState->marioObj->platform == o) {
                o->oAction = 2;
            }
        break;
        case 2:
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 20, 155, 227, 208);
        if (o->oTimer == 19) {
            gMarioState->pos[0] = -3872;
            gMarioState->pos[1] = -2008;
            gMarioState->pos[2] = 7546;
            warp_camera(-4000, -1990, 7500);
            o->oAction = 3;
        }
        break;
        case 3:
            o->oAction = 1;
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 20, 155, 227, 208);
        break;
    }
}


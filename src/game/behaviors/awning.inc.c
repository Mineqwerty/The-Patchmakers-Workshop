void bhv_awning_init(void) {
   
}

void bhv_awning_loop(void) {
    if (gMarioState->marioObj->platform == o) {
        gMarioState->vel[1] = 70.0f;
        gMarioState->action = ACT_TRIPLE_JUMP;
        cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
        o->oAction = 1;
        o->oTimer = 0;
    }

    if (o->oAction == 1) {
        obj_scale_xyz(o, 1.0f, 1.0f - (0.3f * sins(0x888 * o->oTimer)), 1.0f);

        if (o->oTimer == 30) {
            o->oAction = 0;
            obj_scale_xyz(o, 1.0f, 1.0f, 1.0f);
        }
    }
}


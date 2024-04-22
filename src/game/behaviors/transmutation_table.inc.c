void bhv_transmutation_table_init(void) {
    o->oTimer = 30;
}

void bhv_transmutation_table_loop(void) {
    if (gMarioState->marioObj->platform == o) {
        gMarioState->vel[1] = 110.0f;
        gMarioState->action = ACT_TRIPLE_JUMP;
        cur_obj_play_sound_1(SOUND_ACTION_BOUNCE_OFF_OBJECT);
        o->oTimer = 0;
    }

    if (o->oTimer < 30) {
        obj_scale_xyz(o, 1.0f, 1.0f - 0.5f * sins(o->oTimer * 0x444), 1.0f);
    }
}

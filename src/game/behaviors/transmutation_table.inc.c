void bhv_transmutation_table_init(void) {
    o->oTimer = 30;
}

void bhv_transmutation_table_loop(void) {
    if (gMarioState->marioObj->platform == o) {
        if (obj_has_model(o, MODEL_GRAY_MUSHROOM)) {
            if (gMarioState->curPatch == PATCH_BREEZE) {
                o->oAction = 1;
            }
        }
        else {
            gMarioState->vel[1] = 110.0f;
            gMarioState->action = ACT_TRIPLE_JUMP;
            cur_obj_play_sound_1(SOUND_ACTION_BOUNCE_OFF_OBJECT);
            o->oTimer = 0;
        }
    }

    if (o->oTimer < 30) {
        obj_scale_xyz(o, 1.0f, 1.0f - 0.5f * sins(o->oTimer * 0x444), 1.0f);
    }

    if (o->oAction == 1) {
        if (o->oTimer == 5) {
            obj_set_model(o, MODEL_PURPLE_MUSHROOM);
            for (u8 i = 0; i < 10; i++) {
                struct Object *flame = spawn_object_relative(0, (random_u16() % 400) - 200, (random_u16() % 200), (random_u16() % 400) - 200, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flame->oBehParams = 0x01000000;
            }
            o->oAction = 0;
        }
    }
}

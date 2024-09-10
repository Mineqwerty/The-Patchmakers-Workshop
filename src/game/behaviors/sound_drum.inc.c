void bhv_sound_drum_init(void) {
    SET_BPARAM1(o->oPrimColorParams, 0xC2);
    SET_BPARAM2(o->oPrimColorParams, 0xCE);
    SET_BPARAM3(o->oPrimColorParams, 0xBD);
}

void bhv_sound_drum_loop(void) {

    SET_BPARAM1(o->oPrimColorParams, GET_BPARAM1(o->oPrimColorParams)-1);
    SET_BPARAM2(o->oPrimColorParams, GET_BPARAM2(o->oPrimColorParams)-1);
    SET_BPARAM3(o->oPrimColorParams, GET_BPARAM3(o->oPrimColorParams)-1);

    if (o->oTimer % 90 == 89) {
        spawn_object_relative(0, 0, 200, 0, o, MODEL_SOUND_WAVE, bhvSoundWave);
        if (gMarioState->marioObj->platform == o) {
            gMarioState->vel[1] = 100;
            gMarioState->action = ACT_FREEFALL;
        }
        SET_BPARAM1(o->oPrimColorParams, 0xC2);
    SET_BPARAM2(o->oPrimColorParams, 0xCE);
    SET_BPARAM3(o->oPrimColorParams, 0xBD);
    }
}

void bhv_sound_wave_init(void) {
    o->oOpacity = 255;
}

void bhv_sound_wave_loop(void) {
    o->oPosY += 100;
    o->oOpacity -= 8;
    cur_obj_scale(1.0f + ((f32)o->oTimer * 0.1f));

    if (o->oTimer == 30) {
        obj_mark_for_deletion(o);
    }
}


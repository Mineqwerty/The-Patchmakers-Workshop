void bhv_faraway_beep_manager_init(void) {
    o->oCraneBeepDelay = 126;
}

void bhv_faraway_beep_manager_loop(void) {
    if (o->oCraneBeepDelay <= 0) {
        Vec3f randomPosition;
        vec3f_set(randomPosition, -17000 + random_u16()%16000, gMarioState->pos[1], CLAMP(random_u16() - 32000, -31000, 31000));
        switch (random_u16()%3) {
            case 0:
            case 1:
                play_sound(SOUND_NEW_CRANE_SHORT, randomPosition);
            break;
            case 2:
                play_sound(SOUND_NEW_CRANE_LONG, randomPosition);

            break;
        }
        o->oCraneBeepDelay = 90 + random_u16()%300;

    }
    else {
        o->oCraneBeepDelay--;
    }
}


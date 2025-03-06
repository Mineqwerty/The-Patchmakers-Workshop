void bhv_faraway_beep_manager_init(void) {
    o->oCraneBeepDelay = 126;
}

void bhv_faraway_beep_manager_loop(void) {
    if (o->oCraneBeepDelay <= 0) {
        Vec3f randomPosition;
        if (!gIsConsole) {
            vec3f_set(randomPosition, (f32)(-17000 + random_u16()%16000), 
                gMarioState->pos[1], 
                (f32)(CLAMP(random_u16() - 32000, -31000.0f, 31000)));
        
        switch (random_u16()%3) {
            case 0:
            FALL_THROUGH
            case 1:
                play_sound(SOUND_NEW_CRANE_SHORT, randomPosition);
            break;
            case 2:
                play_sound(SOUND_NEW_CRANE_LONG, randomPosition);

            break;
        }
    }
        o->oCraneBeepDelay = 90 + random_u16()%300;

    }
    else {
        o->oCraneBeepDelay--;
    }
}


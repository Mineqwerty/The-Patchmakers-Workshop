void bhv_corr_wind_controller_init(void) {
   
}

void bhv_corr_wind_controller_loop(void) {
    if (gMarioState->floor && gMarioState->floor->type == SURFACE_LESS_BLIZZARD) {
        play_sound(SOUND_NEW_INDOOR_WINDS, gGlobalSoundSource);
    }
    else if (gCurrAreaIndex >= 2) {
        play_sound(SOUND_NEW_INDOOR_WINDS, gGlobalSoundSource);
    }
    else {
        play_sound(SOUND_NEW_2_LOUD_WINDS, gGlobalSoundSource);
    }
}


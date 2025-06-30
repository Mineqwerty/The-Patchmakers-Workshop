void bhv_epilogue_warp_init(void) {
    o->oAction = 0;
    o->oF4 = 0;

    if (!(save_file_get_flags() & (SAVE_FLAG_BEAT_GAME)) || gMarioState->numStars < 120) {
        obj_mark_for_deletion(o);
}

}

void bhv_epilogue_warp_loop(void) {
    if (o->oAction == 0) {
        spawn_object_relative(0, random_u16()%200 - 100, random_u16()%50 + 100, random_u16()%200 - 100, o, MODEL_NONE, bhvSparkleSpawn);
        if (o->oF4 == 0 && o->oDistanceToMario < 300 && (save_file_get_flags() & (SAVE_FLAG_BEAT_GAME)) && (gMarioState->action == ACT_WAITING_FOR_DIALOG || gMarioState->action == ACT_READING_NPC_DIALOG || gMarioState->action == ACT_IDLE || gMarioState->action == ACT_WALKING)) {
            
            s16 dialogResponse = cutscene_object_with_dialog(CUTSCENE_RACE_DIALOG, o, DIALOG_NOT_MUCH_LEFT);

            if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_DOWN) == MARIO_DIALOG_STATUS_SPEAK 
                && dialogResponse) {
                    if (dialogResponse != 0) {
                        if (dialogResponse == 1) {
                            o->oAction = 1;
                            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 0, 0, 0);
                        }
                        else {
                            set_mario_npc_dialog(MARIO_DIALOG_STOP);
                        }
                        o->oF4 = 1;
                    }
                }
        }

        if (o->oDistanceToMario > 500) {
            o->oF4 = 0;
        }
    }
    else if (o->oAction == 1) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 90, 0, 0, 0);
        o->oAction = 2;
    }
    else {
        if (o->oTimer == 89) {
            gCutsceneGameState = CUTSCENE_GAME_STATE_START_EPILOGUE;
            initiate_warp(LEVEL_LLL, 1, 0x0A, 0, 0);
        }
    }
}


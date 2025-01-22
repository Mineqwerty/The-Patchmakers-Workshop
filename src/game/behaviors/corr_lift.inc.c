void bhv_corr_lift_init(void) {
    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvStarUnlockPlatform, 6);

    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_CORR) {
        o->oAction = 2;
        o->oPosY += -1200;
    }
}

void bhv_corr_lift_loop(void) {
    if (o->oAction == 0 && o->parentObj && o->parentObj->oAction == 4 && o->parentObj->oTimer >= 90) {
        o->oAction = 1;
        cur_obj_shake_screen(1);
    }

    if (o->oAction == 1) {
        o->oPosY -= 20;

        if (o->oTimer % 15 == 0) {
            cur_obj_shake_screen(4);
        }

        if (o->oTimer % 4 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_MOVE_2);
        }

        if (o->oTimer == 60) {
            o->oAction = 2;
        }
    }

    if (o->oAction == 2) {
        if (gMarioState->marioObj->platform == o) {
            o->oAction = 3;
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gCamera->cutscene = 1;
            o->oTimer = 0;
        }
    }

    if (o->oAction == 3) {
        o->oPosY += 20;
        //gMarioState->pos[1] = o->oPosY + 82;

        if (o->oTimer % 4 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_MOVE_2);
            }

        if (o->oTimer == 40) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255);
        }
        if (o->oTimer == 69) {
            initiate_warp(LEVEL_WDW, 1, 0x0A, 0, 0);
        }
    }
}


void bhv_ts_warp_platform_init(void) {
    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvStarUnlockPlatform, 7);

    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_TS) {
        o->oAction = 1;
        if (o->oDistanceToMario < 1000) {
            o->oAction = 2;
        }
    }
}

void bhv_ts_warp_platform_loop(void) {
    if (o->oAction == 0 && o->parentObj && o->parentObj->oAction == 4 && o->parentObj->oTimer >= 90) {
        o->oAction = 1;
        cur_obj_shake_screen(1);
        cur_obj_hide();
    }
    if (o->oAction == 1) {
        if (o->oDistanceToMario < 1000) {
            cur_obj_play_sound_2(SOUND_SKYBRIDGE_BREAK);
                for (u8 i = 0; i < 4; i++) {
                    for (u8 j = 0; j < 3; j++) {
                        spawn_object_relative(0, 70 * sins((i * 0x4000) + (j * 0x800)), 70 * sins((i * 0x4000) + (j * 0x800)), 70 * coss((i * 0x4000) + (j * 0x800)), o, MODEL_SKYBRIDGE_FRAGMENT, bhvRingFragmentParticle);
                    }
                }
                o->oAction = 2;
        }
        cur_obj_hide();
    }
    if (o->oAction == 2) {
        cur_obj_unhide();
        load_object_collision_model();

        if (gMarioState->marioObj->platform == o) {
            o->oAction = 3;
            o->oTimer = 0;
        }
    }
    if (o->oAction == 3) {
        gCamera->cutscene = 1;
        gLakituState.goalPos[0] = o->oPosX;
        gLakituState.goalPos[1] = o->oPosY + 400;
        gLakituState.goalPos[2] = o->oPosZ - 400;
        gLakituState.goalFocus[0] = o->oPosX;
        gLakituState.goalFocus[1] = o->oPosY + 400;
        gLakituState.goalFocus[2] = o->oPosZ;
        if (o->oTimer == 40) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255);
        }
        if (o->oTimer == 69) {
            initiate_warp(LEVEL_TTM, 1, 0x0A, 0, 0);
        }
    }

    

}


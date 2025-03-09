void bhv_ts_warp_platform_init(void) {
    o->parentObj = cur_obj_find_object_with_bparam_2nd_byte(bhvStarUnlockPlatform, 7);
    o->oAction = 0;
    cur_obj_hide();

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
        gLakituState.goalPos[1] = o->oPosY + 380;
        gLakituState.goalPos[2] = o->oPosZ - 500;
        gLakituState.goalFocus[0] = o->oPosX;
        gLakituState.goalFocus[1] = o->oPosY + 380;
        gLakituState.goalFocus[2] = o->oPosZ;

        gMarioState->action = ACT_STORY_CUTSCENE;
        gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->oPosX, 0.09f);
        gMarioState->pos[1] = approach_f32_asymptotic(gMarioState->pos[1], o->oPosY + 340, 0.09f);
        gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->oPosZ, 0.09f);
        set_mario_animation(gMarioState, MARIO_ANIM_BEING_GRABBED);
        if (o->oTimer == 40) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255);
        }
        if (o->oTimer == 69) {
            initiate_warp(LEVEL_TTM, 1, 0x0A, 0, 0);
        }
    }

    

}


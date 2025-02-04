#include "src/game/save_file.h"
#include "src/game/cutscene.h"

void bhv_lockbox_key_init(void) {

}

void bhv_lockbox_key_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000) {
            cur_obj_play_sound_2(SOUND_SKYBRIDGE_BREAK);
                for (u8 i = 0; i < 4; i++) {
                    for (u8 j = 0; j < 3; j++) {
                        spawn_object_relative(0, 70 * sins((i * 0x4000) + (j * 0x800)), 70 * sins((i * 0x4000) + (j * 0x800)), 70 * coss((i * 0x4000) + (j * 0x800)), o, MODEL_SKYBRIDGE_FRAGMENT, bhvRingFragmentParticle);
                    }
                }
                o->oAction = 1;
        }
        cur_obj_hide();
        break;
        case 1:
            cur_obj_unhide();
            if (o->oDistanceToMario < 100) {
                o->oAction = 2;
                cur_obj_play_sound_2(SOUND_SKYBRIDGE_BREAK);
                for (u8 i = 0; i < 4; i++) {
                    for (u8 j = 0; j < 3; j++) {
                        spawn_object_relative(0, 70 * sins((i * 0x4000) + (j * 0x800)), 70 * sins((i * 0x4000) + (j * 0x800)), 70 * coss((i * 0x4000) + (j * 0x800)), o, MODEL_SKYBRIDGE_FRAGMENT, bhvRingFragmentParticle);
                    }
                }
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 90, 255, 255, 255);
            }
        break;
        case 2:
            cur_obj_hide();
            if (o->oTimer == 89) {
                save_file_set_flags(SAVE_FLAG_HAVE_LOCKBOX_KEY);
                save_file_do_save(gCurrSaveFileNum-1);
                gCutsceneGameState = CUTSCENE_GAME_STATE_COLLECTED_KEY;
                initiate_warp(LEVEL_CASTLE, 3, 0x0A, 0, 0);
            }
        break;
    }
}


#include "src/game/save_file.h"
#include "src/game/cutscene.h"

void bhv_hub_barrier_init(void) {
    if (save_file_get_flags() & (SAVE_FLAG_UNLOCKED_HUB_3_DOOR)) {
        //obj_mark_for_deletion(o);
    }
}

void bhv_hub_barrier_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 30 && (save_file_get_flags() & (SAVE_FLAG_UNLOCKED_HUB_3_DOOR))) {
                o->oAction = 1;
                begin_cutscene_event(CUTSCENE_EVENT_LEAVING_SECOND_HUB);
            }
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                cur_obj_play_sound_2(SOUND_SKYBRIDGE_BREAK);
                for (u8 i = 0; i < 4; i++) {
                    for (u8 j = 0; j < 3; j++) {
                        spawn_object_relative(0, 70 * sins((i * 0x4000) + (j * 0x800)), 70 * sins((i * 0x4000) + (j * 0x800)), 70 * coss((i * 0x4000) + (j * 0x800)), o, MODEL_SKYBRIDGE_FRAGMENT, bhvRingFragmentParticle);
                    }
                }
                cur_obj_shake_screen(SHAKE_POS_LARGE);
                obj_mark_for_deletion(o);
            }
        break;
    }
}


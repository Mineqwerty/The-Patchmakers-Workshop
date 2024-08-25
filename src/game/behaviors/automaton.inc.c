#include "src/game/ingame_menu.h"

void bhv_automaton_init(void) {

}

void bhv_automaton_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMenuMode == MENU_MODE_SOUND_MENU) {
                cur_obj_init_animation(1);
                o->oAction = 1;
            }
        break;
        case 1:

            if (o->oTimer < 40) {
                if (o->oTimer % 3 == 0) {
                    cur_obj_play_sound_2(SOUND_NEW_MACHINE_CLICK);
                }
            }
            else if (o->oTimer == 40) {
                cur_obj_play_sound_2(SOUND_NEW_MACHINE_LOCK);
            }

            if (gCurrSoundMenuSong >= 0) {
                cur_obj_init_animation(2 + random_u16()%2);
                o->oAction = 2;
            }
        break;
        case 2:
                if (o->oTimer % 3 == 0) {
                    cur_obj_play_sound_2(SOUND_NEW_MACHINE_CLICK);
                }

                if (cur_obj_check_if_at_animation_end()) {
                    o->oAction++;
                    cur_obj_play_sound_2(SOUND_NEW_MACHINE_LOCK);
                    
                }
        break;
        case 3:
            o->oFaceAngleYaw += 0x200;
        break;
    }
}


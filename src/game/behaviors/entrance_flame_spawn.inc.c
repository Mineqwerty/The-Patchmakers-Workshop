#include "levels/castle_inside/header.h"
#include "src/game/save_file.h"
#include "src/audio/external.h"

void bhv_entrance_flame_spawn_init(void) {
    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_CLC) {
        spawn_object_relative(0, 0, 0, 0, o, MODEL_RED_FLAME, bhvSmallFlame);
        obj_mark_for_deletion(o);
    }
}

void bhv_entrance_flame_spawn_loop(void) {
    if (o->oAction == 0 && save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_CLC) {
        o->oAction = 1;
    }

    if (o->oAction == 1 && o->oTimer == 90) {
        spawn_object_relative(0, 0, 0, 0, o, MODEL_RED_FLAME, bhvSmallFlame);
        play_sound(SOUND_OBJ_FLAME_BLOWN, gGlobalSoundSource);
        obj_mark_for_deletion(o);
    }
}


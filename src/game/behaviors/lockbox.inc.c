#include "src/game/save_file.h"
#include "src/game/cutscene.h"

void bhv_lockbox_init(void) {
    if ((save_file_get_flags() & (SAVE_FLAG_BEAT_GAME))) {
        #ifndef COMPLETE_SAVE_FILE
        obj_mark_for_deletion(o);
        #endif
    }
    o->oF4 = 0;
}

void bhv_lockbox_loop(void) {
    cur_obj_scale(2.0f);

    if (o->oAction == 0) {

    if (gCurCutscene == CUTSCENE_EVENT_ENTER_BRINK && cExternalCutsceneTrigger == 1) {
        cur_obj_init_animation(1);
    }

    else if (gCurCutscene == CUTSCENE_EVENT_POST_MANTLE) {
        cur_obj_init_animation(1);

        if (o->oTimer == 1) {
            spawn_object_relative(0, 0, 0, 0, o, MODEL_ESCAPING_SOULS, bhvEscapingSouls);
        }
    }

    else {
        if (o->oF4 == 0 && o->oDistanceToMario < 300 && (save_file_get_flags() & (SAVE_FLAG_HAVE_LOCKBOX_KEY)) && (gMarioState->action == ACT_WAITING_FOR_DIALOG || gMarioState->action == ACT_READING_NPC_DIALOG || gMarioState->action == ACT_IDLE || gMarioState->action == ACT_WALKING)) {
            
            s16 dialogResponse = cutscene_object_with_dialog(CUTSCENE_RACE_DIALOG, o, DIALOG_OPEN_LOCKBOX);

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
}

else {
    if (o->oTimer >= 29) {
        begin_cutscene_event(CUTSCENE_EVENT_ENTER_BRINK);
        o->oAction = 0;
    }
}
}


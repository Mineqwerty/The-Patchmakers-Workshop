#include "src/game/cutscene.h"
#include "src/game/save_file.h"

void bhv_story_cutscene_manager_init(void) {
   
}

void bhv_story_cutscene_manager_loop(void) {
   
}

u8 playedIntro = 0;

void bhv_story_cutscene_manager_hub1_init(void) {
    switch (gCurrAreaIndex) {
        case 1:
            if (!save_file_exists(gCurrSaveFileNum - 1) && !playedIntro) {
                begin_cutscene_event(CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO);
                playedIntro = 1;
            }
            else if (gCutsceneGameState == CUTSCENE_GAME_STATE_REVIVE_BOWSER) {
                begin_cutscene_event(CUTSCENE_EVENT_REVIVE_BOWSER);
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            }
            else if (gCutsceneGameState == CUTSCENE_GAME_STATE_REVIVE_PEACH) {
                begin_cutscene_event(CUTSCENE_EVENT_REVIVE_PEACH);
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            }
        break;
        case 2:
            if (gCutsceneGameState == CUTSCENE_GAME_STATE_ENTER_SECOND_HUB) {
                begin_cutscene_event(CUTSCENE_EVENT_SECOND_HUB_ARRIVAL);
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            }
        break;
        case 3:
            if (gCutsceneGameState == CUTSCENE_GAME_STATE_ENTER_THIRD_HUB) {
                begin_cutscene_event(CUTSCENE_EVENT_THIRD_HUB_ARRIVAL);
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            }
            else if (gCutsceneGameState == CUTSCENE_GAME_STATE_COLLECTED_KEY) {
                o->oAction = 1;
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            }
            //else if (gCutsceneGameState == CUTSCENE_GAME_STATE_BEAT_MANTLE)  {
                begin_cutscene_event(CUTSCENE_EVENT_POST_MANTLE);
                gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
            //}
        break;
    }
}

void bhv_story_cutscene_manager_hub1_loop(void) {
    if (o->oAction == 1) {
        if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK 
                && cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_RECOVERED_KEY)) {
                set_mario_npc_dialog(MARIO_DIALOG_STOP);
                o->oAction = 0;
                }
    }

    
    if (gCutsceneGameState == CUTSCENE_GAME_STATE_ENTER_BRINK) {
        begin_cutscene_event(CUTSCENE_EVENT_ENTER_BRINK);
        gCutsceneGameState = CUTSCENE_GAME_STATE_DEFAULT;
    }
}


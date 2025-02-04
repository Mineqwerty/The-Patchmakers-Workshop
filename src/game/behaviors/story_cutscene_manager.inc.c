#include "src/game/cutscene.h"
#include "src/game/save_file.h"

void bhv_story_cutscene_manager_init(void) {
   
}

void bhv_story_cutscene_manager_loop(void) {
   
}

void bhv_story_cutscene_manager_hub1_init(void) {
    switch (gCurrAreaIndex) {
        case 1:
            if (!save_file_exists(gCurrSaveFileNum - 1)) {
                begin_cutscene_event(CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO);
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
            //begin_cutscene_event(CUTSCENE_EVENT_SECOND_HUB_ARRIVAL);
        break;
    }
}

void bhv_story_cutscene_manager_hub1_loop(void) {
    if (o->oTimer == 90) {
        
    }
}


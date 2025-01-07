#include "src/game/cutscene.h"

void bhv_story_cutscene_manager_init(void) {
   
}

void bhv_story_cutscene_manager_loop(void) {
   
}

void bhv_story_cutscene_manager_hub1_init(void) {
    switch (gCurrAreaIndex) {
        case 1:
            //begin_cutscene_event(CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO);
            //begin_cutscene_event(CUTSCENE_EVENT_REVIVE_BOWSER);
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


#include "src/game/cutscene.h"

void prince_act_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            //if (o->oDistanceToMario < 1000) {
                begin_cutscene_event(CUTSCENE_EVENT_PRINCE_INTRO);
            //}
            o->oSubAction++;
        break;
        }
}

void bhv_prince_boss_init(void) {
   
}

void bhv_prince_boss_loop(void) {
    switch (o->oAction) {
        case 0:
            prince_act_cutscene();
        break;
    }
}


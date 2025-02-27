#include "src/game/cutscene.h"
#include "src/audio/external.h"

void bhv_memory_cutscene_controller_init(void) {

    if (gInMemoryStage) {
        switch (gCurrLevelNum) {
            case LEVEL_BITS:
                play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STREAMED_THE_BRINK), 0);
            break;
        }
        return;
    }

    switch (gCurrLevelNum) {
        case LEVEL_BITDW:
            begin_cutscene_event(CUTSCENE_EVENT_FIRST_MEMORY);
        break;
        case LEVEL_BITFS:
            begin_cutscene_event(CUTSCENE_EVENT_SECOND_MEMORY);
        break;
        case LEVEL_BITS:
            begin_cutscene_event(CUTSCENE_EVENT_THIRD_MEMORY);
        break;
    }
}

void bhv_memory_cutscene_controller_loop(void) {
   
}


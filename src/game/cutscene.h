#include <PR/ultratypes.h>

#include "types.h"
#include "src/game/camera.h"

enum cutscene_titles {
    CUTSCENE_EVENT_STC_BRIDGE,
    CUTSCENE_EVENT_GODDESS_INTRO,
    CUTSCENE_EVENT_POKEY_INTRO,
    CUTSCENE_EVENT_ROSEDRIFT_CLIFF,
    CUTSCENE_EVENT_STONE_PATCH,
    CUTSCENE_EVENT_GODDESS_DEATH
};

extern u8 cCutsceneActive;
extern int cCutsceneIndex;
extern u32 cWaitTimer;
extern u8 cWaiting;
extern s32 *cEventPointer;

void begin_cutscene_event(s32 event);
void event_handler(void);
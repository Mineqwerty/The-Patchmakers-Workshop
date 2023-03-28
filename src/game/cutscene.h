#include <PR/ultratypes.h>

#include "types.h"
#include "src/game/camera.h"

extern u8 cCutsceneActive;
extern int cCutsceneIndex;
extern u32 cWaitTimer;
extern u8 cWaiting;
extern s32 *cEventPointer;

void begin_cutscene_event(s32 event);
void event_handler(void);
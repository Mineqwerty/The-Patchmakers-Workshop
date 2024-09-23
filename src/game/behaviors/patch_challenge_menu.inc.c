#include "src/game/level_update.h"
#include "src/game/ingame_menu.h"
#include "src/game/camera.h"

void bhv_patch_challenge_menu_init(void) {
   
}

void bhv_patch_challenge_menu_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500 && !((gMarioState->action & ACT_GROUP_MASK) >= ACT_GROUP_AIRBORNE && (gMarioState->action & ACT_GROUP_MASK) < (ACT_HOLD_JUMP & ACT_ID_MASK))) {
                gCamera->cutscene = 1;
                gLakituState.goalPos[0] = o->oPosX;
                gLakituState.goalPos[1] = o->oPosY;
                gLakituState.goalPos[2] = o->oPosZ + 600;

                gLakituState.goalFocus[0] = o->oPosX;
                gLakituState.goalFocus[1] = o->oPosY;
                gLakituState.goalFocus[2] = o->oPosZ;
                o->oAction++;
            }
        break;
        case 1:
            gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gMenuMode = MENU_MODE_PATCH_CHALLENGE_MENU;
            gHudDisplay.flags = HUD_DISPLAY_NONE;
            o->oAction = 2;
        break;
        case 2:
            if (o->oDistanceToMario > 600) {
                o->oAction = 0;
            }
        break;
    }
    
}
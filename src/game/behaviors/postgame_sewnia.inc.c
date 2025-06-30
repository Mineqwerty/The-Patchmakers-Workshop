
#include "include/dialog_ids.h"
#include "src/game/ingame_menu.h"
#include "src/game/cutscene.h"

void bhv_postgame_sewnia_init(void) {
    if (gCutsceneGameState != CUTSCENE_GAME_STATE_START_EPILOGUE) {
        obj_mark_for_deletion(o);
    }
}

void bhv_postgame_sewnia_loop(void) {
    if (gCurrAreaIndex == 1) {
        switch (o->oAction) {
            case 0:
                if (cExternalCutsceneTrigger == 1) {
                    o->oPosX = 10722;
                    o->oPosZ = -12901;
                    o->oFaceAngleYaw = 0x8000;
                    o->oAction++; 
                }
            break;
            case 1:
                if (gPageNum >= 6) {
                    o->oSewniaFaceState = 5;
                }
            break;
        }
    }
    else if (gCurrAreaIndex == 3) {
        switch (o->oAction) {
            case 0:
                o->oSewniaFaceState = 5;
                if (gPageNum >= 3) {
                    o->oSewniaFaceState = 6;
                }
                if (gPageNum >= 5) {
                    o->oSewniaFaceState = 5;
                }
                if (gPageNum >= 6) {
                    o->oSewniaFaceState = 0;
                }

                if (cExternalCutsceneTrigger == 2) {
                    o->oAction = 1;
                    o->oPosX = 794;
                    o->oPosZ = -388;
                    cur_obj_init_animation(7);

                }
            break;
            case 1:
                if (o->oTimer < 60) {
                    o->oPosZ -= 9;
                }
                else {
                    cur_obj_init_animation(0);
                }
                
                if (gPageNum >= 10) {
                    o->oSewniaFaceState = 5;
                }

                if (cExternalCutsceneTrigger == 3) {
                    o->oAction++;
                    o->oPosX = 794;
                    o->oPosZ = -388;
                }
            break;
            case 2:
                if (cExternalCutsceneTrigger == 5) {
                    o->oFaceAngleYaw = 0x8200;
                    o->oAction++;
                    o->oPosX = -760;
                    o->oPosZ = -644;
                }
            break;
            case 3:
                o->oSewniaFaceState = 0;
            break;
        }
    }
}


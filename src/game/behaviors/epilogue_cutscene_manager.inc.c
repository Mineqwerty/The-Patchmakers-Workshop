#include "src/game/cutscene.h"

void bhv_epilogue_cutscene_manager_init(void) {
    if (gCutsceneGameState == CUTSCENE_GAME_STATE_START_EPILOGUE) {
        if (gCurrAreaIndex == 1) {
            begin_cutscene_event(CUTSCENE_EVENT_POSTGAME_OUTSIDE_DOOR);
        }
        else { 
            begin_cutscene_event(CUTSCENE_EVENT_REVIVE_MISTRESS);
        }
    }
    else {
        obj_mark_for_deletion(o);
    }
}

void bhv_epilogue_cutscene_manager_loop(void) {
    if (gCurrAreaIndex == 3) {
        if (cExternalCutsceneTrigger == 3 && o->oAction == 0) {
            o->oAction++;
            //spawn_object_rel_with_rot(o, MODEL_MISTRESS_CURED, bhvMistressCured, 0, 0, 0, 0, 0x8000, 0);
            struct Object *mistress = spawn_object_relative(0, 0, 0, 0, o, MODEL_MISTRESS_CURED, bhvMistressCured);
            mistress->oFaceAngleYaw = 0;
        }
    }
}


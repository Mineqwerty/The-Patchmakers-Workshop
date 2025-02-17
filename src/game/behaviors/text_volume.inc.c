#include "src/game/puppyprint.h"
#include "src/game/patch_tutorial_dialog.h"
#include "src/game/ingame_menu.h"
#include "src/game/save_file.h"
#include "src/game/cutscene.h"
#include "src/game/hud.h"
#include "src/game/level_update.h"

void bhv_text_volume_init(void) {
    if (gCurrLevelNum != LEVEL_CASTLE && save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum)) & (1 << 1)) {
        //obj_mark_for_deletion(o);
    }
}

void bhv_text_volume_loop(void) {

    if (gCurrLevelNum != LEVEL_CASTLE) {
        if (!(save_file_get_patch_flags(gCurrSaveFileNum - 1) & (1 << courseToOrderedIndex[gCurrCourseNum]))
        || gCurCutscene > -1) {
            return;
        }
    }

    if (gMarioState->pos[0] < (o->oPosX + (o->oBehParams2ndByte * 100)) 
        && gMarioState->pos[0] > (o->oPosX - (o->oBehParams2ndByte * 100)) 
        && gMarioState->pos[1] < (o->oPosY + (o->oBehParams2ndByte * 100)) 
        && gMarioState->pos[1] > (o->oPosY - (o->oBehParams2ndByte * 100)) 
        && gMarioState->pos[2] < (o->oPosZ + (o->oBehParams2ndByte * 100)) 
        && gMarioState->pos[2] > (o->oPosZ - (o->oBehParams2ndByte * 100))) {
        
        if (o->oAction == 0) {
            o->oAction = 1;
            o->oTimer = 0;
        }
    }
    else if (o->oAction == 2) {
        o->oAction = 3;
        o->oTimer = 0;
    }


    switch (o->oAction) {
        case 1:
            print_set_envcolour(255, 255, 255, CLAMP(o->oTimer * 17, 20, 255));
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            if (o->oTimer == 15) {
                o->oAction = 2;
            }
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_HIDE_DPAD;
        break;
        case 2:
            print_set_envcolour(255, 255, 255, 255);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_HIDE_DPAD;
        break;
        case 3:
            print_set_envcolour(255, 255, 255, CLAMP(255 - (o->oTimer * 17), 20, 255));
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            if (o->oTimer == 15) {
                o->oAction = 0;
            }
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_HIDE_DPAD;
        break;
    }
}


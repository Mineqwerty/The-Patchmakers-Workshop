#include "src/game/puppyprint.h"
#include "src/game/patch_tutorial_dialog.h"
#include "include/dialog_ids.h"
#include "src/game/ingame_menu.h"

void bhv_readable_book_init(void) {
   
}

void bhv_readable_book_loop(void) {
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
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            if (o->oTimer == 15) {
                o->oAction = 2;
            }
        break;
        case 2:
            print_set_envcolour(255, 255, 255, 255);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            print_small_text_buffered(SCREEN_CENTER_X + 5, SCREEN_CENTER_Y + 40, "- Read", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            u8 grayFade = (o->oTimer % 30 < 15 ? 0: 80);
            print_set_envcolour(255-grayFade, 255-grayFade, 255-grayFade, 255);
            
            print_small_text_buffered(SCREEN_CENTER_X - 14, SCREEN_CENTER_Y + 40, "Z", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);

            if (gPlayer1Controller->buttonPressed & Z_TRIG) {
                gMarioState->action = ACT_IDLE;
                o->oAction = 4;
            }

        break;
        case 3:
            print_set_envcolour(255, 255, 255, CLAMP(255 - (o->oTimer * 17), 20, 255));
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            if (o->oTimer == 15) {
                o->oAction = 0;
            }
        break;
        case 4:;

            u16 dialog = DIALOG_BOOK_AUTONOMY;

            switch (GET_BPARAM1(o->oBehParams)) {
                case 20:
                    dialog = DIALOG_BOOK_AUTONOMY;
                break;
                case 21:
                    dialog = DIALOG_BOOK_DEFINING_LIFE;
                break;
                case 22:
                    dialog = DIALOG_BOOK_MACHINE;
                break;
                case 23:
                    dialog = DIALOG_BOOK_SEWNIA;
                break;
            }

            if (gCurrLevelNum != LEVEL_CASTLE) {
                dialog = DIALOG_JOURNAL_TTC - 1 + courseToOrderedIndex[gCurrCourseNum];
            }
            
            if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_DOWN) == MARIO_DIALOG_STATUS_SPEAK 
                && cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialog)) {
                set_mario_npc_dialog(MARIO_DIALOG_STOP);
                o->oAction = 0;
                }
        break;
    }
}


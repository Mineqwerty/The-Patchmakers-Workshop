#include "src/game/puppyprint.h"
#include "src/game/patch_tutorial_dialog.h"

void bhv_text_volume_init(void) {

}

void bhv_text_volume_loop(void) {
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
        break;
        case 2:
            print_set_envcolour(255, 255, 255, 255);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
        break;
        case 3:
            print_set_envcolour(255, 255, 255, CLAMP(255 - (o->oTimer * 17), 20, 255));
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 40, tutorialDialogs[GET_BPARAM1(o->oBehParams)], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            if (o->oTimer == 15) {
                o->oAction = 0;
            }
        break;
    }
}


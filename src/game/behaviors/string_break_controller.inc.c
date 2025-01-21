#include "src/game/cutscene.h"
#include "levels/bowser_2/header.h"

void bhv_string_break_controller_init(void) {
   
}

void bhv_string_break_controller_loop(void) {

    extern const u8 string_break_dma[];
            extern u8 bowser_2_dl_break_string1_i4_i4[];

            u8 *stringTexture = segmented_to_virtual(&bowser_2_dl_break_string1_i4_i4);
    if (gCurCutscene == CUTSCENE_EVENT_PATCHMAKER_BREAKING_POINT) {
        switch (o->oAction) {
            case 0:
            if (cExternalCutsceneTrigger >= 10) {
                o->oAction++;
            } 
            break;
            case 1:;

                dma_read(stringTexture, ((o->oTimer)*4096) + string_break_dma, ((o->oTimer)*4096) + string_break_dma + 4096);

                if (o->oTimer == 30) {
                    o->oAction++;
                }
            break;
            case 2:
            if (cExternalCutsceneTrigger >= 11) {
                o->oAction++;
            } 

            break;
            case 3:;

                dma_read(stringTexture, ((o->oTimer + 30)*4096) + string_break_dma, ((o->oTimer + 30)*4096) + string_break_dma + 4096);

                if (o->oTimer == 20) {
                    o->oAction++;
                }
            break;
            case 4:
            if (cExternalCutsceneTrigger >= 12) {
                o->oAction++;
            } 

            break;
            case 5:;

                dma_read(stringTexture, ((o->oTimer + 50)*4096) + string_break_dma, ((o->oTimer + 50)*4096) + string_break_dma + 4096);

                if (o->oTimer == 20) {
                    o->oAction++;
                }
            break;
            case 6:
            if (cExternalCutsceneTrigger >= 13) {
                o->oAction++;
            } 

            break;
            case 7:;

                dma_read(stringTexture, ((o->oTimer + 70)*4096) + string_break_dma, ((o->oTimer + 70)*4096) + string_break_dma + 4096);

                if (o->oTimer == 78) {
                    o->oAction++;
                }
            break;
        }
    }
}


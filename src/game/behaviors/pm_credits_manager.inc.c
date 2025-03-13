#include "src/game/hud.h"
#include "src/game/puppyprint.h"

void bhv_pm_credits_manager_init(void) {

}

void bhv_pm_credits_manager_loop(void) {

    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gCamera->cutscene = 1;
    gHudDisplay.flags = HUD_DISPLAY_NONE;

    u8 fadeAlpha = (o->oTimer > 120 ?  CLAMP(255 - 255*(f32)(o->oTimer - 120)/30.0f, 1, 255) : CLAMP(255*(f32)(o->oTimer)/30.0f, 1, 255));

    switch (o->oAction) {
        case 0:
            gSpecialHudRender = 1;
            gSpecialHudElementAlpha = CLAMP_U8(o->oTimer * 6);
            if (o->oTimer == 90) {
                o->oAction++;
            }
        break;
        case 1:
            gSpecialHudElementAlpha = CLAMP_U8(255 - o->oTimer * 6);
            if (o->oTimer == 30) {
                gSpecialHudRender = 0;
                o->oAction++;
            }
        break;
        case 2:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Hack Creator", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "CowQuack", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 3:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Original Soundtrack", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Ornevelder\nTori Draws Stuff\nCowQuack", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 4:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Patch Icons", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "PumpkinVolt", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 5:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Custom Fast64 Branch", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Lila", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 6:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Framebuffer Effects", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "TheCozies", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 7:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Rocket Flower Animation", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Thodds", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 8:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Camera Base", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Reonu", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 9:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Cutscene System Advice", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Rovertronic", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 10:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Terrain Sounds", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "Yoshi Milkman", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 11:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "General Code Help", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "ArcticJaguar725\nArthurtilly\nRovertronic\nTheCozies", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 12:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Beta Testing", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "this will be you in 2025", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                o->oAction++;
            }
        break;
        case 13:
            print_set_envcolour(255, 255, 255, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 20, "Special Thanks", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_OUTLINE);
            
            print_set_envcolour(240, 240, 240, fadeAlpha);
            print_small_text_buffered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 20, "The HackerSM64 Team", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            
            if (o->oTimer == 150) {
                
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 90, 0, 0, 0);
                o->oAction++;
            }
        break;
        case 14:
            gSpecialHudRender = 3;
        break;
    }
}


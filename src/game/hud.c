#include <PR/ultratypes.h>



#include "sm64.h"
#include "actors/common1.h"
#include "gfx_dimensions.h"
#include "game_init.h"
#include "level_update.h"
#include "camera.h"
#include "print.h"
#include "ingame_menu.h"
#include "hud.h"
#include "segment2.h"
#include "area.h"
#include "save_file.h"
#include "print.h"
#include "engine/surface_load.h"
#include "engine/math_util.h"
#include "puppycam2.h"
#include "puppyprint.h"
#include "levels/new_file_select/header.h"
#include "levels/castle_inside/header.h"
#include "levels/pss/header.h"
#include "include/behavior_data.h"
#include "actors/group0.h"
#include "levels/bowser_3/header.h"

#include "config.h"
#include "src/game/cutscene.h"

/* @file hud.c
 * This file implements HUD rendering and power meter animations.
 * That includes stars, lives, coins, camera status, power meter, timer
 * cannon reticle, and the unused keys.
 **/

#ifdef BREATH_METER
#define HUD_BREATH_METER_X         40
#define HUD_BREATH_METER_Y         32
#define HUD_BREATH_METER_HIDDEN_Y -20
#endif

// ------------- FPS COUNTER ---------------
// To use it, call print_fps(x,y); every frame.
#define FRAMETIME_COUNT 30

OSTime frameTimes[FRAMETIME_COUNT];
u8 curFrameTimeIndex = 0;

#include "PR/os_convert.h"

#ifdef USE_PROFILER
float profiler_get_fps();
#else
// Call once per frame
f32 calculate_and_update_fps() {
    OSTime newTime = osGetTime();
    OSTime oldTime = frameTimes[curFrameTimeIndex];
    frameTimes[curFrameTimeIndex] = newTime;

    curFrameTimeIndex++;
    if (curFrameTimeIndex >= FRAMETIME_COUNT) {
        curFrameTimeIndex = 0;
    }
    return ((f32)FRAMETIME_COUNT * 1000000.0f) / (s32)OS_CYCLES_TO_USEC(newTime - oldTime);
}
#endif

void print_fps(s32 x, s32 y) {
#ifdef USE_PROFILER
    f32 fps = profiler_get_fps();
#else
    f32 fps = calculate_and_update_fps();
#endif
    char text[14];

    sprintf(text, "FPS %2.2f", fps);
#ifdef PUPPYPRINT
    print_small_text(x, y, text, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
#else
    print_text(x, y, text);
#endif
}

// ------------ END OF FPS COUNER -----------------

struct PowerMeterHUD {
    s8 animation;
    s16 x;
    s16 y;
};

struct CameraHUD {
    s16 status;
};

struct HudBead hudBeads[8];

// Stores health segmented value defined by numHealthWedges
// When the HUD is rendered this value is 8, full health.
static s16 sPowerMeterStoredHealth;

static struct PowerMeterHUD sPowerMeterHUD = {
    POWER_METER_HIDDEN,
    HUD_POWER_METER_X,
    HUD_POWER_METER_HIDDEN_Y,
};

// Power Meter timer that keeps counting when it's visible.
// Gets reset when the health is filled and stops counting
// when the power meter is hidden.
s32 sPowerMeterVisibleTimer = 0;

u8 gSpecialHudRender = 0;
u8 gSpecialHudElementAlpha = 255;
s32 gSpecialHudElementTimer = 0;
f32 gSpecialHudElementValue = 0;
f32 gSpecialHudElementScale = 1.0f;

u8 gSaveTextAlpha = 0;

#ifdef BREATH_METER
static s16 sBreathMeterStoredValue;
static struct PowerMeterHUD sBreathMeterHUD = {
    BREATH_METER_HIDDEN,
    HUD_BREATH_METER_X,
    HUD_BREATH_METER_HIDDEN_Y,
};
s32 sBreathMeterVisibleTimer = 0;
#endif

static struct CameraHUD sCameraHUD = { CAM_STATUS_NONE };

/**
 * Renders a rgba16 16x16 glyph texture from a table list.
 */
void render_hud_tex_lut(s32 x, s32 y, Texture *texture) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gSPDisplayList(gDisplayListHead++, &dl_hud_img_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 15) << 2, (y + 15) << 2,
                        G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders a rgba16 8x8 glyph texture from a table list.
 */
void render_hud_small_tex_lut(s32 x, s32 y, Texture *texture) {
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                        0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders power meter health segment texture using a table list.
 */
void render_power_meter_health_segment(s16 numHealthWedges) {
    Texture *(*healthLUT)[] = segmented_to_virtual(&power_meter_health_segments_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       (*healthLUT)[numHealthWedges - 1]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(gDisplayListHead++, 0, 1, 2, 0);
    gSP1Triangle(gDisplayListHead++, 0, 2, 3, 0);
}

/**
 * Renders power meter display lists.
 * That includes the "POWER" base and the colored health segment textures.
 */
void render_dl_power_meter(s16 numHealthWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sPowerMeterHUD.x, (f32) sPowerMeterHUD.y, 0);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gDisplayListHead++, &dl_power_meter_base);

    if (numHealthWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_begin);
        render_power_meter_health_segment(numHealthWedges);
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_end);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Power meter animation called when there's less than 8 health segments
 * Checks its timer to later change into deemphasizing mode.
 */
void animate_power_meter_emphasized(void) {
    s16 hudDisplayFlags = gHudDisplay.flags;

    if (!(hudDisplayFlags & HUD_DISPLAY_FLAG_EMPHASIZE_POWER)) {
        if (sPowerMeterVisibleTimer == 45.0f) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
        }
    } else {
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Power meter animation called after emphasized mode.
 * Moves power meter y pos speed until it's at 200 to be visible.
 */
static void animate_power_meter_deemphasizing(void) {
    s16 speed = 5;

    if (sPowerMeterHUD.y > HUD_POWER_METER_Y - 20) speed = 3;
    if (sPowerMeterHUD.y > HUD_POWER_METER_Y - 10) speed = 2;
    if (sPowerMeterHUD.y > HUD_POWER_METER_Y -  5) speed = 1;

    sPowerMeterHUD.y += speed;

    if (sPowerMeterHUD.y > HUD_POWER_METER_Y) {
        sPowerMeterHUD.y = HUD_POWER_METER_Y;
        sPowerMeterHUD.animation = POWER_METER_VISIBLE;
    }
}

/**
 * Power meter animation called when there's 8 health segments.
 * Moves power meter y pos quickly until it's at 301 to be hidden.
 */
static void animate_power_meter_hiding(void) {
    sPowerMeterHUD.y += 20;
    if (sPowerMeterHUD.y > HUD_POWER_METER_HIDDEN_Y) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Handles power meter actions depending of the health segments values.
 */
void handle_power_meter_actions(s16 numHealthWedges) {
    // Show power meter if health is not full, less than 8
    if (numHealthWedges < 8 && sPowerMeterStoredHealth == 8
        && sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        sPowerMeterHUD.animation = POWER_METER_EMPHASIZED;
        sPowerMeterHUD.y = HUD_POWER_METER_EMPHASIZED_Y;
    }

    // Show power meter if health is full, has 8
    if (numHealthWedges == 8 && sPowerMeterStoredHealth == 7) {
        sPowerMeterVisibleTimer = 0;
    }

    // After health is full, hide power meter
    if (numHealthWedges == 8 && sPowerMeterVisibleTimer > 45.0f) {
        sPowerMeterHUD.animation = POWER_METER_HIDING;
    }

    // Update to match health value
    sPowerMeterStoredHealth = numHealthWedges;

#ifndef BREATH_METER
    // If Mario is swimming, keep power meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sPowerMeterHUD.animation == POWER_METER_HIDDEN
            || sPowerMeterHUD.animation == POWER_METER_EMPHASIZED) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
            sPowerMeterHUD.y = HUD_POWER_METER_EMPHASIZED_Y;
        }
        sPowerMeterVisibleTimer = 0;
    }
#endif
}

/**
 * Renders the power meter that shows when Mario is in underwater
 * or has taken damage and has less than 8 health segments.
 * And calls a power meter animation function depending of the value defined.
 */
void render_hud_power_meter(void) {
    s16 shownHealthWedges = gHudDisplay.wedges;
    if (sPowerMeterHUD.animation != POWER_METER_HIDING) handle_power_meter_actions(shownHealthWedges);
    if (sPowerMeterHUD.animation == POWER_METER_HIDDEN) return;
    switch (sPowerMeterHUD.animation) {
        case POWER_METER_EMPHASIZED:    animate_power_meter_emphasized();    break;
        case POWER_METER_DEEMPHASIZING: animate_power_meter_deemphasizing(); break;
        case POWER_METER_HIDING:        animate_power_meter_hiding();        break;
        default:                                                             break;
    }
    render_dl_power_meter(shownHealthWedges);
    sPowerMeterVisibleTimer++;
}

void render_hud_eye_effect(void) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, SCREEN_CENTER_X, SCREEN_CENTER_Y, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    if (gSpecialHudElementTimer < 60) {
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, 500, 0);
        gSPDisplayList(gDisplayListHead++, &screen_effect_eye_open_Plane_009_mesh);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, -1000, 0);
        gSPDisplayList(gDisplayListHead++, &screen_effect_eye_open_Plane_009_mesh);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, 500, 0);
    }
    if (gSpecialHudElementTimer == 0) {
        gSpecialHudElementScale = 0.2f;
        gSpecialHudElementAlpha = 255;
    }

    if (gSpecialHudElementTimer < 35) {
        gSpecialHudElementValue = 0.5f;
    }
    else if (gSpecialHudElementTimer < 58) {
        gSpecialHudElementValue = 0.3f;
    }
    else if (gSpecialHudElementTimer < 75) {
        gSpecialHudElementValue = 0.7f;
    }
    else if (gSpecialHudElementTimer < 96) {
        gSpecialHudElementValue = 0.4f;
    }
    else {
        gSpecialHudElementValue = 1.2f;
        gSpecialHudElementAlpha = CLAMP(gSpecialHudElementAlpha - 5, 0, 255);
    }



    gSpecialHudElementScale = approach_f32_asymptotic(gSpecialHudElementScale, gSpecialHudElementValue, 0.02f);

    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0f, gSpecialHudElementScale, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gSpecialHudElementAlpha);
    gSPDisplayList(gDisplayListHead++, &screen_effect_eye_open_Plane_009_mesh);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSpecialHudElementTimer++;

    if (gSpecialHudElementTimer == 180) {
        gSpecialHudRender = 0;
    }

}

void render_dl_curtains() {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }
    guTranslate(mtx, (f32) SCREEN_CENTER_X, (f32) SCREEN_CENTER_Y, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0f, 1.0f, 1.0f);
    //gSPDisplayList(gDisplayListHead++, &patch_challenge_curtain_Plane_012_mesh);
    

        create_dl_translation_matrix(MENU_MTX_PUSH, -100, 0, 0);
        gSPDisplayList(gDisplayListHead++, &patch_challenge_curtain_Plane_012_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

        create_dl_scale_matrix(MENU_MTX_NOPUSH, -1.0f, 1.0f, 1.0f);

        create_dl_translation_matrix(MENU_MTX_PUSH, -100, 0, 0);
        gSPDisplayList(gDisplayListHead++, &patch_challenge_curtain_Plane_012_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

        create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0f, 1.0f, 1.0f);

        create_dl_translation_matrix(MENU_MTX_PUSH, 0, SCREEN_CENTER_Y, 0);
        gSPDisplayList(gDisplayListHead++, &patch_challenge_curtain_top_Plane_013_mesh);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, SCREEN_CENTER_X - 30, -SCREEN_CENTER_Y + 30, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    extern const u8 patch_textures_dma[];
    extern u8 patch_challenge_patch_icon_mario_cap_rgba16_rgba16[];
    u8 *patchTexture = segmented_to_virtual(&patch_challenge_patch_icon_mario_cap_rgba16_rgba16);

    dma_read(patchTexture, (gPatchChallengeIndex * 2048) + patch_textures_dma,
             (gPatchChallengeIndex * 2048) + patch_textures_dma + 2048);

    // create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.4f, 0.4f, 1.0f);
    gSPDisplayList(gDisplayListHead++, &patch_challenge_patch_icon_Plane_014_mesh);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
     gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s16 holdStartTextTimer = 0;
s16 holdStartExitTimer = 0;

void render_patch_challenge_hold_start(void) {
    u8 printAlpha = 255;

    if (gPlayer1Controller->buttonDown & START_BUTTON) {
        holdStartTextTimer = 75;
        holdStartExitTimer++;
    }
    else {
        holdStartExitTimer = 0;
    }

    if (holdStartTextTimer > 0) {
        if (holdStartTextTimer < 60) {
            printAlpha = (4*holdStartTextTimer);
        }
        print_set_envcolour(0, 0, 0, printAlpha);
            print_small_text(SCREEN_CENTER_X+1, SCREEN_CENTER_Y+1, "Hold Start to Exit Course", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
            print_set_envcolour(255, 255, 255, printAlpha);
            print_small_text(SCREEN_CENTER_X, SCREEN_CENTER_Y, "Hold Start to Exit Course", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_VANILLA);
        
        holdStartTextTimer--;
    }

    if (holdStartExitTimer == 60) {
        initiate_warp(EXIT_COURSE_LEVEL, 2, 0x44, WARP_FLAG_EXIT_COURSE, 0);
            fade_into_special_warp(WARP_SPECIAL_NONE, 0);
            gSavedCourseNum = COURSE_NONE;
            holdStartExitTimer = 0;
        //initiate_warp(LEVEL_CASTLE, 2, 0x0A, WARP_FLAG_EXIT_COURSE, 0);
        //struct Object *outtaWarp = spawn_object_relative(0x45, 0, 0, 0, gMarioState->marioObj, MODEL_NONE, bhvWarp);
        //SET_BPARAM1(outtaWarp->oBehParams,  70);
    }
}

void render_hud_patch_challenge_timer(void) {
    u32 printTime[3];
    mm_ss_ms_from_frames(gPatchChallengeTimer, printTime);
        print_set_envcolour(0, 0, 0, 255);
        char textBytes[80];
        sprintf(textBytes, "Time: %02d:%02d.%02d", printTime[0], printTime[1], printTime[2]);
        print_small_text(21, 21, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_VANILLA);
        print_set_envcolour(255, 255, 255, 255);
        print_small_text(20, 20, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_VANILLA);

        mm_ss_ms_from_frames(patchChallengeTimes[gCurrAreaIndex-1], printTime);
        sprintf(textBytes, "Beat: %02d:%02d.%02d", printTime[0], printTime[1], printTime[2]);
        print_set_envcolour(0, 0, 0, 255);
        print_small_text(21, 5, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_VANILLA);
        print_set_envcolour(255, 255, 255, 255);
        print_small_text(20, 4, textBytes, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_VANILLA);
        
}

u8 beadColors[8][3] = { 
    {0xFF, 0x40, 0x3F},
    {0xFF, 0x40, 0x3F},
    {0xFF, 0xE2, 0x29},
    {0xFF, 0xE2, 0x29},
    {0xA5, 0xFF, 0xAB},
    {0xA5, 0xFF, 0xAB},
    {0x70, 0x92, 0xFF},
    {0x70, 0x92, 0xFF},
};

void render_hud_pop_off_beads() {
    for (int i = 0; i < 8; i++) {

        if (hudBeads[i].active == 1) {
            hudBeads[i].x = 9 + 60*sins(i * 0x888);
            hudBeads[i].y = SCREEN_HEIGHT - 10 - 28*sins((8-i) * 0x888);
            hudBeads[i].gravity = (f32)(random_u16() % 3);
            hudBeads[i].xVel = (f32)((random_u16() % 6) - 3);
            hudBeads[i].active = 2;
            hudBeads[i].randTexture = (random_u16() % 2);
        }
        
        if (hudBeads[i].active == 2) {
            hudBeads[i].gravity -= 1.6f;
            hudBeads[i].y += hudBeads[i].gravity;
            hudBeads[i].x += hudBeads[i].xVel;

            if (hudBeads[i].y < 0) {
                hudBeads[i].active = 0;
            }
            else {
                Mtx *mtx = alloc_display_list(sizeof(Mtx));

                if (mtx == NULL) {
                    return;
                }
                gDPSetEnvColor(gDisplayListHead++, beadColors[i][0], beadColors[i][1], beadColors[i][2], 255);
                guTranslate(mtx, (f32) 0, (f32) 0, 0);
                gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
                gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
                        G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0f, 1.0f, 1.0f);
                    create_dl_translation_matrix(MENU_MTX_PUSH, hudBeads[i].x, hudBeads[i].y, 0);
                    switch (hudBeads[i].randTexture) {
                        case 0:
                            gSPDisplayList(gDisplayListHead++, &menu_single_bead_Plane_016_mesh);
                        break;
                        case 1:
                            gSPDisplayList(gDisplayListHead++, &menu_single_bead_2_Plane_017_mesh);
                        break;
                    }
                    
                    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            }
        }
    }
}

void render_hud_power_beads() {
     Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }
    guTranslate(mtx, (f32) 0, (f32) SCREEN_HEIGHT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0f, 1.0f, 1.0f);
    //gSPDisplayList(gDisplayListHead++, &patch_challenge_curtain_Plane_012_mesh);


    extern u8 menu_power_beads_power_meter_rgba16[];

        u8 *powerMeterTexture = segmented_to_virtual(&menu_power_beads_power_meter_rgba16);

        dma_read(powerMeterTexture, (gHudDisplay.wedges*4096) + power_beads_textures_dma, (gHudDisplay.wedges*4096) + power_beads_textures_dma + 4096);
    

        create_dl_translation_matrix(MENU_MTX_PUSH, 40, -25, 0);
        gSPDisplayList(gDisplayListHead++, &menu_power_beads_Plane_015_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_dl_dpad_patches(s16 numHealthWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    //translate it when a cutscene or dialog is going on
    if (gDialogID != -1 || (gHudDisplay.flags & HUD_DISPLAY_FLAG_HIDE_DPAD)) {
        f32 xTimer = gDialogBoxOpenTimer;
        if (gHudDisplay.flags & HUD_DISPLAY_FLAG_HIDE_DPAD) {
            gDpadHideTimer = CLAMP(gDpadHideTimer - 5, 0, 90);
            xTimer = gDpadHideTimer;
        }
        guTranslate(mtx, (f32) 35 - (90 - xTimer), (f32) 32, 0);
    }
    else if (gDpadHideTimer < 90) {
            gDpadHideTimer = CLAMP(gDpadHideTimer + 5, 0, 90);
            guTranslate(mtx, (f32) 35 - (90 - gDpadHideTimer), (f32) 32, 0);
        }
    else {
        guTranslate(mtx, (f32) 35, (f32) 32, 0);
    }
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.4f, 0.4f, 1.0f);
    gSPDisplayList(gDisplayListHead++, &menu_dpad_icon_Plane_004_mesh);
    
        s8 animateBounce[4] = {0, 0, 0, 0};

        if (gPlayer1Controller->buttonPressed & (U_JPAD)) {animateBounce[0] = 1;}
        if (gPlayer1Controller->buttonPressed & (R_JPAD)) {animateBounce[1] = 1;}
        if (gPlayer1Controller->buttonPressed & (D_JPAD)) {animateBounce[2] = 1;}
        if (gPlayer1Controller->buttonPressed & (L_JPAD)) {animateBounce[3] = 1;}

        for (int i = 0; i < 4; i++) {
            if (animateBounce[i] % 2 == 1) {
                if (animateBounce[i] > 20) {
                    animateBounce[i] += 4;
                }
                else {
                    animateBounce[i] += 2;
                }

                if (animateBounce[i] >= 50) {
                    animateBounce[i] = 50;
                }
            }
            else if (animateBounce[i] != 0) {
                if (animateBounce[i] > 20) {
                    animateBounce[i] -= 2;
                }
                else {
                    animateBounce[i] -= 4;
                }

                if (animateBounce[i] < 0) {
                    animateBounce[i] = 0;
                }
            }
        }
        s8 dpadMap[4]; 
        save_file_get_dpad_map(gCurrSaveFileNum - 1, dpadMap);

        if (dpadMap[3] != -1) {
            create_dl_translation_matrix(MENU_MTX_PUSH, 0, animateBounce[3], 0);
            gSPDisplayList(gDisplayListHead++, &menu_patch_left_icon_Plane_007_mesh);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }

        if (dpadMap[1] != -1) {
            create_dl_translation_matrix(MENU_MTX_PUSH, 0, animateBounce[1], 0);
            gSPDisplayList(gDisplayListHead++, &menu_patch_right_icon_Plane_008_mesh);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }

        if (dpadMap[2] != -1) {
            create_dl_translation_matrix(MENU_MTX_PUSH, 0, animateBounce[2], 0);
            gSPDisplayList(gDisplayListHead++, &menu_patch_down_icon_Plane_006_mesh);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }

        if (dpadMap[0] != -1) {
            create_dl_translation_matrix(MENU_MTX_PUSH, 0, animateBounce[0], 0);
            gSPDisplayList(gDisplayListHead++, &menu_patch_up_icon_Plane_005_mesh);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }
    

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void update_dl_dpad_patches(void) {

    s8 dpadMap[4]; 
    save_file_get_dpad_map(gCurrSaveFileNum - 1, dpadMap);

    extern u8 menu_patch_left_icon_nothing_rgba16[];
        extern u8 menu_patch_right_icon_nothing_rgba16[];
        extern u8 menu_patch_down_icon_nothing_rgba16[];
        extern u8 menu_patch_up_icon_nothing_rgba16[];

        u8 *leftTexture = segmented_to_virtual(&menu_patch_left_icon_nothing_rgba16);
        u8 *rightTexture = segmented_to_virtual(&menu_patch_right_icon_nothing_rgba16);
        u8 *downTexture = segmented_to_virtual(&menu_patch_down_icon_nothing_rgba16);
        u8 *upTexture = segmented_to_virtual(&menu_patch_up_icon_nothing_rgba16);

        if (dpadMap[3] != -1) {
            dma_read(leftTexture, (dpadMap[3]*2048) + patch_textures_dma, (dpadMap[3]*2048) + patch_textures_dma + 2048);
        }
        if (dpadMap[1] != -1) {
            dma_read(rightTexture, (dpadMap[1]*2048) + patch_textures_dma, (dpadMap[1]*2048) + patch_textures_dma + 2048);
        }
        if (dpadMap[2] != -1) {
            dma_read(downTexture, (dpadMap[2]*2048) + patch_textures_dma, (dpadMap[2]*2048) + patch_textures_dma + 2048);
        }
        if (dpadMap[0] != -1) {
            dma_read(upTexture, (dpadMap[0]*2048) + patch_textures_dma, (dpadMap[0]*2048) + patch_textures_dma + 2048);
        }
}

#ifdef BREATH_METER
/**
 * Renders breath meter health segment texture using a table list.
 */
void render_breath_meter_segment(s16 numBreathWedges) {
    Texture *(*breathLUT)[];
    breathLUT = segmented_to_virtual(&breath_meter_segments_lut);
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (*breathLUT)[numBreathWedges - 1]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(gDisplayListHead++, 0, 1, 2, 0);
    gSP1Triangle(gDisplayListHead++, 0, 2, 3, 0);
}

/**
 * Renders breath meter display lists.
 * That includes the base and the colored segment textures.
 */
void render_dl_breath_meter(s16 numBreathWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sBreathMeterHUD.x, (f32) sBreathMeterHUD.y, 0);
    gSPMatrix(      gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
                    G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList( gDisplayListHead++, &dl_breath_meter_base);
    if (numBreathWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_breath_meter_health_segments_begin);
        render_breath_meter_segment(numBreathWedges);
        gSPDisplayList(gDisplayListHead++, &dl_breath_meter_health_segments_end);
    }
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Breath meter animation called after emphasized mode.
 * Moves breath meter y pos speed until it's visible.
 */
static void animate_breath_meter_sliding_in(void) {
    approach_s16_symmetric_bool(&sBreathMeterHUD.y, HUD_BREATH_METER_Y, 5);
    if (sBreathMeterHUD.y         == HUD_BREATH_METER_Y) {
        sBreathMeterHUD.animation = BREATH_METER_VISIBLE;
    }
}

/**
 * Breath meter animation called when there's 8 health segments.
 * Moves breath meter y pos quickly until it's hidden.
 */
static void animate_breath_meter_sliding_out(void) {
    approach_s16_symmetric_bool(&sBreathMeterHUD.y, HUD_BREATH_METER_HIDDEN_Y, 20);
    if (sBreathMeterHUD.y         == HUD_BREATH_METER_HIDDEN_Y) {
        sBreathMeterHUD.animation = BREATH_METER_HIDDEN;
    }
}

/**
 * Handles breath meter actions depending of the health segments values.
 */
void handle_breath_meter_actions(s16 numBreathWedges) {
    // Show breath meter if health is not full, less than 8
    if ((numBreathWedges < 8) && (sBreathMeterStoredValue == 8) && sBreathMeterHUD.animation == BREATH_METER_HIDDEN) {
        sBreathMeterHUD.animation = BREATH_METER_SHOWING;
        // sBreathMeterHUD.y         = HUD_BREATH_METER_Y;
    }
    // Show breath meter if breath is full, has 8
    if ((numBreathWedges == 8) && (sBreathMeterStoredValue  == 7)) sBreathMeterVisibleTimer  = 0;
    // After breath is full, hide breath meter
    if ((numBreathWedges == 8) && (sBreathMeterVisibleTimer > 45)) sBreathMeterHUD.animation = BREATH_METER_HIDING;
    // Update to match breath value
    sBreathMeterStoredValue = numBreathWedges;
    // If Mario is swimming, keep breath meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sBreathMeterHUD.animation == BREATH_METER_HIDDEN) {
            sBreathMeterHUD.animation = BREATH_METER_SHOWING;
        }
        sBreathMeterVisibleTimer = 0;
    }
}

void render_hud_breath_meter(void) {
    s16 shownBreathAmount = gHudDisplay.breath;
    if (sBreathMeterHUD.animation != BREATH_METER_HIDING) handle_breath_meter_actions(shownBreathAmount);
    if (sBreathMeterHUD.animation == BREATH_METER_HIDDEN) return;
    switch (sBreathMeterHUD.animation) {
        case BREATH_METER_SHOWING:       animate_breath_meter_sliding_in();  break;
        case BREATH_METER_HIDING:        animate_breath_meter_sliding_out(); break;
        default:                                                             break;
    }
    render_dl_breath_meter(shownBreathAmount);
    sBreathMeterVisibleTimer++;
}
#endif

void render_dl_title_screen() {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }
    
    guTranslate(mtx, (f32) SCREEN_WIDTH/2, (f32) SCREEN_HEIGHT/2, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    //gDPSetCombineMode(gDisplayListHead++, )
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.6f, 0.6f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gSpecialHudElementAlpha);
    gSPDisplayList(gDisplayListHead++, &tpw_logo_titlematMesh_mesh);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}


/**
 * Renders the amount of lives Mario has.
 */
void render_hud_mario_lives(void) {
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(22), HUD_TOP_Y, ","); // 'Mario Head' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(38), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(54), HUD_TOP_Y, "%d", gHudDisplay.lives);
}

#ifdef VANILLA_STYLE_CUSTOM_DEBUG
void render_debug_mode(void) {
    print_text(180, 40, "DEBUG MODE");
    print_text_fmt_int(5, 20, "Z %d", gMarioState->pos[2]);
    print_text_fmt_int(5, 40, "Y %d", gMarioState->pos[1]);
    print_text_fmt_int(5, 60, "X %d", gMarioState->pos[0]);
    print_text_fmt_int(10, 100, "SPD %d", (s32) gMarioState->forwardVel);
    print_text_fmt_int(10, 120, "ANG 0*%04x", (u16) gMarioState->faceAngle[1]);
    print_fps(10,80);
}
#endif

/**
 * Renders the amount of coins collected.
 */
void render_hud_coins(void) {
    print_text_blackout(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X)+2, HUD_TOP_Y - 22, "$"); // 'Coin' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X), HUD_TOP_Y - 20, "$"); // 'Coin' glyph

    print_text_blackout((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 18), HUD_TOP_Y - 22, "*"); // 'X' glyph
    print_text((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 16), HUD_TOP_Y - 20, "*"); // 'X' glyph

    print_text_fmt_int_blackout((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 32), HUD_TOP_Y - 22, "%d", gHudDisplay.coins);
    print_text_fmt_int((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 30), HUD_TOP_Y - 20, "%d", gHudDisplay.coins);
}

/**
 * Renders the amount of stars collected.
 * Disables "X" glyph when Mario has 100 stars or more.
 */
void render_hud_stars(void) {
    if (gHudFlash == HUD_FLASH_STARS && gGlobalTimer & 0x8) return;
    s8 showX = (gHudDisplay.stars < 100);
    print_text_blackout(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 2, HUD_TOP_Y - 2, "^"); // 'Star' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X), HUD_TOP_Y, "^"); // 'Star' glyph


    if (showX) print_text_blackout((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 18), HUD_TOP_Y - 2, "*"); // 'X' glyph
    if (showX) print_text((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 16), HUD_TOP_Y, "*"); // 'X' glyph

    print_text_fmt_int_blackout((showX * 14) + GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X - 18),
                       HUD_TOP_Y - 2, "%d", gHudDisplay.stars);
    print_text_fmt_int((showX * 14) + GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X - 16),
                       HUD_TOP_Y, "%d", gHudDisplay.stars);
}

/**
 * Unused function that renders the amount of keys collected.
 * Leftover function from the beta version of the game.
 */
void render_hud_keys(void) {
    s16 i;

    for (i = 0; i < gHudDisplay.keys; i++) {
        print_text((i * 16) + 220, 142, "|"); // unused glyph - beta key
    }
}

/**
 * Renders the timer when Mario start sliding in PSS.
 */
void render_hud_timer(void) {
    Texture *(*hudLUT)[58] = segmented_to_virtual(&main_hud_lut);
    u16 timerValFrames = gHudDisplay.timer;
    u16 timerMins = timerValFrames / (30 * 60);
    u16 timerSecs = (timerValFrames - (timerMins * 1800)) / 30;
    u16 timerFracSecs = ((timerValFrames - (timerMins * 1800) - (timerSecs * 30)) & 0xFFFF) / 3;

#if MULTILANG
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH: print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185,  "TIME"); break;
        case LANGUAGE_FRENCH:  print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(155), 185, "TEMPS"); break;
        case LANGUAGE_GERMAN:  print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185,  "ZEIT"); break;
    }
#else
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
#endif

    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(91), 185, "%0d", timerMins);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(71), 185, "%02d", timerSecs);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(37), 185, "%d", timerFracSecs);

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(81), 32, (*hudLUT)[GLYPH_APOSTROPHE]);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(46), 32, (*hudLUT)[GLYPH_DOUBLE_QUOTE]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

/**
 * Sets HUD status camera value depending of the actions
 * defined in update_camera_status.
 */
void set_hud_camera_status(s16 status) {
    sCameraHUD.status = status;
}

/**
 * Renders camera HUD glyphs using a table list, depending of
 * the camera status called, a defined glyph is rendered.
 */
void render_hud_camera_status(void) {
    Texture *(*cameraLUT)[6] = segmented_to_virtual(&main_hud_camera_lut);
    s32 x = GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_CAMERA_X);
    s32 y = 205;

    if (sCameraHUD.status == CAM_STATUS_NONE) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(x, y, (*cameraLUT)[GLYPH_CAM_CAMERA]);

    switch (sCameraHUD.status & CAM_STATUS_MODE_GROUP) {
        case CAM_STATUS_MARIO:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_MARIO_HEAD]);
            break;
        case CAM_STATUS_LAKITU:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_LAKITU_HEAD]);
            break;
        case CAM_STATUS_FIXED:
            render_hud_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_FIXED]);
            break;
    }

    switch (sCameraHUD.status & CAM_STATUS_C_MODE_GROUP) {
        case CAM_STATUS_C_DOWN:
            render_hud_small_tex_lut(x + 4, y + 16, (*cameraLUT)[GLYPH_CAM_ARROW_DOWN]);
            break;
        case CAM_STATUS_C_UP:
            render_hud_small_tex_lut(x + 4, y - 8, (*cameraLUT)[GLYPH_CAM_ARROW_UP]);
            break;
    }

    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

void render_hud_boss_intro(void) {

    char *bossTitles[7] = {
        "Pushpin Pokey",
        "Aurumcael",
        "Demonic Solids",
        "Xodorap",
        "The Patchmaker",
        "The Patchmaker",
        "Mantle of Madness"
    };
    u8 bossTitleColor[7];
    switch (gHudDisplay.bossID) {
        case 1:
            bossTitleColor[0] = 209;
            bossTitleColor[1] = 141;
            bossTitleColor[2] = 63;
        break;
        case 2:
            bossTitleColor[0] = 222;
            bossTitleColor[1] = 181;
            bossTitleColor[2] = 58;
        break;
        case 3:
            bossTitleColor[0] = 125;
            bossTitleColor[1] = 175;
            bossTitleColor[2] = 255;
        break;
        case 4:
            bossTitleColor[0] = 0x4C;
            bossTitleColor[1] = 0x2A;
            bossTitleColor[2] = 0xBD;
        break;
        case 5:
            bossTitleColor[0] = 0x4C;
            bossTitleColor[1] = 0x2A;
            bossTitleColor[2] = 0x2D;
        break;
        case 6:
            bossTitleColor[0] = 0x4C;
            bossTitleColor[1] = 0x2A;
            bossTitleColor[2] = 0x2D;
        break;
        case 7:
            bossTitleColor[0] = 0x6C;
            bossTitleColor[1] = 0x4A;
            bossTitleColor[2] = 0x4D;
        break;
        default:
            bossTitleColor[0] = 255;
            bossTitleColor[1] = 255;
            bossTitleColor[2] = 255;
        break;
    }

    s32 flavorAlpha = gHudDisplay.bossIntroTimer * 10;
    if (flavorAlpha > 255) {
        flavorAlpha = 255;
    }
    print_set_envcolour(255, 255, 255, flavorAlpha);
    switch (gHudDisplay.bossID) {
        case 1:
            print_small_text(160, 140, "Mummified scourge of the cliffs", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 2:
            print_small_text(160, 140, "Goddess of an empty heaven", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 3:
            print_small_text(160, 140, "Polyhedral punishers", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 4:
            print_small_text(160, 140, "Drowned angel of the deep", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 5:
            print_small_text(160, 140, "Crazed creator of all that surrounds", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 6:
            print_small_text(160, 140, "Decaying man of creation and failure", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);
        break;
        case 7:
            print_small_text(160, 140, "Product of pride and regret", PRINT_TEXT_ALIGN_CORRUPT, PRINT_ALL, FONT_OUTLINE);
        break;
    }

    s32 titleAlpha = (gHudDisplay.bossIntroTimer - 60) * 10;
    if (titleAlpha > 255) {
        titleAlpha = 255;
    }
    if (titleAlpha < 0) {
        titleAlpha = 0;
    }

    
    print_set_envcolour(bossTitleColor[0], bossTitleColor[1], bossTitleColor[2], titleAlpha);
    s32 printType = PRINT_TEXT_ALIGN_CENTRE;
    if (gHudDisplay.bossID == 7) {
        printType = PRINT_TEXT_ALIGN_CORRUPT;
    }
    print_small_text(160, 160, bossTitles[gHudDisplay.bossID - 1], printType, PRINT_ALL, FONT_OUTLINE);

    gHudDisplay.bossIntroTimer++;

    if (gHudDisplay.bossID == 7) {
        if (gHudDisplay.bossIntroTimer > 250) {
            gHudDisplay.bossIntroTimer = 0;
            gHudDisplay.bossID = 0;
            gHudDisplay.flags &= ~HUD_DISPLAY_BOSS_INTRO;
        }
    }
    else {
        if (gHudDisplay.bossIntroTimer > 150) {
            gHudDisplay.bossIntroTimer = 0;
            gHudDisplay.bossID = 0;
            gHudDisplay.flags &= ~HUD_DISPLAY_BOSS_INTRO;
        }
    }
}

void render_hud_save_text(void) {
    if (gSaveTextIndicatorTimer > 30) {
        gSaveTextAlpha = CLAMP(gSaveTextAlpha + 9, 0, 255);
    }
    else {
        gSaveTextAlpha = CLAMP(gSaveTextAlpha - 9, 0, 255);
    }

    print_set_envcolour(0, 0, 0, CLAMP(gSaveTextAlpha, 1, 255));
    print_small_text(SCREEN_WIDTH-10, SCREEN_HEIGHT-30, "Saved.", PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_VANILLA);
    print_set_envcolour(255, 255, 255, CLAMP(gSaveTextAlpha, 1, 255));
    print_small_text(SCREEN_WIDTH-9, SCREEN_HEIGHT-29, "Saved.", PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_VANILLA);

    gSaveTextIndicatorTimer--;
}

u8 buttonAlphas[5] = {0,0,0,0,0};
f32 joystickOffset = 0;

void render_hud_final_needle_prompts() {

    gHudDisplay.flags = 0;

    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    u8 r, g, b = 0;

    //update button alphas
    if (gFinalNeedleStage == 5) {
        for (int i = 0; i < 5; i++) {
            if (buttonAlphas[i] > 0) {
                buttonAlphas[i] = CLAMP (buttonAlphas[i] - 20, 0, 255);
            }
        }
    }
    else {
        for (int i = 0; i <= gFinalNeedleStage; i++) {
            if (buttonAlphas[i] < 255) {
                buttonAlphas[i] = CLAMP (buttonAlphas[i] + 10, 0, 255);
            }
        }
    }

    //joystick
    if (gPlayer1Controller->rawStickY < -6 || (gFinalNeedleStage == 5)) {
        r = 0;
        g = 255;
        b = 0;
    }
    else {
        r = g = b = (((gGlobalTimer / 15) % 2 == 0) ? 255 : 200);
    }

    //move joystick once full alpha
    if (buttonAlphas[0] == 255) {
        joystickOffset = approach_f32_asymptotic(joystickOffset, -10.0f, 0.04f);
    }

    gDPSetEnvColor(gDisplayListHead++, r, g, b, buttonAlphas[0]);
    create_dl_translation_matrix(MENU_MTX_PUSH, 80, 120, 0);
        gSPDisplayList(gDisplayListHead++, &prompt_joystick_back_buttonmesh_002_mesh);
        create_dl_translation_matrix(MENU_MTX_PUSH, 0, joystickOffset, 0);
            gSPDisplayList(gDisplayListHead++, &prompt_joystick_buttonmesh_003_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    //a button
    if (gFinalNeedleStage >= 1) {
        if ((gPlayer1Controller->buttonDown & A_BUTTON) || (gFinalNeedleStage == 5)) {
            r = 0;
            g = 255;
            b = 0;
        }
        else {
            r = g = b = (((gGlobalTimer / 15) % 2 == 0) ? 255 : 200);
        }
    
        gDPSetEnvColor(gDisplayListHead++, r, g, b, buttonAlphas[1]);
        create_dl_translation_matrix(MENU_MTX_PUSH, 200, 120, 0);
            gSPDisplayList(gDisplayListHead++, &prompt_a_button_buttonmesh_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    //b button
    if (gFinalNeedleStage >= 2) {
        if ((gPlayer1Controller->buttonDown & B_BUTTON) || (gFinalNeedleStage == 5)) {
            r = 0;
            g = 255;
            b = 0;
        }
        else {
            r = g = b = (((gGlobalTimer / 15) % 2 == 0) ? 255 : 200);
        }
    
        gDPSetEnvColor(gDisplayListHead++, r, g, b, buttonAlphas[2]);
        create_dl_translation_matrix(MENU_MTX_PUSH, 240, 160, 0);
            gSPDisplayList(gDisplayListHead++, &prompt_b_button_buttonmesh_001_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    //z trigger
    if (gFinalNeedleStage >= 3) {
        if ((gPlayer1Controller->buttonDown & Z_TRIG) || (gFinalNeedleStage == 5)) {
            r = 0;
            g = 255;
            b = 0;
        }
        else {
            r = g = b = (((gGlobalTimer / 15) % 2 == 0) ? 255 : 200);
        }
    
        gDPSetEnvColor(gDisplayListHead++, r, g, b, buttonAlphas[3]);
        create_dl_translation_matrix(MENU_MTX_PUSH, 70, 200, 0);
            gSPDisplayList(gDisplayListHead++, &prompt_z_trig_buttonmesh_004_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    //r trigger
    if (gFinalNeedleStage >= 4) {
        if ((gPlayer1Controller->buttonDown & R_TRIG) || (gFinalNeedleStage == 5)) {
            r = 0;
            g = 255;
            b = 0;
        }
        else {
            r = g = b = (((gGlobalTimer / 15) % 2 == 0) ? 255 : 200);
        }
    
        gDPSetEnvColor(gDisplayListHead++, r, g, b, buttonAlphas[4]);
        create_dl_translation_matrix(MENU_MTX_PUSH, 250, 100, 0);
            gSPDisplayList(gDisplayListHead++, &prompt_r_trig_buttonmesh_005_mesh);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
}

/**
 * Render HUD strings using hudDisplayFlags with it's render functions,
 * excluding the cannon reticle which detects a camera preset for it.
 */
void render_hud(void) {
    s16 hudDisplayFlags = gHudDisplay.flags;

    if (cSkipCutsceneState == 1) {
        create_dl_ortho_matrix();
        print_set_envcolour(0, 0, 0, CLAMP(cSkipCutsceneTimer * 5, 1, 255));
            print_small_text(SCREEN_WIDTH-10, 10, "Press Start to Skip", PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_VANILLA);
            print_set_envcolour(255, 255, 255, CLAMP(cSkipCutsceneTimer * 5, 1, 255));
            print_small_text(SCREEN_WIDTH-9, 9, "Press Start to Skip", PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_VANILLA);
    }

    if (hudDisplayFlags == HUD_DISPLAY_NONE) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterStoredHealth = 8;
        sPowerMeterVisibleTimer = 0;
#ifdef BREATH_METER
        sBreathMeterHUD.animation = BREATH_METER_HIDDEN;
        sBreathMeterStoredValue = 8;
        sBreathMeterVisibleTimer = 0;
#endif
    } else {
#ifdef VERSION_EU
        // basically create_dl_ortho_matrix but guOrtho screen width is different
        Mtx *mtx = alloc_display_list(sizeof(*mtx));

        if (mtx == NULL) {
            return;
        }

        create_dl_identity_matrix();
        guOrtho(mtx, -16.0f, SCREEN_WIDTH + 16, 0, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx),
                  G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
#else
        create_dl_ortho_matrix();
#endif

        if (gCurrentArea != NULL && gCurrentArea->camera->mode == CAMERA_MODE_INSIDE_CANNON) {
            render_hud_cannon_reticle();
        }

#ifdef ENABLE_LIVES
        if (hudDisplayFlags & HUD_DISPLAY_FLAG_LIVES) {
            render_hud_mario_lives();
        }
#endif

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_COIN_COUNT) {
            if (gCurrLevelNum != LEVEL_PSS) {
            render_hud_coins();
            }
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_STAR_COUNT) {
            if (gCurrLevelNum != LEVEL_PSS) {
            render_hud_stars();
            }
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_KEYS) {
            render_hud_keys();
        }

#ifdef BREATH_METER
        if (hudDisplayFlags & HUD_DISPLAY_FLAG_BREATH_METER) render_hud_breath_meter();
#endif

        if (gBossMaxHealth > 0) {
            render_boss_health();
        }

        if (gSaveTextIndicatorTimer > 0) {
            render_hud_save_text();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_CAMERA_AND_POWER) {

            //Patch challenge renders its overlay instead of health and dpad
            if (gCurrLevelNum == LEVEL_PSS) {
                render_dl_curtains();
                render_hud_patch_challenge_timer();
                render_patch_challenge_hold_start();
            }
            else {
                render_dl_dpad_patches(2);
                render_hud_power_beads();
                render_hud_pop_off_beads();
            }
            
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_TIMER) {
            render_hud_timer();
        }

        if (hudDisplayFlags & HUD_DISPLAY_BOSS_INTRO) {
            render_hud_boss_intro();
        }

#ifdef VANILLA_STYLE_CUSTOM_DEBUG
        if (gCustomDebugMode) {
            render_debug_mode();
        }
#endif
    }

    

    if (gSpecialHudRender > 0) {
        if (hudDisplayFlags == HUD_DISPLAY_NONE) {
            create_dl_ortho_matrix();
        }
        switch (gSpecialHudRender) {
            case 1:
                render_dl_title_screen();
            break;
            case 2:
                render_hud_eye_effect();
            break;
        }
    }

    if (gRenderFinalNeedlePrompts && gFinalNeedleStage < 6) {
        create_dl_ortho_matrix();
        render_hud_final_needle_prompts();
    }
}

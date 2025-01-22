#include "src/game/texscroll.h"
#include <PR/ultratypes.h>

#include "audio/external.h"
#include "behavior_data.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "eu_translation.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/level_update.h"
#include "game/memory.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/save_file.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "game/rumble_init.h"
#include "sm64.h"
#include "star_select.h"
#include "text_strings.h"
#include "game/main.h"
#include "include/seq_ids.h"

/**
 * @file star_select.c
 * This file implements how the star select screen (act selector) function.
 * That includes handles what stars can be selected, star selector types,
 * strings, act values, and star selector model rendering if a star is collected or not.
 */

// Star Selector count models printed in the act selector menu.
static struct Object *sStarSelectorModels[8];

// The act the course is loaded as, affects whether some objects spawn.
static s8 sLoadedActNum;

// Number of obtained stars, excluding the coin star.
static u8 sObtainedStars;

// Total number of stars that appear in the act selector menu.
static s8 sVisibleStars;

// Act selected when the act menu is first opened.
static u8 sInitSelectedActNum;

// Index value of the act selected in the act menu.
static s8 sSelectedActIndex = 0;

// Index value of the star that is selectable in the act menu.
// Excluding the next star, it doesn't count other transparent stars.
static s8 sSelectableStarIndex = 0;

// Act Selector menu timer that keeps counting until you choose an act.
static s32 sActSelectorMenuTimer = 0;

/**
 * Act Selector Star Type Loop Action
 * Defines a select type for a star in the act selector.
 */
void bhv_act_selector_star_type_loop(void) {
    switch (gCurrentObject->oStarSelectorType) {
        // If a star is not selected, don't rotate or change size
        case STAR_SELECTOR_NOT_SELECTED:
            gCurrentObject->oStarSelectorSize -= 0.1f;
            if (gCurrentObject->oStarSelectorSize < 1.0f) {
                gCurrentObject->oStarSelectorSize = 1.0f;
            }
            gCurrentObject->oFaceAngleYaw = 0;
            break;
        // If a star is selected, rotate and slightly increase size
        case STAR_SELECTOR_SELECTED:
            gCurrentObject->oStarSelectorSize += 0.1f;
            if (gCurrentObject->oStarSelectorSize > 1.3f) {
                gCurrentObject->oStarSelectorSize = 1.3f;
            }
            gSelectedStarCoords[0] = o->oPosX;
            gSelectedStarCoords[1] = o->oPosY;
            gSelectedStarCoords[2] = o->oPosZ;
            gCurrentObject->oFaceAngleYaw += 0x800;
            break;
        // If the 100 coin star is selected, rotate
        case STAR_SELECTOR_100_COINS:
            gCurrentObject->oFaceAngleYaw += 0x800;
            break;
    }
    // Scale act selector stars depending of the type selected
    cur_obj_scale(gCurrentObject->oStarSelectorSize);
    // Unused timer, only referenced here. Probably replaced by sActSelectorMenuTimer
    gCurrentObject->oStarSelectorTimer++;
}

/**
 * Renders the 100 coin star with an special star selector type.
 */
void render_100_coin_star(u8 stars) {
    if (stars & STAR_FLAG_ACT_100_COINS) {
        // If the 100 coin star has been collected, create a new star selector next to the coin score.
    #ifdef WIDE
        if (gConfig.widescreen) {
            sStarSelectorModels[6] = spawn_object_abs_with_rot(o, 0, MODEL_STAR,
                                                            bhvActSelectorStarType, (370 * 4.0f) / 3, 24, -300, 0, 0, 0);
        } else {
            sStarSelectorModels[6] = spawn_object_abs_with_rot(o, 0, MODEL_STAR,
                                                            bhvActSelectorStarType, 370, 24, -300, 0, 0, 0);
        }
    #else
        sStarSelectorModels[6] = spawn_object_abs_with_rot(o, 0, MODEL_STAR,
                                                        bhvActSelectorStarType, 370, 24, -300, 0, 0, 0);
    #endif

        sStarSelectorModels[6]->oStarSelectorSize = 0.8f;
        sStarSelectorModels[6]->oStarSelectorType = STAR_SELECTOR_100_COINS;
    }
}

// DO NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOT FORGET ABOUT THE HARDCODED SCRIPT JUMP IN levels/menu/script.c PLEASE!!!!!!!!!!!!!!!!!!!!

void spawn_stage_diorama(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            spawn_object_abs_with_rot(o, 0, MODEL_TTC_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_PIRANHA_PLANT), 0);
        break;
        case LEVEL_WF:
            spawn_object_abs_with_rot(o, 0, MODEL_RDR_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_RAINY_DAY_ROADSIDE_SELECT), 0);
        break;
        case LEVEL_JRB:
            spawn_object_abs_with_rot(o, 0, MODEL_STC_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_STONE_TERRACE_CITY_SELECT), 0);
        break;
        case LEVEL_CCM:
            spawn_object_abs_with_rot(o, 0, MODEL_GSS_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_GOLD_SOAKED_SKY_SELECT), 0);
        break;
        case LEVEL_HMC:
            spawn_object_abs_with_rot(o, 0, MODEL_SS_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_SUBTERRANEAN_SEAWAY_SELECT), 0);
        break;
        case LEVEL_LLL:
            spawn_object_abs_with_rot(o, 0, MODEL_CLC_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_CANDLELIT_CHAMBER_SELECT), 0);
        break;
        case LEVEL_DDD:
            spawn_object_abs_with_rot(o, 0, MODEL_HVH_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_HIDDEN_VILLAGE_HOLD_SELECT), 0);
        break;
        case LEVEL_SSL:
            spawn_object_abs_with_rot(o, 0, MODEL_TVW_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_VIOLET_TWILIT_WOODS_SELECT), 0);
        break;
        case LEVEL_BBH:
            spawn_object_abs_with_rot(o, 0, MODEL_TFP_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_THE_FAR_PLANE_SELECT), 0);
        break;
        case LEVEL_SL:
            spawn_object_abs_with_rot(o, 0, MODEL_EA_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EMPYREAN_ABYSS_SELECT), 0);
        break;
        case LEVEL_WDW:
            spawn_object_abs_with_rot(o, 0, MODEL_CORR_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_CITY_OF_RECONSTRUCTED_RUIN), 0);
        break;
        case LEVEL_TTM:
            spawn_object_abs_with_rot(o, 0, MODEL_TS_DIORAMA, bhvActSelectorStarType, -2000, -500, -7500, 0, 0, 0);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_TIMELESS_SHRINE_SELECT), 0);
        break;
    }
}

/**
 * Act Selector Init Action
 * Checks how many stars has been obtained in a course, to render
 * the correct star models, the 100 coin star and also handles
 * checks of what star should be next in sInitSelectedActNum.
 */
void bhv_act_selector_init(void) {
    s16 i = 0;
    s32 selectorModelIDs[10];
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
    gStarSelectDisturbed = 0;


    sVisibleStars = 0;
    while (i != sObtainedStars) {
        if (stars & (1 << sVisibleStars)) { // Star has been collected
            selectorModelIDs[sVisibleStars] = MODEL_STAR_MARKER;
            i++;
        } else { // Star has not been collected
            selectorModelIDs[sVisibleStars] = MODEL_BLUE_STAR_MARKER;
            // If this is the first star that has not been collected, set
            // the default selection to this star.
            if (sInitSelectedActNum == 0) {
                sInitSelectedActNum = sVisibleStars + 1;
                sSelectableStarIndex = sVisibleStars;
            }
        }
        sVisibleStars++;
    }

    // If the stars have been collected in order so far, show the next star.
    if (sVisibleStars == sObtainedStars && sVisibleStars != 6) {
        selectorModelIDs[sVisibleStars] = MODEL_BLUE_STAR_MARKER;
        sInitSelectedActNum = sVisibleStars + 1;
        sSelectableStarIndex = sVisibleStars;
        sVisibleStars++;
    }

    // If all stars have been collected, set the default selection to the last star.
    if (sObtainedStars == 6) {
        sInitSelectedActNum = sVisibleStars;
    }

    //! Useless, since sInitSelectedActNum has already been set in this
    //! scenario by the code that shows the next uncollected star.
    if (sObtainedStars == 0) {
        sInitSelectedActNum = 1;
    }

    // Render star selector objects
    for (i = 0; i < sVisibleStars; i++) {
        Vec3f starPinCoords;
        get_level_star_pin(gCurrLevelNum, i, starPinCoords);
        sStarSelectorModels[i] =
            spawn_object_abs_with_rot(o, 0, selectorModelIDs[i], bhvActSelectorStarType,
                                    starPinCoords[0], starPinCoords[1], starPinCoords[2], 0, 0, 0);
        sStarSelectorModels[i]->oStarSelectorSize = 1.0f;
    }
    //note: disable menu scrolling when using this
    spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvCoordinateController, -2000.0f, 50, -7500.0f, 0, 0, 0);
    spawn_stage_diorama();
    render_100_coin_star(stars);
}

void get_level_star_pin(s16 levelID, s16 starIndex, Vec3f coords) {
    switch (levelID) {
        case LEVEL_BOB:
            switch (starIndex) {
                case 0: coords[0] = 3338.0f; coords[1] = 1030.0f; coords[2] = -9000.0f;
                break;
                case 1: coords[0] = 377.0f; coords[1] = 1470.0f; coords[2] = -9855.0f;
                break;
                case 2: coords[0] = -3989.0f; coords[1] = 210.0f; coords[2] = -5616.0f;
                break;
                case 3: coords[0] = -4116.0f; coords[1] = 1270.0f; coords[2] = -9045.0f;
                break;
                case 4: coords[0] = 1345.0f; coords[1] = -530.0f; coords[2] = -8283.0f;
                break;
                case 5: coords[0] = 413.0f; coords[1] = -550.0f; coords[2] = -6357.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;

        case LEVEL_WF:
            switch (starIndex) {
                case 0: coords[0] = 794.0f; coords[1] = 130.0f; coords[2] = -10929.0f;
                break;
                case 1: coords[0] = 1683.0f; coords[1] = 190.0f; coords[2] = -6103.0f;
                break;
                case 2: coords[0] = -502.0f; coords[1] = 50.0f; coords[2] = -9682.0f;
                break;
                case 3: coords[0] = -4866.0f; coords[1] = -270.0f; coords[2] = -8825.0f;
                break;
                case 4: coords[0] = 3119.0f; coords[1] = 190.0f; coords[2] = -3756.0f;
                break;
                case 5: coords[0] = -5009.0f; coords[1] = 230.0f; coords[2] = -4264.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;

        case LEVEL_JRB:
            switch (starIndex) {
                case 0: coords[0] = -6046.0f; coords[1] = 1930.0f; coords[2] = -6248.0f;
                break;
                case 1: coords[0] = -4522.0f; coords[1] = 590.0f; coords[2] = -5867.0f;
                break;
                case 2: coords[0] = 656.0f; coords[1] = 550.0f; coords[2] = -8505.0f;
                break;
                case 3: coords[0] = 1643.0f; coords[1] = 410.0f; coords[2] = -5359.0f;
                break;
                case 4: coords[0] = -2548.0f; coords[1] = -370.0f; coords[2] = -4470.0f;
                break;
                case 5: coords[0] = -2040.0f; coords[1] = -350.0f; coords[2] = -9931.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;

        case LEVEL_CCM:
            switch (starIndex) {
                case 0: coords[0] = 2000.0f; coords[1] = 2990.0f; coords[2] = -9660.0f;
                break;
                case 1: coords[0] = -80.0f; coords[1] = -270.0f; coords[2] = -9820.0f;
                break;
                case 2: coords[0] = -6160.0f; coords[1] = 1890.0f; coords[2] = -3900.0f;
                break;
                case 3: coords[0] = -2560.0f; coords[1] = 4550.0f; coords[2] = -2780.0f;
                break;
                case 4: coords[0] = -2240.0f; coords[1] = -270.0f; coords[2] = -4460.0f;
                break;
                case 5: coords[0] = -2400.0f; coords[1] = 3510.0f; coords[2] = -10060.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;
        case LEVEL_HMC:
            switch (starIndex) {
                case 0: coords[0] = 394.0f; coords[1] = 4410.0f; coords[2] = -7626.0f;
                break;
                case 1: coords[0] = 1150.0f; coords[1] = 1770.0f; coords[2] = -4091.0f;
                break;
                case 2: coords[0] = -7456.0f; coords[1] = 2230.0f; coords[2] = -12039.0f;
                break;
                case 3: coords[0] = 1384.0f; coords[1] = -3270.0f; coords[2] = -7419.0f;
                break;
                case 4: coords[0] = 1276.0f; coords[1] = -1250.0f; coords[2] = -10000.0f;
                break;
                case 5: coords[0] = -7777.0f; coords[1] = -1530.0f; coords[2] = -8999.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;

        case LEVEL_LLL:
            switch (starIndex) {
                case 0: coords[0] = 2770.0f; coords[1] = 1330.0f; coords[2] = -3150.0f;
                break;
                case 1: coords[0] = -6860.0f; coords[1] = 1930.0f; coords[2] = -1486.0f;
                break;
                case 2: coords[0] = -7740.0f; coords[1] = 3630.0f; coords[2] = -5890.0f;
                break;
                case 3: coords[0] = -6480.0f; coords[1] = 550.0f; coords[2] = -12190.0f;
                break;
                case 4: coords[0] = 2158.0f; coords[1] = 2510.0f; coords[2] = -13170.0f;
                break;
                case 5: coords[0] = -3566.0f; coords[1] = 970.0f; coords[2] = -7063.0f;
                break;


                default: vec3f_set(coords, -2000.0f, 0.0f, -7500.0f);
                break;
            }
        break;

        default: coords[0] = 377.0f; coords[1] = 1470.0f; coords[2] = -9855.0f;
        break;
    }
}

/**
 * Act Selector Loop Action
 * Handles star selector scrolling depending of what stars are
 * selectable, whenever all 6 stars are obtained or not.
 * Also handles 2 star selector types whenever the star is selected
 * or not, the types are defined in bhv_act_selector_star_type_loop.
 */
void bhv_act_selector_loop(void) {
    s8 i;
    u8 starIndexCounter;
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

    if (o->oTimer == 30) {
        gStarSelectDisturbed = 1;
    }

    if (sObtainedStars != 6) {
        // Sometimes, stars are not selectable even if they appear on the screen.
        // This code filters selectable and non-selectable stars.
        sSelectedActIndex = 0;
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &sSelectableStarIndex, 0, sObtainedStars);
        starIndexCounter = sSelectableStarIndex;
        for (i = 0; i < sVisibleStars; i++) {
            // Can the star be selected (is it either already completed or the first non-completed mission)
            if ((stars & (1 << i)) || i + 1 == sInitSelectedActNum) {
                if (starIndexCounter == 0) { // We have reached the sSelectableStarIndex-th selectable star.
                    sSelectedActIndex = i;
                    break;
                }
                starIndexCounter--;
            }
        }
    } else {
        // If all stars are collected then they are all selectable.
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &sSelectableStarIndex, 0, sVisibleStars - 1);
        sSelectedActIndex = sSelectableStarIndex;
    }

    // Star selector type handler
    for (i = 0; i < sVisibleStars; i++) {
        if (sSelectedActIndex == i) {
            sStarSelectorModels[i]->oStarSelectorType = STAR_SELECTOR_SELECTED;
        } else {
            sStarSelectorModels[i]->oStarSelectorType = STAR_SELECTOR_NOT_SELECTED;
        }
    }
}

/**
 * Print the course number selected with the wood rgba16 course texture.
 */
#if MULTILANG
void print_course_number(s16 language) {
#else
void print_course_number(void) {
#endif
    u8 courseNum[4];

    create_dl_translation_matrix(MENU_MTX_PUSH, 158.0f, 81.0f, 0.0f);

    // Full wood texture in JP & US, lower part of it on EU
    gSPDisplayList(gDisplayListHead++, dl_menu_rgba16_wood_course);

#if MULTILANG
    // Change upper part of the wood texture depending of the language defined
    switch (language) {
        case LANGUAGE_ENGLISH:
            gSPDisplayList(gDisplayListHead++, dl_menu_texture_course_upper);
            break;
        case LANGUAGE_FRENCH:
            gSPDisplayList(gDisplayListHead++, dl_menu_texture_niveau_upper);
            break;
        case LANGUAGE_GERMAN:
            gSPDisplayList(gDisplayListHead++, dl_menu_texture_kurs_upper);
            break;
    }

    gSPDisplayList(gDisplayListHead++, dl_menu_rgba16_wood_course_end);
#endif

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    int_to_str(gCurrCourseNum, courseNum);

    if (gCurrCourseNum < 10) { // 1 digit number
        print_hud_lut_string(HUD_LUT_GLOBAL, 152, 158, courseNum);
    } else { // 2 digit number
        print_hud_lut_string(HUD_LUT_GLOBAL, 143, 158, courseNum);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

#define ACT_NAME_X 163

/**
 * Print act selector strings, some with special checks.
 */
void print_act_selector_strings(void) {
#if MULTILANG
    unsigned char myScore[][10] = { {TEXT_MYSCORE}, {TEXT_MY_SCORE_FR}, {TEXT_MY_SCORE_DE} };
#else
    unsigned char myScore[] = { TEXT_MYSCORE };
#endif
    unsigned char starNumbers[] = { TEXT_ZERO };

#if MULTILANG
    u8 **levelNameTbl;
    u8 *currLevelName;
    u8 **actNameTbl;
#else
    u8 **levelNameTbl = segmented_to_virtual(seg2_course_name_table);
    u8 *currLevelName = segmented_to_virtual(levelNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum)]);
    u8 **actNameTbl = segmented_to_virtual(seg2_act_name_table);
#endif
    u8 *selectedActName;
#if !MULTILANG
    s16 lvlNameX;
    s16 actNameX;
#endif
    s8 i;
#if MULTILANG
    s16 language = eu_get_language();
#endif

    create_dl_ortho_matrix();

#if MULTILANG
    switch (language) {
        default:
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            levelNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            levelNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            levelNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
    currLevelName = segmented_to_virtual(levelNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum)]);
#endif


    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

#if MULTILANG
    print_generic_string(get_str_x_pos_from_center(160, (currLevelName + 3), 10.0f), 33, currLevelName + 3);
#else
    lvlNameX = get_str_x_pos_from_center(160, currLevelName + 3, 10.0f);
    print_generic_string(lvlNameX, 33, currLevelName + 3);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

#if MULTILANG
    print_course_number(language);
#else
    //print_course_number();
#endif

    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    // Print the name of the selected act.
    if (sVisibleStars != 0) {
        selectedActName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum) * 6 + sSelectedActIndex]);

#if MULTILANG
        print_menu_generic_string(get_str_x_pos_from_center(ACT_NAME_X, selectedActName, 8.0f), 81, selectedActName);
#else
        actNameX = get_str_x_pos_from_center(ACT_NAME_X, selectedActName, 8.0f);
        print_menu_generic_string(actNameX, 220, selectedActName);
#endif
    }

    // Print the numbers above each star.
    for (i = 1; i <= sVisibleStars; i++) {
        starNumbers[0] = i;
#if MULTILANG
        print_menu_generic_string(143 - sVisibleStars * 15 + i * 30, 38, starNumbers);
#else
        //print_menu_generic_string(139 - sVisibleStars * 17 + i * 34, 38, starNumbers);
#endif
    }

    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);
 }

/**
 * Geo function that Print act selector strings.
 */
Gfx *geo_act_selector_strings(s16 callContext, UNUSED struct GraphNode *node, UNUSED void *context) {
    if (callContext == GEO_CONTEXT_RENDER) {
        print_act_selector_strings();
    }
    return NULL;
}

/**
 * Initiates act selector values before entering a main course.
 * Also load how much stars a course has, without counting the 100 coin star.
 */
s32 lvl_init_act_selector_values_and_stars(UNUSED s32 arg, UNUSED s32 unused) {
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

    sLoadedActNum = 0;
    sInitSelectedActNum = 0;
    sVisibleStars = 0;
    sActSelectorMenuTimer = 0;
    sObtainedStars =
        save_file_get_course_star_count(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

    // Don't count 100 coin star
    if (stars & STAR_FLAG_ACT_100_COINS) {
        sObtainedStars--;
    }

    return 0;
}

/**
 * Loads act selector button actions with selected act value checks.
 * Also updates objects and returns act number selected after is chosen.
 */
s32 lvl_update_obj_and_load_act_button_actions(UNUSED s32 arg, UNUSED s32 unused) {
    if (sActSelectorMenuTimer > 10) {
        // If any of these buttons are pressed, play sound and go to course act
        if ((gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON | B_BUTTON | Z_TRIG))) {
            play_sound(SOUND_MENU_STAR_SOUND_LETS_A_GO, gGlobalSoundSource);
#if ENABLE_RUMBLE
            queue_rumble_data(60, 70);
            queue_rumble_decay(1);
#endif
            if (sInitSelectedActNum >= sSelectedActIndex + 1) {
                sLoadedActNum = sSelectedActIndex + 1;
            } else {
                sLoadedActNum = sInitSelectedActNum;
            }
            gDialogCourseActNum = sSelectedActIndex + 1;
        }
    }

    area_update_objects(); scroll_textures();
    sActSelectorMenuTimer++;
    Vec3f rotateCoords;
    star_select_update(rotateCoords, 0);
    return sLoadedActNum;
}

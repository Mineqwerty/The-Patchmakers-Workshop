#include <ultra64.h>

#include "sm64.h"
#include "rendering_graph_node.h"
#include "mario_misc.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"
#include "level_geo.h"
#include "src/game/game_init.h"
#include "src/game/level_update.h"
#include "levels/bbh/header.h"
#include "src/game/fb_effects.h"
#include "actors/extension_block/geo_header.h"
#include "levels/wdw/header.inc.h"
#include "src/game/emutest.h"

struct GraphNode *loopNode;
struct GraphNode *originalContinueNode;

/**
 * Geo function that generates a displaylist for environment effects such as
 * snow or jet stream bubbles.
 */
Gfx *geo_envfx_main(s32 callContext, struct GraphNode *node, Mat4 mtxf) {
    Vec3s marioPos;
    Vec3s camFrom;
    Vec3s camTo;
    void *particleList;
    Gfx *gfx = NULL;

    if (callContext == GEO_CONTEXT_RENDER && gCurGraphNodeCamera != NULL) {
        struct GraphNodeGenerated *execNode = (struct GraphNodeGenerated *) node;
        u32 *params = &execNode->parameter; // accessed a s32 as 2 u16s by pointing to the variable and
                                            // casting to a local struct as necessary.

        if (GET_HIGH_U16_OF_32(*params) != gAreaUpdateCounter) {
            s32 snowMode = GET_LOW_U16_OF_32(*params);

            vec3f_to_vec3s(camTo, gCurGraphNodeCamera->focus);
            vec3f_to_vec3s(camFrom, gCurGraphNodeCamera->pos);
            vec3f_to_vec3s(marioPos, gPlayerCameraState->pos);
            particleList = envfx_update_particles(snowMode, marioPos, camTo, camFrom);
            if (particleList != NULL) {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                gfx = alloc_display_list(2 * sizeof(*gfx));
                mtxf_to_mtx(mtx, mtxf);
                gSPMatrix(&gfx[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPBranchList(&gfx[1], VIRTUAL_TO_PHYSICAL(particleList));
                SET_GRAPH_NODE_LAYER(execNode->fnNode.node.flags, LAYER_OCCLUDE_SILHOUETTE_ALPHA);
            }
            SET_HIGH_U16_OF_32(*params, gAreaUpdateCounter);
        }
    } else if (callContext == GEO_CONTEXT_AREA_INIT) {
        // Give these arguments some dummy values. Not used in ENVFX_MODE_NONE
        vec3s_copy(camTo, gVec3sZero);
        vec3s_copy(camFrom, gVec3sZero);
        vec3s_copy(marioPos, gVec3sZero);
        envfx_update_particles(ENVFX_MODE_NONE, marioPos, camTo, camFrom);
    }

    return gfx;
}

/**
 * Geo function that generates a displaylist for the skybox. Can be assigned
 * as the function of a GraphNodeBackground.
 */
Gfx *geo_skybox_main(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *gfx = NULL;
    struct GraphNodeBackground *backgroundNode = (struct GraphNodeBackground *) node;

    if (callContext == GEO_CONTEXT_AREA_LOAD) {
        backgroundNode->unused = 0;
#ifndef L3DEX2_ALONE
    } else if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *camNode = (struct GraphNodeCamera *) gCurGraphNodeRoot->views[0];
        struct GraphNodePerspective *camFrustum =
            (struct GraphNodePerspective *) camNode->fnNode.node.parent;
        gfx = create_skybox_facing_camera(0, backgroundNode->background, camFrustum->fov, gLakituState.pos, gLakituState.focus);
#endif
    }

    return gfx;
}

Gfx *geo_zbuffer_clear(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        Gfx *dlHead = NULL;
        dl = alloc_display_list(14 * sizeof(*dl));
        dlHead = dl;
        gDPPipeSync(dlHead++);
        gDPSetRenderMode(dlHead++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCycleType(dlHead++, G_CYC_FILL);
        gDPSetDepthSource(dlHead++, G_ZS_PIXEL);
        gDPSetDepthImage(dlHead++, gPhysicalZBuffer);
        gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, gPhysicalZBuffer);
        gDPSetFillColor(dlHead++,
                        GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(dlHead++, 0, gBorderHeight, SCREEN_WIDTH - 1,
                        SCREEN_HEIGHT - 1 - gBorderHeight);
        gDPPipeSync(dlHead++);
        gDPSetCycleType(dlHead++, G_CYC_1CYCLE);
        gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                        gPhysicalFramebuffers[sRenderingFramebuffer]);
        gDPSetScissor(dlHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                  SCREEN_HEIGHT - gBorderHeight);
        gDPFullSync(dlHead++);
        gSPEndDisplayList(dlHead++);
    }
    return dl;
}

Gfx *geo_backdrop_move(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslation *) node->next)->translation[0] = gLakituState.pos[0];
        ((struct GraphNodeTranslation *) node->next)->translation[1] = gLakituState.pos[1];
        ((struct GraphNodeTranslation *) node->next)->translation[2] = gLakituState.pos[2];
    }
    return 0;
}

Gfx *geo_remove_cracked_wall(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER && gDestroyedCrackInReality) {
        ((struct GraphNodeTranslation *) node->next)->translation[0] = 0;
        ((struct GraphNodeTranslation *) node->next)->translation[1] = -18000;
        ((struct GraphNodeTranslation *) node->next)->translation[2] = 0;
    }
    return 0;
}

//am I REALLY going to write specific geo functions to cull level geometry in notoriously laggy spots...?

//OF COURSE I AM!
Gfx *geo_hide_ttc_patch_area_entrance(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gMarioState->pos[1] < 3532 && gMarioState->pos[0] < 5200) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_hide_ttc_grass_area(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gMarioState->pos[1] < 2770 && gMarioState->pos[2] < -7371) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_hide_ttc_start_grass_area(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gMarioState->pos[2] < -9355) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_hide_bubble_room(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        //in hvh library
        if (gMarioState->pos[0] > 3234) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_hide_hvh_room(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        //too low to see
        if (gMarioState->pos[1] < 1581) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        //far into vtw room
        else if (gMarioState->pos[0] < 800 && gMarioState->pos[2] > 2232) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_hide_vtw_room(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        //in hvh library
        if (gMarioState->pos[0] > 3389) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        //in hallway
        else if (gMarioState->pos[0] < -2520) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_corr_switch_full_fog_buildings(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gMarioState->pos[0] > -6040 && gMarioState->pos[0] < 11500 && gMarioState->pos[2] > -9180 && gMarioState->pos[2] < 6930) {
            node->next->flags |= GRAPH_RENDER_ACTIVE;
            node->next->next->flags |= GRAPH_RENDER_ACTIVE;
            node->next->next->next->flags &= ~GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
            node->next->next->flags &= ~GRAPH_RENDER_ACTIVE;
            node->next->next->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_update_road_depth(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        Gfx *mat = segmented_to_virtual(mat_bbh_dl_f3dlite_material_003_layer1);

	    align_st_to_cam(mat, 17);
    }
    return 0;
}

Gfx *geo_scale_portal(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        Vec3f portalPos;
        vec3f_set(portalPos, 0, 1065, 12889);
    
        f32 scale = 1.0f;
        f32 dist = 10000.0f;
        if (gMarioState) {
            vec3f_get_lateral_dist(portalPos, gMarioState->pos, &dist);
        

    

        if (dist < 600) {
            scale = 1.0f + 9.0f*(1 - (dist / 600.0f));
        }
    else {
       scale = 1.0f; 
    }
}
        ((struct GraphNodeScale *) node->next)->scale = scale;
    }
    return 0;
}

s32 renderThreshold = -5000;

Gfx *geo_start_loop(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gIsConsole) {
            renderThreshold = 2000;
            }
        
        //main level geo
        gLoopCounter = 4;
        geo_process_node_and_siblings(node->children);

        if (gCamera == NULL || gMarioState == NULL || gMarioState->levelInitTimer < 2) {
            return 0;
        }
        s16 fixedYaw = (s16)(gCamera->yaw + 0x8000);
        gLoopCounter = 0;
        if (gMarioState->pos[0] < -renderThreshold && gMarioState->pos[2] < -renderThreshold 
            && (gMarioState->pos[2] < -15000 || gMarioState->pos[0] < -15000 
                || (fixedYaw) < -0x2000 || fixedYaw > 0x6000)) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 1;
        if (gMarioState->pos[2] < -renderThreshold 
            && (gMarioState->pos[2] < -15000 
                || ((fixedYaw) < -0x2000 || (fixedYaw) > 0x2000))) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 2;
        if (gMarioState->pos[0] > renderThreshold && gMarioState->pos[2] < -renderThreshold 
            && (gMarioState->pos[2] < -15000 || gMarioState->pos[0] > 15000 
                || (fixedYaw) > 0x2000 || fixedYaw < -0x6000)) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 3;
        if (gMarioState->pos[0] < -renderThreshold
            && (gMarioState->pos[0] < -15000 
                || ((fixedYaw) < 0x2000 || (fixedYaw) > -0x6000))) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 5;
        if (gMarioState->pos[0] > renderThreshold
            && (gMarioState->pos[0] > 15000 
                || ((fixedYaw) < 0x6000 || (fixedYaw) > -0x6000))) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 6;
        if (gMarioState->pos[0] < -renderThreshold && gMarioState->pos[2] > renderThreshold
            && (gMarioState->pos[2] > 15000 || gMarioState->pos[0] < -15000 
            || (fixedYaw) > -0x6000 || fixedYaw < 0x2000)) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 7;
        if (gMarioState->pos[2] > renderThreshold
            && (gMarioState->pos[2] > 15000 
                || ((fixedYaw) > -0x6000 || (fixedYaw) < 0x6000))) {
            geo_process_node_and_siblings(node->children);
        }
        gLoopCounter = 8;

        //TFP theme transitions are scrapped for now
        /*
        //TFP TILES
        s8 themeTransition = -1;

        if (gTatumCount == 4650) {
            themeTransition = 1;
        }
        if (gTatumCount == 7777) {
            themeTransition = 2;
        }
        if (gTatumCount == 10315) {
            themeTransition = 3;
        }
        if (gTatumCount == 16820) {
            themeTransition = 0;
            gTatumCount = 0;
        }

        if (themeTransition >= 0) {
            extern const u8 tfp_tile_textures_dma[];
            extern u8 bbh_dl_tiles_rgba16[];

            u8 *tileTexture = segmented_to_virtual(&bbh_dl_tiles_rgba16);

            dma_read(tileTexture, (themeTransition*2048) + tfp_tile_textures_dma, (themeTransition*2048) + tfp_tile_textures_dma + 2048);

            set_fb_effect_type(FBE_EFFECT_MULT);
            set_motion_blur(255);
            set_fb_effect_col(255, 255, 255);
        }
        */

    }
    return 0;
}

Gfx *geo_loop_level(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {

        
            ((struct GraphNodeTranslation *) node->next->next->next)->translation[0] = ((gLoopCounter % 3) - 1) * 32762;
            ((struct GraphNodeTranslation *) node->next->next->next)->translation[2] = ((gLoopCounter / 3) - 1) * 32762;
    }
    return 0;
}

Gfx *geo_end_loop(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {

        if (gLoopCounter >= 8) {
            gLoopCounter = 0;
        }
    }
    return 0;
}

Gfx *geo_choose_tfp_draw(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        if (gLoopCounter != 4 || absf(gMarioState->pos[0]) > 8000 || absf(gMarioState->pos[2]) > 8000) {
            node->next->flags &= ~GRAPH_RENDER_ACTIVE;
            node->next->next->flags |= GRAPH_RENDER_ACTIVE;
        }
        else {
            node->next->next->flags &= ~GRAPH_RENDER_ACTIVE;
            node->next->flags |= GRAPH_RENDER_ACTIVE;
        }
    }
    return 0;
}

Gfx *geo_get_area_material_from_table(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        Gfx *dlHead = NULL;
        dl = alloc_display_list(2 * sizeof(*dl));
        dlHead = dl;
        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE); 

        Gfx *areaTable = gAreas[gCurrAreaIndex].materialTable;
        gSPDisplayList(dlHead++, ((Gfx**)areaTable)[obj->oMaterialIndex]);
        //gSPDisplayList(dlHead++, ((Gfx**)segmented_to_virtual(wdw_area_1_collision_materials))[0]);
	    gSPEndDisplayList(dlHead);
    }

    
    return dl;
}

Gfx *geo_get_area_revert_from_table(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        Gfx *dlHead = NULL;
        dl = alloc_display_list(2 * sizeof(*dl));
        dlHead = dl;
        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE); 

        Gfx *areaTable = gAreas[gCurrAreaIndex].materialTable;
        gSPDisplayList(dlHead++, ((Gfx**)areaTable)[obj->oRevertIndex]);
        //gSPDisplayList(dlHead++, ((Gfx**)segmented_to_virtual(wdw_area_1_collision_materials))[0]);
	    gSPEndDisplayList(dlHead);
    }

    
    return dl;
}

Gfx *geo_rotate_billboard(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
        Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;

    ((struct GraphNodeRotation *) node->next)->rotation[2] = obj->oTimer * 0x222;

    }
}
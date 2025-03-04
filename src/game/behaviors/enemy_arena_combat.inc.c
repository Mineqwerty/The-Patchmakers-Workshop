#include "levels/jrb/falling_stone_1/collision_header.h"
#include "levels/jrb/falling_stone_2/collision_header.h"
#include "levels/jrb/falling_stone_3/collision_header.h"
#include "levels/jrb/falling_stone_4/collision_header.h"
#include "levels/jrb/falling_stone_5/collision_header.h"
#include "levels/jrb/falling_stone_6/collision_header.h"
#include "levels/jrb/falling_stone_7/collision_header.h"
#include "src/game/camera.h"

void spawn_wave_enemy(BehaviorScript enemy, u32 model) {
    u16 randomSpot = random_u16();
    struct Object *waveObj = spawn_object_relative(0, 1500 * sins(randomSpot), 20, 1500 * coss(randomSpot), o, model, enemy);
    SET_BPARAM3(waveObj->oBehParams, 5);
}

void spawn_waves(u8 wave) {
    switch (wave) {
        case 1:
            spawn_wave_enemy(bhvGoomba, MODEL_YARN_GOOMBA);
            spawn_wave_enemy(bhvGoomba, MODEL_YARN_GOOMBA);
            spawn_wave_enemy(bhvGoomba, MODEL_YARN_GOOMBA);
            spawn_wave_enemy(bhvJellyfish, MODEL_JELLYFISH);
            o->oNumWaveEnemiesLeft = 4;
        break;
        case 2:
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            spawn_wave_enemy(bhvJellyfish, MODEL_JELLYFISH);
            spawn_wave_enemy(bhvGoomba, MODEL_YARN_GOOMBA);
            o->oNumWaveEnemiesLeft = 5;
        break;
        case 3:
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            spawn_wave_enemy(bhvJellyfish, MODEL_JELLYFISH);
            spawn_wave_enemy(bhvJellyfish, MODEL_JELLYFISH);
            spawn_wave_enemy(bhvJellyfish, MODEL_JELLYFISH);
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            spawn_wave_enemy(bhvYarnBlooper, MODEL_YARN_BLOOPER);
            o->oNumWaveEnemiesLeft = 6;
        break;
    }
}

void bhv_enemy_obelisk_loop() {

    f32 *dist;
    o->oNumWaveEnemiesLeft = count_objects_with_behavior_and_bparam_3(bhvGoomba, 5) + count_objects_with_behavior_and_bparam_3(bhvJellyfish, 5)  + count_objects_with_behavior_and_bparam_3(bhvYarnBlooper, 5);
    //dbp(o->oNumWaveEnemiesLeft); 

    switch (o->oAction) {
        //forcefield spawning
        case 0:
            if (o->oDistanceToMario < 500.0f && (gMarioState->action == ACT_WALKING || gMarioState->action == ACT_IDLE || gMarioState->action == ACT_WAITING_FOR_DIALOG)) {
                if (o->oDialogTrigger == 0) {
                    create_dialog_box_with_response(DIALOG_OBELISK);
                    gMarioState->action = ACT_WAITING_FOR_DIALOG;
                    o->oDialogTrigger = 1;
                }
                
            }
            else {
                o->oDialogTrigger = 0;
            }

            if (o->oDialogTrigger == 1 && gDialogResponse == DIALOG_RESPONSE_YES) {
                spawn_object(o, MODEL_NONE, bhvEnemyArenaCombatWalls);
                o->oAction = 10;
                gMarioState->action = ACT_IDLE;
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                gMarioState->action = ACT_IDLE;
            }
            load_object_collision_model();
        break;
        //wave 1 spawning
        case 1:
            spawn_waves(1);
            o->oAction++;
        break;
        //wave 1 happening
        case 2:
            if (o->oNumWaveEnemiesLeft <= 0) {
                o->oAction++;
            }
        break; 

        case 3:
            spawn_waves(2);
            o->oAction++;

        break;

        case 4:
            //print_text(20, 20, "wave 2");
            if (o->oNumWaveEnemiesLeft <= 0) {
                o->oAction++;
            }
        break; 

        case 5:
            spawn_waves(3);
            o->oAction++;

        break;

        case 6:
            //print_text(20, 20, "wave 3");
            if (o->oNumWaveEnemiesLeft <= 0) {
                o->oAction++;
            }
        break; 

        case 7:
            
            SET_BPARAM1(o->oBehParams, 4);
            spawn_default_star(o->oPosX + 300, o->oPosY + 300, o->oPosZ);
            o->oAction++;
        break;
        case 10:
            o->oPosY -= 15;
            if (o->oTimer % 4 == 0) {
                cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
            }

            if (o->oTimer == 85) {
                o->oAction = 1;
                cur_obj_hide();
                cur_obj_become_intangible();
                o->oPosY = o->oHomeY;
            }
        break;
    }

}

void bhv_falling_block_obelisk_loop(void) {
    switch (o->oAction) {
        //forcefield spawning
        case 0:
            if (o->oDistanceToMario < 500.0f && (gMarioState->action == ACT_WALKING || gMarioState->action == ACT_IDLE || gMarioState->action == ACT_WAITING_FOR_DIALOG)) {
                if (o->oDialogTrigger == 0) {
                    create_dialog_box_with_response(DIALOG_OBELISK);
                    gMarioState->action = ACT_WAITING_FOR_DIALOG;
                    o->oDialogTrigger = 1;
                }
                
            }
            else {
                o->oDialogTrigger = 0;
            }

            if (o->oDialogTrigger == 1 && gDialogResponse == DIALOG_RESPONSE_YES) {
                spawn_object(o, MODEL_FORCEFIELD, bhvEnemyForcefield);
                o->oAction++;
                gMarioState->action = ACT_IDLE;
            }
            else if (gDialogResponse == DIALOG_RESPONSE_NO) {
                gMarioState->action = ACT_IDLE;
            }
            load_object_collision_model();
        break;
        case 1:
            for (int i = 6; i >= 0; i--) {
                spawn_object_relative(i, 0, 5000 + (i*650), 0, o, MODEL_FALLING_STONE_BLOCK_1 + i, bhvFallingStoneBlock);
            }
            load_object_collision_model();
            o->oAction++;
        break;
        case 2: 
            o->oPosY -= 15;
            if (o->oTimer % 4 == 0) {
                cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
            }

            if (o->oTimer == 75) {
                //set_camera_mode(gMarioState->area->camera, CAMERA_MODE_SLIDE_HOOT, 1);
                gReonucamState.overhead = 1;
                o->oAction++;
                cur_obj_hide();
                o->oBlockShadow = spawn_object_abs_with_rot(o, 0, MODEL_FALLING_STONE_BLOCK_SHADOW, bhvFallingStoneBlockShadow, o->oHomeX, o->oHomeY, o->oHomeZ, 0, 0, 0);
            }
            load_object_collision_model();
        break;
        case 3:

            if (gMarioState->action == ACT_SQUISHED || gMarioState->pos[1] < o->oHomeY + (500 * (o->oBlockNum - 1))) {
                play_sound(SOUND_MARIO_ATTACKED, gMarioState->marioObj->header.gfx.cameraToObject);
                level_trigger_warp(gMarioState, WARP_OP_DEATH);
                    // woosh, he's gone!
                    set_mario_action(gMarioState, ACT_DISAPPEARED, 0);
                    o->oAction++;
            }

            if (o->oBlockNum == 7) {
                    spawn_arena_star_stc(o->oPosX + 300, o->oPosY + 200, o->oPosZ + 300);
                    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
                    gReonucamState.overhead = 0;
                    o->oAction++;
                }
        break;
    }
}

void bhv_falling_stone_block_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0: obj_set_collision_data(o, falling_stone_1_collision);
        break;
        case 1: obj_set_collision_data(o, falling_stone_2_collision);
        break;
        case 2: obj_set_collision_data(o, falling_stone_3_collision);
        break;
        case 3: obj_set_collision_data(o, falling_stone_4_collision);
        break;
        case 4: obj_set_collision_data(o, falling_stone_5_collision);
        break;
        case 5: obj_set_collision_data(o, falling_stone_6_collision);
        break;
        case 6: obj_set_collision_data(o, falling_stone_7_collision);
        break;
    }
    
}

void bhv_falling_stone_block_loop(void) {
    if (o->parentObj->oAction == 3) {
        if (o->parentObj->oBlockNum == o->oBehParams2ndByte) {
            stone_block_fall();
        }
    }

    //if the bparam of the object is within 1 of the block number, load the col model
    if (o->oBehParams2ndByte == o->parentObj->oBlockNum) {
        load_object_collision_model();
        //cur_obj_unhide();
    }
    else {
        //cur_obj_hide();
    }
}

void stone_block_fall(void) {
    o->oPosY -= 20.0f;
    if (o->oPosY - (o->parentObj->oHomeY + (o->oBehParams2ndByte * 500)) < 50.0f) {
        o->oPosY = (o->parentObj->oHomeY + (o->oBehParams2ndByte * 500));
        o->parentObj->oBlockNum++;
        obj_mark_for_deletion(o->parentObj->oBlockShadow);
        load_object_static_model();
        if (o->parentObj->oBlockNum != 7) {
        o->parentObj->oBlockShadow = spawn_object_abs_with_rot(o, 0, MODEL_FALLING_STONE_BLOCK_SHADOW, bhvFallingStoneBlockShadow, o->parentObj->oHomeX, o->parentObj->oHomeY + (o->parentObj->oBlockNum * 500), o->parentObj->oHomeZ, 0, 0, 0);
        o->parentObj->oBlockShadow->oBehParams2ndByte = o->parentObj->oBlockNum;
        }
    }
}

void bhv_falling_stone_block_shadow_loop(void) {
    if (o->oOpacity < 150) {
        o->oOpacity = o->oTimer;
    }
}

void bhv_forcefield_loop(void) {
    if (o->parentObj->oBlockNum == 7) {
        cur_obj_set_model(MODEL_FORCEFIELD_NO_INSIDE);
    }
}

Gfx *geo_switch_falling_block_shadow(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct Object *obj = (struct Object *) gCurGraphNodeObject;
    struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

    if (callContext == GEO_CONTEXT_RENDER) {

            switchCase->selectedCase = obj->oBehParams2ndByte;

    }

    return NULL;
}

#include "src/game/game_init.h"
#include "src/game/level_update.h"


#define POKEY_ACT_IDLE 0
#define POKEY_ACT_CHASE_MARIO 1
#define POKEY_ACT_BURROW 2
#define POKEY_ACT_GROUND_NEEDLES 3
#define POKEY_ACT_THROW_PARTS 4
#define POKEY_ACT_BURROW_DASH 5
#define POKEY_ACT_BURST_FROM_GROUND 6
#define POKEY_ACT_SCATTER 7
#define POKEY_ACT_STUNNED 8
#define POKEY_ACT_POP_UP 9
#define POKEY_ACT_DEATH 10
#define POKEY_ACT_CUTSCENE 11

static struct ObjectHitbox sPushpinPokeyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 2700,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sPushpinPokeySegmentHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sPushpinPokeyPushingHitbox = {
    /* interactType:      */ INTERACT_PUSH_OUT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sPushpinPokeyDisjointedHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 255,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 700,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void spawn_pokey_star(f32 x, f32 y, f32 z);

void pushpin_pokey_set_model() {
    switch (o->oCurrentNumSegments) {
        case 7:
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_PUSHPIN_POKEY_1];
        break;
        case 5:
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_PUSHPIN_POKEY_2];
        break;
        case 3:
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_PUSHPIN_POKEY_3];
        break;  
        case 1:
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_PUSHPIN_POKEY_SEGMENT_HEAD];
        break;
    }
    
}

void pushpin_pokey_idle(void) {
    o->oForwardVel = 0;
    o->oNumHitSegments = 0;
    object_step_without_floor_orient();

    obj_set_hitbox(o, &sPushpinPokeyHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    if (o->oTimer >= 60) {
        if (o->oCurrentNumSegments > 1) {
cur_obj_init_animation(0);
        o->oAction = POKEY_ACT_CHASE_MARIO;
    o->oGravity = 30.5f;
        }
        else {
            cur_obj_init_animation(0);
        pushpin_pokey_set_model();
        o->oAction = POKEY_ACT_DEATH;
        }
    
    }
}

void pushpin_pokey_chase_mario(void) {

    obj_set_hitbox(o, &sPushpinPokeyHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
    
    obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x1000);

    if (o->oForwardVel < 20.0f) {
        o->oForwardVel = 20.0f;
    }

    if ((o->oTimer % 60 - 4) == 0) {
        o->oForwardVel = 170.0f;
    }

    if (o->oTimer >= 200) {
        o->oAction = POKEY_ACT_BURROW;
        o->oTimer = 0;
    }

    object_step_without_floor_orient();
}

void pushpin_pokey_next_attack() {
    
    o->oNumUndergroundAttacks += 1;
    if (o->oNumUndergroundAttacks >= 3) {
        o->oNumUndergroundAttacks = 0;
        o->oAction = POKEY_ACT_BURST_FROM_GROUND;
        return;
    }
    else {
        cur_obj_become_tangible();
    }
    o->oNextPokeyAttack += ((random_u16() % 2) + 1);
    if (o->oNextPokeyAttack >= 3) {
        o->oNextPokeyAttack -= 3;
    }

    switch (o->oNextPokeyAttack) {
                    case 0:
                o->oAction = POKEY_ACT_GROUND_NEEDLES;
                break;
                case 1:
                o->oAction = POKEY_ACT_BURROW_DASH;
                break;
                case 2:
                o->oAction = POKEY_ACT_THROW_PARTS;
                break;
    }
}


void pushpin_pokey_burrow(void) {
    obj_set_hitbox(o, &sPushpinPokeyHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    switch (o->oSubAction) {
        case 0:
        cur_obj_init_animation(1);
        if (cur_obj_check_if_near_animation_end()) {
            o->oSubAction++;
            o->oTimer = 0;
            o->oCamFocus = spawn_object_relative(8, 0, 0, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
        }
        break;
        case 1:
            if (o->oTimer < 120) {
                s16 rotAmount = o->oTimer;
                if (rotAmount > 60) rotAmount = 60;
                o->oMoveAngleYaw += 0x30 * rotAmount;
                o->oPosY -= rotAmount * 0.8;

                if (o->oTimer % 4 == 0) {
                    cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
                }
                
            }
            else {
                o->oSubAction++;
                o->oTimer = 0;
                if (o->oCamFocus) obj_mark_for_deletion(o->oCamFocus);
            }
        break;
        case 2:
            if (o->oTimer > 40) {
                pushpin_pokey_next_attack();
                o->oTimer = 0;
            }

        break;

    }
}

void pushpin_pokey_ground_needles(void) {
    cur_obj_become_intangible();
    switch (o->oSubAction) {
        case 0:
            o->oCamFocus = spawn_object_relative(9, 0, 0, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
            o->oCamFocus->oMoveAngleYaw = obj_angle_to_object(o->oCamFocus, gMarioObject);
            switch (random_u16() % 3) {
                case 0:
                    o->oCamFocus->oPosX = -522;
                    o->oCamFocus->oPosY = 560;
                    o->oCamFocus->oPosZ = -3517;
                    break;
                case 1:
                    o->oCamFocus->oPosX = -1500;
                    o->oCamFocus->oPosY = 230;
                    o->oCamFocus->oPosZ = 1424;
                    break;
                case 2:
                    o->oCamFocus->oPosX = -6550;
                    o->oCamFocus->oPosY = 0;
                    o->oCamFocus->oPosZ = -300;
                break;
            }
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
            o->oSubAction++;
        break;
    }

    if (o->oTimer > 280) {
        if (o->oCamFocus) obj_mark_for_deletion(o->oCamFocus);
        pushpin_pokey_next_attack();
        o->oTimer = 0;
        pushpin_pokey_set_model();
        o->oPosX = gMarioState->pos[0];
        o->oPosZ = gMarioState->pos[2];
    }
}

void pushpin_pokey_throw_parts(void) {
    cur_obj_become_intangible();
    switch (o->oSubAction) {
        case 0:
            o->oCamFocus = spawn_object_relative(11, 0, 0, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
            o->oCamFocus->oPosX = 7200;
            o->oCamFocus->oPosY = 4500;
            o->oCamFocus->oPosZ = 1800;

            gSecondCameraFocus = o->oCamFocus;
            o->oSubAction++;
        break;
        case 1:
            if (o->oTimer > 280 - (10*(7 - o->oCurrentNumSegments))) {
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
                gReonucamState.overhead = 0;
                pushpin_pokey_next_attack();
            }
        break;
    }
}

void pushpin_pokey_burrow_dash(void) {
    cur_obj_become_intangible();
    Vec3f burstPositions[] = {
        {2878, 800, 3908},
        {10000, 1000, -3120},
        {-3780, 700, 7228},
        {-6800, 700, 6500},
        {-6300, 700, -6500}
    };
    Vec3f particlePositions[] = {
        {-347, 900, 1080},
        {5384, 1100, -3120},
        {-3780, 700, 8228},
        {-6800, 700, 2500},
        {-6300, 700, -1200}
    };
    int closestPoint = 0;
        int closestPointValue = 0x8000;
    switch (o->oSubAction) {
        case 0:
        case 2:
        case 4:
        cur_obj_init_animation_with_accel_and_sound(3, 10.0f);
        if (o->oTimer == 60) {
            gSecondCameraFocus = o;
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
        for (int i = 0; i < 5; i++) {
            f32 diffX = absf(gMarioState->pos[0] - burstPositions[i][0]);
            f32 diffY = absf(gMarioState->pos[1] - burstPositions[i][1]);
            f32 diffZ = absf(gMarioState->pos[2] - burstPositions[i][2]);

            f32 sum = diffX + diffY + diffZ;
            if (sum < closestPointValue) {
                closestPoint = i;
                closestPointValue = sum;
            }
        }
            o->oPosX = burstPositions[closestPoint][0];
            o->oPosY = burstPositions[closestPoint][1];
            o->oPosZ = burstPositions[closestPoint][2];
            o->oCamFocus = spawn_object_relative(10, 0, 0, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
            /*
            o->oCamFocus->oPosX = particlePositions[closestPoint][0];
            o->oCamFocus->oPosY = particlePositions[closestPoint][1];
            o->oCamFocus->oPosZ = particlePositions[closestPoint][2];
            */

           o->oCamFocus->oPosX = o->oPosX + (4000 * sins(o->oMoveAngleYaw));
           o->oCamFocus->oPosZ = o->oPosZ + (4000 * coss(o->oMoveAngleYaw));
           o->oCamFocus->oPosY = particlePositions[closestPoint][1];

            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
            o->oFaceAngleYaw = obj_angle_to_object(o, gMarioObject);
            o->oGravity = 0;
            o->oVelY = 0;
        }

        if (o->oTimer > 60 && o->oCamFocus) {
            o->oCamFocus->oPosX = o->oPosX + (4000 * sins(o->oMoveAngleYaw));
           o->oCamFocus->oPosZ = o->oPosZ + (4000 * coss(o->oMoveAngleYaw));
        }

        
        if (o->oTimer == 60) {
            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
            o->oFaceAngleYaw = obj_angle_to_object(o, gMarioObject);
            o->oForwardVel = 30.0f;
            //o->oMoveAnglePitch = 0x4000;
            o->oFaceAnglePitch = -2000;
            o->oVelY = 10.0f;
            o->oTimer = 0;
            o->oSubAction++;
        }

        if (o->oTimer % 3 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
        
        break;
        case 1:
        case 3:
        case 5:
        o->oForwardVel = 80.0f;
        o->oVelY -= 0.3f;
        o->oGravity = 0;
        //cur_obj_play_sound_2(SOUND_AIR_BLOW_WIND);
            cur_obj_move_using_fvel_and_gravity();

            if (o->oTimer == 1) {
                o->oFallingWind1 = spawn_object(o, MODEL_NONE, bhvPushpinPokeyDisjointedHitbox);
                obj_set_hitbox(o->oFallingWind1, &sPushpinPokeyDisjointedHitbox);
                
            }

            if (o->oFallingWind1) {
                o->oFallingWind1->oPosX = o->oPosX + ((457 * o->oCurrentNumSegments) * sins(o->oMoveAngleYaw));
                o->oFallingWind1->oPosZ = o->oPosZ + ((457 * o->oCurrentNumSegments) * coss(o->oMoveAngleYaw));
                o->oFallingWind1->oPosY = o->oPosY - 600.0f;
            }

            if (o->oTimer % 5 == 4) {
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }
            
            o->oFaceAnglePitch += 100;

            if (o->oCamFocus && o->oTimer == 60) {
                obj_mark_for_deletion(o->oCamFocus);
            }
            o->oSubAction = 5;
            if (o->oTimer == 90) {
                if (o->oSubAction == 5) {
                    set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
                }
            }

            if (o->oTimer > 120) {
                o->oSubAction = 6;
                o->oTimer = 0;
                if (o->oSubAction == 6) {
                    o->oFaceAnglePitch = 0;
                    pushpin_pokey_next_attack();
                }
            }
            
        break;
    }
}

void bhv_pushpin_pokey_disjointed_hitbox_loop(void) {
    cur_obj_become_tangible();
    obj_set_hitbox(o, &sPushpinPokeyDisjointedHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_BREAK_STONE_PATCH;
                 if (o->oInteractStatus != INT_STATUS_NONE) {
            o->oInteractStatus = INT_STATUS_NONE;
                 }
}

void pushpin_pokey_burst_from_ground(void) {
    obj_set_hitbox(o, &sPushpinPokeyHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
    o->oGravity = 3.5f;
    switch (o->oSubAction) {
        case 0:
        if (o->oTimer % 31 == 0) {
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            o->oPosY = gMarioState->pos[1] - 4000;
            o->oCamFocus = spawn_object_relative(12, (random_u16() / 32 - 1028), 3500, (random_u16() / 32 - 1028), o, MODEL_PUSHPIN_POKEY_SEGMENT_HEAD, bhvPushpinPokeyCameraFocus);
        }

        if (o->oTimer == 130) {
            o->oSubAction++;
            if (find_floor_height(o->oCamFocus->oPosX, o->oCamFocus->oPosY + 20000.0f, o->oCamFocus->oPosZ) > gMarioState->pos[1] + 600.0f || find_floor_height(o->oCamFocus->oPosX, o->oCamFocus->oPosY + 20000.0f, o->oCamFocus->oPosZ) < gMarioState->pos[1] - 600.0f) {
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            }
            else {
            o->oPosX = o->oCamFocus->oPosX;
            o->oPosZ = o->oCamFocus->oPosZ;
            }
        }

        break;
        case 1:
            o->oSubAction++;
            o->oCamFocus = spawn_object_relative(8, 0, 900, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
            o->oTimer = 0;
            o->oFaceAnglePitch = 0;
        break;
        case 2:

        if (o->oTimer % 3 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
            if (o->oTimer < 150) {
                cur_obj_init_animation(1);
            }
            else {
                o->oSubAction++;
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
                obj_become_tangible(o);
                o->oTimer = 0;
                if (o->oCamFocus) obj_mark_for_deletion(o->oCamFocus);
                if (gMarioState->curPatch == PATCH_STONE && calc_hor_dist(gMarioState->pos, &o->oPosVec) < 300.0f) {
                    o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
                    o->oAction = POKEY_ACT_SCATTER;
                }
            }
        break;
        case 3:
        o->oPosY += 130.0f - o->oTimer;
        if (o->oTimer % 5 == 4) {
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }
            if (o->oTimer > 40) {
                o->oAction = POKEY_ACT_IDLE;
                o->oTimer = 0;
                o->oVelY = 30.0f;
            }

        break;

    }
}

void pushpin_pokey_set_mario_style(void) {
    switch (random_u16() % 8) {
            case 0: set_mario_animation(gMarioState, MARIO_ANIM_SINGLE_JUMP);
            break;
            case 1: set_mario_animation(gMarioState, MARIO_ANIM_DOUBLE_JUMP_RISE);
            break;
            case 2: set_mario_animation(gMarioState, MARIO_ANIM_GROUND_POUND);
            break;
            case 3: set_mario_animation(gMarioState, MARIO_ANIM_FAST_LONGJUMP);
            break;
            case 4: set_mario_animation(gMarioState, MARIO_ANIM_DIVE);
            break;
            case 5: set_mario_animation(gMarioState, MARIO_ANIM_SLIDEFLIP);
            break;
            case 6: set_mario_animation(gMarioState, MARIO_ANIM_AIR_KICK);
            break;
            case 7: set_mario_animation(gMarioState, MARIO_ANIM_SLEEP_LYING);
            break;
        }
        //gMarioState->marioObj->header.gfx.animInfo.curAnim->flags |= ANIM_FLAG_NO_ACCEL;
}

void pushpin_pokey_scatter(void) {
    if (o->oNumHitSegments >= o->oCurrentNumSegments) {
        gMarioState->usedStonePatch = 0;
    }
    else {
        gMarioState->usedStonePatch = 2;
    }

    
/*
    if (o->oNumHitSegments == 0) {
        o->oCamFocus = spawn_object_relative(1, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_HEAD, bhvPushpinPokeySegment);
        o->oCamFocus->oPosX = gMarioState->pos[0];
        o->oCamFocus->oPosY = gMarioState->pos[1] - 100.0f;
        o->oCamFocus->oPosZ = gMarioState->pos[2];
        if (gMarioState->curPatch == PATCH_STONE) {
        gMarioState->vel[1] = 70.0f;
        gMarioState->pos[1] += 10.0f;
        pushpin_pokey_set_mario_style();
        cur_obj_play_sound_2(SOUND_ACTION_BONK);
        gMarioState->action = ACT_STONE_PATCH_AIRBORNE;
        }
        o->oNumHitSegments++;
    }
    */

    if (o->oTimer == 0) {
        for (int i = 0; i < o->oCurrentNumSegments; i++) {
            if (i == 0) {
                o->oCamFocus = spawn_object_relative(1, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_HEAD, bhvPushpinPokeySegment);
                o->oCamFocus->oPosX = gMarioState->pos[0];
                o->oCamFocus->oPosY = gMarioState->pos[1] - 100.0f;
                o->oCamFocus->oPosZ = gMarioState->pos[2];
                gMarioState->vel[1] = 70.0f;
        gMarioState->pos[1] += 10.0f;
                pushpin_pokey_set_mario_style();
        cur_obj_play_sound_2(SOUND_ACTION_BONK);
        gMarioState->action = ACT_STONE_PATCH_AIRBORNE;
            }
            else {
                o->oCamFocus = spawn_object_relative(1, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_BODY, bhvPushpinPokeySegment);
                o->oCamFocus->oPosX = gMarioState->pos[0];
                o->oCamFocus->oPosY = gMarioState->pos[1] - i * 600.0f;
                o->oCamFocus->oPosZ = gMarioState->pos[2];
            }
        }
    }

    if (gMarioState->curPatch != PATCH_STONE) {
        o->oAction = POKEY_ACT_STUNNED;
    }
    /*
    if (o->oTimer >= 30) {
        o->oTimer = 0;
        if (gMarioState->curPatch == PATCH_STONE) {
        o->oCamFocus = spawn_object_relative(1, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_BODY, bhvPushpinPokeySegment);
        o->oCamFocus->oPosX = gMarioState->pos[0];
        o->oCamFocus->oPosY = gMarioState->pos[1] - 100.0f;
        o->oCamFocus->oPosZ = gMarioState->pos[2];
        gMarioState->vel[1] = 70.0f;
        gMarioState->pos[1] += 10.0f;
        pushpin_pokey_set_mario_style();
        cur_obj_play_sound_2(SOUND_ACTION_BONK);
        gMarioState->action = ACT_STONE_PATCH_AIRBORNE;
        }
        else {
            o->oAction = POKEY_ACT_STUNNED;
        }
        o->oNumHitSegments++;
    }
    */

}

void pushpin_pokey_stunned(void) {

    switch (o->oSubAction) {
        case 0:
        play_secondary_music(SEQ_LADY_SECOND_PHASE, 0, 255, 10);
        if (gMarioState->curPatch != PATCH_STONE) {
            for (int i = 0; i < 3; i++) {
                o->oCamFocus = spawn_object_relative(i, 0, 0, 0, o, MODEL_ROSEDRIFT, bhvBounceRosedrift);
                o->oCamFocus->oPosX = gMarioState->pos[0] + (1250 * sins(gLakituState.yaw));
                o->oCamFocus->oPosZ = gMarioState->pos[2] + (1250 * coss(gLakituState.yaw));
                f32 floor = find_floor_height(gMarioState->pos[0], gMarioState->pos[1] + 200.0f, gMarioState->pos[2]);
                if (floor > -6000.0f) {
                    o->oCamFocus->oPosY = floor;
                }
                else {
                    o->oCamFocus->oPosY = gMarioState->pos[1];
                }
            }
            o->oSubAction++;
        }
        break;
        case 1:
            if (gMarioState->curPatch == PATCH_STONE && gMarioState->action == ACT_BOUNCED_ON_ROSEDRIFT && gMarioState->vel[1] < -5.0f) {
                o->oFallingWind1 = spawn_object(o, MODEL_FALLING_WIND, bhvStaticObject);
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 2:
            if (o->oFallingWind1) {
                o->oFallingWind1->oPosX = gMarioState->pos[0];
                 o->oFallingWind1->oPosY = gMarioState->pos[1] - 50.0f;
                  o->oFallingWind1->oPosZ = gMarioState->pos[2];
                  //o->oFallingWind1->oOpacity = 3;
                  o->oFallingWind1->oOpacity = -1 * (gMarioState->vel[1] / 3.0f) + (o->oTimer * 2);
                  if (o->oFallingWind1->oOpacity > 250) {
                    o->oFallingWind1->oOpacity = 250;
                  }

                  if (gSlowdownCount == 2 && o->oFallingWind1) {
                    obj_mark_for_deletion(o->oFallingWind1);
                    o->oSubAction++;
                  }
                  else if (gMarioState->action == ACT_STONE_PATCH_AIR_LAND) {
                    obj_mark_for_deletion(o->oFallingWind1);
                    o->oSubAction = 0;
                  }
            }
        break;
        case 3:
            o->oFallingWind1 = spawn_object(o, MODEL_IMPACT_HIT, bhvStaticObject);
            o->oFallingWind1->oPosX = gMarioState->pos[0];
                 o->oFallingWind1->oPosY = gMarioState->pos[1] - 10.0f;
                  o->oFallingWind1->oPosZ = gMarioState->pos[2];
                  o->oTimer = 0;
                  o->oCurrentNumSegments -= 2;
                  o->oSubAction++;
        break;
        case 4:

        obj_scale_xyz(o->oFallingWind1, 0.2f + ((f32) o->oTimer / 3.0f), 1.0f, 0.2f + ((f32) o->oTimer / 3.0f));
        o->oFallingWind1->oOpacity = 250 - (o->oTimer * 10);
        if (o->oTimer >= 25) {
           o->oFallingWind1->oOpacity = 0; 
        }
        cur_obj_shake_screen(SHAKE_POS_SMALL);
        if (o->oTimer == 90 && o->oFallingWind1) {
            obj_mark_for_deletion(o->oFallingWind1);
        }
        break;
    }
}

void pushpin_pokey_pop_up(void) {
    obj_set_hitbox(o, &sPushpinPokeyHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
    if (o->oFallingWind1) {
            obj_mark_for_deletion(o->oFallingWind1);
        }
    o->oGravity = 3.5f;
    switch (o->oSubAction) {
        case 0:
        if (o->oTimer == 1) {
            /*
            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LADY_FIRST_PHASE), 0);
            */
           o->oInteractType = INTERACT_PUSH_OUT;
           func_80321080(90);
        }
            if (o->oTimer >= 60) {
            o->oSubAction++;
            o->oTimer = 0;
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            o->oPosY = find_floor_height(o->oPosX, gMarioState->pos[1] + 4000, o->oPosZ) - (520 * (o->oCurrentNumSegments));
            o->oCamFocus = spawn_object_relative(8, 0, 900, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
            o->oTimer = 0;
            o->oFaceAnglePitch = 0;
            pushpin_pokey_set_model();
            }
        break;
        case 1:
        
        if (o->oTimer % 3 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
            if (o->oTimer < 30) {
                o->oPosY += 10.0f;
            }
            if (o->oTimer < 50) {
                cur_obj_init_animation(1);
            }
            else {
                o->oSubAction++;
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
                o->oTimer = 0;
                if (o->oCamFocus) obj_mark_for_deletion(o->oCamFocus);
            }
        break;
        case 2:
        o->oInteractType = INTERACT_DAMAGE;
        o->oPosY += 80.0f - o->oTimer;
        o->oFaceAngleYaw += 0x800;
        o->oMoveAngleYaw += 0x800;
        if (o->oTimer % 5 == 4) {
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }
            if (o->oTimer > o->oCurrentNumSegments * 8) {
                o->oAction = POKEY_ACT_IDLE;
                o->oTimer = 0;
                o->oVelY = 30.0f;
            }

        break;

    }
}

void pushpin_pokey_death(void) {
    switch (o->oSubAction) {
        case 0:
        set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
            gCamera->cutscene = 1;
            gLakituState.goalPos[0] = o->oPosX + (2000 * sins(o->oFaceAngleYaw));
           gLakituState.goalPos[2] = o->oPosZ + (2000 * coss(o->oFaceAngleYaw));
           gLakituState.goalPos[1] = o->oPosY + 300.0f;
           o->oPosY += 100.0f;
            
            o->oSubAction++;
        break;
        case 1:
            
           vec3f_copy(&gLakituState.goalFocus, &o->oPosVec);
           o->oMoveAngleYaw += 2048 - (o->oTimer * 20);
           o->oFaceAngleYaw += 2048 - (o->oTimer * 20);
            o->oFaceAngleRoll += 200;
           if (o->oTimer == 100) {
            spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
           }

           if (o->oTimer == 110) {
            gCamera->cutscene = 0;
            set_mario_action(gMarioState, ACT_IDLE, 0);
            spawn_pokey_star(o->oPosX, o->oPosY + 100, o->oPosZ);
            
           }

           if (o->oTimer == 115) {
            obj_mark_for_deletion(o);
           }
        break;
    }
}

void pushpin_pokey_cutscene(void) {
    if (o->oTimer == 0) {
        begin_cutscene_event(2);
        cur_obj_init_animation(1);
        o->oPosY -= 4000;
    }

    if (o->oTimer == 8) {
        o->oCamFocus = spawn_object_relative(8, 0, 900, 0, o, MODEL_NONE, bhvPushpinPokeyCameraFocus);
    }
    if (gCamera->cutscene == 0 && o->oTimer > 30) {
        o->oAction = POKEY_ACT_IDLE;
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LADY_FIRST_PHASE), 0);
    }

    if (o->oTimer == 190) {
        if (o->oCamFocus) obj_mark_for_deletion(o->oCamFocus);
    }

    if (o->oTimer >= 90 && o->oTimer < 190) {
        o->oFaceAngleYaw += 0x800;
        o->oMoveAngleYaw += 0x800;
        o->oPosY += 130.0f - o->oTimer + 90;
        if (o->oTimer % 5 == 4) {
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
        }
    }
    else if (o->oTimer < 90) {
        if (o->oTimer % 3 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
    }

    if (o->oTimer == 170) {
        seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LADY_INTRO), 0);
    }
    if (o->oTimer == 190) {
        o->oPosY = find_floor_height(o->oPosX, gMarioState->pos[1] + 1000, o->oPosZ);
    }

    if (o->oTimer == 240) {
        o->oMoveAngleYaw = -0x34C3;
        
    }


    if (o->oTimer == 390) {
        cur_obj_init_animation(4);
    }

    if (o->oTimer == 450) {
        cur_obj_init_animation(1);
    }
}


void bhv_pushpin_pokey_camera_focus_init(void) {
    switch(o->oBehParams2ndByte) {
        case 0:
    gSecondCameraFocus = o;
    gCamera->controlBossCameraYaw = 1;
    break;
    case 8:
        o->oPosY = find_floor_height(o->oPosX, gMarioState->pos[1] + 1000, o->oPosZ);
    break;
    case 9:
        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x1000);
    break;
    case 11:
    gSecondCameraFocus = o;
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    break;
    }
}


struct SpawnParticlesInfo sBurrowStones = {
    /* behParam:        */ 0,
    /* count:           */ 2,
    /* model:           */ MODEL_PEBBLE,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 40,
    /* forwardVelRange: */ 8,
    /* velYBase:        */ 20,
    /* velYRange:       */ 40,
    /* gravity:         */ -8,
    /* dragStrength:    */ 1,
    /* sizeBase:        */ 20.0f,
    /* sizeRange:       */ 7.0f,
};

struct SpawnParticlesInfo sBurrowMist = {
    2, 15, MODEL_MIST, 10.0f, -120, 0, 10, 0, 2, 10, 85.0f, 0.0f
};

void bhv_pushpin_pokey_camera_focus_loop(void) {
    switch(o->oBehParams2ndByte) {
        case 0:
    o->oPosX = gMarioState->pos[0];
    o->oPosY = gMarioState->pos[1] - 50;
    o->oPosZ = gMarioState->pos[2];
    gSecondCameraFocus = o;
    break;


    case 8:
    case 10:
    cur_obj_spawn_particles(&sBurrowStones);
    
    if (o->oTimer % 15 == 0) {
        set_camera_shake_from_point(SHAKE_POS_SMALL, o->oPosX, o->oPosY, o->oPosZ);
        cur_obj_spawn_particles(&sBurrowMist);
    }
    break;

    case 9:
        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x200);
        o->oForwardVel = 60.0f;
        obj_update_pos_vel_xz();
        f32 floorHeight = find_floor_height(o->oPosX, o->oPosY + 100, o->oPosZ);
        if (floorHeight > -2000.0f) {
        o->oPosY = floorHeight;
        }
        
        if (o->oTimer % 3 == 0) {
            cur_obj_spawn_particles(&sBurrowStones);
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
        if ((o->oTimer + 2) % 6 == 0) {
            cur_obj_spawn_particles(&sBurrowMist);
            set_camera_shake_from_point(SHAKE_POS_SMALL, o->oPosX, o->oPosY, o->oPosZ);
        }
        if (o->oTimer % 15 == 0) {
            spawn_object_relative(0, 0, -180, 0, o, MODEL_PUSHPIN, bhvPushpin);
            cur_obj_play_sound_1(SOUND_GENERAL_TOX_BOX_MOVE);
        }
    break;


    case 11:
        if (o->oTimer % 15 == 0 && (o->parentObj->oNumHitSegments + 1) < o->parentObj->oCurrentNumSegments) {
            spawn_object_relative(0, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_BODY, bhvPushpinPokeySegment);
            play_sound(SOUND_OBJ_EVIL_LAKITU_THROW, gGlobalSoundSource);
            o->parentObj->oNumHitSegments++;
        }
        else if ((o->parentObj->oNumHitSegments + 1) == o->parentObj->oCurrentNumSegments) {
            spawn_object_relative(0, 0, 0, 0, o, MODEL_PUSHPIN_POKEY_SEGMENT_HEAD, bhvPushpinPokeySegment);
            play_sound(SOUND_OBJ_EVIL_LAKITU_THROW, gGlobalSoundSource);
            set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
            gReonucamState.overhead = 3;
            o->parentObj->oNumHitSegments = 0;
            obj_mark_for_deletion(o);
            
        }

    break;

    case 12:
        //head poking up from ground

        obj_set_hitbox(o, &sPushpinPokeyPushingHitbox);
        o->oInteractStatus = 0;
        o->oIntangibleTimer = 0;

        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x1000);

        if (o->oTimer % 7 == 0) {
            cur_obj_spawn_particles(&sBurrowStones);
            cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
        }
        if ((o->oTimer + 2) % 12 == 0) {
            cur_obj_spawn_particles(&sBurrowMist);
            set_camera_shake_from_point(SHAKE_POS_SMALL, o->oPosX, o->oPosY, o->oPosZ);
        }
        if (o->oTimer == 5) {
            cur_obj_play_sound_1(SOUND_OBJ_KING_BOBOMB_JUMP);
        }

    if (o->oTimer < 10) {
        o->oPosY += 50 - o->oTimer * 2;
    }

    if (o->oTimer > 20) {
        o->oPosY -= 120 - o->oTimer * 2;
    }


        if (o->oTimer == 30) {
            obj_mark_for_deletion(o);
        }
    break;
    }
}

static struct ObjectHitbox sPushpinHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 180,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pushpin_init(void) {
    o->oFaceAnglePitch = (random_u16() - 0x8000) / 16.0f;
    o->oFaceAngleRoll = (random_u16() - 0x8000) / 16.0f;
    obj_set_hitbox(o, &sPushpinHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_BREAK_STONE_PATCH;
    o->oDamageOrCoinValue = 3;
}

void bhv_pushpin_loop(void) {
    if (o->oTimer < 3) {
        o->oPosY += 45.0f;
    }

    if (o->oTimer > 60) {
        o->oPosY -= 10.0f;
    }

    if (o->oTimer >= 120) {
        obj_mark_for_deletion(o);
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
}



void bhv_pushpin_pokey_segment_init(void) {
    o->oGravity = 1.5f;
    switch(o->oBehParams2ndByte) {
        case 0:
            
    o->oFaceAnglePitch = random_u16();
    o->oFaceAngleRoll = random_u16();
    o->oFaceAngleYaw = random_u16();
            o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
            o->oMoveAngleYaw += (random_u16() / 0x10) - 0x100;
            o->oVelY = 150.0f;
            o->oForwardVel = 10.0f;
            o->oFaceAngleYaw = o->oMoveAngleYaw;
        break;
    }
    
}

void bhv_pushpin_pokey_segment_loop(void) {
    f32 dist;
    struct Object *pokey = cur_obj_find_nearest_object_with_behavior(bhvPushpinPokey, &dist);
    
    switch(o->oBehParams2ndByte) {
        case 0:
        obj_set_hitbox(o, &sPushpinPokeySegmentHitbox);
        o->oInteractionSubtype = INT_SUBTYPE_BREAK_STONE_PATCH;
    obj_update_pos_vel_xz();
    o->oVelY -= 1.5f;
    o->oPosY += o->oVelY;
    o->oFaceAngleRoll += 0x800;
    o->oFaceAnglePitch += 0x800;
    //object_step_without_floor_orient();

    if (o->oTimer == 90 || (o->oTimer == 45 && gReonucamState.overhead == 1)) {
        o->oPosX = gMarioState->pos[0] + (random_u16() / 64) - 0x200;
        o->oPosZ = gMarioState->pos[2] + (random_u16() / 64) - 0x200;
        o->oPosY -= 2000.0f;
        o->oVelY = -9.5f;
        o->oForwardVel = 0.0f;
    }

    if (find_floor_height(o->oPosX, o->oPosY, o->oPosZ) > o->oPosY - 100.0f) {
        cur_obj_spawn_particles(&sBurrowStones);
        cur_obj_spawn_particles(&sBurrowMist);
    }

    if (o->oPosY < gMarioState->pos[1] - 600.0f) {
        obj_mark_for_deletion(o);
    }
    break;

    case 1:
        if (o->oTimer < (60 - (8 * (7 - o->parentObj->oCurrentNumSegments))) && o->oAction == 0) {
            o->oPosY += 66.0f; //- o->oTimer;

            if (cur_obj_has_model(MODEL_PUSHPIN_POKEY_SEGMENT_HEAD)) {
                gMarioState->pos[0] = o->oPosX;
                gMarioState->pos[1] = o->oPosY + 400.0f;
                gMarioState->pos[2] = o->oPosZ;

                gMarioState->vel[1] = 50.0f;
            }
        }
        //else if (o->oTimer == 60 && o->oAction == 0) {
        else if (o->oSubAction == 0 && o->oAction == 0) {
            o->oInteractionSubtype = INT_SUBTYPE_BULB;
            if (gMarioState->pos[1] - o->oPosY < 300.0f) {
            cur_obj_play_sound_2(SOUND_ACTION_BONK);
            o->oMoveAngleYaw = random_u16();
            o->oAngleVelYaw = random_u16() / 4.0f;
            o->oAngleVelRoll = random_u16() / 4.0f;
            o->oAngleVelPitch = random_u16() / 4.0f;
            o->oForwardVel = 90.0f * (1 + random_float());
            o->oVelY = -9.0f;
            o->oSubAction++;
            pokey->oNumHitSegments++;
            obj_update_pos_vel_xz();
            }
        }
        else {
            o->oFaceAngleYaw += o->oAngleVelYaw;
            o->oAngleVelYaw *= 0.8;
            o->oFaceAngleRoll += o->oAngleVelRoll;
            o->oAngleVelRoll *= 0.8;
            o->oFaceAnglePitch += o->oAngleVelPitch;
            o->oAngleVelPitch *= 0.8;
            if (o->oTimer <= 1500) {
            object_step_without_floor_orient();
            }
            o->oInteractionSubtype = INT_SUBTYPE_BULB;

            if (o->oInteractStatus != INT_STATUS_NONE && gMarioState->curPatch == PATCH_STONE) {
                gMarioState->vel[1] = 30.0f;
                gMarioState->forwardVel = -20.0f;
                //doesnt actually work
                /*
                if (gMarioState->action == ACT_BOUNCED_ON_ROSEDRIFT) {
                    o->oAction = 1;
                    o->oTimer = 0;
                    gMarioState->vel[1] = 0;
                    gSlowdownCount = 2;
                }
                */
            }
            else if (o->oInteractStatus != INT_STATUS_NONE && gMarioState->curPatch != PATCH_STONE) {
            o->oInteractStatus = INT_STATUS_NONE;
            }
        }

        if (o->oTimer > 110) {
            obj_set_hitbox(o, &sPushpinPokeySegmentHitbox);
        }
        if (o->oAction == 1) {
            gCamera->cutscene = 1;
            gLakituState.goalPos[0] += ((900  + gMarioState->pos[0] ) - gLakituState.goalPos[0]  ) / 5.0f;
            gLakituState.goalPos[1] += ( gMarioState->pos[1] + 200.0f - gLakituState.goalPos[1] ) / 20.0f;
            gLakituState.goalPos[2] += ((900  + gMarioState->pos[2] ) - gLakituState.goalPos[2]  ) / 5.0f;
         
            gLakituState.goalFocus[0] = gMarioState->pos[0];
            gLakituState.goalFocus[1] = gMarioState->pos[1];
            gLakituState.goalFocus[2] = gMarioState->pos[2];



            o->oFaceAngleYaw = 0;
            o->oFaceAnglePitch = 0;
            o->oFaceAngleRoll = 0;
            gMarioState->vel[1] = 0;
            gMarioState->pos[1] -= 8.0f;
            obj_scale_xyz(o, 1.0f, (f32) (30.0f - (f32) o->oTimer) / 30.0f, 1.0f);
            if (o->oTimer == 30) {
                gCamera->cutscene = 0;
                gSlowdownCount = 0;
                gMarioState->action = ACT_BACKFLIP;
                gMarioState->vel[1] = 70.0f;
                gMarioState->forwardVel = 40.0f;
                common_patch_cancel(gMarioState);
                gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
                obj_mark_for_deletion(o);
                o->parentObj->oAction = POKEY_ACT_POP_UP;
            }
        }
        else if (o->parentObj->oAction == POKEY_ACT_STUNNED) {
            if (o->oTimer > 1500) {
                o->oPosY -= 20.0f;
            }

            if (o->oTimer == 1590) {
                obj_mark_for_deletion(o);
                o->parentObj->oAction = POKEY_ACT_POP_UP;
            }
        }
        else if (o->parentObj->oAction != POKEY_ACT_SCATTER){
            obj_mark_for_deletion(o);
        }
    break;
    }
}

void bhv_pushpin_pokey_init(void) {
    o->oGravity = 30.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oCurrentNumSegments = 7;
    o->oNextPokeyAttack = (random_u16() % 3);

    o->oAction = POKEY_ACT_CUTSCENE;

    seq_player_lower_volume(SEQ_PLAYER_LEVEL, 2, 0);
            
}

void bhv_pushpin_pokey_loop(void) {
    
    if (o->oAction != POKEY_ACT_BURROW_DASH) {
        o->oFaceAngleYaw = o->oMoveAngleYaw;
    }


    switch (o->oAction) {
        case POKEY_ACT_IDLE:
            pushpin_pokey_idle();
            break;
        case POKEY_ACT_CHASE_MARIO:
            pushpin_pokey_chase_mario();
            break;
        case POKEY_ACT_BURROW:
            pushpin_pokey_burrow();
            break;
        case POKEY_ACT_GROUND_NEEDLES:
            pushpin_pokey_ground_needles();
            break;
        case POKEY_ACT_THROW_PARTS:
            pushpin_pokey_throw_parts();
            break;
        case POKEY_ACT_BURROW_DASH:
            pushpin_pokey_burrow_dash();
            break;
        case POKEY_ACT_BURST_FROM_GROUND:
            pushpin_pokey_burst_from_ground();
            break;
            case POKEY_ACT_SCATTER:
            pushpin_pokey_scatter();
            break;
            case POKEY_ACT_STUNNED:
            pushpin_pokey_stunned();
            break;
            case POKEY_ACT_POP_UP:
            pushpin_pokey_pop_up();
            break;
            case POKEY_ACT_DEATH:
            pushpin_pokey_death();
            break;
            case POKEY_ACT_CUTSCENE:
            pushpin_pokey_cutscene();
            break;
    }
}
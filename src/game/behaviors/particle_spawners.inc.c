#include "src/game/game_init.h"
#include "src/game/emutest.h"

static struct SpawnParticlesInfo sCrashingWaterParticles = {
    /* behParam:        */ 5,
    /* count:           */ 1,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 8,
    /* forwardVelRange: */ 4,
    /* velYBase:        */ 20,
    /* velYRange:       */ 15,
    /* gravity:         */ -3,
    /* dragStrength:    */ 0,
    /* sizeBase:        */ 50.0f,
    /* sizeRange:       */ 7.0f,
};

void bhv_particle_crashing_water_spawner_loop(void) {
    cur_obj_spawn_particles(&sCrashingWaterParticles);
}

void bhv_fire_smoke_spawner_loop(void) {

    u8 flameFrequency = 2;
    if (gIsConsole) {
        flameFrequency = 8;
    }

    if (o->parentObj && obj_has_behavior(o->parentObj, bhvHalo)) {
        flameFrequency /= 2;
        if (o->oTimer % flameFrequency == 0) {
        struct Object *flameParticle = spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
        flameParticle->oVelY = (random_u16() % 8 + 5) / 1.8f;
        flameParticle->oMoveAngleYaw = random_u16();
        flameParticle->oForwardVel = (random_u16() % 4) / 1.2f;
        }
    }
    else if (o->oTimer % flameFrequency == 0) {
        struct Object *flameParticle = spawn_object(o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
        flameParticle->oVelY = (random_u16() % 8 + 5) / 1.8f;
        flameParticle->oMoveAngleYaw = random_u16();
        flameParticle->oForwardVel = (random_u16() % 4) / 1.2f;
    }
}

void bhv_fire_smoke_init(void) {
    o->oBehParams2ndByte = random_u16() % 4 + 1;
    o->oGravity = 0;
    o->oFireSmokeScale = 1.0f - 0.002f * (random_u16() / 512);
    //o->oFaceAngleRoll = random_u16();
}

void bhv_fire_smoke_loop(void) {

    if (o->oTimer == 6) {
        //o->oBehParams2ndByte = random_u16() % 4 + 1;
    }

    if (o->oTimer == 45) {
        obj_mark_for_deletion(o);
    }

    cur_obj_scale(o->oFireSmokeScale * ((f32)(45 - o->oTimer)/45.0f));
    o->oForwardVel *= 0.98f;
    o->oVelY *= 1.01f;

    object_step();
}

void bhv_willowisp_loop(void) {

    if (o->oTimer < 30) {
        cur_obj_scale(7.0f * ((f32) o->oTimer) / 30.0f);
    }
    else {
        cur_obj_scale(7.0f);
    }


    if (o->oDistanceToMario < 300.0f) {
        for (int i = 0; i < 12; i++) {
            struct Object *flameSmoke = spawn_object_abs_with_rot(o->parentObj, 0, MODEL_FIRE_SMOKE, bhvFireSmokeParticle, o->oPosX, o->oPosY, o->oPosZ, 0, (0x1555 * i), 0);
            flameSmoke->oBehParams = 0x01000000;
            flameSmoke->oForwardVel = 10.0f;
            flameSmoke->oVelY = 4.0f;
        }
        o->parentObj->oCurrentWillOWisp = NULL;
        obj_mark_for_deletion(o);
    }
}

void bhv_willowisp_spawner_loop(void) {
    if (o->oBehParams2ndByte >= 1) {
        o->oPosX = gMarioState->pos[0];
                o->oPosY = gMarioState->pos[1];
                o->oPosZ = gMarioState->pos[2];
                if (o->oSpekturrSpawnOffsetValue == 0) {
                    o->oSpekturrSpawnOffsetValue = 120;
                }
                if (o->oTimer % o->oSpekturrSpawnOffsetValue == 0 && o->oSpekturrCount < 3) {
                    spawn_object_relative(o->oSpekturrSpawnBehParam++ % 4, (random_u16() % 512) - 256, 300.0f, (random_u16() % 512) - 256, o, MODEL_NONE, bhvSpekturr);
                    o->oSpekturrSpawnOffsetValue = (random_u16() % 30) + 20;
                    o->oSpekturrCount++;
                    o->oTimer = 0;
                }

                if (o->oSpekturrCount == 3) {
                    if (o->oBehParams2ndByte == 2) {
                        obj_mark_for_deletion(o);
                    }
                }
    }
    else {
    if (o->oTimer > 30 && o->oTimer % 60 == 0 && !o->oCurrentWillOWisp) {
                o->oPosX = gMarioState->pos[0];
                o->oPosY = gMarioState->pos[1];
                o->oPosZ = gMarioState->pos[2];
                f32 staticX = -7459;
                f32 staticZ = 9852; 
                f32 newX = o->oPosX + (staticX - o->oPosX)/2;
                f32 newZ = o->oPosZ + (staticZ - o->oPosZ)/2;
                f32 yHeight = find_floor_height(newX, o->oPosY + 2000, newZ) + 150.0f;
                o->oCurrentWillOWisp = spawn_object_abs_with_rot(o, 0, MODEL_GREY_FLAME, bhvWillOWisp, newX, yHeight, newZ, 0, 0, 0);
            }
    }
}

Gfx *geo_switch_fire_smoke(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct Object *obj = (struct Object *) gCurGraphNodeObject;
    struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

    if (callContext == GEO_CONTEXT_RENDER) {

            switchCase->selectedCase = obj->oBehParams2ndByte;

    }

    return NULL;
}

void bhv_ring_fragment_particle_init(void) {
    o->oFaceAngleYaw = random_u16();
   o->oFaceAnglePitch = random_u16();
   o->oFaceAngleRoll = random_u16();
   o->oAngleVelYaw = random_u16() / 128 + 0x200 * random_sign();
   o->oAngleVelPitch = random_u16() / 128 + 0x200 * random_sign();
   o->oAngleVelRoll = random_u16() / 128 + 0x200 * random_sign();
   o->oVelY = (random_float() * 15.0f) - 7.5f;
   o->oForwardVel = (random_float() * 30.0f) - 15.0f;
   o->oMoveAngleYaw = random_u16();
}

void bhv_ring_fragment_particle_loop(void) {


    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAnglePitch += o->oAngleVelPitch;
    o->oFaceAngleRoll += o->oAngleVelRoll;

    o->oPosY += o->oVelY;

   if (o->oTimer >= 15) {
    cur_obj_scale(((f32)(30 - o->oTimer)) / 15.0f);
   }

   if (o->oTimer == 29) {
    obj_mark_for_deletion(o);
   }
}

void bhv_shadowchomp_particle_init(void) {
    o->oBehParams2ndByte = random_u16() % 4 + 1;
    o->oGravity = 0;
    o->oFireSmokeScale = 1.0f - 0.002f * (random_u16() / 512);
}

void bhv_shadowchomp_particle_loop(void) {
    if (o->oTimer < 2) {
        cur_obj_scale(o->oFireSmokeScale * ((f32)(o->oTimer)/2.0f));
    }
    else {
        cur_obj_scale(o->oFireSmokeScale * ((f32)(47 - o->oTimer)/45.0f));
    }

    if (o->oTimer == 45) {
        obj_mark_for_deletion(o);
    }

    
    o->oForwardVel *= 0.98f;
    o->oVelY *= 1.1f;

    object_step();
}


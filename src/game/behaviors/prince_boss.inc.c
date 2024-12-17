#include "src/game/cutscene.h"

enum PrinceActions {
    PRINCE_ACT_CUTSCENE,
    PRINCE_ACT_IDLE,
    PRINCE_ACT_TELEPORT,
    PRINCE_ACT_URCHIN_CIRCLE,
    PRINCE_ACT_DASH_FORWARD,
    PRINCE_ACT_BARRAGE,
    PRINCE_ACT_SHOCK_WAVES,
    PRINCE_ACT_LASER,
    PRINCE_ACT_MELT_ATTACK
};

enum PrinceAnimations {
    PRINCE_ANIM_IDLE,
    PRINCE_ANIM_WAVE
};

void prince_act_cutscene(void) {
    

    switch (o->oSubAction) {
        case 0:
            if (o->oDistanceToMario < 1000) {
                //begin_cutscene_event(CUTSCENE_EVENT_PRINCE_INTRO);
                o->oAction = PRINCE_ACT_IDLE;
                o->oSubAction++;
            }
            
        break;
    }
}

void prince_act_idle(void) {
    o->oSubAction = 0;
    if (o->oTimer == 30) {
        o->oAction = PRINCE_ACT_URCHIN_CIRCLE;
    }
}

f32 princeTeleportSpots[4][2] = {{4050, 0}, {0, 4050}, {-4050, 0}, {0, -4050}};

void prince_warp_to_teleport_spot(void) {
    o->oPosX = princeTeleportSpots[o->oLastTeleportIndex][0];
    o->oPosZ = princeTeleportSpots[o->oLastTeleportIndex][1];
}

void prince_act_teleport(void) {
    switch(o->oSubAction) {
        case 0:
            obj_scale_xyz(o, 1.0f - (f32)o->oTimer/15.0f, 1.0f + (f32)o->oTimer/15.0f, 1.0f - (f32)o->oTimer/15.0f);
            if (o->oTimer == 14) {
                cur_obj_hide();
                for (int i = 0; i < 3; i++) {
                    spawn_object_relative(0, random_u16()%500 - 250, random_u16()%250, random_u16()%500 - 250, o, MODEL_JELLYFISH, bhvJellyfish);
                }
                o->oTimer = 0;
                o->oLastTeleportIndex = (o->oLastTeleportIndex + 1 + random_u16()%3)%4;
                prince_warp_to_teleport_spot();
                o->oSubAction++;
            }
        break;
        case 1:
            if (o->oTimer > 0) {
                obj_scale_xyz(o, (f32)o->oTimer/15.0f, 2.0f - (f32)o->oTimer/15.0f, (f32)o->oTimer/15.0f);
                cur_obj_unhide();
            }
            if (o->oTimer == 15) {
                o->oAction = PRINCE_ACT_IDLE;
                cur_obj_scale(1.0f);
            }
        break;
    }
}

void prince_act_urchin_circle(void) {

    obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);

    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(PRINCE_ANIM_WAVE);

            if (o->oTimer == 20) {
                for (int i = 0; i < 8; i++) {
                    struct Object *urchin = spawn_object_relative(0, 900*sins(i * 0x1FFF), 0, 900*coss(i * 0x1FFF), gMarioState->marioObj, MODEL_ABYSS_URCHIN, bhvAbyssUrchin);
                    urchin->oPosY = gMarioState->floorHeight;
                    o->oTimer = 0;
                }
                o->oSubAction++;
            }
            
        break;
        case 1:
            if (o->oTimer == 10) {
                struct Object *jelly = spawn_object_relative(0, 0, 0, 0, gMarioState->marioObj, MODEL_JELLY_SURROUND_CIRCLE, bhvJellySurroundCircle);
                jelly->oPosY = gMarioState->floorHeight;
                o->oSubAction++;
                o->oTimer = 0;
            }

            
        break;
        case 2:
            o->oPosY += o->oTimer + 10.0f;

            if (o->oTimer == 90) {
                o->oSubAction++;
                cur_obj_hide();
                o->oLastTeleportIndex = (o->oLastTeleportIndex + 1 + random_u16()%3)%4;
                prince_warp_to_teleport_spot();
                o->oPosY = gMarioState->floorHeight + 2000;
            }
        break;
        case 3:;
            f32 dist;
            struct Object *jellyWall = cur_obj_find_nearest_object_with_behavior(bhvJellySurroundCircle, &dist);

            if (!jellyWall) {
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 4:
            cur_obj_unhide();
            o->oPosY -= 100.0f - o->oTimer;
            if (o->oTimer == 75) {
                o->oAction = PRINCE_ACT_IDLE;
            }
        break;
    }
}

void bhv_prince_boss_init(void) {
    o->oLastTeleportIndex = 0;
}

void bhv_prince_boss_loop(void) {
    switch (o->oAction) {
        case PRINCE_ACT_CUTSCENE:
            prince_act_cutscene();
        break;
        case PRINCE_ACT_IDLE:
            prince_act_idle();
        break;
        case PRINCE_ACT_TELEPORT:
            prince_act_teleport();
        break;
        case PRINCE_ACT_URCHIN_CIRCLE:
            prince_act_urchin_circle();
        break;
    }
}


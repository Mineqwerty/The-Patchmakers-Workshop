#include "src/game/obj_behaviors.h"

struct SpawnParticlesInfo sSpekturrMist = {
    2, 15, MODEL_MIST, 0.0f, -30, 0, 10, 0, 2, 10, 8.0f, 3.0f
};

struct SpawnParticlesInfo sSpekturrEmergeMist = {
    2, 10, MODEL_MIST, 20.0f, -4, 0, 30, 0, 2, 10, 20.0f, 10.0f
};

static struct ObjectHitbox sSpekturrHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 2,
    /* numLootCoins:      */ 0,
    /* radius:            */ 72,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 70,
};

static u8 sSpekturrAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

s16 object_step_without_floor_orient();

void bhv_spekturr_loop(void) {
    o->oGravity = 0;
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 10 || o->oTimer == 20 || o->oTimer == 30) {
                cur_obj_spawn_particles(&sSpekturrMist);
                cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1_LOWPRIO);
            }
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);

            if (o->oTimer == 40) {
                o->oAction = 1;
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_SPEKTURR];
                cur_obj_spawn_particles(&sSpekturrEmergeMist);
                if (gDialogID == -1) {
                    create_automatic_dialog_box(39 + gMarioState->dialogStoryNum);
                    gMarioState->dialogStoryNum++;
                    if (gMarioState->dialogStoryNum == 10) {
                        gMarioState->dialogStoryNum = 0;
                    }
                }
            }
        break;
        case 1:
            o->oVelY = 20.0f;
            if (o->oTimer == 10) {
                o->oAction = 2;
            }
        break;
        case 2:
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);

            approach_f32_asymptotic_bool(&o->oPosX, gMarioState->pos[0] + 300 * sins((o->oBehParams2ndByte * 0x6000) + 0x200*(gGlobalTimer)), 0.07f);
            approach_f32_asymptotic_bool(&o->oPosZ, gMarioState->pos[2] + 300 * coss((o->oBehParams2ndByte * 0x6000) + 0x200*(gGlobalTimer)), 0.07f);
            approach_f32_asymptotic_bool(&o->oPosY, gMarioState->pos[1] + 100 * sins(o->oTimer * 0x400), 0.2f);

            if (o->oTimer % 25 == 0) {
                struct Object *flame = spawn_object_relative(0, 0, 0, 0, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flame->oBehParams = 0x01000000;
            }

            if (o->oTimer >= 240) {
                //o->oHealth = 0;
                //obj_die_if_health_non_positive();
            }
        break;
        case 3:
            o->oGravity = 1.0f;
            o->oFaceAngleYaw += 0x100;
            o->oFaceAngleRoll += 0x200;
            o->oFaceAnglePitch += 0x330;
            if (o->oTimer == 60) {
                o->oHealth = 0;
                obj_die_if_health_non_positive();
            }
        break;
    }

    if (o->oAction != 0 && obj_handle_attacks(&sSpekturrHitbox, 3, sSpekturrAttackHandlers)) {
            o->oAction = 3;
            o->oVelY = 20.0f;
        } 

    
    object_step_without_floor_orient();
}
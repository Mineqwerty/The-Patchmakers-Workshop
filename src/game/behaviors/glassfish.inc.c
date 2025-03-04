static struct ObjectHitbox sGlassfishHitbox = {
    /* interactType:      */ INTERACT_SPINY_WALKING,
    /* downOffset:        */ 75,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 70,
};

static u8 sGlassfishAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_glassfish_init(void) {
    obj_set_hitbox(o, &sGlassfishHitbox);
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oGlassfishMouthObj =
                spawn_object_relative(0, 0, 0, 0, o, MODEL_BLUE_COIN, bhvCoinInsideBoo);
            break;
        case 3:
        case 4:
        case 5:
            o->oGlassfishMouthObj = spawn_object_relative(o->oBehParams2ndByte + 1, 0, 0, 0, o,
                                                          MODEL_GLASSFISH, bhvGlassfish);
            cur_obj_scale(4.0f - (o->oBehParams2ndByte - 3));
            break;
        case 6:
            o->oGlassfishMouthObj = spawn_object_relative(0, 0, 0, 0, o, MODEL_STAR, bhvGlassfishStar);
            break;
    }

    if (o->parentObj != o && obj_has_behavior(o->parentObj, bhvGlassfish)) {
        o->oAction = 3;
    }

    o->oGravity = 0;
    o->oDragStrength = 0;
    o->oFriction = 0;
    o->oHomeX = o->oPosX;
    o->oHomeZ = o->oPosZ;
}

void bhv_glassfish_loop(void) {

    if (o->oTimer > 60
        && o->oDistanceToMario
               < (300 * (o->oBehParams2ndByte >= 3 ? 4 - (o->oBehParams2ndByte - 3) : 1))
        && gMarioState->action == ACT_MARINE_PATCH_SPIN && o->oAction != 3) {
        if (o->oGlassfishMouthObj) {
            o->oGlassfishMouthObj->parentObj = NULL;
        }
        spawn_triangle_break_particles(20, MODEL_SL_CRACKED_ICE_CHUNK, 3.0f, 0);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        o->oAction = 2;
        cur_obj_init_animation(1);
        gMarioState->forwardVel = -25.0f;
        gMarioState->vel[1] = -25.0f;
        gMarioState->action = ACT_BACKWARD_WATER_KB;
    }
    
    o->oInteractStatus = 0;

    switch (o->oAction) {
        case 0:
            approach_f32_symmetric_bool(&o->oForwardVel, 15.0f, 1.0f);
            
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX), 320);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            o->oFaceAnglePitch = o->oMoveAnglePitch;
            if (o->oDistanceToMario < 3000.0f) {
                o->oAction = 1;
            }

            object_step_no_water_particles();
            break;
        case 1:
            o->oMoveAnglePitch = CLAMP(obj_turn_pitch_toward_mario(120.0f, 0), -0x7000, 0x7000);
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            approach_f32_symmetric_bool(&o->oForwardVel, 15.0f, 1.0f);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            o->oFaceAnglePitch = o->oMoveAnglePitch;
            o->oVelY = -(o->oMoveAnglePitch / 512);
            object_step_no_water_particles();

            if (o->oDistanceToMario > 3500.0f) {
                o->oAction = 0;
            }
            break;
        case 2:
            o->oForwardVel = -15.0f;
            if (o->oTimer == 45) {
                spawn_mist_particles_variable(0, 0, 46.0f);
                create_sound_spawner(SOUND_OBJ_ENEMY_DEATH_HIGH);
                obj_mark_for_deletion(o);
            }
            break;

        case 3:
            if (!o->parentObj) {
                o->oAction = 0;
                o->oForwardVel = -160.0f;
                o->oVelY = random_u16() % 128 - 64;
            } else {
                o->oPosX = o->parentObj->oPosX;
                o->oPosY = o->parentObj->oPosY;
                o->oPosZ = o->parentObj->oPosZ;
                o->oFaceAnglePitch = o->parentObj->oFaceAnglePitch;
                o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;
                o->oFaceAngleRoll = o->parentObj->oFaceAngleRoll;
            }
            break;
    }
}

void bhv_glassfish_star_init(void) {

}

void bhv_glassfish_star_loop(void) {
    if (o->oAction == 0) {
        if (!o->parentObj) {
            o->oAction = 1;
            o->oTimer = 0;
        } else {
            o->oPosX = o->parentObj->oPosX;
            o->oPosY = o->parentObj->oPosY;
            o->oPosZ = o->parentObj->oPosZ;
            o->oFaceAnglePitch = o->parentObj->oFaceAnglePitch;
            o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;
            o->oFaceAngleRoll = o->parentObj->oFaceAngleRoll;
        }
    }

    if (o->oAction == 1 && o->oTimer == 30) {
        SET_BPARAM1(o->oBehParams, 5);
        spawn_default_star(-11600.0f, -700.0f, -9055.0f);
        obj_mark_for_deletion(o);
    }
}

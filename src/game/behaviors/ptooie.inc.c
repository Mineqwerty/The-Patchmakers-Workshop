static struct ObjectHitbox sPtooieHitbox = {
    /* interactType:      */ INTERACT_SPINY_WALKING,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 72,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 70,
};

static u8 sPtooieAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_ptooie_init(void) {
    o->oSpikeBall = spawn_object_relative_with_scale(1, 0, 210, 0, 0, o, MODEL_SPIKE_BALL, bhvSpikeBall);
    obj_set_hitbox(o, &sPtooieHitbox);
}

void bhv_ptooie_loop(void) {

    if ((o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
        return;
    }

    o->oPtooieMarioRangeDist = sqr(o->oPosX - gMarioState->pos[0]) + sqr(o->oPosZ - gMarioState->pos[2]);

    switch (o->oAction) {
        case 0:
            if (o->oSpikeBall && sins(o->oTimer * 0x888) < -0.8f) {
                cur_obj_spawn_weak_wind_particles(1, 1.5f, 0.0f, 120.0f, 0.0f);
                cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
            }

            if (o->oTimer >= 60 && o->header.gfx.animInfo.animFrame == 28 && !o->oSpikeBall && !(o->activeFlags & ACTIVE_FLAG_FAR_AWAY)) {
                o->oSpikeBall = spawn_object_relative_with_scale(1, 0, 210, 0, 0, o, MODEL_SPIKE_BALL, bhvSpikeBall);
                o->oTimer = 0;
            }

            if (o->oPtooieMarioRangeDist < sqr(3000.0f) && absf(o->oPosY - gMarioState->pos[1]) < 3000.0f) {
                obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x400);
            }
            //check for xz distance, y distance, action is 0, and spike ball exists
            if (o->oPtooieMarioRangeDist < sqr(2000.0f) && gMarioState->pos[1] - o->oPosY < 200.0f && o->oAction != 1 && o->oSpikeBall) {
                cur_obj_init_animation(1);
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oSpikeBall && o->header.gfx.animInfo.animFrame == 15) {
                o->oSpikeBall->oAction = 1;
                o->oSpikeBall->oForwardVel = 20.0f;
                o->oSpikeBall->oVelY = 5.0f;
                o->oSpikeBall->oTimer = 0;
                o->oSpikeBall = NULL;
            }
            if (o->header.gfx.animInfo.animFrame >= 15 && o->header.gfx.animInfo.animFrame < 21) {
                cur_obj_spawn_weak_wind_particles(30, 2.5f, 0.0f, 120.0f, 0.0f);
                cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
            }
            if (o->header.gfx.animInfo.animFrame > 28) {
                cur_obj_init_animation(0);
                o->oAction = 0;
            }

            
            break;
    }

    if (obj_handle_attacks(&sPtooieHitbox, 0, sPtooieAttackHandlers)) {
        if (o->oSpikeBall) {
            obj_mark_for_deletion(o->oSpikeBall);
        }            
            obj_die_if_health_non_positive();
        } 
}

static struct ObjectHitbox sSpikeBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_spike_ball_init(void) {
    o->oGravity = 1.5f;
    o->oFriction = 0.9f;
    o->oBuoyancy = 2.0f;
    o->oForwardVel = 0;
    o->oWallHitboxRadius = 30;
    obj_set_hitbox(o, &sSpikeBallHitbox);
}

void bhv_spike_ball_loop(void) {

    //if (o->activeFlags & (ACTIVE_FLAG_FAR_AWAY)) {
        //o->oPosY = o->parentObj->oPosY + 210;
        //return o->oTimer = 0;
    //}

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
    switch (o->oAction) {
        case 0:
        if (o->oTimer <= 10) {
                
                obj_scale(o, (f32) (o->oTimer) / 10.0f);
        }

        if (o->parentObj->oHealth == -1) {
            obj_mark_for_deletion(o);
        }
            o->oPosY += 16.0f * sins(o->oTimer * 0x888);
            o->oFaceAngleYaw += 0x100;
            o->oFaceAngleRoll += 0x80;
            o->oFaceAnglePitch += 0x130;
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x400);
            break;
        case 1:
            object_step_without_floor_orient();
            o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f / 1.5f));
            if (o->oForwardVel < 0.3f) {
                if (o->oTimer > 10) {
                    o->oTimer = 0;
                }
                o->oForwardVel = 0.0f;
                obj_scale(o, (f32) (10 - o->oTimer) / 10.0f);
                if (o->oTimer == 10) {
                obj_mark_for_deletion(o);
                }
            }

            if (o->oTimer > 150) {
                o->oForwardVel = 0;
            }
            break;
    }
}
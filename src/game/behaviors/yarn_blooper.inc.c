enum BlooperActions {
    BLOOPER_ACT_WAIT_FOR_MARIO_CLOSE,
    BLOOPER_ACT_DRIFT_TOWARDS_MARIO,
    BLOOPER_ACT_FALL_ON_MARIO,
    BLOOPER_ACT_DISPERSE_AFTER_FALL
};

static struct ObjectHitbox sBlooperHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 3,
    /* numLootCoins:      */ 3,
    /* radius:            */ 80,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 190,
};

static u8 sBlooperAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_yarn_blooper_init(void) {

}

void bhv_yarn_blooper_loop(void) {
    switch (o->oAction) {
        case BLOOPER_ACT_WAIT_FOR_MARIO_CLOSE:
            if (o->oDistanceToMario < 2000) {
                o->oAction = BLOOPER_ACT_DRIFT_TOWARDS_MARIO;
            }
        break;
        case BLOOPER_ACT_DRIFT_TOWARDS_MARIO:
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x50);

            o->oForwardVel = 4.0f;
            o->oVelY -= 1.0f;
            if (o->oVelY < -10.0f) {
                o->oVelY = -10.0f;
            }

            if (o->oTimer % 60 == 0) {
                o->oVelY = 25.0f - ((f32)absf(o->oPosY - o->oHomeY) / 200.0f);
            }
            o->oPosY += o->oVelY;
            cur_obj_move_xz_using_fvel_and_yaw();
            f32 dist;
            vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
            if (dist < 100 && ((o->oPosY + 100) > gMarioState->pos[1])) {
                o->oAction = BLOOPER_ACT_FALL_ON_MARIO;
            }
            if (o->oDistanceToMario > 2100) {
                o->oAction = BLOOPER_ACT_DRIFT_TOWARDS_MARIO;
            }
        break;
        case BLOOPER_ACT_FALL_ON_MARIO:
            if (o->oPosY < gMarioState->pos[1]) {
                o->oAction = BLOOPER_ACT_DISPERSE_AFTER_FALL;
            }

            o->oVelY = -15.0f;
            o->oPosY += o->oVelY;
        break;
        case BLOOPER_ACT_DISPERSE_AFTER_FALL:
        o->oForwardVel = 2.0f;
        o->oVelY = 10.0f;
            o->oPosY += o->oVelY;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer == 50) {
                o->oAction = BLOOPER_ACT_WAIT_FOR_MARIO_CLOSE;
            }
        break;
    }
    o->oGravity = -4.0f;
    o->oDragStrength = 3.0f;
    obj_handle_attacks(&sBlooperHitbox, 0, sBlooperAttackHandlers);
    
    obj_update_standard_actions(1.0f);

    s32 waterLevel = find_water_level(o->oPosX, o->oPosZ);

    if (waterLevel > FLOOR_LOWER_LIMIT + 10) {
        if (o->oPosY < waterLevel) {
            o->oHealth = 1;
        }
        else {
            o->oPosY = waterLevel;
        }
    }
}


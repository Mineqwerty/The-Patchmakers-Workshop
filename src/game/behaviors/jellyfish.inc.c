static struct ObjectHitbox sJellyfishHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 200,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 5,
    /* numLootCoins:      */ 3,
    /* radius:            */ 100,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 300,
};

void bhv_jellyfish_init(void) {

}

void bhv_jellyfish_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_init_animation(0);
            if (o->oDistanceToMario < 3000) {
               obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            }
            else {
                o->oTimer = 0;
            }

            if (o->oTimer == 10) {
                o->oAction = 1;
            }
        break;
        case 1:
            obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x100);
            o->oForwardVel = o->oTimer / 4;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer > 90) {
                o->oTimer = 90;
            }

            if (o->oDistanceToMario >= 4000) {
                o->oAction = 0;
            }
        break;
    }

    if (gMarioState->miasmaArmorTimer > 0) {
        o->oInteractType = INTERACT_NONE;
    }
    else {
        o->oInteractType = INTERACT_SHOCK;
    }
    
    obj_set_hitbox(o, &sJellyfishHitbox);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->oInteractStatus = INT_STATUS_NONE;
        }

    obj_die_if_health_non_positive();
    
}


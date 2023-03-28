struct ObjectHitbox sSeraphimHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 60,
};

void bhv_seraphim_loop(void) {
    treat_far_home_as_mario(1000.0f);
    
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oForwardVel = 5.0f;
        }

    if (o->oDistanceToMario < 1000.0f) {
        o->oForwardVel = 20.0f;
        o->oGoombaTargetYaw = o->oAngleToMario;
        if (o->oAction == 0) o->oAction = 1;
    }
    else {
        o->oForwardVel = 5.0f;
        if (o->oAction == 1) o->oAction = 0;
    }

    object_step();
    cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x400);

    if (o->oAction == 1) {
        if (o->oTimer % 120 == 119) {
            o->oAction = 2;
        }
    }

    if (o->oAction == 2) {
        if (o->oTimer % 5 == 0) {
            struct Object *blob = spawn_object_relative(0, 0, -50, 0, o, MODEL_GOLD_BLOB, bhvGoldBlob);
            blob->oVelY = -20.0f;
            blob->oAction = 3;
        }

        if (o->oTimer == 11) {
            o->oAction = 1;
        }
    }
    
    obj_set_hitbox(o, &sSeraphimHitbox);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {

            u8 healthSubtract = 1;
            for (int i = 0; i < (o->oInteractStatus & INT_STATUS_ATTACK_MASK); i++) {
                healthSubtract *= 2;
            }
            o->oHealth -= healthSubtract;

            if (healthSubtract > 24) {
                o->oHealth = 0;
                obj_die_if_health_non_positive();
            }
        }
    }

    
    o->oInteractStatus = 0;
}
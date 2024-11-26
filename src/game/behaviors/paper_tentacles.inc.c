static struct ObjectHitbox sPaperTentaclesHitbox = {
    /* interactType:      */ INTERACT_PUSH_OUT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 40,
    /* numLootCoins:      */ 0,
    /* radius:            */ 500,
    /* height:            */ 1600,
    /* hurtboxRadius:     */ 490,
    /* hurtboxHeight:     */ 1090,
};

void bhv_paper_tentacles_init(void) {
    obj_set_hitbox(o, &sPaperTentaclesHitbox);
}

void bhv_paper_tentacles_loop(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    obj_die_if_health_non_positive();

    if (o->oHealth <= 0) {
        obj_mark_for_deletion(o);
    }

    if (o->oHealth < o->oTentacleCageMaxHealth && o->oHealth > 0) {
        o->oHealth = o->oTentacleCageMaxHealth;
    }
}


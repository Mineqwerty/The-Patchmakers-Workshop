static struct ObjectHitbox sAbyssUrchinHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 12,
    /* numLootCoins:      */ 5,
    /* radius:            */ 400,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 390,
    /* hurtboxHeight:     */ 590,
};

void bhv_abyss_urchin_init(void) {

}

void bhv_abyss_urchin_loop(void) {
    obj_set_hitbox(o, &sAbyssUrchinHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    obj_die_if_health_non_positive();
}


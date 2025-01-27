struct ObjectHitbox sMantleOfMadnessHitbox = {
    /* interactType:      */ INTERACT_MANTLE_OF_MADNESS,
    /* downOffset:        */ 150,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 20,
    /* numLootCoins:      */ 2,
    /* radius:            */ 1000,
    /* height:            */ 3000,
    /* hurtboxRadius:     */ 990,
    /* hurtboxHeight:     */ 2990,
};

void bhv_mantle_of_madness_init(void) {
    obj_set_hitbox(o, &sMantleOfMadnessHitbox);
    o->oHealth = 300;
    gBossMaxHealth = 300;
    gBossHealth = 300;
}

void bhv_mantle_of_madness_loop(void) {
    if (gMarioState->pos[1] > o->oPosY + 2500) {
        o->oInteractType = INTERACT_BOUNCE_TOP;
    }
    else {
        o->oInteractType = INTERACT_MANTLE_OF_MADNESS;
    }
    o->oInteractStatus = 0;

    gBossHealth = o->oHealth;

}


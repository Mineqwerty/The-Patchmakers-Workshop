static struct ObjectHitbox sTasteNoiseSpikeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


void bhv_taste_noise_spike_hitbox_init(void) {
    obj_set_hitbox(o, &sTasteNoiseSpikeHitbox);
}

void bhv_taste_noise_spike_hitbox_loop(void) {
    o->oInteractStatus = 0;
}


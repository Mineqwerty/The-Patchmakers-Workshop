static struct ObjectHitbox sPMIceNeedleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pm_ice_spike_init(void) {
   
}

void bhv_pm_ice_spike_loop(void) {
    if (o->oTimer < 15) {
        o->oPosY += 20;
    }

    if (o->oTimer > 5) {
        obj_set_hitbox(o, &sPMIceNeedleHitbox);
        o->oInteractStatus = 0;
    }

    if (o->oTimer > 45) {
        o->oPosY -= 20;
    }

    if (o->oTimer == 60) {
        obj_mark_for_deletion(o);
    }
}


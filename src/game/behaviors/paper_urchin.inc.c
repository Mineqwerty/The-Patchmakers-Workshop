static struct ObjectHitbox sPaperUrchinHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 8,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 290,
    /* hurtboxHeight:     */ 590,
};

void bhv_paper_urchin_init(void) {

}

void bhv_paper_urchin_loop(void) {
    obj_set_hitbox(o, &sPaperUrchinHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    obj_die_if_health_non_positive();
}


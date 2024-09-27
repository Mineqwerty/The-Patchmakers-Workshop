struct ObjectHitbox sPaperScuttlebugHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 180,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 90,
};

void bhv_paper_scuttlebug_init(void) {
   
}

void bhv_paper_scuttlebug_loop(void) {
    obj_check_attacks(&sPaperScuttlebugHitbox, o->oAction);
}


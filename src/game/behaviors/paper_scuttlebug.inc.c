#include "src/game/interaction.h"

struct ObjectHitbox sPaperScuttlebugHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 230,
    /* height:            */ 130,
    /* hurtboxRadius:     */ 220,
    /* hurtboxHeight:     */ 90,
};

void bhv_paper_scuttlebug_init(void) {
   
}

void bhv_paper_scuttlebug_loop(void) {
    obj_check_attacks(&sPaperScuttlebugHitbox, o->oAction);

    if (o->oBehParams2ndByte == 1 && o->oDistanceToMario < 300) {
        freeze_enemy(gMarioState, o, 0);
    }
}


#include "src/game/cutscene.h"
static struct ObjectHitbox sPeachNPCHitbox = {
    /* interactType:      */ INTERACT_TEXT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

enum PeachNPCActions {
    PEACH_NPC_ACT_IDLE = 0,
    PEACH_NPC_ACT_IDLE_END = 3,
    PEACH_NPC_ACT_FIND_SPOT = 4,
    PEACH_NPC_ACT_REVIVE_CUTSCENE
};

void peach_npc_act_revive_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(1);
            if (cur_obj_check_if_near_animation_end()) {
                cur_obj_init_animation(2);
                o->oSubAction++;
            }
        break;
    }
}

void bhv_peach_npc_init(void) {
   
}

void bhv_peach_npc_loop(void) {
    if (gCurCutscene == CUTSCENE_EVENT_REVIVE_BOWSER) {
        o->oAction = PEACH_NPC_ACT_REVIVE_CUTSCENE;
    }

    switch (o->oAction) {
        case PEACH_NPC_ACT_FIND_SPOT:
            //bowser_npc_act_find_spot();
        break;
        case PEACH_NPC_ACT_IDLE:
            //bowser_npc_act_idle();
        break;
        case PEACH_NPC_ACT_REVIVE_CUTSCENE:
            peach_npc_act_revive_cutscene();
        break;
    }

    if (o->oAction <= PEACH_NPC_ACT_IDLE_END) {
        
        bhv_bobomb_buddy_loop();
        if (o->oAction > 0) {
            o->oFaceAngleYaw = o->oMoveAngleYaw;
        }
        o->oInteractStatus = 0;
    }
}


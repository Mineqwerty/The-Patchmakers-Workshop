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
    PEACH_NPC_ACT_REVIVE_CUTSCENE,
    PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE
};

void peach_npc_act_revive_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            if (cExternalCutsceneTrigger >= 3) {
                o->oSubAction++;
            }
        break;
        case 1:
        cur_obj_init_animation(1);
            if (cur_obj_check_if_near_animation_end()) {
                cur_obj_init_animation(2);
                o->oSubAction++;
            }
        break;
        case 2:
            
            if (cExternalCutsceneTrigger >= 4) {
                o->oPosX = -30;
                o->oPosY = 130;
                o->oPosZ = 1231;
                cur_obj_init_animation(3);
                o->oSubAction++;
            }
        break;
    }
}

void peach_npc_act_enter_third_hub_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = -4711;
            o->oPosY = 1622;
            o->oPosZ = -7558;
            cur_obj_init_animation(2);
            o->oFaceAngleYaw = 0x2000;
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                o->oPosX = -3410;
                o->oPosY = 1621;
                o->oPosZ = -4872;
                o->oSubAction++;
                o->oFaceAngleYaw = 0x5000;
            }
        break;
    }
}

void bhv_peach_npc_init(void) {
    obj_set_hitbox(o, &sPeachNPCHitbox);
    cur_obj_init_animation(2);
}

void bhv_peach_npc_loop(void) {
    if (gCurCutscene == CUTSCENE_EVENT_REVIVE_PEACH) {
        o->oAction = PEACH_NPC_ACT_REVIVE_CUTSCENE;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_THIRD_HUB_ARRIVAL) {
        o->oAction = PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE;
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
        case PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE:
            peach_npc_act_enter_third_hub_cutscene();
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


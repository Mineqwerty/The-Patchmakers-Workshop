#include "src/game/cutscene.h"
#include "src/game/mario_actions_cutscene.h"
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
    PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE,
    PEACH_NPC_ACT_ENTER_BRINK,
    PEACH_NPC_ACT_ENDING_CUTSCENE
};

void peach_npc_act_revive_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            if (cExternalCutsceneTrigger >= 3) {
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 1:
        cur_obj_init_animation(1);
        
        if (o->oTimer <= 30) {
            sPeachManualBlinkTime = 2;

        }
        else if (o->oTimer > 30 && o->oTimer < 60) {
            sPeachManualBlinkTime = 3;
        }
        else {
            sPeachManualBlinkTime = 0;
        }
            if (cur_obj_check_if_near_animation_end() || cExternalCutsceneTrigger >= 4) {
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
                sPeachManualBlinkTime = 3;
                o->oSubAction++;
            }
        break;
        case 3:
            
            if (cExternalCutsceneTrigger >= 6) {
                o->oPosX = 30;
                o->oPosY = 100;
                o->oPosZ = 1031;
                o->oFaceAngleYaw = -0x3600;
                
                sPeachManualBlinkTime = 0;
                cur_obj_init_animation(2);
                o->oSubAction++;
            }
        break;
        case 4:
            
            if (cExternalCutsceneTrigger >= 7) {
                cur_obj_init_animation(4);
                o->oPosX = -33;
                o->oSubAction++;
            }
        break;
        case 5:
            if (o->oTimer > 30) {
                sPeachManualBlinkTime = 3;
            }
            if (cExternalCutsceneTrigger >= 9) {
                o->oSubAction++;
                o->oFaceAngleYaw = -0x7600;
                cur_obj_init_animation(2);
                sPeachManualBlinkTime = 0;
            }
        break;
        case 6:

            if (cExternalCutsceneTrigger >= 11) {
                cur_obj_init_animation(5);
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

    if (cExternalCutsceneTrigger >= 2) {
        struct Object *spot = cur_obj_find_object_with_bparam_2nd_byte(bhvPeachNpcSpot, DIALOG_PEACH_NPC_ARRIVED_AT_THIRD_HUB);
        o->oPosX = spot->oPosX;
        o->oPosY = spot->oPosY;
        o->oPosZ = spot->oPosZ;
        SET_BPARAM2(o->oBehParams, DIALOG_PEACH_NPC_ARRIVED_AT_THIRD_HUB);
        o->oBehParams2ndByte = DIALOG_PEACH_NPC_ARRIVED_AT_THIRD_HUB;
        o->oAction = PEACH_NPC_ACT_IDLE;
    }
}

void peach_npc_act_enter_brink(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = -3224;
            o->oPosY = 1622;
            o->oPosZ = -4460;
            cur_obj_init_animation(2);
            o->oFaceAngleYaw = -0x7500;
            cur_obj_unhide();
            o->oSubAction++;
        break;
    }
}

void peach_npc_act_ending_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            o->oPosX = -4780;
            o->oPosY = 1622;
            o->oPosZ = -6150;
            cur_obj_init_animation(2);
            o->oFaceAngleYaw = 0;
            o->oSubAction++;
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 1) {
                o->oFaceAngleYaw = 0x2000;
                o->oSubAction++;
            }
        break;
        case 2:
            if (cExternalCutsceneTrigger >= 4) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}

void peach_npc_find_spot(void) {
            u8 randSpot = random_u16()%4;
            struct Object *spot = cur_obj_find_object_with_bparam_2nd_byte(bhvPeachNpcSpot, DIALOG_PEACH_NPC_WINDOW_GALLERY + randSpot);
            o->oPosX = spot->oPosX;
            o->oPosY = spot->oPosY;
            o->oPosZ = spot->oPosZ;
            SET_BPARAM2(o->oBehParams, DIALOG_PEACH_NPC_WINDOW_GALLERY + randSpot);
            o->oBehParams2ndByte = DIALOG_PEACH_NPC_WINDOW_GALLERY + randSpot;
}

void peach_npc_act_find_spot(void) {
    peach_npc_find_spot();
    o->oAction = PEACH_NPC_ACT_IDLE;
}

void peach_npc_act_idle(void) {
    cur_obj_init_animation(2);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void bhv_peach_npc_init(void) {
    obj_set_hitbox(o, &sPeachNPCHitbox);
    if (gCutsceneGameState != CUTSCENE_GAME_STATE_ENTER_SECOND_HUB && gCutsceneGameState != CUTSCENE_GAME_STATE_ENTER_THIRD_HUB) {
        o->oAction = PEACH_NPC_ACT_FIND_SPOT;
    }
    cur_obj_init_animation(2);

    if (gCurrAreaIndex == 3 && (save_file_get_flags() & SAVE_FLAG_BEAT_GAME)) {
        #ifndef COMPLETE_SAVE_FILE
        obj_mark_for_deletion(o);
        #endif
    }
}

void bhv_peach_npc_loop(void) {
    if (gCurCutscene == CUTSCENE_EVENT_REVIVE_PEACH) {
        o->oAction = PEACH_NPC_ACT_REVIVE_CUTSCENE;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_THIRD_HUB_ARRIVAL) {
        o->oAction = PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_ENTER_BRINK) {
        if (o->oAction != PEACH_NPC_ACT_ENTER_BRINK) {
            o->oSubAction = 0;
        }
        o->oAction = PEACH_NPC_ACT_ENTER_BRINK;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_POST_MANTLE) {
        o->oAction = PEACH_NPC_ACT_ENDING_CUTSCENE;
    }

    switch (o->oAction) {
        case PEACH_NPC_ACT_FIND_SPOT:
            peach_npc_act_find_spot();
        break;
        case PEACH_NPC_ACT_IDLE:
            peach_npc_act_idle();
        break;
        case PEACH_NPC_ACT_REVIVE_CUTSCENE:
            peach_npc_act_revive_cutscene();
        break;
        case PEACH_NPC_ACT_ENTER_THIRD_HUB_CUTSCENE:
            peach_npc_act_enter_third_hub_cutscene();
        break;
        case PEACH_NPC_ACT_ENTER_BRINK:
            peach_npc_act_enter_brink();
        break;
        case PEACH_NPC_ACT_ENDING_CUTSCENE:
            peach_npc_act_ending_cutscene();
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


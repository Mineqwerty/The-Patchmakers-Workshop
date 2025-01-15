#include "src/game/cutscene.h"
#include "include/dialog_ids.h"

static struct ObjectHitbox sBowserNPCHitbox = {
    /* interactType:      */ INTERACT_TEXT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

enum BowserNPCActions {
    BOWSER_NPC_ACT_IDLE = 0,
    BOWSER_NPC_ACT_IDLE_END = 3,
    BOWSER_NPC_ACT_FIND_SPOT = 4,
    BOWSER_NPC_ACT_REVIVE_CUTSCENE,
    BOWSER_NPC_ACT_ENTER_SECOND_HUB,
    BOWSER_NPC_ACT_LEAVING_SECOND_HUB,
    BOWSER_NPC_ACT_SECOND_PATCHMAKER_FIGHT_CUTSCENE
};

void bowser_npc_act_revive_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(2);
            if (cExternalCutsceneTrigger >= 2) {
                cur_obj_init_animation(0);
                o->oSubAction++;
            }
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 3) {
                cur_obj_init_animation(27);
                o->oSubAction++;
            }
        break;
        case 2:
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(28);
                o->oSubAction++;
            }
        break;
        case 3:
            if (o->header.gfx.animInfo.animFrame == 19 || o->header.gfx.animInfo.animFrame == 31 || o->header.gfx.animInfo.animFrame == 41) {
                cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
            }

            if (cExternalCutsceneTrigger >= 4) {
                cur_obj_init_animation(12);
                o->oSubAction++;
            }
        break;
        case 4:
            if (cExternalCutsceneTrigger >= 6) {
                cur_obj_init_animation(27);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 5:
            if (o->oTimer >= 60) {
                cur_obj_init_animation(28);
                o->oSubAction++;
            }
        break;
        case 6:
            if (o->header.gfx.animInfo.animFrame == 19 || o->header.gfx.animInfo.animFrame == 31 || o->header.gfx.animInfo.animFrame == 41) {
                cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
            }
            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation(29);
                o->oSubAction++;
            }
        break;
        case 7:
            if (cExternalCutsceneTrigger >= 8) {
                cur_obj_init_animation(30);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 8:
            if (cExternalCutsceneTrigger >= 9) {
                cur_obj_init_animation(31);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
        case 9:
            if (o->oTimer == 110) {
                cur_obj_shake_screen(SHAKE_POS_LARGE);

            }
            if (cExternalCutsceneTrigger >= 10) {
                cur_obj_init_animation(12);
                o->oSubAction++;
                o->oTimer = 0;
            }
        break;
    }
}

void bowser_npc_act_enter_second_hub(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(12);
            if (cExternalCutsceneTrigger >= 2) {
                cur_obj_init_animation(27);
                o->oSubAction = 1;
            }
        break;
        case 1:
            if (cExternalCutsceneTrigger >= 3) {
                cur_obj_init_animation(12);
                o->oSubAction = 2;
            }
        break;
    }

    if (cExternalCutsceneTrigger >= 4) {
            struct Object *spot = cur_obj_find_object_with_bparam_2nd_byte(bhvBowserNpcSpot, DIALOG_BOWSER_NPC_ARRIVED_AT_SECOND_HUB);
            o->oPosX = spot->oPosX;
            o->oPosY = spot->oPosY;
            o->oPosZ = spot->oPosZ;
            SET_BPARAM2(o->oBehParams, DIALOG_BOWSER_NPC_ARRIVED_AT_SECOND_HUB);
            o->oBehParams2ndByte = DIALOG_BOWSER_NPC_ARRIVED_AT_SECOND_HUB;
            o->oAction = BOWSER_NPC_ACT_IDLE;
    }
}

void bowser_npc_act_leaving_second_hub(void) {
            if (cExternalCutsceneTrigger >= 2) {
                cur_obj_unhide();
                cur_obj_init_animation(12);
                o->oMoveAngleYaw = -0x4000;
                o->oFaceAngleYaw = -0x4000;
                
                o->oPosX = -3653;
                o->oPosY = 955;
                o->oPosZ = -1163;
                if (o->oSubAction == 0 && gPageNum == 7) {
                    cur_obj_shake_screen(SHAKE_POS_LARGE);
                    o->oSubAction = 1;
                }
            }
}

void bowser_npc_act_second_patchmaker_fight_cutscene(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_init_animation(12);
            if (cExternalCutsceneTrigger >= 1) {
                o->oSubAction = 1;
            }
        break;
        case 1:
            o->oPosX = 2000;
            o->oPosZ = 400;
            o->oMoveAngleYaw = 0x8000;
            o->oFaceAngleYaw = 0x8000;
            if (cExternalCutsceneTrigger >= 2) {
                for (int i = 0; i < 7; i++) {
                    spawn_object_relative(0, random_u16()%200 - 100, random_u16()%200, - 100 + random_u16()%50, o, MODEL_EXPLOSION, bhvExplosion);
                }
                o->oForwardVel = 80.0f;
                o->oVelY = 50;
                o->oTimer = 0;
                o->oSubAction = 2;
            }
        break;
        case 2:
            cur_obj_init_animation_with_accel_and_sound(3, 2.0f);
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oPosY += o->oVelY;
            o->oVelY -= 2;

            if (o->oTimer >= 30) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}

void bowser_npc_find_spot(void) {
    switch (gCurrAreaIndex) {
        case 2:;
            u8 randSpot = random_u16()%4;
            struct Object *spot = cur_obj_find_object_with_bparam_2nd_byte(bhvBowserNpcSpot, DIALOG_BOWSER_NPC_AUTOMATON + randSpot);
            o->oPosX = spot->oPosX;
            o->oPosY = spot->oPosY;
            o->oPosZ = spot->oPosZ;
            SET_BPARAM2(o->oBehParams, DIALOG_BOWSER_NPC_AUTOMATON + randSpot);
            o->oBehParams2ndByte = DIALOG_BOWSER_NPC_AUTOMATON + randSpot;
        break;
    }
}

void bowser_npc_act_find_spot(void) {
    bowser_npc_find_spot();
    o->oAction = BOWSER_NPC_ACT_IDLE;
}

void bowser_npc_act_idle(void) {
    cur_obj_init_animation(12);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void bhv_bowser_npc_init(void) {
    obj_set_hitbox(o, &sBowserNPCHitbox);
    o->oAction = BOWSER_NPC_ACT_FIND_SPOT;
}

void bhv_bowser_npc_loop(void) {
    if (gCurCutscene == CUTSCENE_EVENT_REVIVE_BOWSER) {
        o->oAction = BOWSER_NPC_ACT_REVIVE_CUTSCENE;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_SECOND_HUB_ARRIVAL) {
        o->oAction = BOWSER_NPC_ACT_ENTER_SECOND_HUB;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_LEAVING_SECOND_HUB) {
        o->oAction = BOWSER_NPC_ACT_LEAVING_SECOND_HUB;
    }
    else if (gCurCutscene == CUTSCENE_EVENT_PATCHMAKER_SECOND_FIGHT_INTRO) {
        o->oAction = BOWSER_NPC_ACT_SECOND_PATCHMAKER_FIGHT_CUTSCENE;
    }

    switch (o->oAction) {
        case BOWSER_NPC_ACT_FIND_SPOT:
            bowser_npc_act_find_spot();
        break;
        case BOWSER_NPC_ACT_IDLE:
            bowser_npc_act_idle();
        break;
        case BOWSER_NPC_ACT_REVIVE_CUTSCENE:
            bowser_npc_act_revive_cutscene();
        break;
        case BOWSER_NPC_ACT_ENTER_SECOND_HUB:
            bowser_npc_act_enter_second_hub();
        break;
        case BOWSER_NPC_ACT_LEAVING_SECOND_HUB:
            bowser_npc_act_leaving_second_hub();
        break;
        case BOWSER_NPC_ACT_SECOND_PATCHMAKER_FIGHT_CUTSCENE:
            bowser_npc_act_second_patchmaker_fight_cutscene();
        break;
    }

    if (o->oAction <= BOWSER_NPC_ACT_IDLE_END) {
        
        bhv_bobomb_buddy_loop();
        if (o->oAction > 0) {
            o->oFaceAngleYaw = o->oMoveAngleYaw;
        }
        o->oInteractStatus = 0;
    }

    
}


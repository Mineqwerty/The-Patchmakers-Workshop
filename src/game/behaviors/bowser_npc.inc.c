#include "src/game/cutscene.h"

static struct ObjectHitbox sBowserNPCHitbox = {
    /* interactType:      */ INTERACT_TEXT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

enum BowserNPCActions {
    BOWSER_NPC_ACT_IDLE,
    BOWSER_NPC_ACT_REVIVE_CUTSCENE
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

void bhv_bowser_npc_init(void) {
    obj_set_hitbox(o, &sBowserNPCHitbox);
}

void bhv_bowser_npc_loop(void) {
    o->oInteractStatus = 0;
    switch (o->oAction) {
        case BOWSER_NPC_ACT_REVIVE_CUTSCENE:
            bowser_npc_act_revive_cutscene();
        break;
    }

    if (gCurCutscene == CUTSCENE_EVENT_REVIVE_BOWSER) {
        o->oAction = BOWSER_NPC_ACT_REVIVE_CUTSCENE;
    }
}


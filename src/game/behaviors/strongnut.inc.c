#include "include/dialog_ids.h"

static struct ObjectHitbox sStrongnutHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 40,
    /* numLootCoins:      */ 5,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 190,
    /* hurtboxHeight:     */ 90,
};

void bhv_strongnut_init(void) {
    obj_set_hitbox(o, &sStrongnutHitbox);
    o->oF4 = 0;
}

void bhv_strongnut_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus != 0) {
                if (o->oHealth <= 0) {
                    o->oAction = 2;
                }
                else {
                    o->oAction = 1;
                }
            }
            o->oInteractStatus = 0;
        break;
        case 1:
            o->oInteractStatus = 0;
            o->oHealth = 40;
            if (!((gMarioState->action & ACT_GROUP_MASK) >= ACT_GROUP_AIRBORNE && (gMarioState->action & ACT_GROUP_MASK) < (ACT_HOLD_JUMP & ACT_ID_MASK))) {
                create_automatic_dialog_box(DIALOG_STRONGNUT_1 + o->oF4 % 3);
                //gMarioState->action = ACT_WAITING_FOR_DIALOG;
                o->oAction = 3;
                o->oF4++;

            }
        break;
        case 2:
            o->oFaceAnglePitch -= 0x200 + (o->oTimer * 0x50);

            if (o->oFaceAnglePitch <= -0x4000) {
                o->oAction = 4;
                o->oFaceAnglePitch = -0x4000;
            }
        break;
        case 3:
            o->oInteractStatus = 0;
            if ((gDialogResponse > 0 && o->oTimer > 10) || o->oTimer > 90) {
                //gMarioState->action = ACT_IDLE;
                o->oAction = 0;
            }
        break;
        case 4:
            if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_DOWN) == MARIO_DIALOG_STATUS_SPEAK 
                && cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_STRONGNUT_BEATEN)) {
                set_mario_npc_dialog(MARIO_DIALOG_STOP);
                SET_BPARAM1(o->oBehParams, 24);
                spawn_default_star(o->oPosX + 300, o->oPosY + 300, o->oPosZ);
                o->oAction = 5;
                }
        break;
    }
}


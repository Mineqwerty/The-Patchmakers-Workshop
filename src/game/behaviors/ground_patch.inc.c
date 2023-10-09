#include "include/seq_ids.h"
#include "src/game/cutscene.h"

void bhv_ground_patch_init(void) {
    if (save_file_get_patch_flags(gCurrSaveFileNum - 1) & (1 << o->oBehParams2ndByte + 1)) {
        obj_mark_for_deletion(o);
    }
}

void bhv_ground_cutscene_patch_init(void) {
    if (save_file_get_patch_flags(gCurrSaveFileNum - 1) & (1 << 1)) {
        obj_mark_for_deletion(o);
    }
}

void bhv_ground_cutscene_patch_loop(void) {
    switch (o->oAction) {
    case 0:
        if (o->oDistanceToMario < 900.0f && !((gMarioState->action & ACT_GROUP_MASK) >= ACT_GROUP_AIRBORNE && (gMarioState->action & ACT_GROUP_MASK) < (ACT_HOLD_JUMP & ACT_ID_MASK))) {
            o->oAction++;
            gMarioState->pos[0] = o->oPosX;
            gMarioState->pos[1] = o->oPosY + 50;
            gMarioState->pos[2] = o->oPosZ - 20;
            gMarioState->faceAngle[1] = 0;
            begin_cutscene_event(CUTSCENE_EVENT_STONE_PATCH);
        }
    break;
    case 1:
        gMarioState->marioBodyState->grabPos = GRAB_POS_CUTSCENE_STONE_PATCH;
    break;
    }
}

void bhv_ground_patch_loop(void) {
   switch (o->oAction) {
    case 0:
        if (o->oDistanceToMario < 200.0f && !((gMarioState->action & ACT_GROUP_MASK) >= ACT_GROUP_AIRBORNE && (gMarioState->action & ACT_GROUP_MASK) < (ACT_HOLD_JUMP & ACT_ID_MASK))) {
            o->oAction++;
            gCamera->cutscene = 1;
            gMarioState->faceAngle[1] = 0x4000;
            gMarioState->pos[0] = o->oPosX - 100;
            gMarioState->pos[1] = o->oPosY + 11.9f;
            gMarioState->pos[2] = o->oPosZ;
            set_mario_action(gMarioState, ACT_COLLECTING_PATCH, 1);
            play_secondary_music(SEQ_PATCH_GET, 0, 255, 3);
        }
    break;
    case 1:
        if (o->oTimer < 19) {
            gLakituState.goalPos[0] = gMarioState->pos[0] + 400 * sins(gMarioState->faceAngle[1]) + 400 * coss(0x333 * o->oTimer);
            gLakituState.goalPos[1] = gMarioState->pos[1] + 10;
            gLakituState.goalPos[2] = gMarioState->pos[2];
        }

        if (o->oTimer == 22) {
            gMarioState->heldObj = o;
            cur_obj_hide();
        }
        if (o->oTimer == 25) {
        o->oAction++;
        }
    break;
    case 2:
    if (o->oTimer <= 60) {
        gLakituState.goalPos[0] = gMarioState->pos[0] + 100 * sins(gMarioState->faceAngle[1]) + 400 * coss(0x222 * o->oTimer);
        gLakituState.goalPos[2] = gMarioState->pos[2] + 100 * coss(gMarioState->faceAngle[1]) + 400 * sins(0x222 * o->oTimer);

        gLakituState.goalPos[1] = gMarioState->pos[1] + 10 + 3*o->oTimer;
    }

    if (o->oTimer == 65) {
        gMarioState->heldObj = NULL;
        gMarioState->equippedPatch = o->oBehParams2ndByte + 1;
        gMarioState->updatePatch = 1;
        save_file_set_patch_flags(gCurrSaveFileNum - 1, (1 << (o->oBehParams2ndByte + 1)));
    }

    if (o->oTimer >= 100 && o->oTimer < 115) {
        gMarioState->faceAngle[1] -= 0x888;
    }

    if (o->oTimer >= 135) {
        gMarioState->marioBodyState->handState = MARIO_HAND_PEACE_SIGN;
    }

    if (o->oTimer == 180) {
        obj_mark_for_deletion(o);
        gCamera->cutscene = 0;
        set_mario_action(gMarioState, ACT_IDLE, 0);
        func_80321080(30);
        gMarioState->marioBodyState->handState = MARIO_HAND_FISTS;
    }
    gLakituState.goalFocus[0] = gMarioState->pos[0];
    gLakituState.goalFocus[1] = gMarioState->pos[1] + 100;
    gLakituState.goalFocus[2] = gMarioState->pos[2];
    break;
   }
}


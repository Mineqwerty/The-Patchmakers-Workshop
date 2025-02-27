#include "src/game/game_init.h"
#include "src/game/ingame_menu.h"

void bhv_patch_challenge_controller_init(void) {
    gPatchChallengeTimer = 0;
    gPatchChallengeIndex = o->oBehParams2ndByte;
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_PATCH_CHALLENGE), 0);
}

void bhv_patch_challenge_controller_loop(void) {
    gCamera->cutscene = 1;
    gLakituState.goalPos[0] = gMarioState->pos[0];
    gLakituState.goalPos[1] = gMarioState->pos[1] + 150;
    gLakituState.goalPos[2] = gMarioState->pos[2] + 4000;
    gLakituState.goalFocus[0] = gMarioState->pos[0];
    gLakituState.goalFocus[1] = gMarioState->pos[1] + 140;
    gLakituState.goalFocus[2] = gMarioState->pos[2];

    gMarioState->pos[2] = 0;

    gMarioState->equippedPatch = o->oBehParams2ndByte;

    if (o->oTimer == 1) {
        gMarioState->updatePatch = 1;
    }

    gCamera->yaw = 0;
    gMarioState->area->camera->yaw = 0;

    if (gMarioState->action != ACT_FALL_AFTER_STAR_GRAB && gMarioState->action != ACT_STAR_DANCE_EXIT) {
        gPatchChallengeTimer++;
    }

    if (gPatchChallengeTimer > patchChallengeTimes[o->oBehParams2ndByte - 1]) {
        level_trigger_warp(gMarioState, WARP_OP_DEATH);
    }
}


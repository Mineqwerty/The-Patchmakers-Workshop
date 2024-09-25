void bhv_patch_challenge_controller_init(void) {
   
}

void bhv_patch_challenge_controller_loop(void) {
    gCamera->cutscene = 1;
    gLakituState.goalPos[0] = gMarioState->pos[0];
    gLakituState.goalPos[1] = gMarioState->pos[1] + 150;
    gLakituState.goalPos[2] = gMarioState->pos[2] + 2000;
    gLakituState.goalFocus[0] = gMarioState->pos[0];
    gLakituState.goalFocus[1] = gMarioState->pos[1] + 140;
    gLakituState.goalFocus[2] = gMarioState->pos[2];

    gMarioState->pos[2] = 0;
}


void bhv_hidden_cannon_init(void) {
   
}

void bhv_hidden_cannon_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 300) {
                o->oAction++;
                gCamera->cutscene = 1;
                cur_obj_play_sound_2(SOUND_OBJ_CANNON_RISE);
    
            }
        break;
        case 1:
            o->oPosZ -= 7.0f;
            gLakituState.goalPos[0] = approach_f32_asymptotic(gLakituState.goalPos[0], o->oPosX + 600, 0.04f);
            gLakituState.goalPos[1] = approach_f32_asymptotic(gLakituState.goalPos[1], o->oPosY + 300, 0.03f);
            gLakituState.goalPos[2] = approach_f32_asymptotic(gLakituState.goalPos[2], o->oPosZ - 400, 0.04f);
            gLakituState.goalFocus[0] = gMarioState->pos[0];
            gLakituState.goalFocus[1] = gMarioState->pos[1];
            gLakituState.goalFocus[2] = gMarioState->pos[2];
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
            gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
            gMarioState->pos[0] = o->oPosX;
            gMarioState->pos[1] = o->oPosY;
            gMarioState->pos[2] = o->oPosZ;

            if (o->oTimer == 60) {
                o->oAction++;
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            }
        break;
        case 2:
            if (o->oTimer == 20) {
                o->oAction++;
            }
        break;
        case 3:
            set_mario_action(gMarioState, ACT_SHOT_FROM_CANNON, 0);
            gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
            gMarioState->faceAngle[1] = o->oFaceAngleYaw;
            gMarioState->vel[1] = 30.0f;
            gMarioState->forwardVel = 120.0f;
            gCamera->cutscene = 0;
            play_sound(SOUND_ACTION_FLYING_FAST, gMarioState->marioObj->header.gfx.cameraToObject);
                play_sound(SOUND_OBJ_POUNDING_CANNON, gMarioState->marioObj->header.gfx.cameraToObject);
            o->oAction++;
        break;
        case 4:
            o->oPosZ += 7.0f;
            if (o->oTimer == 60) {
                o->oAction = 0;
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            }
        break;
    }
}


void bhv_goofy_warp_init(void) {

}

void bhv_goofy_warp_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 300.0f) {
                o->oAction = 1;
                gCamera->cutscene = 1;
            }
        break;
        case 1:
            if (o->oTimer == 5) {
                struct Object *reciever = cur_obj_find_object_with_bparam_2nd_byte(bhvGoofyWarpReciever, o->oBehParams2ndByte);

                if (reciever) {
                    gMarioState->pos[0] = reciever->oPosX;
                    gMarioState->pos[1] = reciever->oPosY;
                    gMarioState->pos[2] = reciever->oPosZ;
                    gMarioState->action = ACT_WAITING_FOR_DIALOG;
                    gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
                    gMarioState->faceAngle[1] = reciever->oFaceAngleYaw;
                    o->oAction++;
                }
                else {
                    gCamera->cutscene = 0;
                    o->oAction = 5;
                }
            }
        break;
        case 2:
            gLakituState.goalFocus[0] = approach_f32_asymptotic(gLakituState.goalFocus[0], gMarioState->pos[0], 0.09f);
            gLakituState.goalFocus[1] = approach_f32_asymptotic(gLakituState.goalFocus[1], gMarioState->pos[1], 0.09f);
            gLakituState.goalFocus[2] = approach_f32_asymptotic(gLakituState.goalFocus[2], gMarioState->pos[2], 0.09f);

            if (o->oTimer == 45) {
                o->oAction++;
            }
        break;
        case 3:
            gCamera->cutscene = 0;
            gMarioState->action = ACT_SPAWN_SPIN_AIRBORNE;
            gMarioState->vel[1] = 50.0f;
            gMarioState->forwardVel = 30.0f;
            gMarioState->marioObj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_MARIO];
            o->oAction = 0;
        break;
    }
}

void bhv_goofy_warp_reciever_init(void) {
   
}

void bhv_goofy_warp_reciever_loop(void) {
   
}


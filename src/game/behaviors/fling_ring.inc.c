void bhv_fling_ring_loop(void) {
    if (o->oAction == 0 && o->oDistanceToMario < 300.0f) {
        gMarioState->faceAngle[1] = o->oFaceAngleYaw;
        gMarioState->action = ACT_TRIPLE_JUMP;
        gMarioState->vel[1] = 40.0f;
        gMarioState->forwardVel = 90.0f;
        o->oAction = 1;
    }

    if (o->oAction == 1 && o->oTimer > 30) {
        o->oAction = 0;
    }
}
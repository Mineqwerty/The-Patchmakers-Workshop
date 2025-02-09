void bhv_fling_ring_loop(void) {

    struct Surface *floor;
    find_floor(gMarioState->pos[0], gMarioState->pos[1], gMarioState->pos[2], &floor);

    if (o->oAction == 0 && o->oDistanceToMario < 350.0f && ((absf(o->oFaceAnglePitch) > 100) || gMarioState->floor->object == o)) {
        gMarioState->faceAngle[1] = o->oFaceAngleYaw;
        gMarioState->action = ACT_TRIPLE_JUMP;
        gMarioState->vel[1] = 40.0f - (o->oFaceAnglePitch / 0x199);
        gMarioState->forwardVel = 90.0f - absi(o->oFaceAnglePitch / 0xB6);
        set_mario_animation(gMarioState, MARIO_ANIM_TRIPLE_JUMP);
        o->oAction = 1;
    }

    if (o->oAction == 1 && o->oTimer > 30) {
        o->oAction = 0;
    }
}
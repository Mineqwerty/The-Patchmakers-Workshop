void bhv_sky_slug_init(void) {
    o->oDrawingDistance = (gIsConsole ? 6000 : 20000);
}

void bhv_sky_slug_loop(void) {

    s32 period = GET_BPARAM1(o->oBehParams) * 10;
    s32 turnTimer = 70;

    if (o->oTimer == 1) {
            o->oForwardVel = o->oBehParams2ndByte;
            cur_obj_init_animation(0);
        }
        if (o->oTimer > period && o->oTimer <= period + turnTimer) {
            o->oForwardVel = 0.0f;
            cur_obj_init_animation(1);
            
        }
        if (o->oTimer == period + turnTimer + 1) {
            o->oForwardVel = o->oBehParams2ndByte;
            o->oMoveAngleYaw += 0x8000;
            cur_obj_init_animation(0);
        }
        if (o->oTimer > period*2 + turnTimer && o->oTimer <= period*2 + turnTimer*2) {
            o->oForwardVel = 0.0f;
            cur_obj_init_animation(1);
            if (o->oTimer == period*2 + turnTimer*2) {
                o->oTimer = 0;
                o->oMoveAngleYaw += 0x8000;
                cur_obj_init_animation(0);
            }
        }

        cur_obj_move_xz_using_fvel_and_yaw();

    if (((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED)) {

        if (gMarioState->waterFloor && gMarioState->waterFloor->object && gMarioState->waterFloor->object == o) {
            gMarioState->pos[0] += o->oVelX;
            gMarioState->pos[1] += o->oVelY;
            gMarioState->pos[2] += o->oVelZ;
        }
        
    }
    else if (gMarioState->equippedPatch == PATCH_CHILLSTEP && ((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_MOVING) || ((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_STATIONARY)) {
        if (gMarioState->waterFloor && gMarioState->waterFloor->object && gMarioState->waterFloor->object == o) {
            gMarioState->pos[0] += o->oVelX;
            gMarioState->pos[1] += o->oVelY;
            gMarioState->pos[2] += o->oVelZ;
            if (gMarioState->patchChildObj) {
                gMarioState->patchChildObj->oPosX += o->oVelX;
                gMarioState->patchChildObj->oPosY += o->oVelY;
                gMarioState->patchChildObj->oPosZ += o->oVelZ;
            }
        }
        
    }

    o->oFaceAngleYaw = o->oMoveAngleYaw;
}


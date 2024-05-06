void bhv_lily_pad_init(void) {
    o->oBuoyancy = 0.3f;
    o->oGravity = 1.6f;
}

void bhv_lily_pad_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oGravity = 1.6f;
            if (gMarioState->marioObj->platform == o && gMarioState->equippedPatch == PATCH_BREEZE && gPlayer1Controller->buttonPressed & L_TRIG) {
                o->oAction = 1;
                o->oVelY = 100.0f;
                
            }
        break;
        case 1:
        if (o->oTimer == 1) {
            gMarioState->action = ACT_BACKFLIP_LAND;
                gMarioState->forwardVel = 0;
        }
            o->oGravity = 1.2f;
            o->oMoveAngleYaw += 0x300;
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            if (o->oTimer == 120) {
                o->oAction = 0;
            }
        break;
    }

    object_step_without_floor_orient();
    
}


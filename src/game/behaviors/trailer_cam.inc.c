enum TrailerCamActions {
    TRAILER_CAM_ACT_MOVE_FREE,
    TRAILER_CAM_ACT_FOLLOW_SPLINE
};

void bhv_trailer_cam_init(void) {
    o->oAction = TRAILER_CAM_ACT_MOVE_FREE;
}

void bhv_trailer_cam_loop(void) {
    switch (o->oAction) {
        case TRAILER_CAM_ACT_MOVE_FREE:
            gCamera->cutscene = 1;
            gMarioState->action = ACT_WAITING_FOR_DIALOG;
            gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];

            gMarioState->pos[0] = o->oPosX;
            gMarioState->pos[1] = o->oPosY;
            gMarioState->pos[2] = o->oPosZ;

            gLakituState.goalPos[0] = o->oPosX;
            gLakituState.goalPos[1] = o->oPosY;
            gLakituState.goalPos[2] = o->oPosZ;
            
            gLakituState.goalFocus[0] = o->oPosX + (100 * sins(o->oFaceAngleYaw) * coss(o->oFaceAnglePitch));
            gLakituState.goalFocus[1] = o->oPosY + (100 * sins(o->oFaceAnglePitch));
            gLakituState.goalFocus[2] = o->oPosZ + (100 * coss(o->oFaceAngleYaw) * coss(o->oFaceAnglePitch));

            o->oFaceAngleYaw -= 712 * ((gPlayer1Controller->buttonDown & R_CBUTTONS) > 0);
            o->oFaceAngleYaw += 712 * ((gPlayer1Controller->buttonDown & L_CBUTTONS) > 0);
            o->oFaceAnglePitch += 512 * ((gPlayer1Controller->buttonDown & U_CBUTTONS) > 0);
            o->oFaceAnglePitch -= 512 * ((gPlayer1Controller->buttonDown & D_CBUTTONS) > 0);

            o->oFaceAnglePitch = CLAMP(o->oFaceAnglePitch, -0x3EFF, 0x3FFF);

            o->oMoveAngleYaw = atan2s(gPlayer1Controller->stickY, -gPlayer1Controller->stickX) + o->oFaceAngleYaw;

            if (gPlayer1Controller->stickX < 4.0f && gPlayer1Controller->stickX > -4.0f
                && gPlayer1Controller->stickY < 4.0f && gPlayer1Controller->stickY > -4.0f) {
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 9.0f);
            } else {
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 18.0f, 8.0f);
            }

            if (gPlayer1Controller->buttonDown & A_BUTTON) {
                o->oPosY += 10;
            }
            if (gPlayer1Controller->buttonDown & B_BUTTON) {
                o->oPosY -= 10;
            }

            if (gPlayer1Controller->buttonPressed & U_JPAD) {
                o->oTCFoc1X = gLakituState.focus[0];
                o->oTCFoc1Y = gLakituState.focus[1];
                o->oTCFoc1Z = gLakituState.focus[2];
                print_text(100, 100, "Foc 1 Set");
            }
            if (gPlayer1Controller->buttonPressed & D_JPAD) {
                o->oTCFoc2X = gLakituState.focus[0];
                o->oTCFoc2Y = gLakituState.focus[1];
                o->oTCFoc2Z = gLakituState.focus[2];
                print_text(100, 100, "Foc 2 Set");
            }
            if (gPlayer1Controller->buttonPressed & R_JPAD) {
                o->oTCPos1X = gLakituState.pos[0];
                o->oTCPos1Y = gLakituState.pos[1];
                o->oTCPos1Z = gLakituState.pos[2];
                print_text(100, 100, "Pos 1 Set");
            }
            if (gPlayer1Controller->buttonPressed & L_JPAD) {
                o->oTCPos2X = gLakituState.pos[0];
                o->oTCPos2Y = gLakituState.pos[1];
                o->oTCPos2Z = gLakituState.pos[2];
                print_text(100, 100, "Pos 2 Set");
            }

            if (gPlayer1Controller->buttonDown & R_TRIG) {
                o->oTCSplineTimer += o->oTimer % 2;
            }
            if (gPlayer1Controller->buttonDown & L_TRIG) {
                o->oTCSplineTimer -= o->oTimer % 2;
            }

            if (gPlayer1Controller->buttonPressed & Z_TRIG) {
                o->oAction = TRAILER_CAM_ACT_FOLLOW_SPLINE;
            }

            cur_obj_move_xz_using_fvel_and_yaw();
        break;
    }
}


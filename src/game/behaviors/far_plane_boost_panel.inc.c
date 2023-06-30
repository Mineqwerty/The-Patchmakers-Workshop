void bhv_far_plane_boost_panel_init(void) {
   
}

void bhv_far_plane_boost_panel_loop(void) {
   if (gMarioObject->platform == o) {
    set_mario_action(gMarioState, ACT_TWIRLING, 5);
    gMarioState->vel[1] = 80.0f;
    gMarioState->faceAngle[1] = o->oFaceAngleYaw;
    gMarioState->forwardVel = 50.0f;
    gMarioState->pos[1] += 20.0f;
   }
}


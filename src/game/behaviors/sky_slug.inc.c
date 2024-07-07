void bhv_sky_slug_init(void) {

}

void bhv_sky_slug_loop(void) {
    if (o->oTimer == 1) {
            o->oForwardVel = 45.0f;
        }
        if (o->oTimer > 150 && o->oTimer <= 180) {
            o->oForwardVel = 0.0f;
            o->oMoveAngleYaw += 0x444;
        }
        if (o->oTimer == 181) {
            o->oForwardVel = 45.0f;
        }
        if (o->oTimer > 330 && o->oTimer <= 360) {
            o->oForwardVel = 0.0f;
            o->oMoveAngleYaw += 0x444;
            if (o->oTimer == 360) {
                o->oTimer = 0;
            }
        }

        cur_obj_move_xz_using_fvel_and_yaw();

    if ((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED) {
        struct Surface *waterFloor;
        find_water_level_and_floor(gMarioState->pos[0], gMarioState->pos[1] + 5000, gMarioState->pos[2], &waterFloor);

        //if (waterFloor && waterFloor->object && waterFloor->object == o) {
        if (o->oDistanceToMario < 1000) {
            gMarioState->pos[0] += o->oVelX;
            gMarioState->pos[1] += o->oVelY;
            gMarioState->pos[2] += o->oVelZ;
        }
        //}
        
        
    }
}


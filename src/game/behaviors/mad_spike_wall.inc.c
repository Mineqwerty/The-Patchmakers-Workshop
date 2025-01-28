void bhv_mad_spike_wall_init(void) {
   
}

void bhv_mad_spike_wall_loop(void) {
        Vec3f pointA;
    Vec3f pointB;
    Vec3f pointC;
    Vec3f pointD;

    s16 laserWidth = 445;
    s16 laserLength = 165;

    vec3f_set(pointA, o->oPosX + laserWidth * coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointB, o->oPosX + laserWidth * -coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * -sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointC, pointA[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointA[2] + laserLength * coss(o->oFaceAngleYaw));
    vec3f_set(pointD, pointB[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointB[2] + laserLength * coss(o->oFaceAngleYaw));


    if (point_inside_xz_tri(gMarioState->pos, pointA, pointB, pointC) || point_inside_xz_tri(gMarioState->pos, pointA, pointC, pointD)) {
        f32 hitHeight = o->oPosY + o->oDistanceToMario * -sins(o->oFaceAnglePitch);
        if (absf(o->oPosY - gMarioState->pos[1]) < 700 && gMarioState->action != ACT_BACKWARD_AIR_KB) {
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            o->oDamageOrCoinValue = 3;
            take_damage_and_knock_back(gMarioState, o);
            gMarioState->vel[1] = 5;
            gMarioState->forwardVel = 0.0f;
            gMarioState->faceAngle[1] = o->oAngleToMario + 0x8000;
        }
    }

    switch (o->oAction) {
        case 0:
            o->oPosY += 40.0f;
            if (o->oTimer % 15 == 0) {
            cur_obj_shake_screen(4);
            }

            if (o->oTimer % 4 == 0) {
                cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
            }

            if (o->oTimer == 30) {
                o->oAction++;
            }

            o->oFaceAngleYaw = o->oAngleToMario;
        break;
        case 1:
            if (o->oTimer == 30) {
                o->oAction++;
            }
        break;
        case 2:
            o->oForwardVel = 30.0f + o->oTimer / 2;
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer > 30) {
                o->oPosY -= 10;
                if (o->oTimer % 4 == 0) {
                    cur_obj_play_sound_2(SOUND_GENERAL_GRINDEL_ROLL);
                }
            }

            if (o->oTimer > 90)  {
                obj_mark_for_deletion(o);
            }
        break;
    }
}


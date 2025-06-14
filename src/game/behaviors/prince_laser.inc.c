void bhv_prince_laser_init(void) {
   
}

void bhv_prince_laser_loop(void) {
    Vec3f pointA;
    Vec3f pointB;
    Vec3f pointC;
    Vec3f pointD;

    s16 laserWidth = 320;
    s16 laserLength = 10000;

    vec3f_set(pointA, o->oPosX + laserWidth * coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointB, o->oPosX + laserWidth * -coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * -sins(o->oFaceAngleYaw + 0x50));

    //vec3f_set(pointA, o->oPosX + 300 * coss(o->oFaceAngleYaw + 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw + 0x50));
    //vec3f_set(pointB, o->oPosX + 300 * coss(o->oFaceAngleYaw - 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw - 0x50));
    vec3f_set(pointC, pointA[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointA[2] + laserLength * coss(o->oFaceAngleYaw));
    vec3f_set(pointD, pointB[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointB[2] + laserLength * coss(o->oFaceAngleYaw));


    if (point_inside_xz_tri(gMarioState->pos, pointA, pointB, pointC) || point_inside_xz_tri(gMarioState->pos, pointA, pointC, pointD)) {
        if (absf(o->oPosY - gMarioState->pos[1] - 60) < 100 && gMarioState->action != ACT_BACKWARD_AIR_KB) {
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            o->oDamageOrCoinValue = 3;
            take_damage_and_knock_back(gMarioState, o);
            gMarioState->vel[1] = 5;
            gMarioState->forwardVel = 0.0f;
            gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
        }
    }
}


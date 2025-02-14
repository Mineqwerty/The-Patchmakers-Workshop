struct ObjectHitbox sMadLaserTurretHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 12,
    /* numLootCoins:      */ 2,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};

void bhv_mad_laser_turret_init(void) {
    obj_set_hitbox(o, &sMadLaserTurretHitbox);
    o->oTimer += o->oBehParams2ndByte * 60;
    f32 dist;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvMantleOfMadness, &dist);
}

void bhv_mad_laser_turret_loop(void) {

    if (o->parentObj && o->parentObj->oMantleOfMadnessPhase != 1 && o->parentObj->oMantleOfMadnessPhase != 4) {
        o->oHealth = 0;
    }

    switch (o->oAction) {
        case 0:
            if (o->oTimer == 240) {
                spawn_object_relative(0, 0, 0, 0, o, MODEL_MAD_LASER, bhvMadLaser);
            }
            if (o->oTimer == 300) {
                o->oTimer = 0;
            }
        break;
    }
    if (o->oTimer < 270) {
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
    }

    obj_die_if_health_non_positive();

    o->oInteractStatus = 0;
}

void bhv_mad_laser_init(void) {

}

void bhv_mad_laser_loop(void) {

    if (o->oTimer == 10) {
        o->oOpacity = 50;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }
    if (o->oTimer == 20) {
        o->oOpacity = 50;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }

    if (o->oTimer < 20) {
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
    }

    if (o->oTimer >= 30 && o->oTimer <= 60) {
        o->oOpacity = 200;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }

    if (o->oTimer == 90) {
        obj_mark_for_deletion(o);
    }

    if (o->oOpacity > 0) {
        o->oOpacity = CLAMP(o->oOpacity - 4, 0, 255);
    }

    if (o->oTimer == 31) {
        Vec3f pointA;
    Vec3f pointB;
    Vec3f pointC;
    Vec3f pointD;

    s16 laserWidth = 120;
    s16 laserLength = 10000;

    vec3f_set(pointA, o->oPosX + laserWidth * coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointB, o->oPosX + laserWidth * -coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * -sins(o->oFaceAngleYaw + 0x50));
    vec3f_set(pointC, pointA[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointA[2] + laserLength * coss(o->oFaceAngleYaw));
    vec3f_set(pointD, pointB[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointB[2] + laserLength * coss(o->oFaceAngleYaw));


    if (point_inside_xz_tri(gMarioState->pos, pointA, pointB, pointC) || point_inside_xz_tri(gMarioState->pos, pointA, pointC, pointD)) {
        f32 hitHeight = o->oPosY + o->oDistanceToMario * -sins(o->oFaceAnglePitch);
        if (absf(hitHeight - gMarioState->pos[1] + 60) < 100 && gMarioState->action != ACT_BACKWARD_AIR_KB) {
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            o->oDamageOrCoinValue = 2;
            take_damage_and_knock_back(gMarioState, o);
            gMarioState->vel[1] = 5;
            gMarioState->forwardVel = 0.0f;
            gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
        }
    }
    }
}


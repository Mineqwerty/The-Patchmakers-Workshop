struct ObjectHitbox sSeraphimHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 50,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 60,
    /* numLootCoins:      */ 3,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 60,
};

void bhv_seraphim_init(void) {
    obj_set_hitbox(o, &sSeraphimHitbox);
}

void bhv_seraphim_loop(void) {
    object_step();
    
switch (o->oAction) {
    case 0:
        o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY + 200*sins(o->oTimer * 0x222), 0.4f);
        if (o->oDistanceToMario < 1000.0f) {
            o->oAction = 1;
        }
    break;
    case 1:
        o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.4f);
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
        approach_f32_asymptotic_bool(&o->oPosX, gMarioState->pos[0] + 600 * sins(0x8000 + gMarioState->faceAngle[1]), 0.09f);
        approach_f32_asymptotic_bool(&o->oPosZ, gMarioState->pos[2] + 600 * coss(0x8000 + gMarioState->faceAngle[1]), 0.09f);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
        if (o->oTimer == 119 && o->oDistanceToMario < 1000.0f) {
            o->oAction = 2;
            cur_obj_init_animation(1);
        }

        if (gMarioState->pos[1] > o->oPosY + 100) {
            o->oAction = 3;
        }
    break;
    case 2:
        approach_s32_bool(&o->oFaceAnglePitch, 0, 0x400, 0x400);
        approach_f32_asymptotic_bool(&o->oPosX, gMarioState->pos[0], 0.4f);
        approach_f32_asymptotic_bool(&o->oPosZ, gMarioState->pos[2], 0.4f);
        if (o->oTimer > 25 && o->oTimer < 41 && o->oTimer % 5 == 0) {
            struct Object *blob = spawn_object_relative(0, 0, -50, 0, o, MODEL_GOLD_BLOB, bhvGoldBlob);
            blob->oVelY = -20.0f;
            blob->oAction = 3;
        }

        if (o->oTimer == 90) {
            f32 dist;
            vec3f_get_lateral_dist(&o->oPosVec, &o->oHomeVec, &dist);
            //if (dist > 2000) {
                o->oAction = 3;
            //}
            //else {
            //    o->oAction = 0;
            //}
            cur_obj_init_animation(0);
        }

        if (gMarioState->pos[1] > o->oPosY + 100) {
            o->oAction = 3;
        }
    break;
    case 3:
    cur_obj_init_animation(0);
        approach_f32_asymptotic_bool(&o->oPosX, o->oHomeX, 0.02f);
        approach_f32_asymptotic_bool(&o->oPosZ, o->oHomeZ, 0.02f);
        if (o->oTimer >= 60) {
            o->oAction = 0;
        }
    break;
}
    
    

    
    obj_die_if_health_non_positive();
    o->oHealth = 60;

    
    o->oInteractStatus = 0;
}
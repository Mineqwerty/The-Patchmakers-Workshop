static struct ObjectHitbox sNeedleBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_needle_ball_init(void) {
    obj_set_hitbox(o, &sNeedleBallHitbox);
}

void bhv_needle_ball_loop(void) {
    if (o->oTimer < 5) {
        cur_obj_scale(CLAMP((f32)o->oTimer / 5.0f, 0.02f, 1.0f));
    }

    o->oVelY = 10*sins(o->oTimer * 0x222);

    o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1] + 100, 6);
    o->oPosY += o->oVelY;

    o->oMoveAngleYaw = o->oAngleToMario + 0x400*sins(o->oTimer * 0x50);
    o->oForwardVel = approach_f32(o->oForwardVel, 20.0f + 10 * sins(o->oTimer * 0x333), 5, 5);
    o->oFaceAngleYaw += 0x231;
    o->oFaceAnglePitch += 0x331;
    o->oFaceAngleRoll += 0x131;

    cur_obj_move_xz_using_fvel_and_yaw();
    f32 dist = 1000;
    vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);

    if (dist < 50 || o->oHealth <= 0 || o->oTimer > 500) {
        o->parentObj->oPatchmakerNeedleBallObj = NULL;
        spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        obj_mark_for_deletion(o);
    }
}


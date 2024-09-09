static struct ObjectHitbox sShadowBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_shadow_ball_init(void) {
    o->oVelY = 20.0f;
    o->oGravity = 1.4f;
}

void bhv_shadow_ball_loop(void) {
    o->oForwardVel = 30.0f;
    obj_set_hitbox(o, &sShadowBallHitbox);
    s16 collisionFlags = object_step();

    if ((collisionFlags & 1) == 1) {
        o->oVelY = 30.0f;
        cur_obj_play_sound_2(SOUND_NEW_SHADOW_BALL_BOUNCE);
    }

    if (o->oTimer > 180) {
        cur_obj_scale(CLAMP((1.0f - ((f32)(o->oTimer - 180) / 60.0f)), 0.02f, 1.0f));
        if (o->oTimer == 240) {
            obj_mark_for_deletion(o);
        }

        o->oInteractStatus = 0;
    }
}


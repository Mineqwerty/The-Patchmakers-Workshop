static struct ObjectHitbox sShadowSpikeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 75,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


void bhv_shadow_spike_init(void) {
    o->oHomeY = o->oPosY;
    obj_set_hitbox(o, &sShadowSpikeHitbox);
    cur_obj_play_sound_2(SOUND_NEW_SHADOW_SPIKE_EMERGE);
}

void bhv_shadow_spike_loop(void) {
    if (o->oTimer < 10) {
        o->oPosY = o->oHomeY - (f32)(10 - o->oTimer)*90.0f;
    }
    else if (o->oTimer > 80) {
        o->oPosY = o->oHomeY - (f32)(o->oTimer - 80)*90.0f;
    }
    else {
        o->oPosY = o->oHomeY;
    }

    if (o->oTimer == 90) {
        obj_mark_for_deletion(o);
    }


}

void bhv_shadow_spike_spawner_init(void) {
    o->oTimer += o->oBehParams2ndByte;
}

void bhv_shadow_spike_spawner_loop(void) {
    o->oFaceAngleYaw += 0x50 + o->oTimer * 20;

    if (o->oTimer < 90) {
        SET_BPARAM1(o->oPrimColorParams, (int)(o->oTimer * 2.7f));
    }
    else if (o->oTimer == 90 && o->oDistanceToMario < 2500) {
        spawn_object_relative(0, 0, 0, 0, o, MODEL_SHADOW_SPIKE, bhvShadowSpike);
        
    }
    else if (o->oTimer < 120) {
        SET_BPARAM1(o->oPrimColorParams, (int)((120 * o->oTimer) * 2.7f));
    }
    else {
        o->oTimer = 0;
    }
}


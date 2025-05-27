static struct ObjectHitbox sPMBubbleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pm_bubble_init(void) {
    o->oPotogooVelXZ = 0.3f;
    o->oPotogooApproachXZ = 1.0f;
    obj_set_hitbox(o, &sPMBubbleHitbox);
}

void bhv_pm_bubble_loop(void) {
    o->oForwardVel = 40.0f;
    if ((object_step_without_floor_orient() & OBJ_COL_FLAG_HIT_WALL)) {
        cur_obj_play_sound_1(SOUND_ACTION_SWIM_FAST);
        o->oAction = 1;
    }

    if (o->oAction == 1){
        o->oPotogooApproachXZ = 1.0f + 0.5f*sins(o->oTimer * 0x444);
        if (o->oTimer == 30) {
            o->oPotogooApproachXZ = 1.0f;
            o->oAction = 0;
        }
    }

    elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 1.0f, 0.1f, 0.3f);
    cur_obj_scale(o->oPotogooApproachXZ);

    if (gCurCutscene != -1 || o->oTimer == 240 || o->oInteractStatus != 0) {
        spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        obj_mark_for_deletion(o);
    }
}


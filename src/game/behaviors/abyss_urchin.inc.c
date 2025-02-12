static struct ObjectHitbox sAbyssUrchinHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 12,
    /* numLootCoins:      */ 5,
    /* radius:            */ 400,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 390,
    /* hurtboxHeight:     */ 590,
};

void bhv_abyss_urchin_init(void) {

}

void bhv_abyss_urchin_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer < 15) {
            cur_obj_scale(CLAMP((f32)o->oTimer / 15.0f, 0.02f, 1.0f));
        }
        else {
            cur_obj_scale(1.0f);
        }

        obj_set_hitbox(o, &sAbyssUrchinHitbox);

        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->oInteractStatus = INT_STATUS_NONE;
        }

        obj_die_if_health_non_positive();
    }

    if (o->oAction == 90) {
        if (gCurrAreaIndex == 5) {
            obj_mark_for_deletion(o);
        }

        if (o->oDistanceToMario > 5000) {
            cur_obj_unhide();
            cur_obj_become_tangible();
            o->oHealth = 12;
            o->oAction = 0;
        }
    }
}


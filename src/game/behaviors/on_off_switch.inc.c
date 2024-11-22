struct ObjectHitbox sOnOffSwitchHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  120,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 100,
    /* height:            */ 250,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 250,
};

void bhv_on_off_switch_init(void) {
   
}

void bhv_on_off_switch_loop(void) {
    if (!o->parentObj) {
        f32 dist;
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvOnOffController, &dist);
    }
    else {
        dbp(o->parentObj->oOnOffState);
        obj_set_hitbox(o, &sOnOffSwitchHitbox);
        cur_obj_set_model(MODEL_OFF_SWITCH + o->parentObj->oOnOffState);

        if (cur_obj_was_attacked_or_ground_pounded()) {
                spawn_mist_particles();
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->parentObj->oOnOffState = (o->parentObj->oOnOffState + 1) % 2;
        }
    }   
}


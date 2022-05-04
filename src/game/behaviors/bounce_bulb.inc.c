static struct ObjectHitbox sBounceBulbHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 92,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

#define ACT_BULB_IDLE 0
#define ACT_BULB_BOUNCE 1

void bhv_bounce_bulb_init(void) {
    obj_set_hitbox(o, &sBounceBulbHitbox);
}

void bhv_bounce_bulb_loop(void) {
    o->oInteractionSubtype = INT_SUBTYPE_BULB;
    switch (o->oAction) {
        case ACT_BULB_IDLE:
            if (o->oInteractStatus != INT_STATUS_NONE) {
                gMarioState->action = ACT_TRIPLE_JUMP;
                gMarioState->vel[1] = 90.0f;
                o->oInteractStatus = INT_STATUS_NONE;
                o->oTimer = 0;
                o->oAction = ACT_BULB_BOUNCE;
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BOUNCE_BULB_OPEN];
            }
            break;
        case ACT_BULB_BOUNCE:
        obj_scale_xyz(o, 1.0f + 0.3f*sins(0x1000 * o->oTimer), 1.0f + -0.3f*sins(0x1000 * o->oTimer), 1.0f + 0.3f*sins(0x1000 * o->oTimer));
        if (o->oTimer == 24) {
            o->oAction = ACT_BULB_IDLE;
            obj_scale_xyz(o, 1, 1, 1);
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BOUNCE_BULB];
        }
        
        break;
    }
}
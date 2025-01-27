struct ObjectHitbox sMantleOfMadnessHitbox = {
    /* interactType:      */ INTERACT_MANTLE_OF_MADNESS,
    /* downOffset:        */ 150,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 20,
    /* numLootCoins:      */ 2,
    /* radius:            */ 1000,
    /* height:            */ 3000,
    /* hurtboxRadius:     */ 990,
    /* hurtboxHeight:     */ 2990,
};

enum MantleOfMadnessPhases {
    MANTLE_OF_MADNESS_PHASE_BEGINNING_DEFAULT,
    MANTLE_OF_MADNESS_PHASE_LASER_TURRETS,
    MANTLE_OF_MADNESS_PHASE_CRUSHING_HANDS,
    MANTLE_OF_MADNESS_PHASE_FIRE_WALLS
};

enum MantleOfMadnessActions {
    MANTLE_OF_MADNESS_ACT_BEGINNING_CUTSCENE,
    MANTLE_OF_MADNESS_ACT_IDLE,
    MANTLE_OF_MADNESS_ACT_NEEDLE_BALL_STORM,
    MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE,
    MANTLE_OF_MADNESS_ACT_RAISE_SPIKE_WALL
};

void mantle_of_madness_control_face_twitch(void) {
    if (random_u16()%10 == 0) {
        o->oTwitchFrames = random_u16()%3 + 1;
    }

    if (o->oTwitchFrames < o->oEnemyInvincibilityTimer) {
        o->oTwitchFrames = o->oEnemyInvincibilityTimer;
    }

    cur_obj_set_model(MODEL_MANTLE_OF_MADNESS);
    if (o->oTwitchFrames > 0) {
        cur_obj_set_model(MODEL_MANTLE_OF_MADNESS_HURT);
        o->oTwitchFrames--;
    }
}

void mantle_of_madness_act_idle() {
    if (o->oTimer == 90) {
        o->oAction = MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE;
    }
}

void mantle_of_madness_act_needle_ball_storm(void) {
    if (o->oTimer % 4 == 0) {
        struct Object *needleBall = spawn_object_relative(0, 0, 600, 0, o, MODEL_NEEDLE_BALL, bhvNeedleBall);
        needleBall->oForwardVel = 100;
    }

    if (o->oTimer == 30) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}

void mantle_of_madness_act_needle_barrage(void) {
    if (o->oTimer % 2 == 0) {
        struct Object *needleBall = spawn_object_relative(0, -500, 100, random_u16()%300 - 150,  o, MODEL_PM_THROWN_NEEDLE, bhvPmThrownNeedle);
        //needleBall->oTimer = 28;
    }

    if (o->oTimer == 30) {
        o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
    }
}


void bhv_mantle_of_madness_init(void) {
    obj_set_hitbox(o, &sMantleOfMadnessHitbox);
    o->oHealth = 300;
    gBossMaxHealth = 300;
    gBossHealth = 300;
    o->oTwitchFrames = 0;
    o->oAction = MANTLE_OF_MADNESS_ACT_IDLE;
}

void bhv_mantle_of_madness_loop(void) {

    switch (o->oAction) {
        case MANTLE_OF_MADNESS_ACT_IDLE:
            mantle_of_madness_act_idle();
        break;
        case MANTLE_OF_MADNESS_ACT_NEEDLE_BALL_STORM:
            mantle_of_madness_act_needle_ball_storm();
        break;
        case MANTLE_OF_MADNESS_ACT_NEEDLE_BARRAGE:
            mantle_of_madness_act_needle_barrage();
        break;
    }

    mantle_of_madness_control_face_twitch();
    o->oInteractStatus = 0;

    gBossHealth = o->oHealth;

}


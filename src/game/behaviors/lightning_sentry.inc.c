void bhv_lightning_sentry_init(void) {

}

void bhv_lightning_sentry_loop(void) {
    if (o->oTimer % 60 == 59) {
        s16 attackRadius = 400;

        if (gCurrLevelNum == LEVEL_BOWSER_3) {
            attackRadius = 1200;
        }

        obj_attack_in_radius(o, (f32)attackRadius, 1, 1);

        for (int i = 0; i < attackRadius/30; i++) {
            spawn_object_relative(0, random_u16()%attackRadius - (attackRadius/2), random_u16() % (s16)((attackRadius*0.75f) - (attackRadius*0.75f * 0.5f)), random_u16()%attackRadius - (attackRadius/2), o, MODEL_BREAKER_SPARK, bhvBreakerSpark);
        }
    }
}


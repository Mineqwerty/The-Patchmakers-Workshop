void bhv_lightning_sentry_init(void) {

}

void bhv_lightning_sentry_loop(void) {
    if (o->oTimer % 60 == 59) {
        obj_attack_in_radius(o, 400.0f, 1, 1);

        for (int i = 0; i < 15; i++) {
            spawn_object_relative(0, random_u16()%400 - 200, random_u16()%300 - 150, random_u16()%400 - 200, o, MODEL_BREAKER_SPARK, bhvBreakerSpark);
        }
    }
}


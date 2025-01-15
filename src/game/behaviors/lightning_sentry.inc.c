void bhv_lightning_sentry_init(void) {

}

void bhv_lightning_sentry_loop(void) {
    if (o->oTimer % 60 == 59) {
        obj_attack_in_radius(o, 400.0f, 1, 1);
    }
}


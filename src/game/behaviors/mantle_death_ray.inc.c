void bhv_mantle_death_ray_init(void) {
    o->oOpacity = 1;
}

void bhv_mantle_death_ray_loop(void) {
    if (o->oTimer < 25) {
        o->oOpacity = CLAMP(10*o->oTimer, 0, 255);
    }
    else {
        o->oOpacity = 255;
    }
}


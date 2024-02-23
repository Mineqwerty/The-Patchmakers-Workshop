void bhv_moving_spectral_octagon_init(void) {
   
}

void bhv_moving_spectral_octagon_loop(void) {
    o->oForwardVel = 20 * sins(o->oTimer * 0x222);
}


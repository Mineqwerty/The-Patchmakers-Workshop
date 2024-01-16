void bhv_swinging_chandelier_init(void) {

}

void bhv_swinging_chandelier_loop(void) {
    o->oFaceAngleRoll = 0x2000 * sins(o->oTimer * 0x222);
    o->oMoveAngleRoll = 0x2000 * sins(o->oTimer * 0x222);
}


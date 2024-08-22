void bhv_cartoon_hand_init(void) {
    o->oHandDirection = 1;
    o->oTargetHandSpeed = random_u16() % 512;
    o->oCurrentHandSpeed = 0;
    o->oFaceAngleRoll = random_u16();
}

void bhv_cartoon_hand_loop(void) {
    if (((o->oCurrentHandSpeed >= o->oTargetHandSpeed) && o->oHandDirection == 1) || ((o->oCurrentHandSpeed <= o->oTargetHandSpeed) && o->oHandDirection == -1)) {
        o->oHandDirection *= -1;
        o->oTargetHandSpeed = o->oHandDirection * (random_u16() % 512);
    }

    o->oCurrentHandSpeed = approach_s32_symmetric(o->oCurrentHandSpeed, o->oTargetHandSpeed, 0x40);
    o->oFaceAngleRoll += o->oCurrentHandSpeed;
}


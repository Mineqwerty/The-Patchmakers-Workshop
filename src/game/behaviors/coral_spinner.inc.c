void bhv_coral_spinner_init(void) {
    if (GET_BPARAM1(o->oBehParams) == 1) {
        o->oFaceAnglePitch = -0x4000;
        o->oMoveAnglePitch = -0x4000;
    }

    o->oMoveAngleRoll = 0x200 * o->oBehParams2ndByte;
    o->oFaceAngleRoll = o->oMoveAngleRoll;
}

void bhv_coral_spinner_loop(void) {
    if (o->oTimer % 45 == 0) {
        o->oAngleVelRoll = 0x600;
    }

    o->oMoveAngleRoll += o->oAngleVelRoll;
    o->oFaceAngleRoll = o->oMoveAngleRoll;

    if (o->oAngleVelRoll > 0) {
        o->oAngleVelRoll -= 0x50;
    }
}


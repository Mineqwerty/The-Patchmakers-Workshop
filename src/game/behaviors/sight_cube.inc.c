void bhv_sight_cube_init(void) {

}

void bhv_sight_cube_loop(void) {
    o->oPosX = o->oHomeX + o->oBehParams2ndByte * 20 * sins((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer + o->oMoveAngleYaw);
    o->oPosZ = o->oHomeZ + o->oBehParams2ndByte * 20 * coss((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer + o->oMoveAngleYaw);

    o->oFaceAngleYaw += GET_BPARAM1(o->oBehParams * 10);
}


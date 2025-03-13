void bhv_pm_miasma_init(void) {
    o->oTimer += 11 * o->oBehParams2ndByte;
}

void bhv_pm_miasma_loop(void) {
    if (cur_obj_check_if_at_animation_end()) {
        cur_obj_init_animation(0);
    }

    if (o->parentObj) {
        o->oPosX = o->parentObj->oPosX;
        o->oPosY = o->parentObj->oPosY + 180;
        o->oPosZ = o->parentObj->oPosZ;

        o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;

        o->oFaceAngleRoll += 0x50 * sins(o->oTimer * 0x361);
    }
}


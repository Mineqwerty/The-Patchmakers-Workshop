void bhv_tfp_rotary_platform_init(void) {
    o->oTimer = o->oBehParams2ndByte * 30;
}

void bhv_tfp_rotary_platform_loop(void) {
   o->oPosX = o->oHomeX + (400.0f * sins(o->oTimer * 0x111));
   o->oPosZ = o->oHomeZ + (400.0f * coss(o->oTimer * 0x111));
}

void bhv_tfp_rotary_arm_init(void) {
    
}

void bhv_tfp_rotary_arm_loop(void) {
            o->oFaceAngleYaw += 0x111;
            o->oMoveAngleYaw += 0x111;
}


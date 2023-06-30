void bhv_tfp_checker_platform_init(void) {
   
}

void bhv_tfp_checker_platform_loop(void) {
   o->oPosY = o->oHomeY + (50 * sins(o->oTimer * 0x400));
   o->oMoveAngleYaw += 0x200;
}


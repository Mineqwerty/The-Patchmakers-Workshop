void bhv_scaling_stairs_init(void) {

}

void bhv_scaling_stairs_loop(void) {
    o->oScalingStairsScale = coss(o->oTimer * 0x222);

    if (o->oScalingStairsScale < 0.04f && o->oScalingStairsScale >= 0) {
        //o->oScalingStairsScale = 0.04f;
    }
    else if (o->oScalingStairsScale > -0.04f && o->oScalingStairsScale <= 0) {
        //o->oScalingStairsScale = -0.04f;
    }

    obj_scale_xyz(o, 1.0f, o->oScalingStairsScale, 1.0f);
}


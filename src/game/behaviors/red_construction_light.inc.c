void bhv_red_construction_light_init(void) {
    o->oTimer += random_u16() % 60;

    if (o->oBehParams2ndByte == 0) {
        SET_BPARAM1(o->oPrimColorParams, 255);
        SET_BPARAM2(o->oPrimColorParams, 0);
        SET_BPARAM3(o->oPrimColorParams, 0);
    }
    else {
        SET_BPARAM1(o->oPrimColorParams, 255);
        SET_BPARAM2(o->oPrimColorParams, 233);
        SET_BPARAM3(o->oPrimColorParams, 0);
        f32 dist;
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvPowerBreakerController, &dist);
    }
}

void bhv_red_construction_light_loop(void) {
    o->oOpacity = 128 + 127*sins(o->oTimer * 0x222);

    if (o->oBehParams2ndByte == 1) {
        if (o->parentObj->oAction >= 1 && o->parentObj->oTimer > 30) {
            cur_obj_enable_rendering();
        }
        else {
            cur_obj_disable_rendering();
        }
    } 
}


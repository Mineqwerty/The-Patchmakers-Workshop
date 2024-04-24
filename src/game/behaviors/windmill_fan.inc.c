void bhv_windmill_fan_init(void) {
    o->oMoveAngleRoll += random_u16();

    if (o->oBehParams2ndByte == 1) {
        struct Object *platform;
        s32 i;

        for (i = 0; i < 4; i++) {
            platform = spawn_object_relative(i, 0, 0, 0, o,
                                            MODEL_WINDMILL_PLATFORM,
                                            bhvWindmillPlatform);
            
        }
    }
}

void bhv_windmill_fan_loop(void) {
    o->oMoveAngleRoll += (o->oBehParams2ndByte == 1 ? 0x60 : 0x120);
}


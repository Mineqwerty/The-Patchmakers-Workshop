void bhv_wind_cloud_init(void) {
    o->oGravity = 0.0f;
}

void bhv_wind_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oVelY < 20.0f) {
                o->oVelY += 1.0f;
                o->oFaceAngleYaw += 0x100;

                if (o->oTimer % 3 == 0) {
                    struct Object *wind = spawn_object_relative(0, random_f32_around_zero(120.0f), -400, random_f32_around_zero(120.0f), o, MODEL_MIST, bhvWeakWindParticle);
                    SET_BPARAM3(wind->oBehParams, 1);
                    cur_obj_play_sound_2(SOUND_ENV_WIND1);
                }
            }

            if (o->oPosY > o->oHomeY + 10*o->oBehParams2ndByte) {
                o->oAction = 1;
            }

        break;
        case 1:
            if (o->oVelY > -10) {
                o->oVelY -= 1.0f;
            }

            if (o->oPosY < o->oHomeY) {
                o->oAction = 0;
            }

        break;
    }

    o->oFaceAngleYaw += 0x200;
}


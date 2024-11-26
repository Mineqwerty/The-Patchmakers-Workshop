void bhv_soul_mote_init(void) {
    o->oOpacity = 255;
}

void bhv_soul_mote_loop(void) {
    if (o->oAction == 0) {
        approach_f32_asymptotic_bool(&o->oPosX, gMarioState->pos[0] + 300 * sins((o->oBehParams2ndByte * 0x3000) + 0x200*(gGlobalTimer)), 0.09f);
        approach_f32_asymptotic_bool(&o->oPosZ, gMarioState->pos[2] + 300 * coss((o->oBehParams2ndByte * 0x3000) + 0x200*(gGlobalTimer)), 0.09f);
        approach_f32_asymptotic_bool(&o->oPosY, gMarioState->pos[1] + 300 * sins((o->oBehParams2ndByte * 0x3000) + 0x200*(gGlobalTimer)), 0.19f);

        o->oOpacity = 50;
        switch (gMarioState->miasmaSoulCount) {
            case 1:
                SET_BPARAM1(o->oPrimColorParams, 0x1C);
                SET_BPARAM2(o->oPrimColorParams, 0x7E);
                SET_BPARAM3(o->oPrimColorParams, 0xFF);
            break;
            case 2:
                SET_BPARAM1(o->oPrimColorParams, 0x7C);
                SET_BPARAM2(o->oPrimColorParams, 0x65);
                SET_BPARAM3(o->oPrimColorParams, 0xAF);
            break;
            case 3:
                SET_BPARAM1(o->oPrimColorParams, 0xAC);
                SET_BPARAM2(o->oPrimColorParams, 0x58);
                SET_BPARAM3(o->oPrimColorParams, 0x86);
            break;
            case 4:
                SET_BPARAM1(o->oPrimColorParams, 0xEF);
                SET_BPARAM2(o->oPrimColorParams, 0x47);
                SET_BPARAM3(o->oPrimColorParams, 0x4F);
            break;
            case 5:;
                u8 r,g,b;
                r = 0xFF - abss(0xF0 * sins(o->oTimer * 0x222));
                g =  0x42 - abss(0x40 * sins(o->oTimer * 0x222));
                b =  0x42 - abss(0x40 * sins(o->oTimer * 0x222));
                SET_BPARAM1(o->oPrimColorParams, r);
                SET_BPARAM2(o->oPrimColorParams, g);
                SET_BPARAM3(o->oPrimColorParams, b);
                o->oOpacity = 150;
            break;
            default:
                SET_BPARAM1(o->oPrimColorParams, 255);
                SET_BPARAM2(o->oPrimColorParams, 255);
                SET_BPARAM3(o->oPrimColorParams, 255);
            break;
        }

        if (gMarioState->miasmaSoulCount < o->oBehParams2ndByte && gMarioState->miasmaArmorTimer > 0) {
            o->oAction = 1;
            o->oOpacity = 0;
            cur_obj_play_sound_2(SOUND_NEW_SOUL_MOTE_SHIELD);
        }
        else if (gMarioState->miasmaSoulCount < o->oBehParams2ndByte) {
            struct Object *flame = spawn_object_relative(0, 0, 0, 0, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flame->oBehParams = 0x01000000;
            obj_mark_for_deletion(o);
        }

    }
    else {
        o->oPosX = gMarioState->pos[0];
        o->oPosY = gMarioState->pos[1] + 80;
        o->oPosZ = gMarioState->pos[2];

        cur_obj_scale(3.0f);

        u8 r,g,b;
                r = 0x5F - abss(0x3F * sins(o->oTimer * 0x222));
                g =  0xB6 - abss(0x84 * sins(o->oTimer * 0x222));
                b =  0xD9 - abss(0x85 * sins(o->oTimer * 0x222));

        SET_BPARAM1(o->oPrimColorParams, r);
        SET_BPARAM2(o->oPrimColorParams, g);
        SET_BPARAM3(o->oPrimColorParams, b);

        o->oOpacity = approach_s16_symmetric(o->oOpacity, CLAMP(gMarioState->miasmaArmorTimer/2, 0, 127), 10);

        if (gMarioState->miasmaArmorTimer == 1) {
            struct Object *flame = spawn_object_relative(0, 0, 0, 0, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flame->oBehParams = 0x01000000;
            obj_mark_for_deletion(o);
        }
    }
}


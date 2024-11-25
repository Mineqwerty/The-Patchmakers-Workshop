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

        if (gMarioState->miasmaSoulCount == o->oBehParams2ndByte && gMarioState->miasmaArmorTimer > 0) {
            o->oAction = 1;
            gMarioState->miasmaSoulCount--;
        }
        else if (gMarioState->miasmaSoulCount < o->oBehParams2ndByte) {
            obj_mark_for_deletion(o);
        }

    }
    else {
        
    }
}


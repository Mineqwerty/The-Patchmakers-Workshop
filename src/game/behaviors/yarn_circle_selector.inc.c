void bhv_yarn_circle_selector_init(void) {
    o->oF4 = 0;
    o->oF8 = 0;
    o->oFaceAngleYaw = 0;
}

void bhv_yarn_circle_selector_loop(void) {
    struct Object *selectedFile = cur_obj_find_object_with_bparam_2nd_byte(bhvFileController, o->oF4+1);

    if (selectedFile) {
        o->oPosX = selectedFile->oPosX;
        o->oPosY = selectedFile->oPosY + 3;
        o->oPosZ = selectedFile->oPosZ;
    }

    if (o->oF8 == 0) {
        switch (o->oF4) {
            case 0:
                
            SET_BPARAM1(o->oPrimColorParams, 200);
            SET_BPARAM2(o->oPrimColorParams, 0);
            SET_BPARAM3(o->oPrimColorParams, 0);
            break;
            case 1:
                
            SET_BPARAM1(o->oPrimColorParams, 0);
            SET_BPARAM2(o->oPrimColorParams, 0);
            SET_BPARAM3(o->oPrimColorParams, 200);
            break;
            case 2:
                
            SET_BPARAM1(o->oPrimColorParams, 180);
            SET_BPARAM2(o->oPrimColorParams, 60);
            SET_BPARAM3(o->oPrimColorParams, 0);
            break;
            case 3:
                
            SET_BPARAM1(o->oPrimColorParams, 0);
            SET_BPARAM2(o->oPrimColorParams, 200);
            SET_BPARAM3(o->oPrimColorParams, 0);
            break;
        }
    }
    else {
        SET_BPARAM1(o->oPrimColorParams, (u8)(255*absf(sins(o->oTimer * 0x179))));
        SET_BPARAM2(o->oPrimColorParams, (u8)(255*absf(sins(o->oTimer * 0x79))));
        SET_BPARAM3(o->oPrimColorParams, (u8)(255*absf(sins(o->oTimer * 0x129))));
    }
}


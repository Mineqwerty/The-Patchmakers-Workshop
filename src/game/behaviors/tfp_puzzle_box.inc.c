void bhv_tfp_puzzle_box_init(void) {
   switch (o->oBehParams2ndByte) {
    case 0:
        SET_BPARAM1(o->oPrimColorParams, 255);
        SET_BPARAM2(o->oPrimColorParams, 255);
        SET_BPARAM3(o->oPrimColorParams, 255);
    break;
    case 1:
        SET_BPARAM1(o->oPrimColorParams, 255);
    break;  
    case 2:
        SET_BPARAM2(o->oPrimColorParams, 255);
    break;  
    case 3:
        SET_BPARAM3(o->oPrimColorParams, 255);
    break;  
   }
}

void bhv_tfp_puzzle_box_loop(void) {
    switch (o->oBehParams2ndByte) {
    case 0:
        SET_BPARAM1(o->oPrimColorParams, 255);
        SET_BPARAM2(o->oPrimColorParams, 255);
        SET_BPARAM3(o->oPrimColorParams, 255);
    break;
    case 1:
        SET_BPARAM1(o->oPrimColorParams, 255);
    break;  
    case 2:
        SET_BPARAM2(o->oPrimColorParams, 255);
    break;  
    case 3:
        SET_BPARAM3(o->oPrimColorParams, 255);
    break;  
   }
}


void bhv_underwater_stone_door_init(void) {

}

void bhv_underwater_stone_door_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer >= o->oBehParams2ndByte * 30) {
                o->oAction++;
            }
        break;
        case 1:
            o->oPosY -= 40.0f;
            if (o->oTimer == 45) {
                o->oAction++;
            }
        break;
    }
}

void bhv_underwater_stone_button_init(void) {
    
}

void bhv_underwater_stone_button_loop(void) {

}


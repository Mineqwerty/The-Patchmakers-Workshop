void bhv_goddess_init(void) {

}

void bhv_goddess_loop(void) {
    switch (o->oAction) {
        case 0: 
            cur_obj_init_animation(1);
            if (o->oTimer == 300) {
                o->oAction = 1;
            }
        break;

        case 1: 
            if (cur_obj_init_animation_and_check_if_near_end(2)) {
                o->oAction = 2;
            }

            o->oPosZ -= 20.0f;
            o->oPosY += 5.0f;
        break;

        case 2: 
            cur_obj_init_animation(0);

            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);

        break;
    }
}
#define GODDESS_ACT_CUTSCENE    0
#define GODDESS_ACT_IDLE_FLIGHT    1
#define GODDESS_ACT_GOLD_BARRAGE    2
#define GODDESS_ACT_SPEAR_DIVE  3
#define GODDESS_ACT_CLOSE_COMBAT    4
#define GODDESS_ACT_GROUND_SHOT    5
#define GODDESS_ACT_FLY_UP    6
#define GODDESS_ACT_BANISH    7

void bhv_goddess_init(void) {
    create_dialog_box(60);
    
}

void bhv_goddess_loop(void) {

    
    switch (o->oAction) {
        case GODDESS_ACT_CUTSCENE: goddess_act_cutscene(); break;
        case GODDESS_ACT_IDLE_FLIGHT: goddess_act_idle_flight(); break;
        case GODDESS_ACT_GOLD_BARRAGE: goddess_act_gold_barrage(); break;
        case GODDESS_ACT_SPEAR_DIVE: goddess_act_spear_dive(); break;
        case GODDESS_ACT_CLOSE_COMBAT: goddess_act_close_combat(); break;
        case GODDESS_ACT_GROUND_SHOT: goddess_act_ground_shot(); break;
        case GODDESS_ACT_FLY_UP: goddess_act_fly_up(); break;
        case GODDESS_ACT_BANISH: goddess_act_banish(); break;
    }
    
}

void goddess_act_idle_flight(void) {
    if (o->oTimer == 60) {
        switch (random_u16() % 2) {
            case 0:
                o->oAction = GODDESS_ACT_GOLD_BARRAGE;
            break;
            case 1:

            break;
        }
    }
}

void goddess_act_gold_barrage(void) {
    
}

void goddess_act_spear_dive(void) {

}

void goddess_act_close_combat(void) {

}

void goddess_act_ground_shot(void) {

}

void goddess_act_fly_up(void) {
    
}

void goddess_act_banish(void) {

}

void goddess_act_cutscene(void) {

    gCamera->cutscene = 1;
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gLakituState.goalPos[0] = -1495;
    gLakituState.goalPos[1] = 912;
    gLakituState.goalPos[2] = -1726;

    gLakituState.goalFocus[0] = -107;
    gLakituState.goalFocus[1] = 1792;
    gLakituState.goalFocus[2] = 706;

    switch (o->oSubAction) {
        case 0: 
            cur_obj_init_animation(1);
            if (o->oTimer == 600) {
                o->oSubAction = 1;
            }
        break;

        case 1: 
            if (cur_obj_init_animation_and_check_if_near_end(2)) {
                o->oSubAction = 2;
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
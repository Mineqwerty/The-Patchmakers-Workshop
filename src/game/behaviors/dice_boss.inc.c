void bhv_dice_boss_init(void) {

}

void bhv_dice_boss_loop(void) {

    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500) {
                o->oAction = 1;
            }
        break;
        case 1:
            switch (o->oDiceBossCurrentDie) {
                case 0:
                    o->oDiceBossDieObj = spawn_object_relative(0, 0, 100, 0, o, MODEL_D4, bhvD4);
                break;
            }

            o->oAction = 2;
        break;
        case 2:
            o->oDiceBossCurrentDie++;
        break;
    }
    
}

void bhv_d4_init(void) {

}

void bhv_d4_loop(void) {

}

enum StarUnlockPlatformActions {
    STAR_UNLOCK_ACTION_IDLE,
    STAR_UNLOCK_ACTION_RAISE_NUMBER,
    STAR_UNLOCK_ACTION_NUMBER_UP,
    STAR_UNLOCK_ACTION_LOWER_NUMBER,
    STAR_UNLOCK_ACTION_UNLOCK_COURSE_ENTRY,
};

void bhv_star_unlock_platform_init(void) {

}

void bhv_star_unlock_platform_loop(void) {
    switch (o->oAction) {
        case STAR_UNLOCK_ACTION_IDLE:
            if (gMarioObject->platform == o) {
                if (GET_BPARAM1(o->oBehParams) >= 10) {
                    if (!o->oStarCountNum1) o->oStarCountNum1 = spawn_orange_number_star_count(GET_BPARAM1(o->oBehParams) % 10, 56, 0, 0);
                    if (!o->oStarCountNum2) o->oStarCountNum2 = spawn_orange_number_star_count(GET_BPARAM1(o->oBehParams) / 10, 28, 0, 0);
                    if (!o->oStarCountNumStar) o->oStarCountNumStar = spawn_orange_number_star_count(10, -28, 0, 0);
                }
                else {
                    if (!o->oStarCountNum1) o->oStarCountNum1 = spawn_orange_number_star_count(GET_BPARAM1(o->oBehParams), 42, 0, 0);
                    if (!o->oStarCountNumStar) o->oStarCountNumStar = spawn_orange_number_star_count(10, -28, 0, 0);
                }
                o->oAction = STAR_UNLOCK_ACTION_RAISE_NUMBER;
            }
        break;
        case STAR_UNLOCK_ACTION_NUMBER_UP:
            if (gMarioState->numStars >= GET_BPARAM1(o->oBehParams)) {
                spawn_object(gMarioObject, MODEL_STAR, bhvUnlockDoorStar);
                o->oAction = STAR_UNLOCK_ACTION_UNLOCK_COURSE_ENTRY;
            }
        break;
        case STAR_UNLOCK_ACTION_LOWER_NUMBER:
            if (!o->oStarCountNum1 && !o->oStarCountNum2 && !o->oStarCountNumStar) {
                o->oAction = STAR_UNLOCK_ACTION_IDLE;
            }
        break;
    }

    if (o->oAction != STAR_UNLOCK_ACTION_IDLE && o->oAction != STAR_UNLOCK_ACTION_UNLOCK_COURSE_ENTRY && gMarioObject->platform != o) {
        o->oAction = STAR_UNLOCK_ACTION_LOWER_NUMBER;
    }
}


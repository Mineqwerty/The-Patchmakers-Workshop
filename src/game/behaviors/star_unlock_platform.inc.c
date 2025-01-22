#include "src/game/save_file.h"

enum StarUnlockPlatformActions {
    STAR_UNLOCK_ACTION_IDLE,
    STAR_UNLOCK_ACTION_RAISE_NUMBER,
    STAR_UNLOCK_ACTION_NUMBER_UP,
    STAR_UNLOCK_ACTION_LOWER_NUMBER,
    STAR_UNLOCK_ACTION_UNLOCK_COURSE_ENTRY,
};

u32 star_unlock_get_course_flag(void) {
    u32 courseFlag;
    switch (o->oBehParams2ndByte) {
        case 1:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_RDR;
        break;
        case 2:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_STC;
        break;
        case 3:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_CLC;
        break;
        case 4:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_HVH;
        break;
        case 5:
            courseFlag = SAVE_FLAG_UNLOCKED_HUB_3_DOOR;
        break;
        case 6:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_CORR;
        break;
        case 7:
            courseFlag = SAVE_FLAG_UNLOCKED_COURSE_TS;
        break;
        default:
            courseFlag = SAVE_FLAG_FILE_EXISTS;
        break;
    }

    return courseFlag;
}

void bhv_star_unlock_platform_init(void) {
    if (save_file_get_flags() & star_unlock_get_course_flag()) {
        obj_mark_for_deletion(o);
    }
}

void bhv_star_unlock_platform_loop(void) {
    switch (o->oAction) {
        case STAR_UNLOCK_ACTION_IDLE:
            if (gMarioObject->platform == o) {
                if (GET_BPARAM1(o->oBehParams) >= 10) {
                    if (!o->oStarCountNum1) o->oStarCountNum1 = spawn_orange_number_star_count(GET_BPARAM1(o->oBehParams) % 10, 78, 0, 0);
                    if (!o->oStarCountNum2) o->oStarCountNum2 = spawn_orange_number_star_count(GET_BPARAM1(o->oBehParams) / 10, 28, 0, 0);
                    if (!o->oStarCountNumStar) o->oStarCountNumStar = spawn_orange_number_star_count(10, -42, 0, 0);
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
                save_file_set_flags(star_unlock_get_course_flag());
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


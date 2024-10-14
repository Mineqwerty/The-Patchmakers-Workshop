enum BlightActions {
    BLIGHT_ACT_IDLE,
    BLIGHT_ACT_ENRAGED
};

void blight_check_enraged(void) {
    s16 relativeAngleToMario = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
    s16 relativeMarioFaceAngle = abs_angle_diff(o->oMoveAngleYaw, gMarioObject->oFaceAngleYaw);
    s16 relativeAngleToMarioThreshhold = 0x1568;
    s16 relativeMarioFaceAngleThreshhold = 0x6B58;
    s32 doneAppearing = FALSE;

    o->oVelY = 0.0f;

    if (relativeAngleToMario > relativeAngleToMarioThreshhold
        || relativeMarioFaceAngle < relativeMarioFaceAngleThreshhold) {
        obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);
        o->oMoveAngleYaw = o->oFaceAngleYaw;
    } else if (o->oDistanceToMario < 500) {
        o->oAction = BLIGHT_ACT_ENRAGED;
    }

}

void bhv_blight_init(void) {
   
}

void bhv_blight_loop(void) {
    switch (o->oAction) {
        case BLIGHT_ACT_IDLE:
            o->oForwardVel = 0;
            blight_check_enraged();
        break;
        case BLIGHT_ACT_ENRAGED:
            obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x800);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            o->oForwardVel = 8.0f;
            o->oPosY = approach_f32_asymptotic(o->oPosY, gMarioState->pos[1] + 20, 0.09f);

            if (o->oTimer == 450) {
                o->oAction = BLIGHT_ACT_IDLE;

            }
        break;
    }

    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
}


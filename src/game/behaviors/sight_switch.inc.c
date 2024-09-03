void bhv_sight_switch_init(void) {
    f32 dist;
    if (o->oBehParams == 0) {
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSightCube, &dist);
    }
    else {
        o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvMovingSightCube, &dist);
    }
}

void bhv_sight_switch_loop(void) {
    switch(o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o) {
                o->oAction = 1;
                cur_obj_set_model(MODEL_SIGHT_SWITCH_ACTIVE);
            }
        break;
        case 1:
            if (o->oTimer == 30) {
                o->oBehParams = 0x00010000;
                o->oBehParams2ndByte = 1;
            }
        break;
    }

    o->oPosX = o->parentObj->oPosX;
    o->oPosY = o->parentObj->oPosY;
    o->oPosZ = o->parentObj->oPosZ;

    o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw;
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}


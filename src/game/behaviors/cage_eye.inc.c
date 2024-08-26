void bhv_cage_eye_init(void) {
   
}

void bhv_cage_eye_loop(void) {
    o->oMoveAngleYaw = o->oAngleToMario + (o->oF4 * 0x1000);

    if (!o->parentObj || o->parentObj->oHealth == 0) {
        obj_mark_for_deletion(o);
    }
}


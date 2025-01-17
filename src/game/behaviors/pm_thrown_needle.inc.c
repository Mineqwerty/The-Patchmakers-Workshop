void bhv_pm_thrown_needle_init(void) {

}

void bhv_pm_thrown_needle_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY += 30 - o->oTimer;

            if  (o->oTimer == 30) {
                o->oAction = 1;
            }
        break;
        case  1:
                obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
                obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
                obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
            if (o->oTimer == 20) {
                
                o->oAction  = 2;
            }
        break;
        case 2:
            o->oForwardVel = 135.0f * coss(o->oFaceAnglePitch);
                    o->oVelY = -135.0f * sins(o->oFaceAnglePitch);
                    o->oDragStrength = 0.0f;
                    o->oGravity = 0.0f;

                    if ((object_step_without_floor_orient() & OBJ_COL_FLAG_GROUNDED) || o->oTimer > 120) {
                        o->oVelY = 0;
                        o->oForwardVel = 0;
                        o->oAction = 3;
                    }
        break;
        case 3:
            if (o->oTimer > 30)  {
                cur_obj_scale(1.0f - (o->oTimer - 30)/30.0f);
            }
            if (o->oTimer == 59) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}


void bhv_floating_plane_init(void) {
    
   SET_BPARAM1(o->oPrimColorParams, random_u16() / 0x100);
   SET_BPARAM2(o->oPrimColorParams, random_u16() / 0x100);
   SET_BPARAM3(o->oPrimColorParams, random_u16() / 0x100);
   //o->oPrimColorParams = o->oBehParams;
}

void bhv_floating_plane_loop(void) {
    // o->oPrimColorParams = o->oBehParams;

    switch (o->oAction) {
        case 0:

            if (o->oTimer >= o->oNextPlaneRotation) {
                o->oFaceAngleYaw = random_u16();
                o->oFaceAngleRoll = random_u16();
                o->oFaceAnglePitch = random_u16();
                o->oNextPlaneRotation = random_u16() / 0x200;
                o->oTimer = 0;
            }

            if (o->oDistanceToMario < 200.0f) {
               o->oAngleVelPitch = random_u16() / 0x50;
               o->oAngleVelYaw = random_u16() / 0x50;
               o->oAngleVelRoll = random_u16() / 0x50;
               SET_BPARAM1(o->oPrimColorParams, random_u16() / 0x100);
               SET_BPARAM2(o->oPrimColorParams, random_u16() / 0x100);
               SET_BPARAM3(o->oPrimColorParams, random_u16() / 0x100);
               o->oAction = 1;
            }
            break;

        case 1:
            cur_obj_rotate_face_angle_using_vel();

            if (o->oAngleVelPitch > 0) {
               o->oAngleVelPitch -= 0x100;
            }
            if (o->oAngleVelYaw > 0) {
               o->oAngleVelPitch -= 0x100;
            }
            if (o->oAngleVelRoll > 0) {
               o->oAngleVelPitch -= 0x100;
            }

            if (o->oTimer == 150) {
               o->oAction = 0;
            }
            break;
    }

}

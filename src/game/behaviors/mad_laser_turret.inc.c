void bhv_mad_laser_turret_init(void) {

}

void bhv_mad_laser_turret_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 240) {
                spawn_object_relative(0, 0, 0, 0, o, MODEL_MAD_LASER, bhvMadLaser);
            }
            if (o->oTimer == 300) {
                o->oTimer = 0;
            }
        break;
    }
    if (o->oTimer < 270) {
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
    }
}

void bhv_mad_laser_init(void) {

}

void bhv_mad_laser_loop(void) {

    if (o->oTimer == 10) {
        o->oOpacity = 50;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }
    if (o->oTimer == 20) {
        o->oOpacity = 50;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }

    if (o->oTimer < 20) {
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);
    }

    if (o->oTimer >= 30 && o->oTimer <= 60) {
        o->oOpacity = 200;
        cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
    }

    if (o->oTimer == 90) {
        obj_mark_for_deletion(o);
    }

    if (o->oOpacity > 0) {
        o->oOpacity = CLAMP(o->oOpacity - 4, 0, 255);
    }
}


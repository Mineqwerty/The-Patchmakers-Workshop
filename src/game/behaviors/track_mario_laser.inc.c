void bhv_track_mario_laser_init(void) {
    o->oOpacity = 255;
}

void bhv_track_mario_laser_loop(void) {
    if (o->oTimer < 80) {
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x40);
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x80);
    }
    else {
        cur_obj_scale(1.0f - ((f32)(o->oTimer-80) / 10.0f));
        if (o->oTimer == 89) {
            obj_mark_for_deletion(o);
        }
    }

    struct Surface *surf;
            Vec3f originPos;
            Vec3f hitpos;
            Vec3f raydir;

            raydir[0] = sins(o->oFaceAngleYaw) * 6000.0f;
            raydir[1] = -sins(o->oFaceAnglePitch) * 6000.0f - 160;
            raydir[2] = coss(o->oFaceAngleYaw) * 6000.0f;

            vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

            vec3f_set(originPos, o->oPosX, o->oPosY, o->oPosZ);

            find_surface_on_ray(originPos, raydir, &surf, hitpos, 1U, 1);
            if (surf != NULL && o->oTimer % 10 == 0) {
                spawn_object_abs_with_rot(o, 0, MODEL_EXPLOSION, bhvExplosion, 
                hitpos[0], hitpos[1] + 50, hitpos[2],
                0, 0, 0);
            }
}


void bhv_paper_bomp_init(void) {

}

void bhv_paper_bomp_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            struct Object *throwMetalBox;
            f32 dist = 1000;
            throwMetalBox = cur_obj_find_nearest_object_with_behavior(bhvMetalBoxSmall, &dist);
            if (throwMetalBox) {
                vec3f_get_lateral_dist(&o->oPosVec, &throwMetalBox->oPosVec, &dist);
                if (dist < 300.0f && absf(throwMetalBox->oPosY - o->oPosY) < 1500) {
                    o->oAction = 1;
                    o->oForwardVel = 10.0f;
                    o->oVelY = 10.0f;
                    cur_obj_play_sound_1(SOUND_ACTION_HIT);
                } 
            }
        break;
        case 1:
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oPosY += o->oVelY;
            o->oVelY -= 2;

            o->oFaceAngleYaw += 0x777;

            if (o->oTimer == 90) {
                obj_mark_for_deletion(o);
            }

        break;
    }
}


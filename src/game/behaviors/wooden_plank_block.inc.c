void bhv_wooden_plank_block_init(void) {

}

void bhv_wooden_plank_block_loop(void) {

    switch (o->oAction) {
        case 0:;
            f32 dist;
            struct Object *flame = cur_obj_find_nearest_object_with_behavior(bhvFlameMovingForwardGrowing, &dist);

            if (flame && dist < 300) {
                o->oAction = 1;
            }

            struct Object *bowser = cur_obj_find_nearest_object_with_behavior(bhvBowser, &dist);

            if (bowser) {
                dist = lateral_dist_between_objects(o, bowser);
            }
            if (bowser && bowser->oAction == 3 && bowser->oTimer >= 16 && dist < 300) {
                struct Object *fragment = spawn_object_relative(0, 0, 0, 0, o, MODEL_WOODEN_PLANK_LEFT, bhvWoodenPlankFragment);
                fragment->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
                fragment = spawn_object_relative(2, 0, 0, 0, o, MODEL_WOODEN_PLANK_RIGHT, bhvWoodenPlankFragment);
                fragment->oMoveAngleYaw = o->oFaceAngleYaw - 0x4000;
                cur_obj_hide();
                o->oAction = 2;
                //gSlowdownCount = 2;
            }
        break;
        case 1:;
            if (o->oTimer % 4 == 0) {
                spawn_object_relative(0, 0, random_u16()%400 - 200, random_u16()%600 - 300, o, MODEL_RED_FLAME, bhvFlameLargeBurningOut);
            }

            if (o->oTimer == 60) {
                obj_mark_for_deletion(o);
            }
        break;
        case 2:
            if (o->oTimer >= 2) {
                //gSlowdownCount = 0;
                obj_mark_for_deletion(o);
            }
        break;
    }
}

void bhv_wooden_plank_fragment_init(void) {
    cur_obj_play_sound_1(SOUND_GENERAL_BREAK_BOX);
}

void bhv_wooden_plank_fragment_loop(void) {
    o->oVelY -= 2;
    o->oPosY += o->oVelY;
    o->oForwardVel = 6.0f;
    cur_obj_move_xz_using_fvel_and_yaw();
    o->oFaceAngleRoll += 0x100 * ((s16)o->oBehParams2ndByte - 1);
}


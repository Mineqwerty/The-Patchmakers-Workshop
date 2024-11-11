void bhv_wooden_plank_block_init(void) {

}

void bhv_wooden_plank_block_loop(void) {
    f32 dist;
    struct Object *bowser = cur_obj_find_nearest_object_with_behavior(bhvBowser, &dist);

    if (bowser) {
        dist = lateral_dist_between_objects(o, bowser);
    }
    if (bowser && bowser->oAction == 3 && bowser->oTimer >= 16 && dist < 300) {
        struct Object *fragment = spawn_object_relative(0, 0, 0, 0, o, MODEL_WOODEN_PLANK_LEFT, bhvWoodenPlankFragment);
        fragment->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
        fragment = spawn_object_relative(2, 0, 0, 0, o, MODEL_WOODEN_PLANK_RIGHT, bhvWoodenPlankFragment);
        fragment->oMoveAngleYaw = o->oFaceAngleYaw - 0x4000;
        
        obj_mark_for_deletion(o);
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


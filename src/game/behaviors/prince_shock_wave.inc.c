void bhv_prince_shock_wave_init(void) {
   
}

void bhv_prince_shock_wave_loop(void) {
    f32 closingTime = 10.0f;
    f32 lateralScale = 4.0f + (f32)o->oTimer / 30.0f;
    obj_scale_xyz(o, lateralScale, 1.0f, lateralScale);

    if (o->oAction == 0) {

        f32 marioDist = lateral_dist_between_objects(o, gMarioState->marioObj);
        if (marioDist > 178*lateralScale && marioDist < 218*lateralScale && absf(gMarioState->pos[1] + 80 - o->oPosY) < 100 && gMarioState->action != ACT_SHOCKED && absf(o->oFaceAngleYaw - o->oAngleToMario) < 0x4000) {

            
            if (gMarioState->miasmaArmorTimer <= 0) {
                update_mario_sound_and_camera(gMarioState);
                drop_and_set_mario_action(gMarioState, ACT_SHOCKED, 0);
                take_damage_from_no_interact_object(gMarioState, 3);
                play_sound(SOUND_MARIO_ATTACKED, gMarioState->marioObj->header.gfx.cameraToObject);
            }
            else {
                gMarioState->invincTimer = 30;
            }
            o->oAction = 1;
        }
    }

    o->oForwardVel = 200;
    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oTimer > 90) {
        obj_mark_for_deletion(o);
    }
}


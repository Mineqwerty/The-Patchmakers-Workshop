void bhv_jelly_surround_circle_init(void) {
   
}

void bhv_jelly_surround_circle_loop(void) {
    if (o->oTimer == 1) {
        obj_set_model(o, MODEL_JELLY_SURROUND_CIRCLE);
    }
    f32 closingTime = 10.0f;
    f32 lateralScale = closingTime - (f32)o->oTimer / 30.0f;
    f32 verticalScale = CLAMP((f32)o->oTimer / 180.0f, 0.02f, 3.5f);
    obj_scale_xyz(o, lateralScale, verticalScale, lateralScale);

    if (o->oAction == 0) {

        f32 marioDist = lateral_dist_between_objects(o, gMarioState->marioObj);
        if (marioDist > 178*lateralScale && marioDist < 218*lateralScale && gMarioState->pos[1] < gMarioState->floorHeight + verticalScale) {

            take_damage_from_no_interact_object(gMarioState, 3);
            play_sound(SOUND_MARIO_ATTACKED, gMarioState->marioObj->header.gfx.cameraToObject);
            if (gMarioState->miasmaArmorTimer <= 0) {
                update_mario_sound_and_camera(gMarioState);
                drop_and_set_mario_action(gMarioState, ACT_SHOCKED, 0);
            }
            o->oAction = 1;
        }
    }

    if (lateralScale < 0.01f) {
        obj_mark_for_deletion(o);
    }
}


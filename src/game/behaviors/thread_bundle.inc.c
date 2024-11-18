void bhv_thread_bundle_init(void) {

}

void bhv_thread_bundle_loop(void) {

    if (gMarioState->action != ACT_CAUGHT_BY_STRING) {
            obj_mark_for_deletion(o);
            return;
        }

    o->oF4 += player_performed_grab_escape_action();

    if (o->oF4 >= 15) {
        set_mario_action(gMarioState, ACT_JUMP, 0);
        gMarioState->vel[1] = 10.0f;
        for (int i = 0; i < 10; i++) {
            spawn_object_relative(3, random_u16()%50 - 25, 5.0f + random_u16()%10, random_u16()%50 - 25, o, MODEL_THREAD_PARTICLE, bhvThreadParticle);
        }
        cur_obj_play_sound_1(SOUND_OBJ_UKIKI_STEP_LEAVES);
        obj_mark_for_deletion(o);
        return;
    }

    

    if (o->oTimer < 15) {
        cur_obj_scale(CLAMP((f32)o->oTimer / 15.0f, 0.02f, 1.0f));
    }

    o->oPosX = o->parentObj->oPosX;
    o->oPosY = o->parentObj->oPosY + 40;
    o->oPosZ = o->parentObj->oPosZ;
}


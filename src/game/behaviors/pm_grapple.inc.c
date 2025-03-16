#define GRAPPLE_FVEL 150.0f

void bhv_pm_grapple_init(void) {
    o->oForwardVel = GRAPPLE_FVEL;
}

void bhv_pm_grapple_loop(void) {
    o->oForwardVel -= 8.0f;

    if (o->oForwardVel <= -GRAPPLE_FVEL) {
        obj_mark_for_deletion(o);
    }

    if (o->oDistanceToMario < 200 && o->oAction == 0 && gMarioState->curPatch != PATCH_STONE) {
        o->oAction = 1;

        if (obj_has_model(o, MODEL_PM_SHADOWCHOMP_OPEN)) {
            cur_obj_play_sound_2(SOUND_SHADOWCHOMP_CHOMP);
            cur_obj_set_model(MODEL_PM_SHADOWCHOMP_CLOSED);
            take_damage_from_no_interact_object(gMarioState, 2);
        }
        else {
            cur_obj_play_sound_2(SOUND_GRAPPLE_HOOK_2);
        }
    }

    cur_obj_move_xz_using_fvel_and_yaw();

    if (o->oAction == 1) {
        set_mario_action(gMarioState, ACT_BACKWARD_AIR_KB, 0);
        gMarioState->pos[2] = o->oPosZ;
        gMarioState->pos[1] = o->oPosY;
        gMarioState->pos[0] = o->oPosX;
    }
}


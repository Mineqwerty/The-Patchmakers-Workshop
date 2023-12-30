void bhv_geyser_init(void) {

}

void bhv_geyser_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer >= 90 && o->oDistanceToMario < 2500) {
                o->oAction = 1;
            }
        break;
        case 1:
            if (o->oTimer % 3 == 0) {
                spawn_object_relative(0, 0, 20, 0, o, MODEL_MIST, bhvGeyserParticle);
            }

            cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);

            if (o->oTimer == 120) {
                o->oAction = 0;
            }
        break;
    }
}

void bhv_geyser_particle_init(void) {
    o->oVelY = 102.0f;
    o->oMoveAngleYaw = random_u16();
    o->oForwardVel = (random_u16() % 10) - 5;
    o->oGravity = 0.0f;
}

void bhv_geyser_particle_loop(void) {
    if (o->oDistanceToMario < 100) {
        gMarioState->vel[1] = o->oVelY;
        gMarioState->action = ACT_TRIPLE_JUMP;
    }

    if (o->oTimer == 20) {
        obj_mark_for_deletion(o);
    }
    cur_obj_scale(6.0f / (((f32) o->oTimer/2) + 1.0f) );

    o->oOpacity = 200 - (o->oTimer * 10);

    object_step_without_floor_orient();
}
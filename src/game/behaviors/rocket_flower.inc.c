void bhv_rocket_flower_init(void) {

}

void bhv_rocket_flower_loop(void) {

    Vec3f crabDisplacement, crabNewDisplacement;
    Vec3f original_pos;
    vec3f_copy(original_pos,&o->oPosX);

    switch (o->oAction) {
        case 0:
            if (o->oTimer < 10) {
                cur_obj_scale(CLAMP((f32) o->oTimer / 10.0f, 0.03f, 1.0f));
            }
            else {
                cur_obj_scale(1.0f);
            }

            if (o->oDistanceToMario < 200.0f) {
                o->oAction = 1;
                gMarioState->boostTimer = 210;
                gMarioState->forwardVel = 128;
            }
        break;
        case 1:
            cur_obj_set_model(MODEL_ROCKET_FLOWER_ROT);
            freeze_game_frames(10);
            o->oAction = 2;
            o->oLocalBoostTimer = gMarioState->boostTimer;
        case 2:
            mtxf_copy(o->transform,gMarioState->HeadMatrix);
            //o->transform[3][0] = gMarioState->HeadMatrix[3][0];
            //o->transform[3][1] = gMarioState->HeadMatrix[3][1];
            //o->transform[3][2] = gMarioState->HeadMatrix[3][2];
            //o->transform[3][3] = gMarioState->HeadMatrix[3][3];
            o->header.gfx.throwMatrix = &o->transform;

            vec3f_set(crabDisplacement, 120.0f, -50.f, 0.0f); // local displacement of the crab
            linear_mtxf_mul_vec3f(o->transform, crabNewDisplacement, crabDisplacement); // rotate it with mario's head
            vec3f_add(o->transform[3], crabNewDisplacement); // add position

            if (gMarioState->wall == NULL) {
                o->transform[3][0] += gMarioState->forwardVel * sins(gMarioState->faceAngle[1]);
                o->transform[3][2] += gMarioState->forwardVel * coss(gMarioState->faceAngle[1]);
                o->transform[3][1] += gMarioState->vel[1];
            }

            vec3f_copy(&o->oPosX,o->transform[3]); 

            vec3f_set(o->header.gfx.scale,3.5f,3.5f,3.5f);

            o->oFaceAngleYaw = gMarioState->faceAngle[1] + 0x8000;
            o->oMoveAngleYaw = gMarioState->faceAngle[1] + 0x8000;

            

            if (gMarioState->boostTimer <= 5 || (o->oLocalBoostTimer != gMarioState->boostTimer)) {
                o->oAction = 3;
                o->oForwardVel = 10.0f;
                o->oMoveAngleYaw = random_u16();
            }

            o->oLocalBoostTimer--;

            if (o->oTimer % 3 == 0) {
                struct Object *flameParticle = spawn_object_relative(0, 0, 100, 100, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flameParticle->oVelY = (random_u16() % 8 + 5) / 2.8f;
                flameParticle->oMoveAngleYaw += (random_u16() % 0x1000) - 0x800;
                flameParticle->oForwardVel = 10.0f - gMarioState->forwardVel / 3.0f;

                cur_obj_play_sound_1(SOUND_ENV_WIND2);
            }

        break;
        case 3:
            
            vec3f_set(o->header.gfx.scale,1.0f,1.0f,1.0f);
            cur_obj_set_model(MODEL_ROCKET_FLOWER);

            o->oVelY -= 1.0f;

            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);

            if (o->oTimer == 15) {
                spawn_mist_particles_variable(0, 0, 46.0f);
                create_sound_spawner(SOUND_OBJ_DEFAULT_DEATH);
                if (o->parentObj) {
                    o->parentObj->oRocketFlowerSpawned = NULL;
                }
                obj_mark_for_deletion(o);
            }
        break;
    }
    
}

void bhv_rocket_flower_spawn_init(void) {
    o->oRocketFlowerSpawned = spawn_object_relative(0, 0, 0, 0, o, MODEL_ROCKET_FLOWER, bhvRocketFlower);
}

void bhv_rocket_flower_spawn_loop(void) {
    if (!o->oRocketFlowerSpawned) {
        o->oRocketFlowerSpawned = spawn_object_relative(0, 0, 0, 0, o, MODEL_ROCKET_FLOWER, bhvRocketFlower);
    }
}


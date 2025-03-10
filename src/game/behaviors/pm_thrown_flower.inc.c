static struct ObjectHitbox sPMStoneFlowerHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pm_thrown_flower_init(void) {
    obj_set_hitbox(o, &sPMStoneFlowerHitbox);
}

struct SpawnParticlesInfo StoneFormFlower = {
    2, 25, MODEL_MIST, 20.0f, -20, 0, 20, 40, 252, 30, 15.0f, 0.0f
};

void bhv_pm_thrown_flower_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x1000;
            o->oPosY += 20;

            if (o->oTimer == 20) {
                o->oAction++;
            }
        break;
        case 1:
            o->oMoveAngleYaw = o->oAngleToMario;
            o->oFaceAngleYaw += 0x1000;
            f32 dist;
            vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
            o->oForwardVel = CLAMP(30 + 2*o->oTimer, 0, dist + 1);
            cur_obj_move_xz_using_fvel_and_yaw();

            if (o->oTimer == 60) {
                o->oAction++;
                o->oForwardVel = 0;
                o->oVelY = 0;
                cur_obj_play_sound_2(SOUND_STONE_PATCH_DEFORM);
                cur_obj_spawn_particles(&StoneFormFlower);
            }
        break;
        case 2:
            cur_obj_set_model(MODEL_PM_THROWN_FLOWER_STONE);
            if (o->oTimer >= 10) {
                o->oVelY -= 4;
            }

            o->oPosY += o->oVelY;
            o->oInteractStatus = 0;

            if ((object_step_without_floor_orient() & OBJ_COL_FLAG_GROUNDED) || o->oTimer > 120) {
                o->oVelY = 0;
                o->oForwardVel = 0;
                cur_obj_play_sound_1(SOUND_ACTION_TERRAIN_HEAVY_LANDING);
                cur_obj_spawn_particles(&StoneFormFlower);
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                o->oAction = 3;
            }
        break;
        case 3:
            if (o->oTimer > 30)  {
                cur_obj_scale(1.0f - (o->oTimer - 30)/30.0f);
            }
            if (o->oTimer == 59) {
                if (random_u16()%5 == 0) {
                    struct Object *coin = spawn_object(o, MODEL_YELLOW_COIN, bhvMovingYellowCoin);

                    cur_obj_play_sound_2(SOUND_GENERAL_COIN_SPURT);

                    coin->oForwardVel = 2.0f;
                    coin->oVelY = 10.0f;
                    coin->oPosY = o->oPosY + 10.0f;
                    coin->oMoveAngleYaw = random_u16();
                }
                obj_mark_for_deletion(o);
            }
        break;
    }
}


enum ShrineShadowActions {
    SHRINE_SHADOW_ACT_IDLE,
    SHRINE_SHADOW_ACT_MOVE_AWAY_FROM_MARIO,
    SHRINE_SHADOW_ACT_FIRE_PROJECTILES,
    SHRINE_SHADOW_ACT_SUMMON_SPIKES,
    SHRINE_SHADOW_ACT_TELEPORT
};

static struct ObjectHitbox sShrineShadowHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 18,
    /* numLootCoins:      */ 15,
    /* radius:            */ 200,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 300,
};

void shrine_shadow_decide_next_attack(void) {
    if (o->oDistanceToMario < 1000) {
        switch (random_u16() % 2) {
            case 0:
                o->oAction = SHRINE_SHADOW_ACT_MOVE_AWAY_FROM_MARIO;
            break;
            case 1:
                o->oTimer = 0;
                o->header.gfx.animInfo.animFrame = 0;
            break;
        }
    }
    else {
        o->oTimer = 0;
        o->header.gfx.animInfo.animFrame = 0;
    }
}

void bhv_shrine_shadow_init(void) {
    obj_set_hitbox(o, &sShrineShadowHitbox);
    o->oWallHitboxRadius = 200.0f;
}

void bhv_shrine_shadow_loop(void) {
    //gCollisionFlags &= ~(COLLISION_FLAG_RETURN_FIRST | COLLISION_FLAG_EXCLUDE_DYNAMIC | COLLISION_FLAG_INCLUDE_INTANGIBLE);
    cur_obj_update_floor_and_walls();

    switch (o->oAction) {
        case SHRINE_SHADOW_ACT_IDLE:
            cur_obj_init_animation(0);
            if (o->oDistanceToMario < 1500 && gMarioState->pos[1] > o->oPosY - 50) {
                o->oAction = SHRINE_SHADOW_ACT_MOVE_AWAY_FROM_MARIO;
            }
        break;
        case SHRINE_SHADOW_ACT_MOVE_AWAY_FROM_MARIO:
            if (o->oSubAction == 0) {
                s16 checkAngle = o->oAngleToMario + 0x8000 + 0x4000;
                s16 goalAngle = o->oAngleToMario + 0x8000;
                f32 goalDist = 0;
                f32 checkDist;
                Vec3f originPos;
                Vec3f hitpos;
                Vec3f raydir;

                //check nearby walls and go in the most ideal direction away from mario
                for (int i = 0; i < 4; i++) {

                    struct Surface *surf;
                            

                            raydir[1] = 0.0f;

                        vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);
                        vec3f_set(originPos, o->oPosX, o->oPosY, o->oPosZ);
                        raydir[0] = sins(checkAngle) * (2000);
                        raydir[1] = 0.0f;
                        raydir[2] = coss(checkAngle) * (2000);
                        find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);

                        if (surf != NULL) {
                            vec3f_get_dist(originPos, hitpos, &checkDist);
                            if (checkDist > goalDist) {
                                goalDist = checkDist;
                                goalAngle = checkAngle;
                            }
                        }
                        else {
                            goalDist = 2000;
                            goalAngle = checkAngle;
                        }
                    
                    checkAngle += 0x4000;
                }

                o->oMoveAngleYaw = goalAngle;
                o->oSubAction = 1;
                cur_obj_init_animation(1);
            }
            else {
                o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0x200);
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 30.0f, 6.0f);

                cur_obj_move_xz_using_fvel_and_yaw();

                if (o->oTimer == 70) {
                    o->oAction = SHRINE_SHADOW_ACT_FIRE_PROJECTILES + (random_u16() % 2);
                }

                if (cur_obj_check_if_at_animation_end()) {
                    cur_obj_init_animation(2);
                }


            }
        break;
        case SHRINE_SHADOW_ACT_FIRE_PROJECTILES:
            cur_obj_init_animation(4);

            obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            if (o->oTimer == 16 || o->oTimer == 22) {
                struct Object *ball = spawn_object_relative(0, 0, 200, 50, o, MODEL_SHADOW_BALL, bhvShadowBall);

                ball->oMoveAngleYaw += (random_u16() % 0x800) - 0x400;
            }

            if (o->oTimer == 40) {
                shrine_shadow_decide_next_attack();
            }


        break;
        case SHRINE_SHADOW_ACT_SUMMON_SPIKES:
            cur_obj_init_animation(5);

            obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            if (o->oTimer == 35) {
                o->oHomeX = gMarioState->pos[0];
                o->oHomeZ = gMarioState->pos[2];
            }

            if (o->oTimer == 45) {
                spawn_object_abs_with_rot(o, 0, MODEL_SHADOW_SPIKE, bhvShadowSpike, o->oHomeX, o->oPosY, o->oHomeZ, 0, 0, 0);
            }

            if (o->oTimer == 60) {
                shrine_shadow_decide_next_attack();
            }

        break;
    }

    obj_die_if_health_non_positive();

    o->oInteractStatus = 0;
}


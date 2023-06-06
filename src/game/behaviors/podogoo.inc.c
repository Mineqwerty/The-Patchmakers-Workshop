#define PODOGOO_ACT_IDLE 0
#define PODOGOO_ACT_BOUNCE 1
#define PODOGOO_ACT_ATTACKED 2

static struct ObjectHitbox sPodogooHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 80,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 90,
};

static u8 sPodogooAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

static u8 sFortogooAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static struct ObjectHitbox sFortogooHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 10,
    /* radius:            */ 240,
    /* height:            */ 500,
    /* hurtboxRadius:     */ 230,
    /* hurtboxHeight:     */ 490,
};

static struct ObjectHitbox sFortogooVulnerableHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 45,
    /* hurtboxHeight:     */ 95,
};

void bhv_podogoo_init(void) {
    obj_set_hitbox(o, &sPodogooHitbox);
    o->oGravity = -5.0f;
    // o->oDragStrength = 10;
    // o->oFriction = 100;
}

void bhv_podogoo_loop(void) {
    if (obj_update_standard_actions(1.0f)) {

        if (obj_handle_attacks(&sPodogooHitbox, 0, sPodogooAttackHandlers)) {
            if (o->oAction < PODOGOO_ACT_ATTACKED) {
                o->oAction = PODOGOO_ACT_ATTACKED;
                o->oTimer = 0;
            }
        }

        switch (o->oAction) {
            case PODOGOO_ACT_IDLE:
                obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
                cur_obj_scale(1.0f);
                if (o->oTimer >= 90 && o->oDistanceToMario < 2000) {
                    o->oAction = PODOGOO_ACT_BOUNCE;
                }
                break;
            case PODOGOO_ACT_BOUNCE:
                if (o->oTimer <= 20) {
                    obj_scale_xyz(o, 1.0f + (((f32) o->oTimer) / 10.0f),
                                  1.0f / (1.0f + (((f32) o->oTimer) / 10.0f)),
                                  1.0f + (((f32) o->oTimer) / 10.0f));
                } else {
                    elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, 1.0f, 0.1f, 0.3f);
                    elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, 1.0f, 0.1f, 0.3f);
                    obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);
                }
                if (o->oTimer == 20) {
                    o->oPotogooApproachXZ = 2.0f;
                    o->oPotogooApproachY = 0.5f;
                    o->oPotogooVelXZ = 0.1f;
                    o->oPotogooVelY = 0.1f;
                    o->oVelY = 40.0f;
                    o->oForwardVel = 60.0f;
                    cur_obj_play_sound_2(SOUND_GENERAL_CRAZY_BOX_BOING_SLOW);
                }
                if (o->oTimer == 90) {
                    o->oAction = PODOGOO_ACT_IDLE;
                }
                break;
        }
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(-78);
        if (o->oForwardVel >= 0) {
            o->oForwardVel -= 2;
            if (o->oForwardVel < 0) {
                o->oForwardVel = 0;
            }
        }
    } else {
        o->oGravity = -5.0f;
    }

    if (o->oAction >= PODOGOO_ACT_ATTACKED) {
        obj_scale_xyz(
            o, 1.0f + ((0.25f - (0.25f * ((f32) o->oTimer) / 30.0f)) * sins(o->oTimer * 0x1000)),
            1.0f + ((0.5f - (0.5f * ((f32) o->oTimer) / 30.0f)) * coss((o->oTimer * 0x1000) + 0x4000)),
            1.0f + ((0.25f - (0.25f * ((f32) o->oTimer) / 30.0f)) * sins(o->oTimer * 0x1000)));

        if (o->oTimer == 30 && o->oAction == PODOGOO_ACT_ATTACKED) {
            o->oAction = PODOGOO_ACT_IDLE;
        }
    }
}


void bhv_fortogoo_init(void) {
    cur_obj_init_animation(1);
   obj_set_hitbox(o, &sFortogooHitbox);
   o->oFortogooChildHitbox = spawn_object_relative(0, 0, 250, 0, o, MODEL_NONE, bhvFortogooVulnerableObject);
}

void bhv_fortogoo_loop(void) {
   obj_handle_attacks(&sFortogooHitbox, 0, sFortogooAttackHandlers);

    if (o->oAction == PODOGOO_ACT_ATTACKED) {
        if (o->oTimer == 1) {
            cur_obj_init_animation(2);
            cur_obj_play_sound_2(SOUND_GENERAL_OPEN_IRON_DOOR);
        }
        if (o->oTimer >= 30) {
            spawn_mist_particles();
            spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
            obj_mark_for_deletion(o->oFortogooChildHitbox);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            obj_die_if_health_non_positive();
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
        }
    }
    else {
        if (o->oTimer == 1) {
            o->oForwardVel = 5.0f;
        }
        if (o->oTimer > 150 && o->oTimer <= 180) {
            o->oForwardVel = 0.0f;
            o->oMoveAngleYaw += 0x444;
        }
        if (o->oTimer == 181) {
            o->oForwardVel = 5.0f;
        }
        if (o->oTimer > 330 && o->oTimer <= 360) {
            o->oForwardVel = 0.0f;
            o->oMoveAngleYaw += 0x444;
            if (o->oTimer == 360) {
                o->oTimer = 0;
            }
        }

        cur_obj_move_xz_using_fvel_and_yaw();
        if (o->oTimer % 25 == 0) {
            cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1_LOWPRIO);
        }
    }
}

Gfx *geo_switch_podogoo_eyes(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        if (obj->oAction >= PODOGOO_ACT_ATTACKED) {
            switchCase->selectedCase = 1;
        }
        else {
            switchCase->selectedCase = 0;
        }
    }
    return NULL;
}

void bhv_fortogoo_vulnerable_object_init(void) {
   
}

void bhv_fortogoo_vulnerable_object_loop(void) {
    if (o->parentObj) {
        o->oPosX = o->parentObj->oPosX;
        o->oPosY = o->parentObj->oPosY + 150;
        o->oPosZ = o->parentObj->oPosZ;

        if (obj_handle_attacks(&sFortogooVulnerableHitbox, 0, sPodogooAttackHandlers)) {
        if (o->parentObj->oAction != PODOGOO_ACT_ATTACKED) {
            
            o->parentObj->oAction = PODOGOO_ACT_ATTACKED;
        }
            
    }
    }
}


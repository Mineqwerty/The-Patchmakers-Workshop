static struct ObjectHitbox sDryBonesHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 100,
    /* height:            */ 160,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 150,
};

static u8 sDryBonesAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_SET_SPEED_TO_ZERO,
};

void bhv_dry_bones_init(void) {
    o->oGravity = -1.0f;

    if (o->oBehParams2ndByte == 1) {
        o->oAction = 3;
        cur_obj_init_animation(2);
    }
}

void bhv_dry_bones_loop(void) {

    cur_obj_update_floor_and_walls();

    if (obj_handle_attacks(&sDryBonesHitbox, 0, sDryBonesAttackHandlers)) {
        if (o->oAction < 2) {
            o->oAction = 2;
            o->oTimer = 0;
            cur_obj_init_animation(2);
        }
        else {
            o->oTimer = 0;
            o->header.gfx.animInfo.animFrame = 20;
        }
    }

    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1500.0f) {
                o->oAction = 1;
                cur_obj_init_animation(1);
            }
        break;
        case 1:
            if (o->oDistanceToMario > 1800.0f) {
                o->oAction = 0;
                cur_obj_init_animation(0);
            }

            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            o->oForwardVel = 8.0f;
            
            cur_obj_move_standard(-78);
        break;
        case 2:
            cur_obj_become_intangible();
            if (o->oTimer == 90) {
                cur_obj_init_animation(3);
            }
            if (o->oTimer > 90 && cur_obj_check_if_at_animation_end()) {
                o->oAction = 0;
                cur_obj_init_animation(0);
                cur_obj_become_tangible();
            }
        break;
    }
}


static struct ObjectHitbox sMimicHitbox = {
    /* interactType:      */ INTERACT_SPINY_WALKING,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 10,
    /* radius:            */ 150,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 120,
    /* hurtboxHeight:     */ 170,
};

enum MimicActions {
    MIMIC_ACT_SPAWN,
    MIMIC_ACT_LUNGE,
    MIMIC_ACT_IDLE,
    MIMIC_ACT_TURN_JUMP
};

void bhv_mimic_init(void) {
    cur_obj_init_animation(0);
    obj_set_hitbox(o, &sMimicHitbox);
    cur_obj_play_sound_1(SOUND_NEW_MIMIC_LAUGH);

    o->oGravity = -2.0f;
    o->oDragStrength = 1.1f;
    o->oFriction = 3.0f;
}

void bhv_mimic_loop(void) {
    switch (o->oAction) {
        case MIMIC_ACT_SPAWN:
            if (o->oTimer == 15) {
                o->oAction = MIMIC_ACT_LUNGE;
            }
        break;
        case MIMIC_ACT_LUNGE:
            if (o->oTimer == 1) {
                o->oForwardVel = 30.0f;
                o->oVelY = 15.0f;
            }

            if (o->oForwardVel > 0) {
                o->oForwardVel -= 1;
            }

            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);

            if (o->header.gfx.animInfo.animFrame == 25) {
                cur_obj_play_sound_2(SOUND_OBJ2_PIRANHA_PLANT_BITE);
            }

            if (o->oTimer == 40) {
                o->oAction = MIMIC_ACT_IDLE;
            }
        break;
        case MIMIC_ACT_IDLE:
            cur_obj_init_animation(1);

            if (o->oTimer == 60) {
                o->oVelY = 15.0f;
                o->oAction = MIMIC_ACT_TURN_JUMP;
            }
        break;
        case MIMIC_ACT_TURN_JUMP:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);

            obj_turn_toward_object(o, gMarioState->marioObj, O_MOVE_ANGLE_YAW_INDEX, 0x400);

            if (o->oMoveFlags & OBJ_MOVE_LANDED) {
                cur_obj_init_animation(0);
                o->oAction = MIMIC_ACT_LUNGE;
            }
        break;
    }
}


enum BlightActions {
    BLIGHT_ACT_IDLE,
    BLIGHT_ACT_ENRAGED,
    BLIGHT_ACT_LOSE_INTEREST
};

static struct ObjectHitbox sBlightHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 5,
    /* radius:            */ 240,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 230,
    /* hurtboxHeight:     */ 490,
};

void blight_check_enraged(void) {
    s16 relativeAngleToMario = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
    s16 relativeMarioFaceAngle = abs_angle_diff(o->oMoveAngleYaw, gMarioObject->oFaceAngleYaw);
    s16 relativeAngleToMarioThreshhold = 0x1568;
    s16 relativeMarioFaceAngleThreshhold = 0x6B58;
    s32 doneAppearing = FALSE;

    o->oVelY = 0.0f;

    if (relativeAngleToMario > relativeAngleToMarioThreshhold
        || relativeMarioFaceAngle < relativeMarioFaceAngleThreshhold) {
        obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);
        o->oMoveAngleYaw = o->oFaceAngleYaw;
    } else if (o->oDistanceToMario < 1500 && gMarioState->curPatch != PATCH_STONE) {
        o->oAction = BLIGHT_ACT_ENRAGED;
        cur_obj_init_animation(1);
        cur_obj_play_sound_2(SOUND_NEW_BLIGHT_SCREAM);
    }

}

void bhv_blight_init(void) {
    obj_set_hitbox(o, &sBlightHitbox);
}

void bhv_blight_loop(void) {
    switch (o->oAction) {
        case BLIGHT_ACT_IDLE:
        cur_obj_scale(1.0f);
            o->oForwardVel = 0;
            blight_check_enraged();
        break;
        case BLIGHT_ACT_ENRAGED:
        cur_obj_scale(1.5f);
            obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x800);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            o->oForwardVel = 8.0f;
            o->oPosY = approach_f32_asymptotic(o->oPosY, gMarioState->pos[1] + 100, 0.03f);

            if (o->oTimer == 300) {
                o->oAction = BLIGHT_ACT_IDLE;
                cur_obj_init_animation(0);

            }

            if (o->oDistanceToMario < 500 && gMarioState->curPatch == PATCH_STONE) {
                o->oAction = BLIGHT_ACT_LOSE_INTEREST;
            }
        break;
        case BLIGHT_ACT_LOSE_INTEREST:
            
            obj_turn_toward_position(o, o->oHomeX, o->oHomeY, o->oHomeZ, O_FACE_ANGLE_YAW_INDEX, 0x800);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            o->oForwardVel = 8.0f;

            if (o->oTimer >= 120) {
                o->oAction = BLIGHT_ACT_IDLE;
                cur_obj_init_animation(0);
            }
        break;
    }

    o->oInteractStatus = 0;

    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
}


Gfx *geo_switch_blight_eyes(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        switch (obj->oAction) {
            case BLIGHT_ACT_ENRAGED:
                switchCase->selectedCase = 1;
            break;
            default:
                switchCase->selectedCase = 0;
            break;
        }
    }
    return NULL;
}

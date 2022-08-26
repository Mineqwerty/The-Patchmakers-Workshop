struct ObjectHitbox sSwampSkeeterHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 180,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 90,
};

struct ObjectHitbox sTaeberHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 400,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 10,
    /* hurtboxHeight:     */ 10,
};

void bhv_swamp_skeeter_init(void) {

}

void bhv_swamp_skeeter_loop(void) {
    obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
    obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
    obj_check_attacks(&sSwampSkeeterHitbox, o->oAction);
}

void bhv_taeber_init(void) {
    o->oTaeberLeaves = spawn_object_relative(0, 0, 0, 0, o, MODEL_TAEBER_LEAVES, bhvTaeberLeaves);
    obj_set_hitbox(o, &sTaeberHitbox);
}

void bhv_taeber_loop(void) {
    obj_scale_xyz(o, 1.0f + (0.05f * sins(o->oTimer * 0x800)), 1.0f + (0.05f * coss(o->oTimer * 0x800)), 1.0f + (0.05f * sins(o->oTimer * 0x800)));
}

void bhv_taeber_leaves_loop(void) {
    o->oFaceAngleYaw += 0x800;
    o->oMoveAngleYaw += 0x800;
}

void bhv_blubol_loop(void) {
    if (gMarioState->action == ACT_GROUND_POUND_LAND && gMarioState->pos[1] > o->oPosY && o->oDistanceToMario < 400.0f && o->oAction == 0) {
        o->oAction = 1;
        o->oForwardVel = 3.0f;
        o->oGravity = 3.0f;
        o->oBounciness = 5.0f;
        o->oFriction = 0.8f;
    }

    if (o->oAction == 1) {
        object_step_without_floor_orient();

        if (o->oBehParams2ndByte == 1 && o->oTimer == 120) {
            spawn_bp3_star(o->oPosX, o->oPosY + 100, o->oPosZ + 100);
            o->oAction = 2;
        }
    }
}
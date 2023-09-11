static struct ObjectHitbox sSwingingAxeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 800,
    /* hurtboxRadius:     */ 79,
    /* hurtboxHeight:     */ 790,
};

void bhv_swinging_axe_init(void) {
    o->oAxeHitbox1 = spawn_object_relative(0, 0, -1538, 0, o, MODEL_NONE, bhvSwingingAxeHitbox);
    o->oAxeHitbox2 = spawn_object_relative(0, 0, -1538, 0, o, MODEL_NONE, bhvSwingingAxeHitbox);
}

void bhv_swinging_axe_loop(void) {

    o->oFaceAngleRoll = 0x2000 * sins(o->oTimer * 0x222);
    o->oMoveAngleRoll = 0x2000 * sins(o->oTimer * 0x222);

    o->oAxeHitbox1->oPosX = o->oPosX - coss(o->oFaceAngleYaw) * (-1538 * sins(o->oFaceAngleRoll) - 400);
    o->oAxeHitbox1->oPosZ = o->oPosZ - sins(o->oFaceAngleYaw) * (-1538 * -sins(o->oFaceAngleRoll) - 400);
    o->oAxeHitbox2->oPosX = o->oPosX - coss(o->oFaceAngleYaw) * (-1538 * sins(o->oFaceAngleRoll) + 400);
    o->oAxeHitbox2->oPosZ = o->oPosZ - sins(o->oFaceAngleYaw) * (-1538 * -sins(o->oFaceAngleRoll) + 400);
}

void bhv_swinging_axe_hitbox_init(void) {
    obj_set_hitbox(o, &sSwingingAxeHitbox);
}

void bhv_swinging_axe_hitbox_loop(void) {
    o->oInteractStatus = 0;
}


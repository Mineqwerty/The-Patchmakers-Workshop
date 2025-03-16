static struct ObjectHitbox sPMHaloHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 80,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pm_halo_init(void) {

}

void bhv_pm_halo_loop(void) {
    o->oPosX = o->oHomeX + (15*o->oTimer) * sins(o->oTimer * 0x800 + (10*o->oTimer));
    o->oPosZ = o->oHomeZ + (15*o->oTimer) * coss(o->oTimer * 0x800 + (10*o->oTimer));

    if (o->oTimer % 20 == 0) {
        cur_obj_play_sound_2(SOUND_HALO_CIRCLE);
    }

    
    obj_set_hitbox(o, &sPMHaloHitbox);
    o->oInteractStatus = 0;

    o->oFaceAngleYaw += 0x1256;

    if (o->oTimer > 210) {
        obj_mark_for_deletion(o);
    }
}


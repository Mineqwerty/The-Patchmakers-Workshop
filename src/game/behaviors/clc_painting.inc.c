struct ObjectHitbox sClcPaintingHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  0,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 50,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 200,
};

void bhv_clc_painting_init(void) {
    o->oFaceAngleRoll = 0x400;
}

void bhv_clc_painting_loop(void) {
    switch (o->oAction) {
        case 0:
            obj_set_hitbox(o, &sClcPaintingHitbox);
            if (cur_obj_was_attacked_or_ground_pounded()) {
                o->oAction = 1;
            }

            o->oInteractStatus = 0;
            
        break;
        case 1:
            o->oGravity = 2.0f;
            s16 collisionFlags = object_step();
            if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
                o->oAction = 2;
                
            }
        break;
        case 2:
            //o->oPosX += 5.0f;
            o->oFaceAnglePitch += 0x200 + (o->oTimer * 0x50);

            if (o->oFaceAnglePitch >= 0x4000) {
                o->oAction = 3;
                o->oFaceAnglePitch = 0x4000;
            }
        break;
    }
    
}


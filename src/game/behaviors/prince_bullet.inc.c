static struct ObjectHitbox sPrinceBulletHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_prince_bullet_init(void) {
    
}

void bhv_prince_bullet_loop(void) {
    switch(o->oAction) {
        case 0:
            cur_obj_scale(CLAMP((f32)o->oTimer / 30.0f, 0.02f, 1.0f));
            if (o->oTimer == 30) {
                o->oAction++;
            }
        break;
        case 1:
            cur_obj_scale(1.0f);
            s16 targetPitch;

            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_PITCH_INDEX, 0x800);
            if (o->oTimer == 60) {
                o->oAction++;
                obj_set_hitbox(o, &sPrinceBulletHitbox);
            }
        break;
        case 2:
            o->oForwardVel = (o->oTimer + 140.0f) * coss(o->oMoveAnglePitch);
            o->oVelY = (o->oTimer + 140.0f) * -sins(o->oMoveAnglePitch);
            o->oGravity = 0;
            cur_obj_move_standard(78);
            

            if (o->oTimer == 120) {
                obj_mark_for_deletion(o);
            }
        break;
    }

    o->oFaceAngleYaw += 0x351;
    o->oFaceAnglePitch += 0x251;
    o->oFaceAngleRoll += 0x371;
}


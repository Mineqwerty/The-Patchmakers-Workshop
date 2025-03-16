static struct ObjectHitbox sDangerPuffHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_danger_puff_init(void) {
    obj_set_hitbox(o, &sDangerPuffHitbox);
    o->oDrawingDistance = (gIsConsole ? 5000 : 20000);
    o->oInteractStatus = 0;
    o->oDangerPuffChaseDecay = 0;
    o->oDangerPuffReturnTime = 0;
}

void bhv_danger_puff_loop(void) {
    
    switch(o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1500) {
                o->oDangerPuffReturnTime = 0;
                o->oDangerPuffChaseDecay++;
                o->oAngleToMario = obj_angle_to_object(o, gMarioObject);
                f32 marioApproachFactor = (o->oDangerPuffChaseDecay > 30 ? 30.0f / (f32)o->oDangerPuffChaseDecay : 1.0f) * 40.0f * ((1500.0f - o->oDistanceToMario) / 1400.0f);
                o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1],  marioApproachFactor * 0.4f);
                o->oMoveAngleYaw = o->oAngleToMario;
                o->oForwardVel = marioApproachFactor;
                cur_obj_move_xz_using_fvel_and_yaw();

                if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                    cur_obj_hide();
                    for (u8 i = 0; i < 8; i++) {
                        spawn_object_relative(0, random_u16() % 200 - 100, random_u16() % 200 - 100, random_u16() % 200 - 100, o, MODEL_LEAVES, bhvTreeLeaf);
                    }
                    o->oAction = 1;
                    cur_obj_play_sound_1(SOUND_GENERAL_EXPLOSION6);
                }
                else if (o->oDistanceToMario < 200 && gMarioState->curPatch == PATCH_STONE) {
                    cur_obj_hide();
                    for (u8 i = 0; i < 8; i++) {
                        spawn_object_relative(0, random_u16() % 200 - 100, random_u16() % 200 - 100, random_u16() % 200 - 100, o, MODEL_LEAVES, bhvTreeLeaf);
                    }
                    o->oAction = 1;
                    cur_obj_play_sound_1(SOUND_GENERAL_EXPLOSION6);
                }
            }
            else if (o->oDangerPuffReturnTime < 90) {
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX,  2.0f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY,  2.0f);
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ,  2.0f);
                o->oDangerPuffChaseDecay = 0;
                o->oDangerPuffReturnTime++;
            }
        break;
        case 1:
            cur_obj_become_intangible();
            if (o->oTimer == 90) {
                o->oPosX = o->oHomeX;
                o->oPosY = o->oHomeY;
                o->oPosZ = o->oHomeZ;
                o->oDangerPuffReturnTime = 90;
                cur_obj_unhide();
            }
            if (o->oTimer >= 90 && o->oTimer < 120) {
                cur_obj_scale(CLAMP(((f32)(o->oTimer - 90)) / 30.0f, 0.02f, 1.0f));
            }

            if (o->oTimer == 120) {
                o->oAction = 0;
                cur_obj_scale(1.0f);
                o->oInteractStatus = 0;
                cur_obj_become_tangible();
                o->oDangerPuffChaseDecay = 0;
            }
        break;
    }
}


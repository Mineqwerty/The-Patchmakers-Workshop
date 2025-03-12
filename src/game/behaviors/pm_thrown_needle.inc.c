static struct ObjectHitbox sPMNeedleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 70,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sPMGiantNeedleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 4,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 140,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_pm_thrown_needle_init(void) {
    obj_set_hitbox(o, &sPMNeedleHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_BREAK_STONE_PATCH;
}

void bhv_pm_thrown_needle_loop(void) {

    struct Object *patchmaker;
    struct Object *halo;
    f32 dist;

    switch (o->oAction) {
        case 0:
            o->oPosY += 30 - o->oTimer;

            if  (o->oTimer == 30) {
                o->oAction = 1;
            }
        break;
        case 1:
                obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
                obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
                obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_PITCH_INDEX, 0x800);

            if (o->oBehParams2ndByte == 1 && o->oTimer == 10) {
                cur_obj_scale(5.0f);
                obj_set_hitbox(o, &sPMGiantNeedleHitbox);
                cur_obj_play_sound_2(SOUND_TRANSMUTATION_CONE);
            }

            if (o->oTimer == 20 + 20*(gCurrLevelNum == LEVEL_BOWSER_3)) {
                
                o->oAction  = 2;
            }
        break;
        case 2:
            o->oForwardVel = 155.0f * coss(o->oFaceAnglePitch);
                    o->oVelY = -135.0f * sins(o->oFaceAnglePitch);
                    o->oDragStrength = 0.0f;
                    o->oGravity = 0.0f;

                    if ((object_step_without_floor_orient() & OBJ_COL_FLAG_GROUNDED) || o->oTimer > 120) {
                        o->oVelY = 0;
                        o->oForwardVel = 0;
                        cur_obj_play_sound_1(SOUND_NEW_WOOD_THUNK);
                        o->oAction = 3;
                    }
        break;
        case 3:
            if (o->oTimer > 30)  {
                cur_obj_scale(1.0f - (o->oTimer - 30)/30.0f);
            }
            if (o->oTimer == 59) {
                if (random_u16()%5 == 0) {
                    struct Object *coin = spawn_object(o, MODEL_YELLOW_COIN, bhvMovingYellowCoin);

                    cur_obj_play_sound_2(SOUND_GENERAL_COIN_SPURT);

                    coin->oForwardVel = 2.0f;
                    coin->oVelY = 10.0f;
                    coin->oPosY = o->oPosY + 10.0f;
                    coin->oMoveAngleYaw = random_u16();
                }
                obj_mark_for_deletion(o);
            }
        break;
        case 4:
            //captured by halo
            cur_obj_scale(1.0f);

            o->oPosX = o->parentObj->oPosX;
            o->oPosY = o->parentObj->oPosY;
            o->oPosZ = o->parentObj->oPosZ;

            if (gCurrLevelNum == LEVEL_BOWSER_3) {
                patchmaker = cur_obj_find_nearest_object_with_behavior(bhvMantleOfMadness, &dist);
            }
            else {
                patchmaker = cur_obj_find_nearest_object_with_behavior(bhvPatchmaker, &dist);
            }
            
            if (patchmaker) {
                obj_turn_toward_object(o, patchmaker, O_MOVE_ANGLE_YAW_INDEX, 0x800);
                    obj_turn_toward_position(o, patchmaker->oPosX, patchmaker->oPosY + 250, patchmaker->oPosZ,
                                            O_MOVE_ANGLE_PITCH_INDEX, 0x800);

                    o->oFaceAngleYaw = o->oMoveAngleYaw;// + 0x8000;
                    o->oFaceAnglePitch = 0;
                }

                halo = cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);

                if (halo->oAction == 3 && halo->oTimer == 18 && o->oTimer > 18) {
                    o->oAction = 5;
                    if (halo && halo->oHaloCapturedObject == o) {
                        halo->oHaloCapturedObject = NULL;
                    }
                }
        break;
        case 5:
        //fling to pm
            if (gCurrLevelNum == LEVEL_BOWSER_3) {
                patchmaker = cur_obj_find_nearest_object_with_behavior(bhvMantleOfMadness, &dist);
            }
            else {
                patchmaker = cur_obj_find_nearest_object_with_behavior(bhvPatchmaker, &dist);
            }

            o->oForwardVel = 60.0f;
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oPosY = approach_f32_asymptotic(o->oPosY, patchmaker->oPosY + 150, 0.09f);

            obj_attack_in_radius(o, 200, 6, 1);

            if (o->oTimer == 60) {
                
                obj_mark_for_deletion(o);
            }
        break;
    }

    if (o->oAction < 4  && o->oBehParams2ndByte != 1) {
        halo = cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);
        if (halo && halo->oAction > 0 && !halo->oHaloCapturedObject && dist < 150) {
            halo->oHaloCapturedObject = o;
            o->parentObj = halo;
            gMarioState->haloCaptureType = 4;
            o->oAction = 4;
        }
    }
}


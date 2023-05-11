static struct ObjectHitbox sBounceBulbHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 92,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

#define ACT_BULB_IDLE 0
#define ACT_BULB_BOUNCE 1

void bhv_bounce_bulb_init(void) {
    obj_set_hitbox(o, &sBounceBulbHitbox);
}

void bhv_bounce_bulb_loop(void) {
    o->oInteractionSubtype = INT_SUBTYPE_BULB;
    switch (o->oAction) {
        case ACT_BULB_IDLE:
            if (o->oInteractStatus != INT_STATUS_NONE && o->collidedObjs[0] == gMarioObject) {
                gMarioState->action = ACT_TRIPLE_JUMP;
                gMarioState->vel[1] = 90.0f;
                o->oInteractStatus = INT_STATUS_NONE;
                o->oTimer = 0;
                o->oAction = ACT_BULB_BOUNCE;
                o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BOUNCE_BULB_OPEN];
            }
            break;
        case ACT_BULB_BOUNCE:
        obj_scale_xyz(o, 1.0f + 0.3f*sins(0x1000 * o->oTimer), 1.0f + -0.3f*sins(0x1000 * o->oTimer), 1.0f + 0.3f*sins(0x1000 * o->oTimer));
        if (o->oTimer == 24) {
            o->oAction = ACT_BULB_IDLE;
            obj_scale_xyz(o, 1, 1, 1);
            o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BOUNCE_BULB];
        }
        
        break;
    }
}

void bhv_bounce_rosedrift_init(void) {
    obj_set_hitbox(o, &sBounceBulbHitbox);
    //o->oPosX += 100 * (2 - (random_u16() % 5));
    //o->oPosZ += 100 * (2 - (random_u16() % 5));
    o->oHomeX = gMarioState->pos[0] + (400.0f * (2.0f - (random_u16() % 5))) + (1250 * -sins(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
    o->oHomeZ = gMarioState->pos[2] + (400.0f * (2.0f - (random_u16() % 5))) + (1250 * -coss(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
    o->oHomeY = find_floor_height(o->oHomeX, gMarioState->pos[1] + 800, o->oHomeZ);
    o->oMoveAngleYaw = cur_obj_angle_to_home();
    o->oFaceAngleYaw = cur_obj_angle_to_home();
}

void bhv_bounce_rosedrift_loop(void) {
    if (o->oTimer < 60 && gMarioState->action != ACT_BOUNCED_ON_ROSEDRIFT) {
        struct Surface *surface;
        struct Surface *homeSurface;
        f32 floorHeight = find_floor(o->oPosX, o->oPosY + 50, o->oPosZ, &surface);
        f32 homeHeight = find_floor(o->oHomeX, o->oHomeY + 50, o->oHomeZ, &homeSurface);
        //if the home position is in a shit spot, keep recalculating it closer and closer to mario based on the timer
        if (homeHeight > gMarioState->pos[1] + 600.0f || homeHeight < gMarioState->pos[1] - 600.0f) {
            o->oHomeX = gMarioState->pos[0] + (100.0f * (2.0f - (random_u16() % 5))) + ((1250 - o->oTimer * 100) * -sins(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
            o->oHomeZ = gMarioState->pos[2] + (100.0f * (2.0f - (random_u16() % 5))) + ((1250 - o->oTimer * 100) * -coss(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
            o->oHomeY = gMarioState->pos[1] + 20;
        }
        //similarly, if the position of the rosedrift is oob or in water place it increasingly closer to mario
        if (o->oPosY < -1000.0f || (surface && surface->type == SURFACE_NEW_WATER)) {
            o->oPosX = gMarioState->pos[0] + (100.0f * (2.0f - (random_u16() % 5))) + ((1250 - o->oTimer * 100) * sins(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
            o->oPosZ = gMarioState->pos[2] + (100.0f * (2.0f - (random_u16() % 5))) + ((1250 - o->oTimer * 100) * coss(gLakituState.yaw + (0x800 - (0x600 * o->oBehParams2ndByte))));
            o->oPosY = gMarioState->pos[1] + 20;
        }
    approach_vec3f_asymptotic(&o->oPosVec, &o->oHomeVec, 0.03f, 0.03f, 0.03f);
    cur_obj_rotate_yaw_toward(cur_obj_angle_to_home(), 0x400);
    obj_resolve_object_collisions(NULL);
    }
    else {
        struct Surface *surface;
        f32 floorHeight = find_floor(o->oPosX, o->oPosY + 2000, o->oPosZ, &surface);
        if (o->oPosY < floorHeight) {
            o->oPosY += 20.0f;
        }
        if (o->oPosY > gMarioState->pos[1] + 70.0f) {
            o->oPosY -= 2.0f;
        }
        obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
    }

    o->oInteractionSubtype = INT_SUBTYPE_BULB;
    switch (o->oAction) {
        case ACT_BULB_IDLE:
            if (o->oInteractStatus != INT_STATUS_NONE && o->oTimer > 60) {
                gMarioState->action = ACT_BOUNCED_ON_ROSEDRIFT;
                gMarioState->vel[1] = 248.0f;
                o->oInteractStatus = INT_STATUS_NONE;
                o->oTimer = 160;
                o->oAction = ACT_BULB_BOUNCE;
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_FREE_ROAM, 1);
                play_sound(SOUND_MARIO_HERE_WE_GO, gGlobalSoundSource);
            }
            else {
                o->oInteractStatus = INT_STATUS_NONE;
            }

            if (o->oTimer >= 900) {
                cur_obj_become_intangible();
                obj_scale_xyz(o, (930.0f - (f32) o->oTimer) / 30.0f, (930.0f - (f32) o->oTimer) / 30.0f, (930.0f - (f32) o->oTimer) / 30.0f);
            }

            if (o->oTimer == 929) {
                obj_mark_for_deletion(o);
            }
            break;
        case ACT_BULB_BOUNCE:
        obj_scale_xyz(o, 1.0f + 0.3f*sins(0x1000 * o->oTimer), 1.0f + -0.3f*sins(0x1000 * o->oTimer), 1.0f + 0.3f*sins(0x1000 * o->oTimer));
        if (o->oTimer == 184) {
            o->oAction = ACT_BULB_IDLE;
            obj_scale_xyz(o, 1, 1, 1);
        }
        
        break;
        case 2:
            if (o->oTimer >= 30) {
                obj_mark_for_deletion(o);
            }
        break;

        
    }
    if (gMarioState->action == ACT_BOUNCED_ON_ROSEDRIFT && o->oAction != 2) {
            o->oTimer = 0;
            o->oAction = 2;
        }
}
struct SpawnParticlesInfo sMistIce = {
    2, 4, MODEL_MIST, 10.0f, -20, 0, 20, 40, 252, 30, 15.0f, 0.0f
};
struct SpawnParticlesInfo sSnowflakeFly = {
    2, 8, MODEL_SNOWFLAKE, 10.0f, 40, 10, 0, 0, 0, 30, 13.0f, 6.0f
};

static struct ObjectHitbox sIceSpikesHitbox = {
    /* interactType:      */ INTERACT_DAMAGE_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 90,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 20,
    /* hurtboxHeight:     */ 20,
};

void bhv_ice_spikes_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
    o->oFaceAngleYaw = 0x2000;
    
}

void bhv_ice_spikes_loop(void) {
    obj_set_hitbox(o, &sIceSpikesHitbox);
    for (int i = 0; i < o->numCollidedObjs; i++) {
        struct Object *other = o->collidedObjs[i];

        if (other != gMarioObject) {
            //other->oInteractStatus |= INT_STATUS_TOUCHED_MARIO | INT_STATUS_WAS_ATTACKED | INT_STATUS_INTERACTED | INT_STATUS_TOUCHED_BOB_OMB;
            attack_object(other, 8);
        }
    }

    o->oInteractStatus = 0;

    if (o->oTimer < 5) {
        if ((gMarioState->action != ACT_GROUND_POUND_LAND)) {
            obj_mark_for_deletion(o);
        }
    }
    if (o->oTimer <= 9) {
        obj_scale_xyz(o, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f);
    }
    else if (o->oTimer > 30 && o->oTimer < 35) {
        obj_scale_xyz(o, 1.5f, 4.5f - ((f32) o->oTimer) / 10.0f, 1.5f);
        o->oPosY -= 5.0f;
    }
    else if(o->oTimer >= 35) {
        obj_scale_xyz(o, 3.5f - ((f32) o->oTimer - 5) / 15.0f, 4.5f - ((f32) o->oTimer) / 10.0f, 3.5f - ((f32) o->oTimer - 5) / 15.0f);
    }

    if (o->oTimer == 40) {
        obj_mark_for_deletion(o);
    }
}

void bhv_ice_floor_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
    cur_obj_spawn_particles(&sSnowflakeFly);
cur_obj_spawn_particles(&sMistIce);
//obj_orient_graph(o, gMarioState->floor->normal.x, gMarioState->floor->normal.y, gMarioState->floor->normal.z, 1);
/*
struct Surface *waterFloor;
Vec3f position;

vec3f_copy(position, &o->oPosVec);

find_water_floor(o->oPosX, o->oPosY + 100, o->oPosZ, &waterFloor);
if (gMarioState->floor) {
    Vec3f floorNormal;
    surface_normal_to_vec3f(floorNormal, gMarioState->floor);
    mtxf_align_terrain_normal(o->transform, floorNormal, position, o->oFaceAngleYaw);
    o->header.gfx.throwMatrix = &o->transform;

}
*/
}

void bhv_ice_floor_loop(void) {

    
   cur_obj_align_gfx_with_floor_ice();

    switch (o->oAction) {
        case 0:
    if (o->oTimer < 2) {
        obj_scale_xyz(o, ((f32) o->oTimer) / 2.0f, 1, ((f32) o->oTimer) / 2.0f);
    }
    else if (sqr(gMarioState->pos[0] - o->oPosX) + sqr(gMarioState->pos[2] - o->oPosZ) > 20000.0f) {
        o->oAction += 1;
        o->oTimer = 0;
    }
    else {
        obj_scale_xyz(o, 1.5f, 1.5f, 1.5f);
    }


    if (o->oTimer > 20 && !o->parentObj) {
         o->oAction += 1;
        o->oTimer = 0;
    }
    break;
    case 1:
        obj_scale_xyz(o, 1.0f - ((f32) o->oTimer) / 10.0f, 1, 1.0f - ((f32) o->oTimer) / 10.0f);

        if (o->oTimer >= 10) {
            obj_mark_for_deletion(o);
        }
    break;
    }
}

void bhv_ice_cube_init(void) {
    gMarioState->forwardVel = 0;
    //gMarioState->pos[0] += (o->oPosX - gMarioState->pos[0] / 3.0f);
    //gMarioState->pos[2] += (o->oPosZ - gMarioState->pos[2] / 3.0f);
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[2] = o->oPosZ;
    gMarioState->action = ACT_JUMP_LAND;

    check_ice_cube_corners_and_push();
}

extern s16 gCutsceneTimer;

void bhv_ice_cube_loop(void) {

    if (o->oIsPushingIceCube == 1 && o->oTimer < 10) {
        check_ice_cube_corners_and_push();
    }


    if (o->oTimer <= 3) {

        switch (o->oBehParams2ndByte) {
            case 0:
                obj_scale_xyz(o, 1, ((f32) o->oTimer) / 3.0f, 1);
                break;
            case 1:
                obj_scale_xyz(o, 2, ((f32) o->oTimer) / 3.0f, 2);
                break;
            case 2:
                obj_scale_xyz(o, 4, ((f32) o->oTimer) / 1.5f, 4);
                gMarioState->pos[1] += 50;
                gMarioState->vel[1] = 0;
                break;
        }

        //sinking mud failsafe
        if (gMarioState->action == ACT_SINK_MUD) {
            gMarioState->pos[0] = o->oPosX;
            gMarioState->pos[1] = o->oPosY + 100;
            gMarioState->pos[2] = o->oPosZ;
            gMarioState->action = ACT_JUMP_LAND;

            gCamera->cutscene = 0;
            clear_cutscene_vars(gCamera);
            gCutsceneTimer = 0;
        }
    }



    if (cur_obj_was_attacked_or_ground_pounded() && o->oBehParams2ndByte != 2) {
        for (int i = 0; i < o->parentObj->oNumLootCoins; i++) {
            struct Object *coin;
            coin = spawn_object_relative(0, 0, 50, 0, o, MODEL_YELLOW_COIN, bhvMovingYellowCoin);
            coin->oVelY = 20.0f;
            coin->oForwardVel = 3.0f;
            coin->oMoveAngleYaw = random_u16();
        }
        
        obj_mark_for_deletion(o->parentObj);
        
        //obj_explode_and_spawn_coins(46.0f, 0);
        spawn_mist_particles();
        spawn_triangle_break_particles(20, MODEL_SL_CRACKED_ICE_CHUNK, 3.0f, 0);
        obj_mark_for_deletion(o);
    }
}

void check_ice_cube_corners_and_push(void) {
    struct Surface *floor;
    Vec3f pushVec;
    pushVec[0] = 0;
    pushVec[2] = 0;
    o->oIsPushingIceCube = 0;
    if (find_floor(o->oPosX + 82, o->oPosY + 150, o->oPosZ + 82, &floor) < -10000) {
        pushVec[0] += -10;
        pushVec[2] += -10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX + 82, o->oPosY + 150, o->oPosZ - 82, &floor) < -10000) {
        pushVec[0] += -10;
        pushVec[2] += 10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX - 82, o->oPosY + 150, o->oPosZ + 82, &floor) < -10000) {
        pushVec[0] += 10;
        pushVec[2] += -10;
        o->oIsPushingIceCube = 1;
    }
    if (find_floor(o->oPosX - 82, o->oPosY + 150, o->oPosZ - 82, &floor) < -10000) {
        pushVec[0] += 10;
        pushVec[2] += 10;
        o->oIsPushingIceCube = 1;
    }

    if (o->oIsPushingIceCube == 1) {
        o->parentObj->oFreezeObject = 0;
        o->parentObj->oIntangibleTimer = -1;
    }
    else {
        o->parentObj->oFreezeObject = 1;
    }

    o->oPosX += pushVec[0];
    o->oPosZ += pushVec[2];
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY;
    o->parentObj->oPosZ = o->oPosZ;
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[2] = o->oPosZ;
    
}
struct ObjectHitbox sGildedStarHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 25,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 100,
};

void bhv_gilded_star_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    obj_set_hitbox(o, &sGildedStarHitbox);
    o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_gilded_star_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_become_tangible();

            cur_obj_enable_rendering();
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            o->oHeldState = HELD_FREE;
            object_step();
            break;

        case HELD_HELD:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_gilded_star_receiver_init(void) {
   
}

void bhv_gilded_star_receiver_loop(void) {
    struct Object *nearBox = cur_obj_find_object_with_bparam_2nd_byte(bhvGildedStar, o->oBehParams2ndByte);
    f32 dist;
    if (nearBox && o->oAction == 0) {
        
    vec3f_get_dist(&o->oPosVec, &nearBox->oPosVec, &dist);
        if (dist < 300.0f && gMarioState->heldObj != nearBox) {
                obj_mark_for_deletion(nearBox);
                nearBox = spawn_object_relative(o->oBehParams2ndByte, 0, 0, 0, o, MODEL_GILDED_STAR_G, bhvStaticObject);
                o->oAction++;
        }
    }
    else if (o->oAction == 1) {
        if (o->oTimer == 30) {
            spawn_default_star(o->oPosX, o->oPosY, o->oPosZ + 200);
        }
    }
}


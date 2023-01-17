#define SEWNIA_ACT_IDLE 0
#define SEWNIA_ACT_FOLLOW_MARIO 1
#define SEWNIA_ACT_TALKING_TO_MARIO 2
#define SEWNIA_ACT_CUTSCENE 3

static struct ObjectHitbox sSewniaHitbox = {
    /* interactType:      */ INTERACT_TEXT,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 85,
    /* height:            */ 140,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_sewnia_init(void) {
    obj_set_hitbox(o, &sSewniaHitbox);
    o->oAction = 1;
    o->oGravity = -3.0f;
}

void bhv_sewnia_loop(void) {

    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-60);

    switch (o->oAction) {
        case 0:
            sewnia_act_idle();
        break;
        case 1:
            sewnia_act_follow_mario();
        break;
        case 2:
            sewnia_act_talking_to_mario();
        break;
        case 3:
            sewnia_act_cutscene();
        break;
    }
}

void sewnia_act_idle(void) {
    o->oInteractStatus = 0;
    cur_obj_init_animation(0);

    o->oForwardVel = 0.0f;
    
}

void sewnia_act_follow_mario(void) {
    
    if (o->oDistanceToMario > 400.0f) {
        cur_obj_init_animation_with_accel_and_sound(1, 1.5f);
        u8 approachMode = 0;
        //cast a ray towards mario. if there are no walls, floors, or ceilings in the way try 
        //to approach mario directly. Otherwise, follow a path along waypoints that leads closer to him.
        
        struct Surface *surf;
        Vec3f originPos;
        Vec3f hitpos;
        Vec3f raydir;

        raydir[0] = gMarioState->pos[0];
        raydir[1] = gMarioState->pos[1] + 100.0f;
        raydir[2] = gMarioState->pos[2];

        vec3f_set(originPos, o->oPosX, o->oPosY + 100.0f, o->oPosZ);

        find_surface_on_ray(&originPos, raydir, &surf, &hitpos, 2U, 1);
        if (surf != NULL) approachMode = 1;
        find_surface_on_ray(&originPos, raydir, &surf, &hitpos, 1U, 1);
        if (surf != NULL) approachMode = 1;
        find_surface_on_ray(&originPos, raydir, &surf, &hitpos, 4U, 1);
        if (surf != NULL) approachMode = 1;


        //if (approachMode == 0) {
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            o->oForwardVel = 20.0f;
        //}
        //else {
        //    follow_along_waypoints();
        //}


    }
    else {
        cur_obj_init_animation(0);
        if (o->oForwardVel > 0.0f) {
        o->oForwardVel -= 4.0f;
    } else {
        o->oForwardVel = 0.0f;
    }
    }
    

}

void follow_along_waypoints(void) {

}

void sewnia_act_talking_to_mario(void) {

}

void sewnia_act_cutscene(void) {

}

Gfx *geo_switch_doll_mouth(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        
    }

    return NULL;
}
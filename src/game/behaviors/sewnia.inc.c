#include "levels/castle_inside/header.h"

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

struct Waypoint *sewnia_find_nearest_waypoint() {
    f32 dist = 0;
    f32 minDist = 32000;
    struct Waypoint *curPoint = segmented_to_virtual(&castle_inside_area_1_spline_SewniaPath);
    struct Waypoint *returnPoint;
    while (curPoint->flags != -1) {

        Vec3f waypointPos;
        vec3f_set(waypointPos, (f32) curPoint->pos[0], (f32) curPoint->pos[1], (f32) curPoint->pos[2]);
        vec3f_get_dist(&o->oPosVec, waypointPos, &dist);
        if (dist < minDist) {
            minDist = dist;
            returnPoint = curPoint;
        }

        curPoint = curPoint + 1;
    }

    return returnPoint;

}

struct Waypoint *find_mario_nearest_waypoint() {
    f32 dist = 0;
    f32 minDist = 32000;
    struct Waypoint *curPoint = segmented_to_virtual(&castle_inside_area_1_spline_SewniaPath);
    struct Waypoint *returnPoint;
    while (curPoint->flags != -1) {

        Vec3f waypointPos;
        vec3f_set(waypointPos, (f32) curPoint->pos[0], (f32) curPoint->pos[1], (f32) curPoint->pos[2]);
        vec3f_get_dist(gMarioState->pos, waypointPos, &dist);
        if (dist < minDist && curPoint->pos[1] - 500 < gMarioState->pos[1]) {
            minDist = dist;
            returnPoint = curPoint;
        }

        curPoint = curPoint + 1;
    }

    return returnPoint;

}

void sewnia_act_idle(void) {
    o->oInteractStatus = 0;
    cur_obj_init_animation(0);

    o->oForwardVel = 0.0f;
    
}

void sewnia_act_follow_mario(void) {
    switch (o->oSubAction) {
        case 0:
            follow_mario_directly();
        break;
        case 1:
            follow_along_waypoints();
        break;
        case 2:
            stay_near_course_entrance();
        break;
    }
    

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oInteractStatus = 0;
        create_sewnia_dialog_box(3);
        o->oAction = SEWNIA_ACT_TALKING_TO_MARIO;
    }
    

}

u8 check_ray_to_mario() {
    struct Surface *surf;
        Vec3f originPos;
        Vec3f hitpos;
        Vec3f raydir;
        u8 rayResult = 0;

        raydir[0] = gMarioState->pos[0] - o->oPosX;
        raydir[1] = gMarioState->pos[1] - o->oPosY;
        raydir[2] = gMarioState->pos[2] - o->oPosZ;

        vec3f_set(originPos, o->oPosX, o->oPosY + 100.0f, o->oPosZ);
        vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

        find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 2);
        if (surf != NULL) rayResult = 1;
        find_surface_on_ray(originPos, raydir, &surf, hitpos, 1U, 2);
        if (surf != NULL) rayResult = 1;
        find_surface_on_ray(originPos, raydir, &surf, hitpos, 4U, 2);
        if (surf != NULL) rayResult = 1;


        return rayResult;
}

void follow_mario_directly(void) {
    if (o->oDistanceToMario > 400.0f) {
        cur_obj_init_animation_with_accel_and_sound(1, 1.5f);
        u8 approachMode = 0;
        //cast a ray towards mario. if there are no walls, floors, or ceilings in the way try 
        //to approach mario directly. Otherwise, follow a path along waypoints that leads closer to him.
        
        approachMode = check_ray_to_mario();

        if (approachMode == 0) {
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            o->oForwardVel = 20.0f;
        }
        else {
            o->oSewniaNextWaypoint = sewnia_find_nearest_waypoint();
           o->oSubAction = 1;
        }


    }
    else {
        cur_obj_init_animation(0);
        if (o->oForwardVel > 0.0f) {
        o->oForwardVel -= 4.0f;
    } else {
        o->oForwardVel = 0.0f;
    }
    }

    

    f32 dist;
    struct Object *nearPoint = cur_obj_find_nearest_object_with_behavior(bhvSewniaStoppingPoint, &dist);
    if (dist < 900 && lateral_dist_between_objects(nearPoint, gMarioObject) < 900) {
        o->oSubAction = 2;
    }
}

void follow_along_waypoints(void) {
    struct Waypoint *prevWaypoint = o->oSewniaLastWaypoint;
    struct Waypoint *nextWaypoint = o->oSewniaNextWaypoint;
    struct Waypoint *marioWaypoint;


   obj_turn_toward_position(o, (f32) nextWaypoint->pos[0], (f32) nextWaypoint->pos[1], (f32) nextWaypoint->pos[2], O_MOVE_ANGLE_YAW_INDEX, 0x1000);
    o->oForwardVel = 30.0f;

    f32 dist = 1000;
    Vec3f waypointPos;
    waypointPos[0] = nextWaypoint->pos[0];
    waypointPos[1] = nextWaypoint->pos[1];
    waypointPos[2] = nextWaypoint->pos[2];
    vec3f_get_dist(&o->oPosVec, waypointPos, &dist);

    if (dist < 100) {
        prevWaypoint = nextWaypoint;
        marioWaypoint = find_mario_nearest_waypoint();
        if (marioWaypoint->flags < prevWaypoint->flags) {
            nextWaypoint = nextWaypoint - 1;
        }
        else {
            nextWaypoint = nextWaypoint + 1;
        }
        
    }

    o->oSewniaNextWaypoint = nextWaypoint;
    o->oSewniaLastWaypoint = prevWaypoint;

    u8 approachMode = 0;
        approachMode = check_ray_to_mario();
        if (approachMode == 0) {
            o->oSubAction = 0;
        }
}

void stay_near_course_entrance(void) {
    f32 dist;
    struct Object *nearPoint = cur_obj_find_nearest_object_with_behavior(bhvSewniaStoppingPoint, &dist);

    if (dist > 100) {
        obj_turn_toward_object(o, nearPoint, O_MOVE_ANGLE_YAW_INDEX, 0x800);
        o->oForwardVel = 20.0f;
        cur_obj_init_animation_with_accel_and_sound(1, 1.5f);
    }
    else {
        obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
        o->oForwardVel = 0.0f;
        cur_obj_init_animation(0);
    }

    if (o->oDistanceToMario >= 900) {
        o->oSubAction = 0;
    }

    
}

void determine_course_dialog(void) {
    f32 dist;
    struct Object *nearPoint = cur_obj_find_nearest_object_with_behavior(bhvSewniaStoppingPoint, &dist);

    if (nearPoint && dist < 200) {
        switch (nearPoint->oBehParams2ndByte) {
            case 0:
                create_dialog_box(8);
            break;
            case 1:
                create_dialog_box(9);
            break;
        }
    }
    else {
        create_dialog_box(5);
    }
}

void sewnia_act_talking_to_mario(void) {
    obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
    obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);

    switch (o->oSubAction) {
        case 0:
        if (gDialogResponse > 0) {
            o->oSubAction = gDialogResponse;
            o->oTimer = 0;
            gDialogResponse = 0;
        }
        break;
        case 1:
            if (o->oTimer == 10) {
                create_dialog_box(4);
            }
        break;
        case 2:
            if (o->oTimer == 10) {
                determine_course_dialog();
            }
        case 3:
            if (o->oTimer == 10) {
                create_dialog_box(6);
            }
        break;
        case 4:
            if (o->oTimer == 10) {
                create_dialog_box(7);
            }
        break;
        break;
    }

    //puts mario back in idle after any of the 4 textboxes are done
    if (o->oSubAction != 0 && gDialogResponse > 0 && o->oTimer > 10) {
                gMarioState->action = ACT_IDLE;
                o->oAction = SEWNIA_ACT_FOLLOW_MARIO;
            }
}

void sewnia_act_cutscene(void) {

}

void bhv_sewnia_init(void) {
    obj_set_hitbox(o, &sSewniaHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
    o->oAction = 1;
    o->oGravity = -3.0f;

    o->oSewniaLastWaypoint = segmented_to_virtual(&castle_inside_area_1_spline_SewniaPath);
    o->oSewniaNextWaypoint = o->oSewniaLastWaypoint;
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

Gfx *geo_switch_doll_mouth(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        
    }

    return NULL;
}
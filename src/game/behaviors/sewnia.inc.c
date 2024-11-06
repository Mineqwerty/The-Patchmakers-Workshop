#include "levels/castle_inside/header.h"
#include "src/game/cutscene.h"
#include "levels/castle_inside/sewnia_pathfinding.inc.c"
#include "src/usb/debug.h"
#include "src/game/save_file.h"
#include "include/dialog_ids.h"

u32 flavorStart = 0;

extern const PathfindData sewnia_path_area_1[];

enum SewniaActions {
    SEWNIA_ACT_IDLE,
    SEWNIA_ACT_FOLLOW_MARIO,
    SEWNIA_ACT_TALKING_TO_MARIO,
    SEWNIA_ACT_EMOTE,
    SEWNIA_ACT_INTRO_CUTSCENE,
    SEWNIA_ACT_REVIVE_MARIO_CUTSCENE,
    SEWNIA_ACT_RUN_TO_NODE,
    SEWNIA_ACT_BEGINNING_CUTSCENE_AT_COURSE_ENTRANCE

};

enum SewniaAnims {
    SEWNIA_ANIM_OLD_IDLE,
    SEWNIA_ANIM_WALK,
    SEWNIA_ANIM_STARING,
    SEWNIA_ANIM_SURPRISED_FALL_BACK,
    SEWNIA_ANIM_STAND_UP_GREET_MARIO,
    SEWNIA_ANIM_CUTSCENE_IDLE_1,
    SEWNIA_ANIM_PEEK_AROUND_CORNER,
    SEWNIA_ANIM_WALK_TO_TABLE,
    SEWNIA_ANIM_INTRO_SEARCH,
    SEWNIA_ANIM_INTRO_FIND_PATCH,
    SEWNIA_ANIM_INTRO_PANIC_TURN,
    SEWNIA_ANIM_RUN_CORRIDOR,
    SEWNIA_ANIM_SLUMP_DOOR,
    SEWNIA_ANIM_PULL_OUT_PATCH
};

enum SewniaFaceStates {
    SEWNIA_FACE_STATE_DEFAULT,
    SEWNIA_FACE_STATE_DEFAULT_BLINK,
    SEWNIA_FACE_STATE_SURPRISED,
    SEWNIA_FACE_STATE_SMILE,
    SEWNIA_FACE_STATE_BLINK_HAPPY,
    SEWNIA_FACE_STATE_FROWN,
    SEWNIA_FACE_STATE_FROWN_BLINK,
    SEWNIA_FACE_STATE_SURPRISED_BLINK,
    SEWNIA_FACE_STATE_SCARED,
    SEWNIA_FACE_STATE_SCARED_GRIMACE,
    SEWNIA_FACE_STATE_BLINK_GRIMACE
};

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

struct PathfindNode waypointPath[40];
s16 shortestPath[50];

void sewnia_init_area_waypoints() {
    struct PathfindNode *curPoint = segmented_to_virtual(&sewnia_path_area_1);
    u8 reachedEnd = FALSE;
    for (int i = 0; i < 50; i++) {
        if (curPoint->nodeID == -1) {
            reachedEnd = TRUE;
            break;
        }

        if (!reachedEnd) {
            //bcopy(curPoint, &waypointPath[i], sizeof(curPoint));
            waypointPath[i] = *curPoint;
        }
        else {
            struct PathfindNode *empty;
            empty->nodeID = -1;
            bcopy(empty, &waypointPath[i], sizeof(empty));
        }

        curPoint = curPoint + 1;
    }

}


void find_best_path() {

    //this is a fake recursive algorithm, specifically non-recursive to avoid funny stack stuff
    
    u16 pathDistances[50];
    for (u8 i = 0; i < 50; i++) {
        shortestPath[i] = -1;
    }
    u8 nodesVisited[60];
    u8 roundRobinNodeValues[60];

    u16 weightDistance = 0;
    u16 smallestDistance = 64000;
    u8 visitedAll = FALSE;

    s32 startNode = o->oSewniaSourceNode;
    s16 currentNode = startNode;
    s32 goalNode = o->oMarioNearestNode;

    struct PathfindNeighbor goalAdjacentNodes[4];
    
    goalAdjacentNodes[0] = waypointPath[goalNode].neighbor1;
    goalAdjacentNodes[1] = waypointPath[goalNode].neighbor2;
    goalAdjacentNodes[2] = waypointPath[goalNode].neighbor3;
    goalAdjacentNodes[3] = waypointPath[goalNode].neighbor4;

    s16 nodeIndex = 0;
    s16 pathsTaken = 0;
    u64 touchedNodes = 0;

    s16 currentPath[50];
        
    for (u8 i = 0; i < 50; i++) {
        currentPath[i] = -1;
    }

    for (u8 nv = 0; nv < 60; nv++) {
        nodesVisited[nv] = FALSE;
        roundRobinNodeValues[nv] = 0;
    }

    while (!visitedAll ) {

        if (goalNode == startNode) {
            shortestPath[0] = goalNode;
            break;
        }
        
        currentPath[nodeIndex] = currentNode;
        touchedNodes |= (1 << currentNode);
        
        for (int j = 0; j < 4; j++) {
            if (currentNode == goalAdjacentNodes[j].id) {
                //finish searching here since the shortest path will always be the one to the goal
                pathDistances[nodeIndex] = goalAdjacentNodes[j].weight;
                currentPath[nodeIndex + 1] = goalNode;
                nodesVisited[currentNode] = TRUE;
                touchedNodes = 0;
                currentNode = goalNode;
                nodeIndex = -1; //set it to -1 to offset the +1 later on
            }
        }
        
        //search for the next path down
        
        if (nodeIndex > -1) {
            u8 initCheckValue = roundRobinNodeValues[currentNode];
            u8 foundPath = FALSE;
            u8 pathCheck = initCheckValue;
            while (!foundPath) {
                struct PathfindNeighbor neighborCheck;
                switch (pathCheck) {
                    case 0:
                        neighborCheck.id = waypointPath[currentNode].neighbor1.id;
                        neighborCheck.weight = waypointPath[currentNode].neighbor1.weight;
                    break;
                    case 1:
                        neighborCheck.id = waypointPath[currentNode].neighbor2.id;
                        neighborCheck.weight = waypointPath[currentNode].neighbor2.weight;
                    break;
                    case 2:
                        neighborCheck.id = waypointPath[currentNode].neighbor3.id;
                        neighborCheck.weight = waypointPath[currentNode].neighbor3.weight;
                    break;
                    case 3:
                        neighborCheck.id = waypointPath[currentNode].neighbor4.id;
                        neighborCheck.weight = waypointPath[currentNode].neighbor4.weight;
                    break;
                }

                if (neighborCheck.id != -1 && !nodesVisited[neighborCheck.id] && !(touchedNodes & (1 << neighborCheck.id))) {
                    //add to the round robin value to check a different branch next time
                    roundRobinNodeValues[currentNode] = (roundRobinNodeValues[currentNode] + 1) % 4;
                    
                    currentPath[nodeIndex] = currentNode;
                    pathDistances[nodeIndex] = neighborCheck.weight;
                    touchedNodes |= (1 << currentNode);
                    currentNode = neighborCheck.id;
                    foundPath = TRUE;
                    
                } else {

                    pathCheck = (pathCheck + 1) % 4;

                    //none of the paths are viable
                    if (pathCheck == initCheckValue) {
                        nodesVisited[currentNode] = TRUE;
                        pathDistances[nodeIndex] = -1;
                        foundPath = TRUE;
                        
                        nodeIndex = -1; //set it to -1 to offset the +1 later on
                        touchedNodes = 0;
                        osSyncPrintf("-------------------------------------------");
                        osSyncPrintf("NONGOAL:");
                        for (u8 i = 0; i < 50; i++) {
                            if (currentPath[i] > -1) {
                                char result[2000];
                                sprintf(result, "%d", currentPath[i]);
                                osSyncPrintf(result);
                            }
                        }

                        if (currentNode == startNode) {
                            visitedAll = TRUE;
                        osSyncPrintf("-------------------------------------------");
                        osSyncPrintf("FAILPATH:");
                            for (u8 i = 0; i < 50; i++) {

                        if (currentPath[i] > -1) {
                            char result[2000];
                            sprintf(result, "%d", currentPath[i]);
                            osSyncPrintf(result);
                        }
                    }
                    osSyncPrintf("BESTPATH:");
                            for (u8 i = 0; i < 50; i++) {

                        if (shortestPath[i] > -1) {
                            char result[2000];
                            sprintf(result, "%d", shortestPath[i]);
                            osSyncPrintf(result);
                        }
                    }
                    
                        }
                        currentNode = startNode;
                        }
                }
            }

            /*
            if (waypointPath[currentNode].neighbor1.id != -1 && !nodesVisited[waypointPath[currentNode].neighbor1.id] && !(touchedNodes & (1 << waypointPath[currentNode].neighbor1.id))) {
                currentPath[nodeIndex] = currentNode;
                pathDistances[nodeIndex] = waypointPath[currentNode].neighbor1.weight;
                touchedNodes |= (1 << currentNode);
                currentNode = waypointPath[currentNode].neighbor1.id;
            }
            else if (waypointPath[currentNode].neighbor2.id != -1 && !nodesVisited[waypointPath[currentNode].neighbor2.id] && !(touchedNodes & (1 << waypointPath[currentNode].neighbor2.id))) {
                currentPath[nodeIndex] = currentNode;
                pathDistances[nodeIndex] = waypointPath[currentNode].neighbor2.weight;
                touchedNodes |= (1 << currentNode);
                currentNode = waypointPath[currentNode].neighbor2.id;
            }
            else if (waypointPath[currentNode].neighbor3.id != -1 && !nodesVisited[waypointPath[currentNode].neighbor3.id] && !(touchedNodes & (1 << waypointPath[currentNode].neighbor3.id))) {
                currentPath[nodeIndex] = currentNode;
                pathDistances[nodeIndex] = waypointPath[currentNode].neighbor3.weight;
                touchedNodes |= (1 << currentNode);
                currentNode = waypointPath[currentNode].neighbor3.id;
            }
            else if (waypointPath[currentNode].neighbor4.id != -1 && !nodesVisited[waypointPath[currentNode].neighbor4.id] && !(touchedNodes & (1 << waypointPath[currentNode].neighbor4.id))) {
                currentPath[nodeIndex] = currentNode;
                pathDistances[nodeIndex] = waypointPath[currentNode].neighbor4.weight;
                touchedNodes |= (1 << currentNode);
                currentNode = waypointPath[currentNode].neighbor4.id;
            }
            //all neighbors have been exhausted
            
            else {
                nodesVisited[currentNode] = TRUE;
                pathDistances[nodeIndex] = -1;
                
                nodeIndex = -1; //set it to -1 to offset the +1 later on
                touchedNodes = 0;
                osSyncPrintf("-------------------------------------------");
  osSyncPrintf("NONGOAL:");
                    for (u8 i = 0; i < 50; i++) {

                if (currentPath[i] > -1) {
                    char result[2000];
                    sprintf(result, "%d", currentPath[i]);
                    osSyncPrintf(result);
                }
            }

                if (currentNode == startNode) {
                    visitedAll = TRUE;
                 osSyncPrintf("-------------------------------------------");
  osSyncPrintf("FAILPATH:");
                    for (u8 i = 0; i < 50; i++) {

                if (currentPath[i] > -1) {
                    char result[2000];
                    sprintf(result, "%d", currentPath[i]);
                    osSyncPrintf(result);
                }
            }
              osSyncPrintf("BESTPATH:");
                    for (u8 i = 0; i < 50; i++) {

                if (shortestPath[i] > -1) {
                    char result[2000];
                    sprintf(result, "%d", shortestPath[i]);
                    osSyncPrintf(result);
                }
            }
            osSyncPrintf("-------------------------------------------");
                }
                currentNode = startNode;
            }
            */
            
        }
        

        
    

        if (nodeIndex == -1) {

            if (currentNode == goalNode) {
                //first node path
                if (shortestPath[0] == -1) {
                    
                    s16 copyNode = currentPath[0];
                    s16 copyNodeID = 0;
                    u16 nodeDistance = 0;
                    while (copyNode != -1 && copyNodeID < 50) {
                        shortestPath[copyNodeID] = currentPath[copyNodeID];
                        //get distance

                        nodeDistance += pathDistances[copyNodeID];
                        copyNodeID++;
                        copyNode = currentPath[copyNodeID];
                    }
                    smallestDistance = nodeDistance;
                    
                }
                else {
                    s16 copyNode = currentPath[0];
                    s16 copyNodeID = 0;
                    u16 nodeDistance = 0;
                    for (u8 k = 0; k < 50; k++) {
                        nodeDistance += pathDistances[k];
                    }

                    if (nodeDistance < smallestDistance) {
                        while (copyNode != -1 && copyNodeID < 50) {
                            
                            shortestPath[copyNodeID] = currentPath[copyNodeID];
                            copyNodeID++;
                            copyNode = currentPath[copyNodeID];
                            
                        }
                        smallestDistance = nodeDistance;
                    }
                }
                for (u8 i = 0; i < 50; i++) {

                if (currentPath[i] > -1) {
                    char result[2000];
                    sprintf(result, "%d", currentPath[i]);
                    osSyncPrintf(result);
                }
            }

            osSyncPrintf("-------------------------------------------");
                currentNode = startNode;
            }

            for (u8 i = 0; i < 50; i++) {
                currentPath[i] = -1;
                pathDistances[i] = 0;
            }
            
        }

        nodeIndex += 1;
        pathsTaken += 1;

        if (nodesVisited[startNode] == TRUE) {
            visitedAll = TRUE;
        }
    }
    
}

struct PathfindNode *sewnia_find_nearest_waypoint() {
    f32 dist = 0;
    f32 minDist = 32000;
    struct PathfindNode *curPoint = segmented_to_virtual(&sewnia_path_area_1);
    struct PathfindNode *returnPoint;
    while (curPoint->nodeID != -1) {

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

struct PathfindNode *find_mario_nearest_waypoint() {
    f32 dist = 0;
    f32 minDist = 32000;
    struct PathfindNode *curPoint = segmented_to_virtual(&sewnia_path_area_1);
    struct PathfindNode *returnPoint;
    while (curPoint->nodeID != -1) {

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

struct PathfindNode *find_node_by_id(s16 nodeID) {
    
    struct PathfindNode *curPoint = segmented_to_virtual(&sewnia_path_area_1);
    struct PathfindNode *returnPoint;
    while (curPoint->nodeID != -1) {

        if (curPoint->nodeID == nodeID) {
            returnPoint = curPoint;
            return returnPoint;
        }

        curPoint = curPoint + 1;
    }

    return returnPoint;

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
        cur_obj_init_animation(SEWNIA_ANIM_OLD_IDLE);
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

    sewnia_init_area_waypoints();
    struct PathfindNode *sewniaNode = sewnia_find_nearest_waypoint();
    o->oSewniaSourceNode = sewniaNode->nodeID;
    struct PathfindNode *marioNode = find_mario_nearest_waypoint();

    if (o->oAction == SEWNIA_ACT_RUN_TO_NODE) {
        marioNode = find_node_by_id(o->oSewniaApproachSpecificNode);
    }

    if (o->oMarioNearestNode != marioNode->nodeID) {
        o->oMarioNearestNode = marioNode->nodeID;
        o->oSewniaCurrentNodeIndex = 0;
        find_best_path();
    }

    struct Waypoint *prevWaypoint = o->oSewniaLastWaypoint;
    struct Waypoint *nextWaypoint = o->oSewniaNextWaypoint;
    struct Waypoint *marioWaypoint;

    struct PathfindNode nextNode = waypointPath[shortestPath[o->oSewniaCurrentNodeIndex]];

    if (shortestPath[o->oSewniaCurrentNodeIndex] != -1) {

        obj_turn_toward_position(o, (f32) nextNode.pos[0], (f32) nextNode.pos[1], (f32) nextNode.pos[2], O_MOVE_ANGLE_YAW_INDEX, 0x1000);
        o->oForwardVel = 30.0f;

        cur_obj_update_floor_and_walls();

        if (o->oFlags & OBJ_MOVE_HIT_WALL) {
            s16 chosenAngle = abss(o->oMoveAngleYaw - (o->oWallAngle + 0x4000));
            if (abss(o->oMoveAngleYaw - (o->oWallAngle - 0x4000)) < chosenAngle) {
                chosenAngle = o->oWallAngle - 0x4000;
            }
            else {
                chosenAngle = o->oWallAngle + 0x4000;
            }
            o->oMoveAngleYaw = chosenAngle;
            o->oFlags &= ~OBJ_MOVE_HIT_WALL;
        }

        cur_obj_move_standard(-60);

        f32 dist = 1000;
        Vec3f waypointPos;
        waypointPos[0] = nextNode.pos[0];
        waypointPos[1] = nextNode.pos[1];
        waypointPos[2] = nextNode.pos[2];
        vec3f_get_dist(&o->oPosVec, waypointPos, &dist);

        if (dist < 100) {
            o->oSewniaCurrentNodeIndex += 1;
        }

        o->oSewniaNextWaypoint = nextWaypoint;
        o->oSewniaLastWaypoint = prevWaypoint;
    }

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

s16 sewnia_determine_flavor_text() {

    s16 flavorText = 0;

    if (gMarioState->numStars >= 10) {
        flavorText = DIALOG_SEWNIA_FLAVOR_10_STARS_1 + (flavorStart%2);
    }
    else if (save_file_get_patch_flags(gCurrSaveFileNum - 1) > 0) {
        flavorText = DIALOG_SEWNIA_FLAVOR_POST_PATCH_FOUND_1 + (flavorStart%3);
    }
    else {
        flavorText = DIALOG_SEWNIA_FLAVOR_BEGINNING_1 + (flavorStart%3);
    }

    flavorStart++;

    return flavorText;
}

enum SewniaDialogSubActions {
    SEWNIA_DIALOG_SUB_ACTION_ASKING_QUESTION,
    SEWNIA_DIALOG_SUB_ACTION_WHAT_NEXT,
    SEWNIA_DIALOG_SUB_ACTION_COURSE_INFO,
    SEWNIA_DIALOG_SUB_ACTION_FOLLOW_TOGGLE,
    SEWNIA_DIALOG_SUB_ACTION_CHATTING
};

void sewnia_act_talking_to_mario(void) {
    obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
    obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);

    switch (o->oSubAction) {
        case SEWNIA_DIALOG_SUB_ACTION_ASKING_QUESTION:
        if (gDialogResponse > 0) {
            o->oSubAction = gDialogResponse;
            o->oTimer = 0;
            gDialogResponse = 0;
        }
        break;
        case SEWNIA_DIALOG_SUB_ACTION_WHAT_NEXT:
            if (o->oTimer == 10) {
                create_dialog_box(4);
            }
        break;
        case SEWNIA_DIALOG_SUB_ACTION_COURSE_INFO:
            if (o->oTimer == 10) {
                determine_course_dialog();
            }
        case SEWNIA_DIALOG_SUB_ACTION_FOLLOW_TOGGLE:
            if (o->oTimer == 10) {
                create_dialog_box(6);
            }
        break;
        case SEWNIA_DIALOG_SUB_ACTION_CHATTING:
            if (o->oTimer == 10) {
                create_dialog_box(sewnia_determine_flavor_text());
            }
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

void sewnia_act_intro_cutscene(void) {
    o->oForwardVel = 0;

    if (cExternalCutsceneTrigger >= 100) {
        cur_obj_hide();
    }
    else {
        cur_obj_unhide();
    }
    switch (o->oSubAction) {
        case 0:
            o->oPosX = 0;
            o->oPosY = 100;
            o->oPosZ = 1152;
            cur_obj_init_animation(SEWNIA_ANIM_STARING);

            o->oSewniaFaceState = SEWNIA_FACE_STATE_DEFAULT;

            if (o->oTimer > 45 + (random_u16()%10)) {
                o->oTimer = 0;
            }

            if (o->oTimer < 3) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_DEFAULT_BLINK;
            }

            if (cExternalCutsceneTrigger == 1){
                cur_obj_init_animation(SEWNIA_ANIM_SURPRISED_FALL_BACK);
                o->oSubAction = 1;
                o->oTimer = 0;
            }
        break;
        case 1:
            o->oSewniaFaceState = 0;
            if (o->oTimer < 10) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_DEFAULT_BLINK;
            }
            else if (o->oTimer < 40) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_SURPRISED;
            }
            else {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }

            if (cExternalCutsceneTrigger == 2){
                o->oSubAction = 2;
                o->oTimer = 0;
            }
        break;
        case 2:
            o->oSewniaFaceState = SEWNIA_FACE_STATE_SURPRISED;

            if (o->oTimer > 45 + (random_u16()%10)) {
                o->oTimer = 0;
            }

            if (o->oTimer < 3) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_SURPRISED_BLINK;
            }

            if (cExternalCutsceneTrigger == 3){
                cur_obj_init_animation(SEWNIA_ANIM_STAND_UP_GREET_MARIO);
                o->oSubAction = 3;
                o->oTimer = 0;
            }
        break;
        case 3:
            
            if (o->oTimer < 12) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }
            else if (o->oTimer < 17) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN;
            }
            else if (o->oTimer < 23) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }
            else if (o->oTimer < 27) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN;
            }
            else if (o->oTimer < 57) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }
            else {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN;
            }
            if (cur_obj_check_if_at_animation_end()) {
                o->oSubAction = 4;
                cur_obj_init_animation(SEWNIA_ANIM_CUTSCENE_IDLE_1);
            }
        break;
        case 4:
            obj_turn_toward_object(o, gMarioState->marioObj, O_FACE_ANGLE_YAW_INDEX, 0x400);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            if (cExternalCutsceneTrigger == 5){
                o->oSubAction++;
            }
        break;
        case 5:
            //if (cExternalCutsceneTrigger == 5){
                o->oAction = SEWNIA_ACT_RUN_TO_NODE;
                o->oSewniaApproachSpecificNode = 30;
            //}
        break;
    }
}

void sewnia_update_movement(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-60);
    
}

void sewnia_act_run_to_node(void) {
    u8 nodeLimit = (o->oSewniaApproachSpecificNode == 30 ? 9 : 2);
    //disgustingly hardcoded. please find a better way
    if (o->oTimer < 10 || (o->oSewniaCurrentNodeIndex != nodeLimit)) {

        if (o->oSewniaApproachSpecificNode == 12 && o->oTimer > 30) {
            o->oForwardVel = 20.0f;
            sewnia_update_movement();
            if (o->oPosX < -1500) {
                if (o->oPosZ > 1150) {
                    o->oSewniaApproachSpecificNode = 13;
                    //obj_turn_toward_position(o, -3000, 0, 1460, O_MOVE_ANGLE_YAW_INDEX, 0x300);
                    //o->oSubAction++;
                    //if (o->oSubAction == 60) {
                    //    o->oAction = SEWNIA_ACT_BEGINNING_CUTSCENE_AT_COURSE_ENTRANCE;
                    //}
                }
                else {
                    obj_turn_toward_position(o, -2320, 0, 1160, O_MOVE_ANGLE_YAW_INDEX, 0x300);
                }
            }
            else {
                obj_turn_toward_position(o, -2170, 0, -1130, O_MOVE_ANGLE_YAW_INDEX, 0x300);
            }
        }
        else {
            cur_obj_init_animation_with_accel_and_sound(SEWNIA_ANIM_WALK, 1.5f);
            follow_along_waypoints();
            dbp(o->oSewniaCurrentNodeIndex);
        }
    }
    else {
        //cur_obj_init_animation(SEWNIA_ANIM_CUTSCENE_IDLE_1);
        o->oAction = SEWNIA_ACT_BEGINNING_CUTSCENE_AT_COURSE_ENTRANCE;
    }
}

void sewnia_act_beginning_cutscene_at_course_entrance(void) {
    switch (o->oSubAction) {
        case 0:
            stay_near_course_entrance();
            sewnia_update_movement();

            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oInteractStatus = 0;
                if (o->oSewniaApproachSpecificNode == 13) {
                    create_dialog_box(30);
                    o->oSubAction = 1;
                }
                else {
                    create_dialog_box(24);
                    o->oSubAction = 1;
                }
            }
        break;
        case 1:
            obj_turn_toward_object(o, gMarioObject, O_MOVE_ANGLE_YAW_INDEX, 0x800);
            obj_turn_toward_object(o, gMarioObject, O_FACE_ANGLE_YAW_INDEX, 0x800);
            if (o->oSubAction != 0 && gDialogResponse > 0 && o->oTimer > 10) {
                gMarioState->action = ACT_IDLE;

                if (o->oSewniaApproachSpecificNode == 30) {
                    o->oAction = SEWNIA_ACT_RUN_TO_NODE;
                    o->oSewniaApproachSpecificNode = 12;
                    o->oSubAction = 0;
                }
                else {
                    o->oAction = SEWNIA_ACT_FOLLOW_MARIO;
                }
                
            }
        break;
    }
}

void sewnia_act_revive_mario_cutscene(void) {
    o->oForwardVel = 0;

    if (cExternalCutsceneTrigger >= 100) {
        cur_obj_hide();
    }
    else {
        cur_obj_unhide();
    }
    switch (o->oSubAction) {
        case 0:
        o->oPosX = 0;
            o->oPosY = 100;
            o->oPosZ = 0;
            o->oFaceAngleYaw = 0;
            o->oMoveAngleYaw = 0;
            if (o->oTimer == 30) {
                o->oSubAction++;
                cur_obj_init_animation(SEWNIA_ANIM_INTRO_SEARCH);
            }
        break;
        case 1:
            if (cExternalCutsceneTrigger == 1) {
                o->oSubAction++;
                cur_obj_init_animation(SEWNIA_ANIM_INTRO_FIND_PATCH);
                o->oTimer = 0;
                
            }
        break;
        case 2:
            if (cExternalCutsceneTrigger == 2) {
                o->oSubAction++;
                o->oTimer = 0;
                cur_obj_init_animation(SEWNIA_ANIM_INTRO_PANIC_TURN);
            }

            if (o->oTimer == 98) {
                    o->oSewniaFaceState = SEWNIA_FACE_STATE_SCARED;
                }
        break;
        case 3:
            if (o->oTimer == 10) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_BLINK_GRIMACE;
            }

            if (o->oTimer == 25) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN;
            }

            if (o->oTimer == 120) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_BLINK_GRIMACE;
            }

            if (o->oTimer == 135) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_SCARED_GRIMACE;
            }

            if (cExternalCutsceneTrigger == 3) {
                o->oSubAction++;
                o->oTimer = 0;
                cur_obj_init_animation(SEWNIA_ANIM_RUN_CORRIDOR);
            }
        break;
        case 4:
               o->oSewniaFaceState = SEWNIA_FACE_STATE_SCARED;
               if (cExternalCutsceneTrigger == 4) {
                cur_obj_init_animation(SEWNIA_ANIM_SLUMP_DOOR);
                o->oSewniaFaceState = SEWNIA_FACE_STATE_SURPRISED;
                o->oTimer = 0;
                o->oSubAction++;
               }
        break;
        case 5:
            if (o->oTimer >= 230) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }
            else if (o->oTimer >= 112) {
                if (o->oTimer % 14 == 0) {
                    o->oSewniaFaceState = SEWNIA_FACE_STATE_SCARED;
                }
                else {
                    o->oSewniaFaceState = SEWNIA_FACE_STATE_SCARED;
                }
            }

            if (cExternalCutsceneTrigger == 6) {
                o->oTimer = 0;
                o->oSubAction++;
            }
        break;
        case 6:
            o->oPosX = 0;
            o->oPosY = 100;
            o->oPosZ = 0;
            o->oFaceAngleYaw = 0;
            o->oMoveAngleYaw = 0;
            cur_obj_init_animation(SEWNIA_ANIM_PEEK_AROUND_CORNER);

            o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN;

            if (o->oTimer > 45 + (random_u16()%10)) {
                o->oTimer = 0;
            }

            if (o->oTimer < 3) {
                o->oSewniaFaceState = SEWNIA_FACE_STATE_FROWN_BLINK;
            }

            if (cExternalCutsceneTrigger == 7){
                cur_obj_init_animation(SEWNIA_ANIM_WALK_TO_TABLE);
                o->oSubAction++;
                o->oTimer = 0;
                o->oPosZ = -400;
            }
        break;
        case 7:
            o->oForwardVel = 8.0f;
            sewnia_update_movement();
            if (cExternalCutsceneTrigger == 8) {
                o->oSubAction++;
                cur_obj_init_animation(SEWNIA_ANIM_PULL_OUT_PATCH);
                o->oForwardVel = 0;
                o->oPosX = 0;
                o->oPosY = 100;
                o->oPosZ = 0;
            }
        break;
        case 8:
            o->oPosX = 0;
            o->oPosY = 100;
            o->oPosZ = 0;
        break;
    }
}

void bhv_sewnia_init(void) {
    obj_set_hitbox(o, &sSewniaHitbox);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
    o->oAction = 1;
    o->oGravity = -3.0f;

    o->oSewniaLastWaypoint = segmented_to_virtual(&castle_inside_area_1_spline_SewniaPath);
    o->oSewniaNextWaypoint = o->oSewniaLastWaypoint;

    o->oWallHitboxRadius = 30.0f;

    //sewnia_init_area_waypoints();
}

void sewnia_act_idle(void) {
    o->oInteractStatus = 0;
    cur_obj_init_animation(SEWNIA_ANIM_OLD_IDLE);

    o->oForwardVel = 0.0f;
    
}

void sewnia_act_follow_mario(void) {
    switch (o->oSubAction) {
        case 0:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-60);
            follow_mario_directly();
            o->oMarioNearestNode = -1;
        break;
        case 1:
            follow_along_waypoints();
        break;
        case 2:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-60);
            stay_near_course_entrance();
            o->oMarioNearestNode = -1;
        break;
    }
    

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oInteractStatus = 0;
        create_sewnia_dialog_box(3);
        o->oAction = SEWNIA_ACT_TALKING_TO_MARIO;
    }
    

}



void bhv_sewnia_loop(void) {

    //print_text_fmt_int(200, 80, "sewnia %d", o->oSewniaSourceNode);
    //print_text_fmt_int(200, 60, "mario %d", o->oMarioNearestNode);

    switch (o->oAction) {
        case SEWNIA_ACT_IDLE:
            sewnia_update_movement();
            sewnia_act_idle();
        break;
        case SEWNIA_ACT_FOLLOW_MARIO:
            
            sewnia_act_follow_mario();
        break;
        case SEWNIA_ACT_TALKING_TO_MARIO:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-60);
            sewnia_act_talking_to_mario();
        break;
        case SEWNIA_ACT_EMOTE:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-60);
            sewnia_act_cutscene();
        break;
        case SEWNIA_ACT_INTRO_CUTSCENE:
            sewnia_act_intro_cutscene();
        break;
        case SEWNIA_ACT_REVIVE_MARIO_CUTSCENE:
            sewnia_act_revive_mario_cutscene();
        break;
        case SEWNIA_ACT_RUN_TO_NODE:
            sewnia_act_run_to_node();
        break;
        case SEWNIA_ACT_BEGINNING_CUTSCENE_AT_COURSE_ENTRANCE:
            sewnia_act_beginning_cutscene_at_course_entrance();
        break;
    }

    if (gCurCutscene != -1) {
        if (gCurCutscene == CUTSCENE_EVENT_MEET_SEWNIA) {
            o->oAction = SEWNIA_ACT_INTRO_CUTSCENE;
        }
        else if (gCurCutscene == CUTSCENE_EVENT_SEWNIA_REVIVE_MARIO) {
            o->oAction = SEWNIA_ACT_REVIVE_MARIO_CUTSCENE;
        }
    }
}

Gfx *geo_switch_doll_mouth(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;


        switchCase->selectedCase = obj->oSewniaFaceState;
    }

    return NULL;
}
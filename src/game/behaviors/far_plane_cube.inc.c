#include "levels/bbh/header.h"

static Trajectory const *sFarPlaneBlockPaths[] = {
    bbh_area_1_spline_BlockPath1,
    bbh_area_1_spline_BlockPath2,
    bbh_area_1_spline_BlockPath3,
    bbh_area_1_spline_BlockPath4,
    bbh_area_1_spline_BlockPath5,
    bbh_area_1_spline_BlockPath6,
    bbh_area_1_spline_BlockPath7,
};

void bhv_far_plane_cube_head_init(void) {
   o->oPlatformOnTrackStartWaypoint = segmented_to_virtual(sFarPlaneBlockPaths[o->oBehParams2ndByte]);
   o->oPlatformOnTrackPrevWaypoint = o->oPlatformOnTrackStartWaypoint;
    o->oPlatformOnTrackPrevWaypointFlags = WAYPOINT_FLAGS_NONE;
    o->oPlatformOnTrackBaseBallIndex = 0;

    vec3s_to_vec3f(&o->oHomeVec, o->oPlatformOnTrackStartWaypoint->pos);
    vec3f_copy(&o->oPosVec, &o->oHomeVec);
}

static void far_plane_cube_update(s32 ballIndex, Vec3f pos) {
    if ((ballIndex == 0) || (GET_BPARAM2(o->oBehParams) & PLATFORM_ON_TRACK_BP_SPAWN_BALLS)) {
        struct Waypoint *initialPrevWaypoint = o->oPlatformOnTrackPrevWaypoint;
        struct Waypoint *nextWaypoint = initialPrevWaypoint;
        struct Waypoint *prevWaypoint;
        f32 amountToMove;
        Vec3f d;
        f32 distToNextWaypoint;

        if (ballIndex != 0) {
            amountToMove = (300.0f * ballIndex);
        } else {
            obj_perform_position_op(POS_OP_SAVE_POSITION);
            o->oPlatformOnTrackPrevWaypointFlags = WAYPOINT_FLAGS_NONE;
            amountToMove = 60;
        }

        do {
            prevWaypoint = nextWaypoint;

            nextWaypoint++;
            if (nextWaypoint->flags == WAYPOINT_FLAGS_END) {
                
                    o->oBehParams2ndByte++;
                        o->oAction = 0;
                 o->oPlatformOnTrackStartWaypoint = segmented_to_virtual(sFarPlaneBlockPaths[o->oBehParams2ndByte]);
   o->oPlatformOnTrackPrevWaypoint = o->oPlatformOnTrackStartWaypoint;
    o->oPlatformOnTrackPrevWaypointFlags = WAYPOINT_FLAGS_NONE;
    o->oPlatformOnTrackBaseBallIndex = 0;

    vec3s_to_vec3f(&o->oHomeVec, o->oPlatformOnTrackStartWaypoint->pos);
    vec3f_copy(&o->oPosVec, &o->oHomeVec);

                    
                    return;
            }

            vec3_diff(d, nextWaypoint->pos, pos);

            distToNextWaypoint = vec3_mag(d);

            // Move directly to the next waypoint, even if it's farther away
            // than amountToMove
            amountToMove -= distToNextWaypoint;
            vec3f_add(pos, d);
        } while (amountToMove > 0.0f);

        // If we moved farther than amountToMove, move in the opposite direction
        // No risk of near-zero division: If distToNextWaypoint is close to
        // zero, then that means we didn't cross a waypoint this frame (since
        // otherwise distToNextWaypoint would equal the distance between two
        // waypoints, which should never be that small). But this implies that
        // amountToMove - distToNextWaypoint <= 0, and amountToMove is at least
        // 0.1 (from platform on track behavior).
        distToNextWaypoint = amountToMove / distToNextWaypoint;
        pos[0] += d[0] * distToNextWaypoint;
        pos[1] += d[1] * distToNextWaypoint;
        pos[2] += d[2] * distToNextWaypoint;

        if (ballIndex != 0) {
            struct Object *trackBall = spawn_object_relative((o->oPlatformOnTrackBaseBallIndex + ballIndex), 0, 0, 0, o,
                                              MODEL_TRAJECTORY_MARKER_BALL, bhvTrackBall);
            if (trackBall != NULL) {
                vec3f_copy(&trackBall->oPosVec, pos);
            }
        } else {
            if (prevWaypoint != initialPrevWaypoint) {
                if (o->oPlatformOnTrackPrevWaypointFlags == WAYPOINT_FLAGS_NONE) {
                    o->oPlatformOnTrackPrevWaypointFlags = initialPrevWaypoint->flags;
                }

                struct Object *cube = spawn_object_abs_with_rot( o, 0, MODEL_FAR_PLANE_CUBE, bhvFarPlaneCube, prevWaypoint->pos[0], prevWaypoint->pos[1],  prevWaypoint->pos[2], 0, 0, 0);
                o->oPlatformOnTrackPrevWaypoint = prevWaypoint;
            }

            vec3f_copy(&o->oPosVec, pos);

            obj_perform_position_op(POS_OP_COMPUTE_VELOCITY);

            o->oPlatformOnTrackPitch = atan2s(sqrtf(sqr(o->oVelX) + sqr(o->oVelZ)), -o->oVelY);
            o->oPlatformOnTrackYaw = atan2s(o->oVelZ, o->oVelX);
        }
    }
}

void bhv_far_plane_cube_head_loop(void) {
    if (cur_obj_was_attacked_or_ground_pounded()) {
        o->oAction = 1;
        spawn_object_abs_with_rot( o, 0, MODEL_FAR_PLANE_CUBE, bhvFarPlaneCube, o->oPlatformOnTrackStartWaypoint->pos[0], o->oPlatformOnTrackStartWaypoint->pos[1], o->oPlatformOnTrackStartWaypoint->pos[2], 0, 0, 0);
    }
    if (o->oAction == 1) {
        far_plane_cube_update(0, &o->oPosVec);
    }
}

void bhv_far_plane_cube_init(void) {
   play_sound(SOUND_BOX_BLIP, gGlobalSoundSource);

   if (o->oF4 == 1) {

    //o->collisionData = segmented_to_virtual(far_plane_cube_no_floor_collision);
   }
}

void bhv_far_plane_cube_loop(void) {
    if (o->oF4 != 1) {
   Vec3f abovePos;
   vec3f_set(abovePos, o->oPosX, o->oPosY + 190,
                      o->oPosZ);

    f32 dist;
   find_nearest_object_from_position_with_behavior(abovePos, bhvFarPlaneCube, &dist);

   if (dist < 30) {
    o->oF4 = 1;
    o->collisionData = segmented_to_virtual(far_plane_cube_no_floor_collision);
   }

   if (o->oTimer > 150) {
    o->oF4 = 1;
   }
    }
}


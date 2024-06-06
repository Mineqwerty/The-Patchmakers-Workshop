#include "levels/sl/header.h"

struct Trajectory *sAbyssSwimmerPaths[] = {
    sl_area_1_spline_SwimmerPath0,
    sl_area_1_spline_SwimmerPath1
};

void bhv_abyss_swimmer_init(void) {
    o->oPathedStartWaypoint = o->oPathedPrevWaypoint =
            segmented_to_virtual(sAbyssSwimmerPaths[o->oBehParams2ndByte]);
}

void bhv_abyss_swimmer_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o) {
                o->oAction = 1;
                cur_obj_init_animation(1);
            }
        break;
        case 1:
            cur_obj_follow_path();
            cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 0x400);
            if (cur_obj_check_anim_frame_in_range(21, 23)) {
                o->oForwardVel += 3.6f;
            }
            else if (o->oForwardVel > 0) {
                o->oForwardVel = CLAMP(o->oForwardVel - 1.7f, 0, 70.0f);
            }
            
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oFaceAngleYaw = approach_s16_asymptotic(o->oFaceAngleYaw, o->oMoveAngleYaw, 0.03f);
            
        break;
    }
}


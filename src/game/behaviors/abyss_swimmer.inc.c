#include "levels/sl/header.h"

struct Trajectory *sAbyssSwimmerPaths[] = {
    sl_area_1_spline_SwimmerPath0,
    sl_area_1_spline_SwimmerPath1,
    sl_area_1_spline_SwimmerPath2,
    sl_area_1_spline_SwimmerPath3
};

void bhv_abyss_swimmer_init(void) {
    o->oPathedStartWaypoint = o->oPathedPrevWaypoint =
            segmented_to_virtual(sAbyssSwimmerPaths[o->oBehParams2ndByte]);

    o->oDrawingDistance = (gIsConsole ? 5000 : 20000);
}

void bhv_abyss_swimmer_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform && gMarioState->marioObj->platform == o) {
                o->oAction = 1;
                cur_obj_init_animation(1);
            }
        break;
        case 1:;
            s32 followStatus;
            followStatus = cur_obj_follow_path();
            cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 0x400);
            if (cur_obj_check_anim_frame_in_range(21, 23)) {
                o->oForwardVel += 3.6f;
                for (int i = 0; i < 4; i++) {
                    spawn_object(o, MODEL_WHITE_PARTICLE_SMALL, bhvSmallParticleBubbles);
                }
            }
            else if (o->oForwardVel > 0) {
                o->oForwardVel = CLAMP(o->oForwardVel - 1.7f, 0, 70.0f);
            }
            
            cur_obj_move_xz_using_fvel_and_yaw();
            o->oFaceAngleYaw = approach_s16_asymptotic(o->oFaceAngleYaw, o->oMoveAngleYaw, 0.03f);

            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oPosY - (o->oPathedTargetPitch / 5), 0.03f);

            if (o->oPathedPrevWaypoint == o->oPathedStartWaypoint) {
                if (!gMarioState->marioObj->platform || gMarioState->marioObj->platform != o) {
                    o->oAction = 0;
                    cur_obj_init_animation(0);
                    o->oForwardVel = 0;
                }
            }
            
        break;
    }
}


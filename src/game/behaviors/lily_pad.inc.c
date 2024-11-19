#include "src/game/interaction.h"

void freeze_lily(void) {
    play_sound(SOUND_CHILLSTEP_PATCH_FREEZE, gMarioState->marioObj->header.gfx.cameraToObject);
    //cur_obj_spawn_particles(&SnowflakeFly2);
    //cur_obj_spawn_particles(&MistIce2);
    //obj->header.gfx.animInfo.curAnim->flags |= ANIM_FLAG_NO_ACCEL;
    o->oLilyIceObj = spawn_object_abs_with_rot(o, 0, MODEL_ICE_CUBE, bhvIceCube, o->oPosX, o->oPosY - 100, o->oPosZ, 0, 0, 0);
    check_for_max_ice_and_break_oldest();
    o->oLilyIceObj->oBehParams2ndByte = 1;
}

void bhv_lily_pad_init(void) {
    o->oBuoyancy = 0.3f;
    o->oGravity = 1.6f;
}

void bhv_lily_pad_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oGravity = 1.6f;
            if (gMarioState->marioObj->platform == o && gMarioState->equippedPatch == PATCH_BREEZE && gPlayer1Controller->buttonPressed & L_TRIG) {
                o->oAction = 1;
                o->oVelY = 100.0f;
                
            }

            if (gMarioState->marioObj->platform == o && gMarioState->equippedPatch == PATCH_CHILLSTEP) {
                freeze_lily();
                o->oAction = 2;
            }

        break;
        case 1:
        if (o->oTimer == 1) {
            gMarioState->action = ACT_BACKFLIP_LAND;
                gMarioState->forwardVel = 0;
        }
            o->oGravity = 1.2f;
            o->oMoveAngleYaw += 0x300;
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            if (o->oTimer == 120) {
                o->oAction = 0;
            }
        break;
        case 2:
            if (o->oLilyIceObj) {
                o->oForwardVel = 5.0f;
                cur_obj_move_xz_using_fvel_and_yaw();
            }
            else {
                o->oAction = 0;
            }
        break;
    }

    object_step_without_floor_orient();
    
}


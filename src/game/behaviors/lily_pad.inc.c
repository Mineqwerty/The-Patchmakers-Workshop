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
    o->oDrawingDistance = (gIsConsole ? 5000 : 20000);
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
                if (o->oBehParams2ndByte == 1) {
                    o->oAction = 2;
                }
                else {
                    o->oAction = 4;
                }
                
            }
            if (o->oTimer < 90) {
                object_step_without_floor_orient();
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
            object_step_without_floor_orient();
        break;
        case 2:
            if (o->oLilyIceObj) {
                o->oForwardVel = CLAMP(o->oTimer/2, 1.0f, 20.0f);
                o->oFriction = 1.0f;
                o->oLilyIceObj->oPosX = o->oPosX;
                o->oLilyIceObj->oPosY = o->oPosY - 100;
                o->oLilyIceObj->oPosZ = o->oPosZ;
                s16 collisionFlags = object_step();
                if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
                    o->oAction = 3;
                }
            }
            else {
                o->oAction = 0;
            }
        break;
        case 3:
            if (o->oLilyIceObj) {
                o->oForwardVel = 20.0f;
                o->oFriction = 1.0f;
                o->oLilyIceObj->oPosX = o->oPosX;
                o->oLilyIceObj->oPosY = o->oPosY - 100;
                o->oLilyIceObj->oPosZ = o->oPosZ;
                s16 collisionFlags = object_step();
                if (collisionFlags & OBJ_COL_FLAG_UNDERWATER) {
                    o->oAction = 4;
                }
            }
            else {
                o->oAction = 0;
            }
        break;
        case 4:

            o->oFriction = 0.1f;
            if (o->oForwardVel > 0) {
                o->oForwardVel -= (o->oTimer % 4 == 0);
            }

            if (o->oTimer > 60) {
                o->oPosY += 10.0f * (((o->oTimer % 2) * 2) - 1);
            }

            if (o->oLilyIceObj) {
                o->oLilyIceObj->oPosX = o->oPosX;
                o->oLilyIceObj->oPosY = o->oPosY - 100;
                o->oLilyIceObj->oPosZ = o->oPosZ;
            }

            if (o->oTimer == 90) {
                if (o->oLilyIceObj) {
                    o->oLilyIceObj->oAction = 20;
                    o->oLilyIceObj = NULL;
                }
                o->oAction = 0;
                o->oBehParams2ndByte = 0;
                o->oBehParams = 0;
            }

            object_step_without_floor_orient();
        break;
    }
    
}


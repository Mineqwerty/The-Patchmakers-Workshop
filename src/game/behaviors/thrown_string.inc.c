#include "src/game/cutscene.h"

void bhv_thrown_string_init(void) {
   
}

void bhv_thrown_string_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer < 30) {
            cur_obj_scale(CLAMP((f32)o->oTimer / 30.0f, 0.02f, 1.0f));
        }
        else {
            cur_obj_scale(1.0f);
        }
        o->oFaceAngleYaw = o->parentObj->oFaceAngleYaw - 0x4000;
        o->oFaceAnglePitch = 0x800;
        o->oPosX = o->parentObj->oPosX + 140 * sins(o->parentObj->oFaceAngleYaw - 0x6000);
        o->oPosY = o->parentObj->oPosY + 250;
        o->oPosZ = o->parentObj->oPosZ + -140 * -coss(o->parentObj->oFaceAngleYaw - 0x6000);
        
        Vec3f pointA;
        Vec3f pointB;
        Vec3f pointC;
        Vec3f pointD;

        s16 laserWidth = 60;
        s16 laserLength = 2500;

        vec3f_set(pointA, o->oPosX + laserWidth * coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * sins(o->oFaceAngleYaw + 0x50));
        vec3f_set(pointB, o->oPosX + laserWidth * -coss(o->oFaceAngleYaw), o->oPosY, o->oPosZ + laserWidth * -sins(o->oFaceAngleYaw + 0x50));

        //vec3f_set(pointA, o->oPosX + 300 * coss(o->oFaceAngleYaw + 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw + 0x50));
        //vec3f_set(pointB, o->oPosX + 300 * coss(o->oFaceAngleYaw - 0x50), o->oPosY, o->oPosZ + 300 * sins(o->oFaceAngleYaw - 0x50));
        vec3f_set(pointC, pointA[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointA[2] + laserLength * coss(o->oFaceAngleYaw));
        vec3f_set(pointD, pointB[0] + laserLength * sins(o->oFaceAngleYaw), o->oPosY, pointB[2] + laserLength * coss(o->oFaceAngleYaw));


        if (o->oTimer > 60 && (point_inside_xz_tri(gMarioState->pos, pointA, pointB, pointC) || point_inside_xz_tri(gMarioState->pos, pointA, pointC, pointD))) {
            if (absf(o->oPosY - 400 - gMarioState->pos[1] + 60) < 130 && gMarioState->action != ACT_BACKWARD_AIR_KB) {
                take_damage_from_no_interact_object(gMarioState, 1);
                if (gMarioState->health > 2*255) {
                    gMarioState->action = ACT_CAUGHT_BY_STRING;
                }
                gMarioState->faceAngle[1] = o->oFaceAngleYaw + 0x8000;
                cur_obj_play_sound_1(SOUND_MARIO_ATTACKED);
                o->oAction = 1;
                o->parentObj->oSubAction = 1;
            }
        }
    }
    else {

        if (o->oTimer == 20) {
            spawn_object_relative(0, 0, 40, 0, gMarioObject, MODEL_THREAD_BUNDLE, bhvThreadBundle);
        }

        cur_obj_init_animation(1);
        gMarioState->pos[0] = approach_f32_asymptotic(gMarioState->pos[0], o->oPosX + 1000 * sins(o->oFaceAngleYaw), 0.09f);
        gMarioState->pos[2] = approach_f32_asymptotic(gMarioState->pos[2], o->oPosZ + 1000 * coss(o->oFaceAngleYaw), 0.09f);

        if (gMarioState->action != ACT_CAUGHT_BY_STRING) {
            obj_mark_for_deletion(o);
        }
    }

    if (gCurCutscene != -1) {
        obj_mark_for_deletion(o);
    }
}


#include "src/game/game_init.h"
#include "src/game/camera.h"

void bhv_water_launcher_init(void) {

}

void bhv_water_launcher_loop(void) {
    switch (o->oAction) {
        case 0:
            if (((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED && gMarioState->waterFloor && gMarioState->waterFloor->object && gMarioState->waterFloor->object == o)) {
                    if (o->oDistanceToMario > 100) {
                        f32 dx = o->oPosX - gMarioState->pos[0];
                        f32 dz = o->oPosZ - gMarioState->pos[2];

                        s16 angleDiff = atan2s(dz, dx);

                        gMarioState->pos[0] += 5*sins(angleDiff);
                        gMarioState->pos[2] += 5*coss(angleDiff);

                        
                    }
                    gMarioState->pos[1] += (o->oPosY - 10 - gMarioState->pos[1]) * 0.2f;
                

                if (o->oTimer == 60) {
                    o->oAction = 1;
                    gMarioState->action = ACT_TRIPLE_JUMP;
                    gMarioState->vel[1] = 200.0f;
                    
                }
                else {
                    load_object_collision_model();
                }

                o->oPotogooApproachXZ = approach_f32_symmetric(o->oPotogooApproachXZ, 1.0f - (((f32)o->oTimer) / 90.0f) + 0.1f * sins(gGlobalTimer * 0x888), 0.1f);
                o->oPotogooApproachY = approach_f32_symmetric(o->oPotogooApproachY, 1.0f - (((f32)o->oTimer) / 90.0f) + 0.1f * coss(gGlobalTimer * 0x888), 0.1f);
                o->oPotogooVelXZ = 0.2f - (((f32)o->oTimer) / 180.0f);
                o->oPotogooVelY = 0.2f - (((f32)o->oTimer) / 180.0f);
                
                
            }
            else {
                o->oTimer = 0;
                o->oPotogooApproachXZ = approach_f32_symmetric(o->oPotogooApproachXZ, 1.0f + 0.2f * sins(gGlobalTimer * 0x444), 0.1f);
                    o->oPotogooApproachY = approach_f32_symmetric(o->oPotogooApproachY, 1.0f + 0.16f * coss(gGlobalTimer * 0x444), 0.1f);
                    o->oPotogooVelXZ = approach_f32_symmetric(o->oPotogooVelXZ, 0.1f, 0.03f);
                    o->oPotogooVelY = approach_f32_symmetric(o->oPotogooVelY, 0.1f, 0.03f);
                    load_object_collision_model();
            }

            
        break;

        case 1:

            o->oPotogooApproachXZ = approach_f32_symmetric(o->oPotogooApproachXZ, 1.0f + 0.2f * sins(gGlobalTimer * 0x444), 0.01f);
                    o->oPotogooApproachY = approach_f32_symmetric(o->oPotogooApproachY, 1.0f + 0.16f * coss(gGlobalTimer * 0x444), 0.01f);

                    o->oPotogooVelXZ = approach_f32_symmetric(o->oPotogooVelXZ, 0.1f, 0.01f);
                    o->oPotogooVelY = approach_f32_symmetric(o->oPotogooVelY, 0.1f, 0.01f);

                    if (o->oTimer == 60) {
                        o->oAction = 0;
                    }

                    if (o->oTimer == 30) {
                        sFOVState.fovFunc = CAM_FOV_APP_45;
                    set_camera_mode(gCamera, CAMERA_MODE_8_DIRECTIONS, 60);
                    }
        break;
    }
    

    elastic_approach(&o->oPotogooApproachXZ, &o->oPotogooVelXZ, (o->oTimer == 0 ? 1.0f : 0.3f), 0.1f, 0.3f);
                    elastic_approach(&o->oPotogooApproachY, &o->oPotogooVelY, (o->oTimer == 0 ? 1.0f : 0.3f), 0.3f, 0.3f);
                    obj_scale_xyz(o, o->oPotogooApproachXZ, o->oPotogooApproachY,
                                  o->oPotogooApproachXZ);
    
}


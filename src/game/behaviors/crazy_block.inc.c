#include "levels/bowser_3/crazy_block_1/collision_header.h"
#include "levels/bowser_3/crazy_block_2/collision_header.h"
#include "levels/bowser_3/crazy_block_3/collision_header.h"

void bhv_crazy_block_init(void) {
    u32 *collisionData;
    
    if (cur_obj_has_model(MODEL_CRAZY_BLOCK_1)) {
        collisionData = segmented_to_virtual(crazy_block_1_collision);
    } 
    else if (cur_obj_has_model(MODEL_CRAZY_BLOCK_2)) {
        collisionData = segmented_to_virtual(crazy_block_2_collision);
    } 
    else if (cur_obj_has_model(MODEL_CRAZY_BLOCK_3)) {
        collisionData = segmented_to_virtual(crazy_block_3_collision);
    } 
    
    o->collisionData = collisionData;
}

enum CRAZY_BLOCK_MOVEMENT_TYPES {
    CRAZY_BLOCK_MOVE_UP_DOWN,
    CRAZY_BLOCK_MOVE_ROTATE,
    CRAZY_BLOCK_MOVE_FORWARD_BACK,
    CRAZY_BLOCK_MOVE_AROUND_POINT,
    CRAZY_BLOCK_MOVE_AROUND_POINT_ROTATE

};

//bp1 is movement type
//bp2 is amplitude (times 10)
//bp3 is period (times 10)

void bhv_crazy_block_loop(void) {
    switch (GET_BPARAM1(o->oBehParams)) {
        case CRAZY_BLOCK_MOVE_UP_DOWN:
            o->oPosY = o->oHomeY + 10*o->oBehParams2ndByte*sins(o->oTimer * 10 * GET_BPARAM3(o->oBehParams));
        break;

        case CRAZY_BLOCK_MOVE_FORWARD_BACK:
            o->oForwardVel = o->oBehParams2ndByte*sins(o->oTimer * 10 * GET_BPARAM3(o->oBehParams));
            cur_obj_move_xz_using_fvel_and_yaw();
        break;

        case CRAZY_BLOCK_MOVE_ROTATE:
            o->oMoveAngleYaw = o->oTimer * 10 * GET_BPARAM3(o->oBehParams);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
        break;

        case CRAZY_BLOCK_MOVE_AROUND_POINT:
            o->oPosX = o->oHomeX + o->oBehParams2ndByte * 10 * sins((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer + o->oMoveAngleYaw);
            o->oPosZ = o->oHomeZ + o->oBehParams2ndByte * 10 * coss((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer + o->oMoveAngleYaw);
        break;

        case CRAZY_BLOCK_MOVE_AROUND_POINT_ROTATE:
            o->oPosX = o->oHomeX + o->oBehParams2ndByte * 10 * sins((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer);
            o->oPosZ = o->oHomeZ + o->oBehParams2ndByte * 10 * coss((GET_BPARAM3(o->oBehParams) * 10) * o->oTimer);
        
            o->oMoveAngleYaw += 0x222;
            o->oFaceAngleYaw = o->oMoveAngleYaw;
        break;
    }

    load_object_collision_model();
}


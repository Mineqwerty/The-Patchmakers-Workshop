#include "levels/bob/rosedrift/anim_header.h"
#include "levels/wf/talotak/anim_header.h"

void bhv_generic_npc_init(void) {
    o->oGravity  = 5.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;

    if (cur_obj_has_model(MODEL_ROSEDRIFT)) {
        o->oAnimations = rosedrift_anims;
        cur_obj_init_animation(0);
    }
    if (cur_obj_has_model(MODEL_TALOTAK)) {
        o->oAnimations = talotak_anims;
        cur_obj_init_animation(0);
    }

}

void bhv_generic_npc_loop(void) {
    
}

void bhv_talotak_init(void) {
    o->oGravity  = 5.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oBounciness = 1.0f;
    o->oInteractionSubtype = INT_SUBTYPE_NOT_GRABBABLE;
    o->oAnimations = talotak_anims;
    cur_obj_init_animation(0);
}

void bhv_talotak_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                if (cur_obj_check_if_near_animation_end()) {
                 o->oAction = 1;
                }
            }
        break;
        case 1:
            o->oVelY = 10.0f;
            cur_obj_init_animation(1);
            o->oAction = 2;
        break;
        case 2:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            if (cur_obj_check_if_near_animation_end()) {
                cur_obj_init_animation(0);
                o->oInteractStatus = 0;
            }
        break;
    }
}
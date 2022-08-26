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
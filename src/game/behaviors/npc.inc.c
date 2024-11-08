#include "levels/bob/rosedrift/anim_header.h"
#include "levels/wf/talotak/anim_header.h"
#include "levels/lll/butlergeist/anim_header.h"
#include "levels/lll/phantasmaid/anim_header.h"
#include "levels/ddd/cashew_man/anim_header.h"
#include "levels/ddd/hazelnut_woman/anim_header.h"
#include "levels/ddd/omiy/anim_header.h"

#include "src/game/cutscene.h"

void bhv_generic_npc_init(void) {
    o->oGravity  = 5.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;

    if (cur_obj_has_model(MODEL_ROSEDRIFT)) {
        o->oAnimations = (struct Animation **) rosedrift_anims;
        cur_obj_init_animation(0);
    }
    if (cur_obj_has_model(MODEL_TALOTAK)) {
        o->oAnimations = (struct Animation **) talotak_anims;
        cur_obj_init_animation(0);
    }
    if (cur_obj_has_model(MODEL_BUTLERGEIST)) {
        o->oAnimations = (struct Animation **) butlergeist_anims;
        cur_obj_init_animation(0);
    }
    if (cur_obj_has_model(MODEL_PHANTASMAID)) {
        o->oAnimations = (struct Animation **) phantasmaid_anims;
        cur_obj_init_animation(0);
    }
    if (cur_obj_has_model(MODEL_CASHEW_MAN) || cur_obj_has_model(MODEL_PECAN_MAN)) {
        o->oAnimations = (struct Animation **) cashew_man_anims;
        cur_obj_init_animation(GET_BPARAM1(o->oBehParams));
    }
    if (cur_obj_has_model(MODEL_HAZELNUT_WOMAN) || cur_obj_has_model(MODEL_MACADAMIA_WOMAN)) {
        o->oAnimations = (struct Animation **) hazelnut_woman_anims;
        cur_obj_init_animation(GET_BPARAM1(o->oBehParams));
    }
    if (cur_obj_has_model(MODEL_OMIY)) {
        o->oAnimations = (struct Animation **) omiy_anims;
        cur_obj_init_animation(0);
    }


}

void bhv_generic_npc_loop(void) {
    if (cur_obj_has_model(MODEL_PHANTASMAID)) {
        //turn anim
        if (cCutsceneActive && o->oTimer == 80) {
            cur_obj_init_animation(1);
        }
        //back to default when the cam is panned away
        if (cCutsceneActive && cExternalCutsceneTrigger == 1) {
            cur_obj_init_animation(0);
        }

        if (cCutsceneActive && cExternalCutsceneTrigger == 3) {
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
        }
        if (cCutsceneActive && cExternalCutsceneTrigger == 4) {
            SET_BPARAM1(o->oBehParams, 4);
            spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 300, gMarioState->pos[2]);
            cExternalCutsceneTrigger = 0;
        }
    }
}

void bhv_talotak_init(void) {
    o->oGravity  = 1.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oBounciness = 1.0f;
    o->oInteractionSubtype = INT_SUBTYPE_NOT_GRABBABLE;
    o->oAnimations = (struct Animation **) talotak_anims;
    cur_obj_init_animation(0);
}

void bhv_talotak_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED || o->oDistanceToMario < 400.0f) {
                 o->oAction = 1;
            }
        break;
        case 1:
            o->oVelY = 10.0f;
            cur_obj_init_animation(1);
            o->oAction = 2;
        break;
        case 2:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            object_step();
            if (cur_obj_check_if_near_animation_end()) {
                cur_obj_init_animation(0);
                o->oAction = 3;
            }
        break;
        case 3:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                 o->oAction = 1;
            }
            if (o->oDistanceToMario > 500.0f) {
                o->oAction = 0;
            }
        break;
    }

    o->oInteractStatus = 0;

}


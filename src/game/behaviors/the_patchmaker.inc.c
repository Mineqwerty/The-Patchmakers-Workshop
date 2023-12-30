enum PatchmakerActions {
    PATCHMAKER_ACT_CUTSCENE,
    PATCHMAKER_ACT_WALK_TO_MARIO,
    PATCHMAKER_ACT_JUMPS,
    PATCHMAKER_ACT_SLASH_DASH
};

enum PatchmakerAnims {
    PATCHMAKER_ANIM_IDLE,
    PATCHMAKER_ANIM_WALK,
    PATCHMAKER_ANIM_SLICE,
    PATCHMAKER_ANIM_JUMP,
    PATCHMAKER_ANIM_JUMP_END
};

void patchmaker_transition_to_next_action() {
    u16 randomAction = random_u16();
    u16 nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;

    switch (o->oAction) {
        case PATCHMAKER_ACT_CUTSCENE:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
        case PATCHMAKER_ACT_WALK_TO_MARIO:
            switch (randomAction % 2) {
                case 0:
                    nextAction = PATCHMAKER_ACT_JUMPS;
                break;
                case 1:
                    nextAction = PATCHMAKER_ACT_SLASH_DASH;
                break;
            }
        break;
        case PATCHMAKER_ACT_JUMPS:
            nextAction = PATCHMAKER_ACT_CUTSCENE;
        break;
        case PATCHMAKER_ACT_SLASH_DASH:

        break;
    }

    o->oAction = nextAction;
}

void patchmaker_act_cutscene(void) {
    if (o->oDistanceToMario < 1500.0f) {
        o->oAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        cur_obj_init_animation(1);
    }
}

void patchmaker_act_walk_to_mario(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    o->oForwardVel = 0.4f;
    object_step();

    if (o->oTimer == 45) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_jumps(void) {

    if (o->oTimer == 12) {
        cur_obj_init_animation(PATCHMAKER_ANIM_JUMP);
    }

    if (o->oTimer == 22) {
        o->oVelY = 25.0f;
        o->oForwardVel = 23.0f;
        o->oMoveAngleYaw = random_u16();
    }

    o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x400);

    s16 collisionFlags = object_step();

    if (((collisionFlags & OBJ_COL_FLAG_GROUNDED) && o->oTimer > 30 ) || o->oTimer >= 85) {
        o->oTimer = 0;
        o->oForwardVel = 0;
        o->oSubAction++;
        cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_JUMP_END, 2.0f);

        if (o->oSubAction == 3) {
            patchmaker_transition_to_next_action();
            o->oMoveAngleYaw = o->oFaceAngleYaw;
        }
    }

}

void patchmaker_act_slash_dash(void) {
    if (o->oTimer == 1) {
        cur_obj_init_animation(PATCHMAKER_ANIM_SLICE);
        o->oMoveAngleYaw = o->oAngleToMario;
        o->oForwardVel = 60.0f;
    }

    object_step();

    if (o->oTimer == 90) {
        patchmaker_transition_to_next_action();
    }
}

void bhv_patchmaker_init(void) {
    o->oGravity = 3.0f;
    o->oDragStrength = 5.0f;
    o->oFriction = 1.0f;
    o->oBounciness = 0.0f;
}

void bhv_patchmaker_loop(void) {
    switch (o->oAction) {
        case PATCHMAKER_ACT_CUTSCENE:
            patchmaker_act_cutscene();
        break;
        case PATCHMAKER_ACT_WALK_TO_MARIO:
            patchmaker_act_walk_to_mario();
        break;
        case PATCHMAKER_ACT_JUMPS:
            patchmaker_act_jumps();
        break;
         case PATCHMAKER_ACT_SLASH_DASH:
            patchmaker_act_slash_dash();
        break;
    }

    if (o->oAction != PATCHMAKER_ACT_JUMPS) {
        o->oFaceAngleYaw = o->oMoveAngleYaw;
    }
}

Gfx *geo_switch_patchmaker_needle(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

            if (obj->oAction == 1 && (obj->oSubAction >= 1 || obj->oTimer > 16)) {
                switchCase->selectedCase = 1;
            }
            else {
                switchCase->selectedCase = 0;
            }
    }
    return NULL;
}
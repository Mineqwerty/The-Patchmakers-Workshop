enum PatchmakerActions {
    PATCHMAKER_ACT_CUTSCENE,
    PATCHMAKER_ACT_WALK_TO_MARIO,
    PATCHMAKER_ACT_JUMPS,
    PATCHMAKER_ACT_SLASH_DASH,
    PATCHMAKER_ACT_GRAB_MARIO
};

enum PatchmakerAnims {
    PATCHMAKER_ANIM_IDLE,
    PATCHMAKER_ANIM_WALK,
    PATCHMAKER_ANIM_SLICE,
    PATCHMAKER_ANIM_JUMP,
    PATCHMAKER_ANIM_JUMP_END,
    PATCHMAKER_ANIM_POINT,
    PATCHMAKER_ANIM_START_GRAB,
    PATCHMAKER_ANIM_GRAB_MISS,
    PATCHMAKER_ANIM_GRAB_MARIO_ATTACK
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
            if (o->oDistanceToMario < 250) {
                nextAction = PATCHMAKER_ACT_GRAB_MARIO;
            }
            else {
                nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
            }
            
        break;
        case PATCHMAKER_ACT_SLASH_DASH:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;

        case PATCHMAKER_ACT_GRAB_MARIO:
            nextAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        break;
    }

    o->oAction = nextAction;
    o->oSubAction = 0;
}

void patchmaker_act_cutscene(void) {
    if (o->oDistanceToMario < 1500.0f) {
        o->oAction = PATCHMAKER_ACT_WALK_TO_MARIO;
        cur_obj_init_animation(1);
        gSecondCameraFocus = o;
        set_camera_mode(gMarioState->area->camera, CAMERA_MODE_BOSS_FIGHT, 1);
    }
}

void patchmaker_act_walk_to_mario(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
    cur_obj_init_animation(PATCHMAKER_ANIM_WALK);
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

    if (o->oTimer == 26) {
        o->oVelY = 25.0f;
        o->oForwardVel = 23.0f;
        if (o->oSubAction == 2) {
            if (random_u16()%1 == 0) {
                o->oMoveAngleYaw = o->oAngleToMario;
                f32 dist;
                vec3f_get_lateral_dist(&o->oPosVec, gMarioState->pos, &dist);
                o->oForwardVel = 0.05*dist;
                o->oVelY = 30.0f;
            }
            else {
                o->oMoveAngleYaw = random_u16();
            }
        }
        else {
            o->oMoveAngleYaw = random_u16();
        }
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
        
    }

    if (o->oTimer == 20) {
        o->oForwardVel = 30.0f;
    }

    object_step();

    if (cur_obj_check_if_at_animation_end()) {
        patchmaker_transition_to_next_action();
    }
}

void patchmaker_act_grab_mario(void) {
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer <= 1) {
                cur_obj_init_animation_with_accel_and_sound(PATCHMAKER_ANIM_START_GRAB, 1.5f);
            }

            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);

            if (cur_obj_check_if_near_animation_end()) {
                if ((o->oAngleToMario) < 0x4000 && o->oDistanceToMario < 250) {
                    o->oSubAction = 2;
                }
                else {
                    o->oSubAction = 1;
                }
            }

        break;
        case 1:
            //grab fail
            cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_MISS);
            if (cur_obj_check_if_near_animation_end()) {
                patchmaker_transition_to_next_action();
            }
        break;
        case 2:
            cur_obj_init_animation(PATCHMAKER_ANIM_GRAB_MARIO_ATTACK);

            if (o->oTimer < 66) {
            gMarioState->action = ACT_STORY_CUTSCENE;
            gMarioState->pos[0] = o->oPosX + 70 * sins(o->oFaceAngleYaw);
            gMarioState->pos[2] = o->oPosZ + 70 * coss(o->oFaceAngleYaw);
            gMarioState->pos[1] = o->oPosY + 100;
            gMarioState->faceAngle[1] = o->oFaceAngleYaw;
            set_mario_animation(gMarioState, MARIO_ANIM_DROWNING_PART1);
            }
            else if (o->oTimer == 66) {
                gMarioState->action = ACT_FORWARD_AIR_KB;
                gMarioState->forwardVel  = 30.0f;
                gMarioState->vel[1] = 10.0f;
            }

            if (o->oTimer > 40 && o->oTimer < 70 && (o->oTimer % 10 > 3) && (o->oTimer % 10 < 8)) {
                
            }

            if (o->oTimer == 42 || o->oTimer == 54 || o->oTimer == 66) {
                take_damage_from_no_interact_object(gMarioState, 1);
                gMarioState->pos[0] += random_u16()%20 - 10;
                gMarioState->pos[1] += random_u16()%20 - 10;
                gMarioState->pos[2] += random_u16()%20 - 10;
            }

            if (cur_obj_check_if_at_animation_end()) {
                patchmaker_transition_to_next_action();
            }
        break;
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
        case PATCHMAKER_ACT_GRAB_MARIO:
            patchmaker_act_grab_mario();
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
enum PatchmakerActions {
    PATCHMAKER_ACT_CUTSCENE,
    PATCHMAKER_ACT_WALK_TO_MARIO
};

void bhv_patchmaker_init(void) {
    o->oGravity = 1.0f;
}

void bhv_patchmaker_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1500.0f) {
                o->oAction = 1;
                cur_obj_init_animation(1);
            }
        break;
        case 1:
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
            o->oForwardVel = 0.4f;
            object_step();
        break;
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
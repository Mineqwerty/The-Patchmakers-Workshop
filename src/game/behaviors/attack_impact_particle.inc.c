void bhv_attack_impact_particle_init(void) {
   
}

void bhv_attack_impact_particle_loop(void) {
    cur_obj_scale(CLAMP((f32)o->oTimer / 2.0f, 0.02f, 3.0f));

    if (o->oTimer == 10) {
        obj_mark_for_deletion(o);
    }

    o->oFaceAngleYaw = gCamera->yaw;

    o->oFaceAngleRoll = o->oTimer * 0x222;

    o->oOpacity = 230 - o->oTimer * 23;
}

Gfx *geo_switch_impact_particle(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        switchCase->selectedCase = CLAMP((obj->oTimer + 1) / 3, 1, 4);
    }
}
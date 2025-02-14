void bhv_final_needle_init(void) {
    //o->oFaceAngleYaw = 0x4000;
}

u8 finalNeedleTopLeftVtx[8] = {
    2, 3, 6, 7, 8, 11, 13, 14
};

void bhv_final_needle_loop(void) {
    extern Vtx final_needle_Circle_002_mesh_layer_1_vtx_1[64];

        Vtx *new = segmented_to_virtual(final_needle_Circle_002_mesh_layer_1_vtx_1);

        //coss(o->oFaceAngleYaw)*(-o->oPosX + gMarioState->pos[0] + shadowChompXOffsets[curVtx]) - sins(o->oFaceAngleYaw)*(-o->oPosZ + gMarioState->pos[2] + shadowChompZOffsets[curVtx]);

        Vec3f topLeftPos;
        topLeftPos[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + 2496) - sins(o->oFaceAngleYaw)*(-o->oPosZ + -2108);
        topLeftPos[1] = -o->oPosY + 3823;
        topLeftPos[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + -2108) - sins(o->oFaceAngleYaw)*(-o->oPosX + 2496);

        s16 i;

        for (i = 0; i < 8; i++) {
            new[finalNeedleTopLeftVtx[i]].v.ob[0] = topLeftPos[0];
            new[finalNeedleTopLeftVtx[i]].v.ob[1] = topLeftPos[1];
            new[finalNeedleTopLeftVtx[i]].v.ob[2] = topLeftPos[2];
        }
}


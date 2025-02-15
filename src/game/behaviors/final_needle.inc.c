void bhv_final_needle_init(void) {
    o->oFaceAngleYaw = 0x4000;
}

u8 finalNeedleTopLeftVtx[8] = {
    2, 3, 6, 7, 8, 11, 13, 14
};

u8 finalNeedleTopRightVtx[8] = {
    18, 19, 22, 23, 24, 27, 29, 30
};

u8 finalNeedleBottomLeftVtx[8] = {
    34, 35, 38, 39, 40, 43, 45, 46
};

u8 finalNeedleBottomRightVtx[8] = {
    50, 51, 54, 55, 56, 59, 61, 62
};

void update_wall_attachment(void) {
    extern Vtx final_needle_Circle_002_mesh_layer_1_vtx_1[64];

        Vtx *new = segmented_to_virtual(final_needle_Circle_002_mesh_layer_1_vtx_1);

        Vec3f topLeftPos;
        topLeftPos[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + 2496) + sins(o->oFaceAngleYaw)*(-o->oPosZ + -2108);
        topLeftPos[1] = -o->oPosY + 3823;
        topLeftPos[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + -2108) + sins(o->oFaceAngleYaw)*(-o->oPosX + 2496);

        Vec3f topRightPos;
        topRightPos[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + 2496) + sins(o->oFaceAngleYaw)*(-o->oPosZ + 2108);
        topRightPos[1] = -o->oPosY + 3823;
        topRightPos[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + 2108) + sins(o->oFaceAngleYaw)*(-o->oPosX + 2496);
        
        Vec3f bottomLeftPos;
        bottomLeftPos[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + 2496) + sins(o->oFaceAngleYaw)*(-o->oPosZ + -2108);
        bottomLeftPos[1] = -o->oPosY + 1823;
        bottomLeftPos[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + -2108) + sins(o->oFaceAngleYaw)*(-o->oPosX + 2496);

        Vec3f bottomRightPos;
        bottomRightPos[0] = coss(o->oFaceAngleYaw)*(-o->oPosX + 2496) + sins(o->oFaceAngleYaw)*(-o->oPosZ + 2108);
        bottomRightPos[1] = -o->oPosY + 1823;
        bottomRightPos[2] = coss(o->oFaceAngleYaw)*(-o->oPosZ + 2108) + sins(o->oFaceAngleYaw)*(-o->oPosX + 2496);

        s16 i;

        for (i = 0; i < 8; i++) {
            new[finalNeedleTopLeftVtx[i]].v.ob[0] = topLeftPos[0];
            new[finalNeedleTopLeftVtx[i]].v.ob[1] = topLeftPos[1];
            new[finalNeedleTopLeftVtx[i]].v.ob[2] = topLeftPos[2];

            new[finalNeedleTopRightVtx[i]].v.ob[0] = topRightPos[0];
            new[finalNeedleTopRightVtx[i]].v.ob[1] = topRightPos[1];
            new[finalNeedleTopRightVtx[i]].v.ob[2] = topRightPos[2];

            new[finalNeedleBottomLeftVtx[i]].v.ob[0] = bottomLeftPos[0];
            new[finalNeedleBottomLeftVtx[i]].v.ob[1] = bottomLeftPos[1];
            new[finalNeedleBottomLeftVtx[i]].v.ob[2] = bottomLeftPos[2];

            new[finalNeedleBottomRightVtx[i]].v.ob[0] = bottomRightPos[0];
            new[finalNeedleBottomRightVtx[i]].v.ob[1] = bottomRightPos[1];
            new[finalNeedleBottomRightVtx[i]].v.ob[2] = bottomRightPos[2];
        }
}

void bhv_final_needle_loop(void) {

    switch (o->oAction) {
        case 0:
            o->oPosY -= 10 + o->oTimer;
            if (o->oTimer == 60) {
                o->oAction++;
            }
        break;
        case 1:
            o->oPosY = 1300;
            o->oPosZ = 0;
            
            o->oPosX = -30 + -800 * gFinalNeedleProgress;
            o->oFaceAnglePitch = -3000 * gFinalNeedleProgress;
        break;
    }

    update_wall_attachment();
}


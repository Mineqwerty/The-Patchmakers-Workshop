Vtx ts_final_door_Plane_032_mesh_layer_1_vtx_cull[8] = {
	{{ {-202, -582, 336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-202, 229, 336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-202, 229, -336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-202, -582, -336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {202, -582, 336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {202, 229, 336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {202, 229, -336}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {202, -582, -336}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx ts_final_door_Plane_032_mesh_layer_1_vtx_0[18] = {
	{{ {-202, 74, 336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 180, 224}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 213, 112}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 74, 336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, -582, 336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, -582, 336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 74, -336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 213, -112}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 229, 0}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 213, 112}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 180, 224}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 229, 0}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 180, -224}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, -582, -336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, -582, -336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 74, -336}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {-202, 180, -224}, 0, {-16, 1008}, {139, 0, 2, 255} }},
	{{ {202, 213, -112}, 0, {-16, 1008}, {139, 0, 2, 255} }},
};

Gfx ts_final_door_Plane_032_mesh_layer_1_tri_0[] = {
	gsSPVertex(ts_final_door_Plane_032_mesh_layer_1_vtx_0 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(5, 0, 2, 0, 2, 6, 5, 0),
	gsSP2Triangles(2, 7, 6, 0, 2, 8, 7, 0),
	gsSP2Triangles(8, 2, 9, 0, 2, 10, 9, 0),
	gsSP2Triangles(2, 1, 10, 0, 1, 3, 10, 0),
	gsSP2Triangles(9, 10, 3, 0, 11, 9, 3, 0),
	gsSP2Triangles(3, 12, 11, 0, 3, 13, 12, 0),
	gsSP2Triangles(3, 4, 13, 0, 5, 13, 4, 0),
	gsSP2Triangles(5, 14, 13, 0, 6, 14, 5, 0),
	gsSP2Triangles(14, 6, 15, 0, 6, 12, 15, 0),
	gsSP2Triangles(6, 16, 12, 0, 7, 16, 6, 0),
	gsSP2Triangles(16, 7, 17, 0, 7, 11, 17, 0),
	gsSP2Triangles(7, 8, 11, 0, 8, 9, 11, 0),
	gsSP2Triangles(12, 17, 11, 0, 16, 17, 12, 0),
	gsSP2Triangles(13, 15, 12, 0, 14, 15, 13, 0),
	gsSPEndDisplayList(),
};


Gfx mat_ts_final_door_primwhite_001[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_ts_final_door_primwhite_001[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx ts_final_door_Plane_032_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(ts_final_door_Plane_032_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_ts_final_door_primwhite_001),
	gsSPDisplayList(ts_final_door_Plane_032_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_ts_final_door_primwhite_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


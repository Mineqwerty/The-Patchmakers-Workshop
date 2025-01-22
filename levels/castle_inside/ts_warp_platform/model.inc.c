Vtx ts_warp_platform_Cube_018_mesh_layer_1_vtx_cull[8] = {
	{{ {-151, -33, 151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-151, 33, 151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-151, 33, -151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-151, -33, -151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {151, -33, 151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {151, 33, 151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {151, 33, -151}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {151, -33, -151}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx ts_warp_platform_Cube_018_mesh_layer_1_vtx_0[18] = {
	{{ {-151, -33, 151}, 0, {368, 1008}, {87, 0, 0, 255} }},
	{{ {-151, 33, 151}, 0, {624, 1008}, {175, 1, 0, 255} }},
	{{ {-151, 33, -151}, 0, {624, 752}, {174, 1, 0, 255} }},
	{{ {-151, -33, -151}, 0, {368, 752}, {87, 0, 0, 255} }},
	{{ {151, 33, -151}, 0, {624, 496}, {166, 1, 0, 255} }},
	{{ {151, -33, -151}, 0, {368, 496}, {87, 0, 0, 255} }},
	{{ {151, 33, 151}, 0, {624, 240}, {175, 1, 0, 255} }},
	{{ {130, 33, -130}, 0, {642, 478}, {218, 52, 49, 255} }},
	{{ {-130, 33, -130}, 0, {862, 478}, {218, 52, 49, 255} }},
	{{ {-151, 33, -151}, 0, {880, 496}, {174, 1, 0, 255} }},
	{{ {-130, 33, 130}, 0, {862, 258}, {218, 52, 49, 255} }},
	{{ {-151, 33, 151}, 0, {880, 240}, {175, 1, 0, 255} }},
	{{ {130, 33, 130}, 0, {642, 258}, {218, 52, 49, 255} }},
	{{ {151, -33, 151}, 0, {368, 240}, {88, 0, 0, 255} }},
	{{ {-151, 33, 151}, 0, {624, -16}, {175, 1, 0, 255} }},
	{{ {-151, -33, 151}, 0, {368, -16}, {87, 0, 0, 255} }},
	{{ {-151, -33, -151}, 0, {112, 496}, {87, 0, 0, 255} }},
	{{ {-151, -33, 151}, 0, {112, 240}, {87, 0, 0, 255} }},
};

Gfx ts_warp_platform_Cube_018_mesh_layer_1_tri_0[] = {
	gsSPVertex(ts_warp_platform_Cube_018_mesh_layer_1_vtx_0 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 7, 6, 4, 0),
	gsSP2Triangles(8, 7, 4, 0, 8, 4, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 10, 11, 0, 12, 11, 6, 0),
	gsSP2Triangles(7, 12, 6, 0, 7, 10, 12, 0),
	gsSP2Triangles(7, 8, 10, 0, 5, 6, 13, 0),
	gsSP2Triangles(13, 6, 14, 0, 13, 14, 15, 0),
	gsSP2Triangles(16, 5, 13, 0, 16, 13, 17, 0),
	gsSPEndDisplayList(),
};


Gfx mat_ts_warp_platform_f3dlite_material[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_ts_warp_platform_f3dlite_material[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx ts_warp_platform_Cube_018_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(ts_warp_platform_Cube_018_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_ts_warp_platform_f3dlite_material),
	gsSPDisplayList(ts_warp_platform_Cube_018_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_ts_warp_platform_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


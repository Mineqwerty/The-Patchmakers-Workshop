Vtx sight_switch_inactive_Plane_002_mesh_layer_1_vtx_cull[8] = {
	{{ {-180, -271, 180}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-180, 341, 180}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-180, 341, -271}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-180, -271, -271}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {321, -271, 180}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {321, 341, 180}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {321, 341, -271}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {321, -271, -271}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx sight_switch_inactive_Plane_002_mesh_layer_1_vtx_0[12] = {
	{{ {180, 321, -180}, 0, {680, 440}, {121, 22, 25, 255} }},
	{{ {-180, 321, -180}, 0, {824, 440}, {121, 22, 25, 255} }},
	{{ {-180, 341, -180}, 0, {824, 440}, {121, 22, 25, 255} }},
	{{ {-180, 321, 180}, 0, {824, 296}, {121, 22, 25, 255} }},
	{{ {180, 321, 180}, 0, {680, 296}, {121, 22, 25, 255} }},
	{{ {180, 341, -180}, 0, {680, 440}, {121, 22, 25, 255} }},
	{{ {-145, 341, -145}, 0, {810, 426}, {121, 22, 25, 255} }},
	{{ {-145, 341, 145}, 0, {810, 310}, {121, 22, 25, 255} }},
	{{ {-180, 341, 180}, 0, {824, 296}, {121, 22, 25, 255} }},
	{{ {180, 341, 180}, 0, {680, 296}, {121, 22, 25, 255} }},
	{{ {145, 341, -145}, 0, {694, 426}, {121, 22, 25, 255} }},
	{{ {145, 341, 145}, 0, {694, 310}, {121, 22, 25, 255} }},
};

Gfx sight_switch_inactive_Plane_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(sight_switch_inactive_Plane_002_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 0, 4, 0, 4, 0, 5, 0),
	gsSP2Triangles(0, 2, 5, 0, 6, 5, 2, 0),
	gsSP2Triangles(7, 6, 2, 0, 7, 2, 8, 0),
	gsSP2Triangles(1, 8, 2, 0, 1, 3, 8, 0),
	gsSP2Triangles(3, 9, 8, 0, 3, 4, 9, 0),
	gsSP2Triangles(4, 5, 9, 0, 10, 9, 5, 0),
	gsSP2Triangles(6, 10, 5, 0, 10, 11, 9, 0),
	gsSP2Triangles(11, 8, 9, 0, 11, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx sight_switch_inactive_Plane_002_mesh_layer_1_vtx_1[4] = {
	{{ {145, 341, -145}, 0, {694, 426}, {121, 22, 25, 255} }},
	{{ {-145, 341, -145}, 0, {810, 426}, {121, 22, 25, 255} }},
	{{ {-145, 341, 145}, 0, {810, 310}, {121, 22, 25, 255} }},
	{{ {145, 341, 145}, 0, {694, 310}, {121, 22, 25, 255} }},
};

Gfx sight_switch_inactive_Plane_002_mesh_layer_1_tri_1[] = {
	gsSPVertex(sight_switch_inactive_Plane_002_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_sight_switch_inactive_primwhite_001[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_sight_switch_inactive_primwhite_001[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_sight_switch_inactive_prim_sight[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 164, 163, 193, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_sight_switch_inactive_prim_sight[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx sight_switch_inactive_Plane_002_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(sight_switch_inactive_Plane_002_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_sight_switch_inactive_primwhite_001),
	gsSPDisplayList(sight_switch_inactive_Plane_002_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_sight_switch_inactive_primwhite_001),
	gsSPDisplayList(mat_sight_switch_inactive_prim_sight),
	gsSPDisplayList(sight_switch_inactive_Plane_002_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_sight_switch_inactive_prim_sight),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


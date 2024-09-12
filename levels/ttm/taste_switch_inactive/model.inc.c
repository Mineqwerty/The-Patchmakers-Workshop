Vtx taste_switch_inactive_Plane_017_mesh_layer_1_vtx_cull[8] = {
	{{ {-195, -593, 193}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-195, 20, 193}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-195, 20, -258}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-195, -593, -258}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {306, -593, 193}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {306, 20, 193}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {306, 20, -258}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {306, -593, -258}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx taste_switch_inactive_Plane_017_mesh_layer_1_vtx_0[12] = {
	{{ {165, 0, -167}, 0, {680, 440}, {121, 22, 25, 255} }},
	{{ {-195, 0, -167}, 0, {824, 440}, {121, 22, 25, 255} }},
	{{ {-195, 20, -167}, 0, {824, 440}, {121, 22, 25, 255} }},
	{{ {-195, 0, 193}, 0, {824, 296}, {121, 22, 25, 255} }},
	{{ {165, 0, 193}, 0, {680, 296}, {121, 22, 25, 255} }},
	{{ {165, 20, -167}, 0, {680, 440}, {121, 22, 25, 255} }},
	{{ {-161, 20, -132}, 0, {810, 426}, {121, 22, 25, 255} }},
	{{ {-161, 20, 158}, 0, {810, 310}, {121, 22, 25, 255} }},
	{{ {-195, 20, 193}, 0, {824, 296}, {121, 22, 25, 255} }},
	{{ {165, 20, 193}, 0, {680, 296}, {121, 22, 25, 255} }},
	{{ {130, 20, -132}, 0, {694, 426}, {121, 22, 25, 255} }},
	{{ {130, 20, 158}, 0, {694, 310}, {121, 22, 25, 255} }},
};

Gfx taste_switch_inactive_Plane_017_mesh_layer_1_tri_0[] = {
	gsSPVertex(taste_switch_inactive_Plane_017_mesh_layer_1_vtx_0 + 0, 12, 0),
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

Vtx taste_switch_inactive_Plane_017_mesh_layer_1_vtx_1[4] = {
	{{ {130, 20, -132}, 0, {694, 426}, {121, 22, 25, 255} }},
	{{ {-161, 20, -132}, 0, {810, 426}, {121, 22, 25, 255} }},
	{{ {-161, 20, 158}, 0, {810, 310}, {121, 22, 25, 255} }},
	{{ {130, 20, 158}, 0, {694, 310}, {121, 22, 25, 255} }},
};

Gfx taste_switch_inactive_Plane_017_mesh_layer_1_tri_1[] = {
	gsSPVertex(taste_switch_inactive_Plane_017_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_taste_switch_inactive_primwhite_001[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_taste_switch_inactive_primwhite_001[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_taste_switch_inactive_prim_sight[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 164, 163, 193, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_taste_switch_inactive_prim_sight[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx taste_switch_inactive_Plane_017_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(taste_switch_inactive_Plane_017_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_taste_switch_inactive_primwhite_001),
	gsSPDisplayList(taste_switch_inactive_Plane_017_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_taste_switch_inactive_primwhite_001),
	gsSPDisplayList(mat_taste_switch_inactive_prim_sight),
	gsSPDisplayList(taste_switch_inactive_Plane_017_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_taste_switch_inactive_prim_sight),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


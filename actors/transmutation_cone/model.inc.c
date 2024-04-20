Vtx transmutation_cone_Circle_003_mesh_layer_5_vtx_0[9] = {
	{{ {308, 0, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {218, 218, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {0, 308, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {0, 0, -50}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {218, -218, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {0, -308, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {-308, 0, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {-218, 218, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
	{{ {-218, -218, 507}, 0, {-16, 1008}, {255, 255, 255, 255} }},
};

Gfx transmutation_cone_Circle_003_mesh_layer_5_tri_0[] = {
	gsSPVertex(transmutation_cone_Circle_003_mesh_layer_5_vtx_0 + 0, 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 4, 0, 0),
	gsSP1Triangle(6, 5, 0, 0),
	gsSP1Triangle(0, 2, 6, 0),
	gsSP1Triangle(2, 7, 6, 0),
	gsSP1Triangle(2, 3, 7, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(7, 3, 6, 0),
	gsSP1Triangle(6, 3, 8, 0),
	gsSP1Triangle(8, 3, 5, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(6, 8, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_transmutation_cone_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(NOISE, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 212, 126, 5, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_transmutation_cone_f3dlite_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx transmutation_cone_Circle_003_mesh_layer_5[] = {
	gsSPDisplayList(mat_transmutation_cone_f3dlite_material),
	gsSPDisplayList(transmutation_cone_Circle_003_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_transmutation_cone_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


Vtx d8_shadow_Circle_007_mesh_layer_6_vtx_0[16] = {
	{{ {-73, 0, -73}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {0, 0, -176}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {-124, 0, -124}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {0, 0, -103}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {-103, 0, 0}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {-176, 0, 0}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {-73, 0, 73}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {-124, 0, 124}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {0, 0, 103}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {0, 0, 176}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {73, 0, 73}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {124, 0, 124}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {103, 0, 0}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {176, 0, 0}, 0, {-16, 1008}, {255, 255, 255, 0} }},
	{{ {73, 0, -73}, 0, {-16, 1008}, {255, 255, 255, 170} }},
	{{ {124, 0, -124}, 0, {-16, 1008}, {255, 255, 255, 0} }},
};

Gfx d8_shadow_Circle_007_mesh_layer_6_tri_0[] = {
	gsSPVertex(d8_shadow_Circle_007_mesh_layer_6_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(3, 0, 4, 0),
	gsSP1Triangle(4, 0, 2, 0),
	gsSP1Triangle(4, 2, 5, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 6, 7, 0),
	gsSP1Triangle(8, 7, 9, 0),
	gsSP1Triangle(10, 8, 9, 0),
	gsSP1Triangle(10, 9, 11, 0),
	gsSP1Triangle(12, 10, 11, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(14, 12, 13, 0),
	gsSP1Triangle(14, 13, 15, 0),
	gsSP1Triangle(3, 14, 15, 0),
	gsSP1Triangle(3, 15, 1, 0),
	gsSP1Triangle(12, 14, 3, 0),
	gsSP1Triangle(8, 12, 3, 0),
	gsSP1Triangle(3, 4, 8, 0),
	gsSP1Triangle(4, 6, 8, 0),
	gsSP1Triangle(8, 10, 12, 0),
	gsSPEndDisplayList(),
};


Gfx mat_d8_shadow_f3dlite_material[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, SHADE, 0, ENVIRONMENT, 0, 0, 0, 0, PRIMITIVE, SHADE, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 0, 0, 0, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_d8_shadow_f3dlite_material[] = {
	gsSPSetGeometryMode(G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx d8_shadow_Circle_007_mesh_layer_6[] = {
	gsSPDisplayList(mat_d8_shadow_f3dlite_material),
	gsSPDisplayList(d8_shadow_Circle_007_mesh_layer_6_tri_0),
	gsSPDisplayList(mat_revert_d8_shadow_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


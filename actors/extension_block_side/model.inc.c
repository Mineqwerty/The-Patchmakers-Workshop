Vtx extension_block_side_Cube_002_mesh_layer_1_vtx_0[14] = {
	{{ {-100, -100, -13}, 0, {1517, 2028}, {255, 255, 255, 255} }},
	{{ {-100, -100, 187}, 0, {1517, -14}, {255, 255, 255, 255} }},
	{{ {-100, 100, 187}, 0, {1006, -14}, {255, 255, 255, 255} }},
	{{ {-100, 100, -13}, 0, {1006, 2028}, {255, 255, 255, 255} }},
	{{ {100, 100, 187}, 0, {496, -14}, {255, 255, 255, 255} }},
	{{ {100, 100, -13}, 0, {496, 2028}, {255, 255, 255, 255} }},
	{{ {100, -100, 187}, 0, {-14, -14}, {255, 255, 255, 255} }},
	{{ {-100, -100, 187}, 0, {-14, -2055}, {255, 255, 255, 255} }},
	{{ {-100, 100, 187}, 0, {496, -2055}, {255, 255, 255, 255} }},
	{{ {100, -100, -13}, 0, {-14, 2028}, {255, 255, 255, 255} }},
	{{ {-100, -100, 187}, 0, {-525, -14}, {255, 255, 255, 255} }},
	{{ {-100, -100, -13}, 0, {-525, 2028}, {255, 255, 255, 255} }},
	{{ {-100, 100, -13}, 0, {496, 4069}, {255, 255, 255, 255} }},
	{{ {-100, -100, -13}, 0, {-14, 4069}, {255, 255, 255, 255} }},
};

Gfx extension_block_side_Cube_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(extension_block_side_Cube_002_mesh_layer_1_vtx_0 + 0, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(4, 7, 6, 0),
	gsSP1Triangle(4, 8, 7, 0),
	gsSP1Triangle(5, 6, 9, 0),
	gsSP1Triangle(9, 6, 10, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 5, 9, 0),
	gsSP1Triangle(12, 9, 13, 0),
	gsSPEndDisplayList(),
};


Gfx mat_extension_block_side_f3dlite_material[] = {
	gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_extension_block_side_f3dlite_material[] = {
	gsSPSetGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx extension_block_side_Cube_002_mesh_layer_1[] = {
	gsSPDisplayList(extension_block_side_Cube_002_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


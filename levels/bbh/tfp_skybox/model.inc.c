Vtx tfp_skybox_Cube_001_mesh_layer_1_vtx_0[24] = {
	{{ {-175, -178, 171}, 0, {368, 1008}, {127, 0, 0, 255} }},
	{{ {-175, -178, -178}, 0, {368, 752}, {127, 0, 0, 255} }},
	{{ {-175, 170, -178}, 0, {624, 752}, {127, 0, 0, 255} }},
	{{ {-175, 170, 171}, 0, {624, 1008}, {127, 0, 0, 255} }},
	{{ {-175, -178, -178}, 0, {368, 752}, {0, 0, 127, 255} }},
	{{ {174, -178, -178}, 0, {368, 496}, {0, 0, 127, 255} }},
	{{ {174, 170, -178}, 0, {624, 496}, {0, 0, 127, 255} }},
	{{ {-175, 170, -178}, 0, {624, 752}, {0, 0, 127, 255} }},
	{{ {174, -178, -178}, 0, {368, 496}, {129, 0, 0, 255} }},
	{{ {174, -178, 171}, 0, {368, 240}, {129, 0, 0, 255} }},
	{{ {174, 170, 171}, 0, {624, 240}, {129, 0, 0, 255} }},
	{{ {174, 170, -178}, 0, {624, 496}, {129, 0, 0, 255} }},
	{{ {174, -178, 171}, 0, {368, 240}, {0, 0, 129, 255} }},
	{{ {-175, -178, 171}, 0, {368, -16}, {0, 0, 129, 255} }},
	{{ {-175, 170, 171}, 0, {624, -16}, {0, 0, 129, 255} }},
	{{ {174, 170, 171}, 0, {624, 240}, {0, 0, 129, 255} }},
	{{ {-175, -178, -178}, 0, {112, 496}, {0, 127, 0, 255} }},
	{{ {-175, -178, 171}, 0, {112, 240}, {0, 127, 0, 255} }},
	{{ {174, -178, 171}, 0, {368, 240}, {0, 127, 0, 255} }},
	{{ {174, -178, -178}, 0, {368, 496}, {0, 127, 0, 255} }},
	{{ {174, 170, -178}, 0, {624, 496}, {0, 129, 0, 255} }},
	{{ {174, 170, 171}, 0, {624, 240}, {0, 129, 0, 255} }},
	{{ {-175, 170, 171}, 0, {880, 240}, {0, 129, 0, 255} }},
	{{ {-175, 170, -178}, 0, {880, 496}, {0, 129, 0, 255} }},
};

Gfx tfp_skybox_Cube_001_mesh_layer_1_tri_0[] = {
	gsSPVertex(tfp_skybox_Cube_001_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(tfp_skybox_Cube_001_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_tfp_skybox_sky_002_v4_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 162, 184, 255, 255),
	gsSPEndDisplayList(),
};

Gfx tfp_skybox_Cube_001_mesh_layer_1[] = {
	gsSPDisplayList(mat_tfp_skybox_sky_002_v4_001),
	gsSPDisplayList(tfp_skybox_Cube_001_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx tfp_skybox_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


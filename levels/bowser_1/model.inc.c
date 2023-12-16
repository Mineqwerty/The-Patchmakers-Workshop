
Vtx bowser_1_dl_Circle_mesh_layer_1_vtx_cull[8] = {
	{{ {-2997, 1025, 2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-2997, 1025, 2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-2997, 1025, -2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-2997, 1025, -2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {2997, 1025, 2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {2997, 1025, 2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {2997, 1025, -2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {2997, 1025, -2997}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx bowser_1_dl_Circle_mesh_layer_1_vtx_0[16] = {
	{{ {0, 1025, -2997}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-1147, 1025, -2769}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-2119, 1025, -2119}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-2997, 1025, 0}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-2769, 1025, -1147}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {0, 1025, 2997}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-2119, 1025, 2119}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-2769, 1025, 1147}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {-1147, 1025, 2769}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {1147, 1025, 2769}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2119, 1025, 2119}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2997, 1025, 0}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2769, 1025, 1147}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2119, 1025, -2119}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2769, 1025, -1147}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {1147, 1025, -2769}, 0, {-16, 1008}, {0, 127, 0, 255} }},
};

Gfx bowser_1_dl_Circle_mesh_layer_1_tri_0[] = {
	gsSPVertex(bowser_1_dl_Circle_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 0, 3, 5, 0),
	gsSP2Triangles(3, 6, 5, 0, 3, 7, 6, 0),
	gsSP2Triangles(6, 8, 5, 0, 5, 9, 10, 0),
	gsSP2Triangles(5, 10, 11, 0, 10, 12, 11, 0),
	gsSP2Triangles(5, 11, 0, 0, 11, 13, 0, 0),
	gsSP2Triangles(11, 14, 13, 0, 13, 15, 0, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bowser_1_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0x524643ff),
    gsSPLightColor(LIGHT_2, 0x241e1dff),
	gsSPEndDisplayList(),
};

Gfx bowser_1_dl_Circle_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bowser_1_dl_Circle_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bowser_1_dl_f3dlite_material),
	gsSPDisplayList(bowser_1_dl_Circle_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx bowser_1_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


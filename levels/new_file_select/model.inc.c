
Vtx new_file_select_dl_Plane_mesh_layer_1_vtx_cull[8] = {
	{{ {-365, -100, 805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-365, 100, 805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-365, 100, -805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-365, -100, -805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {1244, -100, 805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {1244, 100, 805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {1244, 100, -805}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {1244, -100, -805}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx new_file_select_dl_Plane_mesh_layer_1_vtx_0[28] = {
	{{ {-365, 0, 805}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {1244, 0, 805}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {1244, 0, -805}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-365, 0, -805}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {664, -100, 439}, 0, {368, 1008}, {129, 0, 0, 255} }},
	{{ {664, 100, 439}, 0, {624, 1008}, {129, 0, 0, 255} }},
	{{ {664, 100, -451}, 0, {624, 752}, {129, 0, 0, 255} }},
	{{ {664, -100, -451}, 0, {368, 752}, {129, 0, 0, 255} }},
	{{ {664, -100, -451}, 0, {368, 752}, {0, 0, 129, 255} }},
	{{ {664, 100, -451}, 0, {624, 752}, {0, 0, 129, 255} }},
	{{ {864, 100, -451}, 0, {624, 496}, {0, 0, 129, 255} }},
	{{ {864, -100, -451}, 0, {368, 496}, {0, 0, 129, 255} }},
	{{ {864, -100, -451}, 0, {368, 496}, {127, 0, 0, 255} }},
	{{ {864, 100, -451}, 0, {624, 496}, {127, 0, 0, 255} }},
	{{ {864, 100, 439}, 0, {624, 240}, {127, 0, 0, 255} }},
	{{ {864, -100, 439}, 0, {368, 240}, {127, 0, 0, 255} }},
	{{ {864, -100, 439}, 0, {368, 240}, {0, 0, 127, 255} }},
	{{ {864, 100, 439}, 0, {624, 240}, {0, 0, 127, 255} }},
	{{ {664, 100, 439}, 0, {624, -16}, {0, 0, 127, 255} }},
	{{ {664, -100, 439}, 0, {368, -16}, {0, 0, 127, 255} }},
	{{ {664, -100, -451}, 0, {112, 496}, {0, 129, 0, 255} }},
	{{ {864, -100, -451}, 0, {368, 496}, {0, 129, 0, 255} }},
	{{ {864, -100, 439}, 0, {368, 240}, {0, 129, 0, 255} }},
	{{ {664, -100, 439}, 0, {112, 240}, {0, 129, 0, 255} }},
	{{ {864, 100, -451}, 0, {624, 496}, {0, 127, 0, 255} }},
	{{ {664, 100, -451}, 0, {880, 496}, {0, 127, 0, 255} }},
	{{ {664, 100, 439}, 0, {880, 240}, {0, 127, 0, 255} }},
	{{ {864, 100, 439}, 0, {624, 240}, {0, 127, 0, 255} }},
};

Gfx new_file_select_dl_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(new_file_select_dl_Plane_mesh_layer_1_vtx_0 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSPEndDisplayList(),
};

Gfx mat_new_file_select_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx new_file_select_dl_Plane_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(new_file_select_dl_Plane_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_new_file_select_dl_f3dlite_material),
	gsSPDisplayList(new_file_select_dl_Plane_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx new_file_select_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


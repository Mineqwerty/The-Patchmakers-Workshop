

Vtx shadow_spike_Plane_005_mesh_layer_1_vtx_cull[8] = {
	{{ {-132, 0, 132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, 790, 132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, 790, -132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, 0, -132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {132, 0, 132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {132, 790, 132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {132, 790, -132}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {132, 0, -132}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx shadow_spike_Plane_005_mesh_layer_1_vtx_0[12] = {
	{{ {-100, 0, 100}, 0, {-16, 1008}, {0, 17, 126, 255} }},
	{{ {100, 0, 100}, 0, {1008, 1008}, {0, 17, 126, 255} }},
	{{ {0, 738, 0}, 0, {496, 496}, {0, 17, 126, 255} }},
	{{ {100, 0, 100}, 0, {1008, 1008}, {126, 17, 0, 255} }},
	{{ {100, 0, -100}, 0, {1008, -16}, {126, 17, 0, 255} }},
	{{ {0, 738, 0}, 0, {496, 496}, {126, 17, 0, 255} }},
	{{ {100, 0, -100}, 0, {1008, -16}, {0, 17, 130, 255} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 17, 130, 255} }},
	{{ {0, 738, 0}, 0, {496, 496}, {0, 17, 130, 255} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {130, 17, 0, 255} }},
	{{ {-100, 0, 100}, 0, {-16, 1008}, {130, 17, 0, 255} }},
	{{ {0, 738, 0}, 0, {496, 496}, {130, 17, 0, 255} }},
};

Gfx shadow_spike_Plane_005_mesh_layer_1_tri_0[] = {
	gsSPVertex(shadow_spike_Plane_005_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx shadow_spike_Plane_005_mesh_layer_1_vtx_1[12] = {
	{{ {-132, 0, 132}, 0, {-181, 1011}, {0, 235, 131, 255} }},
	{{ {0, 790, 0}, 0, {496, 461}, {0, 235, 131, 255} }},
	{{ {132, 0, 132}, 0, {1173, 1011}, {0, 235, 131, 255} }},
	{{ {132, 0, 132}, 0, {1011, 1173}, {131, 235, 0, 255} }},
	{{ {0, 790, 0}, 0, {461, 496}, {131, 235, 0, 255} }},
	{{ {132, 0, -132}, 0, {1011, -181}, {131, 235, 0, 255} }},
	{{ {132, 0, -132}, 0, {1173, -19}, {0, 235, 125, 255} }},
	{{ {0, 790, 0}, 0, {496, 531}, {0, 235, 125, 255} }},
	{{ {-132, 0, -132}, 0, {-181, -19}, {0, 235, 125, 255} }},
	{{ {-132, 0, -132}, 0, {-19, -181}, {125, 235, 0, 255} }},
	{{ {0, 790, 0}, 0, {531, 496}, {125, 235, 0, 255} }},
	{{ {-132, 0, 132}, 0, {-19, 1173}, {125, 235, 0, 255} }},
};

Gfx shadow_spike_Plane_005_mesh_layer_1_tri_1[] = {
	gsSPVertex(shadow_spike_Plane_005_mesh_layer_1_vtx_1 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_shadow_spike_f3dlite_material_004[] = {
    gsSPLightColor(LIGHT_1, 0xff),
    gsSPLightColor(LIGHT_2, 0xff),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_shadow_spike_f3dlite_material_004[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_shadow_spike_f3dlite_material[] = {
    gsSPLightColor(LIGHT_1, 0xaa0002ff),
    gsSPLightColor(LIGHT_2, 0x530000ff),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_shadow_spike_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx shadow_spike_Plane_005_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(shadow_spike_Plane_005_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_shadow_spike_f3dlite_material_004),
	gsSPDisplayList(shadow_spike_Plane_005_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_shadow_spike_f3dlite_material_004),
	gsSPDisplayList(mat_shadow_spike_f3dlite_material),
	gsSPDisplayList(shadow_spike_Plane_005_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_shadow_spike_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


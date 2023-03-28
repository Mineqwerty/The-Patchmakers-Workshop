Vtx floating_plane_Plane_002_mesh_layer_1_vtx_0[4] = {
	{{ {-81, 0, 81}, 0, {80, 912}, {0, 127, 0, 255} }},
	{{ {81, 0, 81}, 0, {912, 912}, {0, 127, 0, 255} }},
	{{ {81, 0, -81}, 0, {912, 80}, {0, 127, 0, 255} }},
	{{ {-81, 0, -81}, 0, {80, 80}, {0, 127, 0, 255} }},
};

Gfx floating_plane_Plane_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(floating_plane_Plane_002_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx floating_plane_Plane_002_mesh_layer_1_vtx_1[8] = {
	{{ {-81, 0, 81}, 0, {80, 912}, {0, 127, 0, 255} }},
	{{ {-81, 0, -81}, 0, {80, 80}, {0, 127, 0, 255} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {100, 0, -100}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {81, 0, -81}, 0, {912, 80}, {0, 127, 0, 255} }},
	{{ {100, 0, 100}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {81, 0, 81}, 0, {912, 912}, {0, 127, 0, 255} }},
	{{ {-100, 0, 100}, 0, {-16, 1008}, {0, 127, 0, 255} }},
};

Gfx floating_plane_Plane_002_mesh_layer_1_tri_1[] = {
	gsSPVertex(floating_plane_Plane_002_mesh_layer_1_vtx_1 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(6, 0, 7, 0),
	gsSP1Triangle(0, 2, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_floating_plane_f3dlite_material_006[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, PRIMITIVE, 0, 0, 0, 0, 1, PRIMITIVE, 0, PRIMITIVE, 0, 0, 0, 0, 1),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_floating_plane_f3dlite_material_006[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_floating_plane_f3dlite_material_005[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_floating_plane_f3dlite_material_005[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx floating_plane_Plane_002_mesh_layer_1[] = {
	gsSPDisplayList(mat_floating_plane_f3dlite_material_006),
	gsSPDisplayList(floating_plane_Plane_002_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_floating_plane_f3dlite_material_006),
	gsSPDisplayList(mat_floating_plane_f3dlite_material_005),
	gsSPDisplayList(floating_plane_Plane_002_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_floating_plane_f3dlite_material_005),
	gsSPEndDisplayList(),
};

Gfx floating_plane_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


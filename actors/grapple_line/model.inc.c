Lights1 grapple_line_f3d_material_004_lights = gdSPDefLights1(
	0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Vtx grapple_line_Plane_002_mesh_layer_1_vtx_0[12] = {
	{{{-3, -1, -7},0, {-16, 1008},{0xA9, 0xCE, 0xB2, 0xFF}}},
	{{{-3, 2, -7},0, {-16, 1008},{0xA9, 0x32, 0xB2, 0xFF}}},
	{{{0, 3, -7},0, {-16, 1008},{0x0, 0x65, 0xB2, 0xFF}}},
	{{{-3, -1, 0},0, {-16, 1008},{0xA9, 0xCE, 0x4E, 0xFF}}},
	{{{0, -3, 0},0, {-16, 1008},{0x0, 0x9B, 0x4E, 0xFF}}},
	{{{0, -3, -7},0, {-16, 1008},{0x0, 0x9B, 0xB2, 0xFF}}},
	{{{3, -1, -7},0, {-16, 1008},{0x57, 0xCE, 0xB2, 0xFF}}},
	{{{3, 2, -7},0, {-16, 1008},{0x57, 0x32, 0xB2, 0xFF}}},
	{{{0, 3, 0},0, {-16, 1008},{0x0, 0x65, 0x4E, 0xFF}}},
	{{{-3, 2, 0},0, {-16, 1008},{0xA9, 0x32, 0x4E, 0xFF}}},
	{{{3, -1, 0},0, {-16, 1008},{0x57, 0xCE, 0x4E, 0xFF}}},
	{{{3, 2, 0},0, {-16, 1008},{0x57, 0x32, 0x4E, 0xFF}}},
};

Gfx grapple_line_Plane_002_mesh_layer_1_tri_0[] = {
	gsSPVertex(grapple_line_Plane_002_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(0, 4, 3, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(6, 5, 0, 0),
	gsSP1Triangle(2, 6, 0, 0),
	gsSP1Triangle(2, 7, 6, 0),
	gsSP1Triangle(7, 2, 8, 0),
	gsSP1Triangle(2, 9, 8, 0),
	gsSP1Triangle(2, 1, 9, 0),
	gsSP1Triangle(1, 3, 9, 0),
	gsSP1Triangle(8, 9, 3, 0),
	gsSP1Triangle(3, 10, 8, 0),
	gsSP1Triangle(3, 4, 10, 0),
	gsSP1Triangle(5, 10, 4, 0),
	gsSP1Triangle(5, 6, 10, 0),
	gsSP1Triangle(6, 11, 10, 0),
	gsSP1Triangle(6, 7, 11, 0),
	gsSP1Triangle(7, 8, 11, 0),
	gsSP1Triangle(10, 11, 8, 0),
	gsSPEndDisplayList(),
};


Gfx mat_grapple_line_f3d_material_004[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(grapple_line_f3d_material_004_lights),
	gsSPEndDisplayList(),
};

Gfx grapple_line_Plane_002_mesh_layer_1[] = {
	gsSPDisplayList(mat_grapple_line_f3d_material_004),
	gsSPDisplayList(grapple_line_Plane_002_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx grapple_line_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


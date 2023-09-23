
Vtx wing_surface_Plane_013_mesh_layer_1_vtx_0[28] = {
	{{ {5713, 2064, 4334}, 0, {-16, 1008}, {237, 126, 0, 255} }},
	{{ {7118, 2285, 4500}, 0, {1008, 1008}, {237, 126, 0, 255} }},
	{{ {7118, 2285, 3095}, 0, {1008, -16}, {237, 126, 0, 255} }},
	{{ {5713, 2064, 3107}, 0, {-16, -16}, {237, 126, 0, 255} }},
	{{ {7118, 2285, 3095}, 0, {1008, -16}, {238, 126, 7, 255} }},
	{{ {7118, 2285, 4500}, 0, {1008, 1008}, {238, 126, 7, 255} }},
	{{ {10486, 2727, 4066}, 0, {1008, 1008}, {238, 126, 7, 255} }},
	{{ {9182, 2727, 2235}, 0, {1008, -16}, {238, 126, 7, 255} }},
	{{ {9182, 2727, 2235}, 0, {1008, -16}, {248, 126, 12, 255} }},
	{{ {10486, 2727, 4066}, 0, {1008, 1008}, {248, 126, 12, 255} }},
	{{ {12809, 3340, -1580}, 0, {1008, 1008}, {248, 126, 12, 255} }},
	{{ {10613, 3340, -2060}, 0, {1008, -16}, {248, 126, 12, 255} }},
	{{ {10613, 3340, -2060}, 0, {1008, -16}, {255, 126, 14, 255} }},
	{{ {12809, 3340, -1580}, 0, {1008, 1008}, {255, 126, 14, 255} }},
	{{ {12590, 3935, -7087}, 0, {1008, 1008}, {255, 126, 14, 255} }},
	{{ {10345, 3935, -6980}, 0, {1008, -16}, {255, 126, 14, 255} }},
	{{ {10345, 3935, -6980}, 0, {1008, -16}, {4, 127, 9, 255} }},
	{{ {12590, 3935, -7087}, 0, {1008, 1008}, {4, 127, 9, 255} }},
	{{ {9373, 4306, -11422}, 0, {1008, 1008}, {4, 127, 9, 255} }},
	{{ {8500, 4306, -10163}, 0, {1008, -16}, {4, 127, 9, 255} }},
	{{ {8500, 4306, -10163}, 0, {1008, -16}, {7, 127, 2, 255} }},
	{{ {9373, 4306, -11422}, 0, {1008, 1008}, {7, 127, 2, 255} }},
	{{ {3279, 4662, -12522}, 0, {1008, 1008}, {7, 127, 2, 255} }},
	{{ {3416, 4662, -10996}, 0, {1008, -16}, {7, 127, 2, 255} }},
	{{ {3416, 4662, -10996}, 0, {1008, -16}, {255, 127, 0, 255} }},
	{{ {3279, 4662, -12522}, 0, {1008, 1008}, {255, 127, 0, 255} }},
	{{ {-46, 4624, -12226}, 0, {1008, 1008}, {255, 127, 0, 255} }},
	{{ {26, 4624, -11423}, 0, {1008, -16}, {255, 127, 0, 255} }},
};

Gfx wing_surface_Plane_013_mesh_layer_1_tri_0[] = {
	gsSPVertex(wing_surface_Plane_013_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(wing_surface_Plane_013_mesh_layer_1_vtx_0 + 16, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_wing_surface_wing_surface[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx wing_surface_Plane_013_mesh_layer_1[] = {
	gsSPDisplayList(mat_wing_surface_wing_surface),
	gsSPDisplayList(wing_surface_Plane_013_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx wing_surface_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


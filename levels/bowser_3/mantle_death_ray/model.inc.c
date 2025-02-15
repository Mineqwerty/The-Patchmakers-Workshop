Vtx mantle_death_ray_Circle_003_mesh_layer_5_vtx_cull[8] = {
	{{ {-87, -50, 8753}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-87, 100, 8753}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-87, 100, 0}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-87, -50, 0}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {87, -50, 8753}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {87, 100, 8753}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {87, 100, 0}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {87, -50, 0}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx mantle_death_ray_Circle_003_mesh_layer_5_vtx_0[24] = {
	{{ {-87, -50, 0}, 0, {-16, 1008}, {0, 0, 129, 235} }},
	{{ {0, 100, 0}, 0, {-16, 1008}, {0, 0, 129, 235} }},
	{{ {87, -50, 0}, 0, {-16, 1008}, {0, 0, 129, 235} }},
	{{ {-87, -50, 8753}, 0, {-16, 1008}, {0, 0, 127, 56} }},
	{{ {87, -50, 8753}, 0, {-16, 1008}, {0, 0, 127, 7} }},
	{{ {0, 100, 8753}, 0, {-16, 1008}, {0, 0, 127, 5} }},
	{{ {87, -50, 4376}, 0, {-16, 1008}, {110, 63, 0, 76} }},
	{{ {0, 100, 8753}, 0, {-16, 1008}, {110, 63, 0, 5} }},
	{{ {87, -50, 8753}, 0, {-16, 1008}, {110, 63, 0, 7} }},
	{{ {0, 100, 4376}, 0, {-16, 1008}, {110, 63, 0, 76} }},
	{{ {87, -50, 0}, 0, {-16, 1008}, {110, 63, 0, 235} }},
	{{ {0, 100, 0}, 0, {-16, 1008}, {110, 63, 0, 235} }},
	{{ {-87, -50, 4376}, 0, {-16, 1008}, {0, 129, 0, 76} }},
	{{ {87, -50, 8753}, 0, {-16, 1008}, {0, 129, 0, 7} }},
	{{ {-87, -50, 8753}, 0, {-16, 1008}, {0, 129, 0, 56} }},
	{{ {87, -50, 4376}, 0, {-16, 1008}, {0, 129, 0, 76} }},
	{{ {-87, -50, 0}, 0, {-16, 1008}, {0, 129, 0, 235} }},
	{{ {87, -50, 0}, 0, {-16, 1008}, {0, 129, 0, 235} }},
	{{ {0, 100, 4376}, 0, {-16, 1008}, {146, 63, 0, 76} }},
	{{ {-87, -50, 8753}, 0, {-16, 1008}, {146, 63, 0, 56} }},
	{{ {0, 100, 8753}, 0, {-16, 1008}, {146, 63, 0, 5} }},
	{{ {-87, -50, 4376}, 0, {-16, 1008}, {146, 63, 0, 76} }},
	{{ {0, 100, 0}, 0, {-16, 1008}, {146, 63, 0, 235} }},
	{{ {-87, -50, 0}, 0, {-16, 1008}, {146, 63, 0, 235} }},
};

Gfx mantle_death_ray_Circle_003_mesh_layer_5_tri_0[] = {
	gsSPVertex(mantle_death_ray_Circle_003_mesh_layer_5_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 9, 7, 0),
	gsSP2Triangles(10, 9, 6, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 15, 12, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
	gsSP2Triangles(22, 21, 18, 0, 22, 23, 21, 0),
	gsSPEndDisplayList(),
};


Gfx mat_mantle_death_ray_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 1, ENVIRONMENT, SHADE, ENVIRONMENT, 0, 0, 0, PRIMITIVE, 1, ENVIRONMENT, SHADE, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mantle_death_ray_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mantle_death_ray_Circle_003_mesh_layer_5[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(mantle_death_ray_Circle_003_mesh_layer_5_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_mantle_death_ray_f3dlite_material),
	gsSPDisplayList(mantle_death_ray_Circle_003_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_mantle_death_ray_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


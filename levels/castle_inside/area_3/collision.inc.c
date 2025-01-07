Gfx castle_inside_area_3_collision_f3dlite_material_014_layer_1[] = {
    gsSPLightColor(LIGHT_1, 0x494949ff),
    gsSPLightColor(LIGHT_2, 0x202020ff),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx castle_inside_area_3_collision_mat_revert_castle_inside_dl_f3dlite_material_014[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

const Gfx* castle_inside_area_3_collision_materials[] = {
	&castle_inside_area_3_collision_f3dlite_material_014_layer_1,
	&castle_inside_area_3_collision_mat_revert_castle_inside_dl_f3dlite_material_014,
};

const Collision castle_inside_area_3_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-5078, 1782, 2464),
	COL_VERTEX(5078, 1782, 2464),
	COL_VERTEX(5078, 1782, -2464),
	COL_VERTEX(-5078, 1782, -2464),
	COL_TRI_MAT_INIT(SURFACE_DEFAULT, 0, 1, 1, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

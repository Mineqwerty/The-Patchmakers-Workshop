Gfx new_file_select_area_2_collision_f3dlite_material_layer_1[] = {
    gsSPLightColor(LIGHT_1, 0xff),
    gsSPLightColor(LIGHT_2, 0xff),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx new_file_select_area_2_collision_mat_revert_new_file_select_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

const Gfx* new_file_select_area_2_collision_materials[] = {
	&new_file_select_area_2_collision_f3dlite_material_layer_1,
	&new_file_select_area_2_collision_mat_revert_new_file_select_dl_f3dlite_material,
};

const Collision new_file_select_area_2_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-464, -647, 464),
	COL_VERTEX(464, -647, 464),
	COL_VERTEX(464, -647, -464),
	COL_VERTEX(-464, -647, -464),
	COL_TRI_MAT_INIT(SURFACE_DEFAULT, 0, 1, 1, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

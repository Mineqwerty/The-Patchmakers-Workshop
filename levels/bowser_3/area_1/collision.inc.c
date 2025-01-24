Gfx bowser_3_area_1_collision_f3dlite_material_013_layer_1[] = {
	gsSPGeometryMode(G_LIGHTING, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bowser_3_dl_coldconc_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 34),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, bowser_3_dl_coldconc_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx bowser_3_area_1_collision_mat_revert_bowser_3_dl_f3dlite_material_013[] = {
	gsSPGeometryMode(0, G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

const Gfx* bowser_3_area_1_collision_materials[] = {
	&bowser_3_area_1_collision_f3dlite_material_013_layer_1,
	&bowser_3_area_1_collision_mat_revert_bowser_3_dl_f3dlite_material_013,
};

const Collision bowser_3_area_1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(6),
	COL_VERTEX(-3214, 1199, 2268),
	COL_VERTEX(2268, 1199, 2268),
	COL_VERTEX(2268, 1199, -2268),
	COL_VERTEX(-3214, 1199, -2268),
	COL_VERTEX(2268, 4102, 2268),
	COL_VERTEX(2268, 4102, -2268),
	COL_TRI_MAT_INIT(SURFACE_DEFAULT, 0, 1, 1, 4),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(2, 1, 4),
	COL_TRI(2, 4, 5),
	COL_TRI_STOP(),
	COL_END()
};

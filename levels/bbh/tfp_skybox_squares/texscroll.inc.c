void scroll_gfx_mat_tfp_skybox_squares_f3dlite_material_004() {
	Gfx *mat = segmented_to_virtual(mat_tfp_skybox_squares_f3dlite_material_004);
	static int interval_tex_tfp_skybox_squares_f3dlite_material_004 = 11;
	static int cur_interval_tex_tfp_skybox_squares_f3dlite_material_004 = 11;

	if (--cur_interval_tex_tfp_skybox_squares_f3dlite_material_004 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 8));
		shift_t(mat, 14, PACK_TILESIZE(0, 16));
		cur_interval_tex_tfp_skybox_squares_f3dlite_material_004 = interval_tex_tfp_skybox_squares_f3dlite_material_004;
	}

};

void scroll_gfx_mat_tfp_skybox_squares_f3dlite_material_005() {
	Gfx *mat = segmented_to_virtual(mat_tfp_skybox_squares_f3dlite_material_005);
	static int interval_tex_tfp_skybox_squares_f3dlite_material_005 = 8;
	static int cur_interval_tex_tfp_skybox_squares_f3dlite_material_005 = 8;

	if (--cur_interval_tex_tfp_skybox_squares_f3dlite_material_005 <= 0) {
		shift_s(mat, 14, PACK_TILESIZE(0, 24));
		shift_t(mat, 14, PACK_TILESIZE(0, 16));
		cur_interval_tex_tfp_skybox_squares_f3dlite_material_005 = interval_tex_tfp_skybox_squares_f3dlite_material_005;
	}

};

void scroll_bbh_level_geo_tfp_skybox_squares() {
	scroll_gfx_mat_tfp_skybox_squares_f3dlite_material_004();
	scroll_gfx_mat_tfp_skybox_squares_f3dlite_material_005();
};

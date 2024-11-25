void scroll_gfx_mat_bbh_dl_tfp_tiles_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bbh_dl_tfp_tiles_layer1);
	static int interval_tex_bbh_dl_tfp_tiles_layer1 = 3;
	static int cur_interval_tex_bbh_dl_tfp_tiles_layer1 = 3;

	if (--cur_interval_tex_bbh_dl_tfp_tiles_layer1 <= 0) {
		shift_s(mat, 12, PACK_TILESIZE(0, 2));
		shift_t(mat, 12, PACK_TILESIZE(0, 1));
		cur_interval_tex_bbh_dl_tfp_tiles_layer1 = interval_tex_bbh_dl_tfp_tiles_layer1;
	}

};

void scroll_bbh() {
	scroll_gfx_mat_bbh_dl_tfp_tiles_layer1();
};

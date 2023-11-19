void scroll_gfx_mat_hmc_dl_cavewater_001_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_cavewater_001_layer5_area1);


	shift_t(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_hmc() {
	scroll_gfx_mat_hmc_dl_cavewater_001_layer5_area1();
};

void scroll_gfx_mat_hmc_dl_cavewater_001_layer6_area1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_cavewater_001_layer6_area1);


	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_hmc_dl_cozieswater_001_layer5_area3() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_cozieswater_001_layer5_area3);


	shift_t(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 19, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_hmc_dl_cozieswater_002_layer5_area3() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_cozieswater_002_layer5_area3);


	shift_t(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 19, PACK_TILESIZE(0, 3));

};

void scroll_hmc() {
	scroll_gfx_mat_hmc_dl_cavewater_001_layer6_area1();
	scroll_gfx_mat_hmc_dl_cozieswater_001_layer5_area3();
	scroll_gfx_mat_hmc_dl_cozieswater_002_layer5_area3();
};

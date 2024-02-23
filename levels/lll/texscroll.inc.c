void scroll_gfx_mat_lll_dl_spooky_tiles_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_spooky_tiles_layer1);

	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_lll_dl_spectral_sucky_layer5() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_spectral_sucky_layer5);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 2));
	shift_s(mat, 16, PACK_TILESIZE(0, 2));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_lll() {
	scroll_gfx_mat_lll_dl_spooky_tiles_layer1();
	scroll_gfx_mat_lll_dl_spectral_sucky_layer5();
};

void scroll_gfx_mat_moving_spectral_octagon_spectral_sucky_layer5() {
	Gfx *mat = segmented_to_virtual(mat_moving_spectral_octagon_spectral_sucky_layer5);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 2));
	shift_s(mat, 16, PACK_TILESIZE(0, 2));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_lll_level_geo_moving_spectral_octagon() {
	scroll_gfx_mat_moving_spectral_octagon_spectral_sucky_layer5();
};

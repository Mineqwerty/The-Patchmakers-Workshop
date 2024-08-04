void scroll_gfx_mat_jellyfish_cozieswater_003_layer5() {
	Gfx *mat = segmented_to_virtual(mat_jellyfish_cozieswater_003_layer5);


	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 3));

};

void scroll_sl_level_geo_jellyfish() {
	scroll_gfx_mat_jellyfish_cozieswater_003_layer5();
};

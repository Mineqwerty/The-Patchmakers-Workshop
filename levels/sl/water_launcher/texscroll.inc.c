void scroll_gfx_mat_water_launcher_cozieswater_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_water_launcher_cozieswater_001_layer5);


	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 3));

};

void scroll_sl_level_geo_water_launcher() {
	scroll_gfx_mat_water_launcher_cozieswater_001_layer5();
};

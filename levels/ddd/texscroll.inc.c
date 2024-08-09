void scroll_gfx_mat_ddd_dl_cavewater_001_layer6_area1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_cavewater_001_layer6_area1);


	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ddd_dl_housewater_layer6_area2() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_housewater_layer6_area2);


	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));

};

void scroll_ddd() {
	scroll_gfx_mat_ddd_dl_cavewater_001_layer6_area1();
	scroll_gfx_mat_ddd_dl_housewater_layer6_area2();
};

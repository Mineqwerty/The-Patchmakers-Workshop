void scroll_sts_mat_forcefield_no_inside_cozieswater_002_layer5() {
	Gfx *mat = segmented_to_virtual(mat_forcefield_no_inside_cozieswater_002_layer5);
	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 3));
};

void scroll_jrb_level_geo_forcefield_no_inside() {
	scroll_sts_mat_forcefield_no_inside_cozieswater_002_layer5();
}

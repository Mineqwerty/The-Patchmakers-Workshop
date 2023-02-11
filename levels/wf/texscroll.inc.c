void scroll_sts_mat_wf_dl_cozieswater_001_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_cozieswater_001_layer5_area1);
	shift_t(mat, 16, PACK_TILESIZE(0, 2));
	shift_s(mat, 24, PACK_TILESIZE(0, 1));
	shift_t(mat, 24, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_wf_dl_cozieswater_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_cozieswater_layer5);
	shift_t(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 3));
};

void scroll_wf() {
	scroll_sts_mat_wf_dl_cozieswater_001_layer5_area1();
	scroll_sts_mat_wf_dl_cozieswater_layer5();
}

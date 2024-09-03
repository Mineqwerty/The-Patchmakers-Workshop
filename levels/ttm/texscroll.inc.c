void scroll_gfx_mat_ttm_dl_scrollma() {
	Gfx *mat = segmented_to_virtual(mat_ttm_dl_scrollma);

	shift_s(mat, 12, PACK_TILESIZE(0, 1));

};

void scroll_ttm() {
	scroll_gfx_mat_ttm_dl_scrollma();
};

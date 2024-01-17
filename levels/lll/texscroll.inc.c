void scroll_gfx_mat_lll_dl_spooky_tiles_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_spooky_tiles_layer1);

	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_lll() {
	scroll_gfx_mat_lll_dl_spooky_tiles_layer1();
};

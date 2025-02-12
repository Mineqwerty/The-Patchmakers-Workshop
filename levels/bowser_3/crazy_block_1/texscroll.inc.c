void scroll_gfx_mat_crazy_block_1_scarydark_layer1() {
	Gfx *mat = segmented_to_virtual(mat_crazy_block_1_scarydark_layer1);

	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 1));

};

void scroll_bowser_3_level_geo_crazy_block_1() {
	scroll_gfx_mat_crazy_block_1_scarydark_layer1();
};

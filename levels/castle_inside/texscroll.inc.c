void scroll_gfx_mat_castle_inside_dl_bubblewall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_castle_inside_dl_bubblewall_layer1);


	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 2));

};

void scroll_castle_inside() {
	scroll_gfx_mat_castle_inside_dl_bubblewall_layer1();
};

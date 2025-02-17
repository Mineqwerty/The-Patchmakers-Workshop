void scroll_gfx_mat_bits_dl_f3dlite_material_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3dlite_material_001_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 2));
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_bits() {
	scroll_gfx_mat_bits_dl_f3dlite_material_001_layer1();
};

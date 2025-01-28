void scroll_gfx_mat_bowser_3_dl_f3dlite_material_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bowser_3_dl_f3dlite_material_layer1);

	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 4));

};

void scroll_bowser_3() {
	scroll_gfx_mat_bowser_3_dl_f3dlite_material_layer1();
};

void scroll_gfx_mat_hub_barrier_f3dlite_material_layer5() {
	Gfx *mat = segmented_to_virtual(mat_hub_barrier_f3dlite_material_layer5);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_s(mat, 17, PACK_TILESIZE(0, 2));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_castle_inside_level_geo_hub_barrier() {
	scroll_gfx_mat_hub_barrier_f3dlite_material_layer5();
};

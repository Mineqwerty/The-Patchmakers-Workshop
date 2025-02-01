void scroll_gfx_mat_memory_cloud_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_memory_cloud_f3dlite_material);

	shift_t_down(mat, 13, PACK_TILESIZE(0, 2));

};

void scroll_castle_inside_level_geo_memory_cloud() {
	scroll_gfx_mat_memory_cloud_f3dlite_material();
};

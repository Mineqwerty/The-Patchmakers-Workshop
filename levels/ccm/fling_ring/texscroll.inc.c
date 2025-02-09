void scroll_gfx_mat_fling_ring_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_fling_ring_f3dlite_material);

	shift_t(mat, 9, PACK_TILESIZE(0, 4));

};

void scroll_ccm_level_geo_fling_ring() {
	scroll_gfx_mat_fling_ring_f3dlite_material();
};

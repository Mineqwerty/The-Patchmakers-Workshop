void scroll_gfx_mat_jelly_surround_circle_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_jelly_surround_circle_f3dlite_material);


	shift_s(mat, 12, PACK_TILESIZE(0, 3));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 17, PACK_TILESIZE(0, 3));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 2));

};

void scroll_sl_level_geo_jelly_surround_circle() {
	scroll_gfx_mat_jelly_surround_circle_f3dlite_material();
};

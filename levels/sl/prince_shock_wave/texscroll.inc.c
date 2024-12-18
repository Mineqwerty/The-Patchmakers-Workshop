void scroll_gfx_mat_prince_shock_wave_f3dlite_material_009() {
	Gfx *mat = segmented_to_virtual(mat_prince_shock_wave_f3dlite_material_009);


	shift_s(mat, 13, PACK_TILESIZE(0, 3));
	shift_t(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 3));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 2));

};

void scroll_sl_level_geo_prince_shock_wave() {
	scroll_gfx_mat_prince_shock_wave_f3dlite_material_009();
};

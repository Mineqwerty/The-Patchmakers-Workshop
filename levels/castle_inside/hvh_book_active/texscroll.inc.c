void scroll_gfx_mat_hvh_book_active_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_hvh_book_active_f3dlite_material);
	static int interval_tex_hvh_book_active_f3dlite_material = 2;
	static int cur_interval_tex_hvh_book_active_f3dlite_material = 2;

	if (--cur_interval_tex_hvh_book_active_f3dlite_material <= 0) {
		shift_s(mat, 9, PACK_TILESIZE(0, 1));
		shift_t(mat, 9, PACK_TILESIZE(0, 1));
		cur_interval_tex_hvh_book_active_f3dlite_material = interval_tex_hvh_book_active_f3dlite_material;
	}

};

void scroll_castle_inside_level_geo_hvh_book_active() {
	scroll_gfx_mat_hvh_book_active_f3dlite_material();
};

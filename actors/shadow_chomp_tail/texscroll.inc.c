void scroll_gfx_mat_shadow_chomp_tail_shadowchomp_layer5() {
	Gfx *mat = segmented_to_virtual(mat_shadow_chomp_tail_shadowchomp_layer5);


	shift_s(mat, 13, PACK_TILESIZE(0, 2));
	shift_t(mat, 13, PACK_TILESIZE(0, 4));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 3));

};

void scroll_actor_geo_shadow_chomp_tail() {
	scroll_gfx_mat_shadow_chomp_tail_shadowchomp_layer5();
};

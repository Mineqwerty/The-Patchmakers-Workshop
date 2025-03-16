void scroll_gfx_mat_pm_shadowchomp_open_shadowchomp_layer5() {
	Gfx *mat = segmented_to_virtual(mat_pm_shadowchomp_open_shadowchomp_layer5);


	shift_s(mat, 12, PACK_TILESIZE(0, 2));
	shift_t(mat, 12, PACK_TILESIZE(0, 4));
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 3));

};

void scroll_actor_geo_pm_shadowchomp_open() {
	scroll_gfx_mat_pm_shadowchomp_open_shadowchomp_layer5();
};

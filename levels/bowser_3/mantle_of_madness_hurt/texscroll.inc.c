void scroll_gfx_mat_mantle_of_madness_hurt_butter_layer4() {
	Gfx *mat = segmented_to_virtual(mat_mantle_of_madness_hurt_butter_layer4);


	shift_s(mat, 12, PACK_TILESIZE(0, 2));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_mantle_of_madness_hurt_butter_001_layer4() {
	Gfx *mat = segmented_to_virtual(mat_mantle_of_madness_hurt_butter_001_layer4);


	shift_s(mat, 12, PACK_TILESIZE(0, 2));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_bowser_3_level_geo_mantle_of_madness_hurt() {
	scroll_gfx_mat_mantle_of_madness_hurt_butter_layer4();
	scroll_gfx_mat_mantle_of_madness_hurt_butter_001_layer4();
};

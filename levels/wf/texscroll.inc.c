void scroll_gfx_wf_dl_Log_002_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_Log_002_mesh_layer_5);


	shift_t(mat, 16, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 3));

};

void scroll_gfx_wf_dl_Log_006_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_Log_006_mesh_layer_5);


	shift_t(mat, 16, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 3));

};

void scroll_gfx_wf_dl_Plane_015_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_Plane_015_mesh_layer_5);


	shift_t(mat, 16, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 3));

};

void scroll_gfx_wf_dl_Circle_005_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_Circle_005_mesh_layer_5);


	shift_t(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 19, PACK_TILESIZE(0, 3));

};

void scroll_gfx_wf_dl_Circle_006_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_Circle_006_mesh_layer_5);


	shift_t(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 19, PACK_TILESIZE(0, 1));
	shift_t(mat, 19, PACK_TILESIZE(0, 3));

};

void scroll_wf() {
	scroll_gfx_wf_dl_Log_002_mesh_layer_5();
	scroll_gfx_wf_dl_Log_006_mesh_layer_5();
	scroll_gfx_wf_dl_Plane_015_mesh_layer_5();
	scroll_gfx_wf_dl_Circle_005_mesh_layer_5();
	scroll_gfx_wf_dl_Circle_006_mesh_layer_5();
};

void scroll_ttm_dl_Plane_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 153;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ttm_dl_Plane_mesh_layer_5_vtx_0);

	deltaX = (int)(0.699999988079071 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_mat_ttm_dl_scrollma() {
	Gfx *mat = segmented_to_virtual(mat_ttm_dl_scrollma);

	shift_s(mat, 11, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ttm_dl_stainedglass_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ttm_dl_stainedglass_layer1);

	shift_s(mat, 16, PACK_TILESIZE(0, 2));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_ttm() {
	scroll_ttm_dl_Plane_mesh_layer_5_vtx_0();
	scroll_gfx_mat_ttm_dl_scrollma();
	scroll_gfx_mat_ttm_dl_stainedglass_layer1();
};

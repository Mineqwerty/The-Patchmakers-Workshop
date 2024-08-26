void scroll_ccm_dl_Cube_007_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 40;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Cube_007_mesh_layer_4_vtx_0);

	deltaX = (int)(2.6500000953674316 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm() {
	scroll_ccm_dl_Cube_007_mesh_layer_4_vtx_0();
};

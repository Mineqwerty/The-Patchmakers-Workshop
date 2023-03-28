void scroll_seraphim_root_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 78;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(seraphim_root_mesh_layer_4_vtx_0);

	deltaY = (int)(1.2699999809265137 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_seraphim_root_mesh_layer_4_vtx_1() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(seraphim_root_mesh_layer_4_vtx_1);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_level_geo_seraphim() {
	scroll_seraphim_root_mesh_layer_4_vtx_0();
	scroll_seraphim_root_mesh_layer_4_vtx_1();
}

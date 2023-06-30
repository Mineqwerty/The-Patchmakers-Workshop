void scroll_tfp_skybox_Cube_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 109;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(tfp_skybox_Cube_001_mesh_layer_4_vtx_0);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_level_geo_tfp_skybox() {
	scroll_tfp_skybox_Cube_001_mesh_layer_4_vtx_0();
};

void scroll_corr_skybox_Sphere_007_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 666;
	int height = 256 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(corr_skybox_Sphere_007_mesh_layer_1_vtx_1);

	deltaY = (int)(0.9100000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wdw_level_geo_corr_skybox() {
	scroll_corr_skybox_Sphere_007_mesh_layer_1_vtx_1();
};

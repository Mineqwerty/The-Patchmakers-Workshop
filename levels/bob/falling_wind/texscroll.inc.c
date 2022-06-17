void scroll_falling_wind_umesh_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 63;
	int width = 64 * 0x20;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(falling_wind_umesh_mesh_layer_5_vtx_0);

	deltaY = (int)(-2.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_level_geo_falling_wind() {
	scroll_falling_wind_umesh_mesh_layer_5_vtx_0();
}

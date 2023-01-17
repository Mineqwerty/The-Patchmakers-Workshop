void scroll_star_gate_Plane_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 42;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(star_gate_Plane_mesh_layer_5_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_level_geo_star_gate() {
	scroll_star_gate_Plane_mesh_layer_5_vtx_0();
}

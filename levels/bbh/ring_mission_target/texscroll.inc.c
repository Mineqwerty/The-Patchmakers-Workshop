void scroll_ring_mission_target_Circle_005_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 19;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ring_mission_target_Circle_005_mesh_layer_5_vtx_0);

	deltaY = (int)(1.809999942779541 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_level_geo_ring_mission_target() {
	scroll_ring_mission_target_Circle_005_mesh_layer_5_vtx_0();
};

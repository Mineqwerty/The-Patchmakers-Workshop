void scroll_d20_Icosphere_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 0.12999999523162842;
	float offsetX = 0.0;
	Vtx *vertices = segmented_to_virtual(d20_Icosphere_mesh_layer_1_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_ddd_level_geo_d20() {
	scroll_d20_Icosphere_mesh_layer_1_vtx_0();
};

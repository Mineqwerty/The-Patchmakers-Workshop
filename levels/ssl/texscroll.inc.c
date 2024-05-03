void scroll_ssl_dl_Circle_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.1600000262260437;
	float frequencyX = 0.40000003576278687;
	float offsetX = 0.32999998331069946;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_mesh_layer_1_vtx_2);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_ssl() {
	scroll_ssl_dl_Circle_mesh_layer_1_vtx_2();
};

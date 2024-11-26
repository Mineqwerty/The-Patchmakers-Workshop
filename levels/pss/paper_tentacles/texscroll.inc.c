void scroll_paper_tentacles_Plane_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.2800000309944153;
	float frequencyX = 0.3400000333786011;
	float offsetX = 0.0;
	Vtx *vertices = segmented_to_virtual(paper_tentacles_Plane_004_mesh_layer_5_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_paper_tentacles_Plane_004_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.3700000047683716;
	float frequencyX = 0.5199999809265137;
	float offsetX = 0.0;
	Vtx *vertices = segmented_to_virtual(paper_tentacles_Plane_004_mesh_layer_5_vtx_1);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_pss_level_geo_paper_tentacles() {
	scroll_paper_tentacles_Plane_004_mesh_layer_5_vtx_0();
	scroll_paper_tentacles_Plane_004_mesh_layer_5_vtx_1();
};

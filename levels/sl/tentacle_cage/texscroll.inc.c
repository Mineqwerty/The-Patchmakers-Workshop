void scroll_tentacle_cage_Circle_006_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 28;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.3400000333786011;
	float frequencyX = 0.3100000023841858;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.06999999284744263;
	float frequencyY = 0.04000002145767212;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(tentacle_cage_Circle_006_mesh_layer_4_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY = (timeY + 1) % 65530;
}

void scroll_sl_level_geo_tentacle_cage() {
	scroll_tentacle_cage_Circle_006_mesh_layer_4_vtx_0();
};

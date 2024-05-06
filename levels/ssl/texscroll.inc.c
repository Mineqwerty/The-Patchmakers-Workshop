void scroll_ssl_dl_Circle_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 259;
	int width = 64 * 0x20;
	int height = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.25;
	float frequencyX = 0.22000014781951904;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.1600000262260437;
	float frequencyY = 0.12999987602233887;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_mesh_layer_1_vtx_5);

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
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_ssl_dl_Circle_006_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.25;
	float frequencyX = 0.22000014781951904;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.1600000262260437;
	float frequencyY = 0.12999987602233887;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_006_mesh_layer_1_vtx_0);

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
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_ssl() {
	scroll_ssl_dl_Circle_mesh_layer_1_vtx_5();
	scroll_ssl_dl_Circle_006_mesh_layer_1_vtx_0();
};

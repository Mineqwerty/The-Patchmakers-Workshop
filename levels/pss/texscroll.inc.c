void scroll_pss_dl_Cube_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 10;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.25;
	float frequencyX = 0.25;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.2200000286102295;
	float frequencyY = 0.1600000262260437;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(pss_dl_Cube_001_mesh_layer_5_vtx_0);

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

void scroll_pss_dl_Cube_012_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 4;
	int width = 128 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 2.2300000190734863;
	float frequencyX = 0.49000000953674316;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.899999976158142;
	float frequencyY = 0.6100000143051147;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(pss_dl_Cube_012_mesh_layer_5_vtx_3);

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

void scroll_gfx_mat_pss_dl_f3dlite_material_051() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_f3dlite_material_051);

	shift_s(mat, 10, PACK_TILESIZE(0, 2));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_pss() {
	scroll_pss_dl_Cube_001_mesh_layer_5_vtx_0();
	scroll_pss_dl_Cube_012_mesh_layer_5_vtx_3();
	scroll_gfx_mat_pss_dl_f3dlite_material_051();
};

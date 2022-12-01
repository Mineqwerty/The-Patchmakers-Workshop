void scroll_sts_mat_ccm_dl_the_fog_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_the_fog_layer5_area1);
	shift_t(mat, 16, PACK_TILESIZE(0, 1));
	shift_s(mat, 24, PACK_TILESIZE(0, 1));
	shift_t(mat, 24, PACK_TILESIZE(0, 2));
};

void scroll_ccm_dl_Cube_005_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 38;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 0.2800000309944153;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Cube_005_mesh_layer_6_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(-1.0 * 0x20) % height;

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
	currentX += deltaX;	timeX += 1;	currentY += deltaY;
}

void scroll_ccm() {
	scroll_sts_mat_ccm_dl_the_fog_layer5_area1();
	scroll_ccm_dl_Cube_005_mesh_layer_6_vtx_0();
}

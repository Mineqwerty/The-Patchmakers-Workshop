void scroll_ssl_dl_Circle_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 53;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.3100000023841858;
	float frequencyX = 0.2800000309944153;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.2200000286102295;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.6899999976158142;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_mesh_layer_5_vtx_0);

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

void scroll_ssl_dl_Circle_008_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 30;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.3100000023841858;
	float frequencyX = 0.2800000309944153;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.2200000286102295;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.6899999976158142;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_008_mesh_layer_5_vtx_0);

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

void scroll_ssl_dl_Circle_008_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 14;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.3100000023841858;
	float frequencyX = 0.2800000309944153;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.2200000286102295;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.6899999976158142;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Circle_008_mesh_layer_5_vtx_2);

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

void scroll_ssl_dl_Plane_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 357;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

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
	Vtx *vertices = segmented_to_virtual(ssl_dl_Plane_003_mesh_layer_1_vtx_0);

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

void scroll_gfx_mat_ssl_dl_normalwater_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_normalwater_layer5_area1);
	static int interval_tex_ssl_dl_normalwater_layer5_area1 = 2;
	static int cur_interval_tex_ssl_dl_normalwater_layer5_area1 = 2;

	if (--cur_interval_tex_ssl_dl_normalwater_layer5_area1 <= 0) {
		shift_s_down(mat, 17, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 17, PACK_TILESIZE(0, 1));
		cur_interval_tex_ssl_dl_normalwater_layer5_area1 = interval_tex_ssl_dl_normalwater_layer5_area1;
	}

};

void scroll_gfx_mat_ssl_dl_decalwaterflow_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_decalwaterflow_layer5_area1);
	static int interval_tex_ssl_dl_decalwaterflow_layer5_area1 = 2;
	static int cur_interval_tex_ssl_dl_decalwaterflow_layer5_area1 = 2;


	if (--cur_interval_tex_ssl_dl_decalwaterflow_layer5_area1 <= 0) {
		shift_s_down(mat, 12, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 12, PACK_TILESIZE(0, 3));
		cur_interval_tex_ssl_dl_decalwaterflow_layer5_area1 = interval_tex_ssl_dl_decalwaterflow_layer5_area1;
	}
	shift_s_down(mat, 17, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ssl_dl_normalwaterflow_layer5_area1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_normalwaterflow_layer5_area1);
	static int interval_tex_ssl_dl_normalwaterflow_layer5_area1 = 2;
	static int cur_interval_tex_ssl_dl_normalwaterflow_layer5_area1 = 2;


	if (--cur_interval_tex_ssl_dl_normalwaterflow_layer5_area1 <= 0) {
		shift_s_down(mat, 12, PACK_TILESIZE(0, 1));
		shift_t_down(mat, 12, PACK_TILESIZE(0, 3));
		cur_interval_tex_ssl_dl_normalwaterflow_layer5_area1 = interval_tex_ssl_dl_normalwaterflow_layer5_area1;
	}
	shift_s_down(mat, 17, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 2));

};

void scroll_ssl() {
	scroll_ssl_dl_Circle_mesh_layer_5_vtx_0();
	scroll_ssl_dl_Circle_mesh_layer_1_vtx_5();
	scroll_ssl_dl_Circle_006_mesh_layer_1_vtx_0();
	scroll_ssl_dl_Circle_008_mesh_layer_5_vtx_0();
	scroll_ssl_dl_Circle_008_mesh_layer_5_vtx_2();
	scroll_ssl_dl_Plane_003_mesh_layer_1_vtx_0();
	scroll_gfx_mat_ssl_dl_normalwater_layer5_area1();
	scroll_gfx_mat_ssl_dl_decalwaterflow_layer5_area1();
	scroll_gfx_mat_ssl_dl_normalwaterflow_layer5_area1();
};

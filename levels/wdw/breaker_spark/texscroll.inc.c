void scroll_breaker_spark_Plane_009_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 27;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.2800000309944153;
	float frequencyY = 13.569999694824219;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(breaker_spark_Plane_009_mesh_layer_5_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_wdw_level_geo_breaker_spark() {
	scroll_breaker_spark_Plane_009_mesh_layer_5_vtx_0();
};

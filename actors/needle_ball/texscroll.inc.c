void scroll_needle_ball_Bone_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 46;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(needle_ball_Bone_002_mesh_layer_5_vtx_0);

	deltaY = (int)(0.46000003814697266 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_actor_geo_needle_ball() {
	scroll_needle_ball_Bone_002_mesh_layer_5_vtx_0();
};

const Gfx* lift_cloud_collision_materials[] = {
};

const Collision lift_cloud_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-372, 7, 128),
	COL_VERTEX(370, 7, 128),
	COL_VERTEX(370, 7, -178),
	COL_VERTEX(-372, 7, -178),
	COL_VERTEX(-412, -157, 128),
	COL_VERTEX(409, -157, 128),
	COL_VERTEX(409, 171, 128),
	COL_VERTEX(-412, 171, 128),
	COL_TRI_INIT(SURFACE_DEFAULT, 4),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI_STOP(),
	COL_END()
};

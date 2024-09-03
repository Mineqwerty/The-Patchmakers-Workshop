const Gfx* sight_cracked_platform_collision_materials[] = {
};

const Collision sight_cracked_platform_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(10),
	COL_VERTEX(858, -693, 858),
	COL_VERTEX(1214, -693, 0),
	COL_VERTEX(1214, 143, 0),
	COL_VERTEX(858, 143, 858),
	COL_VERTEX(-858, -693, 858),
	COL_VERTEX(0, -693, 1214),
	COL_VERTEX(0, 143, 1214),
	COL_VERTEX(-858, 143, 858),
	COL_VERTEX(-1214, -693, 0),
	COL_VERTEX(-1214, 143, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 14),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(5, 0, 3),
	COL_TRI(5, 3, 6),
	COL_TRI(8, 4, 7),
	COL_TRI(8, 7, 9),
	COL_TRI(3, 2, 9),
	COL_TRI(9, 7, 6),
	COL_TRI(9, 6, 3),
	COL_TRI(4, 8, 1),
	COL_TRI(1, 0, 5),
	COL_TRI(1, 5, 4),
	COL_TRI_STOP(),
	COL_END()
};

const Gfx* sight_cube_collision_materials[] = {
};

const Collision sight_cube_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(321, -321, 321),
	COL_VERTEX(321, -321, -321),
	COL_VERTEX(321, 321, -321),
	COL_VERTEX(321, 321, 321),
	COL_VERTEX(-321, -321, -321),
	COL_VERTEX(-321, 321, -321),
	COL_VERTEX(-321, 321, 321),
	COL_VERTEX(-321, -321, 321),
	COL_TRI_INIT(SURFACE_DEFAULT, 12),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 2),
	COL_TRI(4, 2, 1),
	COL_TRI(5, 6, 3),
	COL_TRI(5, 3, 2),
	COL_TRI(0, 3, 6),
	COL_TRI(0, 6, 7),
	COL_TRI(4, 1, 0),
	COL_TRI(4, 0, 7),
	COL_TRI(4, 7, 6),
	COL_TRI(4, 6, 5),
	COL_TRI_STOP(),
	COL_END()
};

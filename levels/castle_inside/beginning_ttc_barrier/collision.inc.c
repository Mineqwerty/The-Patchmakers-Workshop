const Gfx* beginning_ttc_barrier_collision_materials[] = {
};

const Collision beginning_ttc_barrier_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-563, 960, -831),
	COL_VERTEX(-563, -14, -831),
	COL_VERTEX(-563, -14, -1805),
	COL_VERTEX(-563, 960, -1805),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

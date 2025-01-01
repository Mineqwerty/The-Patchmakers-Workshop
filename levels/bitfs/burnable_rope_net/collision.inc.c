const Gfx* burnable_rope_net_collision_materials[] = {
};

const Collision burnable_rope_net_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-332, 375, 441),
	COL_VERTEX(-332, 375, -441),
	COL_VERTEX(-332, -375, -441),
	COL_VERTEX(-332, -375, 441),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

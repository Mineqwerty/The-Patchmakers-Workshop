const Collision tfp_rotary_arm_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-22, 0, 23),
	COL_VERTEX(22, 0, 23),
	COL_VERTEX(22, 0, -400),
	COL_VERTEX(-22, 0, -400),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

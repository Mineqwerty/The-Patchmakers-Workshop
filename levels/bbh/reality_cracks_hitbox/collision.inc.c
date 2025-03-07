const Gfx* reality_cracks_hitbox_collision_materials[] = {
};

const Collision reality_cracks_hitbox_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(250, 486, -31),
	COL_VERTEX(-237, 486, -31),
	COL_VERTEX(-237, -258, -31),
	COL_VERTEX(250, -258, -31),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

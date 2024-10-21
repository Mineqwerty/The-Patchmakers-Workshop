static const s16 workshop_door_anim_wsclosed_values[] = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	
};

static const u16 workshop_door_anim_wsclosed_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	
};

static const struct Animation workshop_door_anim_wsclosed = {
	0,
	0,
	0,
	1,
	1,
	ANIMINDEX_NUMPARTS(workshop_door_anim_wsclosed_indices),
	workshop_door_anim_wsclosed_values,
	workshop_door_anim_wsclosed_indices,
	0,
};


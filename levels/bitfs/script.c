#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/bitfs/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitfs_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_13), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WOODEN_PLANK_BLOCK, wooden_plank_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WOODEN_PLANK_LEFT, wooden_plank_left_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WOODEN_PLANK_RIGHT, wooden_plank_right_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitfs_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 627, 0),
		OBJECT(MODEL_NONE, 0, 627, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BOWSER, -356, 627, -13961, 0, 0, 0, 0x00000000, bhvBowser),
		OBJECT(MODEL_YARN_GOOMBA, 40, 835, -9073, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -730, 835, -7840, 0, 97, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 308, 835, -7067, 0, -162, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -643, 835, -4364, 0, -162, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 1022, 1547, -2695, 0, -162, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_KOOPA, 1740, 1547, -3132, 0, 43, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 9063, -310, -3288, 0, 43, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 9802, -310, -2620, 0, -31, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_WOODEN_PLANK_BLOCK, -353, 1045, -6604, 0, 0, -20, 0x00000000, bhvWoodenPlankBlock),
		OBJECT(MODEL_WOODEN_PLANK_BLOCK, -353, 1100, -6544, 0, 0, 28, 0x00000000, bhvWoodenPlankBlock),
		OBJECT(MODEL_WOODEN_PLANK_BLOCK, 3549, 1793, -3019, 0, 90, -20, 0x00000000, bhvWoodenPlankBlock),
		OBJECT(MODEL_WOODEN_PLANK_BLOCK, 3608, 1848, -3019, 0, 90, 28, 0x00000000, bhvWoodenPlankBlock),
		OBJECT(MODEL_WOODEN_PLANK_BLOCK, 5246, 1848, -3019, 0, 90, -31, 0x00000000, bhvWoodenPlankBlock),
		OBJECT(MODEL_PODOGOO, 150, 835, -4181, 0, 97, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -995, 835, -4921, 0, 43, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -794, 1198, -2756, 0, 43, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, 2777, 1547, -2663, 0, 43, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_YARN_SCUTTLEBUG, -834, 835, -8899, 0, -162, 0, 0x00000000, bhvScuttlebug),
		TERRAIN(bitfs_area_1_collision),
		TERRAIN_MAT_LUT(bitfs_area_1_collision_materials),
		MACRO_OBJECTS(bitfs_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 627, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
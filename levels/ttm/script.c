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
#include "levels/ttm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttm_segment_7SegmentRomStart, _ttm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ttm_segment_7SegmentRomStart, _ttm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	LOAD_MODEL_FROM_GEO(MODEL_SIGHT_CUBE, sight_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIGHT_SWITCH_INACTIVE, sight_switch_inactive_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIGHT_SWITCH_ACTIVE, sight_switch_active_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIGHT_CRACKED_PLATFORM, sight_cracked_platform_geo), /* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_SIGHT_CUBE, 5521, 17, -5366, 0, -180, 0, (40 << 24) | (6 << 16) | (1 << 8) | (10), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4313, 1204, -6980, 0, -90, 0, (66 << 24) | (12 << 16) | (1 << 8) | (34), bhvMovingSightCube),
		OBJECT(MODEL_NONE, 4153, 1260, -14877, 0, 0, 0, 0x00000000, bhvSightChamberController),
		OBJECT(MODEL_SIGHT_CUBE, 3591, -187, -7175, 0, 0, 0, (40 << 24) | (80 << 16) | (30 << 8), bhvSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 5797, 185, -9274, 0, 0, 0, (30 << 24) | (180 << 16) | (20 << 8), bhvSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 1203, -669, -6827, 0, 0, 0, (30 << 24) | (180 << 16) | (20 << 8), bhvSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 3033, 1083, -7926, 0, 0, 0, (33 << 24) | (180 << 16) | (25 << 8), bhvSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 911, 1415, -9269, 0, 0, 0, (33 << 24) | (180 << 16) | (25 << 8), bhvSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 2886, -827, -5908, 0, 0, 0, (60 << 24) | (5 << 16) | (0 << 8) | (20), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4417, 325, -9147, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 339, -338, -6777, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (110), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 3646, 1772, -9348, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4118, 2176, -11183, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 1010, 87, -8669, 0, 0, 0, (50 << 24) | (5 << 16) | (0 << 8) | (10), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4749, 486, -8055, 0, 0, 0, (50 << 24) | (5 << 16) | (0 << 8) | (10), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 3222, 878, -10244, 0, 0, 0, (50 << 24) | (5 << 16) | (0 << 8) | (10), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 613, 25, -11365, 0, 0, 0, (50 << 24) | (5 << 16) | (0 << 8) | (10), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4187, 1280, -10406, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 4673, 1002, -8888, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 3964, 36, -9831, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_CUBE, 2205, -67, -9613, 0, 0, 0, (50 << 24) | (12 << 16) | (0 << 8) | (130), bhvMovingSightCube),
		OBJECT(MODEL_SIGHT_SWITCH_INACTIVE, 339, -173, -6777, 0, 0, 0, (1 << 24), bhvSightSwitch),
		OBJECT(MODEL_SIGHT_SWITCH_INACTIVE, 911, 1559, -9269, 0, 0, 0, 0x00000000, bhvSightSwitch),
		OBJECT(MODEL_SIGHT_SWITCH_INACTIVE, 5797, 323, -9274, 0, 0, 0, 0x00000000, bhvSightSwitch),
		OBJECT(MODEL_SIGHT_SWITCH_INACTIVE, 4118, 2258, -11183, 0, 0, 0, (1 << 24), bhvSightSwitch),
		OBJECT(MODEL_SIGHT_SWITCH_INACTIVE, 5521, 115, -5366, 0, 0, 0, (1 << 24), bhvSightSwitch),
		TERRAIN(ttm_area_1_collision),
		TERRAIN_MAT_LUT(ttm_area_1_collision_materials),
		MACRO_OBJECTS(ttm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
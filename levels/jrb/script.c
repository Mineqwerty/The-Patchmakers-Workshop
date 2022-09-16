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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_STONE_TOWER_DOOR, stone_tower_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEAR, stone_gear_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GEAR, 2847, 335, -490, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, 2847, 39, -2476, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, 2847, 335, 420, 0, -135, 0, (1 << 16), bhvStoneGear),
		OBJECT(MODEL_STAR, -2220, 3482, -11636, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STONE_TOWER_DOOR, -680, 1556, -5054, 0, 0, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -680, 1556, -5054, 0, -180, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1369, 1556, -5054, 0, 0, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1369, 1556, -5054, 0, -180, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1244, 1556, -4710, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -805, 1556, -4710, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1244, 1556, -5398, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -805, 1556, -5398, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2218, 3082, -11254, 0, 90, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2218, 3082, -11254, 0, -90, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1999, 3082, -11942, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2437, 3082, -11942, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_NONE, 0, 684, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 684, 0),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STONE_TERRACE_CITY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 684, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

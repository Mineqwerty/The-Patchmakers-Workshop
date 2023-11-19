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
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_TILTING_STONE_BRIDGE, tilting_stone_bridge_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNDERWATER_STONE_DOOR, underwater_stone_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNDERWATER_STONE_BUTTON, underwater_stone_button_geo),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 8022, 4543, -10957, 0, 119, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 7488, 5282, -12000, 0, 119, 0, (200 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -10913, 7501, -13720, 0, 119, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -8884, 7017, -9435, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11885, 7207, -6296, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8211, 7200, -4843, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -13374, 7091, -10005, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11480, 4345, -11761, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -12569, 7188, -4308, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7789, 3647, -4154, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -10783, 6978, 944, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_TILTING_STONE_BRIDGE, 10259, 4226, -10280, 0, 119, 0, 0x00000000, bhvBbhTiltingTrapPlatform),
		OBJECT(MODEL_NONE, -2677, 4922, 113, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -2677, 4922, 113),
		OBJECT(MODEL_NONE, 7338, 2647, 9109, 0, 0, 0, (50 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_WATER_RING, 8564, -8131, 836, 0, -148, 0, 0x00000000, bhvSubSeaWaterRing),
		OBJECT(MODEL_NONE, 6542, -8799, -42, 0, 119, 0, 0x00000000, bhvSubSeaWaterRingManager),
		OBJECT(MODEL_WATER_RING, 9775, -7798, 2067, 0, -165, 0, (1 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 8907, -7285, 3955, 0, 136, 0, (2 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 6786, -5913, 5106, 75, 127, 16, (3 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 4805, -3004, 6009, 0, 149, 0, (4 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 944, -4649, 9899, 0, -111, 0, (5 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, -2894, -4507, 5142, 0, -157, 0, (6 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, -138, -2202, -552, 0, 91, 0, (7 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 4957, -2310, -4150, 0, 105, 0, (8 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 11307, -2296, -5655, 0, 85, -23, (9 << 16), bhvSubSeaWaterRing),
		TERRAIN(hmc_area_1_collision),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, hmc_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, 3365, 0, 0, 0, (7 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, -733, 0, 0, 0, (4 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, -4225, 0, 0, 0, (2 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_NONE, 43, 2941, -7459, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		TERRAIN(hmc_area_2_collision),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -2677, 4922, 113),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

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
	LOAD_MIO0(0x7, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_TILTING_STONE_BRIDGE, tilting_stone_bridge_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNDERWATER_STONE_DOOR, underwater_stone_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_UNDERWATER_STONE_BUTTON, underwater_stone_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CORAL_SPINNER, coral_spinner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GLASSFISH, glassfish_geo), /* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_HMC, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -2677, 4922, 113),
		OBJECT(MODEL_NONE, -2677, 4922, 113, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_YARN_BLOOPER, 10899, -1181, 2317, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, 8394, -4788, -1412, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -2858, -1919, 7171, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -907, -2370, 7495, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -1366, -682, 6641, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -1477, -1835, 4764, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -6627, -1898, 10039, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_YARN_BLOOPER, -7552, 196, 9009, 0, 105, 0, 0x00000000, bhvYarnBlooper),
		OBJECT(MODEL_CORAL_SPINNER, 645, -5487, -8892, 0, -90, 0, 0x00000000, bhvCoralSpinner),
		OBJECT(MODEL_CORAL_SPINNER, -2180, -5487, -8892, 0, -90, 0, (40 << 16), bhvCoralSpinner),
		OBJECT(MODEL_CORAL_SPINNER, -5310, -5487, -8892, 0, -90, 0, (78 << 16), bhvCoralSpinner),
		OBJECT(MODEL_NONE, 9762, 6510, -13813, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, 7580, 6702, -12617, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, 8272, 6943, -13275, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_GLASSFISH, 4456, -4866, -1380, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -11597, -963, -8464, 0, 105, 0, (3 << 16), bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, 4386, -3689, 2590, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, 3130, -7374, -2033, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, 4739, -2554, 5994, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -1154, -4943, 9392, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, 8152, -2183, -5289, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -13131, -684, -5969, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -10884, -112, -6297, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -11471, -1718, -6005, 0, 105, 0, 0x00000000, bhvGlassfish),
		OBJECT(MODEL_GLASSFISH, -10262, -1374, 3685, 0, 105, 0, 0x00000000, bhvGlassfish),
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
		OBJECT(MODEL_RED_COIN, -10783, 7082, 944, 0, 119, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 6453, 7313, -2966, 0, 119, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_TILTING_STONE_BRIDGE, 10259, 4226, -10280, 0, 119, 0, 0x00000000, bhvBbhTiltingTrapPlatform),
		OBJECT(MODEL_NONE, 7338, 2647, 9109, 0, 0, 0, (50 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -10173, -3658, -8838, 0, 0, 0, (50 << 24) | (12 << 16), bhvWarp),
		OBJECT(MODEL_WATER_RING, 8564, -8131, 836, 0, -148, 0, 0x00000000, bhvSubSeaWaterRing),
		OBJECT(MODEL_NONE, 6542, -8799, -42, 0, 119, 0, 0x00000000, bhvSubSeaWaterRingManager),
		OBJECT(MODEL_WATER_RING, 9775, -7798, 2067, 0, -165, 0, (1 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 8907, -7285, 3955, 0, 136, 0, (2 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 6786, -5913, 5106, 60, 108, -20, (3 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 4805, -3004, 6009, 0, 149, 0, (4 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 944, -4649, 9899, 0, -111, 0, (5 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, -2894, -4507, 5142, 0, -157, 0, (6 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, -138, -2202, -552, 0, 91, 0, (7 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 4957, -2310, -4150, 0, 105, 0, (8 << 16), bhvSubSeaWaterRing),
		OBJECT(MODEL_WATER_RING, 11307, -2296, -5655, 23, 85, -2, (9 << 16), bhvSubSeaWaterRing),
		TERRAIN(hmc_area_1_collision),
		TERRAIN_MAT_LUT(hmc_area_1_collision_materials),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SUBTERRANEAN_SEAWAY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, hmc_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 62, 2956, -7766, 0, 119, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_UNDERWATER_STONE_BUTTON, 11756, 3114, 13278, 0, -180, 0, (7 << 16), bhvUnderwaterStoneButton),
		OBJECT(MODEL_UNDERWATER_STONE_BUTTON, -12188, 3825, -3526, 0, 0, 0, (4 << 16), bhvUnderwaterStoneButton),
		OBJECT(MODEL_UNDERWATER_STONE_BUTTON, 5317, 3099, -2573, 0, -90, 0, (2 << 16), bhvUnderwaterStoneButton),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, 3365, 0, 0, 0, (7 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, -733, 0, 0, 0, (4 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_UNDERWATER_STONE_DOOR, 15, 4726, -4225, 0, 0, 0, (2 << 16), bhvUnderwaterStoneDoor),
		OBJECT(MODEL_NONE, 43, 2941, -7459, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		TERRAIN(hmc_area_2_collision),
		TERRAIN_MAT_LUT(hmc_area_2_collision_materials),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SUBTERRANEAN_SEAWAY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, hmc_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 5343, -3290, -8444, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -2243, 3726, -4263, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, -2253, 3998, -5447, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, -2248, 5289, -4816, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, -2255, 5691, -5864, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, -2246, 5781, -3906, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_NONE, -2258, 2976, -4740, 0, 119, 0, 0x00000000, bhvGeyser),
		OBJECT(MODEL_STAR, -4238, 7131, -4812, 0, 119, 0, (4 << 24), bhvStar),
		TERRAIN(hmc_area_3_collision),
		TERRAIN_MAT_LUT(hmc_area_3_collision_materials),
		MACRO_OBJECTS(hmc_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SUBTERRANEAN_SEAWAY),
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
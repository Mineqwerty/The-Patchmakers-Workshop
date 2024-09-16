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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_SWAMP_SKEETER, swamp_skeeter_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TALOTAK, talotak_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TAEBER, taeber_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TAEBER_LEAVES, taeber_leaves_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLUBOL, blubol_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GROUND_PATCH, grounded_patch_chillstep_geo), /* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x41, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_WF, 0x02, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_WF, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 10512, 1421, 2979, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_YARN_GOOMBA, -2305, 100, -2851, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -2831, 100, -2433, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_SKEETER, -4910, -835, 10265, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 2731, -208, 3604, 0, 0, 0, (30 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_SWAMP_SKEETER, 9335, -254, -3013, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_SWAMP_SKEETER, 12294, -363, -3329, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_SWAMP_SKEETER, 10665, -195, -1864, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_NONE, 8096, 774, 5898, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_SKEETER, -5502, -1053, 11387, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -6995, -1250, 11588, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 11801, 837, 4951, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 9976, -1330, -11729, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_YARN_GOOMBA, 5140, 561, 9716, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 11042, 1671, 9572, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 13227, 902, 4005, 0, -75, 0, 0x00000000, bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, 13266, 914, 4397, 0, -75, 0, 0x00000000, bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, 13424, 965, 4713, 0, -75, 0, 0x00000000, bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, 13585, 996, 4986, 0, -75, 0, 0x00000000, bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, -4452, -192, -4397, 0, 0, 0, (30 << 24) | (12 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1624, 278, -985, 0, 10, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4751, 285, 4841, 0, 10, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4821, 980, 8741, 0, 10, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9264, 1961, 11450, 0, 120, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10923, 1722, 8362, 0, -175, 0, 0x00000000, bhvCoinFormation),
		MARIO_POS(0x01, -90, -2073, 100, 1819),
		OBJECT(MODEL_NONE, -2103, 100, 1816, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BLUBOL, 8419, 3252, -11973, 8, 2, 11, (1 << 16), bhvBlubol),
		OBJECT(MODEL_BLUBOL, 8201, 3241, -11840, -16, -2, -18, 0x00000000, bhvBlubol),
		OBJECT(MODEL_BLUBOL, 8435, 3297, -11746, -27, -4, 12, 0x00000000, bhvBlubol),
		OBJECT(MODEL_NONE, 10112, -4, -1804, 0, 42, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6893, -1064, -12147, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6801, -187, -13968, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6605, 391, -12238, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7519, 1038, -13586, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5932, 1802, -13010, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6435, 2646, -13718, 0, 10, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3255, 423, 8152, 0, 27, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 11614, 12, -7974, 0, 163, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7553, 3694, -12483, 0, 52, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2556, 203, -1800, 0, 10, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9933, 1322, 3229, 0, -175, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6935, 146, -4390, 0, 10, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9936, 46, -6625, 0, 10, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4534, -1553, -13001, 0, 10, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -125, 314, 121, 0, 27, 0, 0x00000000, bhvRainSoundManager),
		OBJECT(MODEL_RED_COIN, 11563, -235, -3504, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 7259, 381, -5086, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, 10821, -52, -2353, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9171, -43, -1733, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8835, -158, -3312, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12989, -107, -2802, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12444, 133, -1531, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10050, -257, -3875, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10277, -12, -604, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_YELLOW_COIN, -857, 145, 7468, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -1960, 150, 7150, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 5113, 290, 6459, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4531, 229, 7102, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 3954, 144, 6180, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 10542, 1084, 5365, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 10170, -139, -2895, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 10979, -162, -2979, 0, 27, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_STAR, 4859, -3260, 3200, 0, 27, 0, (11 << 24), bhvStar),
		OBJECT(MODEL_STAR, -9765, 319, -13134, 0, 27, 0, (12 << 24), bhvStar),
		OBJECT(MODEL_STAR, -8976, -664, 14147, 0, 0, 0, (4 << 24) | (4 << 16), bhvStar),
		OBJECT(MODEL_TAEBER, 7507, -207, -13408, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 6837, 988, -13950, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 6162, 1294, -13690, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5570, 2590, -13926, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5038, 2754, -12879, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5635, 3074, -12057, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, -2672, 41, 7270, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, -8976, -1459, 14147, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TALOTAK, 8383, -1713, -13181, 0, -12, 0, 0x00000000, bhvTalotak),
		OBJECT(MODEL_TALOTAK, 7770, -1713, -14078, 0, -12, 0, 0x00000000, bhvTalotak),
		OBJECT(MODEL_TALOTAK, 6974, 119, -7230, 0, -12, 0, 0x00000000, bhvTalotak),
		OBJECT(MODEL_TALOTAK, 4891, 119, -6618, 0, -71, 0, 0x00000000, bhvTalotak),
		OBJECT(MODEL_TALOTAK, 1697, 119, 1416, 0, 0, 0, 0x00000000, bhvTalotak),
		TERRAIN(wf_area_1_collision),
		ROOMS(wf_area_1_collision_rooms),
		TERRAIN_MAT_LUT(wf_area_1_collision_materials),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_RAINY_DAY_ROADSIDE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, wf_area_2),
		WARP_NODE(0x0A, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x41, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YARN_GOOMBA, 1612, 237, -1682, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 3517, 237, -454, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_TAEBER, 3463, 2058, 11707, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_YARN_GOOMBA, 3739, 2518, 13486, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_STAR, 3212, 3507, 13369, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, -5356, -18, -1325, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_GROUND_PATCH, -481, 250, -1306, -90, 0, 0, (1 << 16), bhvGroundPatch),
		OBJECT(MODEL_NONE, -481, 418, -1306, 0, 0, 0, (5 << 24) | (4 << 16), bhvTextVolume),
		OBJECT(MODEL_NONE, 3569, 237, 2377, 0, 0, 0, (7 << 24) | (8 << 16), bhvTextVolume),
		OBJECT(MODEL_NONE, 1812, 452, -1208, 0, 0, 0, (6 << 24) | (6 << 16), bhvTextVolume),
		OBJECT(MODEL_NONE, 3515, 1208, 10110, 0, 0, 0, (8 << 24) | (10 << 16), bhvTextVolume),
		TERRAIN(wf_area_2_collision),
		TERRAIN_MAT_LUT(wf_area_2_collision_materials),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, wf_area_3),
		WARP_NODE(0x0A, LEVEL_WF, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x41, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -357, -6875, 8116, 0, 0, 0, (5 << 24) | (5 << 16), bhvStar),
		OBJECT(MODEL_NONE, -3678, 1722, -270, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -3188, 1749, -257, 0, 83, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -125, 314, 121, 0, 27, 0, 0x00000000, bhvRainSoundManager),
		TERRAIN(wf_area_3_collision),
		TERRAIN_MAT_LUT(wf_area_3_collision_materials),
		MACRO_OBJECTS(wf_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_RAINY_DAY_ROADSIDE),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, -2073, 100, 1819),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
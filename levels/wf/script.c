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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_WF, 0x02, 10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUBOL, 8419, 3252, -11973, 8, 0, 11, (1 << 16), bhvBlubol),
		OBJECT(MODEL_BLUBOL, 8201, 3241, -11840, -15, -7, -17, 0x00000000, bhvBlubol),
		OBJECT(MODEL_BLUBOL, 8435, 3297, -11746, -27, 2, 11, 0x00000000, bhvBlubol),
		OBJECT(MODEL_STAR, 10512, 1421, 2979, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_YARN_GOOMBA, -2786, 100, 462, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -2910, 100, -642, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_SKEETER, -2489, 210, -1241, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 2731, -208, 3604, 0, 0, 0, (30 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_SWAMP_SKEETER, 9335, -254, -3013, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_SWAMP_SKEETER, 12294, -363, -3329, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_SWAMP_SKEETER, 10665, -195, -1864, 0, 0, 0, 0x00000000, bhvSwampSkeeter),
		OBJECT(MODEL_RED_COIN, 11563, -235, -3504, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 7259, 381, -5086, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, 10821, -52, -2353, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9171, -43, -1733, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8835, -158, -3312, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12989, -107, -2802, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12444, 133, -1531, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10050, -257, -3875, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10277, -12, -604, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_TAEBER, 7507, -207, -13408, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 6837, 988, -13950, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 6162, 1294, -13690, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5570, 2590, -13926, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5038, 2754, -12879, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TAEBER, 5635, 3074, -12057, 0, 0, 0, 0x00000000, bhvTaeber),
		OBJECT(MODEL_TALOTAK, 8383, -1713, -13181, 0, -12, 0, 0x00000000, bhvGenericNPC),
		OBJECT(MODEL_TALOTAK, 7770, -1713, -14078, 0, -12, 0, 0x00000000, bhvGenericNPC),
		OBJECT(MODEL_TALOTAK, 6974, 119, -7230, 0, -12, 0, 0x00000000, bhvGenericNPC),
		OBJECT(MODEL_TALOTAK, 4891, 119, -6618, 0, -71, 0, 0x00000000, bhvGenericNPC),
		OBJECT(MODEL_TALOTAK, 1697, 119, 1416, 0, 0, 0, 0x00000000, bhvGenericNPC),
		OBJECT(MODEL_NONE, -2316, 100, 1462, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -2316, 100, 1462),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_RAINY_DAY_ROADSIDE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0x0A, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YARN_GOOMBA, 1612, 237, -1682, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 3517, 237, -454, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 2932, 1974, 12032, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 4067, 2518, 12118, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_STAR, 3212, 3507, 13369, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, -5356, -18, -1325, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -2316, 100, 1462),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

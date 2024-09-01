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
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, corr_skybox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_CONSTRUCTION_LIGHT, red_construction_light_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POWER_BREAKER, power_breaker_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BREAKER_SPARK, breaker_spark_geo), /* Fast64 begin persistent block [level commands] */
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

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WDW, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WDW, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -10965, 117, 1142),
		OBJECT(MODEL_NONE, -10940, 119, 1132, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT_WITH_ACTS(MODEL_POWER_BREAKER, -7739, 393, 8885, 0, 0, 0, 0x00000000, bhvPowerBreaker, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_NONE, 1886, 872, 4738, 0, 0, 0, 0x00000000, bhvPowerBreakerController, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_POWER_BREAKER, -7358, 757, -9900, 0, 0, 0, 0x00000000, bhvPowerBreaker, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_POWER_BREAKER, 1100, 1765, -6577, -59, 0, 0, 0x00000000, bhvPowerBreaker, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_POWER_BREAKER, 4942, 2222, -291, 99, 0, 0, 0x00000000, bhvPowerBreaker, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_POWER_BREAKER, 10285, 1192, -7014, 0, 0, 0, 0x00000000, bhvPowerBreaker, ACT_5 | ACT_6),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvCorrWindController),
		OBJECT(MODEL_FOG_RED_COIN, -5905, 2130, -9539, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -8483, 2568, -12252, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -3445, 4303, -9532, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -2282, 5185, -9559, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -8531, 5688, -10652, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -9054, 2690, -10345, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -7332, 3918, -11275, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FOG_RED_COIN, -6963, 5101, -10986, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, -4835, 639, 7759, 0, 0, 0, 0x00000000, bhvRedConstructionLight),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, -16, 288, 4702, 0, 0, 0, 0x00000000, bhvRedConstructionLight),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, 308, 1414, 785, 0, 0, 0, 0x00000000, bhvRedConstructionLight),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, -10316, 452, 4745, 0, 0, 0, 0x00000000, bhvRedConstructionLight),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, 2285, 2955, -3027, 0, 0, 0, 0x00000000, bhvRedConstructionLight),
		OBJECT(MODEL_STAR, 6713, 7825, 1935, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_RED_CONSTRUCTION_LIGHT, -6326, 1401, -7129, 0, 0, 0, (2 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 8850, 10570, 10435, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_NONE, 2085, 4115, -5391, 0, 0, 0, (30 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 9887, -1613, -10002, 0, 0, 0, (60 << 24) | (12 << 16), bhvWarp),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 3090, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 4182, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 5269, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2749, 3090, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2749, 4182, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2749, 5269, 688, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 3090, -2524, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 4182, -2524, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, -463, 5269, -2524, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 8826, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 6556, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 4633, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 2566, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 8826, 12559, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 6556, 12559, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 4633, 12559, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6726, 2566, 12559, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 10974, 8826, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 10974, 6556, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 10974, 4633, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 10974, 2566, 8311, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 5830, 7038, 2609, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 5726, 5155, 2982, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 5624, 3295, 3351, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2911, 6171, 1556, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2706, 4451, 2128, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 4285, 6164, 2051, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 4078, 4424, 2630, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 6335, 4361, -1193, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 7324, 4463, 1812, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 5268, 5820, -9141, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2738, 6324, -5234, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 2816, 4767, -5515, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 4808, 3252, -9399, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 5878, 2401, -1663, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(MODEL_RED_CONSTRUCTION_LIGHT, 7227, 2698, 2161, 0, 0, 0, (1 << 16), bhvRedConstructionLight, ACT_5 | ACT_6),
		TERRAIN(wdw_area_1_collision),
		TERRAIN_MAT_LUT(wdw_area_1_collision_materials),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, wdw_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 581, 8000, 6215, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -824, -506, 157, 0, 0, 0, 0x00000000, bhvCorrWindController),
		OBJECT(MODEL_STAR, -1312, 7689, 5011, 0, 0, 0, (1 << 24), bhvStar),
		TERRAIN(wdw_area_2_collision),
		TERRAIN_MAT_LUT(wdw_area_2_collision_materials),
		MACRO_OBJECTS(wdw_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, wdw_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WDW, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WDW, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -4755, 5724, -5942, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, -6394, 245, -8020, 0, 0, 0, (5 << 24), bhvStar),
		TERRAIN(wdw_area_3_collision),
		TERRAIN_MAT_LUT(wdw_area_3_collision_materials),
		MACRO_OBJECTS(wdw_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SNOW),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10965, 117, 1142),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
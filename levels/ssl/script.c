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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_PURPLE_MUSHROOM, purple_mushroom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GRAY_MUSHROOM, gray_mushroom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LILY_PAD, lily_pad_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DANGER_PUFF, danger_puff_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MALVA_BUD, malva_bud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MALVA_FLOWER, malva_flower_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, vtw_skybox_geo), /* Fast64 begin persistent block [level commands] */
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

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_SSL, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_SSL, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x33, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x043, WARP_NO_CHECKPOINT),
		WARP_NODE(0xEF, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 148, 435, -816, 0, 0, 0, 0x00000000, bhvFoliageManager),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_STAR, 10605, 3619, 752, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 1663, -4561, -8586, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_NONE, -10044, 87, -3591, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 5490, 3818, -2975, 0, -64, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2934, 1944, -12379, 0, -77, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9876, 1475, -7156, 0, -68, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8626, 1788, -13132, 0, -103, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1392, 2061, -2576, 0, -134, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1529, 313, 13982, 0, -134, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -9036, 712, 3658, 0, 99, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12827, -617, -1715, 0, 99, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7899, -3252, -10159, 0, -166, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8680, -3761, -3285, 0, 75, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2986, 2001, -8515, 0, 135, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4958, 383, -462, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5080, 1609, 3769, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9900, 1500, -7200, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9619, 3552, -351, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 11205, 3694, 2102, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4909, 3304, 6807, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_DANGER_PUFF, 480, 1342, 4138, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 2424, 2001, 439, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 3203, 1791, 4841, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 2571, 374, 13484, 0, 17, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 11500, 2149, 11490, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 13475, 2202, 15431, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 14902, 2593, 3178, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 2701, 1770, -10578, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -2589, -5680, -2293, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 2367, 4079, -846, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, 1348, 3649, -2769, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -15186, 856, 4529, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -13591, 541, 340, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -15620, -231, -1096, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -15257, -585, -4062, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -13169, -1024, -4535, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -10394, -2150, -8746, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -11509, -2469, -11699, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -9139, -2926, -12784, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -5431, -3931, -11589, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -5654, -4105, -9791, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -676, -4536, -10374, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -4010, -5373, -1574, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -3150, -5611, -1862, 0, 37, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -4748, -5072, -1469, 0, -82, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -4687, -4766, -3060, 0, -82, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -4853, -5003, -2168, 0, -82, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -5235, -4758, -3030, 0, 50, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -6459, -4451, -2012, 0, 50, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_DANGER_PUFF, -5685, -4689, -2485, 0, 50, 0, 0x00000000, bhvDangerPuff),
		OBJECT(MODEL_NONE, 1523, 2276, -5907, 0, -180, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13604, 449, 8546, 0, 170, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 15435, 1980, 11532, 0, 178, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_FORTUNE_TELEPORTER_PEDESTAL, 5665, -6140, 1665, 0, 0, 0, 0x00000000, bhvFortuneTeleporterPedestal),
		OBJECT(MODEL_GRAY_MUSHROOM, -5374, 515, -3660, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 6746, 1567, -7860, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 5107, 1924, -12973, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 6633, 2379, -10390, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_LILY_PAD, -3170, 878, 6509, 0, 0, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_NONE, -3456, 1354, 4676, 0, 37, 0, 0x00000000, bhvLilyStarManager),
		OBJECT(MODEL_LILY_PAD, -3456, 878, 4676, 0, 37, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -4271, 878, 4214, 0, -62, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -2648, 878, 3635, 0, -22, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -2239, 878, 4648, 0, -154, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, 3013, 3260, 7852, 0, -120, 0, (1 << 16), bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, 2015, 3258, 8110, 0, -143, 0, (1 << 16), bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -2564, 1880, -78, 0, -1, 0, (1 << 16), bhvLilyPad),
		OBJECT(MODEL_MALVA_BUD, -2621, 1965, -3542, 0, 37, 0, 0x00000000, bhvMalvaFlower),
		OBJECT(MODEL_NONE, -3708, 344, -3426, 0, 37, 0, 0x00000000, bhvMalvaFlowerManager),
		OBJECT(MODEL_MALVA_BUD, 12101, 3019, -8117, 0, 37, 0, 0x00000000, bhvMalvaFlower),
		OBJECT(MODEL_MALVA_BUD, 1957, 2052, -7367, 0, 37, 0, 0x00000000, bhvMalvaFlower),
		OBJECT(MODEL_MALVA_BUD, 5824, 2792, 6810, 0, 37, 0, 0x00000000, bhvMalvaFlower),
		OBJECT(MODEL_MALVA_BUD, 7243, 3835, -4716, 0, 37, 0, 0x00000000, bhvMalvaFlower),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7068, -624, 13381, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 9765, 245, 13371, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7769, -231, 14575, 0, 64, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7371, -163, 12571, 0, -44, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 15332, 866, 8704, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 14146, -41, 11660, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, -1608, 4028, -902, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 5787, 1776, -10407, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_RED_COIN, 13099, 2702, -10781, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5128, 2932, -12990, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7796, 3277, -10387, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6624, 3272, -11276, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11260, 1490, -7625, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9525, 1592, -10277, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9107, 3093, -12773, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2081, 2819, -8328, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 6731, -5836, 1131, 0, 0, 0, (23 << 24), bhvStar),
		OBJECT(MODEL_NONE, 1137, 1838, -12176, 0, 0, 0, (2 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 1504, 2547, -4370, 0, -134, 0, (239 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -4034, 1396, -3803, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5408, 2148, -5547, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6749, 2036, -7840, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6796, 3393, -3786, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1547, 1229, -6609, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7097, -294, 14437, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6766, 742, 11810, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10080, 854, 13754, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3195, 1753, 6518, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2539, 4900, 8024, 0, -120, 0, (50 << 24) | (13 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1571, 605, -6542, 0, 0, 0, (40 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -1616, 5584, -917, 0, 0, 0, (40 << 24) | (12 << 16), bhvWarp),
		TERRAIN(ssl_area_1_collision),
		ROOMS(ssl_area_1_collision_rooms),
		TERRAIN_MAT_LUT(ssl_area_1_collision_materials),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_VIOLET_TWILIT_WOODS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, ssl_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x33, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x43, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 11841, 559, -5, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_FORTUNE_TELEPORTER_PEDESTAL, 12374, 771, -1792, 0, 0, 0, 0x00000000, bhvFortuneTeleporterPedestal),
		OBJECT(MODEL_GRAY_MUSHROOM, 3198, 3950, -6135, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GROUND_PATCH, 10592, 675, -12, -90, 0, 0, (7 << 16), bhvGroundPatch),
		OBJECT(MODEL_STAR, 3119, 5387, -8619, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 9989, 687, 23, -90, 0, 0, (45 << 24) | (9 << 16), bhvTextVolume),
		OBJECT(MODEL_NONE, -1135, 1350, 9967, -90, 0, 0, (46 << 24) | (12 << 16), bhvTextVolume),
		TERRAIN(ssl_area_2_collision),
		TERRAIN_MAT_LUT(ssl_area_2_collision_materials),
		MACRO_OBJECTS(ssl_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_PATCH_AREA),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, ssl_area_3),
		WARP_NODE(0x0A, LEVEL_SSL, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_SSL, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x33, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x43, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 102, 1253, -148, 0, 156, 0, (50 << 24) | (10 << 16), bhvWarp),
		OBJECT(MODEL_SKYBOX_TEST, -1430, 2324, -3, 0, 156, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, 2873, 4637, -414, 0, 156, 0, (5 << 24), bhvStar),
		TERRAIN(ssl_area_3_collision),
		TERRAIN_MAT_LUT(ssl_area_3_collision_materials),
		MACRO_OBJECTS(ssl_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_CRICKETS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, ssl_area_4),
		WARP_NODE(0x0A, LEVEL_SSL, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_SSL, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x33, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x43, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 102, 1253, -148, 0, 156, 0, (50 << 24) | (10 << 16), bhvWarp),
		OBJECT(MODEL_GLOBAL_GROUND_BOOK, 1086, 1535, -2548, 0, -180, 0, (31 << 24) | (3 << 16), bhvReadableBook),
		TERRAIN(ssl_area_4_collision),
		TERRAIN_MAT_LUT(ssl_area_4_collision_materials),
		MACRO_OBJECTS(ssl_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_CRICKETS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
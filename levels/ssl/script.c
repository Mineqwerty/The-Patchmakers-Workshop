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
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_PURPLE_MUSHROOM, purple_mushroom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GRAY_MUSHROOM, gray_mushroom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LILY_PAD, lily_pad_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SSL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 148, 435, -816, 0, 0, 0, 0x00000000, bhvFoliageManager),
		OBJECT(MODEL_GRAY_MUSHROOM, -5374, 515, -3660, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 6746, 1567, -7860, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 5107, 1924, -12973, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GRAY_MUSHROOM, 6633, 2379, -10390, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_LILY_PAD, -3170, 878, 6509, 0, 0, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -1596, 878, 6502, 0, 37, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -4271, 878, 4214, 0, -62, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -3072, 878, 2640, 0, -22, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, -2239, 878, 4648, 0, -154, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, 3013, 3260, 7852, 0, 37, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_LILY_PAD, 1846, 3258, 8247, 0, 139, 0, 0x00000000, bhvLilyPad),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7068, -624, 13381, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 9765, 245, 13371, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7769, -231, 14575, 0, 64, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 7371, -163, 12571, 0, -44, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 15332, 866, 8704, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 14146, -41, 11660, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_PURPLE_MUSHROOM, 5787, 1776, -10407, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_RED_COIN, 13099, 2702, -10781, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5128, 2932, -12990, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7796, 3277, -10387, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6624, 3272, -11276, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11260, 1490, -7625, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9525, 1592, -10277, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9107, 3093, -12773, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2081, 2819, -8328, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 10605, 3619, 752, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 1137, 1838, -12176, 0, 0, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 1663, -4561, -8586, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_NONE, -10044, 87, -3591, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -10044, 87, -3591),
		OBJECT(MODEL_NONE, 1571, 605, -6542, 0, 0, 0, (40 << 24) | (11 << 16), bhvWarp),
		TERRAIN(ssl_area_1_collision),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ssl_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GRAY_MUSHROOM, 3198, 3950, -6135, 0, 0, 0, 0x00000000, bhvVTWMushroom),
		OBJECT(MODEL_GROUND_PATCH, 10592, 675, -12, -90, 0, 0, (8 << 16), bhvGroundPatch),
		OBJECT(MODEL_STAR, 3119, 5387, -8619, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 11841, 559, -5, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ssl_area_2_collision),
		MACRO_OBJECTS(ssl_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10044, 87, -3591),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

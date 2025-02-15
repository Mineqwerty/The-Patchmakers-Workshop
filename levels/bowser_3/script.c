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
#include "levels/bowser_3/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_3_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bowser_3_segment_7SegmentRomStart, _bowser_3_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _bowser_3_segment_7SegmentRomStart, _bowser_3_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_13), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_MANTLE_OF_MADNESS, mantle_of_madness_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MANTLE_OF_MADNESS_HURT, mantle_of_madness_hurt_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_LASER_TURRET, mad_laser_turret_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_LASER, mad_laser_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SPIKE_WALL, mad_spike_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND, mad_slamming_hand_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND_SHADOW, mad_slamming_hand_shadow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND_EYEBALL, mad_slamming_hand_eyeball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GROW_SCARY_WALLS_1, grow_scary_wall_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GROW_SCARY_WALLS_2, grow_scary_wall_2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CRAZY_BLOCK_1, crazy_block_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CRAZY_BLOCK_2, crazy_block_2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CRAZY_BLOCK_3, crazy_block_3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FINAL_NEEDLE, final_needle_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_3_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -2887, 1199, -108),
		OBJECT(MODEL_NONE, -2887, 1199, -108, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_CRAZY_BLOCK_1, 858, -6359, -3652, 0, 0, 0, (1 << 24) | (36 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, -11765, -6359, 3454, 0, 0, 0, (1 << 24) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, -1883, -5147, 332, 0, 0, 0, (1 << 24) | (40 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, 3081, -7271, 2991, 0, 33, 0, (1 << 24) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, 5207, -7518, 2981, 0, -54, 0, (1 << 24) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, 6849, -7281, 3014, 0, -54, 0, (1 << 24) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_1, 4216, -7281, -1955, 0, -54, 0, (1 << 24) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -7338, -6359, -3100, 0, -6, 0, (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -95, -7324, 2323, 0, -65, 0, (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -5339, -5270, -2221, 0, 13, 0, (2 << 24) | (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -11389, -6163, -1779, 0, 13, 0, (2 << 24) | (50 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -4535, -6359, -2597, 0, -6, 0, (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, -4595, -7277, -2067, 0, 50, 0, (2 << 24) | (90 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_3, -6256, -6359, 3311, 0, -6, 0, (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, 1683, -7448, 450, 0, 111, 0, (2 << 24) | (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, 1591, -7877, 1123, 0, 66, 0, (2 << 24) | (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_2, 9138, -7899, 2174, 0, 51, 0, (100 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_3, -11453, -6359, -2932, 0, 0, 0, (3 << 24) | (40 << 16) | (30 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_3, -9410, -6746, -3339, 0, 0, 0, (4 << 24) | (44 << 16) | (35 << 8), bhvCrazyBlock),
		OBJECT(MODEL_CRAZY_BLOCK_3, -5494, -5306, 1039, 0, 0, 0, (4 << 24) | (67 << 16) | (35 << 8), bhvCrazyBlock),
		OBJECT(MODEL_YARN_GOOMBA, -8560, -6359, 1547, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -9281, -6359, 2624, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -5793, -5055, -3445, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 82, -7271, 301, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_MANTLE_OF_MADNESS, 2268, 1199, 0, 0, 0, 0, 0x00000000, bhvMantleOfMadness),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 930, -7271, -205, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, -2062, -4726, 2177, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 9649, -6711, -338, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 10054, -6359, 3647, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 14202, -6304, -2634, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 14202, -6304, 2789, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 14882, -6304, -4164, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 13861, -6304, -2667, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 14682, -6304, 4099, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_YARN_SCUTTLEBUG, 13592, -6304, 2102, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_FINAL_NEEDLE, 153, 1529, 138, 0, 0, 0, 0x00000000, bhvFinalNeedle),
		TERRAIN(bowser_3_area_1_collision),
		TERRAIN_MAT_LUT(bowser_3_area_1_collision_materials),
		MACRO_OBJECTS(bowser_3_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -2887, 1199, -108),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
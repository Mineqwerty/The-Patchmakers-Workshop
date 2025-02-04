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
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_MIO0(0x7, _bowser_3_segment_7SegmentRomStart, _bowser_3_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_MANTLE_OF_MADNESS, mantle_of_madness_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MANTLE_OF_MADNESS_HURT, mantle_of_madness_hurt_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_LASER_TURRET, mad_laser_turret_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_LASER, mad_laser_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SPIKE_WALL, mad_spike_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND, mad_slamming_hand_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND_SHADOW, mad_slamming_hand_shadow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MAD_SLAMMING_HAND_EYEBALL, mad_slamming_hand_eyeball_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_3_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -2914, 1200, 0),
		OBJECT(MODEL_NONE, -2914, 1200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_MANTLE_OF_MADNESS, 2268, 1199, 0, 0, 0, 0, 0x00000000, bhvMantleOfMadness),
		TERRAIN(bowser_3_area_1_collision),
		TERRAIN_MAT_LUT(bowser_3_area_1_collision_materials),
		MACRO_OBJECTS(bowser_3_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_BOSS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -2914, 1200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
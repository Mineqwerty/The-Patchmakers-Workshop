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
#include "levels/bowser_2/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_2_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x07, _bowser_2_segment_7SegmentRomStart, _bowser_2_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_2_TILTING_ARENA, bowser_2_geo_000170), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_2_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOWSER_2, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvStringBreakController),
		MARIO_POS(0x01, 0, -5098, 1000, 0),
		OBJECT(MODEL_NONE, -5098, 1000, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BOWSER, -4380, 1000, 0, 0, 90, 0, 0x00000000, bhvBowserNpc),
		OBJECT(MODEL_PATCHMAKER, 723, 1000, 4249, 0, -180, 0, 0x00000000, bhvPatchmaker),
		TERRAIN(bowser_2_area_1_collision),
		TERRAIN_MAT_LUT(bowser_2_area_1_collision_materials),
		MACRO_OBJECTS(bowser_2_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -5098, 1000, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
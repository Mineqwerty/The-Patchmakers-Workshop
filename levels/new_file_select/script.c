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

#include "make_const_nonconst.h"
#include "levels/new_file_select/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_new_file_select_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _new_file_select_segment_7SegmentRomStart, _new_file_select_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x7, _new_file_select_segment_7SegmentRomStart, _new_file_select_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_PATCHMAKER_SHADOW, patchmaker_title_screen_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_YARN_SELECTOR_CIRCLE, yarn_selector_circle_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, new_file_select_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_PATCHMAKER_SHADOW, 482, 0, 0, 0, 90, 0, 0x00000000, bhvPatchmakerFileSelect),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 644, 144, -195, 0, 94, 0, (1 << 16), bhvFileController),
		OBJECT(MODEL_NONE, 644, 144, -155, 0, 89, 0, (2 << 16), bhvFileController),
		OBJECT(MODEL_NONE, 617, 144, -194, 0, 92, 0, (3 << 16), bhvFileController),
		OBJECT(MODEL_NONE, 617, 144, -155, 0, 92, 0, (4 << 16), bhvFileController),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 90, 0, 0x00000000, bhvNewFileSelectManager),
		TERRAIN(new_file_select_area_1_collision),
		TERRAIN_MAT_LUT(new_file_select_area_1_collision_materials),
		MACRO_OBJECTS(new_file_select_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_TITLE_SCREEN),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
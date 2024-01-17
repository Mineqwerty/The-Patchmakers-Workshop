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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CHANDELIER, chandelier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLOATING_TABLE, floating_table_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SCALING_STAIRS, scaling_stairs_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHANDELIER, 8868, 1920, -1779, 0, 28, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_CHANDELIER, 11497, 2705, -2407, 0, 90, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_CHANDELIER, 13496, 2970, 4345, 0, 90, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_YARN_GOOMBA, 4153, 981, 50, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 4153, 981, -2418, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 4682, 981, -3699, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 5392, 981, -2728, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_SCALING_STAIRS, 12177, 2777, 2144, 0, 0, 0, 0x00000000, bhvScalingStairs),
		OBJECT(MODEL_STAR, 13500, 3699, 7375, 0, -90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_FLOATING_TABLE, 11451, 2211, -3335, 0, 90, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 9943, 2342, 1224, 0, -180, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 13502, 3619, 3279, 0, -180, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 13502, 3619, 4330, 0, -90, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_NONE, 0, 620, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 620, 0),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 620, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

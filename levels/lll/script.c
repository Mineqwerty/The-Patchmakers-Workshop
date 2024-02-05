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
	LOAD_MODEL_FROM_GEO(MODEL_CLC_PUZZLE_EYE, clc_puzzle_eye_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLC_PUZZLE_SWITCH, clc_puzzle_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLC_PUZZLE_WALL, clc_puzzle_wall_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CLC_DOOR, clc_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_LLL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHANDELIER, 8868, 1920, -1779, 0, 28, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_CHANDELIER, 11497, 2705, -2407, 0, 90, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_CHANDELIER, 13496, 2970, 4345, 0, 90, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_CHANDELIER, 6172, 2551, 9123, 0, 90, 0, 0x00000000, bhvSwingingChandelier),
		OBJECT(MODEL_NONE, -2965, 4748, 11425, 0, 90, 0, (11 << 16), bhvWarp),
		OBJECT(MODEL_CLC_DOOR, 6122, 981, -2794, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 6122, 981, -2594, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -6990, 5272, -91, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -6990, 5272, 109, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -772, 1815, 9599, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -772, 1815, 9799, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -768, 4771, 7389, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, -768, 4771, 7589, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 1143, 2148, 3244, 0, 0, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 1343, 2148, 3244, 0, -180, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 1487, 476, 1136, 0, 0, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 1687, 476, 1136, 0, -180, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 6045, 5272, -91, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 6045, 5272, 109, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 3719, 2148, 1968, 0, -90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_CLC_DOOR, 3719, 2148, 2168, 0, 90, 0, 0x00000000, bhvClcDoor),
		OBJECT(MODEL_YARN_GOOMBA, 4153, 981, 50, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 4153, 981, -2418, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 4682, 981, -3699, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_CLC_PUZZLE_EYE, -9149, 5272, 398, 0, -180, 0, 0x00000000, bhvClcPuzzleEye),
		OBJECT(MODEL_CLC_PUZZLE_EYE, -8266, 5272, 2323, 0, -90, 0, (1 << 16), bhvClcPuzzleEye),
		OBJECT(MODEL_CLC_PUZZLE_EYE, -10203, 5272, 1137, 0, -180, 0, (2 << 16), bhvClcPuzzleEye),
		OBJECT(MODEL_CLC_PUZZLE_SWITCH, -10633, 5272, -446, 0, 0, 0, 0x00000000, bhvClcPuzzleSwitch),
		OBJECT(MODEL_CLC_PUZZLE_SWITCH, -12471, 5272, 436, 0, 0, 0, (1 << 16), bhvClcPuzzleSwitch),
		OBJECT(MODEL_CLC_PUZZLE_SWITCH, -8263, 5272, 4579, 0, 0, 0, (2 << 16), bhvClcPuzzleSwitch),
		OBJECT(MODEL_CLC_PUZZLE_WALL, -11971, 5272, 432, 0, 90, 0, 0x00000000, bhvClcPuzzleWall),
		OBJECT(MODEL_CLC_PUZZLE_WALL, -8267, 5272, 4192, 0, 0, 0, (1 << 16), bhvClcPuzzleWall),
		OBJECT(MODEL_CLC_PUZZLE_WALL, -10204, 5272, 4192, 0, 0, 0, (2 << 16), bhvClcPuzzleWall),
		OBJECT(MODEL_CLC_PUZZLE_WALL, -10204, 5272, 2326, 0, 0, 0, (1 << 16), bhvClcPuzzleWall),
		OBJECT(MODEL_FLOATING_TABLE, 7636, 1451, 1600, 0, -180, 0, 0x00000000, bhvSpinningTable),
		OBJECT(MODEL_FLOATING_TABLE, 3269, 1823, 5063, 0, -180, 0, 0x00000000, bhvSpinningTable),
		OBJECT(MODEL_SCALING_STAIRS, 12177, 2777, 2144, 0, 0, 0, 0x00000000, bhvScalingStairs),
		OBJECT(MODEL_STAR, 13500, 3699, 7375, 0, -90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -10192, 5487, 4689, 0, -90, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_FLOATING_TABLE, 11451, 2211, -3335, 0, 90, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 9943, 2342, 1224, 0, -180, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 13502, 3619, 3279, 0, -180, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 13502, 3619, 4330, 0, -90, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 6460, 2863, 6394, 0, -13, 0, (1 << 16), bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 2935, 2040, 8080, 0, -73, 0, 0x00000000, bhvFloatingTable),
		OBJECT(MODEL_FLOATING_TABLE, 3822, 2832, 7175, 0, 165, 0, (1 << 16), bhvFloatingTable),
		OBJECT(MODEL_NONE, 0, 620, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 620, 0),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, lll_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_LLL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YARN_GOOMBA, 927, 0, 5213, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 1477, 0, 4434, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 1369, 3942, 5472, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -3203, 4882, 3942, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 1720, 6297, 5450, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, 3259, 1601, 5703, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -1347, 2676, 6458, 0, 28, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_STAR, 20, 6612, 7001, 0, -90, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 314, 372, 4853, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(lll_area_2_collision),
		MACRO_OBJECTS(lll_area_2_macro_objs),
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

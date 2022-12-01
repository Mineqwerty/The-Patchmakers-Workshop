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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_STONE_TOWER_DOOR, stone_tower_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEAR, stone_gear_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, skybox_test_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GRAPPLE_STONE, grapple_stone_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ENEMY_OBELISK, enemy_obelisk_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FORCEFIELD, forcefield_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROTATING_STONE_CYLINDER, rotating_stone_cylinder_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 288, 1698, -7413, 0, -180, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_NONE, -202, 2355, -6701, 0, -180, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, -500, 2604, -7798, 0, -180, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, -1386, 2701, -8440, 0, -180, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, -2286, 2771, -9075, 0, -180, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, -2224, 3074, -10099, 0, -180, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, 1495, 1316, -18, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3474, 1850, -1640, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4825, 2432, 7834, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5206, 1412, 7840, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1532, 1537, 4892, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6232, 3951, 9857, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5878, 3320, 9492, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1662, 194, 1309, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2904, -253, 3193, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4286, 1453, 4728, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3760, 832, 7787, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 110, 1698, -9675, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 797, 920, 3659, 0, -180, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2365, 920, 3659, 0, -180, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2091, -489, -7277, 0, 0, 0, (30 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_ENEMY_OBELISK, -10392, 805, 9724, 0, 0, 0, 0x00000000, bhvEnemyObelisk),
		OBJECT(MODEL_GEAR, 2847, 335, -490, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, 2847, 39, -2476, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, 2847, 335, 420, 0, -135, 0, (1 << 16), bhvStoneGear),
		OBJECT(MODEL_GEAR, -5729, 679, 3134, 0, -180, 0, (2 << 16), bhvStoneGear),
		OBJECT(MODEL_GEAR, -8400, 870, 3134, 0, -180, 0, (2 << 16), bhvStoneGear),
		OBJECT(MODEL_GEAR, -6894, 789, 1677, 0, -180, 0, (3 << 16), bhvStoneGear),
		OBJECT(MODEL_GEAR, -11340, 335, -490, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, -11340, 335, 420, 0, -135, 0, (1 << 16), bhvStoneGear),
		OBJECT(MODEL_GEAR, -11340, 335, -2252, 0, -180, 0, 0x00000000, bhvStoneGear),
		OBJECT(MODEL_GEAR, -11340, 335, -1342, 0, -135, 0, (1 << 16), bhvStoneGear),
		OBJECT(MODEL_GRAPPLE_STONE, 1765, 2393, 9015, 0, -180, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 1603, 1010, 2281, 0, 90, 0, (1 << 16), bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 1603, 1010, 1389, 0, 90, 0, (1 << 16), bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 3940, 1465, 7692, 0, -90, 0, (2 << 16), bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 3294, 2751, 6846, 0, 0, 0, (2 << 16), bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 4573, 2588, 8287, 0, -180, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 5036, 2583, 8326, 0, 0, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 2192, 2463, 11019, 0, -90, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 3725, 2463, 11019, 0, -90, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_RED_COIN, 2063, 2717, 10781, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 2321, 1871, 7069, 0, -180, 0, (2 << 24) | (2 << 16), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, 4807, 2871, 6855, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6134, 1644, 8476, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4807, 2871, 8310, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6046, 3280, 8480, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3752, 2713, 10181, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3731, 2860, 9522, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3555, 3498, 6860, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_ROTATING_STONE_CYLINDER, -9069, 318, 2004, 0, -180, 0, 0x00000000, bhvRotatingStoneCylinder),
		OBJECT(MODEL_ROTATING_STONE_CYLINDER, -9069, 318, 728, 0, -180, 0, (1 << 16), bhvRotatingStoneCylinder),
		OBJECT(MODEL_ROTATING_STONE_CYLINDER, -10136, 318, 728, 0, -180, 0, (0 << 16), bhvRotatingStoneCylinder),
		OBJECT(MODEL_SKYBOX_TEST, 735, 422, 1592, 0, -180, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, -2220, 3482, -11636, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -11192, 959, -3144, 0, 90, 0, (4 << 24) | (4 << 16), bhvStar),
		OBJECT(MODEL_STONE_TOWER_DOOR, -680, 1556, -5054, 0, 0, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -680, 1556, -5054, 0, -180, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1369, 1556, -5054, 0, 0, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1369, 1556, -5054, 0, -180, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1244, 1556, -4710, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -805, 1556, -4710, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1244, 1556, -5398, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -805, 1556, -5398, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, 5734, 1435, 8464, 0, -180, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, 5734, 1435, 8464, 0, 0, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2218, 3082, -11254, 0, 90, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2218, 3082, -11254, 0, -90, 0, 0x00000000, bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -1999, 3082, -11942, 0, -90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_STONE_TOWER_DOOR, -2437, 3082, -11942, 0, 90, 0, (2 << 16), bhvStoneTowerDoor),
		OBJECT(MODEL_NONE, 0, 684, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 684, 0),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STONE_TERRACE_CITY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GRAPPLE_STONE, -1194, 1782, -79, 0, 0, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, -9, 2432, -2038, 0, -90, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 1411, 2603, -1727, 0, 180, 0, 0x00000000, bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, 781, 2721, 600, 0, 90, 0, (1 << 16), bhvGrappleStone),
		OBJECT(MODEL_GRAPPLE_STONE, -1336, 2901, 1741, 0, -180, 0, (1 << 16), bhvGrappleStone),
		OBJECT(MODEL_STAR, -1795, 3112, 1741, 0, -180, 0, (1 << 24) | (1 << 16), bhvStar),
		OBJECT(MODEL_NONE, -2035, 4645, 1077, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STONE_TERRACE_CITY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 684, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

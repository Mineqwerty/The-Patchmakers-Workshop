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
#include "levels/ddd/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ddd_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_AWNING, awning_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, hvh_skybox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_REGULAR_TABLE, regular_table_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSHROOM_TABLE, mushroom_table_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_FLOWER, red_flower_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_DDD, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_AWNING, -2693, 729, -1014, 0, 0, 0, 0x00000000, bhvAwning),
		OBJECT(MODEL_AWNING, -4803, 729, -1014, 0, 0, 0, 0x00000000, bhvAwning),
		OBJECT(MODEL_AWNING, -4803, 729, 395, 0, -180, 0, 0x00000000, bhvAwning),
		OBJECT(MODEL_AWNING, -2670, 729, 395, 0, -180, 0, 0x00000000, bhvAwning),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -3603, 711, -6161, 0, -145, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, 1649, 303, 4053, 0, -180, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX_SMALL, -3032, 711, -6692, 0, -180, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_CANNON_BARREL, -5784, 2390, 1074, 84, -180, 0, 0x00000000, bhvHiddenCannon),
		OBJECT(MODEL_METAL_BOX, 2513, 752, -125, 0, -180, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_PODOGOO, 2326, 619, -2554, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, 2644, 676, -3525, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -10554, 303, -1736, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -11715, 303, -3261, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -8761, 303, 10767, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -11826, 303, 11828, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_RED_FLOWER, -2218, 483, 572, 0, 0, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, -263, 475, 8574, 0, 114, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, -9251, 627, 7813, 0, 54, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, -3241, 711, -6387, 0, 152, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, 2427, 1044, 637, 0, 47, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, 305, 1437, -5230, 0, 16, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, 1078, 1462, 7182, 0, 58, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_RED_FLOWER, -3925, 303, 13546, 0, 157, 0, 0x00000000, bhvRedFlower),
		OBJECT(MODEL_SKYBOX_TEST, -207, 264, 1112, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, -3228, 4854, -6392, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 1168, 552, 3974, 0, -180, 0, (2 << 24) | (8 << 16), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -11016, -926, 8649, 0, -180, 0, (11 << 16), bhvWarp),
		OBJECT_WITH_ACTS(MODEL_NONE, 11397, 1743, -97, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp, ACT_1),
		MARIO_POS(0x01, 0, 11397, 1743, -97),
		OBJECT_WITH_ACTS(MODEL_NONE, -919, 493, -213, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		TERRAIN(ddd_area_1_collision),
		MACRO_OBJECTS(ddd_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HIDDEN_VILLAGE_HOLD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ddd_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_METAL_BOX, 3764, 1883, 1554, 0, -22, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_GROUND_PATCH, 692, -12, -1343, -90, 0, 0, (6 << 16), bhvGroundPatch),
		OBJECT(MODEL_PODOGOO, 2301, 4269, 1167, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, 2705, 4269, 770, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -897, 4398, -319, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_PODOGOO, -3178, 4269, -374, 0, -180, 0, 0x00000000, bhvPodogoo),
		OBJECT(MODEL_TRANSMUTATION_STAR, -5825, 5813, -782, 0, 90, 0, (1 << 24), bhvTransmutationStar),
		OBJECT(MODEL_REGULAR_TABLE, 5195, 1883, 1699, 0, 0, 0, 0x00000000, bhvTransmutationTable),
		OBJECT(MODEL_METAL_BOX, 2098, 1883, 878, 0, -22, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_REGULAR_TABLE, 3654, 3187, 1676, 0, 0, 0, 0x00000000, bhvTransmutationTable),
		OBJECT(MODEL_REGULAR_TABLE, -3461, 4269, -852, 0, 0, 0, 0x00000000, bhvTransmutationTable),
		OBJECT_WITH_ACTS(MODEL_NONE, -2649, -802, -1030, 0, 69, 0, 0x000A0000, bhvSpinAirborneWarp, ACT_1),
		TERRAIN(ddd_area_2_collision),
		MACRO_OBJECTS(ddd_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HIDDEN_VILLAGE_HOLD),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 11397, 1743, -97),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

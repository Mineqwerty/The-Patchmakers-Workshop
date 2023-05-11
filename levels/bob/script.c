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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOUNCE_BULB, bounce_bulb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOUNCE_BULB_OPEN, bounce_bulb_open_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PTOOIE, ptooie_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIKE_BALL, spike_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROSEDRIFT, rosedrift_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN_POKEY_1, pushpin_pokey_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN_POKEY_2, pushpin_pokey_2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN_POKEY_3, pushpin_pokey_3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN, pushpin_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN_POKEY_SEGMENT_HEAD, segment_head_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHPIN_POKEY_SEGMENT_BODY, segment_body_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FALLING_WIND, falling_wind_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_IMPACT_HIT, impact_hit_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, ttc_skybox_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BOB, 0x02, 0x0A, WARP_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_NONE, -3607, 39, 297, 0, 0, 0, 0x00000000, bhvPokeyBossWalls, ACT_6),
		OBJECT_WITH_ACTS(MODEL_BOUNCE_BULB, 1652, 684, -4276, 0, 0, 0, 0x00000000, bhvBounceBulb, ACT_1 | ACT_2 | ACT_3),
		OBJECT(MODEL_BOUNCE_BULB, -4878, 1864, -12169, 0, 90, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, -5523, 2720, -12227, 0, 90, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 3478, 1131, -11359, 0, 59, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 2186, 2281, -10475, 0, 67, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 2499, -83, -11909, 0, 143, 0, 0x00000000, bhvBounceBulb),
		OBJECT_WITH_ACTS(MODEL_BOUNCE_BULB, 1652, 684, -4276, 0, 0, 0, 0x00000000, bhvBounceBulb, ACT_4 | ACT_5),
		OBJECT(MODEL_NONE, 1336, 995, -1326, 0, 157, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -4476, 1979, -8011, 0, 151, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 830, 2138, 1364, 0, 104, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1804, 3087, 2041, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2616, 312, -3183, 0, 139, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6918, 1955, -4941, 0, 102, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1848, 277, -8345, 0, 114, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5005, 4015, 3527, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -9187, 199, 2087, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5021, 612, -8547, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3809, 1758, -3551, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1895, 38, -11111, 0, 90, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3275, 118, -1564, 0, 0, 180, 0x30210000, bhvWarp),
		OBJECT(MODEL_NONE, 7610, 47, -6379, 0, 0, 180, 0x30200000, bhvWarp),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -105, 373, -1390, 0, 0, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -577, 236, -733, 0, 53, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -105, 373, -1390, 0, 0, 0, 0x00000000, bhvGoomba, ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -577, 236, -733, 0, 53, 0, 0x00000000, bhvGoomba, ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, -979, 501, -1927, 0, -74, 0, (0 << 24) | (20 << 16), bhvRosedriftCutscene, ACT_6),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, -911, 447, -1596, 0, -42, 0, (0 << 24) | (20 << 16), bhvRosedriftCutscene, ACT_6),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, -469, 477, -1591, 0, 14, 0, (0 << 24) | (21 << 16), bhvRosedriftCutscene, ACT_6),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -1394, 2201, -7960, 0, 0, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -3807, 1817, -12997, 0, 0, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -3164, 1704, -12378, 0, 0, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_YARN_GOOMBA, -3663, 1780, -12553, 0, -40, 0, 0x00000000, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		MARIO_POS(0x01, 0, 0, 404, 0),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, 730, 1689, 996, 0, 12, 0, 0x00000000, bhvPtooie, ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, 3319, 2859, 1534, 0, 42, 0, 0x00000000, bhvPtooie, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, 4983, 2859, 105, 0, 42, 0, 0x00000000, bhvPtooie, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT(MODEL_PTOOIE, 4570, 3954, 1500, 0, 42, 0, 0x00000000, bhvPtooie),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, -862, 1469, -4682, 0, 24, 0, 0x00000000, bhvPtooie, ACT_4 | ACT_5),
		OBJECT(MODEL_PTOOIE, -2594, 2255, -7969, 0, 88, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, -5281, 3647, -10926, 0, 88, 0, 0x00000000, bhvPtooie),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, 730, 1689, 996, 0, 12, 0, 0x00000000, bhvPtooie, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_PTOOIE, -862, 1469, -4682, 0, 24, 0, 0x00000000, bhvPtooie, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_PUSHPIN_POKEY_1, -361, 422, -1955, 0, -74, 0, (0 << 24) | (0 << 16), bhvPushpinPokey, ACT_6),
		OBJECT(MODEL_RED_COIN, -3312, 1784, -4399, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -5650, 4186, -10361, 0, 0, 0, (2 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -5537, 2533, -6239, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1391, 2253, -9191, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5300, 1830, -9614, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4314, 2501, -5312, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5849, 3480, -12255, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 586, 1838, -8032, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3398, 1913, -13057, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, -2361, 140, 1084, 0, -74, 0, (0 << 24) | (0 << 16), bhvGenericNPC, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, 5166, 1033, -3303, 0, -74, 0, (1 << 16), bhvGenericNPC, ACT_1 | ACT_2 | ACT_3),
		OBJECT(MODEL_ROSEDRIFT, -4835, 1862, -11743, 0, -179, 0, (2 << 16), bhvGenericNPC),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, -2361, 140, 1084, 0, -74, 0, (0 << 24) | (0 << 16), bhvGenericNPC, ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_ROSEDRIFT, 5166, 1033, -3303, 0, -74, 0, (1 << 16), bhvGenericNPC, ACT_4 | ACT_5),
		OBJECT(MODEL_SKYBOX_TEST, -3643, 100, 1649, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, 4740, 4155, 1842, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2633, 4205, -11776, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_NONE, 1648, 1076, -4289, 0, 157, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2497, 299, -11916, 0, 157, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4879, 2368, -12186, 0, 157, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5527, 3013, -12227, 0, 157, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1963, 2569, -9221, 0, 157, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3656, 100, 1731, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -14507, -286, -425, 0, 0, 0, 0x00010000, bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -2781, 4, -17, 0, 90, 0, (0 << 16), bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, -2781, 4, -200, 0, 90, 0, (0 << 16), bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_NONE, -2781, 4, 185, 0, 90, 0, (0 << 16), bhvParticleCrashingWaterSpawner),
		OBJECT(MODEL_MIST, 1413, -156, 3, 0, 0, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_NONE, -2784, -2300, 8, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_NONE, 4435, -111, 3, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_NONE, -7029, 828, -178, 0, 90, 0, (10 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, 575, 115, 2, 0, 0, 0, (4 << 16), bhvStar),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND_WATERWORKS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 404, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

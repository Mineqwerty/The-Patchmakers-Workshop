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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, gss_skybox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLD_CLOUD, gold_cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GODDESS, goddess_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TORCH_HOLDER, torch_holder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TORCH_HOLDER_LIT, torch_holder_lit_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLAME_PUZZLE_BARRIER, flame_puzzle_barrier_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HALO_SWITCH, halo_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPEKTURR, spekturr_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STAR_GATE, star_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLING_RING, fling_ring_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLD_BLOB, gold_blob_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLD_SWORD, gold_sword_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLD_FRAGMENT, gold_fragment_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_CCM, 0x01, 0x11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_SKYBOX_TEST, -207, 264, 1112, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, -5490, 3238, -4979, 0, 76, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, -5932, 3308, -6232, 0, 146, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 4758, 1560, -121, 0, -87, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 5350, 1664, 904, -45, 2, -2, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 5828, 2710, 3687, -90, 0, -3, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 6535, 4307, 3711, 0, 93, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 11450, 4945, 3892, -45, -90, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 5350, 2059, 2055, -45, 2, -2, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_FLING_RING, 10608, 5456, 3892, -90, -90, 0, 0x00000000, bhvFlingRing, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT(MODEL_GOLD_BLOB, 21, 100, -790, 0, 0, 0, 0x00000000, bhvGoldBlob),
		OBJECT(MODEL_GOLD_CLOUD, 582, -1229, -6416, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -6282, -669, -9874, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -10764, 638, -5307, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -11227, 758, -3921, 0, -49, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -13058, 500, -5076, 0, 36, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -11977, 185, -6424, 0, 176, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -12289, 332, -3378, 0, 110, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -10921, -300, -7906, 0, -47, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -5216, -1251, -10035, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, 7807, 1645, -1138, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, 6752, 1214, -6419, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, 9797, 3768, 3827, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_NONE, 9497, 2492, -4571, 0, 0, 0, (40 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 7701, 694, -5940, 0, 0, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 7342, 750, -6122, 0, 0, 0, (100 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_RED_COIN, 8959, 3098, -3552, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 11496, -795, -8042, 0, 0, 0, (4 << 24) | (4 << 16), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, 9498, 3119, -4605, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7669, 1622, -5951, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7315, 2152, -6025, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9287, 1415, -6159, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7427, 410, -8125, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9293, 464, -8399, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9836, -646, -8632, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -11224, 1477, 1560, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9559, 6571, 3716, 0, 0, 0, (4 << 24) | (4 << 16), bhvStar),
		OBJECT_WITH_ACTS(MODEL_STAR_GATE, -6342, 3801, -5384, 0, 0, 0, 0x00000000, bhvStarGate, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_NONE, -6342, 3801, -5384, 0, 0, 0, 0x00100000, bhvSpinAirborneWarp, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_STAR_GATE, 5505, 2011, -82, 0, 0, 0, 0x00000000, bhvStarGate, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_NONE, 5505, 2011, -82, 0, 0, 0, 0x00110000, bhvSpinAirborneWarp, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT(MODEL_TORCH_HOLDER, 1064, 100, -922, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -905, 100, -955, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -3188, -657, -11884, 0, 0, 0, (1 << 16), bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, 8959, 2863, -3552, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, 8341, 2862, -3528, 0, 0, 0, (1 << 16), bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, 9249, 332, -8261, 105, -2, -4, (1 << 16), bhvTorchHolder),
		OBJECT(MODEL_NONE, -201, 2791, 7299, 0, -47, 0, (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 0, 200, 1208, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 1208),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_GOLD_SOAKED_SKY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x03, 0, 0, 0),
		WARP_NODE(0x11, LEVEL_CCM, 0x01, 0x10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_TORCH_HOLDER, 5785, -9276, 2245, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -903, -9440, 12456, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -9994, -8842, 1720, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -8761, -9322, -9120, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, 7571, -9242, -10747, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT_WITH_ACTS(MODEL_NONE, -2295, -8764, 493, 0, 0, 0, (1 << 16), bhvWillOWispSpawner, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_NONE, -2028, -8587, -345, 0, 0, 0, (3 << 24) | (3 << 16), bhvGSSHiddenStar, ACT_4),
		OBJECT_WITH_ACTS(MODEL_STAR_GATE, -6342, -8511, -5384, 0, 0, 0, 0x00100000, bhvStarGate, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_STAR_GATE, 5505, -8667, -82, 0, 0, 0, 0x00110000, bhvStarGate, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(MODEL_NONE, -2573, -8601, -752, 0, 0, 0, 0x00000000, bhvWillOWispSpawner, ACT_2),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_GOLD_SOAKED_SKY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ccm_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x01, 0x03, 0, 0, 0),
		OBJECT(MODEL_TORCH_HOLDER, -3122, -9863, 4447, 0, 0, 0, 0x00000000, bhvTorchHolder),
		OBJECT(MODEL_TORCH_HOLDER, -4483, -9863, 4447, 0, 0, 0, (1 << 16), bhvTorchHolder),
		OBJECT(MODEL_FLAME_PUZZLE_BARRIER, -3767, -9863, 3495, 0, 0, 0, 0x00000000, bhvFlamePuzzleBarrier),
		OBJECT(MODEL_FLAME_PUZZLE_BARRIER, -1820, -9234, -3776, 0, 0, 0, (1 << 16), bhvFlamePuzzleBarrier),
		OBJECT(MODEL_HALO_SWITCH, -1681, -9214, -2556, 0, 0, 0, 0x00000000, bhvHaloSwitch),
		OBJECT(MODEL_STAR, -1873, -8971, -7362, 0, 0, 0, (1 << 24) | (1 << 16), bhvStar),
		TERRAIN(ccm_area_3_collision),
		MACRO_OBJECTS(ccm_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, ccm_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GODDESS, -100, 852, 2279, 0, -180, 0, 0x00000000, bhvGoddessBoss),
		OBJECT(MODEL_GOLD_BLOB, 460, -400, -4878, 0, 0, 0, 0x00000000, bhvGoldBlob),
		OBJECT(MODEL_GOLD_BLOB, -619, -400, -4878, 0, 0, 0, 0x00000000, bhvGoldBlob),
		OBJECT(MODEL_GOLD_BLOB, 2026, -400, -4878, 0, 0, 0, 0x00000000, bhvGoldBlob),
		OBJECT(MODEL_NONE, -651, -303, -2230, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_4_collision),
		MACRO_OBJECTS(ccm_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_BOSS_KOOPA_FINAL),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 1208),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

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
#include "levels/pss/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_PAPER_SCUTTLEBUG, paper_scuttlebug_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIFT_CLOUD, lift_cloud_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIFT_CLOUD_SWITCH, lift_cloud_switch_geo), /* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pss_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x45, LEVEL_CASTLE, 0x02, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (1 << 16), bhvPatchChallengeController),
		OBJECT(MODEL_STAR, -12264, -433, 0, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(pss_area_1_collision),
		TERRAIN_MAT_LUT(pss_area_1_collision_materials),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, pss_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x45, LEVEL_CASTLE, 0x02, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -12352, -494, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (2 << 16), bhvPatchChallengeController),
		OBJECT(MODEL_STAR, 13906, 1449, 0, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -9385, -433, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -6292, -703, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -4809, -703, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -4098, -604, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -3426, -512, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -1895, -104, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -2102, 551, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -3556, 1130, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -6845, 1942, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -4143, 2841, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 79, 2996, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 961, 2516, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 1836, 2804, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 2550, 2286, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 5540, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 5840, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 6140, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 5240, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 6440, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 6740, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 7040, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 7340, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 7640, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -6765, -770, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, -1386, 224, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 7940, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 8240, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 8540, 1173, 0, 0, 0, 0, (1 << 16), bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 12613, 65, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		OBJECT(MODEL_PAPER_SCUTTLEBUG, 13012, 502, 0, 0, 0, 0, 0x00000000, bhvPaperScuttlebug),
		TERRAIN(pss_area_2_collision),
		TERRAIN_MAT_LUT(pss_area_2_collision_materials),
		MACRO_OBJECTS(pss_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, pss_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x45, LEVEL_CASTLE, 0x02, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -12317, -548, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (3 << 16), bhvPatchChallengeController),
		OBJECT(MODEL_STAR, 12881, -1285, 0, 0, 0, 0, (2 << 24), bhvStar),
		TERRAIN(pss_area_3_collision),
		TERRAIN_MAT_LUT(pss_area_3_collision_materials),
		MACRO_OBJECTS(pss_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, pss_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x45, LEVEL_CASTLE, 0x02, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -12317, -548, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_LIFT_CLOUD, -8172, -521, 0, 0, 0, 0, 0x00000000, bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, -7527, -442, -100, 0, 0, 0, 0x00000000, bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, -4892, 1376, -100, 0, 0, 0, (1 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 2286, 278, -100, 0, 0, 0, (2 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 1487, 1722, -115, 0, 0, 0, (3 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 2766, 2879, -115, 0, 0, 0, (4 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 3592, 3982, -115, 0, 0, 0, (5 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 4861, 4535, -115, 0, 0, 0, (6 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD_SWITCH, 7435, 6261, -115, 0, 0, 0, (7 << 16), bhvLiftCloudSwitch),
		OBJECT(MODEL_LIFT_CLOUD, -5378, 848, 0, 0, 0, 0, (1 << 24) | (1 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 1971, -198, 0, 0, 0, 0, (2 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 1971, 1239, 0, 0, 0, 0, (3 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 1971, 2639, 0, 0, 0, 0, (4 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 4019, 3795, 0, 0, 0, 0, (1 << 24) | (5 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 5487, 4262, 0, 0, 0, 0, (1 << 24) | (6 << 16), bhvLiftCloud),
		OBJECT(MODEL_LIFT_CLOUD, 7017, 5481, 95, 0, 0, 0, (1 << 24) | (7 << 16), bhvLiftCloud),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (4 << 16), bhvPatchChallengeController),
		OBJECT(MODEL_STAR, 11547, 6052, 0, 0, 0, 0, (5 << 24), bhvStar),
		TERRAIN(pss_area_4_collision),
		TERRAIN_MAT_LUT(pss_area_4_collision_materials),
		MACRO_OBJECTS(pss_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, pss_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x45, LEVEL_CASTLE, 0x02, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_PSS, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -13055, 2800, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (5 << 16), bhvPatchChallengeController),
		OBJECT(MODEL_STAR, -13872, 9370, 0, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_NONE, 0, 2137, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 538, 2612, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 1517, 2612, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 6662, 4831, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -9156, 6251, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -11344, 7066, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -14397, 7854, 0, 0, 0, 0, (132 << 16), bhvPoleGrabbing),
		TERRAIN(pss_area_5_collision),
		TERRAIN_MAT_LUT(pss_area_5_collision_materials),
		MACRO_OBJECTS(pss_area_5_macro_objs),
		STOP_MUSIC(0),
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
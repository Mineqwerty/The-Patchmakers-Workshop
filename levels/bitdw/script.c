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
#include "levels/bitdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_DRY_BONES, dry_bones_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOWSER_1, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -15071, 200, 0),
		OBJECT(MODEL_NONE, -15071, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BOO, -3331, 805, 3671, 0, -90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5018, 671, 5130, 0, -122, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -712, 165, -10038, 0, -92, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -1802, 349, -9522, 0, -106, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2703, 349, -9956, 0, -74, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 12068, -5783, -8301, 0, -160, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 11299, -5827, -9176, 0, 53, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 10801, -5320, -7744, 0, 78, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 12154, -4531, -10422, 0, 78, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 12884, -3095, -6923, 0, 78, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 14077, -979, -8695, 0, 78, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_NONE, 861, -3133, -4061, 0, -74, 0, 0x00000000, bhvMemoryCutsceneController),
		OBJECT(MODEL_DRY_BONES, -9174, 553, 4837, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 13625, -6059, -8181, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 1396, -838, 1903, 0, -90, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 69, -643, 2036, 0, 27, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, -4459, -1754, -2162, 0, 100, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 1594, -2082, -8684, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 894, -2082, -8877, 0, -44, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 2553, -1894, -11260, 0, -44, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 3228, -1894, -11256, 0, 65, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 2227, -1894, -11256, 0, -58, 0, (1 << 16), bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 5000, -2082, -10742, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 12521, -6059, -6729, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 14155, -3882, -8473, 0, -90, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_DRY_BONES, 11126, -2804, -7360, 0, 61, 0, 0x00000000, bhvDryBones),
		OBJECT(MODEL_YARN_KOOPA, -6937, 553, 4330, 0, -90, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 3419, -237, 8737, 0, -90, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 3485, -2082, -8930, 0, -90, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 2995, -2082, -10100, 0, -90, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 2369, -2082, -8672, 0, -169, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 12981, -6059, -8682, 0, -169, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_YARN_KOOPA, 12914, -6059, -7730, 0, -169, 0, 0x00000000, bhvKoopa),
		TERRAIN(bitdw_area_1_collision),
		TERRAIN_MAT_LUT(bitdw_area_1_collision_materials),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -15071, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
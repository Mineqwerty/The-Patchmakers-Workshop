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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_SKYBOX_TEST, -207, 264, 1112, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_GOLD_CLOUD, 81, 668, -13950, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -3719, -724, -8203, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -10764, 638, -5307, 0, 0, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -11227, 758, -3921, 0, -49, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -13058, 500, -5076, 0, 36, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -12020, 1100, -6076, 0, 176, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -12289, 332, -3378, 0, 110, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_GOLD_CLOUD, -11816, 1360, -7839, 0, -47, 0, 0x00000000, bhvGoldCloud),
		OBJECT(MODEL_NONE, -11580, 1562, -9699, 0, -47, 0, (11 << 16), bhvWarp),
		OBJECT(MODEL_STAR, -11224, 1477, 1560, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 1208, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 1208),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ccm_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GODDESS, -100, 852, 2279, 0, -180, 0, 0x00000000, bhvGoddessBoss),
		OBJECT(MODEL_NONE, -651, -303, -2230, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_3_collision),
		MACRO_OBJECTS(ccm_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
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

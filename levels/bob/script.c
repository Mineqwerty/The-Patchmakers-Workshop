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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BOB, 0x02, 0x0A, WARP_CHECKPOINT),
		OBJECT(MODEL_BOUNCE_BULB, 1652, 684, -4276, 0, 0, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, -4878, 1864, -12169, 0, 90, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, -5523, 2720, -12227, 0, 90, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 3478, 1131, -11359, 0, 59, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 2186, 2281, -10475, 0, 67, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_BOUNCE_BULB, 2499, -83, -11909, 0, 143, 0, 0x00000000, bhvBounceBulb),
		OBJECT(MODEL_NONE, 7610, 47, -6379, 0, 0, 180, 0x30200000, bhvWarp),
		OBJECT(MODEL_YARN_GOOMBA, -105, 373, -1390, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YARN_GOOMBA, -577, 236, -733, 0, 53, 0, 0x00000000, bhvGoomba),
		MARIO_POS(0x01, 0, -3651, 181, 1728),
		OBJECT(MODEL_PTOOIE, 730, 1689, 996, 0, 12, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, 3319, 2859, 1534, 0, 42, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, 4983, 2859, 105, 0, 42, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, 4570, 3954, 1500, 0, 42, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, -862, 1469, -4682, 0, 24, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, -2594, 2255, -7969, 0, 88, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_PTOOIE, -5281, 3647, -10926, 0, 88, 0, 0x00000000, bhvPtooie),
		OBJECT(MODEL_RED_COIN, -3312, 1784, -4399, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -5650, 4186, -10361, 0, 0, 0, (2 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -5537, 2533, -6239, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1391, 2253, -9191, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5300, 1830, -9614, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4314, 2501, -5312, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5849, 3480, -12255, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 586, 1838, -8032, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3398, 1913, -13057, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 4740, 4155, 1842, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2633, 4205, -11776, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_NONE, -1430, 1525, -4458, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -14507, -286, -425, 0, 0, 0, 0x00010000, bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -3651, 181, 1728),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

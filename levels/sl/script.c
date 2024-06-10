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
#include "levels/sl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _sl_segment_7SegmentRomStart, _sl_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_FLOATING_TILTING_GEM, floating_tilting_gem_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ABYSS_SWIMMER, abyss_swimmer_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SKYBOX_TEST, ea_skybox_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ABYSS_URCHIN, abyss_urchin_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TENTACLE_CAGE, tentacle_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CAGE_EYE, cage_eye_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -12407, 4642, 5259, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -12555, 4397, 4102, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -12125, 4362, 2881, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -7838, 3286, 11265, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -12108, 4581, 1696, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -12413, 4975, 1637, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -11210, 6193, 214, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -10243, 6077, 114, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -9555, 6274, -453, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 5502, -3832, 10952, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 6162, -3284, 11196, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 5699, -2847, 10506, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -2941, -958, 8810, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -3945, 1080, 5599, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 5705, -1578, 2405, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 4654, -1485, 1141, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 6238, -4088, 11423, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -3263, 1107, 4656, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -2404, 1889, 2970, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -1451, 4901, 4535, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, -640, 5174, 4156, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_FLOATING_TILTING_GEM, 1071, 9716, 244, 0, 0, 0, 0x00000000, bhvFloatingTiltingGem),
		OBJECT(MODEL_NONE, -4492, -1508, 5324, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -5498, -1778, 5536, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -4587, -1778, 5977, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -3902, -1076, 6308, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -3999, -858, 11750, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -4008, -35, 11399, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -6049, -2758, 1337, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -1465, 5186, 3041, 0, 0, 0, 0x00D20000, bhvPoleGrabbing),
		OBJECT(MODEL_RED_COIN, -599, 11251, 4111, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -2776, 10763, 776, 0, 0, 0, (2 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -522, 10529, 7453, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2471, 8359, 5205, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1886, 8325, 2893, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -625, 5597, 4151, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -390, 8765, 1140, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -777, 10060, 4367, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1086, 10022, 255, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SKYBOX_TEST, 239, 136, 215, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, -8679, 7060, -1312, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_ABYSS_SWIMMER, -4316, -974, 7129, 0, 14, 0, 0x00000000, bhvAbyssSwimmer),
		OBJECT(MODEL_ABYSS_SWIMMER, -4769, 2800, 10959, 0, -92, 0, (1 << 16), bhvAbyssSwimmer),
		OBJECT(MODEL_ABYSS_SWIMMER, -4782, -2723, 4015, 0, -150, 0, (2 << 16), bhvAbyssSwimmer),
		OBJECT(MODEL_ABYSS_SWIMMER, -855, 2309, 4118, 0, 85, 0, (3 << 16), bhvAbyssSwimmer),
		OBJECT(MODEL_ABYSS_URCHIN, 6002, -4362, 9125, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_NONE, 6965, -3288, 777, 0, 0, 0, (60 << 24) | (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -4982, -1753, 5895, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -4982, -1753, 5895),
		TERRAIN(sl_area_1_collision),
		MACRO_OBJECTS(sl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, sl_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_TENTACLE_CAGE, -213, 3244, 343, 0, 0, 0, (5 << 16), bhvTentacleCage),
		OBJECT(MODEL_SKYBOX_TEST, -4128, 1433, 3923, 0, 0, 0, 0x00000000, bhvBackgroundObject),
		OBJECT(MODEL_STAR, -213, 3530, 343, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_ABYSS_URCHIN, 3474, 3565, -1327, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, 1498, 4300, -4863, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, 2021, 4300, -4718, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, -2849, 3565, 1139, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, 271, 3761, 5319, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, -985, 3853, 5199, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_ABYSS_URCHIN, -1175, 3461, -1886, 0, 0, 0, 0x00000000, bhvAbyssUrchin),
		OBJECT(MODEL_NONE, -1452, 7172, -165, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(sl_area_2_collision),
		MACRO_OBJECTS(sl_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -4982, -1753, 5895),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
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
		OBJECT(MODEL_STAR, -8679, 7060, -1312, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_ABYSS_SWIMMER, -4316, -974, 7129, 0, 14, 0, 0x00000000, bhvAbyssSwimmer),
		OBJECT(MODEL_ABYSS_SWIMMER, -4769, 2800, 10959, 0, -92, 0, (1 << 16), bhvAbyssSwimmer),
		OBJECT(MODEL_NONE, -4982, -1753, 5895, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -4982, -1753, 5895),
		TERRAIN(sl_area_1_collision),
		MACRO_OBJECTS(sl_area_1_macro_objs),
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

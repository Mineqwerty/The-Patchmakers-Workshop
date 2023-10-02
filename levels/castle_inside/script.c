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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_STC_DOOR_RIGHT, stc_entrance_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STC_DOOR_LEFT, stc_entrance_door2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RDR_GARAGE_DOOR, garage_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_STAR_UNLOCK_PLATFORM, star_unlock_platform_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1F, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -1905, 191, -31, 0, 0, 0, 0x050B0000, bhvWarp),
		OBJECT(MODEL_NONE, -3127, 100, -1049, 0, 0, 0, 0x050C0000, bhvWarp),
		OBJECT(MODEL_NONE, -3127, 100, -1599, 0, 0, 0, 0x050D0000, bhvWarp),
		OBJECT(MODEL_NONE, -2014, 100, -1225, 0, 0, 0, 0x051F0000, bhvPaintingDeathWarp),
		OBJECT(MODEL_NONE, -1004, 1808, 590, 0, 0, 0, 0x050E0000, bhvWarp),
		OBJECT(MODEL_SEWNIA, -217, 100, -1359, 0, 0, 0, 0x00000000, bhvSewnia),
		OBJECT(MODEL_NONE, 5373, 554, -1303, 0, 0, 0, 0x050F0000, bhvWarp),
		OBJECT(MODEL_STC_DOOR_RIGHT, 3889, 554, 2488, 0, 0, 0, 0x00000000, bhvStcDoor),
		OBJECT(MODEL_STC_DOOR_LEFT, 3889, 554, 2906, 0, 0, 0, (1 << 16), bhvStcDoor),
		OBJECT(MODEL_RDR_GARAGE_DOOR, -4862, 0, 1245, 0, 0, 0, 0x00000000, bhvGarageDoor),
		OBJECT(MODEL_NONE, -2096, 100, -508, 0, 0, 0, 0x00000000, bhvSewniaStoppingPoint),
		OBJECT(MODEL_NONE, -4134, 100, -1677, 0, 0, 0, (1 << 16), bhvSewniaStoppingPoint),
		OBJECT(MODEL_NONE, 4862, 554, 357, 0, 0, 0, (2 << 16), bhvSewniaStoppingPoint),
		OBJECT(MODEL_NONE, 510, 1699, 255, 0, 0, 0, (2 << 16), bhvSewniaStoppingPoint),
		OBJECT(MODEL_STAR_UNLOCK_PLATFORM, -4862, 0, 731, 0, 0, 0, (0 << 24) | (1 << 16), bhvStarUnlockPlatform),
		OBJECT(MODEL_STAR_UNLOCK_PLATFORM, 4443, 554, 2697, 0, -90, 0, (0 << 24) | (2 << 16), bhvStarUnlockPlatform),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
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

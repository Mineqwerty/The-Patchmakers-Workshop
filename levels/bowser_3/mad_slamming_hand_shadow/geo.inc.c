#include "src/game/envfx_snow.h"

const GeoLayout mad_slamming_hand_shadow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, mad_slamming_hand_shadow_Circle_001_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

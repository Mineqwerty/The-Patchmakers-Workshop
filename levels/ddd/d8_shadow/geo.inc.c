#include "src/game/envfx_snow.h"

const GeoLayout d8_shadow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, d8_shadow_Circle_007_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

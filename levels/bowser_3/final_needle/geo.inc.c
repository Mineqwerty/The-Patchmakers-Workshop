#include "src/game/envfx_snow.h"

const GeoLayout final_needle_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, final_needle_Circle_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

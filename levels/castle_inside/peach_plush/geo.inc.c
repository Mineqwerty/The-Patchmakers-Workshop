#include "src/game/envfx_snow.h"

const GeoLayout peach_plush_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, peach_plush_Peach_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, peach_plush_Peach_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

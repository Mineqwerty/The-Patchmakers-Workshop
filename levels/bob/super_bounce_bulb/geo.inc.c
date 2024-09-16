#include "src/game/envfx_snow.h"

const GeoLayout super_bounce_bulb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, super_bounce_bulb_Circle_019_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, super_bounce_bulb_Circle_019_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

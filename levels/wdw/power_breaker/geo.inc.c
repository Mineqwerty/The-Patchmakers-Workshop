#include "src/game/envfx_snow.h"

const GeoLayout power_breaker_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, power_breaker_power_breaker_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout gilded_star_g_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gilded_star_g_Circle_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout sky_slug_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sky_slug_Circle_009_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sky_slug_Circle_009_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sky_slug_Circle_009_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

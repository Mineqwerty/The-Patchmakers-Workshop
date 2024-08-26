#include "src/game/envfx_snow.h"

const GeoLayout rocket_flower_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rocket_flower_Plane_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rocket_flower_Plane_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

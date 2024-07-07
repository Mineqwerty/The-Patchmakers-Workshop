#include "src/game/envfx_snow.h"

const GeoLayout rocket_flower_rotated_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rocket_flower_rotated_Plane_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rocket_flower_rotated_Plane_001_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

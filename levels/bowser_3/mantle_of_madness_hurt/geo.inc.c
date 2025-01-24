#include "src/game/envfx_snow.h"

const GeoLayout mantle_of_madness_hurt_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mantle_of_madness_hurt_Plane_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mantle_of_madness_hurt_Plane_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

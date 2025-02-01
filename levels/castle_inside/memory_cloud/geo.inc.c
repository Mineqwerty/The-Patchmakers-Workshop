#include "src/game/envfx_snow.h"

const GeoLayout memory_cloud_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, memory_cloud_Sphere_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

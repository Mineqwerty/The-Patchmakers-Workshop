#include "src/game/envfx_snow.h"

const GeoLayout gold_cloud_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gold_cloud_Cube_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

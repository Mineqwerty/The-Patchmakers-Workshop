#include "src/game/envfx_snow.h"

const GeoLayout triangle_tornado_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, triangle_tornado_Plane_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

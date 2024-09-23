#include "src/game/envfx_snow.h"

const GeoLayout drawback_curtain_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, drawback_curtain_Plane_021_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

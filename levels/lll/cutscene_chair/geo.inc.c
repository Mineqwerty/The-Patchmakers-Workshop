#include "src/game/envfx_snow.h"

const GeoLayout cutscene_chair_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cutscene_chair_Plane_013_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

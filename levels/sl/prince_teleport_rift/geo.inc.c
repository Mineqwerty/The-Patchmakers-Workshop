#include "src/game/envfx_snow.h"

const GeoLayout prince_teleport_rift_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, prince_teleport_rift_Cube_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

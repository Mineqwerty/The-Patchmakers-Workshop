#include "src/game/envfx_snow.h"

const GeoLayout tfp_diorama_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tfp_diorama_Cube_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

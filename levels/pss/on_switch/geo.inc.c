#include "src/game/envfx_snow.h"

const GeoLayout on_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, on_switch_Cube_016_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

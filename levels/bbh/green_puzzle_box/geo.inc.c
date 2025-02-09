#include "src/game/envfx_snow.h"

const GeoLayout green_puzzle_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, green_puzzle_box_Cube_009_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

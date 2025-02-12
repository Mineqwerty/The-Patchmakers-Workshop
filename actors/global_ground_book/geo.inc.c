#include "src/game/envfx_snow.h"

const GeoLayout global_ground_book_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, global_ground_book_Cube_021_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

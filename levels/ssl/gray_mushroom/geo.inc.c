#include "src/game/envfx_snow.h"

const GeoLayout gray_mushroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gray_mushroom_Circle_007_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout clc_painting_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clc_painting_Circle_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

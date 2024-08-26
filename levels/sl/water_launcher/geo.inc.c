#include "src/game/envfx_snow.h"

const GeoLayout water_launcher_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, water_launcher_Circle_011_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, water_launcher_Circle_011_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

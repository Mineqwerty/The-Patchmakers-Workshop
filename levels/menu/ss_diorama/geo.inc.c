#include "src/game/envfx_snow.h"

const GeoLayout ss_diorama_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ss_diorama_Circle_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ss_diorama_Circle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

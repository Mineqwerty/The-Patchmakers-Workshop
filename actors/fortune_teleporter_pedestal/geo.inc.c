#include "src/game/envfx_snow.h"

const GeoLayout fortune_teleporter_pedestal_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fortune_teleporter_pedestal_Circle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

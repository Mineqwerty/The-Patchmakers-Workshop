#include "src/game/envfx_snow.h"

const GeoLayout cartoon_clock_hand_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cartoon_clock_hand_Cube_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cartoon_clock_hand_Cube_008_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

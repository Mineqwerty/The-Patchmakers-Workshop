#include "src/game/envfx_snow.h"

const GeoLayout speech_bubble_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, speech_bubble_Plane_042_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

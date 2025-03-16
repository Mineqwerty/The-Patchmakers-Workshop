#include "src/game/envfx_snow.h"

const GeoLayout pm_thread_of_life_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pm_thread_of_life_Plane_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pm_thread_of_life_Plane_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

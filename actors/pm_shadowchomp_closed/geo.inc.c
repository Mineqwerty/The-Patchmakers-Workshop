#include "src/game/envfx_snow.h"

const GeoLayout pm_shadowchomp_closed_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pm_shadowchomp_closed_Sphere_004_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, pm_shadowchomp_closed_Sphere_004_mesh_layer_7),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

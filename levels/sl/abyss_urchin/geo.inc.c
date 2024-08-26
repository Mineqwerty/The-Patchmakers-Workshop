#include "src/game/envfx_snow.h"

const GeoLayout abyss_urchin_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, abyss_urchin_Sphere_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, abyss_urchin_Sphere_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout shadow_transition_sphere_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shadow_transition_sphere_Sphere_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

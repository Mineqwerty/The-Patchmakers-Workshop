#include "src/game/envfx_snow.h"

const GeoLayout shadow_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, shadow_ball_Sphere_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

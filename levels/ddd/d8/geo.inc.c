#include "src/game/envfx_snow.h"

const GeoLayout d8_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 70),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, d8_Sphere_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

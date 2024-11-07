#include "src/game/envfx_snow.h"

const GeoLayout dice_spear_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 70),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dice_spear_Sphere_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout mario_plush_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_plush_skinned_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

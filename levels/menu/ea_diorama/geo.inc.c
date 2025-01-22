#include "src/game/envfx_snow.h"

const GeoLayout ea_diorama_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ea_diorama_Circle_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ea_diorama_Circle_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

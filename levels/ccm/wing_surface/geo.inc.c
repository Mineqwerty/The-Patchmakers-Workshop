#include "src/game/envfx_snow.h"

const GeoLayout wing_surface_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wing_surface_Plane_014_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

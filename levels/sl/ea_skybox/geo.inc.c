#include "src/game/envfx_snow.h"

const GeoLayout ea_skybox_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, ea_skybox_Sphere_006_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ea_skybox_Sphere_006_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

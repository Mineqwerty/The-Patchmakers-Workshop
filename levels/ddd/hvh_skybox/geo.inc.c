#include "src/game/envfx_snow.h"

const GeoLayout hvh_skybox_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, hvh_skybox_Sphere_004_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hvh_skybox_Sphere_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

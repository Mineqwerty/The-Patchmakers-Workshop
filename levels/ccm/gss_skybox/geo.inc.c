#include "src/game/envfx_snow.h"

const GeoLayout gss_skybox_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, gss_skybox_Sphere_001_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, gss_skybox_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

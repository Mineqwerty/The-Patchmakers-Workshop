#include "src/game/envfx_snow.h"

const GeoLayout tfp_skybox_bubbles_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tfp_skybox_bubbles_Cube_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tfp_skybox_bubbles_Cube_002_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tfp_skybox_bubbles_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tfp_skybox_bubbles_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

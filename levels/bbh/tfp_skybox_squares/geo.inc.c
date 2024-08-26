#include "src/game/envfx_snow.h"

const GeoLayout tfp_skybox_squares_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tfp_skybox_squares_Cube_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, tfp_skybox_squares_Cube_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tfp_skybox_squares_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, tfp_skybox_squares_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

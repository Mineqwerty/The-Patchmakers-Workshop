#include "src/game/envfx_snow.h"

const GeoLayout ground_patch_portal_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ground_patch_portal_Plane_003_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ground_patch_portal_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

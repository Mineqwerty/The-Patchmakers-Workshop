#include "src/game/envfx_snow.h"

const GeoLayout shadow_chomp_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shadow_chomp_bottom_skinned_mesh_layer_5),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, -65, -37, 0, shadow_chomp_bottom_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shadow_chomp_top_skinned_mesh_layer_5),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, -65, 37, 0, shadow_chomp_top_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shadow_chomp_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

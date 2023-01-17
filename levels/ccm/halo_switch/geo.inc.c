#include "src/game/envfx_snow.h"

const GeoLayout halo_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, halo_switch_Plane_009_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, halo_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

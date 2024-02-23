#include "src/game/envfx_snow.h"

const GeoLayout moving_spectral_octagon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, moving_spectral_octagon_Plane_007_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, moving_spectral_octagon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

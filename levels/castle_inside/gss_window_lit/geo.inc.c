#include "src/game/envfx_snow.h"

const GeoLayout gss_window_lit_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gss_window_lit_Plane_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gss_window_lit_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

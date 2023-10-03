#include "src/game/envfx_snow.h"

const GeoLayout gss_window_light_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gss_window_light_Plane_006_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gss_window_light_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

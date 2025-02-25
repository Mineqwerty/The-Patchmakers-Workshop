#include "src/game/envfx_snow.h"

const GeoLayout ts_panel_touch_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ts_panel_touch_Plane_027_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout falling_stone_2_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, falling_stone_2_Plane_013_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, falling_stone_2_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

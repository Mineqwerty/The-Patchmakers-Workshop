#include "src/game/envfx_snow.h"

const GeoLayout falling_stone_4_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, falling_stone_4_Plane_015_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, falling_stone_4_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

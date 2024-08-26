#include "src/game/envfx_snow.h"

const GeoLayout underwater_stone_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, underwater_stone_button_Circle_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, underwater_stone_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

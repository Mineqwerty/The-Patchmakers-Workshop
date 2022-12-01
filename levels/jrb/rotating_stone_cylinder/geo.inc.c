#include "src/game/envfx_snow.h"

const GeoLayout rotating_stone_cylinder_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rotating_stone_cylinder_Circle_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rotating_stone_cylinder_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

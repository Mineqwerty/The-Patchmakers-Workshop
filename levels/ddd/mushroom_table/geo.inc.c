#include "src/game/envfx_snow.h"

const GeoLayout mushroom_table_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mushroom_table_Circle_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mushroom_table_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

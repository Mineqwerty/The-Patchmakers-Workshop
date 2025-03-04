#include "src/game/envfx_snow.h"

const GeoLayout underwater_stone_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, underwater_stone_button_Circle_007_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout clc_puzzle_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clc_puzzle_switch_Cube_005_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clc_puzzle_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

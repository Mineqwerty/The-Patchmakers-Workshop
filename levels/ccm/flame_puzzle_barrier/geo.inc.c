#include "src/game/envfx_snow.h"

const GeoLayout flame_puzzle_barrier_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, flame_puzzle_barrier_Cube_013_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, flame_puzzle_barrier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout dice_cube_shot_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dice_cube_shot_Cube_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

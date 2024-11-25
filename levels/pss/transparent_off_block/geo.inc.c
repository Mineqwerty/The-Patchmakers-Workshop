#include "src/game/envfx_snow.h"

const GeoLayout transparent_off_block_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, transparent_off_block_Cube_018_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

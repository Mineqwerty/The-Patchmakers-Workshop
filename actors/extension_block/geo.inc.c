#include "src/game/envfx_snow.h"
#include "src/game/level_geo.h"

const GeoLayout extension_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_get_area_material_from_table),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, extension_block_Cube_001_mesh_layer_1),
		GEO_ASM(0, geo_get_area_revert_from_table),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

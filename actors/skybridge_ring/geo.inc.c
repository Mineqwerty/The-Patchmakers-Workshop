#include "src/game/envfx_snow.h"

const GeoLayout skybridge_ring_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_transparent_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, skybridge_ring_Circle_005_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

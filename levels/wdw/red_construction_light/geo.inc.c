#include "src/game/envfx_snow.h"

const GeoLayout red_construction_light_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency),
		GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_transparent_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, red_construction_light_Plane_004_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

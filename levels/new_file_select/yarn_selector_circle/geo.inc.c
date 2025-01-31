#include "src/game/envfx_snow.h"

const GeoLayout yarn_selector_circle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_ALPHA, yarn_selector_circle_Plane_002_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

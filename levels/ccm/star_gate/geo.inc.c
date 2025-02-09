#include "src/game/envfx_snow.h"

const GeoLayout star_gate_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, star_gate_Plane_mesh_layer_5),
		GEO_ASM(0, geo_update_cutout_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_ALPHA, star_gate_Plane_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

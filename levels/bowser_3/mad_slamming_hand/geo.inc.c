#include "src/game/envfx_snow.h"

const GeoLayout mad_slamming_hand_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mad_slamming_hand_Plane_005_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout drag_spark_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_transparent_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, drag_spark_Plane_003_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

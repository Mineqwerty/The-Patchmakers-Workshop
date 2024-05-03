#include "src/game/envfx_snow.h"

const GeoLayout floating_petal_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_transparent_prim_color_from_obj_fields),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, floating_petal_Bone_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

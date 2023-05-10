#include "src/game/envfx_snow.h"

const GeoLayout portal_barrier_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_transparent_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, portal_barrier_Plane_009_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, portal_barrier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

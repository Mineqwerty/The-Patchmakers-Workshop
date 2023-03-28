#include "src/game/envfx_snow.h"

const GeoLayout floating_plane_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_prim_color_from_obj_fields),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floating_plane_Plane_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floating_plane_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

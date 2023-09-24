#include "src/game/envfx_snow.h"

const GeoLayout gss_diorama_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gss_diorama_Plane_002_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gss_diorama_Plane_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gss_diorama_Plane_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gss_diorama_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gss_diorama_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gss_diorama_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

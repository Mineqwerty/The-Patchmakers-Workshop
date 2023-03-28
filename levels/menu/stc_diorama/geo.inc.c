#include "src/game/envfx_snow.h"

const GeoLayout stc_diorama_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, stc_diorama_Plane_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stc_diorama_Plane_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stc_diorama_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, stc_diorama_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

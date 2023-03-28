#include "src/game/envfx_snow.h"

const GeoLayout forcefield_no_inside_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, forcefield_no_inside_Plane_005_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, forcefield_no_inside_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

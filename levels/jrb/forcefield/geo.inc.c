#include "src/game/envfx_snow.h"

const GeoLayout forcefield_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, forcefield_Plane_005_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, forcefield_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

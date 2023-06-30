#include "src/game/envfx_snow.h"

const GeoLayout ring_mission_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ring_mission_Circle_004_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ring_mission_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

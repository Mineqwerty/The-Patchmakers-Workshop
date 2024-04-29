#include "src/game/envfx_snow.h"

const GeoLayout patch_upgrade_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, patch_upgrade_Circle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, patch_upgrade_Circle_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

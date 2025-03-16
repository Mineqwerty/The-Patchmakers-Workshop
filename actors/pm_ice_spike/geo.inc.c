#include "src/game/envfx_snow.h"

const GeoLayout pm_ice_spike_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pm_ice_spike_Plane_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

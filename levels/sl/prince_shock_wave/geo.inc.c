#include "src/game/envfx_snow.h"

const GeoLayout prince_shock_wave_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, prince_shock_wave_Circle_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

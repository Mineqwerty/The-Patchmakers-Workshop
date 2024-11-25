#include "src/game/envfx_snow.h"

const GeoLayout reality_cracks_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, reality_cracks_reality_cracks_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout bowser_plush_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bowser_plush_Bowser_014_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bowser_plush_Bowser_014_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

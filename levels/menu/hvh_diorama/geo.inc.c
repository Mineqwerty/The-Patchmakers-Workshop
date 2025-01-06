#include "src/game/envfx_snow.h"

const GeoLayout hvh_diorama_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hvh_diorama_Plane_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hvh_diorama_Plane_004_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hvh_diorama_Plane_004_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

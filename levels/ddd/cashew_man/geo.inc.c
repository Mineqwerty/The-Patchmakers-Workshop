#include "src/game/envfx_snow.h"

const GeoLayout cashew_man_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 84, 0, cashew_man_body_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 27, 76, 0, cashew_man_armL_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -28, 76, 0, cashew_man_armR_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 92, 0, cashew_man_head_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cashew_man_head_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -2, 0, cashew_man_legL_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -13, -2, 0, cashew_man_legR_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

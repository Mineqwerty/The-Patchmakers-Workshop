#include "src/game/envfx_snow.h"

const GeoLayout macadamia_woman_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, macadamia_woman_root_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, macadamia_woman_body_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 106, 0, macadamia_woman_body_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 25, 49, 0, macadamia_woman_armL_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -26, 49, 0, macadamia_woman_armR_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 61, 0, macadamia_woman_head_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, macadamia_woman_head_mesh_layer_6),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

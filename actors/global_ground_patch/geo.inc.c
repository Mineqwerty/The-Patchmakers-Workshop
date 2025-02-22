#include "src/game/envfx_snow.h"

const GeoLayout global_ground_patch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 0, 0, global_ground_patch_billboard_mesh_mesh_layer_5),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, global_ground_patch_mesh_mesh_layer_4),
			GEO_OPEN_NODE(),
				GEO_BILLBOARD_WITH_PARAMS(LAYER_OPAQUE, 0, 0, 0),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

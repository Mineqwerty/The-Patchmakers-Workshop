#include "src/game/envfx_snow.h"

const GeoLayout sky_bully_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, sky_bully_Bone_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, sky_bully_Bone_mesh_layer_1),
			GEO_BILLBOARD_WITH_PARAMS(LAYER_OPAQUE, 0, 0, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_ALPHA, 0, 60, 0, sky_bully_Bone_002_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

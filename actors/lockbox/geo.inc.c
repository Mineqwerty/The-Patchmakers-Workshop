#include "src/game/envfx_snow.h"

const GeoLayout lockbox_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 0, -90),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, lockbox_Bone_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -5, 0, 16, lockbox_Bone_001_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -5, 0, -16, lockbox_Bone_002_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

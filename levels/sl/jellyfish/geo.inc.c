#include "src/game/envfx_snow.h"

const GeoLayout jellyfish_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 151, 0, jellyfish_Bone_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellyfish_Bone_001_skinned_mesh_layer_5),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, -12, 0, 0, -90, 180),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, jellyfish_Bone_001_mesh_layer_5),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jellyfish_Bone_002_skinned_mesh_layer_5),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 100, 0, jellyfish_Bone_002_mesh_layer_5),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

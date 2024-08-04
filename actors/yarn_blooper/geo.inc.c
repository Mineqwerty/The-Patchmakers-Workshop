#include "src/game/envfx_snow.h"

const GeoLayout yarn_blooper_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 90, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, yarn_blooper_Bone_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, yarn_blooper_Bone_mesh_layer_6),
				GEO_DISPLAY_LIST(LAYER_ALPHA, yarn_blooper_Bone_001_skinned_mesh_layer_4),
				GEO_ANIMATED_PART(LAYER_ALPHA, 0, -147, 0, yarn_blooper_Bone_001_mesh_layer_4),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 39, yarn_blooper_Bone_002_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, -39, yarn_blooper_Bone_003_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

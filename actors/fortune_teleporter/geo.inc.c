#include "src/game/envfx_snow.h"

const GeoLayout fortune_teleporter_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, fortune_teleporter_Bone_001_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -89, -10, 89, fortune_teleporter_Bone_001_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, fortune_teleporter_Bone_002_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 89, -10, 89, fortune_teleporter_Bone_002_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, fortune_teleporter_Bone_003_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 89, -10, -89, fortune_teleporter_Bone_003_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, fortune_teleporter_Bone_004_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -89, -10, -89, fortune_teleporter_Bone_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

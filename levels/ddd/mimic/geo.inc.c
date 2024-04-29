#include "src/game/envfx_snow.h"

const GeoLayout mimic_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mimic_Bone_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, mimic_Bone_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 102, -76, mimic_Bone_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, mimic_Bone_001_mesh_layer_4),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 61, -42, mimic_tg_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, mimic_tg2_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 64, 152, mimic_tg2_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

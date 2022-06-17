#include "src/game/envfx_snow.h"

const GeoLayout segment_head_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, segment_head_Bone_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, segment_head_Bone_mesh_layer_6),
			GEO_SHADOW(1, 209, 770),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, segment_head_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, segment_head_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

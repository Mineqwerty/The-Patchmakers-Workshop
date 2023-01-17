#include "src/game/envfx_snow.h"

const GeoLayout fire_smoke_Bone_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_flame_color),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, fire_smoke_Bone_001_mesh_layer_5_mat_override_smoke_1_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fire_smoke_Bone_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_flame_color),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, fire_smoke_Bone_001_mesh_layer_5_mat_override_smoke_2_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fire_smoke_Bone_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_flame_color),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, fire_smoke_Bone_001_mesh_layer_5_mat_override_smoke_3_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fire_smoke_Bone_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(0, geo_update_flame_color),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, fire_smoke_Bone_001_mesh_layer_5_mat_override_smoke_4_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fire_smoke_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_fire_smoke),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, fire_smoke_Bone_001_mesh_layer_5),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, fire_smoke_Bone_opt1),
			GEO_BRANCH(1, fire_smoke_Bone_opt2),
			GEO_BRANCH(1, fire_smoke_Bone_opt3),
			GEO_BRANCH(1, fire_smoke_Bone_opt4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fire_smoke_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

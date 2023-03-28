#include "src/game/envfx_snow.h"

const GeoLayout falling_stone_shadow_Armature_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 124, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ASM(20, geo_update_layer_transparency),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, -124, 0, falling_stone_shadow_switch_option_shadow_2_mesh_layer_6),
			
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_Armature_003[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(20, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_root_shadow_3_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_Armature_004[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(20, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_root_shadow_4_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_Armature_005[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(20, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_root_shadow_5_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_Armature_006[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(20, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_root_shadow_6_mesh_layer_6),
		
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_Armature_007[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_ASM(20, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_root_shadow_7_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout falling_stone_shadow_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(0, geo_switch_falling_block_shadow),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ASM(20, geo_update_layer_transparency),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, falling_stone_shadow_umesh_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, falling_stone_shadow_Armature_002),
				GEO_BRANCH(1, falling_stone_shadow_Armature_003),
				GEO_BRANCH(1, falling_stone_shadow_Armature_004),
				GEO_BRANCH(1, falling_stone_shadow_Armature_005),
				GEO_BRANCH(1, falling_stone_shadow_Armature_006),
				GEO_BRANCH(1, falling_stone_shadow_Armature_007),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, falling_stone_shadow_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

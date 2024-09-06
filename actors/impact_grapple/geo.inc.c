#include "src/game/envfx_snow.h"

const GeoLayout impact_grapple_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, impact_grapple_mesh_mesh_layer_5_mat_override_impact1_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout impact_grapple_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, impact_grapple_mesh_mesh_layer_5_mat_override_impact2_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout impact_grapple_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, impact_grapple_mesh_mesh_layer_5_mat_override_impact3_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout impact_grapple_switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, impact_grapple_mesh_mesh_layer_5_mat_override_impact4_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout impact_grapple_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_impact_particle),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_update_layer_transparency),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, impact_grapple_mesh_mesh_layer_5),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, impact_grapple_switch_opt1),
			GEO_BRANCH(1, impact_grapple_switch_opt2),
			GEO_BRANCH(1, impact_grapple_switch_opt3),
			GEO_BRANCH(1, impact_grapple_switch_opt4),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

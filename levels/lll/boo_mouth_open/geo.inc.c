#include "src/game/envfx_snow.h"

const GeoLayout boo_mouth_open_001_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, boo_mouth_open_body_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boo_mouth_open_geo[] = {
	GEO_CULLING_RADIUS(80),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 150, 70),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, boo_mouth_open_body_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, boo_mouth_open_001_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

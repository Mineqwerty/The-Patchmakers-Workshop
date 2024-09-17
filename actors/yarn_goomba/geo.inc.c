#include "src/game/envfx_snow.h"

const GeoLayout yarn_goomba_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 5, 0, yarn_goomba_skl_root_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 8, -1, 0, yarn_goomba_leg_l_mesh_layer_1),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -8, -1, 0, 0, 180, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, yarn_goomba_leg_r_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_SHADOW(1, 148, 84),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

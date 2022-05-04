#include "src/game/envfx_snow.h"

const GeoLayout spike_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 1, 0, 0, 90, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, spike_ball_main_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, spike_ball_billboard_body_mesh_layer_4),
				GEO_SHADOW(1, 178, 50),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spike_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, spike_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

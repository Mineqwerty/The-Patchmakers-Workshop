#include "src/game/envfx_snow.h"

const GeoLayout gold_spike_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, gold_spike_ball_root_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 100, 0, gold_spike_ball_bill_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gold_spike_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, gold_spike_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

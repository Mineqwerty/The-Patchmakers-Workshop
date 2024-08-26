#include "src/game/envfx_snow.h"

const GeoLayout boost_panel_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, -180, 0),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, boost_panel_rood_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, -102, 92, 0, boost_panel_spinL_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 92, 0, boost_panel_spinR_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, boost_panel_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

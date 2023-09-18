#include "src/game/envfx_snow.h"

const GeoLayout seraphim_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_root_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, seraphim_billboard_mesh_layer_4),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 15, 0, NULL),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_eye_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_wingfrontL_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_wingfrontR_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_wingrotL_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, seraphim_wingrotR_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, seraphim_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout sky_slug_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, sky_slug_root_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, sky_slug_root_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, sky_slug_root_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, sky_slug_antennae_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 51, 731, sky_slug_antennae_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_ALPHA, 335, 0, -263, sky_slug_backL_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, -334, 0, -263, sky_slug_backR_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 335, 0, 241, sky_slug_frontL_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, -334, 0, 241, sky_slug_frontR_mesh_layer_4),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

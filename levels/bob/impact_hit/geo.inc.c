#include "src/game/envfx_snow.h"

const GeoLayout impact_hit_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 100, 0, impact_hit_umesh_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, impact_hit_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

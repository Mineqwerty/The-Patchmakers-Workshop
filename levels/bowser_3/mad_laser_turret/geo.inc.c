#include "src/game/envfx_snow.h"

const GeoLayout mad_laser_turret_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mad_laser_turret_Sphere_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

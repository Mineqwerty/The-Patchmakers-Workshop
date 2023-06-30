#include "levels/bbh/header.h"
#include "levels/bbh/texscroll.inc.c"
#include "levels/bbh/far_plane_cube_head/texscroll.inc.c"
#include "levels/bbh/boost_panel/texscroll.inc.c"
#include "levels/bbh/ring_mission/texscroll.inc.c"
#include "levels/bbh/ring_mission_target/texscroll.inc.c"
#include "levels/bbh/tfp_skybox/texscroll.inc.c"
void scroll_textures_bbh() {
			scroll_bbh();
	scroll_bbh_level_geo_far_plane_cube_head();
	scroll_bbh_level_geo_boost_panel();
	scroll_bbh_level_geo_ring_mission();
	scroll_bbh_level_geo_ring_mission_target();
	scroll_bbh_level_geo_tfp_skybox();
}

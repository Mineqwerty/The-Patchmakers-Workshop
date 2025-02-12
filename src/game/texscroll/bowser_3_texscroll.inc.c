#include "levels/bowser_3/header.h"
#include "levels/bowser_3/mantle_of_madness/texscroll.inc.c"
#include "levels/bowser_3/mantle_of_madness_hurt/texscroll.inc.c"
#include "levels/bowser_3/texscroll.inc.c"

#include "levels/bowser_3/grow_scary_wall_1/texscroll.inc.c"
#include "levels/bowser_3/grow_scary_wall_2/texscroll.inc.c"
#include "levels/bowser_3/crazy_block_1/texscroll.inc.c"
#include "levels/bowser_3/crazy_block_2/texscroll.inc.c"
#include "levels/bowser_3/crazy_block_3/texscroll.inc.c"
void scroll_textures_bowser_3() {
	scroll_bowser_3_level_geo_mantle_of_madness();
	scroll_bowser_3_level_geo_mantle_of_madness_hurt();
	scroll_bowser_3();
	scroll_bowser_3_level_geo_grow_scary_wall_1();
	scroll_bowser_3_level_geo_grow_scary_wall_2();
	scroll_bowser_3_level_geo_crazy_block_1();
	scroll_bowser_3_level_geo_crazy_block_2();
	scroll_bowser_3_level_geo_crazy_block_3();
}

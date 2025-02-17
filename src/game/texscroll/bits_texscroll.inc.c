#include "levels/bits/header.h"

#include "levels/bits/texscroll.inc.c"

#include "levels/bits/brink_skybox/texscroll.inc.c"
#include "levels/bits/triangle_tornado/texscroll.inc.c"
void scroll_textures_bits() {
	scroll_bits();
	scroll_bits_level_geo_brink_skybox();
	scroll_bits_level_geo_triangle_tornado();
}

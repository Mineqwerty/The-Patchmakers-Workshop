#include "levels/castle_inside/header.h"

#include "levels/castle_inside/texscroll.inc.c"

#include "levels/castle_inside/shadow_transition_sphere/texscroll.inc.c"
#include "levels/castle_inside/hvh_book_active/texscroll.inc.c"
void scroll_textures_castle_inside() {
	scroll_castle_inside();
	scroll_castle_inside_level_geo_shadow_transition_sphere();
	scroll_castle_inside_level_geo_hvh_book_active();
}

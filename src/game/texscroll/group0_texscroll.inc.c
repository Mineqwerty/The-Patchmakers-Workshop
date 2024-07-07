#include "actors/group0.h"
#include "actors/portal/texscroll.inc.c"
#include "actors/shadow_chomp/texscroll.inc.c"
#include "actors/shadow_chomp_tail/texscroll.inc.c"
#include "actors/miasma_ribbon/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_portal();
	scroll_actor_geo_shadow_chomp();
	scroll_actor_geo_shadow_chomp_tail();
	scroll_actor_geo_miasma_ribbon();
}

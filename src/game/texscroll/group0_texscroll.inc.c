#include "actors/group0.h"
#include "actors/portal/texscroll.inc.c"
#include "actors/shadow_chomp/texscroll.inc.c"
#include "actors/shadow_chomp_tail/texscroll.inc.c"
#include "actors/miasma_ribbon/texscroll.inc.c"
#include "actors/menu_purple_portal/texscroll.inc.c"
#include "actors/menu_orange_portal/texscroll.inc.c"
#include "actors/breaker_spark/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_portal();
	scroll_actor_geo_shadow_chomp();
	scroll_actor_geo_shadow_chomp_tail();
	scroll_actor_geo_miasma_ribbon();
	scroll_actor_dl_menu_purple_portal();
	scroll_actor_dl_menu_orange_portal();
	scroll_wdw_level_geo_breaker_spark();
}

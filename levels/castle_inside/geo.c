#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "levels/castle_inside/header.h"

#include "levels/castle_inside/star_door/geo.inc.c"
#include "levels/castle_inside/trap_door/geo.inc.c"
#include "levels/castle_inside/areas/1/geo.inc.c"
#include "levels/castle_inside/areas/2/pendulum/geo.inc.c" // Another weird case
#include "levels/castle_inside/clock_minute_hand/geo.inc.c"
#include "levels/castle_inside/clock_hour_hand/geo.inc.c"
#include "levels/castle_inside/areas/2/geo.inc.c"
#include "levels/castle_inside/water_level_pillar/geo.inc.c"
#include "levels/castle_inside/areas/3/geo.inc.c"

#include "levels/castle_inside/geo.inc.c"

#include "levels/castle_inside/garage_door/geo.inc.c"
#include "levels/castle_inside/stc_entrance_door/geo.inc.c"
#include "levels/castle_inside/stc_entrance_door2/geo.inc.c"
#include "levels/castle_inside/star_unlock_platform/geo.inc.c"
#include "levels/castle_inside/gss_window_lit/geo.inc.c"
#include "levels/castle_inside/gss_window_unlit/geo.inc.c"
#include "levels/castle_inside/gss_window_light/geo.inc.c"
#include "levels/castle_inside/cartoon_clock_hand/geo.inc.c"
#include "levels/castle_inside/paper_spinner/geo.inc.c"
#include "levels/castle_inside/automaton/geo.inc.c"
#include "levels/castle_inside/clc_painting/geo.inc.c"
#include "levels/castle_inside/shadow_transition_sphere/geo.inc.c"
#include "levels/castle_inside/hvh_book_normal/geo.inc.c"
#include "levels/castle_inside/hvh_book_active/geo.inc.c"
#include "levels/castle_inside/music_note/geo.inc.c"
#include "levels/castle_inside/drawback_curtain/geo.inc.c"
#include "levels/castle_inside/workshop_door/geo.inc.c"
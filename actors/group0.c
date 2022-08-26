#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/config.h"
#include FONT_C_FILE
#endif

#include "unused_ice_shard/model.inc.c"

#include "patch_mario_stone/model.inc.c"
#include "patches/model.inc.c"
#include "menu_layer_1/model.inc.c"
#include "menu_layer_3/model.inc.c"
#include "menu_layer_2/model.inc.c"
#include "menu_options/model.inc.c"
#include "ice_floor/model.inc.c"
#include "ice_spikes/model.inc.c"
#include "snowflake/model.inc.c"
#include "ice_cube/model.inc.c"
#include "ice_cube/collision.inc.c"
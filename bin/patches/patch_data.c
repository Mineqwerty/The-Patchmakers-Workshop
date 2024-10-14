#include <ultra64.h>

#include "sm64.h"
#include "make_const_nonconst.h"

ALIGNED8 const u8 patch_textures_dma[] = {
    #include "actors/amp/mario_cap.rgba16.inc.c" 
    ,
    #include "actors/amp/stone_patch.rgba16.inc.c"
    ,
    #include "actors/amp/chillstep_patch.rgba16.inc.c"
    ,
    #include "actors/amp/grapple_patch.rgba16.inc.c"
    ,
    #include "actors/amp/halo_patch.rgba16.inc.c"
    ,
    #include "actors/amp/marine_patch.rgba16.inc.c"
    ,
    #include "actors/amp/shadowchomp_patch.rgba16.inc.c"
    ,
    #include "actors/amp/transmutation_patch.rgba16.inc.c"
    ,
    #include "actors/amp/breeze_patch.rgba16.inc.c"
    ,
    #include "actors/amp/portal_patch.rgba16.inc.c"
    ,
    #include "actors/amp/miasma_patch.rgba16.inc.c"
    ,
    #include "actors/amp/extension_patch.rgba16.inc.c"
    ,
    #include "actors/amp/skybridge_patch.rgba16.inc.c"

};

ALIGNED8 static const Texture texture_menu_stone_patch[] = {
#include "actors/amp/mario_cap.rgba16.inc.c" 
};
ALIGNED8 static const Texture texture_menu_chillstep_patch[] = {
#include "actors/amp/chillstep_patch.rgba16.inc.c"
};
ALIGNED8 static const Texture texture_menu_grapple_patch[] = {
#include "actors/amp/grapple_patch.rgba16.inc.c"
};
ALIGNED8 static const Texture texture_menu_halo_patch[] = {
#include "actors/amp/halo_patch.rgba16.inc.c"
};
ALIGNED8 static const Texture texture_menu_marine_patch[] = {
#include "actors/amp/marine_patch.rgba16.inc.c"
};
ALIGNED8 static const Texture texture_menu_portal_patch[] = {
#include "actors/amp/portal_patch.rgba16.inc.c"
};


// 0x030293E0
const Texture *const patch_textures_lut[] = {
    texture_menu_stone_patch,
    texture_menu_chillstep_patch,
    texture_menu_grapple_patch,
    texture_menu_halo_patch,
    texture_menu_marine_patch,
    texture_menu_portal_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch,
    texture_menu_stone_patch
};

ALIGNED8 const u8 tfp_tile_textures_dma[] = {
    #include "actors/amp/tfp_tiles1.rgba16.inc.c" 
    ,
    #include "actors/amp/tfp_tiles2.rgba16.inc.c"
    ,
    #include "actors/amp/tfp_tiles3.rgba16.inc.c"
    ,
    #include "actors/amp/tfp_tiles4.rgba16.inc.c"
};

ALIGNED8 const u8 power_beads_textures_dma[] = {
    #include "actors/amp/power_meter_0.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_1.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_2.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_3.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_4.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_5.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_6.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_7.rgba16.inc.c" 
    ,
    #include "actors/amp/power_meter_8.rgba16.inc.c" 
    ,

};
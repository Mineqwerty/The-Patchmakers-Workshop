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

ALIGNED8 const u8 string_break_dma[] = {
#include "actors/amp/break_string0.i4.inc.c"
,
#include "actors/amp/break_string1.i4.inc.c"
    ,
#include "actors/amp/break_string2.i4.inc.c"
    ,
#include "actors/amp/break_string3.i4.inc.c"
    ,
#include "actors/amp/break_string4.i4.inc.c"
    ,
#include "actors/amp/break_string5.i4.inc.c"
    ,
#include "actors/amp/break_string6.i4.inc.c"
    ,
#include "actors/amp/break_string7.i4.inc.c"
    ,
#include "actors/amp/break_string8.i4.inc.c"
    ,
#include "actors/amp/break_string9.i4.inc.c"
    ,
#include "actors/amp/break_string10.i4.inc.c"
    ,
#include "actors/amp/break_string11.i4.inc.c"
    ,
#include "actors/amp/break_string12.i4.inc.c"
    ,
#include "actors/amp/break_string13.i4.inc.c"
    ,
#include "actors/amp/break_string14.i4.inc.c"
    ,
#include "actors/amp/break_string15.i4.inc.c"
    ,
#include "actors/amp/break_string16.i4.inc.c"
    ,
#include "actors/amp/break_string17.i4.inc.c"
    ,
#include "actors/amp/break_string18.i4.inc.c"
    ,
#include "actors/amp/break_string19.i4.inc.c"
    ,
#include "actors/amp/break_string20.i4.inc.c"
    ,
#include "actors/amp/break_string21.i4.inc.c"
    ,
#include "actors/amp/break_string22.i4.inc.c"
    ,
#include "actors/amp/break_string23.i4.inc.c"
    ,
#include "actors/amp/break_string24.i4.inc.c"
    ,
#include "actors/amp/break_string25.i4.inc.c"
    ,
#include "actors/amp/break_string26.i4.inc.c"
    ,
#include "actors/amp/break_string27.i4.inc.c"
    ,
#include "actors/amp/break_string28.i4.inc.c"
    ,
#include "actors/amp/break_string29.i4.inc.c"
    ,
#include "actors/amp/break_string30.i4.inc.c"
    ,
#include "actors/amp/break_string31.i4.inc.c"
    ,
#include "actors/amp/break_string32.i4.inc.c"
    ,
#include "actors/amp/break_string33.i4.inc.c"
    ,
#include "actors/amp/break_string34.i4.inc.c"
    ,
#include "actors/amp/break_string35.i4.inc.c"
    ,
#include "actors/amp/break_string36.i4.inc.c"
    ,
#include "actors/amp/break_string37.i4.inc.c"
    ,
#include "actors/amp/break_string38.i4.inc.c"
    ,
#include "actors/amp/break_string39.i4.inc.c"
    ,
#include "actors/amp/break_string40.i4.inc.c"
    ,
#include "actors/amp/break_string41.i4.inc.c"
    ,
#include "actors/amp/break_string42.i4.inc.c"
    ,
#include "actors/amp/break_string43.i4.inc.c"
    ,
#include "actors/amp/break_string44.i4.inc.c"
    ,
#include "actors/amp/break_string45.i4.inc.c"
    ,
#include "actors/amp/break_string46.i4.inc.c"
    ,
#include "actors/amp/break_string47.i4.inc.c"
    ,
#include "actors/amp/break_string48.i4.inc.c"
    ,
#include "actors/amp/break_string49.i4.inc.c"
    ,
#include "actors/amp/break_string50.i4.inc.c"
    ,
#include "actors/amp/break_string51.i4.inc.c"
    ,
#include "actors/amp/break_string52.i4.inc.c"
    ,
#include "actors/amp/break_string53.i4.inc.c"
    ,
#include "actors/amp/break_string54.i4.inc.c"
    ,
#include "actors/amp/break_string55.i4.inc.c"
    ,
#include "actors/amp/break_string56.i4.inc.c"
    ,
#include "actors/amp/break_string57.i4.inc.c"
    ,
#include "actors/amp/break_string58.i4.inc.c"
    ,
#include "actors/amp/break_string59.i4.inc.c"
    ,
#include "actors/amp/break_string60.i4.inc.c"
    ,
#include "actors/amp/break_string61.i4.inc.c"
    ,
#include "actors/amp/break_string62.i4.inc.c"
    ,
#include "actors/amp/break_string63.i4.inc.c"
    ,
#include "actors/amp/break_string64.i4.inc.c"
    ,
#include "actors/amp/break_string65.i4.inc.c"
    ,
#include "actors/amp/break_string66.i4.inc.c"
    ,
#include "actors/amp/break_string67.i4.inc.c"
    ,
#include "actors/amp/break_string68.i4.inc.c"
    ,
#include "actors/amp/break_string69.i4.inc.c"
    ,
#include "actors/amp/break_string70.i4.inc.c"
    ,
#include "actors/amp/break_string71.i4.inc.c"
    ,
#include "actors/amp/break_string72.i4.inc.c"
    ,
#include "actors/amp/break_string73.i4.inc.c"
    ,
#include "actors/amp/break_string74.i4.inc.c"
    ,
#include "actors/amp/break_string75.i4.inc.c"
    ,
#include "actors/amp/break_string76.i4.inc.c"
    ,
#include "actors/amp/break_string77.i4.inc.c"
    ,
#include "actors/amp/break_string78.i4.inc.c"
    ,
#include "actors/amp/break_string79.i4.inc.c"
    ,
#include "actors/amp/break_string80.i4.inc.c"
    ,
#include "actors/amp/break_string81.i4.inc.c"
    ,
#include "actors/amp/break_string82.i4.inc.c"
    ,
#include "actors/amp/break_string83.i4.inc.c"
    ,
#include "actors/amp/break_string84.i4.inc.c"
    ,
#include "actors/amp/break_string85.i4.inc.c"
    ,
#include "actors/amp/break_string86.i4.inc.c"
    ,
#include "actors/amp/break_string87.i4.inc.c"
    ,
#include "actors/amp/break_string88.i4.inc.c"
    ,
#include "actors/amp/break_string89.i4.inc.c"
    ,
#include "actors/amp/break_string90.i4.inc.c"
    ,
#include "actors/amp/break_string91.i4.inc.c"
    ,
#include "actors/amp/break_string92.i4.inc.c"
    ,
#include "actors/amp/break_string93.i4.inc.c"
    ,
#include "actors/amp/break_string94.i4.inc.c"
    ,
#include "actors/amp/break_string95.i4.inc.c"
    ,
#include "actors/amp/break_string96.i4.inc.c"
    ,
#include "actors/amp/break_string97.i4.inc.c"
    ,
#include "actors/amp/break_string98.i4.inc.c"
    ,
#include "actors/amp/break_string99.i4.inc.c"
    ,
#include "actors/amp/break_string100.i4.inc.c"
    ,
#include "actors/amp/break_string101.i4.inc.c"
    ,
#include "actors/amp/break_string102.i4.inc.c"
    ,
#include "actors/amp/break_string103.i4.inc.c"
    ,
#include "actors/amp/break_string104.i4.inc.c"
    ,
#include "actors/amp/break_string105.i4.inc.c"
    ,
#include "actors/amp/break_string106.i4.inc.c"
    ,
#include "actors/amp/break_string107.i4.inc.c"
    ,
#include "actors/amp/break_string108.i4.inc.c"
    ,
#include "actors/amp/break_string109.i4.inc.c"
    ,
#include "actors/amp/break_string110.i4.inc.c"
    ,
#include "actors/amp/break_string111.i4.inc.c"
    ,
#include "actors/amp/break_string112.i4.inc.c"
    ,
#include "actors/amp/break_string113.i4.inc.c"
    ,
#include "actors/amp/break_string114.i4.inc.c"
    ,
#include "actors/amp/break_string115.i4.inc.c"
    ,
#include "actors/amp/break_string116.i4.inc.c"
    ,
#include "actors/amp/break_string117.i4.inc.c"
    ,
#include "actors/amp/break_string118.i4.inc.c"
    ,
#include "actors/amp/break_string119.i4.inc.c"
    ,
#include "actors/amp/break_string120.i4.inc.c"
    ,
#include "actors/amp/break_string121.i4.inc.c"
    ,
#include "actors/amp/break_string122.i4.inc.c"
    ,
#include "actors/amp/break_string123.i4.inc.c"
    ,
#include "actors/amp/break_string124.i4.inc.c"
    ,
#include "actors/amp/break_string125.i4.inc.c"
    ,
#include "actors/amp/break_string126.i4.inc.c"
    ,
#include "actors/amp/break_string127.i4.inc.c"
    ,
#include "actors/amp/break_string128.i4.inc.c"
    ,
#include "actors/amp/break_string129.i4.inc.c"
    ,
#include "actors/amp/break_string130.i4.inc.c"
    ,
#include "actors/amp/break_string131.i4.inc.c"
    ,
#include "actors/amp/break_string132.i4.inc.c"
    ,
#include "actors/amp/break_string133.i4.inc.c"
    ,
#include "actors/amp/break_string134.i4.inc.c"
    ,
#include "actors/amp/break_string135.i4.inc.c"
    ,
#include "actors/amp/break_string136.i4.inc.c"
    ,
#include "actors/amp/break_string137.i4.inc.c"
    ,
#include "actors/amp/break_string138.i4.inc.c"
    ,
#include "actors/amp/break_string139.i4.inc.c"
    ,
#include "actors/amp/break_string140.i4.inc.c"
    ,
#include "actors/amp/break_string141.i4.inc.c"
    ,
#include "actors/amp/break_string142.i4.inc.c"
    ,
#include "actors/amp/break_string143.i4.inc.c"
    ,
#include "actors/amp/break_string144.i4.inc.c"
    ,
#include "actors/amp/break_string145.i4.inc.c"
    ,
#include "actors/amp/break_string146.i4.inc.c"
    ,
#include "actors/amp/break_string147.i4.inc.c"
    ,
#include "actors/amp/break_string148.i4.inc.c"
    ,
#include "actors/amp/break_string149.i4.inc.c"
};
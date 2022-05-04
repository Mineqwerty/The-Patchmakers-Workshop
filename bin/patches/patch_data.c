#include <ultra64.h>

#include "sm64.h"
#include "make_const_nonconst.h"

ALIGNED8 const u8 patch_textures_dma[] = {
    #include "actors/amp/mario_cap.rgba16.inc.c" 
    ,
    #include "actors/amp/stone_patch.rgba16.inc.c"
};
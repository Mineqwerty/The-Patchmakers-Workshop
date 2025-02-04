#ifndef TTM_HEADER_H
#define TTM_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout ttm_geo_000710[];
extern const GeoLayout ttm_geo_000730[];
extern const GeoLayout ttm_geo_000748[];
extern const GeoLayout ttm_geo_000778[];
extern const GeoLayout ttm_geo_0007A8[];
extern const GeoLayout ttm_geo_0007D8[];
extern const GeoLayout ttm_geo_000808[];
extern const GeoLayout ttm_geo_000830[];
extern const GeoLayout ttm_geo_000858[];
extern const GeoLayout ttm_geo_000880[];
extern const GeoLayout ttm_geo_0008A8[];
extern const GeoLayout ttm_geo_0008D0[];
extern const GeoLayout ttm_geo_0008F8[];
extern const GeoLayout ttm_geo_000920[];
extern const GeoLayout ttm_geo_000948[];
extern const GeoLayout ttm_geo_000970[];
extern const GeoLayout ttm_geo_000990[];
extern const GeoLayout ttm_geo_0009C0[];
extern const GeoLayout ttm_geo_0009F0[];
extern const GeoLayout ttm_geo_000A18[];
extern const GeoLayout ttm_geo_000A40[];
extern const GeoLayout ttm_geo_000A70[];
extern const GeoLayout ttm_geo_000B5C[];
extern const GeoLayout ttm_geo_000BEC[];
extern const GeoLayout ttm_geo_000C84[];
extern const GeoLayout ttm_geo_000D14[];
extern const GeoLayout ttm_geo_000D4C[];
extern const GeoLayout ttm_geo_000D84[];
extern const GeoLayout ttm_geo_000DBC[];
extern const GeoLayout ttm_geo_000DF4[];

// leveldata
extern const Gfx ttm_seg7_dl_0700A120[];
extern const Gfx ttm_seg7_dl_0700A2E0[];
extern const Gfx ttm_seg7_dl_0700A8C0[];
extern const Gfx ttm_seg7_dl_0700AB08[];
extern const Gfx ttm_seg7_dl_0700AF90[];
extern const Gfx ttm_seg7_dl_0700B0D0[];
extern const Gfx ttm_seg7_dl_0700B530[];
extern const Gfx ttm_seg7_dl_0700B670[];
extern const Gfx ttm_seg7_dl_0700BAD0[];
extern const Gfx ttm_seg7_dl_0700BC10[];
extern const Gfx ttm_seg7_dl_0700BE20[];
extern const Gfx ttm_seg7_dl_0700C070[];
extern const Gfx ttm_seg7_dl_0700C408[];
extern const Gfx ttm_seg7_dl_0700CAE0[];
extern const Gfx ttm_seg7_dl_0700CD10[];
extern const Gfx ttm_seg7_dl_0700D1D8[];
extern const Gfx ttm_seg7_dl_0700D688[];
extern const Gfx ttm_seg7_dl_0700DF78[];
extern const Gfx ttm_seg7_dl_0700E308[];
extern const Gfx ttm_seg7_dl_0700EAC8[];
extern const Gfx ttm_seg7_dl_0700EC58[];
extern const Gfx ttm_seg7_dl_0700F270[];
extern const Gfx ttm_seg7_dl_0700FA18[];
extern const Gfx ttm_seg7_dl_07010978[];
extern const Gfx ttm_seg7_dl_07010A68[];
extern const Gfx ttm_seg7_dl_07011128[];
extern const Gfx ttm_seg7_dl_07011608[];
extern const Gfx ttm_seg7_dl_07011C78[];
extern const Gfx ttm_seg7_dl_07011D78[];
extern const Gfx ttm_seg7_dl_07012270[];
extern const Gfx ttm_seg7_dl_07012388[];
extern const Gfx ttm_seg7_dl_070123A0[];
extern const Gfx ttm_seg7_dl_070123B8[];
extern const Gfx ttm_seg7_dl_07012410[];
extern struct Painting ttm_slide_painting;
extern const Gfx ttm_seg7_dl_07013430[];
extern const Gfx ttm_seg7_dl_07013608[];
extern const Collision ttm_seg7_collision_pitoune_2[];
extern const Collision ttm_seg7_collision_ukiki_cage[];
extern const Collision ttm_seg7_area_1_collision[];
extern const MacroObject ttm_seg7_area_1_macro_objs[];
extern const Trajectory ttm_seg7_trajectory_070170A0[];
extern const struct MovtexQuadCollection ttm_movtex_puddle[];
extern Movtex ttm_movtex_tris_begin_waterfall[];
extern Movtex ttm_movtex_tris_begin_puddle_waterfall[];
extern Movtex ttm_movtex_tris_end_waterfall[];
extern Movtex ttm_movtex_tris_end_puddle_waterfall[];
extern Movtex ttm_movtex_tris_puddle_waterfall[];
extern const Gfx ttm_dl_waterfall[];
extern const Gfx ttm_dl_bottom_waterfall[];
extern const Gfx ttm_dl_puddle_waterfall[];
extern const Gfx ttm_seg7_dl_0701D798[];
extern const Gfx ttm_seg7_dl_0701DBB8[];
extern const Gfx ttm_seg7_dl_070249A0[];
extern const Gfx ttm_seg7_dl_07024C78[];
extern const Gfx ttm_seg7_dl_07025F48[];
extern const Gfx ttm_seg7_dl_0702A1B8[];
extern const Gfx ttm_seg7_dl_0702A8A0[];
extern const Gfx ttm_seg7_dl_0702A9C0[];
extern const Gfx ttm_seg7_dl_0702AAA8[];
extern const Gfx ttm_seg7_dl_0702AB90[];
extern const Gfx ttm_seg7_dl_0702AC78[];
extern const Gfx ttm_seg7_dl_0702BB60[];
extern const Collision ttm_seg7_area_2_collision[];
extern const Collision ttm_seg7_area_3_collision[];
extern const Collision ttm_seg7_area_4_collision[];
extern const Collision ttm_seg7_collision_podium_warp[];
extern const MacroObject ttm_seg7_area_2_macro_objs[];
extern const MacroObject ttm_seg7_area_3_macro_objs[];
extern const MacroObject ttm_seg7_area_4_macro_objs[];

// script
extern const LevelScript level_ttm_entry[];

#include "levels/ttm/header.inc.h"

#include "levels/ttm/sight_cube/collision_header.h"

#include "levels/ttm/sight_cube/geo_header.h"

#include "levels/ttm/sight_switch_inactive/collision_header.h"

#include "levels/ttm/sight_switch_inactive/geo_header.h"

#include "levels/ttm/sight_switch_active/geo_header.h"

#include "levels/ttm/sight_cracked_platform/collision_header.h"

#include "levels/ttm/sight_cracked_platform/geo_header.h"

#include "levels/ttm/sight_door/collision_header.h"

#include "levels/ttm/sight_door/geo_header.h"

#include "levels/ttm/shrine_shadow/geo_header.h"

#include "levels/ttm/shrine_shadow/anim_header.h"

#include "levels/ttm/shadow_ball/geo_header.h"

#include "levels/ttm/shadow_spike/geo_header.h"

#include "levels/ttm/touch_door/collision_header.h"

#include "levels/ttm/touch_door/geo_header.h"

#include "levels/ttm/ground_shadow_spike_indicator/geo_header.h"

#include "levels/ttm/scent_flower/geo_header.h"

#include "levels/ttm/sound_drum/collision_header.h"

#include "levels/ttm/sound_drum/geo_header.h"

#include "levels/ttm/sound_wave/geo_header.h"

#include "levels/ttm/taste_switch_active/geo_header.h"

#include "levels/ttm/taste_switch_inactive/geo_header.h"

#include "levels/ttm/taste_switch_inactive/collision_header.h"

#include "levels/ttm/taste_door/collision_header.h"

#include "levels/ttm/taste_door/geo_header.h"

#include "levels/ttm/shrine_shape_1/geo_header.h"

#include "levels/ttm/shrine_shape_2/geo_header.h"

#include "levels/ttm/shrine_shape_3/geo_header.h"

#include "levels/ttm/shrine_shape_4/geo_header.h"

#include "levels/ttm/shrine_shape_5/geo_header.h"

#endif

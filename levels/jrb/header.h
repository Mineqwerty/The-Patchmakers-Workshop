#ifndef JRB_HEADER_H
#define JRB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout jrb_geo_000900[];
extern const GeoLayout jrb_geo_000918[];
extern const GeoLayout jrb_geo_000930[];
extern const GeoLayout jrb_geo_000948[];
extern const GeoLayout jrb_geo_000960[];
extern const GeoLayout jrb_geo_000978[];
extern const GeoLayout jrb_geo_000990[];
extern const GeoLayout jrb_geo_0009B0[];
extern const GeoLayout jrb_geo_0009C8[];
extern const GeoLayout jrb_geo_0009E8[];
extern const GeoLayout jrb_geo_000A00[];
extern const GeoLayout jrb_geo_000A18[];
extern const GeoLayout jrb_geo_000AFC[];

// leveldata
extern const Gfx jrb_seg7_dl_07002FD0[];
extern const Gfx jrb_seg7_dl_07004940[];
extern const Gfx jrb_seg7_dl_07004C78[];
extern const Gfx jrb_seg7_dl_070058C8[];
extern const Gfx jrb_seg7_dl_070069B0[];
extern const Gfx jrb_seg7_dl_07007570[];
extern const Gfx jrb_seg7_dl_07007718[];
extern const Gfx jrb_seg7_dl_07007AC8[];
extern const Gfx jrb_seg7_dl_07007DC8[];
extern const Gfx jrb_seg7_dl_070080F8[];
extern const Gfx jrb_seg7_dl_07008FD8[];
extern const Gfx jrb_seg7_dl_070090B0[];
extern const Gfx jrb_seg7_dl_07009A58[];
extern const Gfx jrb_seg7_dl_07009B30[];
extern const Gfx jrb_seg7_dl_0700A608[];
extern const Gfx jrb_seg7_dl_0700AC68[];
extern const Gfx jrb_seg7_dl_0700AE48[];
extern const Gfx jrb_seg7_dl_0700AFB0[];
extern const Collision jrb_seg7_area_1_collision[];
extern const MacroObject jrb_seg7_area_1_macro_objs[];
extern const Collision jrb_seg7_collision_rock_solid[];
extern const Collision jrb_seg7_collision_floating_platform[];
extern const Collision jrb_seg7_collision_floating_box[];
extern const Collision jrb_seg7_collision_in_sunken_ship_3[];
extern const Collision jrb_seg7_collision_in_sunken_ship[];
extern const Collision jrb_seg7_collision_0700CEF0[];
extern const Collision jrb_seg7_collision_in_sunken_ship_2[];
extern const Collision jrb_seg7_collision_pillar_base[];
extern const Collision jrb_seg7_collision_0700D1DC[];
extern const Trajectory jrb_seg7_trajectory_unagi_1[];
extern const Trajectory jrb_seg7_trajectory_unagi_2[];
extern const struct MovtexQuadCollection jrb_movtex_water[];
extern const struct MovtexQuadCollection jrb_movtex_initial_mist[];
extern const Gfx jrb_seg7_dl_0700EF00[];
extern const Gfx jrb_seg7_dl_0700FE48[];
extern const Gfx jrb_seg7_dl_07010548[];
extern const Collision jrb_seg7_area_2_collision[];
extern const MacroObject jrb_seg7_area_2_macro_objs[];
extern const struct MovtexQuadCollection jrb_movtex_sunken_ship_water[];

// script
extern const LevelScript level_jrb_entry[];


#include "levels/jrb/header.inc.h"

#include "levels/jrb/stone_tower_door/collision_header.h"

#include "levels/jrb/stone_tower_door/geo_header.h"

#include "levels/jrb/stone_gear/collision_header.h"

#include "levels/jrb/stone_gear/geo_header.h"

#include "levels/jrb/skybox_test/geo_header.h"

#include "levels/jrb/grapple_stone/geo_header.h"

#include "levels/jrb/grapple_stone/collision_header.h"

#include "levels/jrb/enemy_obelisk/collision_header.h"

#include "levels/jrb/enemy_obelisk/geo_header.h"

#include "levels/jrb/forcefield/collision_header.h"

#include "levels/jrb/forcefield/geo_header.h"

#include "levels/jrb/rotating_stone_cylinder/collision_header.h"

#include "levels/jrb/rotating_stone_cylinder/geo_header.h"

#include "levels/jrb/stone_elevator/collision_header.h"

#include "levels/jrb/stone_elevator/geo_header.h"

#include "levels/jrb/extending_stone_bridge/collision_header.h"

#include "levels/jrb/extending_stone_bridge/geo_header.h"

#include "levels/jrb/falling_stone_1/geo_header.h"

#include "levels/jrb/falling_stone_1/collision_header.h"

#include "levels/jrb/falling_stone_2/collision_header.h"

#include "levels/jrb/falling_stone_2/geo_header.h"

#include "levels/jrb/falling_stone_3/geo_header.h"

#include "levels/jrb/falling_stone_3/collision_header.h"

#include "levels/jrb/falling_stone_4/geo_header.h"

#include "levels/jrb/falling_stone_4/collision_header.h"

#include "levels/jrb/falling_stone_5/geo_header.h"

#include "levels/jrb/falling_stone_5/collision_header.h"

#include "levels/jrb/falling_stone_6/geo_header.h"

#include "levels/jrb/falling_stone_7/collision_header.h"

#include "levels/jrb/falling_stone_7/geo_header.h"

#include "levels/jrb/falling_stone_6/collision_header.h"

#include "levels/jrb/forcefield_no_inside/geo_header.h"

#include "levels/jrb/falling_stone_shadow/geo_header.h"

#endif

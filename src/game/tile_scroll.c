#include <ultra64.h>
#include "game/memory.h"
#include "game/tile_scroll.h"
#include "src/game/camera.h"
#include "src/engine/math_util.h"
#include "src/game/game_init.h"


/*
 * Parameters:
 * dl - Which display list to modify (make sure it's passed by reference).
 *
 * cmd - Location of the gsDPSetTileSize command in the display list.
 *
 * s/t - How much to scroll.
 */

void shift_s(Gfx *dl, u32 cmd, u16 s) {
    SetTileSize *tile = dl;
    tile += cmd;
    tile->s += s;
    tile->u += s;
}

void shift_t(Gfx *dl, u32 cmd, u16 t) {
    SetTileSize *tile = dl;
    tile += cmd;
    tile->t += t;
    tile->v += t;
}

void shift_s_down(Gfx *dl, u32 cmd, u16 s) {
    SetTileSize *tile = dl;
    tile += cmd;
    tile->s -= s;
    tile->u += s;
}

void shift_t_down(Gfx *dl, u32 cmd, u16 t) {
    SetTileSize *tile = dl;
    tile += cmd;
    tile->t -= t;
    tile->v += t;
}

void align_st_to_cam(Gfx *dl, u32 cmd) {
    SetTileSize *tile = (SetTileSize *)dl;
    tile += cmd;
    Vec3f dir;
    Vec3f down = { 0, -1, 0 };
    vec3f_diff(dir, gLakituState.focus, gLakituState.pos);
    vec3f_normalize(dir);
    f32 amt = vec3f_dot(dir, down);
    amt = absf(amt); // 1 looking down, 0 perpendicular
    amt = ((amt * -1) + 1) * 256.0f*sins(0x100 * gGlobalTimer);
    f32 sA = sins(gLakituState.yaw) * amt;
    f32 tA = coss(gLakituState.yaw) * amt;

    tile->u = tile->s = 256 - roundf(sA);
    tile->v = tile->t = 256 - roundf(tA);
}

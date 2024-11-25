#include "src/game/game_init.h"

void bhv_reality_cracks_init(void) {
}

void bhv_reality_cracks_loop(void) {
    if (gDestroyedCrackInReality) {
        obj_mark_for_deletion(o);
    } else {
        load_object_collision_model();
    }
}

void bhv_reality_cracks_hitbox_init(void) {
}

void bhv_reality_cracks_hitbox_loop(void) {
    if (o->oAction == 0) {

        struct Surface *surf;
        Vec3f originPos;
        Vec3f hitpos;
        Vec3f raydir;

        raydir[0] = sins(o->oMoveAngleYaw) * 20.0f;
        raydir[1] = 0.0f;
        raydir[2] = coss(o->oMoveAngleYaw) * 20.0f;

        vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

        vec3f_set(originPos, o->oPosX, o->oPosY,
                o->oPosZ);

        find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);
        if (surf != NULL && surf->object && obj_has_behavior(surf->object, bhvExtensionBlock)) {
            gDestroyedCrackInReality = 1;
            o->oAction = 1;
            spawn_triangle_break_particles(20, MODEL_SL_CRACKED_ICE_CHUNK, 5.0f, 0);
            cur_obj_play_sound_1(SOUND_SKYBRIDGE_BREAK);
        }
    }
}

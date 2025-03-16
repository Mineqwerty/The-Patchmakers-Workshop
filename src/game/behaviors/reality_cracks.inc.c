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
    o->oAction = 0;
}

void bhv_reality_cracks_hitbox_loop(void) {
    if (o->oAction == 0) {

        struct Surface *surf;
        Vec3f originPos;
        Vec3f hitpos;
        Vec3f raydir;

        raydir[0] = sins(o->oFaceAngleYaw) * 30.0f;
        raydir[1] = 0.0f;
        raydir[2] = coss(o->oFaceAngleYaw) * 30.0f;

        vec3f_set(hitpos, 0.0f, 0.0f, 0.0f);

        vec3f_set(originPos, o->oPosX + sins(o->oFaceAngleYaw) * 10.0f, o->oPosY,
                o->oPosZ + coss(o->oFaceAngleYaw) * 10.0f);

        find_surface_on_ray(originPos, raydir, &surf, hitpos, 2U, 1);

        struct Object *extBlock;
        f32 extBlockDist;

        extBlock = cur_obj_find_object_with_bparam_2nd_byte(bhvExtensionBlock, 1);

        if (extBlock && extBlockDist < 550 && extBlock->oAction == 2) {
        //if ((surf != NULL && surf->object && obj_has_behavior(surf->object, bhvExtensionBlock))) {
            gDestroyedCrackInReality = 1;
            o->oAction = 1;
            spawn_triangle_break_particles(20, MODEL_SL_CRACKED_ICE_CHUNK, 5.0f, 0);
            cur_obj_play_sound_1(SOUND_SKYBRIDGE_BREAK);
        }

        load_object_collision_model();
    }
}

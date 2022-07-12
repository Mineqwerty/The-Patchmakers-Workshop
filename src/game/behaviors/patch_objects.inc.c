struct SpawnParticlesInfo sMistIce = {
    2, 4, MODEL_MIST, 10.0f, -20, 0, 20, 40, 252, 30, 15.0f, 0.0f
};
struct SpawnParticlesInfo sSnowflakeFly = {
    2, 8, MODEL_SNOWFLAKE, 10.0f, 40, 10, 0, 0, 0, 30, 13.0f, 6.0f
};

void bhv_ice_spikes_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
}

void bhv_ice_spikes_loop(void) {
    if (o->oTimer <= 9) {
        obj_scale_xyz(o, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f, ((f32) o->oTimer) / 6.0f);
    }
    else if (o->oTimer > 30 && o->oTimer < 35) {
        obj_scale_xyz(o, 1.5f, 4.5f - ((f32) o->oTimer) / 10.0f, 1.5f);
        o->oPosY -= 5.0f;
    }
    else if(o->oTimer >= 35) {
        obj_scale_xyz(o, 3.5f - ((f32) o->oTimer - 5) / 15.0f, 4.5f - ((f32) o->oTimer) / 10.0f, 3.5f - ((f32) o->oTimer - 5) / 15.0f);
    }

    if (o->oTimer == 40) {
        obj_mark_for_deletion(o);
    }
}

void bhv_ice_floor_init(void) {
    obj_scale_xyz(o, 0, 0, 0);
    cur_obj_spawn_particles(&sSnowflakeFly);
cur_obj_spawn_particles(&sMistIce);
//obj_orient_graph(o, gMarioState->floor->normal.x, gMarioState->floor->normal.y, gMarioState->floor->normal.z, 1);

struct Surface *waterFloor;
Vec3f position;

vec3f_copy(position, &o->oPosVec);

find_floor(o->oPosX, o->oPosY + 50, o->oPosZ, &waterFloor);
if (waterFloor) {
    Vec3f floorNormal;
    surface_normal_to_vec3f(floorNormal, waterFloor);
    mtxf_align_terrain_normal(o->transform, floorNormal, position, o->oFaceAngleYaw);
    o->header.gfx.throwMatrix = &o->transform;

}

}

void bhv_ice_floor_loop(void) {

    
    
    struct Surface *waterFloor;
Vec3f position;

vec3f_copy(position, &o->oPosVec);

find_floor(o->oPosX, o->oPosY + 50, o->oPosZ, &waterFloor);
if (waterFloor) {
    Vec3f floorNormal;
    surface_normal_to_vec3f(floorNormal, waterFloor);
    mtxf_align_terrain_normal(o->transform, floorNormal, position, o->oFaceAngleYaw);
    o->header.gfx.throwMatrix = &o->transform;

}
    

   //obj_orient_graph(o, waterFloor->normal.x, waterFloor->normal.y, waterFloor->normal.z, 1);

    if (o->parentObj) {
         print_text_fmt_int(20, 60, "X %d", waterFloor->normal.x);
          print_text_fmt_int(20, 40, "Y %d", waterFloor->normal.y);
        print_text_fmt_int(20, 20, "Z %d", waterFloor->normal.z);
    }


    switch (o->oAction) {
        case 0:
    if (o->oTimer < 2) {
        obj_scale_xyz(o, ((f32) o->oTimer) / 2.0f, 1, ((f32) o->oTimer) / 2.0f);
    }
    else if (sqr(gMarioState->pos[0] - o->oPosX) + sqr(gMarioState->pos[2] - o->oPosZ) > 20000.0f) {
        o->oAction += 1;
        o->oTimer = 0;
    }
    else {
        obj_scale_xyz(o, 1.5f, 1.5f, 1.5f);
    }


    if (o->oTimer > 20 && !o->parentObj) {
         o->oAction += 1;
        o->oTimer = 0;
    }
    break;
    case 1:
        obj_scale_xyz(o, 1.0f - ((f32) o->oTimer) / 10.0f, 1, 1.0f - ((f32) o->oTimer) / 10.0f);

        if (o->oTimer >= 10) {
            obj_mark_for_deletion(o);
        }
    break;
    }
}
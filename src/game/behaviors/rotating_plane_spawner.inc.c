void bhv_rotating_plane_spawner_init(void) {

}

void bhv_rotating_plane_spawner_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oSpawnedRotatingPlane = spawn_object_relative(0, 0, 0, 0, o, MODEL_FLOATING_PLANE, bhvFloatingPlane);
            o->oAction = 1;
        break;
        case 1:
            if (!o->oSpawnedRotatingPlane || o->oSpawnedRotatingPlane->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
                o->oAction = 2;
            }
        break;
        case 2:
            if (o->oTimer == 30) {
                o->oAction = 0;
            }
        break;
    }
}


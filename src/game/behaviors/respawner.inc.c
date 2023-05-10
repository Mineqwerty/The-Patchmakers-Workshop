// respawner.inc.c

void bhv_respawner_loop(void) {
    struct Object *spawnedObject;
    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, o->oRespawnerMinSpawnDist)) {
        spawnedObject = spawn_object(o, o->oRespawnerModelToRespawn, o->oRespawnerBehaviorToRespawn);
        spawnedObject->oBehParams = o->oBehParams;
        spawnedObject->oPrimColorParams = o->oPrimColorParams;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void create_respawner(ModelID32 model, const BehaviorScript *behToSpawn, s32 minSpawnDist, s32 behParams) {
    struct Object *respawner = spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvRespawner, o->oHomeX, o->oHomeY, o->oHomeZ, 0, 0, 0);
    respawner->oBehParams = behParams;
    respawner->oPrimColorParams = o->oPrimColorParams;
    respawner->oRespawnerModelToRespawn = model;
    respawner->oRespawnerMinSpawnDist = minSpawnDist;
    respawner->oRespawnerBehaviorToRespawn = behToSpawn;
}

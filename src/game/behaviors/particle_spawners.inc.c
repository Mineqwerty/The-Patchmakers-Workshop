static struct SpawnParticlesInfo sCrashingWaterParticles = {
    /* behParam:        */ 5,
    /* count:           */ 1,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 8,
    /* forwardVelRange: */ 4,
    /* velYBase:        */ 20,
    /* velYRange:       */ 15,
    /* gravity:         */ -3,
    /* dragStrength:    */ 0,
    /* sizeBase:        */ 50.0f,
    /* sizeRange:       */ 7.0f,
};

void bhv_particle_crashing_water_spawner_loop(void) {
    cur_obj_spawn_particles(&sCrashingWaterParticles);
}
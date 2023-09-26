void bhv_torch_holder_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oTorchFlame = spawn_object_relative(0, 0, 250, 0, o, MODEL_NONE, bhvFireSmokeSpawner);
        spawn_object_relative(0, 0, 250, 0, o, MODEL_NONE, bhvFlame);
    }
}

void bhv_torch_holder_loop(void) {

    if (o->oBehParams2ndByte == 0) {
    f32 dist;
    cur_obj_find_nearest_object_with_behavior(bhvFireSmokeSpawner, &dist);
    if (dist < 300.0f) {
        o->oBehParams2ndByte = 1;
        o->oTorchFlame = spawn_object_relative(1, 0, 250, 0, o, MODEL_NONE, bhvFireSmokeSpawner);
        spawn_object_relative(0, 0, 250, 0, o, MODEL_NONE, bhvFlame);

        if (gCurrAreaIndex == 2) spawn_object_relative(1, 0, 0, 0, o, MODEL_NONE, bhvWillOWispSpawner);

         struct Object *hiddenStar = cur_obj_nearest_object_with_behavior(bhvGSSHiddenStar);

        if (hiddenStar != NULL) {
            hiddenStar->oHiddenStarTriggerCounter++;

            play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) hiddenStar->oHiddenStarTriggerCounter - 1) << 16), gGlobalSoundSource);
        }

    }
    }

    if (o->oTorchFlame) {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TORCH_HOLDER_LIT];
    }
}

void bhv_flame_puzzle_barrier_loop(void) {
    if (o->oBehParams2ndByte == 1) {
        f32 dist;
        struct Object *switchObj = cur_obj_find_nearest_object_with_behavior(bhvHaloSwitch, &dist);
    if (switchObj == NULL) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                struct Object *flame = spawn_object_abs_with_rot(gMarioObject, 0, MODEL_FIRE_SMOKE, bhvFireSmokeParticle, o->oPosX - 1000 + (200*j), o->oPosY + (200*i), o->oPosZ, 0, 0, 0);
                flame->oBehParams = 0x00010000;
            }
        }

        obj_mark_for_deletion(o);
    }
    }
    else if (o->oBehParams2ndByte == 2) {
        f32 dist;
        struct Object *seraphim = cur_obj_find_nearest_object_with_behavior(bhvSeraphim, &dist);
    if (seraphim == NULL) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                struct Object *flame = spawn_object_abs_with_rot(gMarioObject, 0, MODEL_FIRE_SMOKE, bhvFireSmokeParticle, o->oPosX - 1000 + (200*j), o->oPosY + (200*i), o->oPosZ, 0, 0, 0);
                flame->oBehParams = 0x00010000;
            }
        }

        obj_mark_for_deletion(o);
    }
    }
    else {
    struct Object *flameHolder = cur_obj_find_object_with_bparam_2nd_byte(bhvTorchHolder, 0);
    if (flameHolder == NULL) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                struct Object *flame = spawn_object_abs_with_rot(gMarioObject, 0, MODEL_FIRE_SMOKE, bhvFireSmokeParticle, o->oPosX - 1000 + (200*j), o->oPosY + (200*i), o->oPosZ, 0, 0, 0);
                flame->oBehParams = 0x00010000;
            }
        }

        obj_mark_for_deletion(o);
    }
    }
}

void bhv_halo_switch_loop(void) {
    f32 dist;
    cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);
    if (dist < 300.0f) {
            spawn_object_abs_with_rot(gMarioObject, 0, MODEL_FIRE_SMOKE, bhvFireSmokeParticle, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
            play_sound(SOUND_GENERAL_WATER_LEVEL_TRIG, gGlobalSoundSource);
            obj_mark_for_deletion(o);
        

    }
}
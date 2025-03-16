void bhv_eyebulb_init(void) {
    o->oEyebulbEye = spawn_object_relative(0, 0, 50, 0, o, MODEL_MR_I, bhvMrI);
    o->oDrawingDistance = (gIsConsole ? 5000 : 20000);
}

void bhv_eyebulb_loop(void) {
    switch (o->oAction) {
        case 0:
            if (!o->oEyebulbEye || o->oEyebulbEye->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
                o->oAction = 1;
            }
        break;
        case 1:
            if (o->oTimer == 90) {
               o->oEyebulbEye = spawn_object_relative(0, 0, 50, 0, o, MODEL_MR_I, bhvMrI);
               o->oAction  = 0;
            }
        break;
    }

    //only calc distance if mario meets the halo criteria, should help performance
    if (gMarioState->equippedPatch == PATCH_HALO && gMarioState->haloCaptureType == 1) {
        f32 dist;
        struct Object *haloFire = cur_obj_find_nearest_object_with_behavior(bhvHalo, &dist);

        if (o->oAction != 3 && haloFire && haloFire->oHaloCapturedObject && obj_has_behavior(haloFire->oHaloCapturedObject, bhvFireSmokeSpawner) && dist < 200) {
            if (o->oEyebulbEye) {
                o->oEyebulbEye->oAction = 3;
                o->oBehParams = 0;
                o->oBehParams2ndByte = 0;
            }
            o->oEyebulbEye = spawn_object_relative(0, 0, 50, 0, o, MODEL_RED_FLAME, bhvLargeFlame);
            o->oAction = 3;
        }
    }
}


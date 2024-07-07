void bhv_malva_flower_init(void) {
    f32 dist;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvMalvaFlowerManager, &dist);
}

void bhv_malva_flower_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->marioObj->platform == o) {
                if (obj_has_model(o, MODEL_MALVA_BUD)) {
                    if (gMarioState->curPatch == PATCH_BREEZE) {
                        o->oAction = 1;
                        cur_obj_play_sound_1(SOUND_NEW_BREEZE_RESTORE);
                    }
                }
            }
        break;
        case 1:
            cur_obj_scale_over_time(SCALE_AXIS_X, 10, 1.0f, 0.2f);
            cur_obj_scale_over_time(SCALE_AXIS_Z, 10, 1.0f, 0.2f);
            if (o->oTimer == 10) {
                cur_obj_set_model(MODEL_MALVA_FLOWER);
                o->oAction = 2;
                o->parentObj->oF4 += 1;
                for (u8 i = 0; i < 10; i++) {
                struct Object *flame = spawn_object_relative(0, (random_u16() % 400) - 200, (random_u16() % 200), (random_u16() % 400) - 200, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
                flame->oBehParams = 0x01000000;
                
            }
            }
        break;
        case 2:
            cur_obj_scale_over_time(SCALE_AXIS_X, 5, 0.2f, 1.5f);
            cur_obj_scale_over_time(SCALE_AXIS_Z, 5, 0.2f, 1.5f);
            if (o->oTimer == 5) {
                o->oAction = 3;
            }
        break;
        case 3:
            cur_obj_scale_over_time(SCALE_AXIS_X, 3, 1.5f, 1.0f);
            cur_obj_scale_over_time(SCALE_AXIS_Z, 3, 1.5f, 1.0f);
            if (o->oTimer == 3) {
                o->oAction = 4;
                if (o->parentObj->oF4 == 5) {
                    SET_BPARAM1(o->oBehParams, 2);
                    spawn_default_star(o->oPosX, o->oPosY + 300, o->oPosZ);
                }
                else {
                    spawn_orange_number(o->parentObj->oF4, 0, 100, 0);
                }
            }
        break;
    }
    
}

void bhv_malva_flower_manager_init(void) {

}

void bhv_malva_flower_manager_loop(void) {
    
}


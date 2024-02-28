void bhv_eyebulb_init(void) {
    o->oEyebulbEye = spawn_object_relative(0, 0, 50, 0, o, MODEL_MR_I, bhvMrI);
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
}


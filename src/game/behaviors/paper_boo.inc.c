void bhv_paper_boo_init(void) {
    o->oPaperBooSpawned = NULL;
}

void bhv_paper_boo_loop(void) {
    cur_obj_set_model(MODEL_NONE);
    switch (o->oAction) {
        case 0:
            if (!o->oPaperBooSpawned) {
                o->oPaperBooSpawned = spawn_object_relative(0, 0, 0, 0, o, MODEL_PAPER_BOO, bhvPaperBooEatable);
                o->oAction++;
            }
        break;
        case 1:
            if (!o->oPaperBooSpawned) {
                o->oAction++;
                o->oTimer = 0;
            }
        break;
        case 2:
            if (o->oTimer >= 90) {
                o->oPaperBooSpawned = spawn_object_relative(0, 0, 0, 0, o, MODEL_PAPER_BOO, bhvPaperBooEatable);
                o->oAction = 1;
            }
        break;
    }
}


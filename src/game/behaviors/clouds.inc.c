void bhv_gold_cloud_loop(void) {
    switch (o->oAction) {
        case 0:
            gold_cloud_drift_xz();

            if (gMarioObject->platform == o) {
                o->oAction = 1;
                o->oVelY = gMarioState->vel[1];
            }
        break;
        case 1:
            gold_cloud_bounce();
        break;
        case 2:
            if (gMarioObject->platform != o) {
                o->oAction = 0;
            }
        break;
    }

    obj_scale_xyz(o, 1.0f + (0.05f * sins(0x200 * gGlobalTimer)), 1.0f + (0.05f * coss(0x200 * gGlobalTimer)), 1.0f + (0.05f * sins(0x200 * gGlobalTimer)));
}

void gold_cloud_drift_xz(void) {
    
}

void gold_cloud_bounce(void) {
    o->oGravity = 0;
    if (o->oPosY < o->oHomeY) {
        o->oVelY += 4.0f;
    }
    else {
        o->oVelY -= 4.0f;
    }

    if (o->oTimer == 60) {
        //o->oAction = 2;
    }

    o->oVelY *= 0.95f;
    object_step();

    if (sqr(o->oPosY - o->oHomeY) < 30 && o->oVelY < 5.0f) {
        o->oAction = 2;
    }
}
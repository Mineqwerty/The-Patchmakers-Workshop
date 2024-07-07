void bhv_tentacle_cage_init(void) {
    for (int i = 0; i < o->oBehParams2ndByte; i++) {
        struct Object *eye = spawn_object_relative(0, 0, 600, 0, o, MODEL_CAGE_EYE, bhvCageEye);
        //why
        eye->oF4 = ((i+1) / 2) * (-1 + 2*(i%2));
    }

    o->oHealth = 8 * o->oBehParams2ndByte;
    o->oTentacleCageMaxHealth = o->oHealth;
}

void bhv_tentacle_cage_loop(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    obj_die_if_health_non_positive();

    if (o->oHealth <= 0) {
        obj_mark_for_deletion(o);
    }

    if (o->oHealth < o->oTentacleCageMaxHealth && o->oHealth > 0) {
        o->oHealth = o->oTentacleCageMaxHealth;
    }
}


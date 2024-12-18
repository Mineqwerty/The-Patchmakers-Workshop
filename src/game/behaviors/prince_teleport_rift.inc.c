void bhv_prince_teleport_rift_init(void) {

}

void bhv_prince_teleport_rift_loop(void) {
    cur_obj_scale(CLAMP(sins(o->oTimer * 0x444), 0.02f, 1.0f));

    if (o->oTimer == 30) {
        obj_mark_for_deletion(o);
    }
}


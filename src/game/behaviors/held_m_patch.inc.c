void bhv_held_m_patch_init(void) {
   
}

void bhv_held_m_patch_loop(void) {
    if (o->oTimer == 180)  {
        obj_mark_for_deletion(o);
    }
}


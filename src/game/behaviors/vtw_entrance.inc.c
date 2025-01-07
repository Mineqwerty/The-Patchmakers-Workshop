void bhv_vtw_entrance_init(void) {
    if (gMarioState->numStars < 24) {
        obj_mark_for_deletion(o);
    }
    else {
        struct Object *warp = spawn_object_relative(o->oBehParams2ndByte, 0, 0, 0, o, MODEL_NONE, bhvFadingWarp);
        warp->oBehParams = o->oBehParams;
    }
}

void bhv_vtw_entrance_loop(void) {

}


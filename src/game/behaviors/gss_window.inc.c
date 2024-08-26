void bhv_gss_window_init(void) {
    if (gMarioState->numStars >= 8) {
        cur_obj_set_model(MODEL_GSS_WINDOW_LIT);
    }
    else {
        cur_obj_set_model(MODEL_GSS_WINDOW_UNLIT);
    }
}

void bhv_gss_window_loop(void) {

}

void bhv_gss_window_light_init(void) {
    if (gMarioState->numStars < 8) {
        obj_mark_for_deletion(o);
    }
}

void bhv_gss_window_light_loop(void) {
   
}


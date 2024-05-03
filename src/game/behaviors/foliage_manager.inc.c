void bhv_foliage_manager_init(void) {
   
}

void bhv_foliage_manager_loop(void) {
    //if (gGlobalTimer > 90 ){
    extern u8 ssl_dl_foliageshados_i8[];
    calculate_foliage_scroll(segmented_to_virtual(ssl_dl_foliageshados_i8));
    //}
}


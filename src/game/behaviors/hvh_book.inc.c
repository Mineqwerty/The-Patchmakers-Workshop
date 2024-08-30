static struct ObjectHitbox sHvhBookHitbox = {
    /* interactType:      */ INTERACT_BBH_ENTRANCE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_hvh_book_init(void) {
    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_HVH) {
                cur_obj_set_model(MODEL_HVH_BOOK_ACTIVE);
                o->oAction = 1;
            }
            
}

void bhv_hvh_book_loop(void) {
    switch (o->oAction) {
        case 0:
            if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_COURSE_HVH) {
                cur_obj_set_model(MODEL_HVH_BOOK_ACTIVE);
                o->oAction = 1;
            }
        break;
        case 1:
            obj_set_hitbox(o, &sHvhBookHitbox);
            if (obj_check_if_collided_with_object(o, gMarioObject)) {
                o->oAction = 2;
            }
        break;
    }
    
}


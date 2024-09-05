void bhv_sight_door_init(void) {

}

void bhv_sight_door_loop(void) {
    f32 dist;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSightChamberController, &dist);

    if (o->parentObj && o->parentObj->oAction == 1) {
        obj_mark_for_deletion(o);
    }
}


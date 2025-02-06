void bhv_portal_puzzle_barrier_init(void) {
    //lol
    gMarioState->boostTimer = 0;
}

void bhv_portal_puzzle_barrier_loop(void) {
   struct Object *floorSwitch = cur_obj_find_object_with_bparam_2nd_byte(bhvFloorSwitchHardcodedModel, o->oBehParams2ndByte);

   if (floorSwitch && floorSwitch->oAction == 5) {
    if (o->oAction == 0) {
        o->oAction = 1;
        o->oTimer = 0;
    }
   }
   else if (o->oAction == 2) {
    o->oAction = 3;
     o->oTimer = 0;
   }
   
   if (o->oAction == 0) {
    load_object_collision_model();
    o->oPrimColorParams = 0;
   }

   else if (o->oAction == 1) {
        load_object_collision_model();
        o->oPrimColorParams = o->oTimer * 12;
        if (o->oTimer > 20) {
            o->oPrimColorParams = 255;
            o->oAction = 2;
        }
   }

    //invisible
   else if (o->oAction == 2) {
    o->oPrimColorParams = 255;
   }


   else if (o->oAction == 3) {
        load_object_collision_model();
        o->oPrimColorParams = 255 - (o->oTimer * 12);
        if (o->oTimer > 20) {
            o->oPrimColorParams = 0;
            o->oAction = 0;
        }
   }
}


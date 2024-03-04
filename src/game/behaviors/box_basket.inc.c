void bhv_box_basket_init(void) {
   switch (o->oBehParams2ndByte) {
    case 1:
        SET_BPARAM1(o->oPrimColorParams, 255);
    break;  
    case 2:
        SET_BPARAM2(o->oPrimColorParams, 255);
    break;  
    case 3:
        SET_BPARAM3(o->oPrimColorParams, 255);
    break;  
   }
}

void bhv_box_basket_loop(void) {
    struct Object *nearBox = cur_obj_find_object_with_bparam_2nd_byte(bhvTfpPuzzleBox, o->oBehParams2ndByte);
    f32 dist;
    if (nearBox && o->oAction == 0) {
        
    vec3f_get_dist(&o->oPosVec, &nearBox->oPosVec, &dist);
        if (dist < 300.0f && gMarioState->heldObj != nearBox) {
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                obj_mark_for_deletion(nearBox);
                nearBox = spawn_object_relative(o->oBehParams2ndByte, 0, 50, 0, o, MODEL_GRABBABLE_PUZZLE_BOX, bhvStaticObject);
                switch (o->oBehParams2ndByte) {
    case 1:
        SET_BPARAM1(nearBox->oPrimColorParams, 255);
    break;  
    case 2:
        SET_BPARAM2(nearBox->oPrimColorParams, 255);
    break;  
    case 3:
        SET_BPARAM3(nearBox->oPrimColorParams, 255);
    break;  
   }
                struct Object *counter = cur_obj_find_nearest_object_with_behavior(bhvBoxCounter, &dist);
                if (counter) {
                    counter->oF4 -= 1;
                }
                o->oAction++;
        }
    }
    else {
        if (o->parentObj) {
            //o->parentObj->oPosX = o->oPosX;
            //o->parentObj->oPosY = o->oPosY;
            //o->parentObj->oPosZ = o->oPosZ;
        }
    }
}

void bhv_box_counter_init(void) {
   o->oF4 = 3;
}

void bhv_box_counter_loop(void) {
    o->oPosX = gMarioState->pos[0];
    o->oPosY = gMarioState->pos[1];
    o->oPosZ = gMarioState->pos[2];
   if (o->oF4 == 0) {
        struct Object *star = spawn_star(o, gMarioState->pos[0], gMarioState->pos[1] + 1000.0f, gMarioState->pos[2]);
        star->oBehParams = 0x04000000;
        star->oPosX = gMarioState->pos[0];
        star->oPosY = gMarioState->pos[1];
        star->oPosZ = gMarioState->pos[2];
        star->oHomeX = gMarioState->pos[0];
        star->oHomeY = gMarioState->pos[1] + 300;
        star->oHomeZ = gMarioState->pos[2];
        o->oF4 = -1;
   }
}


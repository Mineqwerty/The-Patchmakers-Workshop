void bhv_underwater_stone_door_init(void) {

}

void bhv_underwater_stone_door_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer >= o->oBehParams2ndByte * 30) {
                o->oAction++;
            }
        break;
        case 1:
            o->oPosY -= 40.0f;
            if (o->oTimer == 45) {
                o->oAction++;
            }
        break;
        case 2:;
            struct Object *button = cur_obj_find_object_with_bparam_2nd_byte(bhvUnderwaterStoneButton, o->oBehParams2ndByte);

            if (button && button->oAction > 0) {
                o->oAction = 3;
            }
        break;
        case 3:
            o->oPosY += 40.0f;
            if (o->oTimer == 45) {
                o->oAction++;
            }
        break;
    }
}

struct ObjectHitbox sUnderwaterStoneButtonHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  20,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 150,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 200,
};

void bhv_underwater_stone_button_init(void) {
    
}

void bhv_underwater_stone_button_loop(void) {
    obj_set_hitbox(o, &sUnderwaterStoneButtonHitbox);
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 300 && gMarioState->action == ACT_MARINE_PATCH_SPIN) {
                o->oAction++;
            }
        break;
        case 1:
            cur_obj_scale_over_time(SCALE_AXIS_Z, 10, 1.0f, 0.4f);
            if (o->oTimer == 10) {
                o->oAction++;
            }
        break;
    }
    load_object_collision_model();
}


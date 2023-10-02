#include "levels/castle_inside/header.h"

void bhv_stc_door_init(void) {
    switch(o->oBehParams2ndByte) {
        case 0:
            o->collisionData = segmented_to_virtual(&stc_entrance_door_collision);
        break;
        case 1:
            o->collisionData = segmented_to_virtual(&stc_entrance_door2_collision);
        break;
    }
}

void bhv_stc_door_loop(void) {
   
}


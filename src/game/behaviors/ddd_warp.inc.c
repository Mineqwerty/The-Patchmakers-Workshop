// ddd_warp.inc.c

void bhv_ddd_warp_loop(void) {
#ifndef UNLOCK_ALL
    if (gDddPaintingStatus & DDD_FLAG_BOWSERS_SUB_BEATEN) {
#endif
        o->collisionData = segmented_to_virtual(NULL);
#ifndef UNLOCK_ALL
    } else {
        o->collisionData = segmented_to_virtual(NULL);
    }
#endif
}

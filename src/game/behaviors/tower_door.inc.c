// tower_door.inc.c

void bhv_tower_door_loop(void) {
    if (o->oTimer == 0) {
        o->oMoveAngleYaw -= 0x4000;
    }
}

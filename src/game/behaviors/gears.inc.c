void bhv_stone_gear_loop(void) {
    switch (o->oAction) {
        case 0:
    if (gGlobalTimer % 85 == 0) {
                o->oAction++;
                o->oTimer = 0;
                cur_obj_play_sound_2(SOUND_GENERAL_BIG_CLOCK);
            }
            break;
            case 1:
            if (o->oBehParams2ndByte == 0) {
                o->oFaceAngleYaw += 0x666;
                o->oMoveAngleYaw += 0x666;
            }
            else {
                o->oFaceAngleYaw -= 0x666;
                o->oMoveAngleYaw -= 0x666;
            }
            if (o->oTimer == 4) {
                o->oAction = 0;
            }
    }
}










#define ACT_STONE_TOWER_DOOR_CLOSED 0
#define ACT_STONE_TOWER_DOOR_OPENING 1
#define ACT_STONE_TOWER_DOOR_OPEN 2
#define ACT_STONE_TOWER_DOOR_CLOSING 3

void bhv_stone_tower_door_init(void) {
    o->oAction = o->oBehParams2ndByte;
    gGlobalTimer = 0;
}

void bhv_stone_tower_door_loop(void) {
    switch (o->oAction) {
        case ACT_STONE_TOWER_DOOR_CLOSED:
        case ACT_STONE_TOWER_DOOR_OPEN:
            if (gGlobalTimer % 85 == 0) {
                o->oAction++;
                o->oTimer = 0;
            }
            break;
        case ACT_STONE_TOWER_DOOR_OPENING:
            if (o->oTimer < 11) {
                o->oPosX -= 20 * sins(o->oFaceAngleYaw);
                o->oPosZ -= 20 * coss(o->oFaceAngleYaw);
            }
            else {
                o->oAction = ACT_STONE_TOWER_DOOR_OPEN;
            }
            break;
        case ACT_STONE_TOWER_DOOR_CLOSING:
            if (o->oTimer < 11) {
                o->oPosX += 20 * sins(o->oFaceAngleYaw);
                o->oPosZ += 20 * coss(o->oFaceAngleYaw);
            }
            else {
                o->oAction = ACT_STONE_TOWER_DOOR_CLOSED;
            }
            break;
    }

    if (o->oAction == ACT_STONE_TOWER_DOOR_OPEN) {
        cur_obj_hide();
    }
    else {
        cur_obj_unhide();
    }
}
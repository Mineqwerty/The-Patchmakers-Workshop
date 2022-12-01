void bhv_stone_gear_loop(void) {

    u8 turnTimer = 85;

    if (gMarioState->action == ACT_GRAPPLE_WALL) {
        turnTimer = 42;
    }

    switch (o->oAction) {
        case 0:
    if (gGlobalTimer % turnTimer == 0 && gMarioState->curPatch != 3) {
                o->oAction++;
                o->oTimer = 0;
                cur_obj_play_sound_2(SOUND_GENERAL_BIG_CLOCK);
            }
            break;
            case 1:
            if (o->oBehParams2ndByte % 2 == 0) {
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

    if (o->oBehParams2ndByte >= 2) {
        obj_scale_xyz(o, 1, 2, 1);
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

void bhv_grapple_stone_loop(void) {
    
if (o->oBehParams2ndByte == 0) {
    if (gGlobalTimer % 42 == 0) {
            if (gMarioState->curPatch != 3 || o->oAction % 2 == 1) {
                o->oAction++;
            }
                if (o->oAction > 3) {
                    o->oAction = 0;
                }
            }

    switch(o->oAction) {
        
        case 1:
            o->oPosX -= sins(o->oFaceAngleYaw) * 40.0f;
            o->oPosZ -= coss(o->oFaceAngleYaw) * 40.0f;
        break;
        case 3:
            o->oPosX += sins(o->oFaceAngleYaw) * 40.0f;
            o->oPosZ += coss(o->oFaceAngleYaw) * 40.0f;
        break;
    }
}
else if (o->oBehParams2ndByte == 1){
    if (gGlobalTimer % 42 == 0) {
        if (gMarioState->curPatch != 3 || o->oAction % 2 == 1) {
                o->oAction++;
        }
                if (o->oAction > 3) {
                    o->oAction = 0;
                }
            }
    switch(o->oAction) {
        case 1:
        case 3:
            o->oMoveAngleYaw += (0x8000 / 42);
        break;
    }
}

else {
    if (gGlobalTimer % 42 == 0) {
            if (gMarioState->curPatch != 3 || o->oAction % 2 == 1) {
                o->oAction++;
            }
                if (o->oAction > 3) {
                    o->oAction = 0;
                }
            }

    switch(o->oAction) {
        
        case 1:
            o->oPosY += 30.0f;
        break;
        case 3:
            o->oPosY -= 30.0f;
        break;
    }
}


}

void bhv_rotating_stone_cylinder_loop(void) {
    if (gMarioState->curPatch != 3) {
        o->oMoveAngleYaw += 0x400 * (1 - (o->oBehParams2ndByte * 2));
    }
    //else {
        //o->oMoveAngleYaw += 0x100 * (1 - (o->oBehParams2ndByte * 2));
    //}
}
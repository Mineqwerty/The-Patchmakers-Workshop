#include "src/game/game_init.h"

void bhv_stone_gear_loop(void) {

    u8 turnTimer = 16;

    if (gMarioState->action == ACT_GRAPPLE_WALL) {
        turnTimer = 8;
    }

    switch (o->oAction) {
        case 0:
            if (gMarioState->curPatch != 3 && (gTatumCount / 41) % turnTimer == 0) {
                o->oAction++;
                o->oTimer = 0;
                cur_obj_play_sound_2(SOUND_GENERAL_BIG_CLOCK);
            }
            break;
        case 1:
            if (o->oBehParams2ndByte % 2 == 0) {
                o->oFaceAngleYaw += 0x666;
                o->oMoveAngleYaw += 0x666;
            } else {
                o->oFaceAngleYaw -= 0x666;
                o->oMoveAngleYaw -= 0x666;
            }
            if (o->oTimer == 4) {
                o->oAction = 0;
            }
            break;
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
            } else {
                o->oAction = ACT_STONE_TOWER_DOOR_OPEN;
            }
            break;
        case ACT_STONE_TOWER_DOOR_CLOSING:
            if (o->oTimer < 11) {
                o->oPosX += 20 * sins(o->oFaceAngleYaw);
                o->oPosZ += 20 * coss(o->oFaceAngleYaw);
            } else {
                o->oAction = ACT_STONE_TOWER_DOOR_CLOSED;
            }
            break;
    }

    if (o->oAction == ACT_STONE_TOWER_DOOR_OPEN) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }
}

void bhv_grapple_stone_loop(void) {

    if (o->oBehParams2ndByte == 0) {
        if (o->oAction % 2 == 0 && (gTatumCount / 41) % 16 == 0) {
            if (gMarioState->curPatch != 3) {
                return o->oAction++;
            }
        }

        u8 distance;

        switch (o->oAction) {

            case 1:

                distance = GET_BPARAM1(o->oBehParams);

                o->oPosX -= sins(o->oFaceAngleYaw) * (((f32)distance) * 10.0f / 15.0f);
                o->oPosZ -= coss(o->oFaceAngleYaw) * (((f32)distance) * 10.0f / 15.0f);
                if (o->oTimer == 14) {
                o->oAction++;
                }
                break;
            case 3:
                o->oPosX += sins(o->oFaceAngleYaw) * (((f32)distance) * 10.0f / 15.0f);
                o->oPosZ += coss(o->oFaceAngleYaw) * (((f32)distance) * 10.0f / 15.0f);
                if (o->oTimer == 14) {
                o->oAction = 0;
                }
                break;
        }
    } else if (o->oBehParams2ndByte == 1) {
        if (o->oAction % 2 == 0) {
            if ((gTatumCount / 41) % 8 == 0) {
                if (gMarioState->curPatch != 3) {
                    o->oPrimColorParams = 0x9500FFFF;
                    o->oBeatNumber = 8;
                    return o->oAction++;
                }
            }

            if ((gTatumCount / 41) % 8 == 4 && o->oBeatNumber != 4) {
                o->oBeatNumber = 4;
                o->oPrimColorParams = 0x3A4b54FF;
            }
            if ((gTatumCount / 41) % 8 == 6 && o->oBeatNumber != 6) {
                o->oBeatNumber = 6;
                o->oPrimColorParams = 0x3A4b54FF;
            }
        }

        switch (o->oAction) {
            case 1:
            case 3:
                o->oMoveAngleYaw += (0x8000 / 16);
                if (o->oTimer == 15) {
                    o->oAction++;
                    if (o->oAction > 3) {
                        o->oAction = 0;
                    }
                }
                break;
        }
    }

    else {
        if (o->oAction % 2 == 0 && (gTatumCount / 41) % 8 == 0) {
            if (gMarioState->curPatch != 3) {
                return o->oAction++;
            }
        }

        // TODO: sort out a bparam system for distance and time traveled.
        if (o->oTimer == 15) {
            o->oAction++;
            if (o->oAction > 3) {
                o->oAction = 0;
            }
        }

        switch (o->oAction) {

            case 1:
                o->oPosY += 30.0f;
                break;
            case 3:
                o->oPosY -= 30.0f;
                break;
        }
    }

    grapple_stone_shift_color_to_grey();
}

void grapple_stone_shift_color_to_grey(void) {
    u8 r = GET_BPARAM1(o->oPrimColorParams);
    u8 g = GET_BPARAM2(o->oPrimColorParams);
    u8 b = GET_BPARAM3(o->oPrimColorParams);

    if (r > 0x10) {
        r -= 0x10;
        if (r < 0x10)
            r = 0x00;
    }
    if (g > 0x10) {
        g -= 0x10;
        if (g < 0x10)
            g = 0x00;
    }
    if (b > 0x10) {
        b -= 0x10;
        if (b < 0x10)
            b = 0x00;
    }

    SET_BPARAM1(o->oPrimColorParams, r);
    SET_BPARAM2(o->oPrimColorParams, g);
    SET_BPARAM3(o->oPrimColorParams, b);
}

void bhv_rotating_stone_cylinder_loop(void) {
    if (gMarioState->curPatch != 3) {
        o->oMoveAngleYaw += 0x400 * (1 - (o->oBehParams2ndByte * 2));
    }
    // else {
    // o->oMoveAngleYaw += 0x100 * (1 - (o->oBehParams2ndByte * 2));
    //}
}

void bhv_stone_elevator_loop(void) {
    switch (o->oAction) {
        case 0:
        case 2:
            if ((gTatumCount / 41) % 4 == 0) {
                //check if elevator is ascending and if mario is on it
                if (o->oAction != 2 && gMarioObject->platform == o) {
                    o->oAction++;
                }
                //check if elevator is descending and if mario isnt on it
                else if (o->oAction == 2 && gMarioObject->platform != o) {
                    o->oAction++;
                }
                //after 3 seconds of mario not being on the elevator while it was ascending, start descending.
                else if (o->oTimer > 90 && o->oAction == 0 && gMarioObject->platform != o && o->oF4 > 0) {
                    o->oAction = 2;
                    o->oF4 = 8 - o->oF4 + 1;
                }
            }
            break;
        case 1:
            o->oPosY += o->oBehParams2ndByte * 5.0f;
            if (o->oTimer == 5) {
                if (o->oF4 == 8) {
                    o->oAction++;
                    o->oF4 = 0;
                } else {
                    o->oAction--;
                    o->oF4++;
                }
            }
            break;
        case 3:
            o->oPosY -= o->oBehParams2ndByte * 5.0f;
            if (o->oTimer == 5) {
                if (o->oF4 == 8) {
                    o->oAction = 0;
                    o->oF4 = 0;
                } else {
                    o->oAction--;
                    o->oF4++;
                }
            }
            break;
    }
}

void bhv_extending_stone_bridge_init(void) {
    if (o->oBehParams2ndByte == 0) {
        for (int i = 1; i < 7; i++) {
            struct Object *nextPanel = spawn_object_relative(
                i, 0, 0, 0, o, MODEL_EXTENDING_STONE_BRIDGE, bhvExtendingStoneBridge);
            obj_scale_xyz(nextPanel, 0.99f, 1.0f - (((f32) i) * 0.05f), 1.0f - (((f32) i) * 0.05f));
        }
    }

    o->oHomeX = o->oPosX;
}

void bhv_extending_stone_bridge_loop(void) {
    if (o->oAction == 0) {
        if (o->oPosX < o->oHomeX + (1120 * (o->oBehParams2ndByte + 1))) {
            o->oPosX += 40;
        } else {
            o->oAction++;
        }
    }
}
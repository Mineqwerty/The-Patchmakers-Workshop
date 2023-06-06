#include "src/game/cutscene.h"

void bhv_rosedrift_cutscene_init(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oBehParams = 0x00170000;
        o->oBehParams2ndByte = 23;
    }
}

void bhv_rosedrift_cutscene_loop(void) {
    if (o->oBehParams2ndByte == 23) {
        if (cCutsceneActive == 0) {
            obj_mark_for_deletion(o);
        }
    } else {
        o->oForwardVel = 20.0f;
        o->oPosY -= 3.0f;

        if (o->oTimer > 120) {
            obj_mark_for_deletion(o);
        }
    }
}

Gfx *geo_switch_rosedrift_eyes(s32 callContext, struct GraphNode *node) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        switch (obj->oBehParams2ndByte) {
            case 20:
                switchCase->selectedCase = 1;
                break;
            case 21:
                switchCase->selectedCase = 2;
                break;
            case 22:
                switchCase->selectedCase = 3;
                break;
            case 23:
                switchCase->selectedCase = 2;
                break;
            default:
                switchCase->selectedCase = 0;
                break;
        }

        u8 bParam1 = GET_BPARAM1(obj->oBehParams);

        if (bParam1 != 0) {
            switch (bParam1) {
            case 20:
                switchCase->selectedCase = 1;
                break;
            case 21:
                switchCase->selectedCase = 2;
                break;
            case 22:
                switchCase->selectedCase = 3;
                break;
            case 23:
                switchCase->selectedCase = 2;
                break;
            default:
                switchCase->selectedCase = 0;
                break;
        }
        }
    }
    return NULL;
}

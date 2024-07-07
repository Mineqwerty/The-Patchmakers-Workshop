#include "src/game/save_file.h"

void bhv_patch_upgrade_init(void) {
    if (save_file_get_collected_patch_upgrades(gCurrSaveFileNum - 1) & o->oBehParams2ndByte) {
        obj_mark_for_deletion(o);
    }
}

void bhv_patch_upgrade_loop(void) {

    o->oFaceAnglePitch = 0x200 * sins(o->oTimer * 0x111);
    o->oFaceAngleYaw += 0x200;

    if (o->oDistanceToMario < 200.0f) {
        save_file_set_collected_patch_upgrades(gCurrSaveFileNum - 1, (1 << o->oBehParams2ndByte));
        obj_mark_for_deletion(o);
    }
}


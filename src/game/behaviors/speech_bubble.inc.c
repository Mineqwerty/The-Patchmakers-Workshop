void bhv_speech_bubble_init(void) {
   
}

void bhv_speech_bubble_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_scale(1.0f + 0.2f * sins(o->oTimer * 0x222));
            if (gDialogID != -1 || o->parentObj->oSewniaHasSpawnedSpeechBubble == 0) {
                o->oAction = 1;
            }
        break;
        case 1:
            cur_obj_scale(1.0f - ((f32)o->oTimer / 30.0f));

            if (o->oTimer == 29) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}


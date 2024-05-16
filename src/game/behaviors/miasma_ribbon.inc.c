void bhv_miasma_ribbon_init(void) {
    cur_obj_hide();
    cur_obj_init_animation_and_anim_frame(random_u16() % 2, 0);
}

void bhv_miasma_ribbon_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oBehParams2ndByte > 0) {
                o->oBehParams2ndByte--;
            }
            else {
                o->oAction = 1;
                cur_obj_unhide();

                if (GET_BPARAM1(o->oBehParams) == 1) {
                    o->oAction = 2;
                    o->oMoveAngleYaw = random_u16();
                }
                
            }

            cur_obj_scale(0.02f);
        break;
        case 1:
            if (o->oTimer < 10) {
                cur_obj_scale(CLAMP(((f32)o->oTimer) / 10.0f, 0.02f, 1.0f));
            }
            else if (o->oTimer < 20) {
                cur_obj_scale(1.0f);
            }
            else {
                cur_obj_scale(CLAMP(((f32)(30 - o->oTimer) / 10.0f), 0.02f, 1.0f));
            }

            if (o->oTimer == 30) {
                obj_mark_for_deletion(o);
            }
        break;
        case 2:
            if (o->oTimer < 10) {
                cur_obj_scale(CLAMP(((f32)o->oTimer) / 5.0f, 0.02f, 1.0f));
            }
            else if (o->oTimer < 20) {
                cur_obj_scale(2.0f);
            }
            else {
                cur_obj_scale(CLAMP(((f32)(30 - o->oTimer) / 5.0f), 0.02f, 1.0f));
            }

            if (o->oTimer == 30) {
                obj_mark_for_deletion(o);
            }

            o->oFaceAngleYaw += random_u16() % 4096;
            o->oMoveAngleYaw = o->oFaceAngleYaw;
        break;
    }
    
}


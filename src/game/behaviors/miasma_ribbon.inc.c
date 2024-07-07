void bhv_miasma_ribbon_init(void) {
    cur_obj_hide();
    if (GET_BPARAM1(o->oBehParams) == 2) {
        cur_obj_init_animation_and_anim_frame(0, 5);
    }
    else {
        cur_obj_init_animation_and_anim_frame(random_u16() % 2, 0);
    }
    
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
                if (GET_BPARAM1(o->oBehParams) == 2) {
                    o->oAction = 3;
                    
                }

                cur_obj_play_sound_1(SOUND_NEW_MIASMA_GROW);
                
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

            if (o->oTimer == 11 && GET_BPARAM3(o->oBehParams) == 1) {
                u8 charges = gMarioState->miasmaSoulCount;
                gMarioState->miasmaSoulCount = 0;
                obj_attack_in_radius(o, 1200.0f, charges * 8, 2);
            }

            if (o->oTimer == 15) {
                spawn_object_relative(0, 0, 0, 400 + random_u16()%120, o, MODEL_RED_FLAME, bhvFlameLargeBurningOut);
            }

            if (o->oTimer == 30) {
                obj_mark_for_deletion(o);
            }

            o->oFaceAngleYaw += random_u16() % 4096;
            o->oMoveAngleYaw = o->oFaceAngleYaw;
        break;
        case 3:
            cur_obj_init_animation_with_accel_and_sound(0, 1.7f);
            if (o->oTimer < 4) {
                cur_obj_scale(CLAMP(((f32)o->oTimer) / 4.0f, 0.02f, 1.0f));
            }
            else if (o->oTimer < 11) {
                cur_obj_scale(1.0f);
            }
            else {
                cur_obj_scale(CLAMP(((f32)(16 - o->oTimer) / 5.0f), 0.02f, 1.0f));
            }

            if (o->oTimer == 3) {
                cur_obj_play_sound_1(SOUND_NEW_MIASMA_SLICE);
            }

            if (o->oTimer == 9) {
                obj_attack_in_quad(o, 1000.0f, 500.0f, 200.0f, 600.0f, 4, 2);
            }

            if (o->oTimer == 16) {
                obj_mark_for_deletion(o);
            }
        break;

        
    }

    o->oForwardVel = gMarioState->forwardVel;
        cur_obj_move_xz_using_fvel_and_yaw();
    
}


void bhv_stone_patch_cutscene_shard_init(void) {
    cur_obj_set_model(MODEL_SHARD_START + o->oBehParams2ndByte);
    o->oGravity = 2.0f;
    o->oBounciness = 0;
}

void bhv_stone_patch_cutscene_shard_loop(void) {
    if (o->oAction == 0 && gMarioState->action == ACT_COLLECTING_PATCH && gMarioState->actionArg == 7) {
        o->oAction++;
    }
    else if (o->oAction == 1) {
        o->oVelY = random_f32_around_zero(10.0f) - 20.0f;
        o->oAngleVelPitch = random_u16() / 128;
        o->oAngleVelRoll = random_u16() / 128;
        o->oAngleVelYaw = random_u16() / 128;
        o->oMoveAngleYaw = random_u16();
        o->oForwardVel = random_f32_around_zero(8.0f);
        o->oAction++;
    }
    else if (o->oAction == 2) {
        object_step_without_floor_orient();
        o->oFaceAngleYaw += o->oAngleVelYaw;
        o->oFaceAngleRoll += o->oAngleVelRoll;
        o->oFaceAnglePitch += o->oAngleVelPitch;

        if (o->oTimer > 30) {
            cur_obj_scale(1.0f - (((f32)o->oTimer - 30.0f) / 150.0f));
            if (o->oTimer == 179) {
                obj_mark_for_deletion(o);
            }
        }
    }
}


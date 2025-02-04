void bhv_shrine_shape_init(void) {

}

void bhv_shrine_shape_loop(void) {
    if (o->parentObj->oShrineShapeStep >= o->oBehParams2ndByte) {
        o->oFaceAnglePitch += 0x50 + 0x111 * o->oBehParams2ndByte;
        o->oFaceAngleYaw += 60*sins(0x222*(o->oTimer + 3*o->oBehParams2ndByte));
    }
    else if (o->parentObj->oShrineShapeStep >= 0) {
        o->oPosX = approach_f32_symmetric(o->oPosX, o->oPosX + (200*o->parentObj->oShrineShapeStep), 20);
    }
    else {
        o->oPosX = approach_f32_symmetric(o->oPosX, o->parentObj->oPosX + 1000*o->oBehParams2ndByte, 20);
    }
}

void bhv_shrine_shape_controller_init(void) {
    for (int i = 0; i < 5; i++) {
        spawn_object_relative(i, 1000*i, 0, 0, o, MODEL_SHRINE_SHAPE_BEGIN + i, bhvShrineShape);
    }
}

void bhv_shrine_shape_controller_loop(void) {
    if (gMarioState->pos[0] > o->oPosX && gMarioState->pos[1] > o->oPosY - 1000) {
        o->oShrineShapeStep = CLAMP((s32)(gMarioState->pos[0] - o->oPosX - (200*o->oShrineShapeStep))/1000, o->oShrineShapeStep, 4);
    }
    else {
        o->oShrineShapeStep = -1;
    }
}


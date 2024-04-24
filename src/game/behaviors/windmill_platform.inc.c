void bhv_windmill_platform_init(void) {
   
}

void bhv_windmill_platform_loop(void) {
    f32 offsetXZ;
    s16 offsetAngle;

    offsetAngle = o->parentObj->oFaceAngleRoll + o->oBehParams2ndByte * 0x4000;
    f32 bladeDist = 2000.0f;
    offsetXZ = bladeDist * coss(offsetAngle);

    o->oPosZ = o->parentObj->oPosZ - offsetXZ * sins(o->parentObj->oMoveAngleYaw);

    o->oPosY = o->parentObj->oPosY + bladeDist * sins(offsetAngle);

    o->oPosX = o->parentObj->oPosX + offsetXZ * coss(o->parentObj->oMoveAngleYaw);
}


void bhv_floating_table_init(void) {
    o->oFloatingTableInitYaw = o->oFaceAngleYaw;
}

void bhv_floating_table_loop(void) {
   o->oPosX = o->oHomeX + 400*(sins(o->oMoveAngleYaw) * coss(o->oTimer * 0x111));
   o->oPosZ = o->oHomeZ + 400*(coss(o->oMoveAngleYaw) * coss(o->oTimer * 0x111));

   o->oPosY = o->oHomeY + 100*sins(o->oTimer * 0x254);
   o->oFaceAngleYaw = o->oFloatingTableInitYaw + 0x200*sins(o->oTimer * 0x326) + (random_u16()%5);
   o->oFaceAngleRoll = o->oMoveAngleRoll + 0x100*sins(o->oTimer * 0x126) + (random_u16()%5);
   o->oFaceAnglePitch = o->oMoveAnglePitch + 0x100*sins(o->oTimer * 0x226) + (random_u16()%5);
}

void bhv_spinning_table_init(void) {
    obj_scale_xyz(o, 1.0f, 1.0f, 3.0f);
}

void bhv_spinning_table_loop(void) {
    o->oMoveAngleYaw += 0x100;
    o->oFaceAngleYaw += 0x100;
    o->oPosY = o->oHomeY + 100*sins(o->oTimer * 0x184);
}


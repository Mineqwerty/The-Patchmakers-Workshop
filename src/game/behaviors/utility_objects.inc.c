void bhv_coordinate_controller_init(void) {
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
}

void bhv_coordinate_controller_loop(void) {
    print_text_fmt_int(20, 200, "X %d", (int) o->oPosX);
    print_text_fmt_int(20, 180, "Y %d", (int) o->oPosY);
    print_text_fmt_int(20, 160, "Z %d", (int) o->oPosZ);

    o->oPosX += gPlayer1Controller->rawStickX;
    o->oPosZ += gPlayer1Controller->rawStickY;

    if (gPlayer1Controller->buttonDown & L_TRIG) {
        o->oPosY += 20.0f;
    }
    if (gPlayer1Controller->buttonDown & R_TRIG) {
        o->oPosY -= 20.0f;
    }

    if (gPlayer1Controller->buttonDown & D_JPAD) {
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
    }
}

void bhv_background_object_loop(void) {
    o->oPosX = gLakituState.goalPos[0];
    o->oPosY = gLakituState.goalPos[1];
    o->oPosZ = gLakituState.goalPos[2];

    cur_obj_scale(100.0f);
}
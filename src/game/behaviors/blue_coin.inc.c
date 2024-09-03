
/**
 * Behavior for bhvHiddenBlueCoin and bhvBlueCoinSwitch.
 * bhvHiddenBlueCoin are the stationary blue coins that appear when
 * you press a blue coin switch (a.k.a. bhvBlueCoinSwitch).
 */

/**
 * Update function for bhvHiddenBlueCoin.
 */
void bhv_hidden_blue_coin_loop(void) {
    struct Object *blueCoinSwitch;

    switch (o->oAction) {
        case HIDDEN_BLUE_COIN_ACT_INACTIVE:
            // Become invisible and intangible
            cur_obj_disable_rendering();
            cur_obj_become_intangible();

            // Set action to HIDDEN_BLUE_COIN_ACT_WAITING after the blue coin switch is found.
            o->oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(bhvBlueCoinSwitch);

            if (o->oHiddenBlueCoinSwitch != NULL) {
                o->oAction = HIDDEN_BLUE_COIN_ACT_WAITING;
            }

            break;

        case HIDDEN_BLUE_COIN_ACT_WAITING:
            // Wait until the blue coin switch starts ticking to activate.
            blueCoinSwitch = o->oHiddenBlueCoinSwitch;

            if (blueCoinSwitch->oAction == BLUE_COIN_SWITCH_ACT_TICKING) {
                o->oAction = HIDDEN_BLUE_COIN_ACT_ACTIVE;
                o->oHiddenBlueCoinTimer = blueCoinSwitch->oBehParams2ndByte * 30;
            }

            break;

        case HIDDEN_BLUE_COIN_ACT_ACTIVE:
            // Become tangible
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // Delete the coin once collected
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                //spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                //obj_mark_for_deletion(o);
                blueCoinSwitch->oNumBlueCoinsCollected++;
                struct Object *bc = spawn_object_relative(0, 0, 10, 0, o, MODEL_BLUE_COIN_NO_SHADOW, bhvBlueCoinRotateAroundMario);
                bc->oLinkedBlueCoin = o;
                cur_obj_disable_rendering();
                cur_obj_become_intangible();
                o->oAction = 3;
            }

            if (cur_obj_wait_then_blink(o->oHiddenBlueCoinTimer, o->oHiddenBlueCoinTimer + 20)) {
                o->oAction = HIDDEN_BLUE_COIN_ACT_INACTIVE;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            }

            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_blue_coin_rotate_around_mario(void) {
    struct Object *blueCoinSwitch;

    switch (o->oAction) {
        case 0:
            o->oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(bhvBlueCoinSwitch);

            if (o->oHiddenBlueCoinSwitch != NULL) {
                o->oAction = 1;
            }

            break;

        case 1:
            blueCoinSwitch = o->oHiddenBlueCoinSwitch;

            f32 offsetAngle = o->oBehParams2ndByte * (0x8000 / CLAMP(blueCoinSwitch->oNumBlueCoinsCollected, 1, 256));

            approach_f32_asymptotic(o->oPosX, gMarioState->pos[0] + 600.0f * sins(blueCoinSwitch->oTimer * 0x222 + offsetAngle), 0.08f);
            approach_f32_asymptotic(o->oPosZ, gMarioState->pos[2] + 600.0f * coss(blueCoinSwitch->oTimer * 0x222 + offsetAngle), 0.08f);
            approach_f32_asymptotic(o->oPosY, gMarioState->pos[1] + 100.0f, 0.08f);

            if (o->oHiddenBlueCoinSwitch->oAction == 3) {
                o->oLinkedBlueCoin->oAction = 0;
                obj_mark_for_deletion(o);
            }

            break;

        case 2:
            //fly to mario

            break;
    }
}

/**
 * Update function for bhvBlueCoinSwitch.
 */
void bhv_blue_coin_switch_loop(void) {
    // The switch's model is 1/3 size.
    cur_obj_scale(3.0f);

    switch (o->oAction) {
        case BLUE_COIN_SWITCH_ACT_IDLE:
            // If Mario is on the switch and has ground-pounded,
            // recede and get ready to start ticking.
            if (gMarioObject->platform == o) {
                if (gMarioStates[0].action == ACT_GROUND_POUND_LAND) {
                    // Set to BLUE_COIN_SWITCH_ACT_RECEDING
                    o->oAction = BLUE_COIN_SWITCH_ACT_RECEDING;
                    o->oVelY = -16.0f;
                    // Set gravity to 0 so it doesn't accelerate when receding.
                    o->oGravity = 0.0f;

                    cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
                }
            }

            // Have collision
            load_object_collision_model();

            break;

        case BLUE_COIN_SWITCH_ACT_RECEDING:
            // Recede for 6 frames before going invisible and ticking.
            // This is probably an off-by-one error, since the switch is 100 units tall
            // and recedes at 20 units/frame, which means it will fully recede after 5 frames.
            if (o->oTimer > 3) {
                // Set to BLUE_COIN_SWITCH_ACT_TICKING
                o->oAction = BLUE_COIN_SWITCH_ACT_TICKING;
                // ???
                o->oVelY    = 0.0f;
                o->oGravity = 0.0f;
                // Spawn particles. There's a function that calls this same function
                // with the same arguments, spawn_mist_particles, why didn't they just call that?
                spawn_mist_particles_variable(0, 0, 46.0f);
            } else {
                // Have collision while receding
                load_object_collision_model();
                // Recede
                cur_obj_move_using_fvel_and_gravity();
            }

            break;

        case BLUE_COIN_SWITCH_ACT_TICKING:
            // Tick faster when the blue coins start blinking
            if (o->oTimer < (o->oBehParams2ndByte * 30)) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }

            if (cur_obj_nearest_object_with_behavior(bhvHiddenBlueCoin) == NULL) {
                spawn_mist_particles_variable(0, 0, 46.0f);
                //obj_mark_for_deletion(o);
                o->oAction = 4;
            // Set to BLUE_COIN_SWITCH_ACT_EXTENDING after the coins unload after the 240-frame timer expires.
            } else if (o->oTimer > 240) {
                o->oAction  = BLUE_COIN_SWITCH_ACT_EXTENDING;
                o->oVelY    = 16.0f;
                o->oGravity =  0.0f;
                o->oNumBlueCoinsCollected = 0;
            }
            load_object_collision_model();
            break;
        case BLUE_COIN_SWITCH_ACT_EXTENDING:
            if (o->oTimer > 3) {
                // Set to BLUE_COIN_SWITCH_ACT_IDLE
                o->oAction = BLUE_COIN_SWITCH_ACT_IDLE;
            } else {
                // Have collision while extending
                load_object_collision_model();
                // Extend
                cur_obj_move_using_fvel_and_gravity();
            }
            break;
            case 4:

            break;
    }
}

#include "src/game/cutscene.h"

void bhv_power_breaker_init(void) {
    if (gCurrActNum == 6) {
        o->oAction = 2;
    }
}

void bhv_power_breaker_loop(void) {
    f32 dist;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvPowerBreakerController, &dist);

    

    switch (o->oAction) {
        case 0:
            o->oFaceAngleRoll = 0x2000;

            if (o->parentObj) {
                if (o->oDistanceToMario < o->parentObj->oClosestMarioBreakerDistance) {
                    o->parentObj->oClosestMarioBreakerDistance = o->oDistanceToMario;
                    o->parentObj->oBreakerSpawnObject = o;
                }
            }

            if (o->oDistanceToMario < 150) {
                o->parentObj->oNumBreakersLeft--;
                cur_obj_play_sound_2(SOUND_GENERAL_BIG_CLOCK);
                o->oAction = 1;
            }
        break;
        case 1:
            o->oFaceAngleRoll -= 0x100;
            if (o->oFaceAngleRoll <= -0x2000) {
                o->oAction = 2;
            }
        break;
        case 2:
            o->oFaceAngleRoll = -0x2000;
        break;
    }
}

void bhv_power_breaker_controller_init(void) {
    o->oBreakerSpawnObject = o;
    o->oClosestMarioBreakerDistance = 32000;
    o->oNumBreakersLeft = 5;

    if (gCurrActNum == 6) {
        o->oAction = 3;
    }
}

void bhv_power_breaker_controller_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oNumBreakersLeft > 0) {
                if (o->oTimer == 40) {
                    switch (random_u16()%3) {
                        case 0:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_1, o->oBreakerSpawnObject);
                        break;
                        case 1:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_2, o->oBreakerSpawnObject);
                        break;
                        case 2:
                            other_obj_play_sound_2(SOUND_NEW_BREAKER_SPARK_3, o->oBreakerSpawnObject);
                        break;
                    }
                    o->oTimer = random_u16()%30;
                }

                if (random_u16()%5 == 0) {
                    struct Object *spark = spawn_object_relative(0, random_u16()%50-25, random_u16()%50-25, random_u16()%50-25, o->oBreakerSpawnObject, MODEL_BREAKER_SPARK, bhvBreakerSpark);
                    spark->oForwardVel = random_u16()%10;
                    spark->oMoveAngleYaw = random_u16();
                    spark->oVelY = random_u16()%15;
                }
            }
            else {
                begin_cutscene_event(CUTSCENE_EVENT_CITY_LIGHTS_ON);
                o->oAction = 1;
            }
        break;
        case 1:
            if (o->oTimer == 180) {
                SET_BPARAM1(o->oBehParams, 4);
                spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
            }
        break;
    }

    o->oClosestMarioBreakerDistance = 32000;
    
}

void bhv_breaker_spark_init(void) {

}

void bhv_breaker_spark_loop(void) {
    cur_obj_scale((f32)(30 - o->oTimer)/30.0f);
    if (o->oTimer == 29) {
        obj_mark_for_deletion(o);
    }

    o->oGravity = -1.0f;
    cur_obj_move_using_fvel_and_gravity();
}


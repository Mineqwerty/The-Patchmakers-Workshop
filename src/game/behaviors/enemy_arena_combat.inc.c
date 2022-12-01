void bhv_enemy_obelisk_loop() {

    f32 *dist;

    switch (o->oAction) {
        //forcefield spawning
        case 0:
            if (o->oDistanceToMario < 500.0f) {
                spawn_object(o, MODEL_FORCEFIELD, bhvEnemyForcefield);
                o->oAction++;
            }
        break;
        //wave 1 spawning
        case 1:
            if (o->oTimer > 30) {
                if (o->oTimer % 20 == 0) {
                    u16 randomSpot = random_u16();
                    spawn_object_relative(0, 1500 * sins(randomSpot), 20, 1500 * coss(randomSpot), o, MODEL_YARN_GOOMBA, bhvGoomba);
                }
            if (o->oTimer >= 120) {
                o->oAction++;
            }
            }
        break;
        //wave 1 happening
        case 2:
            print_text(20, 20, "wave 1");
            if (!cur_obj_find_nearest_object_with_behavior(bhvGoomba, &dist)) {
                o->oAction++;
            }
        break; 

        case 3:
            if (o->oTimer > 30) {
                if (o->oTimer % 20 == 0) {
                    u16 randomSpot = random_u16();
                    spawn_object_relative(0, 1500 * sins(randomSpot), 20, 1500 * coss(randomSpot), o, MODEL_CHUCKYA, bhvChuckya);
                    
                }
            if (o->oTimer >= 120) {
                o->oAction++;
            }
            }

        break;

        case 4:
            print_text(20, 20, "wave 2");
            if (!cur_obj_find_nearest_object_with_behavior(bhvChuckya, &dist)) {
                o->oAction++;
            }
        break; 

        case 5:
            if (o->oTimer > 30) {
                if (o->oTimer % 20 == 0) {
                    u16 randomSpot = random_u16();
                    spawn_object_relative(0, 1500 * sins(randomSpot), 20, 1500 * coss(randomSpot), o, MODEL_WHOMP, bhvSmallWhomp);
                    
                }
            if (o->oTimer >= 120) {
                o->oAction++;
            }
            }

        break;

        case 6:
            print_text(20, 20, "wave 3");
            if (!cur_obj_find_nearest_object_with_behavior(bhvSmallWhomp, &dist)) {
                o->oAction++;
            }
        break; 

        case 7:
            
            spawn_arena_star_stc(o->oPosX + 300, o->oPosY + 200, o->oPosZ + 300);
            o->oAction++;
        break;
    }

}
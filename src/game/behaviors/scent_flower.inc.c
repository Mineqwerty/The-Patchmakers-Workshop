#include "src/game/rendering_graph_node.h"

void bhv_scent_flower_init(void) {

}

void bhv_scent_flower_loop(void) {
    if (o->oDistanceToMario < 1000) {
        gFogScaler = CLAMP(gFogScaler + 0.008f, 0.02f, 1.0f);

        if (o->oTimer % 6 == 0) {
            struct Object *flame = spawn_object_relative(0, 0, 150, 0, o, MODEL_FIRE_SMOKE, bhvFireSmokeParticle);
            flame->oBehParams = 0x01000000;
        }
    }
}


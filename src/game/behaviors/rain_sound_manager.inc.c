#include "src/audio/external.h"
#include "src/game/camera.h"

void bhv_rain_sound_manager_init(void) {
   
}

void bhv_rain_sound_manager_loop(void) {
    play_secondary_music(38, 255, 255, 10);
    if (gCurrLevelNum == LEVEL_WF && gCurrAreaIndex == 3) {
        set_camera_mode(gMarioState->area->camera, CAMERA_MODE_SPIRAL_STAIRS, 1);
    }

}


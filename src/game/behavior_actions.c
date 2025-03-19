#include <PR/ultratypes.h>

#include "types.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/group13.h"
#include "area.h"
#include "audio/external.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "camera.h"
#include "debug.h"
#include "dialog_ids.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "engine/surface_load.h"
#include "game_init.h"
#include "ingame_menu.h"
#include "interaction.h"
#include "level_misc_macros.h"
#include "level_table.h"
#include "level_update.h"
#include "levels/bob/header.h"
#include "levels/bowser_3/header.h"
#include "levels/castle_inside/header.h"
#include "levels/hmc/header.h"
#include "main.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "mario_step.h"
#include "obj_behaviors.h"
#include "obj_behaviors_2.h"
#include "object_constants.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "paintings.h"
#include "platform_displacement.h"
#include "rendering_graph_node.h"
#include "save_file.h"
#include "seq_ids.h"
#include "sm64.h"
#include "spawn_object.h"
#include "spawn_sound.h"
#include "rumble_init.h"
#include "puppylights.h"

#include "behaviors/star_door.inc.c"
#include "behaviors/mr_i.inc.c"
#include "behaviors/pole.inc.c"
#include "behaviors/thi_top.inc.c"
#include "behaviors/capswitch.inc.c"
#include "behaviors/king_bobomb.inc.c"
#include "behaviors/beta_chest.inc.c"
#include "behaviors/water_objs.inc.c"
#include "behaviors/cannon.inc.c"
#include "behaviors/chuckya.inc.c"
#include "behaviors/breakable_wall.inc.c"
#include "behaviors/kickable_board.inc.c"
#include "behaviors/tower_door.inc.c"
#include "behaviors/rotating_platform.inc.c"
#include "behaviors/koopa_shell_underwater.inc.c"
#include "behaviors/warp.inc.c"
#include "behaviors/white_puff_explode.inc.c"

// not in behavior file
static struct SpawnParticlesInfo sMistParticles = {
    /* behParam:        */ 2,
    /* count:           */ 20,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 40,
    /* forwardVelRange: */ 5,
    /* velYBase:        */ 30,
    /* velYRange:       */ 20,
    /* gravity:         */ 252,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 330.0f,
    /* sizeRange:       */ 10.0f,
};

// generate_wind_puffs/dust (something like that)
void spawn_mist_particles_variable(s32 count, s32 offsetY, f32 size) {
    sMistParticles.sizeBase = size;
    sMistParticles.sizeRange = size / 20.0f;
    sMistParticles.offsetY = offsetY;

    if (count == 0) {
        sMistParticles.count = 20;
    } else if (count > 20) {
        sMistParticles.count = count;
    } else {
        sMistParticles.count = 4;
    }

    cur_obj_spawn_particles(&sMistParticles);
}

#include "behaviors/sparkle_spawn_star.inc.c"
#include "behaviors/coin.inc.c"
#include "behaviors/collide_particles.inc.c"
#include "behaviors/door.inc.c"
#include "behaviors/thwomp.inc.c"
#include "behaviors/tumbling_bridge.inc.c"
#include "behaviors/elevator.inc.c"
#include "behaviors/water_mist_particle.inc.c"
#include "behaviors/break_particles.inc.c"
#include "behaviors/water_mist.inc.c"
#include "behaviors/ground_particles.inc.c"
#include "behaviors/wind.inc.c"
#include "behaviors/unused_particle_spawn.inc.c"
#include "behaviors/ukiki_cage.inc.c"
#include "behaviors/falling_rising_platform.inc.c"
#include "behaviors/fishing_boo.inc.c"
#include "behaviors/flamethrower.inc.c"
#include "behaviors/bouncing_fireball.inc.c"
#include "behaviors/shock_wave.inc.c"
#include "behaviors/flame_mario.inc.c"
#include "behaviors/beta_fish_splash_spawner.inc.c"
#include "behaviors/spindrift.inc.c"
#include "behaviors/tower_platform.inc.c"
#include "behaviors/tree_particles.inc.c"
#include "behaviors/square_platform_cycle.inc.c"
#include "behaviors/piranha_bubbles.inc.c"
#include "behaviors/purple_switch.inc.c"
#include "behaviors/metal_box.inc.c"
#include "behaviors/breakable_box.inc.c"

// not sure what this is doing here. not in a behavior file.
Gfx *geo_move_mario_part_from_parent(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx) {

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (obj == gMarioObject && obj->prevObj != NULL) {
            obj_update_pos_from_parent_transformation(mtx, obj->prevObj);
            obj_set_gfx_pos_from_pos(obj->prevObj);
        }
    }

    return NULL;
}

#include "behaviors/heave_ho.inc.c"
#include "behaviors/spawn_star_exit.inc.c"
#include "behaviors/unused_poundable_platform.inc.c"
#include "behaviors/beta_trampoline.inc.c"
#include "behaviors/jumping_box.inc.c"
#include "behaviors/boo_cage.inc.c"

// not in behavior file
// n is the number of objects to spawn, r if the rate of change of phase (frequency?)
void spawn_sparkle_particles(s32 n, s32 radius, s32 height, s32 r) {
    static s16 spawnSparkleParticleAngle = 0x0;
    s32 i;
    s16 separation = 0x10000 / n; // Evenly spread around a circle

    for (i = 0; i < n; i++) {
        spawn_object_relative(OBJ_BP_NONE, sins(spawnSparkleParticleAngle + i * separation) * radius, (i + 1) * height,
                              coss(spawnSparkleParticleAngle + i * separation) * radius, o, MODEL_NONE, bhvSparkleSpawn);
    }

    spawnSparkleParticleAngle += r * 0x100;
}

#include "behaviors/beta_boo_key.inc.c"
#include "behaviors/grand_star.inc.c"
#include "behaviors/bowser_key.inc.c"
#include "behaviors/bullet_bill.inc.c"
#include "behaviors/bowser.inc.c"
#include "behaviors/bowser_falling_platform.inc.c"
#include "behaviors/bowser_flame.inc.c"
#include "behaviors/blue_fish.inc.c"
#include "behaviors/checkerboard_platform.inc.c"
#include "behaviors/ddd_warp.inc.c"
#include "behaviors/water_pillar.inc.c"
#include "behaviors/moat_drainer.inc.c"
#include "behaviors/bowser_key_cutscene.inc.c"
#include "behaviors/moat_grill.inc.c"
#include "behaviors/clock_arm.inc.c"
#include "behaviors/ukiki.inc.c"
#include "behaviors/lll_octagonal_rotating_mesh.inc.c"
#include "behaviors/lll_sinking_rock_block.inc.c"
#include "behaviors/lll_rotating_hex_flame.inc.c"
#include "behaviors/lll_floating_wood_piece.inc.c"
#include "behaviors/lll_volcano_flames.inc.c"
#include "behaviors/lll_hexagonal_ring.inc.c"
#include "behaviors/lll_sinking_rectangle.inc.c"
#include "behaviors/tilting_inverted_pyramid.inc.c"
#include "behaviors/tox_box.inc.c"
#include "behaviors/piranha_plant.inc.c"
#include "behaviors/bowser_puzzle_piece.inc.c"

void set_obj_anim_with_accel_and_sound(s16 frame1, s16 frame2, s32 sound) {
    s32 range = o->header.gfx.animInfo.animAccel / 0x10000;
    if (range == 0) {
        range = 1;
    }

    if (cur_obj_check_anim_frame_in_range(frame1, range) || cur_obj_check_anim_frame_in_range(frame2, range)) {
        cur_obj_play_sound_2(sound);
    }
}

#include "behaviors/tuxie.inc.c"
#include "behaviors/fish.inc.c"
#include "behaviors/express_elevator.inc.c"
#include "behaviors/bub.inc.c"
#include "behaviors/exclamation_box.inc.c"
#include "behaviors/sound_spawner.inc.c"
#include "behaviors/ddd_sub.inc.c"
#include "behaviors/sushi.inc.c"
#include "behaviors/jrb_ship.inc.c"
#include "behaviors/white_puff.inc.c"
#include "behaviors/blue_coin.inc.c"
#include "behaviors/grill_door.inc.c"
#include "behaviors/wdw_water_level.inc.c"
#include "behaviors/tweester.inc.c"
#include "behaviors/boo.inc.c"
#include "behaviors/bbh_tilting_trap.inc.c"
#include "behaviors/bbh_haunted_bookshelf.inc.c"
#include "behaviors/bbh_merry_go_round.inc.c"
#include "behaviors/static_checkered_platform.inc.c"
#include "behaviors/beta_bowser_anchor.inc.c"
#include "behaviors/music_touch.inc.c"
#include "behaviors/castle_floor_trap.inc.c"
#include "behaviors/pole_base.inc.c"
#include "behaviors/sparkle_spawn.inc.c"
#include "behaviors/scuttlebug.inc.c" // :scuttleeyes:
#include "behaviors/whomp.inc.c"
#include "behaviors/water_splashes_and_waves.inc.c"
#include "behaviors/strong_wind_particle.inc.c"
#include "behaviors/sl_snowman_wind.inc.c"
#include "behaviors/sl_walking_penguin.inc.c"

//bounce bulb in obj_behaviors_2.c
#include "behaviors/particle_spawners.inc.c"
//ptooie in obj_behaviors_2.c
#include "behaviors/npc.inc.c"
#include "behaviors/pushpin_pokey.inc.c"
#include "behaviors/utility_objects.inc.c"
#include "behaviors/patch_objects.inc.c"
//freezable enemies in obj_behaviors_2.c
#include "behaviors/gears.inc.c"
#include "behaviors/enemy_arena_combat.inc.c"
#include "behaviors/clouds.inc.c"
#include "behaviors/goddess_boss.inc.c"
#include "behaviors/sewnia.inc.c"
#include "behaviors/torch_holder.inc.c"
//spekturr in obj_behaviors_2.c
#include "behaviors/star_gate.inc.c"
#include "behaviors/fling_ring.inc.c"
#include "behaviors/the_patchmaker.inc.c"
//seraphim in obj_behaviors_2.c
#include "behaviors/floating_plane.inc.c"
//far plane cube in obj_behaviors_2.c
#include "behaviors/portal_puzzle_barrier.inc.c"
#include "behaviors/portal_window.inc.c"
#include "behaviors/tfp_growing_block.inc.c"
#include "behaviors/tfp_puzzle_box.inc.c"
#include "behaviors/tfp_rotary_platform.inc.c"
#include "behaviors/box_basket.inc.c"
#include "behaviors/ground_patch.inc.c"
#include "behaviors/sewnia_stopping_point.inc.c"
#include "behaviors/rosedrift_cutscene.inc.c"
//podogoo in obj behaviors 2 blah blah blah
#include "behaviors/far_plane_boost_panel.inc.c"
#include "behaviors/ring_mission_ring.inc.c"
#include "behaviors/ring_mission.inc.c"
#include "behaviors/ring_mission_target.inc.c"
#include "behaviors/tfp_checker_platform.inc.c"
#include "behaviors/wind_cloud.inc.c"
#include "behaviors/swinging_axe.inc.c"
#include "behaviors/wing_surface.inc.c"
#include "behaviors/stone_patch_cutscene_shard.inc.c"
#include "behaviors/patchmaker_file_select.inc.c"
#include "behaviors/new_file_select_manager.inc.c"
#include "behaviors/garage_door.inc.c"
#include "behaviors/stc_door.inc.c"
#include "behaviors/star_unlock_platform.inc.c"
#include "behaviors/gss_window.inc.c"
#include "behaviors/sub_sea_water_ring.inc.c"
#include "behaviors/underwater_stone_door.inc.c"
#include "behaviors/coral_spinner.inc.c"
#include "behaviors/text_volume.inc.c"

#include "behaviors/geyser.inc.c"

#include "behaviors/swinging_chandelier.inc.c"
#include "behaviors/floating_table.inc.c"
#include "behaviors/scaling_stairs.inc.c"
#include "behaviors/clc_puzzle_switch.inc.c"
#include "behaviors/blight.inc.c"
#include "behaviors/moving_spectral_octagon.inc.c"
#include "behaviors/eyebulb.inc.c"
#include "behaviors/awning.inc.c"
#include "behaviors/hidden_cannon.inc.c"
#include "behaviors/mistress.inc.c"
#include "behaviors/transmutation_table.inc.c"
#include "behaviors/transmutation_star.inc.c"
#include "behaviors/red_flower.inc.c"
#include "behaviors/windmill_fan.inc.c"
#include "behaviors/windmill_platform.inc.c"
#include "behaviors/goofy_warp.inc.c"
#include "behaviors/trailer_cam.inc.c"

#include "behaviors/patch_upgrade.inc.c"
#include "behaviors/rocket_flower.inc.c"
#include "behaviors/dice_boss.inc.c"
#include "behaviors/foliage_manager.inc.c"
#include "behaviors/floating_petal.inc.c"
#include "behaviors/rain_sound_manager.inc.c"
#include "behaviors/lily_pad.inc.c"
#include "behaviors/danger_puff.inc.c"
#include "behaviors/malva_flower.inc.c"
#include "behaviors/miasma_ribbon.inc.c"
#include "behaviors/story_cutscene_manager.inc.c"
#include "behaviors/floating_tilting_gem.inc.c"
#include "behaviors/abyss_swimmer.inc.c"
#include "behaviors/cage_eye.inc.c"

#include "behaviors/sky_slug.inc.c"

#include "behaviors/water_launcher.inc.c"

#include "behaviors/enemy_arena_combat_walls.inc.c"

#include "behaviors/corr_wind_controller.inc.c"
#include "behaviors/red_construction_light.inc.c"
#include "behaviors/power_breaker.inc.c"
#include "behaviors/cartoon_hand.inc.c"
#include "behaviors/paper_spinner.inc.c"
#include "behaviors/automaton.inc.c"
#include "behaviors/sound_menu.inc.c"
#include "behaviors/entrance_flame_spawn.inc.c"
#include "behaviors/clc_painting.inc.c"
#include "behaviors/shadow_transition_sphere.inc.c"
#include "behaviors/hvh_book.inc.c"
#include "behaviors/music_note.inc.c"
#include "behaviors/sight_cube.inc.c"
#include "behaviors/moving_sight_cube.inc.c"
#include "behaviors/sight_switch.inc.c"
#include "behaviors/sight_cracked_platform.inc.c"
#include "behaviors/sight_chamber_controller.inc.c"
#include "behaviors/sight_door.inc.c"
#include "behaviors/attack_impact_particle.inc.c"
#include "behaviors/shadow_ball.inc.c"
#include "behaviors/shadow_spike.inc.c"
#include "behaviors/scent_flower.inc.c"
#include "behaviors/sound_drum.inc.c"
#include "behaviors/taste_noise_spike_hitbox.inc.c"
#include "behaviors/taste_switch.inc.c"
#include "behaviors/taste_door.inc.c"
#include "behaviors/drawback_curtain.inc.c"
#include "behaviors/patch_challenge_menu.inc.c"
#include "behaviors/gilded_star.inc.c"
#include "behaviors/patch_challenge_controller.inc.c"
#include "behaviors/lift_cloud.inc.c"
#include "behaviors/paper_boo.inc.c"
#include "behaviors/master.inc.c"
#include "behaviors/cutscene_chair.inc.c"
#include "behaviors/eyebulb_star_spawner.inc.c"
#include "behaviors/character_plush.inc.c"
#include "behaviors/stab_needle.inc.c"
#include "behaviors/held_m_patch.inc.c"
#include "behaviors/strongnut.inc.c"
#include "behaviors/wooden_plank_block.inc.c"
#include "behaviors/thrown_string.inc.c"
#include "behaviors/thread_bundle.inc.c"
#include "behaviors/drag_spark.inc.c"
#include "behaviors/needle_ball.inc.c"
#include "behaviors/thread_particle.inc.c"
#include "behaviors/paper_bomp.inc.c"
#include "behaviors/lily_star_manager.inc.c"
#include "behaviors/rotating_plane_spawner.inc.c"
#include "behaviors/on_off_switch.inc.c"
#include "behaviors/on_off_block.inc.c"
#include "behaviors/reality_cracks.inc.c"
#include "behaviors/soul_mote.inc.c"

#include "behaviors/prince_boss.inc.c"
#include "behaviors/jelly_surround_circle.inc.c"
#include "behaviors/prince_teleport_rift.inc.c"
#include "behaviors/prince_bullet.inc.c"
#include "behaviors/prince_shock_wave.inc.c"
#include "behaviors/focus_object.inc.c"
#include "behaviors/prince_laser.inc.c"
#include "behaviors/faraway_beep_manager.inc.c"
#include "behaviors/rose_crystal.inc.c"
#include "behaviors/grey_fire_torch.inc.c"
#include "behaviors/thread_of_life.inc.c"
#include "behaviors/bowser_npc.inc.c"
#include "behaviors/readable_book.inc.c"
#include "behaviors/burnable_rope_net.inc.c"
#include "behaviors/memory_cutscene_controller.inc.c"
#include "behaviors/bowser_npc_spot.inc.c"
#include "behaviors/vtw_entrance.inc.c"
#include "behaviors/fortune_teleporter.inc.c"
#include "behaviors/hub_barrier.inc.c"
#include "behaviors/lightning_sentry.inc.c"
#include "behaviors/pm_shockwave.inc.c"
#include "behaviors/pm_thrown_needle.inc.c"
#include "behaviors/string_break_controller.inc.c"
#include "behaviors/sewnia_body.inc.c"
#include "behaviors/corr_lift.inc.c"
#include "behaviors/ts_warp_platform.inc.c"
#include "behaviors/mantle_of_madness.inc.c"
#include "behaviors/mad_spike_wall.inc.c"
#include "behaviors/track_mario_laser.inc.c"
#include "behaviors/mad_slamming_hand.inc.c"
#include "behaviors/new_file_select_star_count_number.inc.c"
#include "behaviors/yarn_circle_selector.inc.c"
#include "behaviors/memory_cloud.inc.c"
#include "behaviors/peach_npc.inc.c"
#include "behaviors/shrine_shape.inc.c"
#include "behaviors/lockbox_key.inc.c"
#include "behaviors/beginning_hub_barrier.inc.c"
#include "behaviors/crazy_block.inc.c"
#include "behaviors/final_needle.inc.c"
#include "behaviors/mantle_death_ray.inc.c"
#include "behaviors/triangle_tornado.inc.c"
#include "behaviors/lockbox.inc.c"
#include "behaviors/ts_panel.inc.c"
#include "behaviors/ts_door.inc.c"
#include "behaviors/peach_npc_spot.inc.c"
#include "behaviors/speech_bubble.inc.c"
#include "behaviors/pm_credits_manager.inc.c"
#include "behaviors/escaping_souls.inc.c"
#include "behaviors/lower_city_gate.inc.c"
#include "behaviors/pm_thrown_flower.inc.c"
#include "behaviors/pm_ice_spike.inc.c"
#include "behaviors/pm_ice_spike_spawner.inc.c"
#include "behaviors/pm_grapple.inc.c"
#include "behaviors/pm_halo.inc.c"
#include "behaviors/pm_bubble.inc.c"
#include "behaviors/pm_miasma.inc.c"
#include "behaviors/pm_portal.inc.c"
#include "behaviors/sisyphus_manager.inc.c"
#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <PR/ultratypes.h>

#include "types.h"
#include "area.h"
#include "puppycam2.h"

#include "course_table.h"

#if defined(SRAM)
    #define EEPROM_SIZE 0x8000
#elif defined(EEP16K)
    #define EEPROM_SIZE 0x800
#else
    #define EEPROM_SIZE 0x200
#endif

#define NUM_SAVE_FILES 4

struct SaveBlockSignature {
    u16 magic;
    u16 chksum;
};

struct SaveFile {

    // 48 bits
    u16 patchFlags;
    u8 dpadPatchMap[4];

    u32 flags;

    // Star flags for each course.
    // The most significant bit of the byte *following* each course is set if the
    // cannon is open.
    u8 courseStars[COURSE_COUNT-1]; // 200 bits

    u32 unlockedSongs[4]; // 128 bits

    u32 patchChallengeFrames[12]; // 384 bits

    struct SaveBlockSignature signature; // 32 bits 
};

enum SaveFileIndex {
    SAVE_FILE_A,
    SAVE_FILE_B,
    SAVE_FILE_C,
    SAVE_FILE_D
};

struct MainMenuSaveData {
    // Each save file has a 2 bit "age" for each course. The higher this value,
    // the older the high score is. This is used for tie-breaking when displaying
    // on the high score screen.
    u32 coinScoreAges[NUM_SAVE_FILES];
    u8 soundMode: 2;
#ifdef WIDE
    u8 wideMode: 1;
#endif
#ifdef REONUCAM
    u8 cameraSpeedSetting: 3;
#endif

    u8 cameraCorrectionSetting : 1;
    u8 patchButtonSetting : 1;

#if MULTILANG
    u8 language: 2;
#define SUBTRAHEND 8
#else
#define SUBTRAHEND 6
#endif
    u8 firstBoot;

    #ifdef PUPPYCAM
    struct gPuppyOptions saveOptions;
    #endif
    struct SaveBlockSignature signature;
};

struct SaveBuffer {
    // Each of the four save files has two copies. If one is bad, the other is used as a backup.
    struct SaveFile files[NUM_SAVE_FILES][2];
    // Main menu data, storing config options.
    struct MainMenuSaveData menuData;
};

#ifdef PUPPYCAM
extern void puppycam_set_save(void);
extern void puppycam_get_save(void);
extern void puppycam_check_save(void);
#endif

STATIC_ASSERT(sizeof(struct SaveBuffer) <= EEPROM_SIZE, "ERROR: Save struct too big for specified save type");

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;
extern s8 sUnusedGotGlobalCoinHiScore;
extern u8 gGotFileCoinHiScore;
extern u8 gCurrCourseStarFlags;
extern u8 gSpecialTripleJump;
extern s8 gLevelToCourseNumTable[];

enum CourseFlags {
    COURSE_FLAG_CANNON_UNLOCKED      = (1 <<  7), /* 0x00000080 */
};

// game progress flags
enum SaveProgressFlags {
    SAVE_FLAG_FILE_EXISTS            = (1 <<  0), /* 0x00000001 */
    SAVE_FLAG_HAVE_WING_CAP          = (1 <<  1), /* 0x00000002 */
    SAVE_FLAG_HAVE_METAL_CAP         = (1 <<  2), /* 0x00000004 */
    SAVE_FLAG_HAVE_VANISH_CAP        = (1 <<  3), /* 0x00000008 */
    SAVE_FLAG_HAVE_KEY_1             = (1 <<  4), /* 0x00000010 */
    SAVE_FLAG_HAVE_KEY_2             = (1 <<  5), /* 0x00000020 */
    SAVE_FLAG_ENTERED_SECOND_HUB = (1 <<  6), /* 0x00000040 */
    SAVE_FLAG_ENTERED_THIRD_HUB = (1 <<  7), /* 0x00000080 */
    SAVE_FLAG_UNLOCKED_CLC_SHORTCUT         = (1 <<  8), /* 0x00000100 */
    SAVE_FLAG_HAVE_LOCKBOX_KEY           = (1 <<  9), /* 0x00000200 */
    SAVE_FLAG_UNLOCKED_COURSE_RDR      = (1 << 10), /* 0x00000400 */
    SAVE_FLAG_UNLOCKED_COURSE_STC       = (1 << 11), /* 0x00000800 */
    SAVE_FLAG_UNLOCKED_COURSE_CLC      = (1 << 12), /* 0x00001000 */
    SAVE_FLAG_UNLOCKED_COURSE_HVH      = (1 << 13), /* 0x00002000 */
    SAVE_FLAG_UNLOCKED_COURSE_CORR    = (1 << 14), /* 0x00004000 */
    SAVE_FLAG_UNLOCKED_COURSE_TS    = (1 << 15), /* 0x00008000 */
    SAVE_FLAG_BEAT_GAME          = (1 << 16), /* 0x00010000 */
    SAVE_FLAG_CAP_ON_KLEPTO          = (1 << 17), /* 0x00020000 */
    SAVE_FLAG_CAP_ON_UKIKI           = (1 << 18), /* 0x00040000 */
    SAVE_FLAG_CAP_ON_MR_BLIZZARD     = (1 << 19), /* 0x00080000 */
    SAVE_FLAG_UNLOCKED_50_STAR_DOOR  = (1 << 20), /* 0x00100000 */
    SAVE_FLAG_COLLECTED_TOAD_STAR_1  = (1 << 24), /* 0x01000000 */
    SAVE_FLAG_COLLECTED_TOAD_STAR_2  = (1 << 25), /* 0x02000000 */
    SAVE_FLAG_COLLECTED_TOAD_STAR_3  = (1 << 26), /* 0x04000000 */
    SAVE_FLAG_COLLECTED_MIPS_STAR_1  = (1 << 27), /* 0x08000000 */
    SAVE_FLAG_COLLECTED_MIPS_STAR_2  = (1 << 28), /* 0x10000000 */
};

enum SaveProgressFlagsNew {
    N_SAVE_FLAG_FILE_EXISTS            = (1 <<  0), /* 0x00000001 */
    N_SAVE_FLAG_CUTSCENE_STC_BRIDGE          = (1 <<  1), /* 0x00000002 */
    N_SAVE_FLAG_CUTSCENE_MISTRESS         = (1 <<  2), /* 0x00000004 */
};

//why did i think i would need this
enum PatchCollectedFlags {
    PATCH_FLAG_HAVE_STONE            = (1 <<  0), /* 0x00000001 */
    PATCH_FLAG_HAVE_CHILLSTEP         = (1 <<  1), /* 0x00000002 */
    PATCH_FLAG_HAVE_GRAPPLE         = (1 <<  2), /* 0x00000004 */
    PATCH_FLAG_HAVE_HALO        = (1 <<  3), /* 0x00000008 */
    PATCH_FLAG_HAVE_5             = (1 <<  4), /* 0x00000010 */
    PATCH_FLAG_HAVE_6             = (1 <<  5), /* 0x00000020 */
    PATCH_FLAG_HAVE_7 = (1 <<  6), /* 0x00000040 */
    PATCH_FLAG_HAVE_8 = (1 <<  7), /* 0x00000080 */
    PATCH_FLAG_HAVE_9         = (1 <<  8), /* 0x00000100 */
    PATCH_FLAG_HAVE_10           = (1 <<  9), /* 0x00000200 */
    PATCH_FLAG_HAVE_11      = (1 << 10), /* 0x00000400 */
    PATCH_FLAG_HAVE_12       = (1 << 11), /* 0x00000800 */
    PATCH_FLAG_HAVE_13      = (1 << 12), /* 0x00001000 */
    PATCH_FLAG_HAVE_14      = (1 << 13), /* 0x00002000 */
    PATCH_FLAG_HAVE_15    = (1 << 14), /* 0x00004000 */
    PATCH_FLAG_FILLER    = (1 << 15), /* 0x00008000 */
};

enum StarFlags {
    STAR_FLAGS_NONE         = (0 << 0), // 0x00
    STAR_FLAG_ACT_1         = (1 << 0), // 0x01
    STAR_FLAG_ACT_2         = (1 << 1), // 0x02
    STAR_FLAG_ACT_3         = (1 << 2), // 0x04
    STAR_FLAG_ACT_4         = (1 << 3), // 0x08
    STAR_FLAG_ACT_5         = (1 << 4), // 0x10
    STAR_FLAG_ACT_6         = (1 << 5), // 0x20
    STAR_FLAG_ACT_100_COINS = (1 << 6), // 0x40
    STAR_FLAG_LAST          = STAR_FLAG_ACT_100_COINS
};

#define SAVE_FLAG_TO_STAR_FLAG(cmd) (((cmd) >> 24) & 0x7F)
#define STAR_FLAG_TO_SAVE_FLAG(cmd) ((cmd) << 24)

// Variable for setting a warp checkpoint.

// possibly a WarpDest struct where arg is a union. TODO: Check?
struct WarpCheckpoint {
    /*0x00*/ u8 actNum;
    /*0x01*/ u8 courseNum;
    /*0x02*/ u8 levelID;
    /*0x03*/ u8 areaNum;
    /*0x04*/ u8 warpNode;
};

extern struct WarpCheckpoint gWarpCheckpoint;

extern s8 gMainMenuDataModified;
extern s8 gSaveFileModified;

void save_file_do_save(s32 fileIndex);
void save_file_erase(s32 fileIndex);
void save_file_copy(s32 srcFileIndex, s32 destFileIndex);
void save_file_load_all(void);
void save_file_reload(void);
void save_file_collect_star_or_key(s16 coinScore, s16 starIndex);
s32 save_file_exists(s32 fileIndex);
u32 save_file_get_max_coin_score(s32 courseIndex);
s32 save_file_get_course_star_count(s32 fileIndex, s32 courseIndex);
s32 save_file_get_total_star_count(s32 fileIndex, s32 minCourse, s32 maxCourse);
void save_file_set_flags(u32 flags);
void save_file_clear_flags(u32 flags);
u32 save_file_get_flags(void);
u32 save_file_get_star_flags(s32 fileIndex, s32 courseIndex);
u16 save_file_get_patch_flags(s32 fileIndex);
void save_file_set_star_flags(s32 fileIndex, s32 courseIndex, u32 starFlags);
void save_file_set_patch_flags(s32 fileIndex, u16 patchFlags);
void save_file_get_dpad_map(s32 fileIndex, s8 dpadMap[4]);
void save_file_set_dpad_map(s32 fileIndex, s8 dpadMap[4]);
u32 save_file_get_collected_patch_upgrades(s32 fileIndex);
void save_file_set_collected_patch_upgrades(s32 fileIndex, u32 patchUpgrades);
s32 save_file_get_course_coin_score(s32 fileIndex, s32 courseIndex);
s32 save_file_is_cannon_unlocked(void);
u32 save_file_get_camera_correction(void);
u32 save_file_get_patch_button(void);
void save_file_set_camera_correction(u8 mode);
void save_file_set_patch_button(u8 mode);
void save_file_set_cannon_unlocked(void);
void save_file_set_sound_mode(u16 mode);
u32 save_file_get_sound_mode(void);
#ifdef WIDE
u32 save_file_get_widescreen_mode(void);
void save_file_set_widescreen_mode(u8 mode);
#endif
#ifdef REONUCAM
u8 save_file_get_camera_speed(void);
void save_file_set_camera_speed(u8 speed);
#endif

void disable_warp_checkpoint(void);
void check_if_should_set_warp_checkpoint(struct WarpNode *warpNode);
s32 check_warp_checkpoint(struct WarpNode *warpNode);
void save_file_set_patch_challenge_time(s32 fileIndex, s8 patchChallenge, u32 frames);
u32 save_file_get_patch_challenge_time(s32 fileIndex, s8 patchChallenge);
u32 save_file_is_song_unlocked(s32 fileIndex, u8 seqID);
u32 save_file_is_secret_star_collected(s32 fileIndex, s16 starIndex);
void save_file_set_collected_song(s32 fileIndex, u8 seqID);

extern s16 gSaveTextIndicatorTimer;

#if MULTILANG
enum EuLanguages {
    LANGUAGE_ENGLISH,
    LANGUAGE_FRENCH,
    LANGUAGE_GERMAN
};

void eu_set_language(u16 language);
u32 eu_get_language(void);
#else
#define LANGUAGE_ENGLISH 0
#endif

#endif // SAVE_FILE_H

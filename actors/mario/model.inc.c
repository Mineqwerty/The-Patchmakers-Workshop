// Mario

// 0x04000000 # solid color blue - butt, left thigh, right thigh - all poly types
const Lights1 mario_blue_lights_group = gdSPDefLights1(
    0x00, 0x00, 0x7f,
    0x00, 0x00, 0xff, 0x28, 0x28, 0x28
);

// 0x04000018 # solid color red - left & right arm, torso (tshirt part), caps - all poly types
const Lights1 mario_red_lights_group = gdSPDefLights1(
    0x7f, 0x00, 0x00,
    0xff, 0x00, 0x00, 0x28, 0x28, 0x28
);

// 0x04000030 # solid color white - metal butt & left thigh - normal left & right hand closed & open (with cap too) and all wings - all poly types
const Lights1 mario_white_lights_group = gdSPDefLights1(
    0x7f, 0x7f, 0x7f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x04000048 # solid color brown 1 - foot - all poly types
const Lights1 mario_brown1_lights_group = gdSPDefLights1(
    0x39, 0x0e, 0x07,
    0x72, 0x1c, 0x0e, 0x28, 0x28, 0x28
);

// 0x04000060 # solid color beige skin - face (cap on and off dls) - all poly types
const Lights1 mario_beige_lights_group = gdSPDefLights1(
    0x7f, 0x60, 0x3c,
    0xfe, 0xc1, 0x79, 0x28, 0x28, 0x28
);

// 0x04000078  # solid color brown 2 - hair - all poly types
const Lights1 mario_brown2_lights_group = gdSPDefLights1(
    0x39, 0x03, 0x00,
    0x73, 0x06, 0x00, 0x28, 0x28, 0x28
);

// 0x04000090
ALIGNED8 static const Texture mario_texture_metal[] = {
#include "actors/mario/mario_metal.rgba16.inc.c"
};

// 0x04001090
ALIGNED8 static const Texture mario_texture_yellow_button[] = {
#include "actors/mario/mario_overalls_button.rgba16.inc.c"
};

// 0x04001890
ALIGNED8 static const Texture mario_texture_m_logo[] = {
#include "actors/mario/mario_logo.rgba16.inc.c"
};

// 0x04002090
ALIGNED8 static const Texture mario_texture_hair_sideburn[] = {
#include "actors/mario/mario_sideburn.rgba16.inc.c"
};

// 0x04002890
ALIGNED8 static const Texture mario_texture_mustache[] = {
#include "actors/mario/mario_mustache.rgba16.inc.c"
};

// 0x04003090
ALIGNED8 static const Texture mario_texture_eyes_front[] = {
#include "actors/mario/mario_eyes_center.rgba16.inc.c"
};

// 0x04003890
ALIGNED8 static const Texture mario_texture_eyes_half_closed[] = {
#include "actors/mario/mario_eyes_half_closed.rgba16.inc.c"
};

// 0x04004090
ALIGNED8 static const Texture mario_texture_eyes_closed[] = {
#include "actors/mario/mario_eyes_closed.rgba16.inc.c"
};

// Unreferenced texture
// 0x04004890
UNUSED ALIGNED8 static const Texture mario_texture_eyes_closed_unused1[] = {
#include "actors/mario/mario_eyes_closed_unused_0.rgba16.inc.c"
};

// Unreferenced texture
// 0x04005090
UNUSED ALIGNED8 static const Texture mario_texture_eyes_closed_unused2[] = {
#include "actors/mario/mario_eyes_closed_unused_1.rgba16.inc.c"
};

// 0x04005890
ALIGNED8 static const Texture mario_texture_eyes_right[] = {
#include "actors/mario/mario_eyes_left_unused.rgba16.inc.c"
};

// 0x04006090
ALIGNED8 static const Texture mario_texture_eyes_left[] = {
#include "actors/mario/mario_eyes_right_unused.rgba16.inc.c"
};

// 0x04006890
ALIGNED8 static const Texture mario_texture_eyes_up[] = {
#include "actors/mario/mario_eyes_up_unused.rgba16.inc.c"
};

// 0x04007090
ALIGNED8 static const Texture mario_texture_eyes_down[] = {
#include "actors/mario/mario_eyes_down_unused.rgba16.inc.c"
};

// 0x04007890
ALIGNED8 static const Texture mario_texture_eyes_dead[] = {
#include "actors/mario/mario_eyes_dead.rgba16.inc.c"
};

// 0x04008090
ALIGNED8 static const Texture mario_texture_wings_half_1[] = {
#include "actors/mario/mario_wing.rgba16.inc.c"
};

// 0x04009090
ALIGNED8 static const Texture mario_texture_wings_half_2[] = {
#include "actors/mario/mario_wing_tip.rgba16.inc.c"
};

// 0x0400A090
ALIGNED8 static const Texture mario_texture_metal_wings_half_1[] = {
#include "actors/mario/mario_metal_wing_unused.rgba16.inc.c"
};

// 0x0400B090
ALIGNED8 static const Texture mario_texture_metal_wings_half_2[] = {
#include "actors/mario/mario_metal_wing_tip_unused.rgba16.inc.c"
};

// 0x0400C090
static const Vtx mario_butt_dl_vertex_group1[] = {
    {{{    -9,     73,    -34}, 0, {     0,      0}, {0xc2, 0x6b, 0xe6, 0x00}}},
    {{{    -9,     73,     34}, 0, {     0,      0}, {0xbe, 0x6a, 0x12, 0x00}}},
    {{{    22,     82,    -26}, 0, {     0,      0}, {0x07, 0x7e, 0xf5, 0x00}}},
    {{{    73,     11,      0}, 0, {     0,      0}, {0x7e, 0x04, 0x00, 0x00}}},
    {{{    55,    -61,    -36}, 0, {     0,      0}, {0x67, 0xbe, 0xe1, 0x00}}},
    {{{    44,    -10,    -92}, 0, {     0,      0}, {0x4f, 0xf2, 0x9e, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
    {{{    43,     40,     91}, 0, {     0,      0}, {0x4e, 0x30, 0x57, 0x00}}},
    {{{     8,     -8,    -99}, 0, {     0,      0}, {0xf3, 0xee, 0x84, 0x00}}},
    {{{    36,    -51,    -79}, 0, {     0,      0}, {0x30, 0xb8, 0xa4, 0x00}}},
    {{{    26,    -74,    -46}, 0, {     0,      0}, {0x18, 0x88, 0xe2, 0x00}}},
    {{{    36,    -52,     79}, 0, {     0,      0}, {0x30, 0xb8, 0x5c, 0x00}}},
    {{{    26,    -74,     45}, 0, {     0,      0}, {0x12, 0x88, 0x22, 0x00}}},
    {{{    55,    -61,     36}, 0, {     0,      0}, {0x60, 0xb3, 0x1a, 0x00}}},
};

// 0x0400C180
static const Vtx mario_butt_dl_vertex_group2[] = {
    {{{    -5,     59,     72}, 0, {     0,      0}, {0xc0, 0x52, 0x47, 0x00}}},
    {{{    -9,     73,     34}, 0, {     0,      0}, {0xbe, 0x6a, 0x12, 0x00}}},
    {{{   -32,     40,     39}, 0, {     0,      0}, {0x8b, 0x25, 0x1d, 0x00}}},
    {{{    52,     70,     38}, 0, {     0,      0}, {0x53, 0x5d, 0x16, 0x00}}},
    {{{    22,     82,     26}, 0, {     0,      0}, {0x07, 0x7d, 0x11, 0x00}}},
    {{{    27,     72,     63}, 0, {     0,      0}, {0x06, 0x6c, 0x42, 0x00}}},
    {{{    43,     40,    -91}, 0, {     0,      0}, {0x4e, 0x30, 0xa9, 0x00}}},
    {{{    27,     72,    -63}, 0, {     0,      0}, {0x07, 0x6b, 0xbe, 0x00}}},
    {{{    52,     70,    -39}, 0, {     0,      0}, {0x59, 0x56, 0xe5, 0x00}}},
    {{{    -5,     59,    -72}, 0, {     0,      0}, {0xc0, 0x52, 0xb9, 0x00}}},
    {{{   -17,     32,    -79}, 0, {     0,      0}, {0xa4, 0x23, 0xb1, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{    73,     11,      0}, 0, {     0,      0}, {0x7e, 0x04, 0x00, 0x00}}},
    {{{    43,     40,     91}, 0, {     0,      0}, {0x4e, 0x30, 0x57, 0x00}}},
};

// 0x0400C260
static const Vtx mario_butt_dl_vertex_group3[] = {
    {{{   -14,    -74,      0}, 0, {     0,      0}, {0xcb, 0x8d, 0x00, 0x00}}},
    {{{    -9,    -69,     55}, 0, {     0,      0}, {0xcd, 0x97, 0x30, 0x00}}},
    {{{   -31,    -51,     42}, 0, {     0,      0}, {0x8d, 0xd7, 0x1f, 0x00}}},
    {{{    26,    -74,    -46}, 0, {     0,      0}, {0x18, 0x88, 0xe2, 0x00}}},
    {{{    -9,    -69,    -55}, 0, {     0,      0}, {0xcd, 0x97, 0xd0, 0x00}}},
    {{{     4,    -48,    -86}, 0, {     0,      0}, {0xd8, 0xba, 0x9f, 0x00}}},
    {{{     4,    -49,     86}, 0, {     0,      0}, {0xd8, 0xb9, 0x61, 0x00}}},
    {{{    26,    -74,     45}, 0, {     0,      0}, {0x12, 0x88, 0x22, 0x00}}},
    {{{   -32,     40,     39}, 0, {     0,      0}, {0x8b, 0x25, 0x1d, 0x00}}},
    {{{    -9,     73,     34}, 0, {     0,      0}, {0xbe, 0x6a, 0x12, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{    27,     72,     63}, 0, {     0,      0}, {0x06, 0x6c, 0x42, 0x00}}},
    {{{    -5,     59,     72}, 0, {     0,      0}, {0xc0, 0x52, 0x47, 0x00}}},
    {{{    52,     70,    -39}, 0, {     0,      0}, {0x59, 0x56, 0xe5, 0x00}}},
    {{{    22,     82,    -26}, 0, {     0,      0}, {0x07, 0x7e, 0xf5, 0x00}}},
    {{{    52,     70,     38}, 0, {     0,      0}, {0x53, 0x5d, 0x16, 0x00}}},
};

// 0x0400C360
static const Vtx mario_butt_dl_vertex_group4[] = {
    {{{     6,     33,    -95}, 0, {     0,      0}, {0xe6, 0x26, 0x8b, 0x00}}},
    {{{    27,     72,    -63}, 0, {     0,      0}, {0x07, 0x6b, 0xbe, 0x00}}},
    {{{    43,     40,    -91}, 0, {     0,      0}, {0x4e, 0x30, 0xa9, 0x00}}},
    {{{   -31,    -51,     42}, 0, {     0,      0}, {0x8d, 0xd7, 0x1f, 0x00}}},
    {{{   -31,    -51,    -42}, 0, {     0,      0}, {0x91, 0xd0, 0xdc, 0x00}}},
    {{{   -14,    -74,      0}, 0, {     0,      0}, {0xcb, 0x8d, 0x00, 0x00}}},
    {{{    -9,    -69,    -55}, 0, {     0,      0}, {0xcd, 0x97, 0xd0, 0x00}}},
    {{{    73,     11,      0}, 0, {     0,      0}, {0x7e, 0x04, 0x00, 0x00}}},
    {{{    44,    -10,    -92}, 0, {     0,      0}, {0x4f, 0xf2, 0x9e, 0x00}}},
    {{{    52,     70,     38}, 0, {     0,      0}, {0x53, 0x5d, 0x16, 0x00}}},
    {{{    52,     70,    -39}, 0, {     0,      0}, {0x59, 0x56, 0xe5, 0x00}}},
    {{{    43,     40,     91}, 0, {     0,      0}, {0x4e, 0x30, 0x57, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{    27,     72,     63}, 0, {     0,      0}, {0x06, 0x6c, 0x42, 0x00}}},
};

// 0x0400C450
static const Vtx mario_butt_dl_vertex_group5[] = {
    {{{    -5,     59,    -72}, 0, {     0,      0}, {0xc0, 0x52, 0xb9, 0x00}}},
    {{{    -9,     73,    -34}, 0, {     0,      0}, {0xc2, 0x6b, 0xe6, 0x00}}},
    {{{    27,     72,    -63}, 0, {     0,      0}, {0x07, 0x6b, 0xbe, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{   -32,     40,     39}, 0, {     0,      0}, {0x8b, 0x25, 0x1d, 0x00}}},
    {{{   -18,     32,     79}, 0, {     0,      0}, {0xa4, 0x23, 0x4f, 0x00}}},
    {{{    -5,     59,     72}, 0, {     0,      0}, {0xc0, 0x52, 0x47, 0x00}}},
    {{{    22,     82,    -26}, 0, {     0,      0}, {0x07, 0x7e, 0xf5, 0x00}}},
    {{{    52,     70,    -39}, 0, {     0,      0}, {0x59, 0x56, 0xe5, 0x00}}},
    {{{    27,     72,     63}, 0, {     0,      0}, {0x06, 0x6c, 0x42, 0x00}}},
    {{{    43,     40,     91}, 0, {     0,      0}, {0x4e, 0x30, 0x57, 0x00}}},
    {{{    52,     70,     38}, 0, {     0,      0}, {0x53, 0x5d, 0x16, 0x00}}},
    {{{     8,     -8,     99}, 0, {     0,      0}, {0xf3, 0xef, 0x7c, 0x00}}},
    {{{    36,    -52,     79}, 0, {     0,      0}, {0x30, 0xb8, 0x5c, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
};

// 0x0400C540
static const Vtx mario_butt_dl_vertex_group6[] = {
    {{{     6,     33,    -95}, 0, {     0,      0}, {0xe6, 0x26, 0x8b, 0x00}}},
    {{{    43,     40,    -91}, 0, {     0,      0}, {0x4e, 0x30, 0xa9, 0x00}}},
    {{{    44,    -10,    -92}, 0, {     0,      0}, {0x4f, 0xf2, 0x9e, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
    {{{    36,    -52,     79}, 0, {     0,      0}, {0x30, 0xb8, 0x5c, 0x00}}},
    {{{    55,    -61,     36}, 0, {     0,      0}, {0x60, 0xb3, 0x1a, 0x00}}},
    {{{   -18,     32,     79}, 0, {     0,      0}, {0xa4, 0x23, 0x4f, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{    -5,     59,     72}, 0, {     0,      0}, {0xc0, 0x52, 0x47, 0x00}}},
    {{{   -20,     -7,     81}, 0, {     0,      0}, {0xa3, 0xf9, 0x55, 0x00}}},
    {{{     8,     -8,     99}, 0, {     0,      0}, {0xf3, 0xef, 0x7c, 0x00}}},
    {{{     4,    -49,     86}, 0, {     0,      0}, {0xd8, 0xb9, 0x61, 0x00}}},
    {{{   -20,     -8,    -81}, 0, {     0,      0}, {0xa3, 0xf8, 0xab, 0x00}}},
    {{{     8,     -8,    -99}, 0, {     0,      0}, {0xf3, 0xee, 0x84, 0x00}}},
    {{{     4,    -48,    -86}, 0, {     0,      0}, {0xd8, 0xba, 0x9f, 0x00}}},
};

// 0x0400C630
static const Vtx mario_butt_dl_vertex_group7[] = {
    {{{    -5,     59,    -72}, 0, {     0,      0}, {0xc0, 0x52, 0xb9, 0x00}}},
    {{{     6,     33,    -95}, 0, {     0,      0}, {0xe6, 0x26, 0x8b, 0x00}}},
    {{{   -17,     32,    -79}, 0, {     0,      0}, {0xa4, 0x23, 0xb1, 0x00}}},
    {{{   -20,     -8,    -81}, 0, {     0,      0}, {0xa3, 0xf8, 0xab, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{   -18,     32,     79}, 0, {     0,      0}, {0xa4, 0x23, 0x4f, 0x00}}},
    {{{   -20,     -7,     81}, 0, {     0,      0}, {0xa3, 0xf9, 0x55, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{    55,    -61,     36}, 0, {     0,      0}, {0x60, 0xb3, 0x1a, 0x00}}},
    {{{    73,     11,      0}, 0, {     0,      0}, {0x7e, 0x04, 0x00, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
    {{{    55,    -61,    -36}, 0, {     0,      0}, {0x67, 0xbe, 0xe1, 0x00}}},
    {{{    36,    -51,    -79}, 0, {     0,      0}, {0x30, 0xb8, 0xa4, 0x00}}},
    {{{    44,    -10,    -92}, 0, {     0,      0}, {0x4f, 0xf2, 0x9e, 0x00}}},
    {{{     8,     -8,    -99}, 0, {     0,      0}, {0xf3, 0xee, 0x84, 0x00}}},
};

// 0x0400C720
static const Vtx mario_butt_dl_vertex_group8[] = {
    {{{     8,     -8,     99}, 0, {     0,      0}, {0xf3, 0xef, 0x7c, 0x00}}},
    {{{     4,    -49,     86}, 0, {     0,      0}, {0xd8, 0xb9, 0x61, 0x00}}},
    {{{    36,    -52,     79}, 0, {     0,      0}, {0x30, 0xb8, 0x5c, 0x00}}},
    {{{    -9,     73,    -34}, 0, {     0,      0}, {0xc2, 0x6b, 0xe6, 0x00}}},
    {{{    22,     82,    -26}, 0, {     0,      0}, {0x07, 0x7e, 0xf5, 0x00}}},
    {{{    27,     72,    -63}, 0, {     0,      0}, {0x07, 0x6b, 0xbe, 0x00}}},
    {{{    27,     72,     63}, 0, {     0,      0}, {0x06, 0x6c, 0x42, 0x00}}},
    {{{    -5,     59,     72}, 0, {     0,      0}, {0xc0, 0x52, 0x47, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{     6,     33,    -95}, 0, {     0,      0}, {0xe6, 0x26, 0x8b, 0x00}}},
    {{{    -5,     59,    -72}, 0, {     0,      0}, {0xc0, 0x52, 0xb9, 0x00}}},
    {{{    22,     82,     26}, 0, {     0,      0}, {0x07, 0x7d, 0x11, 0x00}}},
    {{{    52,     70,     38}, 0, {     0,      0}, {0x53, 0x5d, 0x16, 0x00}}},
    {{{    -9,     73,     34}, 0, {     0,      0}, {0xbe, 0x6a, 0x12, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{    26,    -74,     45}, 0, {     0,      0}, {0x12, 0x88, 0x22, 0x00}}},
};

// 0x0400C820
static const Vtx mario_butt_dl_vertex_group9[] = {
    {{{     4,    -48,    -86}, 0, {     0,      0}, {0xd8, 0xba, 0x9f, 0x00}}},
    {{{    36,    -51,    -79}, 0, {     0,      0}, {0x30, 0xb8, 0xa4, 0x00}}},
    {{{    26,    -74,    -46}, 0, {     0,      0}, {0x18, 0x88, 0xe2, 0x00}}},
    {{{   -20,     -7,     81}, 0, {     0,      0}, {0xa3, 0xf9, 0x55, 0x00}}},
    {{{   -18,     32,     79}, 0, {     0,      0}, {0xa4, 0x23, 0x4f, 0x00}}},
    {{{   -32,     40,     39}, 0, {     0,      0}, {0x8b, 0x25, 0x1d, 0x00}}},
    {{{     8,     -8,    -99}, 0, {     0,      0}, {0xf3, 0xee, 0x84, 0x00}}},
    {{{     7,     33,     95}, 0, {     0,      0}, {0xe6, 0x26, 0x75, 0x00}}},
    {{{     8,     -8,     99}, 0, {     0,      0}, {0xf3, 0xef, 0x7c, 0x00}}},
    {{{    44,     -9,     92}, 0, {     0,      0}, {0x4f, 0xf2, 0x62, 0x00}}},
    {{{    -9,     73,     34}, 0, {     0,      0}, {0xbe, 0x6a, 0x12, 0x00}}},
    {{{    22,     82,     26}, 0, {     0,      0}, {0x07, 0x7d, 0x11, 0x00}}},
    {{{    22,     82,    -26}, 0, {     0,      0}, {0x07, 0x7e, 0xf5, 0x00}}},
    {{{    -9,    -69,    -55}, 0, {     0,      0}, {0xcd, 0x97, 0xd0, 0x00}}},
    {{{   -31,    -51,    -42}, 0, {     0,      0}, {0x91, 0xd0, 0xdc, 0x00}}},
    {{{   -20,     -8,    -81}, 0, {     0,      0}, {0xa3, 0xf8, 0xab, 0x00}}},
};

// 0x0400C920
static const Vtx mario_butt_dl_vertex_group10[] = {
    {{{   -31,    -51,     42}, 0, {     0,      0}, {0x8d, 0xd7, 0x1f, 0x00}}},
    {{{    -9,    -69,     55}, 0, {     0,      0}, {0xcd, 0x97, 0x30, 0x00}}},
    {{{     4,    -49,     86}, 0, {     0,      0}, {0xd8, 0xb9, 0x61, 0x00}}},
    {{{   -20,     -7,     81}, 0, {     0,      0}, {0xa3, 0xf9, 0x55, 0x00}}},
    {{{   -32,     40,     39}, 0, {     0,      0}, {0x8b, 0x25, 0x1d, 0x00}}},
    {{{   -32,     40,    -39}, 0, {     0,      0}, {0x89, 0x25, 0xeb, 0x00}}},
    {{{   -20,     -8,    -81}, 0, {     0,      0}, {0xa3, 0xf8, 0xab, 0x00}}},
    {{{   -31,    -51,    -42}, 0, {     0,      0}, {0x91, 0xd0, 0xdc, 0x00}}},
    {{{    55,    -61,     36}, 0, {     0,      0}, {0x60, 0xb3, 0x1a, 0x00}}},
    {{{    26,    -74,     45}, 0, {     0,      0}, {0x12, 0x88, 0x22, 0x00}}},
    {{{    26,    -74,    -46}, 0, {     0,      0}, {0x18, 0x88, 0xe2, 0x00}}},
    {{{   -14,    -74,      0}, 0, {     0,      0}, {0xcb, 0x8d, 0x00, 0x00}}},
    {{{    -9,    -69,    -55}, 0, {     0,      0}, {0xcd, 0x97, 0xd0, 0x00}}},
    {{{    55,    -61,    -36}, 0, {     0,      0}, {0x67, 0xbe, 0xe1, 0x00}}},
};

// 0x0400CA00 - 0x0400CC98
const Gfx mario_butt_dl[] = {
    gsSPVertex(mario_butt_dl_vertex_group1, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9,  5, 10, 0x0),
    gsSP2Triangles( 4, 11, 10, 0x0, 12, 13, 14, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group2, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9, 10, 11, 0x0),
    gsSP2Triangles(12,  3, 13, 0x0,  6,  8, 12, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group3, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  1,  7, 0x0,  8,  9, 10, 0x0),
    gsSP2Triangles(11,  9, 12, 0x0, 13, 14, 15, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group4, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 4,  6,  5, 0x0,  7,  8,  2, 0x0),
    gsSP2Triangles( 9,  7, 10, 0x0, 11, 12,  7, 0x0),
    gsSP1Triangle(13, 11, 14, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group5, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  1,  0, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  2,  7,  8, 0x0),
    gsSP2Triangles( 9, 10, 11, 0x0, 12, 13, 14, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group6, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9, 10,  7, 0x0),
    gsSP2Triangles(11, 10,  9, 0x0, 12, 13, 14, 0x0),
    gsSP1Triangle( 0, 13, 12, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group7, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  2,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  7,  2,  3, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  9,  8, 11, 0x0),
    gsSP2Triangles(11, 12, 13, 0x0, 13, 14,  1, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group8, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9, 10,  5, 0x0),
    gsSP2Triangles( 4, 11, 12, 0x0,  6, 11, 13, 0x0),
    gsSP2Triangles(13,  3, 14, 0x0, 15,  2,  1, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group9, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 1,  0,  6, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0,  0, 13, 14, 0x0),
    gsSP1Triangle(15,  0, 14, 0x0),
    gsSPVertex(mario_butt_dl_vertex_group10, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 3,  4,  0, 0x0,  0,  4,  5, 0x0),
    gsSP2Triangles( 5,  6,  7, 0x0,  5,  7,  0, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  9, 11, 10, 0x0),
    gsSP2Triangles( 9,  1, 11, 0x0, 11, 12, 10, 0x0),
    gsSP1Triangle(10, 13,  8, 0x0),
    gsSPEndDisplayList(),
};

// 0x0400CC98 - 0x0400CCC8
const Gfx mario_butt[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_butt_dl),
    gsSPEndDisplayList(),
};

// 0x0400CCC8 - 0x0400CD40
const Gfx mario_metal_butt[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_butt_dl),
    gsSPEndDisplayList(),
};

// 0x0400CD40
static const Vtx mario_left_arm_shared_dl_vertex_group1[] = {
    {{{     7,     27,     20}, 0, {     0,      0}, {0xda, 0x61, 0x47, 0x00}}},
    {{{    59,     20,     15}, 0, {     0,      0}, {0x44, 0x4a, 0x4c, 0x00}}},
    {{{    59,     21,    -21}, 0, {     0,      0}, {0x37, 0x67, 0xd0, 0x00}}},
    {{{     6,    -16,     32}, 0, {     0,      0}, {0xd5, 0xdc, 0x71, 0x00}}},
    {{{    58,    -15,     25}, 0, {     0,      0}, {0x32, 0xc6, 0x64, 0x00}}},
    {{{     5,    -42,     -5}, 0, {     0,      0}, {0xd3, 0x8a, 0xff, 0x00}}},
    {{{    57,    -36,     -5}, 0, {     0,      0}, {0x3e, 0x93, 0xef, 0x00}}},
    {{{     6,    -13,    -42}, 0, {     0,      0}, {0xd6, 0xde, 0x8e, 0x00}}},
    {{{    58,    -13,    -34}, 0, {     0,      0}, {0x3b, 0xfb, 0x90, 0x00}}},
    {{{     7,     29,    -26}, 0, {     0,      0}, {0xda, 0x62, 0xbb, 0x00}}},
    {{{    -8,     17,    -17}, 0, {     0,      0}, {0x90, 0x2a, 0xd6, 0x00}}},
    {{{    -8,     16,     10}, 0, {     0,      0}, {0x9a, 0x44, 0x1d, 0x00}}},
    {{{    -8,     -9,    -27}, 0, {     0,      0}, {0x8e, 0xe8, 0xce, 0x00}}},
    {{{    -9,    -26,     -5}, 0, {     0,      0}, {0x96, 0xbd, 0x0e, 0x00}}},
    {{{    -8,    -11,     18}, 0, {     0,      0}, {0x8b, 0xff, 0x2f, 0x00}}},
};

// 0x0400CE30
static const Vtx mario_left_arm_shared_dl_vertex_group2[] = {
    {{{    68,     13,    -16}, 0, {     0,      0}, {0x6a, 0x38, 0xd9, 0x00}}},
    {{{    68,    -10,    -25}, 0, {     0,      0}, {0x75, 0xe7, 0xd9, 0x00}}},
    {{{    58,    -13,    -34}, 0, {     0,      0}, {0x3b, 0xfb, 0x90, 0x00}}},
    {{{    59,     20,     15}, 0, {     0,      0}, {0x44, 0x4a, 0x4c, 0x00}}},
    {{{    68,     12,      9}, 0, {     0,      0}, {0x78, 0x1f, 0x1b, 0x00}}},
    {{{    67,    -12,     16}, 0, {     0,      0}, {0x6f, 0xe8, 0x37, 0x00}}},
    {{{    57,    -36,     -5}, 0, {     0,      0}, {0x3e, 0x93, 0xef, 0x00}}},
    {{{    67,    -26,     -5}, 0, {     0,      0}, {0x6e, 0xc2, 0xfe, 0x00}}},
    {{{    58,    -15,     25}, 0, {     0,      0}, {0x32, 0xc6, 0x64, 0x00}}},
    {{{    59,     21,    -21}, 0, {     0,      0}, {0x37, 0x67, 0xd0, 0x00}}},
    {{{     7,     27,     20}, 0, {     0,      0}, {0xda, 0x61, 0x47, 0x00}}},
    {{{    -8,    -11,     18}, 0, {     0,      0}, {0x8b, 0xff, 0x2f, 0x00}}},
    {{{     6,    -16,     32}, 0, {     0,      0}, {0xd5, 0xdc, 0x71, 0x00}}},
    {{{    -9,    -26,     -5}, 0, {     0,      0}, {0x96, 0xbd, 0x0e, 0x00}}},
    {{{     5,    -42,     -5}, 0, {     0,      0}, {0xd3, 0x8a, 0xff, 0x00}}},
};

// 0x0400CF20
static const Vtx mario_left_arm_shared_dl_vertex_group3[] = {
    {{{     5,    -42,     -5}, 0, {     0,      0}, {0xd3, 0x8a, 0xff, 0x00}}},
    {{{    -8,     -9,    -27}, 0, {     0,      0}, {0x8e, 0xe8, 0xce, 0x00}}},
    {{{     6,    -13,    -42}, 0, {     0,      0}, {0xd6, 0xde, 0x8e, 0x00}}},
    {{{    -8,     17,    -17}, 0, {     0,      0}, {0x90, 0x2a, 0xd6, 0x00}}},
    {{{     7,     29,    -26}, 0, {     0,      0}, {0xda, 0x62, 0xbb, 0x00}}},
    {{{    -8,     16,     10}, 0, {     0,      0}, {0x9a, 0x44, 0x1d, 0x00}}},
    {{{     7,     27,     20}, 0, {     0,      0}, {0xda, 0x61, 0x47, 0x00}}},
    {{{    58,    -13,    -34}, 0, {     0,      0}, {0x3b, 0xfb, 0x90, 0x00}}},
    {{{    57,    -36,     -5}, 0, {     0,      0}, {0x3e, 0x93, 0xef, 0x00}}},
    {{{     6,    -16,     32}, 0, {     0,      0}, {0xd5, 0xdc, 0x71, 0x00}}},
    {{{    58,    -15,     25}, 0, {     0,      0}, {0x32, 0xc6, 0x64, 0x00}}},
    {{{    59,     20,     15}, 0, {     0,      0}, {0x44, 0x4a, 0x4c, 0x00}}},
    {{{    59,     21,    -21}, 0, {     0,      0}, {0x37, 0x67, 0xd0, 0x00}}},
    {{{    -8,    -11,     18}, 0, {     0,      0}, {0x8b, 0xff, 0x2f, 0x00}}},
};

// 0x0400D000
static const Vtx mario_left_arm_shared_dl_vertex_group4[] = {
    {{{    68,     12,      9}, 0, {     0,      0}, {0x78, 0x1f, 0x1b, 0x00}}},
    {{{    68,    -10,    -25}, 0, {     0,      0}, {0x75, 0xe7, 0xd9, 0x00}}},
    {{{    68,     13,    -16}, 0, {     0,      0}, {0x6a, 0x38, 0xd9, 0x00}}},
    {{{    67,    -12,     16}, 0, {     0,      0}, {0x6f, 0xe8, 0x37, 0x00}}},
    {{{    67,    -26,     -5}, 0, {     0,      0}, {0x6e, 0xc2, 0xfe, 0x00}}},
    {{{    -8,     17,    -17}, 0, {     0,      0}, {0x90, 0x2a, 0xd6, 0x00}}},
    {{{    -8,     -9,    -27}, 0, {     0,      0}, {0x8e, 0xe8, 0xce, 0x00}}},
    {{{    -8,    -11,     18}, 0, {     0,      0}, {0x8b, 0xff, 0x2f, 0x00}}},
    {{{    -9,    -26,     -5}, 0, {     0,      0}, {0x96, 0xbd, 0x0e, 0x00}}},
};

// 0x0400D090 - 0x0400D1D8
const Gfx mario_left_arm_shared_dl[] = {
    gsSPVertex(mario_left_arm_shared_dl_vertex_group1, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 5,  6,  4, 0x0,  7,  8,  6, 0x0),
    gsSP2Triangles( 9,  2,  8, 0x0,  9, 10, 11, 0x0),
    gsSP2Triangles( 7, 12, 10, 0x0,  5, 13, 12, 0x0),
    gsSP2Triangles( 3, 14, 13, 0x0,  0, 11, 14, 0x0),
    gsSPVertex(mario_left_arm_shared_dl_vertex_group2, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  0, 0x0),
    gsSP2Triangles( 5,  4,  3, 0x0,  6,  7,  5, 0x0),
    gsSP2Triangles( 1,  7,  6, 0x0,  2,  1,  6, 0x0),
    gsSP2Triangles( 6,  5,  8, 0x0,  8,  5,  3, 0x0),
    gsSP2Triangles( 3,  0,  9, 0x0,  9,  0,  2, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0, 12, 13, 14, 0x0),
    gsSPVertex(mario_left_arm_shared_dl_vertex_group3, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  4, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  2,  4,  7, 0x0),
    gsSP2Triangles( 0,  2,  8, 0x0,  9,  0, 10, 0x0),
    gsSP2Triangles( 6,  9, 11, 0x0,  4,  6, 12, 0x0),
    gsSP1Triangle(13,  5,  3, 0x0),
    gsSPVertex(mario_left_arm_shared_dl_vertex_group4, 9, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 3,  4,  1, 0x0,  5,  6,  7, 0x0),
    gsSP1Triangle( 6,  8,  7, 0x0),
    gsSPEndDisplayList(),
};

// 0x0400D1D8 - 0x0400D1F8
const Gfx mario_left_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_left_arm_shared_dl),
    gsSPEndDisplayList(),
};

Vtx mario_000_offset_001_mesh_layer_1_vtx_1[23] = {
	{{ {47, 75, -34}, 0, {-16, -16}, {72, 102, 230, 255} }},
	{{ {47, 75, 35}, 0, {-16, -16}, {72, 102, 26, 255} }},
	{{ {82, 37, 27}, 0, {-16, -16}, {105, 69, 21, 255} }},
	{{ {82, 37, -26}, 0, {-16, -16}, {105, 69, 235, 255} }},
	{{ {100, 1, 24}, 0, {-16, -16}, {124, 17, 21, 255} }},
	{{ {100, 1, -23}, 0, {-16, -16}, {124, 17, 235, 255} }},
	{{ {93, -36, 26}, 0, {-16, -16}, {107, 189, 15, 255} }},
	{{ {93, -36, -25}, 0, {-16, -16}, {107, 189, 241, 255} }},
	{{ {54, -63, 0}, 0, {-16, -16}, {47, 138, 0, 255} }},
	{{ {46, -34, 84}, 0, {-16, -16}, {35, 202, 110, 255} }},
	{{ {47, 3, 89}, 0, {-16, -16}, {47, 8, 118, 255} }},
	{{ {6, -11, 93}, 0, {-16, -16}, {0, 233, 125, 255} }},
	{{ {84, -29, 63}, 0, {-16, -16}, {95, 216, 75, 255} }},
	{{ {80, 14, 62}, 0, {-16, -16}, {97, 35, 74, 255} }},
	{{ {44, 51, 75}, 0, {-16, -16}, {62, 54, 97, 255} }},
	{{ {13, 33, 91}, 0, {-16, -16}, {15, 27, 123, 255} }},
	{{ {6, -10, -92}, 0, {-16, -16}, {0, 235, 131, 255} }},
	{{ {47, 3, -88}, 0, {-16, -16}, {47, 8, 138, 255} }},
	{{ {46, -34, -83}, 0, {-16, -16}, {35, 202, 146, 255} }},
	{{ {12, 33, -90}, 0, {-16, -16}, {13, 28, 133, 255} }},
	{{ {43, 51, -74}, 0, {-16, -16}, {61, 53, 158, 255} }},
	{{ {80, 14, -61}, 0, {-16, -16}, {97, 35, 182, 255} }},
	{{ {84, -29, -62}, 0, {-16, -16}, {95, 216, 181, 255} }},
};

Gfx mario_000_offset_001_mesh_layer_1_tri_1[] = {
	gsSPVertex(mario_000_offset_001_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 3, 2, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(10, 9, 12, 0),
	gsSP1Triangle(13, 10, 12, 0),
	gsSP1Triangle(14, 10, 13, 0),
	gsSP1Triangle(15, 10, 14, 0),
	gsSP1Triangle(15, 11, 10, 0),
	gsSPVertex(mario_000_offset_001_mesh_layer_1_vtx_1 + 16, 7, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(1, 3, 4, 0),
	gsSP1Triangle(5, 1, 4, 0),
	gsSP1Triangle(6, 1, 5, 0),
	gsSP1Triangle(6, 2, 1, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_displaylist_mesh_layer_1_vtx_0[99] = {
	{{ {97, 103, 25}, 0, {708, 942}, {78, 66, 76, 255} }},
	{{ {104, 87, 70}, 0, {1122, 848}, {43, 99, 68, 255} }},
	{{ {144, 83, 67}, 0, {1092, 412}, {32, 91, 83, 255} }},
	{{ {175, 91, 39}, 0, {826, 96}, {165, 88, 10, 255} }},
	{{ {153, 33, 95}, 0, {1346, 280}, {0, 70, 106, 255} }},
	{{ {145, 101, 0}, 0, {464, 430}, {22, 125, 0, 255} }},
	{{ {175, 91, -38}, 0, {90, 114}, {165, 88, 246, 255} }},
	{{ {97, 103, -24}, 0, {240, 954}, {78, 65, 179, 255} }},
	{{ {144, 83, -66}, 0, {-162, 444}, {32, 91, 173, 255} }},
	{{ {153, 33, -94}, 0, {-420, 326}, {0, 69, 149, 255} }},
	{{ {104, 87, -69}, 0, {-176, 882}, {43, 99, 188, 255} }},
	{{ {92, 88, 84}, 0, {-16, -16}, {42, 78, 91, 255} }},
	{{ {104, 87, 70}, 0, {-16, -16}, {43, 99, 68, 255} }},
	{{ {97, 103, 25}, 0, {-16, -16}, {78, 66, 76, 255} }},
	{{ {96, 49, 94}, 0, {-16, -16}, {11, 40, 120, 255} }},
	{{ {44, 44, 97}, 0, {-16, -16}, {209, 29, 114, 255} }},
	{{ {144, 83, 67}, 0, {-16, -16}, {32, 91, 83, 255} }},
	{{ {104, 87, 70}, 0, {-16, -16}, {43, 99, 68, 255} }},
	{{ {96, 49, 94}, 0, {-16, -16}, {11, 40, 120, 255} }},
	{{ {153, 33, 95}, 0, {-16, -16}, {0, 70, 106, 255} }},
	{{ {97, 103, -24}, 0, {240, 954}, {78, 65, 179, 255} }},
	{{ {108, 105, 0}, 0, {472, 838}, {101, 77, 255, 255} }},
	{{ {145, 101, 0}, 0, {464, 430}, {22, 125, 0, 255} }},
	{{ {97, 103, 25}, 0, {708, 942}, {78, 66, 76, 255} }},
	{{ {92, 88, -83}, 0, {-16, -16}, {42, 78, 165, 255} }},
	{{ {97, 103, -24}, 0, {-16, -16}, {78, 65, 179, 255} }},
	{{ {104, 87, -69}, 0, {-16, -16}, {43, 99, 188, 255} }},
	{{ {96, 49, -93}, 0, {-16, -16}, {12, 40, 136, 255} }},
	{{ {144, 83, -66}, 0, {-16, -16}, {32, 91, 173, 255} }},
	{{ {153, 33, -94}, 0, {-16, -16}, {0, 69, 149, 255} }},
	{{ {44, 44, -96}, 0, {-16, -16}, {209, 29, 142, 255} }},
	{{ {44, 44, 97}, 0, {-16, -16}, {209, 29, 114, 255} }},
	{{ {3, 54, 52}, 0, {-16, -16}, {143, 25, 53, 255} }},
	{{ {42, 0, 103}, 0, {-16, -16}, {184, 0, 105, 255} }},
	{{ {17, -52, 47}, 0, {-16, -16}, {134, 252, 34, 255} }},
	{{ {-7, 62, 0}, 0, {-16, -16}, {133, 33, 0, 255} }},
	{{ {17, -52, -46}, 0, {-16, -16}, {134, 252, 222, 255} }},
	{{ {3, 54, -51}, 0, {-16, -16}, {143, 25, 203, 255} }},
	{{ {42, 0, -102}, 0, {-16, -16}, {184, 0, 151, 255} }},
	{{ {44, 44, -96}, 0, {-16, -16}, {209, 29, 142, 255} }},
	{{ {56, -45, -76}, 0, {-16, -16}, {202, 199, 156, 255} }},
	{{ {64, -25, -134}, 0, {-16, -16}, {214, 5, 136, 255} }},
	{{ {85, -23, -110}, 0, {-16, -16}, {7, 91, 167, 255} }},
	{{ {102, -33, -134}, 0, {-16, -16}, {50, 237, 141, 255} }},
	{{ {120, -12, -109}, 0, {-16, -16}, {239, 31, 134, 255} }},
	{{ {91, -54, -85}, 0, {-16, -16}, {198, 192, 163, 255} }},
	{{ {97, 103, 25}, 0, {-16, -16}, {78, 66, 76, 255} }},
	{{ {108, 105, 0}, 0, {-16, -16}, {101, 77, 255, 255} }},
	{{ {117, 128, 0}, 0, {-16, -16}, {124, 229, 0, 255} }},
	{{ {97, 103, -24}, 0, {-16, -16}, {78, 65, 179, 255} }},
	{{ {102, 129, -40}, 0, {-16, -16}, {76, 224, 160, 255} }},
	{{ {77, 108, -33}, 0, {-16, -16}, {23, 45, 139, 255} }},
	{{ {75, 130, -45}, 0, {-16, -16}, {255, 226, 133, 255} }},
	{{ {47, 131, -40}, 0, {-16, -16}, {175, 233, 161, 255} }},
	{{ {52, 111, -30}, 0, {-16, -16}, {179, 54, 170, 255} }},
	{{ {32, 132, 0}, 0, {-16, -16}, {130, 237, 254, 255} }},
	{{ {41, 109, 0}, 0, {-16, -16}, {141, 54, 0, 255} }},
	{{ {52, 111, 31}, 0, {-16, -16}, {179, 55, 85, 255} }},
	{{ {47, 131, 41}, 0, {-16, -16}, {176, 231, 96, 255} }},
	{{ {77, 108, 34}, 0, {-16, -16}, {23, 45, 117, 255} }},
	{{ {75, 130, 46}, 0, {-16, -16}, {255, 226, 123, 255} }},
	{{ {102, 129, 41}, 0, {-16, -16}, {77, 224, 96, 255} }},
	{{ {104, 162, 41}, 0, {-16, -16}, {73, 57, 87, 255} }},
	{{ {102, 129, 41}, 0, {-16, -16}, {77, 224, 96, 255} }},
	{{ {117, 128, 0}, 0, {-16, -16}, {124, 229, 0, 255} }},
	{{ {119, 161, 0}, 0, {-16, -16}, {120, 41, 0, 255} }},
	{{ {102, 129, -40}, 0, {-16, -16}, {76, 224, 160, 255} }},
	{{ {104, 162, -40}, 0, {-16, -16}, {72, 56, 168, 255} }},
	{{ {75, 130, -45}, 0, {-16, -16}, {255, 226, 133, 255} }},
	{{ {78, 163, -45}, 0, {-16, -16}, {3, 67, 148, 255} }},
	{{ {52, 164, -40}, 0, {-16, -16}, {194, 66, 167, 255} }},
	{{ {47, 131, -40}, 0, {-16, -16}, {175, 233, 161, 255} }},
	{{ {32, 132, 0}, 0, {-16, -16}, {130, 237, 254, 255} }},
	{{ {33, 165, 0}, 0, {-16, -16}, {144, 60, 254, 255} }},
	{{ {47, 131, 41}, 0, {-16, -16}, {176, 231, 96, 255} }},
	{{ {52, 164, 41}, 0, {-16, -16}, {195, 67, 89, 255} }},
	{{ {75, 130, 46}, 0, {-16, -16}, {255, 226, 123, 255} }},
	{{ {78, 163, 46}, 0, {-16, -16}, {3, 68, 107, 255} }},
	{{ {104, 162, 41}, 0, {-16, -16}, {73, 57, 87, 255} }},
	{{ {101, 179, 0}, 0, {-16, -16}, {47, 118, 0, 255} }},
	{{ {78, 163, 46}, 0, {-16, -16}, {3, 68, 107, 255} }},
	{{ {119, 161, 0}, 0, {-16, -16}, {120, 41, 0, 255} }},
	{{ {104, 162, -40}, 0, {-16, -16}, {72, 56, 168, 255} }},
	{{ {78, 163, -45}, 0, {-16, -16}, {3, 67, 148, 255} }},
	{{ {60, 181, 0}, 0, {-16, -16}, {230, 124, 0, 255} }},
	{{ {52, 164, -40}, 0, {-16, -16}, {194, 66, 167, 255} }},
	{{ {33, 165, 0}, 0, {-16, -16}, {144, 60, 254, 255} }},
	{{ {52, 164, 41}, 0, {-16, -16}, {195, 67, 89, 255} }},
	{{ {42, 0, 103}, 0, {-16, -16}, {184, 0, 105, 255} }},
	{{ {64, -25, 135}, 0, {-16, -16}, {214, 5, 120, 255} }},
	{{ {85, -23, 111}, 0, {-16, -16}, {5, 91, 89, 255} }},
	{{ {56, -45, 77}, 0, {-16, -16}, {202, 199, 100, 255} }},
	{{ {17, -52, 47}, 0, {-16, -16}, {134, 252, 34, 255} }},
	{{ {91, -54, 86}, 0, {-16, -16}, {198, 192, 93, 255} }},
	{{ {64, -25, 135}, 0, {-16, -16}, {214, 5, 120, 255} }},
	{{ {91, -54, 86}, 0, {-16, -16}, {198, 192, 93, 255} }},
	{{ {102, -33, 135}, 0, {-16, -16}, {49, 236, 116, 255} }},
	{{ {120, -11, 111}, 0, {-16, -16}, {238, 32, 122, 255} }},
	{{ {85, -23, 111}, 0, {-16, -16}, {5, 91, 89, 255} }},
};

Gfx mario_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(4, 3, 2, 0),
	gsSP1Triangle(3, 5, 0, 0),
	gsSP1Triangle(6, 5, 3, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(8, 6, 9, 0),
	gsSP1Triangle(10, 7, 8, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSP1Triangle(12, 11, 14, 0),
	gsSP1Triangle(15, 14, 11, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 16, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 8, 10, 0),
	gsSP1Triangle(11, 10, 12, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(8, 11, 14, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 31, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(3, 1, 4, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(7, 9, 5, 0),
	gsSP1Triangle(7, 10, 9, 0),
	gsSP1Triangle(11, 10, 7, 0),
	gsSP1Triangle(11, 12, 10, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(10, 12, 14, 0),
	gsSP1Triangle(9, 10, 14, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 46, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(7, 6, 5, 0),
	gsSP1Triangle(5, 8, 7, 0),
	gsSP1Triangle(9, 7, 8, 0),
	gsSP1Triangle(8, 10, 9, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(11, 12, 9, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(14, 12, 13, 0),
	gsSP1Triangle(15, 14, 13, 0),
	gsSP1Triangle(13, 0, 15, 0),
	gsSP1Triangle(2, 15, 0, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 62, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(9, 8, 6, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 8, 10, 0),
	gsSP1Triangle(10, 12, 11, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(13, 14, 15, 0),
	gsSP1Triangle(15, 14, 0, 0),
	gsSP1Triangle(14, 1, 0, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 78, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(1, 3, 4, 0),
	gsSP1Triangle(1, 4, 5, 0),
	gsSP1Triangle(5, 6, 1, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 6, 7, 0),
	gsSP1Triangle(8, 9, 6, 0),
	gsSP1Triangle(9, 2, 6, 0),
	gsSP1Triangle(6, 2, 1, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(11, 10, 13, 0),
	gsSP1Triangle(14, 13, 10, 0),
	gsSP1Triangle(11, 13, 15, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_0 + 94, 5, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(0, 2, 4, 0),
	gsSPEndDisplayList(),
};

// 0x0400D8F0 - 0x0400D910
const Gfx mario_left_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_left_hand_closed_shared_dl),
    gsSPEndDisplayList(),
};

// 0x0400D910
static const Vtx mario_right_arm_shared_dl_vertex_group1[] = {
    {{{    57,    -14,    -22}, 0, {     0,      0}, {0x33, 0xcf, 0x97, 0x00}}},
    {{{     5,    -44,      5}, 0, {     0,      0}, {0xd3, 0x8a, 0xf7, 0x00}}},
    {{{     6,    -15,    -30}, 0, {     0,      0}, {0xd6, 0xe6, 0x8c, 0x00}}},
    {{{    57,    -38,      6}, 0, {     0,      0}, {0x3e, 0x93, 0x07, 0x00}}},
    {{{     6,    -19,     44}, 0, {     0,      0}, {0xd5, 0xd4, 0x6e, 0x00}}},
    {{{    57,    -17,     37}, 0, {     0,      0}, {0x33, 0xe8, 0x71, 0x00}}},
    {{{     7,     25,     32}, 0, {     0,      0}, {0xd9, 0x5c, 0x4d, 0x00}}},
    {{{    58,     17,     27}, 0, {     0,      0}, {0x44, 0x59, 0x39, 0x00}}},
    {{{     7,     27,    -13}, 0, {     0,      0}, {0xda, 0x67, 0xc2, 0x00}}},
    {{{    58,     19,     -9}, 0, {     0,      0}, {0x3e, 0x4a, 0xaf, 0x00}}},
    {{{    -9,    -28,      6}, 0, {     0,      0}, {0x96, 0xbf, 0xec, 0x00}}},
    {{{    -9,    -10,    -15}, 0, {     0,      0}, {0x8f, 0x01, 0xc7, 0x00}}},
    {{{    -8,     15,     -5}, 0, {     0,      0}, {0x91, 0x39, 0xed, 0x00}}},
    {{{    -8,     14,     22}, 0, {     0,      0}, {0x99, 0x2e, 0x38, 0x00}}},
    {{{    -9,    -13,     30}, 0, {     0,      0}, {0x8a, 0xe9, 0x26, 0x00}}},
    {{{    67,    -12,    -13}, 0, {     0,      0}, {0x68, 0xeb, 0xbc, 0x00}}},
};

// 0x0400DA10
static const Vtx mario_right_arm_shared_dl_vertex_group2[] = {
    {{{    57,    -38,      6}, 0, {     0,      0}, {0x3e, 0x93, 0x07, 0x00}}},
    {{{    67,    -14,     28}, 0, {     0,      0}, {0x6f, 0xe8, 0x37, 0x00}}},
    {{{    57,    -17,     37}, 0, {     0,      0}, {0x33, 0xe8, 0x71, 0x00}}},
    {{{    58,     17,     27}, 0, {     0,      0}, {0x44, 0x59, 0x39, 0x00}}},
    {{{    67,     11,     -4}, 0, {     0,      0}, {0x78, 0x26, 0xf1, 0x00}}},
    {{{    58,     19,     -9}, 0, {     0,      0}, {0x3e, 0x4a, 0xaf, 0x00}}},
    {{{    67,     10,     21}, 0, {     0,      0}, {0x71, 0x2a, 0x25, 0x00}}},
    {{{    66,    -28,      6}, 0, {     0,      0}, {0x75, 0xd1, 0xfe, 0x00}}},
    {{{    67,    -12,    -13}, 0, {     0,      0}, {0x68, 0xeb, 0xbc, 0x00}}},
    {{{    -9,    -13,     30}, 0, {     0,      0}, {0x8a, 0xe9, 0x26, 0x00}}},
    {{{    -9,    -28,      6}, 0, {     0,      0}, {0x96, 0xbf, 0xec, 0x00}}},
    {{{     5,    -44,      5}, 0, {     0,      0}, {0xd3, 0x8a, 0xf7, 0x00}}},
    {{{    -8,     14,     22}, 0, {     0,      0}, {0x99, 0x2e, 0x38, 0x00}}},
    {{{     6,    -19,     44}, 0, {     0,      0}, {0xd5, 0xd4, 0x6e, 0x00}}},
    {{{    -8,     15,     -5}, 0, {     0,      0}, {0x91, 0x39, 0xed, 0x00}}},
    {{{     7,     25,     32}, 0, {     0,      0}, {0xd9, 0x5c, 0x4d, 0x00}}},
};

// 0x0400DB10
static const Vtx mario_right_arm_shared_dl_vertex_group3[] = {
    {{{    -9,    -10,    -15}, 0, {     0,      0}, {0x8f, 0x01, 0xc7, 0x00}}},
    {{{    -8,     15,     -5}, 0, {     0,      0}, {0x91, 0x39, 0xed, 0x00}}},
    {{{     7,     27,    -13}, 0, {     0,      0}, {0xda, 0x67, 0xc2, 0x00}}},
    {{{    -9,    -28,      6}, 0, {     0,      0}, {0x96, 0xbf, 0xec, 0x00}}},
    {{{     6,    -15,    -30}, 0, {     0,      0}, {0xd6, 0xe6, 0x8c, 0x00}}},
    {{{    58,     19,     -9}, 0, {     0,      0}, {0x3e, 0x4a, 0xaf, 0x00}}},
    {{{    57,    -14,    -22}, 0, {     0,      0}, {0x33, 0xcf, 0x97, 0x00}}},
    {{{    58,     17,     27}, 0, {     0,      0}, {0x44, 0x59, 0x39, 0x00}}},
    {{{    57,    -17,     37}, 0, {     0,      0}, {0x33, 0xe8, 0x71, 0x00}}},
    {{{     7,     25,     32}, 0, {     0,      0}, {0xd9, 0x5c, 0x4d, 0x00}}},
    {{{    57,    -38,      6}, 0, {     0,      0}, {0x3e, 0x93, 0x07, 0x00}}},
    {{{     6,    -19,     44}, 0, {     0,      0}, {0xd5, 0xd4, 0x6e, 0x00}}},
    {{{     5,    -44,      5}, 0, {     0,      0}, {0xd3, 0x8a, 0xf7, 0x00}}},
    {{{    67,    -12,    -13}, 0, {     0,      0}, {0x68, 0xeb, 0xbc, 0x00}}},
    {{{    67,     11,     -4}, 0, {     0,      0}, {0x78, 0x26, 0xf1, 0x00}}},
    {{{    66,    -28,      6}, 0, {     0,      0}, {0x75, 0xd1, 0xfe, 0x00}}},
};

// 0x0400DC10
static const Vtx mario_right_arm_shared_dl_vertex_group4[] = {
    {{{    -9,    -10,    -15}, 0, {     0,      0}, {0x8f, 0x01, 0xc7, 0x00}}},
    {{{    -9,    -28,      6}, 0, {     0,      0}, {0x96, 0xbf, 0xec, 0x00}}},
    {{{    -9,    -13,     30}, 0, {     0,      0}, {0x8a, 0xe9, 0x26, 0x00}}},
    {{{    -8,     15,     -5}, 0, {     0,      0}, {0x91, 0x39, 0xed, 0x00}}},
    {{{    -8,     14,     22}, 0, {     0,      0}, {0x99, 0x2e, 0x38, 0x00}}},
    {{{    67,     11,     -4}, 0, {     0,      0}, {0x78, 0x26, 0xf1, 0x00}}},
    {{{    67,    -14,     28}, 0, {     0,      0}, {0x6f, 0xe8, 0x37, 0x00}}},
    {{{    66,    -28,      6}, 0, {     0,      0}, {0x75, 0xd1, 0xfe, 0x00}}},
    {{{    67,     10,     21}, 0, {     0,      0}, {0x71, 0x2a, 0x25, 0x00}}},
};

Gfx mario_000_displaylist_mesh_layer_1_tri_1[] = {
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(0, 4, 3, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(6, 3, 5, 0),
	gsSP1Triangle(7, 3, 6, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(3, 7, 1, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(9, 12, 10, 0),
	gsSP1Triangle(13, 12, 9, 0),
	gsSP1Triangle(14, 12, 13, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_1 + 16, 11, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(1, 4, 2, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 5, 7, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(10, 5, 8, 0),
	gsSPEndDisplayList(),
};

// 0x0400DDE8 - 0x0400DE08
const Gfx mario_right_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_right_arm_shared_dl),
    gsSPEndDisplayList(),
};

// 0x0400DE08
static const Vtx mario_right_forearm_shared_dl_vertex[] = {
    {{{    47,    -15,    -19}, 0, {     0,      0}, {0x41, 0xcf, 0x9f, 0x00}}},
    {{{    -3,    -39,      6}, 0, {     0,      0}, {0xd4, 0x8a, 0xf8, 0x00}}},
    {{{    -2,    -15,    -23}, 0, {     0,      0}, {0xd7, 0xe5, 0x8c, 0x00}}},
    {{{    46,    -36,      6}, 0, {     0,      0}, {0x3f, 0x94, 0x0f, 0x00}}},
    {{{    -2,    -18,     38}, 0, {     0,      0}, {0xd6, 0xd5, 0x6f, 0x00}}},
    {{{    47,    -17,     34}, 0, {     0,      0}, {0x42, 0xec, 0x6a, 0x00}}},
    {{{    -1,     18,     28}, 0, {     0,      0}, {0xdb, 0x5d, 0x4d, 0x00}}},
    {{{    48,     13,     25}, 0, {     0,      0}, {0x45, 0x5d, 0x32, 0x00}}},
    {{{    -1,     20,     -9}, 0, {     0,      0}, {0xdb, 0x67, 0xc1, 0x00}}},
    {{{    48,     15,     -7}, 0, {     0,      0}, {0x45, 0x4c, 0xb6, 0x00}}},
    {{{   -14,    -28,      6}, 0, {     0,      0}, {0x90, 0xc9, 0xef, 0x00}}},
    {{{   -14,    -12,    -13}, 0, {     0,      0}, {0x91, 0x01, 0xc3, 0x00}}},
    {{{   -13,     12,     -4}, 0, {     0,      0}, {0x9e, 0x4b, 0xe7, 0x00}}},
    {{{   -13,     10,     21}, 0, {     0,      0}, {0x8d, 0x22, 0x28, 0x00}}},
    {{{   -14,    -14,     28}, 0, {     0,      0}, {0x9a, 0xd8, 0x3f, 0x00}}},
    {{{    59,     -8,      7}, 0, {     0,      0}, {0x7f, 0xfd, 0x00, 0x00}}},
};

Gfx mario_000_displaylist_mesh_layer_1_tri_2[] = {
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_2 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(5, 8, 7, 0),
	gsSP1Triangle(9, 6, 7, 0),
	gsSP1Triangle(9, 10, 6, 0),
	gsSP1Triangle(3, 10, 9, 0),
	gsSP1Triangle(3, 9, 1, 0),
	gsSP1Triangle(1, 9, 7, 0),
	gsSP1Triangle(1, 7, 11, 0),
	gsSP1Triangle(1, 11, 12, 0),
	gsSP1Triangle(13, 12, 11, 0),
	gsSP1Triangle(13, 11, 14, 0),
	gsSP1Triangle(11, 15, 14, 0),
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_2 + 16, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(5, 6, 4, 0),
	gsSP1Triangle(6, 7, 4, 0),
	gsSP1Triangle(2, 7, 6, 0),
	gsSP1Triangle(1, 7, 2, 0),
	gsSP1Triangle(4, 7, 1, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(9, 8, 11, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_displaylist_mesh_layer_1_vtx_3[12] = {
	{{ {96, 49, 94}, 0, {-90, 710}, {11, 40, 120, 255} }},
	{{ {44, 44, 97}, 0, {180, 1350}, {209, 29, 114, 255} }},
	{{ {42, 0, 103}, 0, {952, 1176}, {184, 0, 105, 255} }},
	{{ {85, -23, 111}, 0, {1222, 502}, {5, 91, 89, 255} }},
	{{ {120, -11, 111}, 0, {906, 106}, {238, 32, 122, 255} }},
	{{ {153, 33, 95}, 0, {6, -84}, {0, 70, 106, 255} }},
	{{ {120, -12, -109}, 0, {900, 168}, {239, 31, 134, 255} }},
	{{ {96, 49, -93}, 0, {-86, 684}, {12, 40, 136, 255} }},
	{{ {153, 33, -94}, 0, {74, -74}, {0, 69, 149, 255} }},
	{{ {85, -23, -110}, 0, {1134, 566}, {7, 91, 167, 255} }},
	{{ {42, 0, -102}, 0, {826, 1194}, {184, 0, 151, 255} }},
	{{ {44, 44, -96}, 0, {102, 1318}, {209, 29, 142, 255} }},
};

Gfx mario_000_displaylist_mesh_layer_1_tri_3[] = {
	gsSPVertex(mario_000_displaylist_mesh_layer_1_vtx_3 + 0, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(5, 0, 4, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 7, 6, 0),
	gsSP1Triangle(7, 9, 10, 0),
	gsSP1Triangle(10, 11, 7, 0),
	gsSPEndDisplayList(),
};

// 0x0400E458 - 0x0400E478
const Gfx mario_right_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_right_hand_closed_dl),
    gsSPEndDisplayList(),
};

// 0x0400E478 - 0x0400E4A8
const Gfx mario_metal_right_hand_closed[] = {
    gsSPDisplayList(mario_right_hand_closed_dl),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

Vtx mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0[103] = {
	{{ {104, 87, -69}, 0, {-176, 882}, {43, 99, 188, 255} }},
	{{ {97, 103, -24}, 0, {240, 954}, {78, 65, 179, 255} }},
	{{ {144, 83, -66}, 0, {-162, 444}, {32, 91, 173, 255} }},
	{{ {175, 91, -38}, 0, {90, 114}, {33, 115, 214, 255} }},
	{{ {145, 101, 0}, 0, {464, 430}, {22, 125, 0, 255} }},
	{{ {108, 105, 0}, 0, {472, 838}, {101, 77, 255, 255} }},
	{{ {97, 103, 25}, 0, {708, 942}, {78, 66, 76, 255} }},
	{{ {175, 91, 39}, 0, {826, 96}, {33, 115, 42, 255} }},
	{{ {144, 83, 67}, 0, {1092, 412}, {32, 91, 83, 255} }},
	{{ {104, 87, 70}, 0, {1122, 848}, {43, 99, 68, 255} }},
	{{ {153, 33, 95}, 0, {1346, 280}, {255, 54, 115, 255} }},
	{{ {153, 33, -94}, 0, {-420, 326}, {245, 51, 140, 255} }},
	{{ {144, 83, -66}, 0, {-16, -16}, {32, 91, 173, 255} }},
	{{ {153, 33, -94}, 0, {-16, -16}, {245, 51, 140, 255} }},
	{{ {96, 49, -93}, 0, {-16, -16}, {12, 40, 136, 255} }},
	{{ {104, 87, -69}, 0, {-16, -16}, {43, 99, 188, 255} }},
	{{ {96, 49, -93}, 0, {-16, -16}, {12, 40, 136, 255} }},
	{{ {92, 88, -83}, 0, {-16, -16}, {42, 78, 165, 255} }},
	{{ {104, 87, -69}, 0, {-16, -16}, {43, 99, 188, 255} }},
	{{ {44, 44, -96}, 0, {-16, -16}, {209, 29, 142, 255} }},
	{{ {97, 103, -24}, 0, {-16, -16}, {78, 65, 179, 255} }},
	{{ {92, 88, 84}, 0, {-16, -16}, {42, 78, 91, 255} }},
	{{ {104, 87, 70}, 0, {-16, -16}, {43, 99, 68, 255} }},
	{{ {97, 103, 25}, 0, {-16, -16}, {78, 66, 76, 255} }},
	{{ {96, 49, 94}, 0, {-16, -16}, {11, 40, 120, 255} }},
	{{ {44, 44, 97}, 0, {-16, -16}, {209, 29, 114, 255} }},
	{{ {144, 83, 67}, 0, {-16, -16}, {32, 91, 83, 255} }},
	{{ {153, 33, 95}, 0, {-16, -16}, {255, 54, 115, 255} }},
	{{ {42, 0, -102}, 0, {-16, -16}, {184, 0, 151, 255} }},
	{{ {3, 54, -51}, 0, {-16, -16}, {143, 25, 203, 255} }},
	{{ {17, -52, -46}, 0, {-16, -16}, {134, 252, 222, 255} }},
	{{ {56, -45, -76}, 0, {-16, -16}, {202, 199, 156, 255} }},
	{{ {42, 0, -102}, 0, {-16, -16}, {184, 0, 151, 255} }},
	{{ {64, -25, -134}, 0, {-16, -16}, {214, 5, 136, 255} }},
	{{ {56, -45, -76}, 0, {-16, -16}, {202, 199, 156, 255} }},
	{{ {85, -23, -110}, 0, {-16, -16}, {7, 91, 167, 255} }},
	{{ {102, -33, -134}, 0, {-16, -16}, {50, 237, 141, 255} }},
	{{ {120, -12, -109}, 0, {-16, -16}, {1, 14, 130, 255} }},
	{{ {91, -54, -85}, 0, {-16, -16}, {218, 182, 160, 255} }},
	{{ {17, -52, -46}, 0, {-16, -16}, {134, 252, 222, 255} }},
	{{ {-7, 62, 0}, 0, {-16, -16}, {133, 33, 0, 255} }},
	{{ {3, 54, -51}, 0, {-16, -16}, {143, 25, 203, 255} }},
	{{ {17, -52, 47}, 0, {-16, -16}, {134, 252, 34, 255} }},
	{{ {31, -84, 0}, 0, {-16, -16}, {158, 175, 0, 255} }},
	{{ {3, 54, 52}, 0, {-16, -16}, {143, 25, 53, 255} }},
	{{ {42, 0, 103}, 0, {-16, -16}, {184, 0, 105, 255} }},
	{{ {56, -45, 77}, 0, {-16, -16}, {202, 199, 100, 255} }},
	{{ {64, -25, 135}, 0, {-16, -16}, {214, 5, 120, 255} }},
	{{ {64, -25, 135}, 0, {-16, -16}, {214, 5, 120, 255} }},
	{{ {56, -45, 77}, 0, {-16, -16}, {202, 199, 100, 255} }},
	{{ {91, -54, 86}, 0, {-16, -16}, {218, 182, 96, 255} }},
	{{ {102, -33, 135}, 0, {-16, -16}, {49, 236, 116, 255} }},
	{{ {120, -11, 111}, 0, {-16, -16}, {0, 15, 126, 255} }},
	{{ {85, -23, 111}, 0, {-16, -16}, {5, 91, 89, 255} }},
	{{ {42, 0, 103}, 0, {-16, -16}, {184, 0, 105, 255} }},
	{{ {44, 44, 97}, 0, {-16, -16}, {209, 29, 114, 255} }},
	{{ {3, 54, 52}, 0, {-16, -16}, {143, 25, 53, 255} }},
	{{ {97, 103, 25}, 0, {-16, -16}, {78, 66, 76, 255} }},
	{{ {108, 105, 0}, 0, {-16, -16}, {101, 77, 255, 255} }},
	{{ {117, 128, 0}, 0, {-16, -16}, {124, 229, 0, 255} }},
	{{ {97, 103, -24}, 0, {-16, -16}, {78, 65, 179, 255} }},
	{{ {102, 129, -40}, 0, {-16, -16}, {76, 224, 160, 255} }},
	{{ {77, 108, -33}, 0, {-16, -16}, {23, 45, 139, 255} }},
	{{ {75, 130, -45}, 0, {-16, -16}, {255, 226, 133, 255} }},
	{{ {47, 131, -40}, 0, {-16, -16}, {175, 233, 161, 255} }},
	{{ {75, 130, -45}, 0, {-16, -16}, {255, 226, 133, 255} }},
	{{ {77, 108, -33}, 0, {-16, -16}, {23, 45, 139, 255} }},
	{{ {52, 111, -30}, 0, {-16, -16}, {179, 54, 170, 255} }},
	{{ {32, 132, 0}, 0, {-16, -16}, {130, 237, 254, 255} }},
	{{ {41, 109, 0}, 0, {-16, -16}, {141, 54, 0, 255} }},
	{{ {52, 111, 31}, 0, {-16, -16}, {179, 55, 85, 255} }},
	{{ {47, 131, 41}, 0, {-16, -16}, {176, 231, 96, 255} }},
	{{ {77, 108, 34}, 0, {-16, -16}, {23, 45, 117, 255} }},
	{{ {75, 130, 46}, 0, {-16, -16}, {255, 226, 123, 255} }},
	{{ {102, 129, 41}, 0, {-16, -16}, {77, 224, 96, 255} }},
	{{ {97, 103, 25}, 0, {-16, -16}, {78, 66, 76, 255} }},
	{{ {117, 128, 0}, 0, {-16, -16}, {124, 229, 0, 255} }},
	{{ {104, 162, 41}, 0, {-16, -16}, {73, 57, 87, 255} }},
	{{ {119, 161, 0}, 0, {-16, -16}, {120, 41, 0, 255} }},
	{{ {102, 129, -40}, 0, {-16, -16}, {76, 224, 160, 255} }},
	{{ {102, 129, -40}, 0, {-16, -16}, {76, 224, 160, 255} }},
	{{ {104, 162, -40}, 0, {-16, -16}, {72, 56, 168, 255} }},
	{{ {119, 161, 0}, 0, {-16, -16}, {120, 41, 0, 255} }},
	{{ {75, 130, -45}, 0, {-16, -16}, {255, 226, 133, 255} }},
	{{ {78, 163, -45}, 0, {-16, -16}, {3, 67, 148, 255} }},
	{{ {52, 164, -40}, 0, {-16, -16}, {194, 66, 167, 255} }},
	{{ {47, 131, -40}, 0, {-16, -16}, {175, 233, 161, 255} }},
	{{ {32, 132, 0}, 0, {-16, -16}, {130, 237, 254, 255} }},
	{{ {33, 165, 0}, 0, {-16, -16}, {144, 60, 254, 255} }},
	{{ {47, 131, 41}, 0, {-16, -16}, {176, 231, 96, 255} }},
	{{ {52, 164, 41}, 0, {-16, -16}, {195, 67, 89, 255} }},
	{{ {75, 130, 46}, 0, {-16, -16}, {255, 226, 123, 255} }},
	{{ {78, 163, 46}, 0, {-16, -16}, {3, 68, 107, 255} }},
	{{ {104, 162, 41}, 0, {-16, -16}, {73, 57, 87, 255} }},
	{{ {102, 129, 41}, 0, {-16, -16}, {77, 224, 96, 255} }},
	{{ {101, 179, 0}, 0, {-16, -16}, {47, 118, 0, 255} }},
	{{ {78, 163, -45}, 0, {-16, -16}, {3, 67, 148, 255} }},
	{{ {60, 181, 0}, 0, {-16, -16}, {230, 124, 0, 255} }},
	{{ {101, 179, 0}, 0, {-16, -16}, {47, 118, 0, 255} }},
	{{ {52, 164, -40}, 0, {-16, -16}, {194, 66, 167, 255} }},
	{{ {33, 165, 0}, 0, {-16, -16}, {144, 60, 254, 255} }},
	{{ {52, 164, 41}, 0, {-16, -16}, {195, 67, 89, 255} }},
	{{ {78, 163, 46}, 0, {-16, -16}, {3, 68, 107, 255} }},
};

Gfx mario_002_switch_option_head__no_cap__mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSP1Triangle(1, 5, 4, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(7, 4, 6, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(6, 9, 8, 0),
	gsSP1Triangle(10, 7, 8, 0),
	gsSP1Triangle(3, 4, 7, 0),
	gsSP1Triangle(2, 3, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(14, 15, 12, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(1, 4, 2, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(6, 5, 8, 0),
	gsSP1Triangle(9, 8, 5, 0),
	gsSP1Triangle(10, 6, 8, 0),
	gsSP1Triangle(8, 11, 10, 0),
	gsSP1Triangle(12, 13, 3, 0),
	gsSP1Triangle(12, 14, 13, 0),
	gsSP1Triangle(12, 15, 14, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(1, 4, 6, 0),
	gsSP1Triangle(2, 1, 6, 0),
	gsSP1Triangle(7, 8, 9, 0),
	gsSP1Triangle(7, 10, 8, 0),
	gsSP1Triangle(7, 11, 10, 0),
	gsSP1Triangle(10, 12, 8, 0),
	gsSP1Triangle(12, 10, 13, 0),
	gsSP1Triangle(10, 14, 13, 0),
	gsSP1Triangle(15, 13, 14, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 48, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(0, 3, 5, 0),
	gsSP1Triangle(6, 0, 5, 0),
	gsSP1Triangle(7, 8, 6, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(11, 10, 12, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(15, 13, 14, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 64, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(6, 7, 4, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(9, 7, 8, 0),
	gsSP1Triangle(10, 9, 8, 0),
	gsSP1Triangle(8, 11, 10, 0),
	gsSP1Triangle(12, 10, 11, 0),
	gsSP1Triangle(13, 10, 12, 0),
	gsSP1Triangle(14, 13, 12, 0),
	gsSP1Triangle(12, 15, 14, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 80, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 5, 3, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 5, 7, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(9, 10, 8, 0),
	gsSP1Triangle(10, 9, 11, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(11, 14, 13, 0),
	gsSP1Triangle(13, 15, 12, 0),
	gsSP1Triangle(15, 13, 2, 0),
	gsSP1Triangle(15, 2, 1, 0),
	gsSP1Triangle(15, 1, 4, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_0 + 96, 7, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(4, 1, 3, 0),
	gsSP1Triangle(4, 5, 1, 0),
	gsSP1Triangle(5, 6, 1, 0),
	gsSP1Triangle(1, 6, 2, 0),
	gsSPEndDisplayList(),
};

// 0x0400E7B0 - 0x0400E7E0
const Gfx mario_left_thigh[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_left_thigh_dl),
    gsSPEndDisplayList(),
};

// 0x0400E7E0 - 0x0400E858
const Gfx mario_metal_left_thigh[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_left_thigh_dl),
    gsSPEndDisplayList(),
};

Vtx mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_2[12] = {
	{{ {96, 49, 94}, 0, {-90, 710}, {11, 40, 120, 255} }},
	{{ {44, 44, 97}, 0, {180, 1350}, {209, 29, 114, 255} }},
	{{ {42, 0, 103}, 0, {952, 1176}, {184, 0, 105, 255} }},
	{{ {85, -23, 111}, 0, {1222, 502}, {5, 91, 89, 255} }},
	{{ {120, -11, 111}, 0, {906, 106}, {0, 15, 126, 255} }},
	{{ {153, 33, 95}, 0, {6, -84}, {255, 54, 115, 255} }},
	{{ {42, 0, -102}, 0, {826, 1194}, {184, 0, 151, 255} }},
	{{ {44, 44, -96}, 0, {102, 1318}, {209, 29, 142, 255} }},
	{{ {96, 49, -93}, 0, {-86, 684}, {12, 40, 136, 255} }},
	{{ {85, -23, -110}, 0, {1134, 566}, {7, 91, 167, 255} }},
	{{ {120, -12, -109}, 0, {900, 168}, {1, 14, 130, 255} }},
	{{ {153, 33, -94}, 0, {74, -74}, {245, 51, 140, 255} }},
};

Gfx mario_002_switch_option_head__no_cap__mesh_layer_1_tri_2[] = {
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_2 + 0, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(5, 0, 4, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(8, 9, 6, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSP1Triangle(10, 8, 11, 0),
	gsSPEndDisplayList(),
};

Vtx mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3[92] = {
	{{ {153, 33, 95}, 0, {-16, -16}, {255, 54, 115, 255} }},
	{{ {200, 75, 84}, 0, {-16, -16}, {33, 81, 93, 255} }},
	{{ {151, 72, 70}, 0, {-16, -16}, {227, 91, 84, 255} }},
	{{ {181, -9, 116}, 0, {-16, -16}, {42, 2, 120, 255} }},
	{{ {120, -11, 111}, 0, {-16, -16}, {0, 15, 126, 255} }},
	{{ {145, -83, 105}, 0, {-16, -16}, {0, 202, 115, 255} }},
	{{ {91, -54, 86}, 0, {-16, -16}, {218, 182, 96, 255} }},
	{{ {64, -103, 52}, 0, {-16, -16}, {25, 139, 44, 255} }},
	{{ {56, -45, 77}, 0, {-16, -16}, {202, 199, 100, 255} }},
	{{ {58, -114, 60}, 0, {-16, -16}, {87, 169, 32, 255} }},
	{{ {31, -85, 87}, 0, {-16, -16}, {228, 250, 124, 255} }},
	{{ {17, -52, 47}, 0, {-16, -16}, {134, 252, 34, 255} }},
	{{ {9, -88, 59}, 0, {-16, -16}, {132, 237, 22, 255} }},
	{{ {31, -84, 0}, 0, {-16, -16}, {158, 175, 0, 255} }},
	{{ {36, -116, 36}, 0, {-16, -16}, {239, 146, 195, 255} }},
	{{ {64, -103, -51}, 0, {-16, -16}, {25, 139, 213, 255} }},
	{{ {31, -84, 0}, 0, {-16, -16}, {158, 175, 0, 255} }},
	{{ {36, -116, -35}, 0, {-16, -16}, {239, 146, 61, 255} }},
	{{ {64, -103, -51}, 0, {-16, -16}, {25, 139, 213, 255} }},
	{{ {9, -88, -58}, 0, {-16, -16}, {132, 237, 234, 255} }},
	{{ {17, -52, -46}, 0, {-16, -16}, {134, 252, 222, 255} }},
	{{ {31, -85, -86}, 0, {-16, -16}, {228, 250, 132, 255} }},
	{{ {56, -45, -76}, 0, {-16, -16}, {202, 199, 156, 255} }},
	{{ {58, -114, -59}, 0, {-16, -16}, {87, 169, 224, 255} }},
	{{ {91, -54, -85}, 0, {-16, -16}, {218, 182, 160, 255} }},
	{{ {145, -84, -104}, 0, {-16, -16}, {0, 201, 141, 255} }},
	{{ {120, -12, -109}, 0, {-16, -16}, {1, 14, 130, 255} }},
	{{ {182, -9, -115}, 0, {-16, -16}, {43, 255, 136, 255} }},
	{{ {153, 33, -94}, 0, {-16, -16}, {245, 51, 140, 255} }},
	{{ {200, 70, -97}, 0, {-16, -16}, {32, 64, 151, 255} }},
	{{ {151, 72, -68}, 0, {-16, -16}, {216, 94, 181, 255} }},
	{{ {175, 91, -38}, 0, {-16, -16}, {199, 100, 201, 255} }},
	{{ {200, 70, -97}, 0, {-16, -16}, {32, 64, 151, 255} }},
	{{ {175, 91, -38}, 0, {-16, -16}, {199, 100, 201, 255} }},
	{{ {211, 91, -71}, 0, {-16, -16}, {35, 82, 165, 255} }},
	{{ {201, 125, -13}, 0, {-16, -16}, {249, 127, 0, 255} }},
	{{ {160, 96, 0}, 0, {-16, -16}, {184, 105, 4, 255} }},
	{{ {175, 91, 39}, 0, {-16, -16}, {227, 112, 53, 255} }},
	{{ {209, 86, 60}, 0, {-16, -16}, {49, 98, 64, 255} }},
	{{ {200, 75, 84}, 0, {-16, -16}, {33, 81, 93, 255} }},
	{{ {151, 72, 70}, 0, {-16, -16}, {227, 91, 84, 255} }},
	{{ {227, 35, 75}, 0, {-16, -16}, {108, 11, 66, 255} }},
	{{ {181, -9, 116}, 0, {-16, -16}, {42, 2, 120, 255} }},
	{{ {227, -14, 59}, 0, {-16, -16}, {114, 235, 52, 255} }},
	{{ {189, -102, 73}, 0, {-16, -16}, {74, 176, 66, 255} }},
	{{ {145, -83, 105}, 0, {-16, -16}, {0, 202, 115, 255} }},
	{{ {116, -126, 68}, 0, {-16, -16}, {235, 148, 64, 255} }},
	{{ {64, -103, 52}, 0, {-16, -16}, {25, 139, 44, 255} }},
	{{ {64, -103, 52}, 0, {-16, -16}, {25, 139, 44, 255} }},
	{{ {119, -134, 0}, 0, {-16, -16}, {241, 130, 255, 255} }},
	{{ {116, -126, 68}, 0, {-16, -16}, {235, 148, 64, 255} }},
	{{ {64, -103, -51}, 0, {-16, -16}, {25, 139, 213, 255} }},
	{{ {116, -124, -67}, 0, {-16, -16}, {235, 148, 192, 255} }},
	{{ {145, -84, -104}, 0, {-16, -16}, {0, 201, 141, 255} }},
	{{ {189, -102, -71}, 0, {-16, -16}, {73, 175, 191, 255} }},
	{{ {182, -9, -115}, 0, {-16, -16}, {43, 255, 136, 255} }},
	{{ {227, -14, -58}, 0, {-16, -16}, {114, 239, 203, 255} }},
	{{ {221, 35, -73}, 0, {-16, -16}, {112, 3, 196, 255} }},
	{{ {200, 70, -97}, 0, {-16, -16}, {32, 64, 151, 255} }},
	{{ {211, 91, -71}, 0, {-16, -16}, {35, 82, 165, 255} }},
	{{ {232, 69, -34}, 0, {-16, -16}, {117, 226, 216, 255} }},
	{{ {248, 104, -43}, 0, {-16, -16}, {106, 51, 208, 255} }},
	{{ {201, 125, -13}, 0, {-16, -16}, {249, 127, 0, 255} }},
	{{ {209, 86, 60}, 0, {-16, -16}, {49, 98, 64, 255} }},
	{{ {209, 86, 60}, 0, {-16, -16}, {49, 98, 64, 255} }},
	{{ {231, 81, 33}, 0, {-16, -16}, {108, 52, 42, 255} }},
	{{ {248, 104, -43}, 0, {-16, -16}, {106, 51, 208, 255} }},
	{{ {227, 35, 75}, 0, {-16, -16}, {108, 11, 66, 255} }},
	{{ {237, 64, 0}, 0, {-16, -16}, {127, 249, 4, 255} }},
	{{ {227, -14, 59}, 0, {-16, -16}, {114, 235, 52, 255} }},
	{{ {241, -34, 0}, 0, {-16, -16}, {124, 229, 0, 255} }},
	{{ {189, -102, 73}, 0, {-16, -16}, {74, 176, 66, 255} }},
	{{ {200, -117, 0}, 0, {-16, -16}, {80, 157, 0, 255} }},
	{{ {116, -126, 68}, 0, {-16, -16}, {235, 148, 64, 255} }},
	{{ {119, -134, 0}, 0, {-16, -16}, {241, 130, 255, 255} }},
	{{ {116, -124, -67}, 0, {-16, -16}, {235, 148, 192, 255} }},
	{{ {189, -102, -71}, 0, {-16, -16}, {73, 175, 191, 255} }},
	{{ {227, -14, -58}, 0, {-16, -16}, {114, 239, 203, 255} }},
	{{ {221, 35, -73}, 0, {-16, -16}, {112, 3, 196, 255} }},
	{{ {232, 69, -34}, 0, {-16, -16}, {117, 226, 216, 255} }},
	{{ {36, -116, -35}, 0, {-16, -16}, {239, 146, 61, 255} }},
	{{ {58, -114, -59}, 0, {-16, -16}, {87, 169, 224, 255} }},
	{{ {64, -103, -51}, 0, {-16, -16}, {25, 139, 213, 255} }},
	{{ {35, -120, -67}, 0, {-16, -16}, {230, 146, 198, 255} }},
	{{ {9, -88, -58}, 0, {-16, -16}, {132, 237, 234, 255} }},
	{{ {31, -85, -86}, 0, {-16, -16}, {228, 250, 132, 255} }},
	{{ {58, -114, 60}, 0, {-16, -16}, {87, 169, 32, 255} }},
	{{ {36, -116, 36}, 0, {-16, -16}, {239, 146, 195, 255} }},
	{{ {64, -103, 52}, 0, {-16, -16}, {25, 139, 44, 255} }},
	{{ {35, -120, 68}, 0, {-16, -16}, {230, 146, 58, 255} }},
	{{ {31, -85, 87}, 0, {-16, -16}, {228, 250, 124, 255} }},
	{{ {9, -88, 59}, 0, {-16, -16}, {132, 237, 22, 255} }},
};

Gfx mario_002_switch_option_head__no_cap__mesh_layer_1_tri_3[] = {
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(0, 4, 3, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(9, 7, 8, 0),
	gsSP1Triangle(8, 10, 9, 0),
	gsSP1Triangle(10, 8, 11, 0),
	gsSP1Triangle(11, 12, 10, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(13, 14, 12, 0),
	gsSP1Triangle(13, 7, 14, 0),
	gsSP1Triangle(13, 15, 7, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(0, 4, 3, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(6, 2, 7, 0),
	gsSP1Triangle(6, 8, 2, 0),
	gsSP1Triangle(8, 9, 2, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSP1Triangle(11, 9, 10, 0),
	gsSP1Triangle(10, 12, 11, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(15, 13, 14, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 3, 5, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(5, 8, 7, 0),
	gsSP1Triangle(7, 9, 6, 0),
	gsSP1Triangle(10, 9, 7, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(11, 10, 12, 0),
	gsSP1Triangle(13, 12, 10, 0),
	gsSP1Triangle(13, 14, 12, 0),
	gsSP1Triangle(15, 14, 13, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 48, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(7, 6, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(8, 7, 9, 0),
	gsSP1Triangle(10, 9, 7, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(9, 11, 12, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(11, 14, 13, 0),
	gsSP1Triangle(14, 15, 13, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 64, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(5, 6, 4, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 6, 7, 0),
	gsSP1Triangle(8, 7, 9, 0),
	gsSP1Triangle(10, 8, 9, 0),
	gsSP1Triangle(10, 11, 8, 0),
	gsSP1Triangle(11, 12, 8, 0),
	gsSP1Triangle(8, 12, 6, 0),
	gsSP1Triangle(12, 13, 6, 0),
	gsSP1Triangle(13, 4, 6, 0),
	gsSP1Triangle(13, 14, 4, 0),
	gsSP1Triangle(14, 15, 4, 0),
	gsSP1Triangle(4, 15, 2, 0),
	gsSP1Triangle(4, 2, 1, 0),
	gsSPVertex(mario_002_switch_option_head__no_cap__mesh_layer_1_vtx_3 + 80, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(3, 5, 1, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(6, 9, 7, 0),
	gsSP1Triangle(10, 9, 6, 0),
	gsSP1Triangle(11, 9, 10, 0),
	gsSP1Triangle(7, 9, 11, 0),
	gsSPEndDisplayList(),
};

// 0x0400ECA0 - 0x0400ECC0
const Gfx mario_left_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_left_foot_shared_dl),
    gsSPEndDisplayList(),
};

// 0x0400ECC0
static const Vtx mario_right_thigh_shared_dl_vertex_group1[] = {
    {{{    98,    -35,    -10}, 0, {     0,      0}, {0x47, 0x97, 0xfc, 0x00}}},
    {{{    19,    -16,     41}, 0, {     0,      0}, {0xee, 0xd6, 0x76, 0x00}}},
    {{{    22,    -54,     -9}, 0, {     0,      0}, {0xf2, 0x82, 0xfd, 0x00}}},
    {{{    91,     46,     16}, 0, {     0,      0}, {0x35, 0x5c, 0x44, 0x00}}},
    {{{    13,     48,     24}, 0, {     0,      0}, {0xd6, 0x66, 0x3e, 0x00}}},
    {{{    12,     49,    -37}, 0, {     0,      0}, {0xe5, 0x6e, 0xc9, 0x00}}},
    {{{    90,     47,    -32}, 0, {     0,      0}, {0x3b, 0x50, 0xb2, 0x00}}},
    {{{    18,    -13,    -58}, 0, {     0,      0}, {0xea, 0xdc, 0x89, 0x00}}},
    {{{     1,    -44,     -9}, 0, {     0,      0}, {0xad, 0xa1, 0xff, 0x00}}},
    {{{   -15,      0,     -7}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    -1,    -11,    -47}, 0, {     0,      0}, {0x9d, 0xe3, 0xb7, 0x00}}},
    {{{    -6,     38,    -31}, 0, {     0,      0}, {0x9e, 0x3f, 0xcf, 0x00}}},
    {{{    -5,     36,     18}, 0, {     0,      0}, {0x9e, 0x2d, 0x42, 0x00}}},
    {{{    95,     -3,    -49}, 0, {     0,      0}, {0x4d, 0xec, 0x9e, 0x00}}},
    {{{   116,     11,     -9}, 0, {     0,      0}, {0x7e, 0x0b, 0xfe, 0x00}}},
    {{{    96,     -5,     30}, 0, {     0,      0}, {0x51, 0xe7, 0x5d, 0x00}}},
};

// 0x0400EDC0
static const Vtx mario_right_thigh_shared_dl_vertex_group2[] = {
    {{{    -5,     36,     18}, 0, {     0,      0}, {0x9e, 0x2d, 0x42, 0x00}}},
    {{{   -15,      0,     -7}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{     0,    -14,     31}, 0, {     0,      0}, {0xa0, 0xdf, 0x4b, 0x00}}},
    {{{     1,    -44,     -9}, 0, {     0,      0}, {0xad, 0xa1, 0xff, 0x00}}},
    {{{    19,    -16,     41}, 0, {     0,      0}, {0xee, 0xd6, 0x76, 0x00}}},
    {{{    -6,     38,    -31}, 0, {     0,      0}, {0x9e, 0x3f, 0xcf, 0x00}}},
    {{{    13,     48,     24}, 0, {     0,      0}, {0xd6, 0x66, 0x3e, 0x00}}},
    {{{    18,    -13,    -58}, 0, {     0,      0}, {0xea, 0xdc, 0x89, 0x00}}},
    {{{    -1,    -11,    -47}, 0, {     0,      0}, {0x9d, 0xe3, 0xb7, 0x00}}},
    {{{    95,     -3,    -49}, 0, {     0,      0}, {0x4d, 0xec, 0x9e, 0x00}}},
    {{{    98,    -35,    -10}, 0, {     0,      0}, {0x47, 0x97, 0xfc, 0x00}}},
    {{{    90,     47,    -32}, 0, {     0,      0}, {0x3b, 0x50, 0xb2, 0x00}}},
    {{{    91,     46,     16}, 0, {     0,      0}, {0x35, 0x5c, 0x44, 0x00}}},
    {{{    12,     49,    -37}, 0, {     0,      0}, {0xe5, 0x6e, 0xc9, 0x00}}},
    {{{    96,     -5,     30}, 0, {     0,      0}, {0x51, 0xe7, 0x5d, 0x00}}},
};

Gfx mario_000_displaylist_001_mesh_layer_4_tri_0[] = {
	gsSPVertex(mario_000_displaylist_001_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

// 0x0400EFB8 - 0x0400EFD8
const Gfx mario_right_thigh[] = {
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_right_thigh_shared_dl),
    gsSPEndDisplayList(),
};

// 0x0400EFD8
static const Vtx mario_right_leg_shared_dl_vertex_group1[] = {
    {{{    63,    -45,    -12}, 0, {     0,      0}, {0xf2, 0x9b, 0x4a, 0x00}}},
    {{{    66,    -11,     34}, 0, {     0,      0}, {0xf2, 0x9b, 0x4a, 0x00}}},
    {{{     4,    -36,    -10}, 0, {     0,      0}, {0xc0, 0x93, 0xfe, 0x00}}},
    {{{    66,    -11,     34}, 0, {     0,      0}, {0xfb, 0x22, 0x7a, 0x00}}},
    {{{    69,     45,     18}, 0, {     0,      0}, {0xfc, 0x22, 0x7a, 0x00}}},
    {{{     9,     44,     16}, 0, {     0,      0}, {0xc6, 0x4b, 0x53, 0x00}}},
    {{{    69,     45,     18}, 0, {     0,      0}, {0xff, 0x7f, 0x03, 0x00}}},
    {{{    69,     46,    -37}, 0, {     0,      0}, {0xff, 0x7f, 0x03, 0x00}}},
    {{{     9,     46,    -33}, 0, {     0,      0}, {0xcd, 0x60, 0xc0, 0x00}}},
    {{{    69,     46,    -37}, 0, {     0,      0}, {0xf7, 0x27, 0x88, 0x00}}},
    {{{    65,     -9,    -56}, 0, {     0,      0}, {0xf8, 0x28, 0x88, 0x00}}},
    {{{    65,     -9,    -56}, 0, {     0,      0}, {0xef, 0xa0, 0xb0, 0x00}}},
    {{{    63,    -45,    -12}, 0, {     0,      0}, {0xef, 0xa0, 0xb0, 0x00}}},
    {{{     6,     -6,     30}, 0, {     0,      0}, {0xb4, 0xe4, 0x61, 0x00}}},
    {{{   -13,     10,     -9}, 0, {     0,      0}, {0x82, 0x08, 0x02, 0x00}}},
    {{{     5,     -3,    -50}, 0, {     0,      0}, {0xb2, 0xea, 0xa0, 0x00}}},
};

// 0x0400F0D8
static const Vtx mario_right_leg_shared_dl_vertex_group2[] = {
    {{{    65,     -9,    -56}, 0, {     0,      0}, {0x75, 0xee, 0xd5, 0x00}}},
    {{{    83,      4,    -10}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    63,    -45,    -12}, 0, {     0,      0}, {0x75, 0xd1, 0xfd, 0x00}}},
    {{{    66,    -11,     34}, 0, {     0,      0}, {0x77, 0xec, 0x26, 0x00}}},
    {{{    69,     45,     18}, 0, {     0,      0}, {0x7a, 0x18, 0x17, 0x00}}},
    {{{    69,     46,    -37}, 0, {     0,      0}, {0x79, 0x19, 0xe6, 0x00}}},
    {{{     4,    -36,    -10}, 0, {     0,      0}, {0xc0, 0x93, 0xfe, 0x00}}},
    {{{     5,     -3,    -50}, 0, {     0,      0}, {0xb2, 0xea, 0xa0, 0x00}}},
    {{{    65,     -9,    -56}, 0, {     0,      0}, {0xef, 0xa0, 0xb0, 0x00}}},
    {{{    65,     -9,    -56}, 0, {     0,      0}, {0xf8, 0x28, 0x88, 0x00}}},
    {{{     9,     46,    -33}, 0, {     0,      0}, {0xcd, 0x60, 0xc0, 0x00}}},
    {{{     9,     44,     16}, 0, {     0,      0}, {0xc6, 0x4b, 0x53, 0x00}}},
    {{{    69,     45,     18}, 0, {     0,      0}, {0xff, 0x7f, 0x03, 0x00}}},
    {{{     6,     -6,     30}, 0, {     0,      0}, {0xb4, 0xe4, 0x61, 0x00}}},
    {{{    66,    -11,     34}, 0, {     0,      0}, {0xfb, 0x22, 0x7a, 0x00}}},
    {{{    66,    -11,     34}, 0, {     0,      0}, {0xf2, 0x9b, 0x4a, 0x00}}},
};

Gfx mario_000_displaylist_001_mesh_layer_4_tri_1[] = {
	gsSPVertex(mario_000_displaylist_001_mesh_layer_4_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_displaylist_002_mesh_layer_4_vtx_0[4] = {
	{{ {0, 0, 0}, 0, {-16, 1978}, {233, 0, 125, 255} }},
	{{ {104, 0, 19}, 0, {974, 1978}, {233, 0, 125, 255} }},
	{{ {104, 212, 19}, 0, {974, -34}, {233, 0, 125, 255} }},
	{{ {0, 212, 0}, 0, {-16, -34}, {234, 0, 125, 255} }},
};

Gfx mario_000_displaylist_002_mesh_layer_4_tri_0[] = {
	gsSPVertex(mario_000_displaylist_002_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

// 0x0400F4E8 - 0x0400F528
const Gfx mario_right_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_right_foot_dl),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

// 0x0400F528 - 0x0400F568
const Gfx mario_metal_right_foot[] = {
    gsSPDisplayList(mario_right_foot_dl),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

Vtx mario_000_offset_003_mesh_layer_1_vtx_0[31] = {
	{{ {6, -13, -42}, 0, {-16, -16}, {219, 225, 138, 255} }},
	{{ {-8, -9, -27}, 0, {-16, -16}, {144, 241, 198, 255} }},
	{{ {-8, 17, -17}, 0, {-16, -16}, {146, 54, 223, 255} }},
	{{ {5, -42, -5}, 0, {-16, -16}, {216, 135, 254, 255} }},
	{{ {57, -36, -5}, 0, {-16, -16}, {49, 139, 253, 255} }},
	{{ {58, -13, -34}, 0, {-16, -16}, {51, 223, 144, 255} }},
	{{ {7, 29, -26}, 0, {-16, -16}, {224, 103, 188, 255} }},
	{{ {-8, 16, 10}, 0, {-16, -16}, {146, 51, 37, 255} }},
	{{ {-8, -11, 18}, 0, {-16, -16}, {144, 237, 58, 255} }},
	{{ {-9, -26, -5}, 0, {-16, -16}, {142, 200, 254, 255} }},
	{{ {6, -16, 32}, 0, {-16, -16}, {219, 216, 115, 255} }},
	{{ {58, -15, 25}, 0, {-16, -16}, {52, 216, 109, 255} }},
	{{ {67, -12, 16}, 0, {-16, -16}, {111, 232, 58, 255} }},
	{{ {67, -26, -5}, 0, {-16, -16}, {109, 191, 254, 255} }},
	{{ {68, -10, -25}, 0, {-16, -16}, {110, 240, 194, 255} }},
	{{ {68, 13, -16}, 0, {-16, -16}, {111, 50, 221, 255} }},
	{{ {59, 21, -21}, 0, {-16, -16}, {55, 95, 192, 255} }},
	{{ {68, 13, -16}, 0, {-16, -16}, {111, 50, 221, 255} }},
	{{ {58, -13, -34}, 0, {-16, -16}, {51, 223, 144, 255} }},
	{{ {7, 29, -26}, 0, {-16, -16}, {224, 103, 188, 255} }},
	{{ {7, 27, 20}, 0, {-16, -16}, {223, 96, 76, 255} }},
	{{ {-8, 16, 10}, 0, {-16, -16}, {146, 51, 37, 255} }},
	{{ {-8, -11, 18}, 0, {-16, -16}, {144, 237, 58, 255} }},
	{{ {6, -16, 32}, 0, {-16, -16}, {219, 216, 115, 255} }},
	{{ {-9, -26, -5}, 0, {-16, -16}, {142, 200, 254, 255} }},
	{{ {59, 20, 15}, 0, {-16, -16}, {55, 90, 71, 255} }},
	{{ {58, -15, 25}, 0, {-16, -16}, {52, 216, 109, 255} }},
	{{ {67, -12, 16}, 0, {-16, -16}, {111, 232, 58, 255} }},
	{{ {68, 12, 9}, 0, {-16, -16}, {113, 44, 38, 255} }},
	{{ {68, -10, -25}, 0, {-16, -16}, {110, 240, 194, 255} }},
	{{ {67, -26, -5}, 0, {-16, -16}, {109, 191, 254, 255} }},
};

Gfx mario_000_offset_003_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_offset_003_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 0, 4, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(0, 6, 5, 0),
	gsSP1Triangle(0, 2, 6, 0),
	gsSP1Triangle(6, 2, 7, 0),
	gsSP1Triangle(8, 7, 2, 0),
	gsSP1Triangle(2, 1, 8, 0),
	gsSP1Triangle(1, 9, 8, 0),
	gsSP1Triangle(3, 9, 1, 0),
	gsSP1Triangle(10, 9, 3, 0),
	gsSP1Triangle(10, 3, 11, 0),
	gsSP1Triangle(3, 4, 11, 0),
	gsSP1Triangle(4, 12, 11, 0),
	gsSP1Triangle(4, 13, 12, 0),
	gsSP1Triangle(14, 13, 4, 0),
	gsSP1Triangle(5, 14, 4, 0),
	gsSP1Triangle(15, 14, 5, 0),
	gsSPVertex(mario_000_offset_003_mesh_layer_1_vtx_0 + 16, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(4, 7, 9, 0),
	gsSP1Triangle(7, 10, 9, 0),
	gsSP1Triangle(10, 11, 9, 0),
	gsSP1Triangle(11, 12, 9, 0),
	gsSP1Triangle(12, 11, 13, 0),
	gsSP1Triangle(11, 14, 13, 0),
	gsSP1Triangle(12, 13, 1, 0),
	gsSP1Triangle(9, 12, 1, 0),
	gsSP1Triangle(9, 1, 0, 0),
	gsSP1Triangle(4, 9, 0, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_offset_004_mesh_layer_1_vtx_0[16] = {
	{{ {-2, 21, -21}, 0, {-16, -16}, {224, 103, 189, 255} }},
	{{ {-14, 13, -15}, 0, {-16, -16}, {150, 61, 221, 255} }},
	{{ {-14, 11, 10}, 0, {-16, -16}, {149, 55, 42, 255} }},
	{{ {-3, -14, -34}, 0, {-16, -16}, {221, 224, 138, 255} }},
	{{ {46, -14, -30}, 0, {-16, -16}, {64, 224, 151, 255} }},
	{{ {47, 16, -19}, 0, {-16, -16}, {67, 89, 196, 255} }},
	{{ {-2, 19, 16}, 0, {-16, -16}, {225, 97, 76, 255} }},
	{{ {-15, -13, 17}, 0, {-16, -16}, {149, 236, 65, 255} }},
	{{ {-15, -27, -4}, 0, {-16, -16}, {147, 191, 253, 255} }},
	{{ {-15, -11, -24}, 0, {-16, -16}, {147, 241, 192, 255} }},
	{{ {-3, -38, -4}, 0, {-16, -16}, {220, 134, 252, 255} }},
	{{ {45, -34, -4}, 0, {-16, -16}, {62, 145, 252, 255} }},
	{{ {58, -7, -3}, 0, {-16, -16}, {127, 253, 1, 255} }},
	{{ {47, 14, 13}, 0, {-16, -16}, {67, 84, 68, 255} }},
	{{ {-3, -17, 26}, 0, {-16, -16}, {222, 215, 115, 255} }},
	{{ {46, -17, 22}, 0, {-16, -16}, {64, 216, 102, 255} }},
};

Gfx mario_000_offset_004_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_offset_004_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 0, 4, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(0, 6, 5, 0),
	gsSP1Triangle(0, 2, 6, 0),
	gsSP1Triangle(6, 2, 7, 0),
	gsSP1Triangle(8, 7, 2, 0),
	gsSP1Triangle(8, 2, 1, 0),
	gsSP1Triangle(9, 8, 1, 0),
	gsSP1Triangle(3, 9, 1, 0),
	gsSP1Triangle(10, 9, 3, 0),
	gsSP1Triangle(10, 3, 11, 0),
	gsSP1Triangle(3, 4, 11, 0),
	gsSP1Triangle(4, 12, 11, 0),
	gsSP1Triangle(5, 12, 4, 0),
	gsSP1Triangle(13, 12, 5, 0),
	gsSP1Triangle(6, 13, 5, 0),
	gsSP1Triangle(6, 14, 13, 0),
	gsSP1Triangle(6, 7, 14, 0),
	gsSP1Triangle(14, 7, 8, 0),
	gsSP1Triangle(14, 8, 10, 0),
	gsSP1Triangle(10, 8, 9, 0),
	gsSP1Triangle(14, 10, 15, 0),
	gsSP1Triangle(10, 11, 15, 0),
	gsSP1Triangle(11, 12, 15, 0),
	gsSP1Triangle(15, 12, 13, 0),
	gsSP1Triangle(14, 15, 13, 0),
	gsSPEndDisplayList(),
};

// 0x04010348 - 0x04010370
const Gfx mario_torso_dl[] = {
    gsSPDisplayList(mario_pants_overalls_shared_dl),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_tshirt_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04010370 - 0x040103F0
const Gfx mario_torso[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_yellow_button),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_yellow_button_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_torso_dl),
    gsSPEndDisplayList(),
};

Vtx mario_002_switch_option_right_hand_open_mesh_layer_1_vtx_0[58] = {
	{{ {2, 3, 26}, 0, {-16, -16}, {74, 52, 89, 255} }},
	{{ {20, -46, 12}, 0, {-16, -16}, {117, 221, 35, 255} }},
	{{ {26, -32, 6}, 0, {-16, -16}, {55, 168, 73, 255} }},
	{{ {13, -39, -31}, 0, {-16, -16}, {99, 222, 184, 255} }},
	{{ {20, -27, -27}, 0, {-16, -16}, {16, 178, 157, 255} }},
	{{ {-10, 14, -43}, 0, {-16, -16}, {50, 60, 156, 255} }},
	{{ {1, 15, -37}, 0, {-16, -16}, {225, 28, 136, 255} }},
	{{ {-3, 35, -9}, 0, {-16, -16}, {206, 114, 24, 255} }},
	{{ {-17, 40, -8}, 0, {-16, -16}, {43, 120, 0, 255} }},
	{{ {11, 5, 17}, 0, {-16, -16}, {5, 27, 124, 255} }},
	{{ {26, 16, 28}, 0, {-16, -16}, {222, 13, 122, 255} }},
	{{ {45, -34, 10}, 0, {-16, -16}, {255, 159, 82, 255} }},
	{{ {41, -37, -36}, 0, {-16, -16}, {216, 157, 187, 255} }},
	{{ {25, -1, -44}, 0, {-16, -16}, {224, 227, 137, 255} }},
	{{ {11, 29, -52}, 0, {-16, -16}, {219, 30, 138, 255} }},
	{{ {6, 53, -9}, 0, {-16, -16}, {172, 93, 23, 255} }},
	{{ {26, 16, 28}, 0, {-16, -16}, {222, 13, 122, 255} }},
	{{ {70, 89, -20}, 0, {-16, -16}, {240, 126, 249, 255} }},
	{{ {6, 53, -9}, 0, {-16, -16}, {172, 93, 23, 255} }},
	{{ {77, 41, 21}, 0, {-16, -16}, {20, 40, 119, 255} }},
	{{ {83, -17, 10}, 0, {-16, -16}, {67, 193, 88, 255} }},
	{{ {45, -34, 10}, 0, {-16, -16}, {255, 159, 82, 255} }},
	{{ {89, -47, -37}, 0, {-16, -16}, {75, 164, 212, 255} }},
	{{ {41, -37, -36}, 0, {-16, -16}, {216, 157, 187, 255} }},
	{{ {76, -18, -48}, 0, {-16, -16}, {45, 3, 137, 255} }},
	{{ {25, -1, -44}, 0, {-16, -16}, {224, 227, 137, 255} }},
	{{ {26, 41, -41}, 0, {-16, -16}, {245, 65, 147, 255} }},
	{{ {11, 29, -52}, 0, {-16, -16}, {219, 30, 138, 255} }},
	{{ {78, 59, -34}, 0, {-16, -16}, {246, 22, 131, 255} }},
	{{ {119, 70, -42}, 0, {-16, -16}, {50, 65, 159, 255} }},
	{{ {121, 73, -21}, 0, {-16, -16}, {77, 95, 34, 255} }},
	{{ {141, 34, -7}, 0, {-16, -16}, {116, 248, 52, 255} }},
	{{ {133, 28, -40}, 0, {-16, -16}, {80, 216, 166, 255} }},
	{{ {141, 34, -7}, 0, {-16, -16}, {116, 248, 52, 255} }},
	{{ {83, -17, 10}, 0, {-16, -16}, {67, 193, 88, 255} }},
	{{ {89, -6, -27}, 0, {-16, -16}, {101, 227, 184, 255} }},
	{{ {89, -47, -37}, 0, {-16, -16}, {75, 164, 212, 255} }},
	{{ {76, -18, -48}, 0, {-16, -16}, {45, 3, 137, 255} }},
	{{ {69, 10, -36}, 0, {-16, -16}, {51, 29, 143, 255} }},
	{{ {26, 41, -41}, 0, {-16, -16}, {245, 65, 147, 255} }},
	{{ {78, 59, -34}, 0, {-16, -16}, {246, 22, 131, 255} }},
	{{ {119, 70, -42}, 0, {-16, -16}, {50, 65, 159, 255} }},
	{{ {121, 73, -21}, 0, {-16, -16}, {77, 95, 34, 255} }},
	{{ {2, 3, 26}, 0, {-16, -16}, {168, 240, 90, 255} }},
	{{ {6, -38, 7}, 0, {-16, -16}, {167, 176, 42, 255} }},
	{{ {20, -46, 12}, 0, {-16, -16}, {185, 161, 45, 255} }},
	{{ {-6, -3, 17}, 0, {-16, -16}, {151, 226, 66, 255} }},
	{{ {-20, 22, -7}, 0, {-16, -16}, {131, 0, 22, 255} }},
	{{ {-17, 40, -8}, 0, {-16, -16}, {132, 21, 16, 255} }},
	{{ {-20, 22, -7}, 0, {-16, -16}, {131, 0, 22, 255} }},
	{{ {2, 3, 26}, 0, {-16, -16}, {168, 240, 90, 255} }},
	{{ {-10, 14, -43}, 0, {-16, -16}, {145, 244, 195, 255} }},
	{{ {-15, 4, -32}, 0, {-16, -16}, {141, 222, 214, 255} }},
	{{ {1, -33, -23}, 0, {-16, -16}, {159, 179, 226, 255} }},
	{{ {13, -39, -31}, 0, {-16, -16}, {181, 164, 212, 255} }},
	{{ {6, -38, 7}, 0, {-16, -16}, {167, 176, 42, 255} }},
	{{ {20, -46, 12}, 0, {-16, -16}, {185, 161, 45, 255} }},
	{{ {-6, -3, 17}, 0, {-16, -16}, {151, 226, 66, 255} }},
};

Gfx mario_002_switch_option_right_hand_open_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_002_switch_option_right_hand_open_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(5, 6, 4, 0),
	gsSP1Triangle(7, 6, 5, 0),
	gsSP1Triangle(5, 8, 7, 0),
	gsSP1Triangle(7, 8, 0, 0),
	gsSP1Triangle(0, 9, 7, 0),
	gsSP1Triangle(2, 9, 0, 0),
	gsSP1Triangle(10, 9, 2, 0),
	gsSP1Triangle(2, 11, 10, 0),
	gsSP1Triangle(2, 12, 11, 0),
	gsSP1Triangle(2, 4, 12, 0),
	gsSP1Triangle(4, 13, 12, 0),
	gsSP1Triangle(4, 6, 13, 0),
	gsSP1Triangle(6, 14, 13, 0),
	gsSP1Triangle(14, 6, 7, 0),
	gsSP1Triangle(7, 15, 14, 0),
	gsSP1Triangle(7, 10, 15, 0),
	gsSP1Triangle(7, 9, 10, 0),
	gsSPVertex(mario_002_switch_option_right_hand_open_mesh_layer_1_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 4, 0, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(9, 11, 10, 0),
	gsSP1Triangle(2, 10, 11, 0),
	gsSP1Triangle(10, 2, 1, 0),
	gsSP1Triangle(1, 12, 10, 0),
	gsSP1Triangle(13, 12, 1, 0),
	gsSP1Triangle(1, 14, 13, 0),
	gsSP1Triangle(14, 1, 3, 0),
	gsSP1Triangle(15, 14, 3, 0),
	gsSP1Triangle(4, 15, 3, 0),
	gsSPVertex(mario_002_switch_option_right_hand_open_mesh_layer_1_vtx_0 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(4, 3, 2, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(5, 6, 3, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(7, 8, 6, 0),
	gsSP1Triangle(6, 8, 3, 0),
	gsSP1Triangle(8, 0, 3, 0),
	gsSP1Triangle(8, 9, 0, 0),
	gsSP1Triangle(9, 1, 0, 0),
	gsSP1Triangle(10, 1, 9, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSP1Triangle(11, 14, 12, 0),
	gsSP1Triangle(15, 14, 11, 0),
	gsSPVertex(mario_002_switch_option_right_hand_open_mesh_layer_1_vtx_0 + 48, 10, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(3, 4, 1, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 5, 3, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(5, 7, 9, 0),
	gsSP1Triangle(9, 4, 5, 0),
	gsSP1Triangle(9, 1, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_offset_006_mesh_layer_1_vtx_0[28] = {
	{{ {58, 17, 27}, 0, {-16, -16}, {54, 90, 72, 255} }},
	{{ {67, 10, 21}, 0, {-16, -16}, {111, 50, 37, 255} }},
	{{ {67, 11, -4}, 0, {-16, -16}, {112, 51, 223, 255} }},
	{{ {67, -14, 28}, 0, {-16, -16}, {110, 232, 59, 255} }},
	{{ {57, -17, 37}, 0, {-16, -16}, {50, 216, 110, 255} }},
	{{ {7, 25, 32}, 0, {-16, -16}, {224, 97, 76, 255} }},
	{{ {7, 27, -13}, 0, {-16, -16}, {225, 104, 190, 255} }},
	{{ {58, 19, -9}, 0, {-16, -16}, {55, 96, 194, 255} }},
	{{ {67, -12, -13}, 0, {-16, -16}, {110, 239, 195, 255} }},
	{{ {66, -28, 6}, 0, {-16, -16}, {111, 195, 250, 255} }},
	{{ {57, -38, 6}, 0, {-16, -16}, {51, 140, 250, 255} }},
	{{ {57, -14, -22}, 0, {-16, -16}, {50, 227, 143, 255} }},
	{{ {5, -44, 5}, 0, {-16, -16}, {217, 135, 248, 255} }},
	{{ {6, -19, 44}, 0, {-16, -16}, {220, 214, 114, 255} }},
	{{ {-8, 14, 22}, 0, {-16, -16}, {147, 53, 38, 255} }},
	{{ {-8, 15, -5}, 0, {-16, -16}, {147, 56, 223, 255} }},
	{{ {-9, -10, -15}, 0, {-16, -16}, {144, 246, 196, 255} }},
	{{ {-8, 15, -5}, 0, {-16, -16}, {147, 56, 223, 255} }},
	{{ {7, 27, -13}, 0, {-16, -16}, {225, 104, 190, 255} }},
	{{ {6, -15, -30}, 0, {-16, -16}, {221, 227, 137, 255} }},
	{{ {58, 19, -9}, 0, {-16, -16}, {55, 96, 194, 255} }},
	{{ {57, -14, -22}, 0, {-16, -16}, {50, 227, 143, 255} }},
	{{ {67, -12, -13}, 0, {-16, -16}, {110, 239, 195, 255} }},
	{{ {5, -44, 5}, 0, {-16, -16}, {217, 135, 248, 255} }},
	{{ {-9, -28, 6}, 0, {-16, -16}, {143, 198, 252, 255} }},
	{{ {-9, -13, 30}, 0, {-16, -16}, {145, 238, 60, 255} }},
	{{ {6, -19, 44}, 0, {-16, -16}, {220, 214, 114, 255} }},
	{{ {-8, 14, 22}, 0, {-16, -16}, {147, 53, 38, 255} }},
};

Gfx mario_000_offset_006_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_offset_006_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(4, 0, 5, 0),
	gsSP1Triangle(0, 6, 5, 0),
	gsSP1Triangle(0, 7, 6, 0),
	gsSP1Triangle(0, 2, 7, 0),
	gsSP1Triangle(7, 2, 8, 0),
	gsSP1Triangle(8, 2, 9, 0),
	gsSP1Triangle(2, 3, 9, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(10, 9, 3, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 8, 10, 0),
	gsSP1Triangle(11, 10, 12, 0),
	gsSP1Triangle(10, 13, 12, 0),
	gsSP1Triangle(10, 4, 13, 0),
	gsSP1Triangle(10, 3, 4, 0),
	gsSP1Triangle(4, 5, 13, 0),
	gsSP1Triangle(5, 14, 13, 0),
	gsSP1Triangle(15, 14, 5, 0),
	gsSP1Triangle(6, 15, 5, 0),
	gsSPVertex(mario_000_offset_006_mesh_layer_1_vtx_0 + 16, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(4, 3, 2, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(5, 7, 3, 0),
	gsSP1Triangle(7, 8, 3, 0),
	gsSP1Triangle(9, 8, 7, 0),
	gsSP1Triangle(10, 9, 7, 0),
	gsSP1Triangle(11, 9, 10, 0),
	gsSP1Triangle(9, 11, 1, 0),
	gsSP1Triangle(9, 1, 0, 0),
	gsSP1Triangle(0, 8, 9, 0),
	gsSP1Triangle(8, 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_offset_007_mesh_layer_1_vtx_0[16] = {
	{{ {-2, -18, 38}, 0, {-16, -16}, {220, 214, 114, 255} }},
	{{ {-14, -14, 28}, 0, {-16, -16}, {147, 237, 62, 255} }},
	{{ {-3, -39, 6}, 0, {-16, -16}, {217, 135, 250, 255} }},
	{{ {-13, 10, 21}, 0, {-16, -16}, {148, 54, 41, 255} }},
	{{ {-1, 18, 28}, 0, {-16, -16}, {223, 96, 77, 255} }},
	{{ {47, -17, 34}, 0, {-16, -16}, {65, 218, 103, 255} }},
	{{ {46, -36, 6}, 0, {-16, -16}, {61, 145, 250, 255} }},
	{{ {47, -15, -19}, 0, {-16, -16}, {64, 227, 150, 255} }},
	{{ {-2, -15, -23}, 0, {-16, -16}, {221, 227, 137, 255} }},
	{{ {-14, -28, 6}, 0, {-16, -16}, {145, 194, 250, 255} }},
	{{ {-14, -12, -13}, 0, {-16, -16}, {147, 243, 191, 255} }},
	{{ {-13, 12, -4}, 0, {-16, -16}, {151, 61, 218, 255} }},
	{{ {-1, 20, -9}, 0, {-16, -16}, {225, 104, 190, 255} }},
	{{ {48, 13, 25}, 0, {-16, -16}, {68, 83, 68, 255} }},
	{{ {59, -8, 7}, 0, {-16, -16}, {127, 253, 255, 255} }},
	{{ {48, 15, -7}, 0, {-16, -16}, {67, 91, 197, 255} }},
};

Gfx mario_000_offset_007_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_offset_007_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 4, 0, 0),
	gsSP1Triangle(6, 5, 0, 0),
	gsSP1Triangle(6, 0, 2, 0),
	gsSP1Triangle(7, 6, 2, 0),
	gsSP1Triangle(7, 2, 8, 0),
	gsSP1Triangle(2, 9, 8, 0),
	gsSP1Triangle(1, 9, 2, 0),
	gsSP1Triangle(9, 1, 3, 0),
	gsSP1Triangle(10, 9, 3, 0),
	gsSP1Triangle(10, 3, 11, 0),
	gsSP1Triangle(11, 3, 4, 0),
	gsSP1Triangle(12, 11, 4, 0),
	gsSP1Triangle(13, 12, 4, 0),
	gsSP1Triangle(5, 13, 4, 0),
	gsSP1Triangle(5, 14, 13, 0),
	gsSP1Triangle(6, 14, 5, 0),
	gsSP1Triangle(7, 14, 6, 0),
	gsSP1Triangle(15, 14, 7, 0),
	gsSP1Triangle(15, 7, 8, 0),
	gsSP1Triangle(15, 8, 12, 0),
	gsSP1Triangle(8, 10, 12, 0),
	gsSP1Triangle(9, 10, 8, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(13, 14, 15, 0),
	gsSP1Triangle(13, 15, 12, 0),
	gsSPEndDisplayList(),
};

Vtx mario_000_displaylist_004_mesh_layer_1_vtx_0[36] = {
	{{ {-14, 26, 41}, 0, {-16, -16}, {45, 80, 88, 255} }},
	{{ {13, -38, 41}, 0, {-16, -16}, {88, 230, 88, 255} }},
	{{ {23, -26, 35}, 0, {-16, -16}, {15, 191, 108, 255} }},
	{{ {31, -40, -1}, 0, {-16, -16}, {61, 153, 212, 255} }},
	{{ {24, -57, -4}, 0, {-16, -16}, {117, 211, 237, 255} }},
	{{ {4, -3, -33}, 0, {-16, -16}, {76, 33, 159, 255} }},
	{{ {15, 0, -23}, 0, {-16, -16}, {12, 0, 130, 255} }},
	{{ {-2, 41, -1}, 0, {-16, -16}, {218, 113, 212, 255} }},
	{{ {-19, 47, -4}, 0, {-16, -16}, {45, 117, 236, 255} }},
	{{ {1, 24, 35}, 0, {-16, -16}, {245, 63, 110, 255} }},
	{{ {29, 6, 49}, 0, {-16, -16}, {191, 250, 109, 255} }},
	{{ {75, -33, 66}, 0, {-16, -16}, {24, 178, 98, 255} }},
	{{ {55, -44, -4}, 0, {-16, -16}, {6, 140, 204, 255} }},
	{{ {35, 9, -37}, 0, {-16, -16}, {232, 246, 132, 255} }},
	{{ {10, 60, -4}, 0, {-16, -16}, {177, 88, 210, 255} }},
	{{ {29, 62, 34}, 0, {-16, -16}, {206, 89, 75, 255} }},
	{{ {29, 62, 34}, 0, {-16, -16}, {206, 89, 75, 255} }},
	{{ {29, 6, 49}, 0, {-16, -16}, {191, 250, 109, 255} }},
	{{ {57, 10, 66}, 0, {-16, -16}, {243, 20, 125, 255} }},
	{{ {75, -33, 66}, 0, {-16, -16}, {24, 178, 98, 255} }},
	{{ {96, -8, 52}, 0, {-16, -16}, {104, 250, 73, 255} }},
	{{ {104, -26, 1}, 0, {-16, -16}, {101, 191, 215, 255} }},
	{{ {55, -44, -4}, 0, {-16, -16}, {6, 140, 204, 255} }},
	{{ {35, 9, -37}, 0, {-16, -16}, {232, 246, 132, 255} }},
	{{ {86, 30, -33}, 0, {-16, -16}, {69, 28, 153, 255} }},
	{{ {58, 81, 0}, 0, {-16, -16}, {23, 122, 228, 255} }},
	{{ {10, 60, -4}, 0, {-16, -16}, {177, 88, 210, 255} }},
	{{ {54, 54, 44}, 0, {-16, -16}, {20, 81, 95, 255} }},
	{{ {86, 15, 52}, 0, {-16, -16}, {69, 45, 97, 255} }},
	{{ {97, 39, 24}, 0, {-16, -16}, {108, 61, 28, 255} }},
	{{ {4, -3, -33}, 0, {-16, -16}, {153, 214, 194, 255} }},
	{{ {-16, -12, 6}, 0, {-16, -16}, {139, 208, 247, 255} }},
	{{ {-19, 47, -4}, 0, {-16, -16}, {131, 247, 236, 255} }},
	{{ {24, -57, -4}, 0, {-16, -16}, {160, 175, 237, 255} }},
	{{ {13, -38, 41}, 0, {-16, -16}, {155, 185, 30, 255} }},
	{{ {-14, 26, 41}, 0, {-16, -16}, {134, 235, 30, 255} }},
};

Gfx mario_000_displaylist_004_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_displaylist_004_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 2, 1, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(5, 6, 3, 0),
	gsSP1Triangle(7, 6, 5, 0),
	gsSP1Triangle(5, 8, 7, 0),
	gsSP1Triangle(7, 8, 0, 0),
	gsSP1Triangle(0, 9, 7, 0),
	gsSP1Triangle(2, 9, 0, 0),
	gsSP1Triangle(10, 9, 2, 0),
	gsSP1Triangle(11, 10, 2, 0),
	gsSP1Triangle(12, 11, 2, 0),
	gsSP1Triangle(2, 3, 12, 0),
	gsSP1Triangle(13, 12, 3, 0),
	gsSP1Triangle(3, 6, 13, 0),
	gsSP1Triangle(13, 6, 7, 0),
	gsSP1Triangle(14, 13, 7, 0),
	gsSP1Triangle(14, 7, 9, 0),
	gsSP1Triangle(15, 14, 9, 0),
	gsSP1Triangle(9, 10, 15, 0),
	gsSPVertex(mario_000_displaylist_004_mesh_layer_1_vtx_0 + 16, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 2, 1, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 5, 3, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(7, 8, 5, 0),
	gsSP1Triangle(9, 8, 7, 0),
	gsSP1Triangle(10, 9, 7, 0),
	gsSP1Triangle(9, 10, 0, 0),
	gsSP1Triangle(0, 11, 9, 0),
	gsSP1Triangle(11, 0, 2, 0),
	gsSP1Triangle(12, 11, 2, 0),
	gsSP1Triangle(4, 12, 2, 0),
	gsSP1Triangle(4, 13, 12, 0),
	gsSP1Triangle(5, 13, 4, 0),
	gsSP1Triangle(8, 13, 5, 0),
	gsSP1Triangle(9, 13, 8, 0),
	gsSP1Triangle(11, 13, 9, 0),
	gsSP1Triangle(13, 11, 12, 0),
	gsSPVertex(mario_000_displaylist_004_mesh_layer_1_vtx_0 + 30, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 1, 3, 0),
	gsSP1Triangle(5, 1, 4, 0),
	gsSP1Triangle(2, 1, 5, 0),
	gsSPEndDisplayList(),
};

// 0x04011960 - 0x040119A0
const Gfx mario_face_cap_on_dl[] = {
    gsSPDisplayList(mario_face_part_cap_on_dl),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_face_cap_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_face_back_hair_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x040119A0 - 0x04011A90
const Gfx mario_cap_on_eyes_front[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_front),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011A90 - 0x04011B80
const Gfx mario_cap_on_eyes_half_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_half_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011B80 - 0x04011C70
const Gfx mario_cap_on_eyes_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011C70 - 0x04011D60
const Gfx mario_cap_on_eyes_right[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_right),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011D60 - 0x04011E50
const Gfx mario_cap_on_eyes_left[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_left),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011E50 - 0x04011F40
const Gfx mario_cap_on_eyes_up[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_up),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04011F40 - 0x04012030
const Gfx mario_cap_on_eyes_down[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_down),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04012030 - 0x04012120
const Gfx mario_cap_on_eyes_dead[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_dead),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04012120 - 0x04012160
const Gfx mario_metal_cap_on_shared_dl[] = {
    gsSPDisplayList(mario_m_logo_dl),
    gsSPDisplayList(mario_eyes_cap_on_dl),
    gsSPDisplayList(mario_hair_sideburn_cap_on_dl),
    gsSPDisplayList(mario_mustache_cap_on_dl),
    gsSPDisplayList(mario_face_part_cap_on_dl),
    gsSPDisplayList(mario_face_cap_dl),
    gsSPDisplayList(mario_face_back_hair_cap_on_dl),
    gsSPEndDisplayList(),
};

// Unreferenced light group
UNUSED static const Lights1 mario_lights_unused1 = gdSPDefLights1(
    0x3f, 0x30, 0x1e,
    0xfe, 0xc1, 0x79, 0x28, 0x28, 0x28
);

// Unreferenced light group
UNUSED static const Lights1 mario_lights_unused2 = gdSPDefLights1(
    0x1c, 0x01, 0x00,
    0x73, 0x06, 0x00, 0x28, 0x28, 0x28
);

// 0x04012190
static const Vtx mario_eyes_cap_off_dl_vertex[] = {
    {{{   104,     87,    -69}, 0, {  -160,    898}, {0x30, 0x5c, 0xb7, 0xff}}},
    {{{    97,    103,    -24}, 0, {   256,    970}, {0x40, 0x5a, 0xc3, 0xff}}},
    {{{   144,     83,    -66}, 0, {  -146,    460}, {0x19, 0x5b, 0xad, 0xff}}},
    {{{   153,     33,     95}, 0, {  1362,    296}, {0x05, 0x38, 0x71, 0xff}}},
    {{{   175,     91,     39}, 0, {   842,    112}, {0x01, 0x75, 0x2f, 0xff}}},
    {{{   144,     83,     67}, 0, {  1108,    428}, {0x19, 0x5b, 0x53, 0xff}}},
    {{{   145,    101,      0}, 0, {   480,    446}, {0x13, 0x7d, 0x00, 0xff}}},
    {{{    97,    103,     25}, 0, {   724,    958}, {0x40, 0x5a, 0x3d, 0xff}}},
    {{{   175,     91,    -38}, 0, {   106,    130}, {0xf5, 0x73, 0xcc, 0xff}}},
    {{{   104,     87,     70}, 0, {  1138,    864}, {0x30, 0x5c, 0x49, 0xff}}},
    {{{   153,     33,    -94}, 0, {  -404,    342}, {0xfe, 0x36, 0x8e, 0xff}}},
    {{{   108,    105,      0}, 0, {   488,    854}, {0x69, 0x46, 0x00, 0xff}}},
};

// 0x04012250
static const Vtx mario_hair_sideburn_cap_off_dl_vertex[] = {
    {{{    42,      0,    103}, 0, {   968,   1192}, {0xc3, 0x05, 0x6e, 0xff}}},
    {{{    85,    -23,    111}, 0, {  1238,    518}, {0x04, 0x58, 0x5a, 0xff}}},
    {{{    96,     49,     94}, 0, {   -74,    726}, {0x10, 0x28, 0x77, 0xff}}},
    {{{    44,     44,     97}, 0, {   196,   1366}, {0xda, 0x21, 0x74, 0xff}}},
    {{{   153,     33,     95}, 0, {    22,    -68}, {0x05, 0x38, 0x71, 0xff}}},
    {{{   120,    -11,    111}, 0, {   922,    122}, {0xff, 0x13, 0x7d, 0xff}}},
    {{{    42,      0,   -102}, 0, {   842,   1210}, {0xc3, 0x05, 0x92, 0xff}}},
    {{{    44,     44,    -96}, 0, {   118,   1334}, {0xda, 0x21, 0x8c, 0xff}}},
    {{{    96,     49,    -93}, 0, {   -70,    700}, {0x11, 0x27, 0x89, 0xff}}},
    {{{    85,    -23,   -110}, 0, {  1150,    582}, {0x06, 0x59, 0xa6, 0xff}}},
    {{{   120,    -12,   -109}, 0, {   916,    184}, {0xff, 0x13, 0x83, 0xff}}},
    {{{   153,     33,    -94}, 0, {    90,    -58}, {0xfe, 0x36, 0x8e, 0xff}}},
};

// 0x04012310
static const Vtx mario_mustache_cap_off_dl_vertex_group1[] = {
    {{{    92,     88,    -83}, 0, {   992,    -10}, {0x23, 0x59, 0xad, 0xff}}},
    {{{    77,    108,    -33}, 0, {   360,    296}, {0x0e, 0x16, 0x84, 0xff}}},
    {{{    97,    103,    -24}, 0, {   298,     20}, {0x40, 0x5a, 0xc3, 0xff}}},
    {{{    48,     94,    -75}, 0, {   844,    640}, {0xd7, 0x60, 0xb9, 0xff}}},
    {{{    44,     44,    -96}, 0, {  1272,    592}, {0xda, 0x21, 0x8c, 0xff}}},
    {{{    52,    111,    -30}, 0, {   294,    656}, {0xa8, 0x32, 0xb5, 0xff}}},
    {{{    92,     88,     84}, 0, {   948,     -8}, {0x23, 0x59, 0x53, 0xff}}},
    {{{    77,    108,     34}, 0, {   330,    316}, {0x0e, 0x16, 0x7c, 0xff}}},
    {{{    48,     94,     76}, 0, {   848,    630}, {0xd7, 0x60, 0x47, 0xff}}},
    {{{    97,    103,     25}, 0, {   248,     50}, {0x40, 0x5a, 0x3d, 0xff}}},
    {{{    52,    111,     31}, 0, {   292,    670}, {0xa8, 0x33, 0x4b, 0xff}}},
    {{{    44,     44,     97}, 0, {  1276,    566}, {0xda, 0x21, 0x74, 0xff}}},
    {{{     3,     54,     52}, 0, {   768,   1210}, {0x95, 0x1d, 0x3c, 0xff}}},
    {{{    27,    100,     30}, 0, {   336,   1006}, {0xb1, 0x60, 0x16, 0xff}}},
    {{{     3,     54,    -51}, 0, {   720,   1228}, {0x95, 0x1d, 0xc4, 0xff}}},
    {{{    41,    109,      0}, 0, {   -30,    876}, {0x95, 0x44, 0x00, 0xff}}},
};

// 0x04012410
static const Vtx mario_mustache_cap_off_dl_vertex_group2[] = {
    {{{    41,    109,      0}, 0, {   -38,    852}, {0x95, 0x44, 0x00, 0xff}}},
    {{{    52,    111,    -30}, 0, {   294,    656}, {0xa8, 0x32, 0xb5, 0xff}}},
    {{{    27,    100,    -29}, 0, {   310,   1002}, {0xb1, 0x60, 0xea, 0xff}}},
    {{{    48,     94,    -75}, 0, {   844,    640}, {0xd7, 0x60, 0xb9, 0xff}}},
    {{{     3,     54,    -51}, 0, {   720,   1228}, {0x95, 0x1d, 0xc4, 0xff}}},
};

// 0x04012460
static const Vtx mario_face_part_cap_off_dl_vertex_group1[] = {
    {{{    97,    103,     25}, 0, {     0,      0}, {0x40, 0x5a, 0x3d, 0xff}}},
    {{{   108,    105,      0}, 0, {     0,      0}, {0x69, 0x46, 0x00, 0xff}}},
    {{{   117,    128,      0}, 0, {     0,      0}, {0x7a, 0xe1, 0x06, 0xff}}},
    {{{    92,     88,    -83}, 0, {     0,      0}, {0x23, 0x59, 0xad, 0xff}}},
    {{{    97,    103,    -24}, 0, {     0,      0}, {0x40, 0x5a, 0xc3, 0xff}}},
    {{{   104,     87,    -69}, 0, {     0,      0}, {0x30, 0x5c, 0xb7, 0xff}}},
    {{{    96,     49,    -93}, 0, {     0,      0}, {0x11, 0x27, 0x89, 0xff}}},
    {{{    44,     44,    -96}, 0, {     0,      0}, {0xda, 0x21, 0x8c, 0xff}}},
    {{{   102,    129,    -40}, 0, {     0,      0}, {0x50, 0xdc, 0xa6, 0xff}}},
    {{{    77,    108,    -33}, 0, {     0,      0}, {0x0e, 0x16, 0x84, 0xff}}},
    {{{   144,     83,    -66}, 0, {     0,      0}, {0x19, 0x5b, 0xad, 0xff}}},
    {{{    44,     44,     97}, 0, {     0,      0}, {0xda, 0x21, 0x74, 0xff}}},
    {{{    96,     49,     94}, 0, {     0,      0}, {0x10, 0x28, 0x77, 0xff}}},
    {{{    92,     88,     84}, 0, {     0,      0}, {0x23, 0x59, 0x53, 0xff}}},
    {{{   104,     87,     70}, 0, {     0,      0}, {0x30, 0x5c, 0x49, 0xff}}},
};

// 0x04012550
static const Vtx mario_face_part_cap_off_dl_vertex_group2[] = {
    {{{    -7,     62,      0}, 0, {     0,      0}, {0x85, 0x1d, 0x00, 0xff}}},
    {{{     3,     54,     52}, 0, {     0,      0}, {0x95, 0x1d, 0x3c, 0xff}}},
    {{{    27,    100,     30}, 0, {     0,      0}, {0xb1, 0x60, 0x16, 0xff}}},
    {{{   144,     83,     67}, 0, {     0,      0}, {0x19, 0x5b, 0x53, 0xff}}},
    {{{   104,     87,     70}, 0, {     0,      0}, {0x30, 0x5c, 0x49, 0xff}}},
    {{{    96,     49,     94}, 0, {     0,      0}, {0x10, 0x28, 0x77, 0xff}}},
    {{{   117,    128,      0}, 0, {     0,      0}, {0x7a, 0xe1, 0x06, 0xff}}},
    {{{   102,    129,     41}, 0, {     0,      0}, {0x45, 0xd6, 0x61, 0xff}}},
    {{{    97,    103,     25}, 0, {     0,      0}, {0x40, 0x5a, 0x3d, 0xff}}},
    {{{    77,    108,     34}, 0, {     0,      0}, {0x0e, 0x16, 0x7c, 0xff}}},
    {{{    44,     44,     97}, 0, {     0,      0}, {0xda, 0x21, 0x74, 0xff}}},
    {{{    42,      0,    103}, 0, {     0,      0}, {0xc3, 0x05, 0x6e, 0xff}}},
    {{{    17,    -52,     47}, 0, {     0,      0}, {0x89, 0xf8, 0x29, 0xff}}},
    {{{    64,    -25,    135}, 0, {     0,      0}, {0xcc, 0xe5, 0x70, 0xff}}},
    {{{    56,    -45,     77}, 0, {     0,      0}, {0xe3, 0xca, 0x6e, 0xff}}},
    {{{    85,    -23,    111}, 0, {     0,      0}, {0x04, 0x58, 0x5a, 0xff}}},
};

// 0x04012650
static const Vtx mario_face_part_cap_off_dl_vertex_group3[] = {
    {{{    96,     49,     94}, 0, {     0,      0}, {0x10, 0x28, 0x77, 0xff}}},
    {{{   153,     33,     95}, 0, {     0,      0}, {0x05, 0x38, 0x71, 0xff}}},
    {{{   144,     83,     67}, 0, {     0,      0}, {0x19, 0x5b, 0x53, 0xff}}},
    {{{    64,    -25,    135}, 0, {     0,      0}, {0xcc, 0xe5, 0x70, 0xff}}},
    {{{    91,    -54,     86}, 0, {     0,      0}, {0xe9, 0xa9, 0x59, 0xff}}},
    {{{   102,    -33,    135}, 0, {     0,      0}, {0x30, 0x18, 0x72, 0xff}}},
    {{{    56,    -45,     77}, 0, {     0,      0}, {0xe3, 0xca, 0x6e, 0xff}}},
    {{{    85,    -23,    111}, 0, {     0,      0}, {0x04, 0x58, 0x5a, 0xff}}},
    {{{   120,    -11,    111}, 0, {     0,      0}, {0xff, 0x13, 0x7d, 0xff}}},
    {{{    52,    111,    -30}, 0, {     0,      0}, {0xa8, 0x32, 0xb5, 0xff}}},
    {{{    41,    109,      0}, 0, {     0,      0}, {0x95, 0x44, 0x00, 0xff}}},
    {{{    32,    132,      0}, 0, {     0,      0}, {0x84, 0xe8, 0xf8, 0xff}}},
    {{{    85,    -23,   -110}, 0, {     0,      0}, {0x06, 0x59, 0xa6, 0xff}}},
    {{{    64,    -25,   -134}, 0, {     0,      0}, {0xcc, 0xe5, 0x90, 0xff}}},
    {{{    42,      0,   -102}, 0, {     0,      0}, {0xc3, 0x05, 0x92, 0xff}}},
};

// 0x04012740
static const Vtx mario_face_part_cap_off_dl_vertex_group4[] = {
    {{{    27,    100,     30}, 0, {     0,      0}, {0xb1, 0x60, 0x16, 0xff}}},
    {{{    27,    100,    -29}, 0, {     0,      0}, {0xb1, 0x60, 0xea, 0xff}}},
    {{{    -7,     62,      0}, 0, {     0,      0}, {0x85, 0x1d, 0x00, 0xff}}},
    {{{     3,     54,    -51}, 0, {     0,      0}, {0x95, 0x1d, 0xc4, 0xff}}},
    {{{    41,    109,      0}, 0, {     0,      0}, {0x95, 0x44, 0x00, 0xff}}},
    {{{   144,     83,    -66}, 0, {     0,      0}, {0x19, 0x5b, 0xad, 0xff}}},
    {{{   153,     33,    -94}, 0, {     0,      0}, {0xfe, 0x36, 0x8e, 0xff}}},
    {{{    96,     49,    -93}, 0, {     0,      0}, {0x11, 0x27, 0x89, 0xff}}},
    {{{    42,      0,   -102}, 0, {     0,      0}, {0xc3, 0x05, 0x92, 0xff}}},
    {{{    44,     44,    -96}, 0, {     0,      0}, {0xda, 0x21, 0x8c, 0xff}}},
    {{{    64,    -25,   -134}, 0, {     0,      0}, {0xcc, 0xe5, 0x90, 0xff}}},
    {{{   102,    -33,   -134}, 0, {     0,      0}, {0x32, 0x19, 0x8f, 0xff}}},
    {{{    91,    -54,    -85}, 0, {     0,      0}, {0xe8, 0xaa, 0xa7, 0xff}}},
    {{{    85,    -23,   -110}, 0, {     0,      0}, {0x06, 0x59, 0xa6, 0xff}}},
    {{{   120,    -12,   -109}, 0, {     0,      0}, {0xff, 0x13, 0x83, 0xff}}},
};

// 0x04012830
static const Vtx mario_face_part_cap_off_dl_vertex_group5[] = {
    {{{    33,    165,      0}, 0, {     0,      0}, {0x8f, 0x38, 0x09, 0xff}}},
    {{{    60,    181,      0}, 0, {     0,      0}, {0xea, 0x7c, 0x00, 0xff}}},
    {{{    52,    164,    -40}, 0, {     0,      0}, {0xb8, 0x34, 0xa6, 0xff}}},
    {{{   102,    -33,   -134}, 0, {     0,      0}, {0x32, 0x19, 0x8f, 0xff}}},
    {{{   120,    -12,   -109}, 0, {     0,      0}, {0xff, 0x13, 0x83, 0xff}}},
    {{{    91,    -54,    -85}, 0, {     0,      0}, {0xe8, 0xaa, 0xa7, 0xff}}},
    {{{    56,    -45,    -76}, 0, {     0,      0}, {0xe3, 0xca, 0x92, 0xff}}},
    {{{    64,    -25,   -134}, 0, {     0,      0}, {0xcc, 0xe5, 0x90, 0xff}}},
    {{{    42,      0,   -102}, 0, {     0,      0}, {0xc3, 0x05, 0x92, 0xff}}},
    {{{    17,    -52,    -46}, 0, {     0,      0}, {0x89, 0xf8, 0xd7, 0xff}}},
    {{{     3,     54,    -51}, 0, {     0,      0}, {0x95, 0x1d, 0xc4, 0xff}}},
    {{{    -7,     62,      0}, 0, {     0,      0}, {0x85, 0x1d, 0x00, 0xff}}},
    {{{    17,    -52,     47}, 0, {     0,      0}, {0x89, 0xf8, 0x29, 0xff}}},
    {{{    52,    164,     41}, 0, {     0,      0}, {0xc8, 0x3d, 0x5f, 0xff}}},
    {{{    78,    163,     46}, 0, {     0,      0}, {0x03, 0x55, 0x5d, 0xff}}},
    {{{   101,    179,      0}, 0, {     0,      0}, {0x27, 0x78, 0x00, 0xff}}},
};

// 0x04012930
static const Vtx mario_face_part_cap_off_dl_vertex_group6[] = {
    {{{   104,    162,     41}, 0, {     0,      0}, {0x52, 0x27, 0x58, 0xff}}},
    {{{   101,    179,      0}, 0, {     0,      0}, {0x27, 0x78, 0x00, 0xff}}},
    {{{    78,    163,     46}, 0, {     0,      0}, {0x03, 0x55, 0x5d, 0xff}}},
    {{{    52,    164,     41}, 0, {     0,      0}, {0xc8, 0x3d, 0x5f, 0xff}}},
    {{{    75,    130,     46}, 0, {     0,      0}, {0x00, 0xec, 0x7d, 0xff}}},
    {{{   119,    161,      0}, 0, {     0,      0}, {0x79, 0x23, 0xf6, 0xff}}},
    {{{   104,    162,    -40}, 0, {     0,      0}, {0x44, 0x31, 0xa1, 0xff}}},
    {{{    78,    163,    -45}, 0, {     0,      0}, {0x03, 0x54, 0xa2, 0xff}}},
    {{{    60,    181,      0}, 0, {     0,      0}, {0xea, 0x7c, 0x00, 0xff}}},
    {{{    47,    131,     41}, 0, {     0,      0}, {0xb0, 0xe4, 0x5e, 0xff}}},
    {{{    33,    165,      0}, 0, {     0,      0}, {0x8f, 0x38, 0x09, 0xff}}},
    {{{   102,    129,     41}, 0, {     0,      0}, {0x45, 0xd6, 0x61, 0xff}}},
    {{{    77,    108,     34}, 0, {     0,      0}, {0x0e, 0x16, 0x7c, 0xff}}},
    {{{    52,    164,    -40}, 0, {     0,      0}, {0xb8, 0x34, 0xa6, 0xff}}},
    {{{    32,    132,      0}, 0, {     0,      0}, {0x84, 0xe8, 0xf8, 0xff}}},
    {{{   117,    128,      0}, 0, {     0,      0}, {0x7a, 0xe1, 0x06, 0xff}}},
};

// 0x04012A30
static const Vtx mario_face_part_cap_off_dl_vertex_group7[] = {
    {{{    52,    111,     31}, 0, {     0,      0}, {0xa8, 0x33, 0x4b, 0xff}}},
    {{{    47,    131,     41}, 0, {     0,      0}, {0xb0, 0xe4, 0x5e, 0xff}}},
    {{{    32,    132,      0}, 0, {     0,      0}, {0x84, 0xe8, 0xf8, 0xff}}},
    {{{    77,    108,     34}, 0, {     0,      0}, {0x0e, 0x16, 0x7c, 0xff}}},
    {{{    52,    164,    -40}, 0, {     0,      0}, {0xb8, 0x34, 0xa6, 0xff}}},
    {{{    78,    163,    -45}, 0, {     0,      0}, {0x03, 0x54, 0xa2, 0xff}}},
    {{{    75,    130,    -45}, 0, {     0,      0}, {0x00, 0xec, 0x83, 0xff}}},
    {{{   104,    162,    -40}, 0, {     0,      0}, {0x44, 0x31, 0xa1, 0xff}}},
    {{{    60,    181,      0}, 0, {     0,      0}, {0xea, 0x7c, 0x00, 0xff}}},
    {{{    17,    -52,    -46}, 0, {     0,      0}, {0x89, 0xf8, 0xd7, 0xff}}},
    {{{    31,    -84,      0}, 0, {     0,      0}, {0xa0, 0xae, 0x00, 0xff}}},
    {{{    17,    -52,     47}, 0, {     0,      0}, {0x89, 0xf8, 0x29, 0xff}}},
    {{{    41,    109,      0}, 0, {     0,      0}, {0x95, 0x44, 0x00, 0xff}}},
    {{{    47,    131,    -40}, 0, {     0,      0}, {0xbc, 0xde, 0x9c, 0xff}}},
    {{{   102,    129,    -40}, 0, {     0,      0}, {0x50, 0xdc, 0xa6, 0xff}}},
    {{{    77,    108,    -33}, 0, {     0,      0}, {0x0e, 0x16, 0x84, 0xff}}},
};

Gfx mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_tri_1[] = {
	gsSPVertex(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(3, 6, 5, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(6, 8, 7, 0),
	gsSP1Triangle(7, 8, 0, 0),
	gsSP1Triangle(0, 9, 7, 0),
	gsSP1Triangle(2, 9, 0, 0),
	gsSP1Triangle(10, 9, 2, 0),
	gsSP1Triangle(11, 10, 2, 0),
	gsSP1Triangle(11, 2, 4, 0),
	gsSP1Triangle(12, 11, 4, 0),
	gsSP1Triangle(4, 13, 12, 0),
	gsSP1Triangle(13, 4, 5, 0),
	gsSP1Triangle(14, 13, 5, 0),
	gsSP1Triangle(15, 14, 5, 0),
	gsSP1Triangle(5, 7, 15, 0),
	gsSP1Triangle(10, 15, 7, 0),
	gsSP1Triangle(7, 9, 10, 0),
	gsSPVertex(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_vtx_1 + 16, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 4, 0, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(6, 7, 4, 0),
	gsSP1Triangle(7, 6, 8, 0),
	gsSP1Triangle(6, 9, 8, 0),
	gsSP1Triangle(10, 8, 9, 0),
	gsSP1Triangle(10, 11, 8, 0),
	gsSP1Triangle(1, 11, 10, 0),
	gsSP1Triangle(2, 1, 10, 0),
	gsSP1Triangle(1, 12, 11, 0),
	gsSP1Triangle(3, 12, 1, 0),
	gsSP1Triangle(4, 12, 3, 0),
	gsSP1Triangle(7, 12, 4, 0),
	gsSP1Triangle(12, 7, 13, 0),
	gsSP1Triangle(13, 7, 8, 0),
	gsSP1Triangle(11, 13, 8, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSPVertex(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_vtx_1 + 30, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 1, 3, 0),
	gsSP1Triangle(5, 1, 4, 0),
	gsSP1Triangle(2, 1, 5, 0),
	gsSPEndDisplayList(),
};

Vtx mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_vtx_0[8] = {
	{{ {178, -177, 128}, 0, {-16, 4008}, {168, 179, 207, 255} }},
	{{ {319, -248, -14}, 0, {-16, -16}, {168, 179, 207, 255} }},
	{{ {349, -325, 53}, 0, {974, -16}, {168, 179, 207, 255} }},
	{{ {207, -253, 195}, 0, {974, 4008}, {168, 179, 207, 255} }},
	{{ {414, 206, 82}, 0, {974, -16}, {189, 101, 217, 255} }},
	{{ {368, 146, 7}, 0, {-16, -16}, {189, 101, 217, 255} }},
	{{ {212, 96, 143}, 0, {-16, 4008}, {189, 101, 217, 255} }},
	{{ {258, 156, 218}, 0, {974, 4008}, {189, 101, 217, 255} }},
};

Gfx mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_tri_0[] = {
	gsSPVertex(mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_vtx_1[8] = {
	{{ {368, 146, 7}, 0, {974, -16}, {189, 101, 217, 255} }},
	{{ {166, 37, 68}, 0, {-16, 4008}, {190, 101, 217, 255} }},
	{{ {212, 96, 143}, 0, {974, 4008}, {189, 101, 217, 255} }},
	{{ {322, 87, -67}, 0, {-16, -16}, {190, 101, 217, 255} }},
	{{ {178, -177, 128}, 0, {974, 4008}, {168, 179, 207, 255} }},
	{{ {149, -100, 60}, 0, {-16, 4008}, {167, 179, 207, 255} }},
	{{ {319, -248, -14}, 0, {974, -16}, {168, 179, 207, 255} }},
	{{ {290, -171, -81}, 0, {-16, -16}, {168, 179, 206, 255} }},
};

Gfx mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_tri_1[] = {
	gsSPVertex(mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_vtx_1 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSPEndDisplayList(),
};

// 0x040139C0 - 0x040139E8
const Gfx mario_face_cap_off_dl[] = {
    gsSPDisplayList(mario_face_part_cap_off_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_face_hair_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x040139E8 - 0x04013AB8
const Gfx mario_cap_off_eyes_front[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_front),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013AB8 - 0x04013B88
const Gfx mario_cap_off_eyes_half_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_half_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013B88 - 0x04013C58
const Gfx mario_cap_off_eyes_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013C58 - 0x04013D28
const Gfx mario_cap_off_eyes_right[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_right),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013D28 - 0x04013DF8
const Gfx mario_cap_off_eyes_left[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_left),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013DF8 - 0x04013EC8
const Gfx mario_cap_off_eyes_up[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_up),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013EC8 - 0x04013F98
const Gfx mario_cap_off_eyes_down[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_down),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04013F98 - 0x04014068
const Gfx mario_cap_off_eyes_dead[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_dead),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_hair_sideburn),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04014068 - 0x04014098
const Gfx mario_metal_cap_off_shared_dl[] = {
    gsSPDisplayList(mario_eyes_cap_off_dl),
    gsSPDisplayList(mario_mustache_cap_off_dl),
    gsSPDisplayList(mario_hair_sideburn_cap_off_dl),
    gsSPDisplayList(mario_face_part_cap_off_dl),
    gsSPDisplayList(mario_face_hair_cap_off_dl),
    gsSPEndDisplayList(),
};

Vtx mario_000_displaylist_005_mesh_layer_1_vtx_0[28] = {
	{{ {75, 23, 40}, 0, {-16, -16}, {42, 120, 0, 255} }},
	{{ {109, 11, 20}, 0, {-16, -16}, {43, 120, 0, 255} }},
	{{ {110, 11, -36}, 0, {-16, -16}, {41, 120, 0, 255} }},
	{{ {78, 22, -61}, 0, {-16, -16}, {41, 120, 0, 255} }},
	{{ {-14, 54, 29}, 0, {-16, -16}, {42, 120, 0, 255} }},
	{{ {-11, 53, -56}, 0, {-16, -16}, {42, 120, 0, 255} }},
	{{ {-40, 63, 5}, 0, {-16, -16}, {42, 120, 0, 255} }},
	{{ {-42, 64, -29}, 0, {-16, -16}, {43, 120, 0, 255} }},
	{{ {110, 11, -36}, 0, {-16, -16}, {80, 172, 203, 255} }},
	{{ {109, 11, 20}, 0, {-16, -16}, {74, 172, 61, 255} }},
	{{ {80, -29, -7}, 0, {-16, -16}, {56, 142, 9, 255} }},
	{{ {44, -11, 32}, 0, {-16, -16}, {253, 183, 104, 255} }},
	{{ {75, 23, 40}, 0, {-16, -16}, {17, 212, 118, 255} }},
	{{ {-14, 54, 29}, 0, {-16, -16}, {206, 0, 117, 255} }},
	{{ {-36, 11, 19}, 0, {-16, -16}, {180, 205, 88, 255} }},
	{{ {-40, 63, 5}, 0, {-16, -16}, {144, 24, 56, 255} }},
	{{ {-54, 14, -10}, 0, {-16, -16}, {138, 210, 3, 255} }},
	{{ {-36, 11, 19}, 0, {-16, -16}, {180, 205, 88, 255} }},
	{{ {-40, 63, 5}, 0, {-16, -16}, {144, 24, 56, 255} }},
	{{ {-42, 64, -29}, 0, {-16, -16}, {141, 22, 206, 255} }},
	{{ {-34, 11, -46}, 0, {-16, -16}, {179, 205, 168, 255} }},
	{{ {-11, 53, -56}, 0, {-16, -16}, {210, 0, 138, 255} }},
	{{ {43, -18, -55}, 0, {-16, -16}, {2, 175, 158, 255} }},
	{{ {78, 22, -61}, 0, {-16, -16}, {30, 212, 141, 255} }},
	{{ {110, 11, -36}, 0, {-16, -16}, {80, 172, 203, 255} }},
	{{ {80, -29, -7}, 0, {-16, -16}, {56, 142, 9, 255} }},
	{{ {27, -35, -11}, 0, {-16, -16}, {231, 132, 6, 255} }},
	{{ {44, -11, 32}, 0, {-16, -16}, {253, 183, 104, 255} }},
};

Gfx mario_000_displaylist_005_mesh_layer_1_tri_0[] = {
	gsSPVertex(mario_000_displaylist_005_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(7, 6, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 10, 9, 0),
	gsSP1Triangle(9, 12, 11, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(13, 14, 11, 0),
	gsSP1Triangle(14, 13, 15, 0),
	gsSPVertex(mario_000_displaylist_005_mesh_layer_1_vtx_0 + 16, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSP1Triangle(5, 6, 4, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(8, 9, 6, 0),
	gsSP1Triangle(10, 6, 9, 0),
	gsSP1Triangle(9, 11, 10, 0),
	gsSP1Triangle(10, 11, 1, 0),
	gsSP1Triangle(10, 1, 0, 0),
	gsSP1Triangle(0, 4, 10, 0),
	gsSP1Triangle(4, 6, 10, 0),
	gsSPEndDisplayList(),
};

// 0x04014638 - 0x04014668
const Gfx mario_medium_poly_butt[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_butt_dl),
    gsSPEndDisplayList(),
};

// 0x04014668 - 0x040146E0
const Gfx mario_metal_medium_poly_butt[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_butt_dl),
    gsSPEndDisplayList(),
};

// 0x040146E0
static const Vtx mario_medium_poly_left_arm_shared_dl_vertex[] = {
    {{{    -6,    -32,    -22}, 0, {     0,      0}, {0x08, 0x84, 0x18, 0x00}}},
    {{{    60,    -27,    -18}, 0, {     0,      0}, {0x3d, 0xc5, 0xa3, 0x00}}},
    {{{    60,    -18,     26}, 0, {     0,      0}, {0x5c, 0xbe, 0x36, 0x00}}},
    {{{    -6,    -32,    -22}, 0, {     0,      0}, {0x07, 0xf5, 0x82, 0x00}}},
    {{{    -7,     21,    -27}, 0, {     0,      0}, {0x07, 0xf5, 0x82, 0x00}}},
    {{{    59,     16,    -22}, 0, {     0,      0}, {0x5b, 0x4f, 0xda, 0x00}}},
    {{{    -7,     20,     18}, 0, {     0,      0}, {0x0c, 0x73, 0x32, 0x00}}},
    {{{    59,     14,     14}, 0, {     0,      0}, {0x38, 0x4b, 0x55, 0x00}}},
    {{{    -6,    -21,     33}, 0, {     0,      0}, {0x0b, 0x2a, 0x77, 0x00}}},
    {{{    -7,     21,    -27}, 0, {     0,      0}, {0x0a, 0x7e, 0x04, 0x00}}},
    {{{    -6,    -21,     33}, 0, {     0,      0}, {0x08, 0x84, 0x18, 0x00}}},
    {{{    -7,     21,    -27}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -6,    -32,    -22}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -6,    -21,     33}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -7,     20,     18}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
};

// 0x040147D0 - 0x04014840
const Gfx mario_medium_poly_left_arm_shared_dl[] = {
    gsSPVertex(mario_medium_poly_left_arm_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 4,  5,  1, 0x0,  6,  7,  5, 0x0),
    gsSP2Triangles( 8,  2,  7, 0x0,  6,  8,  7, 0x0),
    gsSP2Triangles( 9,  6,  5, 0x0, 10,  0,  2, 0x0),
    gsSP2Triangles( 5,  2,  1, 0x0, 11, 12, 13, 0x0),
    gsSP2Triangles(13, 14, 11, 0x0,  5,  7,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x04014840 - 0x04014860
const Gfx mario_medium_poly_left_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_left_arm_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04014860
static const Vtx mario_medium_poly_left_forearm_shared_dl_vertex[] = {
    {{{    -9,    -29,    -18}, 0, {     0,      0}, {0x05, 0x84, 0x19, 0x00}}},
    {{{    53,    -26,    -17}, 0, {     0,      0}, {0x59, 0xd0, 0xb5, 0x00}}},
    {{{    53,    -17,     24}, 0, {     0,      0}, {0x3d, 0xab, 0x47, 0x00}}},
    {{{    -9,    -29,    -18}, 0, {     0,      0}, {0x04, 0xf3, 0x82, 0x00}}},
    {{{    -9,     16,    -24}, 0, {     0,      0}, {0x04, 0xf4, 0x82, 0x00}}},
    {{{    53,     13,    -21}, 0, {     0,      0}, {0x3b, 0x64, 0xce, 0x00}}},
    {{{    -9,     15,     15}, 0, {     0,      0}, {0x07, 0x75, 0x30, 0x00}}},
    {{{    53,     13,     12}, 0, {     0,      0}, {0x52, 0x41, 0x47, 0x00}}},
    {{{    -9,    -19,     28}, 0, {     0,      0}, {0x07, 0x2c, 0x76, 0x00}}},
    {{{    -9,     16,    -24}, 0, {     0,      0}, {0x06, 0x7e, 0x02, 0x00}}},
    {{{    -9,    -19,     28}, 0, {     0,      0}, {0x05, 0x84, 0x1a, 0x00}}},
    {{{    -9,     16,    -24}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -9,    -29,    -18}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -9,    -19,     28}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -9,     15,     15}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
};

// 0x04014950 - 0x040149C0
const Gfx mario_medium_poly_left_forearm_shared_dl[] = {
    gsSPVertex(mario_medium_poly_left_forearm_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 4,  5,  1, 0x0,  6,  7,  5, 0x0),
    gsSP2Triangles( 8,  2,  7, 0x0,  6,  8,  7, 0x0),
    gsSP2Triangles( 9,  6,  5, 0x0, 10,  0,  2, 0x0),
    gsSP2Triangles( 1,  7,  2, 0x0,  1,  5,  7, 0x0),
    gsSP2Triangles(11, 12, 13, 0x0, 13, 14, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x040149C0
static const Vtx mario_medium_poly_left_hand_closed_shared_dl_vertex_group1[] = {
    {{{    31,     10,     40}, 0, {     0,      0}, {0xd8, 0xed, 0x76, 0x00}}},
    {{{    12,      1,     26}, 0, {     0,      0}, {0xf1, 0xf7, 0x7d, 0x00}}},
    {{{    27,    -32,     -3}, 0, {     0,      0}, {0x06, 0x82, 0x0b, 0x00}}},
    {{{    11,      2,    -28}, 0, {     0,      0}, {0xca, 0xf6, 0x8e, 0x00}}},
    {{{    44,    -22,    -46}, 0, {     0,      0}, {0xde, 0xb9, 0x9d, 0x00}}},
    {{{    18,     37,    -31}, 0, {     0,      0}, {0xc7, 0x28, 0x97, 0x00}}},
    {{{    -2,     36,     -2}, 0, {     0,      0}, {0xb0, 0x61, 0x03, 0x00}}},
    {{{    -5,     -5,     34}, 0, {     0,      0}, {0x2f, 0x13, 0x74, 0x00}}},
    {{{    -6,     -5,    -32}, 0, {     0,      0}, {0x1c, 0x0e, 0x86, 0x00}}},
    {{{    81,     32,     40}, 0, {     0,      0}, {0x48, 0x1f, 0x63, 0x00}}},
    {{{    55,     84,      9}, 0, {     0,      0}, {0x14, 0x74, 0x2c, 0x00}}},
    {{{   102,    -23,      6}, 0, {     0,      0}, {0x64, 0xc4, 0x31, 0x00}}},
    {{{    95,     43,    -12}, 0, {     0,      0}, {0x6e, 0x36, 0xe0, 0x00}}},
    {{{    54,     58,    -32}, 0, {     0,      0}, {0x02, 0x4e, 0x9d, 0x00}}},
    {{{    84,    -10,    -41}, 0, {     0,      0}, {0x39, 0xe2, 0x93, 0x00}}},
    {{{    53,    -42,      9}, 0, {     0,      0}, {0x04, 0x83, 0x0f, 0x00}}},
};

// 0x04014AC0
static const Vtx mario_medium_poly_left_hand_closed_shared_dl_vertex_group2[] = {
    {{{    31,     10,     40}, 0, {     0,      0}, {0xd8, 0xed, 0x76, 0x00}}},
    {{{    55,     84,      9}, 0, {     0,      0}, {0x14, 0x74, 0x2c, 0x00}}},
    {{{     7,     62,     10}, 0, {     0,      0}, {0xa7, 0x5a, 0x00, 0x00}}},
    {{{    27,    -32,     -3}, 0, {     0,      0}, {0x06, 0x82, 0x0b, 0x00}}},
    {{{    14,    -51,     -2}, 0, {     0,      0}, {0x37, 0xd5, 0x97, 0x00}}},
    {{{    -6,     -5,    -32}, 0, {     0,      0}, {0x1c, 0x0e, 0x86, 0x00}}},
    {{{   -26,     40,     -1}, 0, {     0,      0}, {0x05, 0x48, 0x98, 0x00}}},
    {{{    -2,     36,     -2}, 0, {     0,      0}, {0xb0, 0x61, 0x03, 0x00}}},
    {{{   -26,     40,     -1}, 0, {     0,      0}, {0x11, 0x50, 0x60, 0x00}}},
    {{{    -5,     -5,     34}, 0, {     0,      0}, {0x2f, 0x13, 0x74, 0x00}}},
    {{{    14,    -51,     -2}, 0, {     0,      0}, {0x49, 0xd5, 0x5e, 0x00}}},
    {{{    18,     37,    -31}, 0, {     0,      0}, {0xc7, 0x28, 0x97, 0x00}}},
    {{{    44,    -22,    -46}, 0, {     0,      0}, {0xde, 0xb9, 0x9d, 0x00}}},
    {{{    53,    -42,      9}, 0, {     0,      0}, {0x04, 0x83, 0x0f, 0x00}}},
    {{{    54,     58,    -32}, 0, {     0,      0}, {0x02, 0x4e, 0x9d, 0x00}}},
};

// 0x04014BB0
static const Vtx mario_medium_poly_left_hand_closed_shared_dl_vertex_group3[] = {
    {{{    54,     58,    -32}, 0, {     0,      0}, {0x02, 0x4e, 0x9d, 0x00}}},
    {{{    95,     43,    -12}, 0, {     0,      0}, {0x6e, 0x36, 0xe0, 0x00}}},
    {{{    84,    -10,    -41}, 0, {     0,      0}, {0x39, 0xe2, 0x93, 0x00}}},
    {{{     7,     62,     10}, 0, {     0,      0}, {0xa7, 0x5a, 0x00, 0x00}}},
    {{{    55,     84,      9}, 0, {     0,      0}, {0x14, 0x74, 0x2c, 0x00}}},
    {{{    53,    -42,      9}, 0, {     0,      0}, {0x04, 0x83, 0x0f, 0x00}}},
    {{{   102,    -23,      6}, 0, {     0,      0}, {0x64, 0xc4, 0x31, 0x00}}},
    {{{    18,     37,    -31}, 0, {     0,      0}, {0xc7, 0x28, 0x97, 0x00}}},
    {{{    44,    -22,    -46}, 0, {     0,      0}, {0xde, 0xb9, 0x9d, 0x00}}},
    {{{    11,      2,    -28}, 0, {     0,      0}, {0xca, 0xf6, 0x8e, 0x00}}},
    {{{    -5,     -5,     34}, 0, {     0,      0}, {0x8c, 0xce, 0x01, 0x00}}},
    {{{    -6,     -5,    -32}, 0, {     0,      0}, {0x8c, 0xce, 0x01, 0x00}}},
    {{{    14,    -51,     -2}, 0, {     0,      0}, {0x8c, 0xce, 0x01, 0x00}}},
    {{{   -26,     40,     -1}, 0, {     0,      0}, {0x8c, 0xce, 0x01, 0x00}}},
};

// 0x04014C90 - 0x04014DC0
const Gfx mario_medium_poly_left_hand_closed_shared_dl[] = {
    gsSPVertex(mario_medium_poly_left_hand_closed_shared_dl_vertex_group1, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  4, 0x0),
    gsSP2Triangles( 5,  3,  6, 0x0,  6,  1,  0, 0x0),
    gsSP2Triangles( 2,  1,  7, 0x0,  7,  1,  6, 0x0),
    gsSP2Triangles( 6,  3,  8, 0x0,  3,  2,  8, 0x0),
    gsSP2Triangles( 0,  9, 10, 0x0, 11,  9,  0, 0x0),
    gsSP2Triangles(10, 12, 13, 0x0, 14, 12, 11, 0x0),
    gsSP2Triangles(11, 12,  9, 0x0,  9, 12, 10, 0x0),
    gsSP1Triangle(15, 11,  0, 0x0),
    gsSPVertex(mario_medium_poly_left_hand_closed_shared_dl_vertex_group2, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 5,  6,  7, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 9, 10,  3, 0x0,  7,  0,  2, 0x0),
    gsSP2Triangles( 7,  2, 11, 0x0,  3, 12, 13, 0x0),
    gsSP2Triangles( 3, 13,  0, 0x0, 11,  2, 14, 0x0),
    gsSPVertex(mario_medium_poly_left_hand_closed_shared_dl_vertex_group3, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  0, 0x0),
    gsSP2Triangles( 5,  2,  6, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 7,  2,  8, 0x0,  7,  0,  2, 0x0),
    gsSP2Triangles( 5,  8,  2, 0x0, 10, 11, 12, 0x0),
    gsSP1Triangle(10, 13, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x04014DC0 - 0x04014DE0
const Gfx mario_medium_poly_left_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_left_hand_closed_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04014DE0
static const Vtx mario_medium_poly_right_arm_shared_dl_vertex[] = {
    {{{    60,    -28,     22}, 0, {     0,      0}, {0x3b, 0xc7, 0x60, 0x00}}},
    {{{    60,    -19,    -19}, 0, {     0,      0}, {0x5a, 0xbc, 0xc7, 0x00}}},
    {{{    60,     14,     24}, 0, {     0,      0}, {0x5b, 0x4f, 0x26, 0x00}}},
    {{{    -7,    -31,     24}, 0, {     0,      0}, {0x04, 0x84, 0xe6, 0x00}}},
    {{{    -7,    -20,    -27}, 0, {     0,      0}, {0x04, 0x84, 0xe6, 0x00}}},
    {{{    -8,     21,    -15}, 0, {     0,      0}, {0x11, 0x73, 0xce, 0x00}}},
    {{{    -8,     22,     27}, 0, {     0,      0}, {0x0e, 0x7e, 0xfd, 0x00}}},
    {{{    60,     13,     -9}, 0, {     0,      0}, {0x3c, 0x46, 0xaa, 0x00}}},
    {{{    -7,    -20,    -27}, 0, {     0,      0}, {0x0e, 0x23, 0x88, 0x00}}},
    {{{    -8,     22,     27}, 0, {     0,      0}, {0x03, 0xfa, 0x7e, 0x00}}},
    {{{    -7,    -31,     24}, 0, {     0,      0}, {0x03, 0xfa, 0x7e, 0x00}}},
    {{{    -7,    -20,    -27}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -7,    -31,     24}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -8,     22,     27}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{    -8,     21,    -15}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
};

// 0x04014ED0 - 0x04014F40
const Gfx mario_medium_poly_right_arm_shared_dl[] = {
    gsSPVertex(mario_medium_poly_right_arm_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  4, 0x0),
    gsSP2Triangles( 2,  5,  6, 0x0,  7,  8,  5, 0x0),
    gsSP2Triangles( 7,  1,  8, 0x0,  2,  7,  5, 0x0),
    gsSP2Triangles( 0,  2,  9, 0x0,  0,  9, 10, 0x0),
    gsSP2Triangles( 1,  0,  3, 0x0, 11, 12, 13, 0x0),
    gsSP2Triangles(13, 14, 11, 0x0,  1,  7,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x04014F40 - 0x04014F60
const Gfx mario_medium_poly_right_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_right_arm_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04014F60
static const Vtx mario_medium_poly_right_forearm_shared_dl_vertex[] = {
    {{{    -5,    -18,    -24}, 0, {     0,      0}, {0x81, 0xfe, 0x03, 0x00}}},
    {{{    -3,    -29,     21}, 0, {     0,      0}, {0x81, 0xfe, 0x03, 0x00}}},
    {{{    -4,     17,     26}, 0, {     0,      0}, {0x81, 0xfe, 0x03, 0x00}}},
    {{{    52,     13,    -10}, 0, {     0,      0}, {0x51, 0x40, 0xb7, 0x00}}},
    {{{    53,     13,     22}, 0, {     0,      0}, {0x3d, 0x63, 0x31, 0x00}}},
    {{{    53,    -26,     19}, 0, {     0,      0}, {0x5b, 0xd0, 0x49, 0x00}}},
    {{{    52,    -17,    -21}, 0, {     0,      0}, {0x3a, 0xac, 0xb6, 0x00}}},
    {{{    -3,    -29,     21}, 0, {     0,      0}, {0x04, 0x85, 0xe4, 0x00}}},
    {{{    -5,    -18,    -24}, 0, {     0,      0}, {0x03, 0x85, 0xe3, 0x00}}},
    {{{    -5,     17,    -12}, 0, {     0,      0}, {0x09, 0x75, 0xd1, 0x00}}},
    {{{    -4,     17,     26}, 0, {     0,      0}, {0x08, 0x7e, 0x00, 0x00}}},
    {{{    -5,    -18,    -24}, 0, {     0,      0}, {0x06, 0x2a, 0x89, 0x00}}},
    {{{    -4,     17,     26}, 0, {     0,      0}, {0x06, 0xf5, 0x7e, 0x00}}},
    {{{    -3,    -29,     21}, 0, {     0,      0}, {0x06, 0xf4, 0x7e, 0x00}}},
    {{{    -5,     17,    -12}, 0, {     0,      0}, {0x81, 0xfe, 0x03, 0x00}}},
};

// 0x04015050 - 0x040150C0
const Gfx mario_medium_poly_right_forearm_shared_dl[] = {
    gsSPVertex(mario_medium_poly_right_forearm_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  3,  5, 0x0,  6,  7,  8, 0x0),
    gsSP2Triangles( 4,  9, 10, 0x0,  3, 11,  9, 0x0),
    gsSP2Triangles( 3,  6, 11, 0x0,  4,  3,  9, 0x0),
    gsSP2Triangles( 5,  4, 12, 0x0,  5, 12, 13, 0x0),
    gsSP2Triangles( 6,  5,  7, 0x0,  2, 14,  0, 0x0),
    gsSPEndDisplayList(),
};

// 0x040150C0
static const Vtx mario_medium_poly_right_hand_closed_dl_vertex_group1[] = {
    {{{    -7,     -4,     36}, 0, {     0,      0}, {0x8c, 0xcd, 0xfd, 0x00}}},
    {{{   -26,     40,      0}, 0, {     0,      0}, {0x8c, 0xcd, 0xfd, 0x00}}},
    {{{    -4,     -7,    -34}, 0, {     0,      0}, {0x8c, 0xcd, 0xfd, 0x00}}},
    {{{    14,    -51,      7}, 0, {     0,      0}, {0x8c, 0xcd, 0xfd, 0x00}}},
    {{{    81,     -8,     49}, 0, {     0,      0}, {0x36, 0xe6, 0x6f, 0x00}}},
    {{{    42,    -20,     54}, 0, {     0,      0}, {0xd9, 0xbb, 0x62, 0x00}}},
    {{{    54,    -42,     -4}, 0, {     0,      0}, {0x04, 0x82, 0xf6, 0x00}}},
    {{{    52,     59,     37}, 0, {     0,      0}, {0xff, 0x55, 0x5e, 0x00}}},
    {{{    16,     38,     35}, 0, {     0,      0}, {0xc1, 0x2d, 0x63, 0x00}}},
    {{{    10,      3,     33}, 0, {     0,      0}, {0xc3, 0xfa, 0x6e, 0x00}}},
    {{{   102,    -23,      0}, 0, {     0,      0}, {0x65, 0xc1, 0xd7, 0x00}}},
    {{{    55,     84,     -8}, 0, {     0,      0}, {0x15, 0x73, 0xd1, 0x00}}},
    {{{     7,     62,    -11}, 0, {     0,      0}, {0xa7, 0x5a, 0xf9, 0x00}}},
    {{{    94,     43,     18}, 0, {     0,      0}, {0x6d, 0x38, 0x21, 0x00}}},
    {{{    32,      8,    -40}, 0, {     0,      0}, {0xda, 0xe8, 0x8a, 0x00}}},
    {{{    26,    -32,      8}, 0, {     0,      0}, {0x08, 0x82, 0xfa, 0x00}}},
};

// 0x040151C0
static const Vtx mario_medium_poly_right_hand_closed_dl_vertex_group2[] = {
    {{{    16,     38,     35}, 0, {     0,      0}, {0xc1, 0x2d, 0x63, 0x00}}},
    {{{     7,     62,    -11}, 0, {     0,      0}, {0xa7, 0x5a, 0xf9, 0x00}}},
    {{{    -3,     37,      3}, 0, {     0,      0}, {0xb0, 0x62, 0xf7, 0x00}}},
    {{{    32,      8,    -40}, 0, {     0,      0}, {0xda, 0xe8, 0x8a, 0x00}}},
    {{{    26,    -32,      8}, 0, {     0,      0}, {0x08, 0x82, 0xfa, 0x00}}},
    {{{    14,    -51,      7}, 0, {     0,      0}, {0x4f, 0xd0, 0xaa, 0x00}}},
    {{{    -4,     -7,    -34}, 0, {     0,      0}, {0x37, 0x10, 0x8f, 0x00}}},
    {{{   -26,     40,      0}, 0, {     0,      0}, {0x15, 0x51, 0xa1, 0x00}}},
    {{{   -26,     40,      0}, 0, {     0,      0}, {0x02, 0x4f, 0x62, 0x00}}},
    {{{    -7,     -4,     36}, 0, {     0,      0}, {0x19, 0x13, 0x7a, 0x00}}},
    {{{    14,    -51,      7}, 0, {     0,      0}, {0x36, 0xd7, 0x6b, 0x00}}},
    {{{    55,     84,     -8}, 0, {     0,      0}, {0x15, 0x73, 0xd1, 0x00}}},
    {{{   102,    -23,      0}, 0, {     0,      0}, {0x65, 0xc1, 0xd7, 0x00}}},
    {{{    54,    -42,     -4}, 0, {     0,      0}, {0x04, 0x82, 0xf6, 0x00}}},
    {{{    94,     43,     18}, 0, {     0,      0}, {0x6d, 0x38, 0x21, 0x00}}},
    {{{    83,     30,    -39}, 0, {     0,      0}, {0x4e, 0x1c, 0xa1, 0x00}}},
};

// 0x040152C0
static const Vtx mario_medium_poly_right_hand_closed_dl_vertex_group3[] = {
    {{{   102,    -23,      0}, 0, {     0,      0}, {0x65, 0xc1, 0xd7, 0x00}}},
    {{{    94,     43,     18}, 0, {     0,      0}, {0x6d, 0x38, 0x21, 0x00}}},
    {{{    81,     -8,     49}, 0, {     0,      0}, {0x36, 0xe6, 0x6f, 0x00}}},
    {{{    52,     59,     37}, 0, {     0,      0}, {0xff, 0x55, 0x5e, 0x00}}},
    {{{    55,     84,     -8}, 0, {     0,      0}, {0x15, 0x73, 0xd1, 0x00}}},
    {{{    32,      8,    -40}, 0, {     0,      0}, {0xda, 0xe8, 0x8a, 0x00}}},
    {{{    83,     30,    -39}, 0, {     0,      0}, {0x4e, 0x1c, 0xa1, 0x00}}},
    {{{    -7,     -4,     36}, 0, {     0,      0}, {0x19, 0x13, 0x7a, 0x00}}},
    {{{    26,    -32,      8}, 0, {     0,      0}, {0x08, 0x82, 0xfa, 0x00}}},
    {{{    10,      3,     33}, 0, {     0,      0}, {0xc3, 0xfa, 0x6e, 0x00}}},
    {{{    -3,     37,      3}, 0, {     0,      0}, {0xb0, 0x62, 0xf7, 0x00}}},
    {{{    13,      0,    -26}, 0, {     0,      0}, {0xf5, 0xf2, 0x83, 0x00}}},
    {{{    -4,     -7,    -34}, 0, {     0,      0}, {0x37, 0x10, 0x8f, 0x00}}},
    {{{    16,     38,     35}, 0, {     0,      0}, {0xc1, 0x2d, 0x63, 0x00}}},
    {{{    42,    -20,     54}, 0, {     0,      0}, {0xd9, 0xbb, 0x62, 0x00}}},
};

// 0x040153B0 - 0x040154E0
const Gfx mario_medium_poly_right_hand_closed_dl[] = {
    gsSPVertex(mario_medium_poly_right_hand_closed_dl_vertex_group1, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  7,  8, 0x0),
    gsSP2Triangles( 5,  4,  8, 0x0,  9,  5,  8, 0x0),
    gsSP2Triangles(10,  4,  6, 0x0,  7, 11, 12, 0x0),
    gsSP2Triangles( 4, 13,  7, 0x0,  7, 12,  8, 0x0),
    gsSP2Triangles(14,  6, 15, 0x0,  6,  5, 15, 0x0),
    gsSPVertex(mario_medium_poly_right_hand_closed_dl_vertex_group2, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  6,  7,  2, 0x0),
    gsSP2Triangles( 2,  8,  9, 0x0,  9, 10,  4, 0x0),
    gsSP2Triangles( 1, 11,  3, 0x0,  3, 12, 13, 0x0),
    gsSP2Triangles(11, 14, 15, 0x0, 15, 14, 12, 0x0),
    gsSPVertex(mario_medium_poly_right_hand_closed_dl_vertex_group3, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  1,  4, 0x0),
    gsSP2Triangles( 5,  6,  0, 0x0,  4,  6,  5, 0x0),
    gsSP2Triangles( 7,  8,  9, 0x0,  7,  9, 10, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0, 12, 11,  8, 0x0),
    gsSP2Triangles( 5, 11, 10, 0x0, 10,  9, 13, 0x0),
    gsSP2Triangles(14,  9,  8, 0x0,  8, 11,  5, 0x0),
    gsSPEndDisplayList(),
};

// 0x040154E0 - 0x04015500
const Gfx mario_medium_poly_right_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_right_hand_closed_dl),
    gsSPEndDisplayList(),
};

// 0x04015500 - 0x04015530
const Gfx mario_metal_medium_poly_right_hand_closed[] = {
    gsSPDisplayList(mario_medium_poly_right_hand_closed_dl),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

// 0x04015530
static const Vtx mario_medium_poly_left_thigh_dl_vertex[] = {
    {{{    18,    -12,     58}, 0, {     0,      0}, {0x13, 0xdd, 0x78, 0x00}}},
    {{{    22,    -52,      8}, 0, {     0,      0}, {0x1c, 0x85, 0x01, 0x00}}},
    {{{    99,    -35,      8}, 0, {     0,      0}, {0x3e, 0x92, 0x01, 0x00}}},
    {{{    14,     51,     38}, 0, {     0,      0}, {0x08, 0x75, 0x30, 0x00}}},
    {{{    92,     47,     33}, 0, {     0,      0}, {0x36, 0x4b, 0x56, 0x00}}},
    {{{    14,     50,    -23}, 0, {     0,      0}, {0x0a, 0x65, 0xb5, 0x00}}},
    {{{    92,     47,    -16}, 0, {     0,      0}, {0x47, 0x55, 0xc5, 0x00}}},
    {{{    19,    -13,    -42}, 0, {     0,      0}, {0x15, 0xdb, 0x89, 0x00}}},
    {{{    96,     -3,    -31}, 0, {     0,      0}, {0x68, 0xf1, 0xba, 0x00}}},
    {{{    96,     -3,     48}, 0, {     0,      0}, {0x71, 0xf8, 0x38, 0x00}}},
    {{{    19,    -13,    -42}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    22,    -52,      8}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    18,    -12,     58}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    14,     51,     38}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    14,     50,    -23}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
};

// 0x04015620 - 0x040156B0
const Gfx mario_medium_poly_left_thigh_dl[] = {
    gsSPVertex(mario_medium_poly_left_thigh_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles( 5,  3,  6, 0x0,  7,  5,  6, 0x0),
    gsSP2Triangles( 1,  7,  2, 0x0,  7,  8,  2, 0x0),
    gsSP2Triangles( 6,  8,  7, 0x0,  3,  4,  6, 0x0),
    gsSP2Triangles( 0,  9,  4, 0x0,  2,  9,  0, 0x0),
    gsSP2Triangles( 9,  2,  8, 0x0, 10, 11, 12, 0x0),
    gsSP2Triangles(12, 13, 10, 0x0, 13, 14, 10, 0x0),
    gsSP2Triangles( 8,  6,  9, 0x0,  6,  4,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x040156B0 - 0x040156E0
const Gfx mario_medium_poly_left_thigh[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_left_thigh_dl),
    gsSPEndDisplayList(),
};

// 0x040156E0 - 0x04015758
const Gfx mario_metal_medium_poly_left_thigh[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_left_thigh_dl),
    gsSPEndDisplayList(),
};

// 0x04015758
static const Vtx mario_medium_poly_left_leg_shared_dl_vertex[] = {
    {{{     5,    -35,      9}, 0, {     0,      0}, {0xca, 0x8e, 0x00, 0x00}}},
    {{{    65,    -44,     10}, 0, {     0,      0}, {0xee, 0x83, 0x01, 0x00}}},
    {{{    66,     -9,     54}, 0, {     0,      0}, {0xf2, 0xdc, 0x78, 0x00}}},
    {{{     9,     46,     33}, 0, {     0,      0}, {0xd5, 0x61, 0x45, 0x00}}},
    {{{    69,     47,     37}, 0, {     0,      0}, {0xf9, 0x66, 0x4b, 0x00}}},
    {{{    70,     47,    -18}, 0, {     0,      0}, {0xfb, 0x74, 0xcf, 0x00}}},
    {{{    10,     46,    -16}, 0, {     0,      0}, {0xaf, 0x40, 0xb7, 0x00}}},
    {{{    67,     -9,    -36}, 0, {     0,      0}, {0xf4, 0xda, 0x88, 0x00}}},
    {{{     7,     -4,    -31}, 0, {     0,      0}, {0x9b, 0xee, 0xb6, 0x00}}},
    {{{     7,     -4,     49}, 0, {     0,      0}, {0x8f, 0xf5, 0x37, 0x00}}},
    {{{    66,     -9,     54}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    65,    -44,     10}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    67,     -9,    -36}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    70,     47,    -18}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    69,     47,     37}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
};

// 0x04015848 - 0x040158D8
const Gfx mario_medium_poly_left_leg_shared_dl[] = {
    gsSPVertex(mario_medium_poly_left_leg_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  2,  4, 0x0),
    gsSP2Triangles( 3,  4,  5, 0x0,  6,  5,  7, 0x0),
    gsSP2Triangles( 0,  7,  1, 0x0,  0,  8,  7, 0x0),
    gsSP2Triangles( 7,  8,  6, 0x0,  5,  6,  3, 0x0),
    gsSP2Triangles( 3,  9,  2, 0x0,  2,  9,  0, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0,  8,  0,  9, 0x0),
    gsSP2Triangles( 9,  6,  8, 0x0,  9,  3,  6, 0x0),
    gsSP2Triangles(12, 13, 10, 0x0, 13, 14, 10, 0x0),
    gsSPEndDisplayList(),
};

// 0x040158D8
static const Vtx mario_medium_poly_left_foot_shared_dl_vertex_group1[] = {
    {{{   108,     10,     36}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   108,      9,    -20}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{    75,     21,    -41}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{    76,     22,     61}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   -14,     55,    -27}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   -13,     55,     49}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   -41,     65,      9}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{    41,    -18,     54}, 0, {     0,      0}, {0x04, 0xb4, 0x65, 0x00}}},
    {{{    76,     22,     61}, 0, {     0,      0}, {0x12, 0xdd, 0x78, 0x00}}},
    {{{   -13,     55,     49}, 0, {     0,      0}, {0xce, 0x07, 0x74, 0x00}}},
    {{{    42,    -11,    -33}, 0, {     0,      0}, {0xff, 0xb8, 0x98, 0x00}}},
    {{{   -37,     12,    -16}, 0, {     0,      0}, {0xa1, 0xcf, 0xbd, 0x00}}},
    {{{   -14,     55,    -27}, 0, {     0,      0}, {0xcc, 0x02, 0x8d, 0x00}}},
    {{{   -36,     13,     39}, 0, {     0,      0}, {0xa0, 0xd0, 0x42, 0x00}}},
    {{{    75,     21,    -41}, 0, {     0,      0}, {0x09, 0xda, 0x88, 0x00}}},
    {{{   108,      9,    -20}, 0, {     0,      0}, {0x44, 0xad, 0xbe, 0x00}}},
};

// 0x040159D8
static const Vtx mario_medium_poly_left_foot_shared_dl_vertex_group2[] = {
    {{{    78,    -30,      7}, 0, {     0,      0}, {0x34, 0x8d, 0xfb, 0x00}}},
    {{{   108,      9,    -20}, 0, {     0,      0}, {0x44, 0xad, 0xbe, 0x00}}},
    {{{   108,     10,     36}, 0, {     0,      0}, {0x4c, 0xaf, 0x3c, 0x00}}},
    {{{    42,    -11,    -33}, 0, {     0,      0}, {0xff, 0xb8, 0x98, 0x00}}},
    {{{    76,     22,     61}, 0, {     0,      0}, {0x12, 0xdd, 0x78, 0x00}}},
    {{{    41,    -18,     54}, 0, {     0,      0}, {0x04, 0xb4, 0x65, 0x00}}},
    {{{   -36,     13,     39}, 0, {     0,      0}, {0xa0, 0xd0, 0x42, 0x00}}},
    {{{   -13,     55,     49}, 0, {     0,      0}, {0xce, 0x07, 0x74, 0x00}}},
    {{{   -41,     65,      9}, 0, {     0,      0}, {0x83, 0x15, 0x00, 0x00}}},
    {{{   -14,     55,    -27}, 0, {     0,      0}, {0xcc, 0x02, 0x8d, 0x00}}},
    {{{   -37,     12,    -16}, 0, {     0,      0}, {0xa1, 0xcf, 0xbd, 0x00}}},
    {{{    25,    -34,     11}, 0, {     0,      0}, {0xdd, 0x87, 0xfb, 0x00}}},
};

// 0x04015A98 - 0x04015B60
const Gfx mario_medium_poly_left_foot_shared_dl[] = {
    gsSPVertex(mario_medium_poly_left_foot_shared_dl_vertex_group1, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSP2Triangles( 3,  2,  4, 0x0,  5,  3,  4, 0x0),
    gsSP2Triangles( 6,  5,  4, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0, 13,  7,  9, 0x0),
    gsSP2Triangles(10, 12, 14, 0x0, 10, 14, 15, 0x0),
    gsSPVertex(mario_medium_poly_left_foot_shared_dl_vertex_group2, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  0,  3, 0x0),
    gsSP2Triangles( 2,  4,  5, 0x0,  5,  0,  2, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  8,  9, 10, 0x0),
    gsSP2Triangles(11,  3,  0, 0x0, 10,  3, 11, 0x0),
    gsSP2Triangles( 0,  5, 11, 0x0, 11,  5,  6, 0x0),
    gsSP2Triangles(11,  6, 10, 0x0,  6,  8, 10, 0x0),
    gsSPEndDisplayList(),
};

// 0x04015B60 - 0x04015B80
const Gfx mario_medium_poly_left_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_left_foot_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04015B80
static const Vtx mario_medium_poly_right_thigh_shared_dl_vertex[] = {
    {{{    18,    -11,    -58}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    23,    -52,     -9}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    20,    -14,     41}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    97,     -3,     30}, 0, {     0,      0}, {0x69, 0xf1, 0x45, 0x00}}},
    {{{    99,    -33,    -10}, 0, {     0,      0}, {0x40, 0x93, 0xfc, 0x00}}},
    {{{    95,     -1,    -49}, 0, {     0,      0}, {0x71, 0xfb, 0xc7, 0x00}}},
    {{{    18,    -11,    -58}, 0, {     0,      0}, {0x12, 0xe0, 0x87, 0x00}}},
    {{{    91,     49,    -33}, 0, {     0,      0}, {0x34, 0x4e, 0xab, 0x00}}},
    {{{    92,     48,     16}, 0, {     0,      0}, {0x47, 0x55, 0x3d, 0x00}}},
    {{{    13,     52,    -37}, 0, {     0,      0}, {0x06, 0x76, 0xd3, 0x00}}},
    {{{    20,    -14,     41}, 0, {     0,      0}, {0x16, 0xd9, 0x76, 0x00}}},
    {{{    23,    -52,     -9}, 0, {     0,      0}, {0x1d, 0x85, 0xfd, 0x00}}},
    {{{    14,     50,     24}, 0, {     0,      0}, {0x0a, 0x63, 0x4d, 0x00}}},
    {{{    13,     52,    -37}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    14,     50,     24}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
};

// 0x04015C70 - 0x04015D00
const Gfx mario_medium_poly_right_thigh_shared_dl[] = {
    gsSPVertex(mario_medium_poly_right_thigh_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  5,  4, 0x0,  7,  5,  6, 0x0),
    gsSP2Triangles( 8,  7,  9, 0x0, 10,  3,  8, 0x0),
    gsSP2Triangles( 4,  3, 10, 0x0,  4, 10, 11, 0x0),
    gsSP2Triangles( 8, 12, 10, 0x0,  8,  9, 12, 0x0),
    gsSP2Triangles( 7,  6,  9, 0x0,  4, 11,  6, 0x0),
    gsSP2Triangles( 5,  8,  3, 0x0,  5,  7,  8, 0x0),
    gsSP2Triangles( 2, 13,  0, 0x0,  2, 14, 13, 0x0),
    gsSPEndDisplayList(),
};

// 0x04015D00 - 0x04015D20
const Gfx mario_medium_poly_right_thigh[] = {
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_right_thigh_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04015D20
static const Vtx mario_medium_poly_right_leg_shared_dl_vertex[] = {
    {{{     6,     -1,    -50}, 0, {     0,      0}, {0x8e, 0xf7, 0xca, 0x00}}},
    {{{     5,    -34,    -11}, 0, {     0,      0}, {0xc9, 0x8e, 0xfe, 0x00}}},
    {{{     7,     -4,     30}, 0, {     0,      0}, {0x9b, 0xed, 0x4a, 0x00}}},
    {{{    67,     -9,     34}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    64,    -43,    -12}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    66,     -7,    -56}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    66,     -7,    -56}, 0, {     0,      0}, {0xf1, 0xde, 0x87, 0x00}}},
    {{{    10,     48,    -33}, 0, {     0,      0}, {0xd6, 0x63, 0xbe, 0x00}}},
    {{{    10,     46,     16}, 0, {     0,      0}, {0xb1, 0x3f, 0x4b, 0x00}}},
    {{{    71,     47,     18}, 0, {     0,      0}, {0xfd, 0x73, 0x33, 0x00}}},
    {{{    67,     -9,     34}, 0, {     0,      0}, {0xf4, 0xd8, 0x77, 0x00}}},
    {{{    64,    -43,    -12}, 0, {     0,      0}, {0xec, 0x83, 0xfd, 0x00}}},
    {{{    70,     49,    -37}, 0, {     0,      0}, {0xfa, 0x67, 0xb8, 0x00}}},
    {{{    71,     47,     18}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    70,     49,    -37}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
};

// 0x04015E10 - 0x04015EA0
const Gfx mario_medium_poly_right_leg_shared_dl[] = {
    gsSPVertex(mario_medium_poly_right_leg_shared_dl_vertex, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 1,  0,  6, 0x0,  6,  0,  7, 0x0),
    gsSP2Triangles( 7,  8,  9, 0x0,  8,  2, 10, 0x0),
    gsSP2Triangles(10,  2,  1, 0x0, 11, 10,  1, 0x0),
    gsSP2Triangles(10,  9,  8, 0x0,  9, 12,  7, 0x0),
    gsSP2Triangles(12,  6,  7, 0x0,  6, 11,  1, 0x0),
    gsSP2Triangles( 5, 13,  3, 0x0,  5, 14, 13, 0x0),
    gsSP2Triangles( 2,  8,  0, 0x0,  8,  7,  0, 0x0),
    gsSPEndDisplayList(),
};

// 0x04015EA0
static const Vtx mario_medium_poly_right_foot_dl_vertex_group1[] = {
    {{{   -38,     12,     14}, 0, {     0,      0}, {0xa1, 0xcf, 0x43, 0x00}}},
    {{{   -43,     65,    -12}, 0, {     0,      0}, {0x83, 0x13, 0xff, 0x00}}},
    {{{   -36,     12,    -41}, 0, {     0,      0}, {0xa1, 0xce, 0xbe, 0x00}}},
    {{{    25,    -34,    -11}, 0, {     0,      0}, {0xdf, 0x86, 0x07, 0x00}}},
    {{{    41,    -18,    -55}, 0, {     0,      0}, {0x07, 0xb3, 0x9c, 0x00}}},
    {{{    79,    -29,     -7}, 0, {     0,      0}, {0x36, 0x8e, 0x08, 0x00}}},
    {{{    42,    -10,     32}, 0, {     0,      0}, {0xff, 0xba, 0x69, 0x00}}},
    {{{   -15,     55,     24}, 0, {     0,      0}, {0xcb, 0x04, 0x73, 0x00}}},
    {{{   -14,     54,    -51}, 0, {     0,      0}, {0xcf, 0x04, 0x8c, 0x00}}},
    {{{   108,     11,    -36}, 0, {     0,      0}, {0x4e, 0xb0, 0xc6, 0x00}}},
    {{{    76,     23,    -62}, 0, {     0,      0}, {0x14, 0xdb, 0x89, 0x00}}},
    {{{   107,     12,     20}, 0, {     0,      0}, {0x45, 0xaf, 0x44, 0x00}}},
    {{{    74,     24,     40}, 0, {     0,      0}, {0x08, 0xdc, 0x79, 0x00}}},
    {{{   -15,     55,     24}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   -14,     54,    -51}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   -43,     65,    -12}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
};

// 0x04015FA0
static const Vtx mario_medium_poly_right_foot_dl_vertex_group2[] = {
    {{{   -15,     55,     24}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{    76,     23,    -62}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   -14,     54,    -51}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{    74,     24,     40}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   108,     11,    -36}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   107,     12,     20}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
};

// 0x04016000 - 0x040160C8
const Gfx mario_medium_poly_right_foot_dl[] = {
    gsSPVertex(mario_medium_poly_right_foot_dl_vertex_group1, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 2,  4,  3, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 3,  6,  0, 0x0,  5,  6,  3, 0x0),
    gsSP2Triangles( 0,  7,  1, 0x0,  1,  8,  2, 0x0),
    gsSP2Triangles( 9,  5,  4, 0x0,  4, 10,  9, 0x0),
    gsSP2Triangles( 6,  5, 11, 0x0,  9, 11,  5, 0x0),
    gsSP2Triangles(11, 12,  6, 0x0, 12,  7,  6, 0x0),
    gsSP2Triangles( 8,  4,  2, 0x0,  7,  0,  6, 0x0),
    gsSP2Triangles( 8, 10,  4, 0x0, 13, 14, 15, 0x0),
    gsSPVertex(mario_medium_poly_right_foot_dl_vertex_group2, 6, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 3,  4,  1, 0x0,  3,  5,  4, 0x0),
    gsSPEndDisplayList(),
};

// 0x040160C8 - 0x04016108
const Gfx mario_medium_poly_right_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_right_foot_dl),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

Gfx mat_mario_hair_v3_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(mario_hair_v3_001_lights),
	gsSPEndDisplayList(),
};

// 0x04016148
static const Vtx mario_seg4_vertex_04016148[] = {
    {{{    75,     24,    -60}, 0, {   -74,   -930}, {0x60, 0x27, 0xb8, 0xff}}},
    {{{    36,     47,    -76}, 0, {  -174,    168}, {0x2e, 0x36, 0x98, 0xff}}},
    {{{    44,     78,    -35}, 0, {   988,     92}, {0x45, 0x65, 0xe2, 0xff}}},
    {{{   -26,     49,    -87}, 0, {  -538,   1590}, {0xc4, 0x29, 0x99, 0xff}}},
    {{{     1,     87,    -53}, 0, {   638,   1164}, {0x0e, 0x74, 0xd1, 0xff}}},
    {{{     1,     87,     54}, 0, {  2522,    702}, {0x11, 0x74, 0x2f, 0xff}}},
    {{{     1,     87,     54}, 0, {   272,   1122}, {0x11, 0x74, 0x2f, 0xff}}},
    {{{    44,     78,     37}, 0, {   -92,    108}, {0x47, 0x5f, 0x2a, 0xff}}},
    {{{    44,     78,    -35}, 0, { -1398,   -128}, {0x45, 0x65, 0xe2, 0xff}}},
    {{{   -26,     49,     88}, 0, {  1514,   1490}, {0xc4, 0x29, 0x67, 0xff}}},
    {{{    36,     47,     77}, 0, {  1110,    130}, {0x2f, 0x37, 0x68, 0xff}}},
    {{{    75,     24,     60}, 0, {   968,   -926}, {0x62, 0x27, 0x46, 0xff}}},
};

// 0x04016208
static const Vtx mario_seg4_vertex_04016208[] = {
    {{{    82,     37,     28}, 0, {     0,      0}, {0x71, 0x36, 0x0e, 0xff}}},
    {{{    82,     37,    -28}, 0, {     0,      0}, {0x71, 0x35, 0xea, 0xff}}},
    {{{    44,     78,    -35}, 0, {     0,      0}, {0x45, 0x65, 0xe2, 0xff}}},
    {{{    44,     78,     37}, 0, {     0,      0}, {0x47, 0x5f, 0x2a, 0xff}}},
    {{{    95,    -39,    -25}, 0, {     0,      0}, {0x79, 0xe6, 0xe8, 0xff}}},
    {{{    95,    -39,     25}, 0, {     0,      0}, {0x75, 0xdb, 0x1d, 0xff}}},
    {{{    54,    -68,      0}, 0, {     0,      0}, {0x2d, 0x8a, 0x00, 0xff}}},
    {{{    56,     -4,     79}, 0, {     0,      0}, {0x39, 0x04, 0x71, 0xff}}},
    {{{    75,     24,     60}, 0, {     0,      0}, {0x62, 0x27, 0x46, 0xff}}},
    {{{    36,     47,     77}, 0, {     0,      0}, {0x2f, 0x37, 0x68, 0xff}}},
    {{{     9,      0,     94}, 0, {     0,      0}, {0x0e, 0x03, 0x7e, 0xff}}},
    {{{    22,    -41,     87}, 0, {     0,      0}, {0x1f, 0xc9, 0x6d, 0xff}}},
    {{{    83,    -29,     58}, 0, {     0,      0}, {0x54, 0xc8, 0x4c, 0xff}}},
    {{{    83,    -29,    -58}, 0, {     0,      0}, {0x52, 0xc9, 0xb2, 0xff}}},
    {{{    40,    -66,    -47}, 0, {     0,      0}, {0x1d, 0x91, 0xcb, 0xff}}},
    {{{    22,    -41,    -86}, 0, {     0,      0}, {0x1e, 0xca, 0x92, 0xff}}},
};

// 0x04016308
static const Vtx mario_seg4_vertex_04016308[] = {
    {{{    36,     47,    -76}, 0, {     0,      0}, {0x2e, 0x36, 0x98, 0xff}}},
    {{{    75,     24,    -60}, 0, {     0,      0}, {0x60, 0x27, 0xb8, 0xff}}},
    {{{    56,     -4,    -77}, 0, {     0,      0}, {0x38, 0x04, 0x8f, 0xff}}},
    {{{     9,      0,    -93}, 0, {     0,      0}, {0x0e, 0x03, 0x82, 0xff}}},
    {{{    83,    -29,    -58}, 0, {     0,      0}, {0x52, 0xc9, 0xb2, 0xff}}},
    {{{    22,    -41,    -86}, 0, {     0,      0}, {0x1e, 0xca, 0x92, 0xff}}},
    {{{    22,    -41,     87}, 0, {     0,      0}, {0x1f, 0xc9, 0x6d, 0xff}}},
    {{{    40,    -66,     48}, 0, {     0,      0}, {0x1d, 0x91, 0x35, 0xff}}},
    {{{    83,    -29,     58}, 0, {     0,      0}, {0x54, 0xc8, 0x4c, 0xff}}},
};

// 0x04016398
static const Vtx mario_seg4_vertex_04016398[] = {
    {{{    83,    -29,    -58}, 0, {     0,      0}, {0x52, 0xc9, 0xb2, 0xff}}},
    {{{    95,    -39,    -25}, 0, {     0,      0}, {0x79, 0xe6, 0xe8, 0xff}}},
    {{{    54,    -68,      0}, 0, {     0,      0}, {0x2d, 0x8a, 0x00, 0xff}}},
    {{{    75,     24,    -60}, 0, {     0,      0}, {0x60, 0x27, 0xb8, 0xff}}},
    {{{    82,     37,    -28}, 0, {     0,      0}, {0x71, 0x35, 0xea, 0xff}}},
    {{{    40,    -66,    -47}, 0, {     0,      0}, {0x1d, 0x91, 0xcb, 0xff}}},
    {{{    44,     78,    -35}, 0, {     0,      0}, {0x45, 0x65, 0xe2, 0xff}}},
    {{{    75,     24,     60}, 0, {     0,      0}, {0x62, 0x27, 0x46, 0xff}}},
    {{{    82,     37,     28}, 0, {     0,      0}, {0x71, 0x36, 0x0e, 0xff}}},
    {{{    44,     78,     37}, 0, {     0,      0}, {0x47, 0x5f, 0x2a, 0xff}}},
    {{{    83,    -29,     58}, 0, {     0,      0}, {0x54, 0xc8, 0x4c, 0xff}}},
    {{{    95,    -39,     25}, 0, {     0,      0}, {0x75, 0xdb, 0x1d, 0xff}}},
    {{{    40,    -66,     48}, 0, {     0,      0}, {0x1d, 0x91, 0x35, 0xff}}},
    {{{     1,     87,    -53}, 0, {     0,      0}, {0x0e, 0x74, 0xd1, 0xff}}},
    {{{   -30,     88,     42}, 0, {     0,      0}, {0xd3, 0x72, 0x1f, 0xff}}},
    {{{     1,     87,     54}, 0, {     0,      0}, {0x11, 0x74, 0x2f, 0xff}}},
};

// 0x04016498
static const Vtx mario_seg4_vertex_04016498[] = {
    {{{     1,     87,    -53}, 0, {     0,      0}, {0x0e, 0x74, 0xd1, 0xff}}},
    {{{   -30,     88,    -41}, 0, {     0,      0}, {0xc7, 0x6a, 0xda, 0xff}}},
    {{{   -30,     88,     42}, 0, {     0,      0}, {0xd3, 0x72, 0x1f, 0xff}}},
    {{{   -26,     49,    -87}, 0, {     0,      0}, {0xc4, 0x29, 0x99, 0xff}}},
    {{{   -71,     56,      0}, 0, {     0,      0}, {0x89, 0x2b, 0x00, 0xff}}},
    {{{   -26,     49,     88}, 0, {     0,      0}, {0xc4, 0x29, 0x67, 0xff}}},
    {{{     1,     87,     54}, 0, {     0,      0}, {0x11, 0x74, 0x2f, 0xff}}},
    {{{   -59,    -44,      0}, 0, {     0,      0}, {0x88, 0xd8, 0x00, 0xff}}},
    {{{   -26,    -72,    -38}, 0, {     0,      0}, {0xda, 0x8b, 0xe5, 0xff}}},
    {{{   -26,    -72,     39}, 0, {     0,      0}, {0xda, 0x8b, 0x1b, 0xff}}},
    {{{   -26,    -41,     85}, 0, {     0,      0}, {0xcc, 0xc2, 0x61, 0xff}}},
    {{{   -26,    -41,    -84}, 0, {     0,      0}, {0xcc, 0xc2, 0x9f, 0xff}}},
    {{{    40,    -66,     48}, 0, {     0,      0}, {0x1d, 0x91, 0x35, 0xff}}},
    {{{    22,    -41,     87}, 0, {     0,      0}, {0x1f, 0xc9, 0x6d, 0xff}}},
    {{{     9,      0,     94}, 0, {     0,      0}, {0x0e, 0x03, 0x7e, 0xff}}},
    {{{    54,    -68,      0}, 0, {     0,      0}, {0x2d, 0x8a, 0x00, 0xff}}},
};

// 0x04016598
static const Vtx mario_seg4_vertex_04016598[] = {
    {{{   -26,     49,     88}, 0, {     0,      0}, {0xc4, 0x29, 0x67, 0xff}}},
    {{{     9,      0,     94}, 0, {     0,      0}, {0x0e, 0x03, 0x7e, 0xff}}},
    {{{    36,     47,     77}, 0, {     0,      0}, {0x2f, 0x37, 0x68, 0xff}}},
    {{{     9,      0,    -93}, 0, {     0,      0}, {0x0e, 0x03, 0x82, 0xff}}},
    {{{   -26,     49,    -87}, 0, {     0,      0}, {0xc4, 0x29, 0x99, 0xff}}},
    {{{    36,     47,    -76}, 0, {     0,      0}, {0x2e, 0x36, 0x98, 0xff}}},
    {{{   -26,    -41,    -84}, 0, {     0,      0}, {0xcc, 0xc2, 0x9f, 0xff}}},
    {{{    22,    -41,    -86}, 0, {     0,      0}, {0x1e, 0xca, 0x92, 0xff}}},
    {{{    40,    -66,    -47}, 0, {     0,      0}, {0x1d, 0x91, 0xcb, 0xff}}},
    {{{   -26,    -72,    -38}, 0, {     0,      0}, {0xda, 0x8b, 0xe5, 0xff}}},
    {{{    54,    -68,      0}, 0, {     0,      0}, {0x2d, 0x8a, 0x00, 0xff}}},
    {{{   -26,    -72,     39}, 0, {     0,      0}, {0xda, 0x8b, 0x1b, 0xff}}},
    {{{    40,    -66,     48}, 0, {     0,      0}, {0x1d, 0x91, 0x35, 0xff}}},
};

// 0x04016668 - 0x040166B8
const Gfx mario_medium_poly_yellow_button_dl[] = {
    gsSPVertex(mario_seg4_vertex_04016148, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 2,  1,  4, 0x0,  4,  5,  2, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9, 10,  6, 0x0),
    gsSP2Triangles( 6, 10,  7, 0x0,  7, 10, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x040166B8 - 0x04016800
const Gfx mario_medium_poly_pants_overalls_shared_dl[] = {
    gsSPVertex(mario_seg4_vertex_04016398, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  0,  3, 0x0),
    gsSP2Triangles( 3,  4,  1, 0x0,  2,  5,  0, 0x0),
    gsSP2Triangles( 4,  3,  6, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 7, 10, 11, 0x0,  8,  7, 11, 0x0),
    gsSP2Triangles(11, 10,  2, 0x0, 10, 12,  2, 0x0),
    gsSP1Triangle(13, 14, 15, 0x0),
    gsSPVertex(mario_seg4_vertex_04016498, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  1,  0, 0x0),
    gsSP2Triangles( 4,  2,  1, 0x0,  1,  3,  4, 0x0),
    gsSP2Triangles( 5,  2,  4, 0x0,  6,  2,  5, 0x0),
    gsSP2Triangles( 4,  3,  7, 0x0,  8,  9,  7, 0x0),
    gsSP2Triangles( 5,  4,  7, 0x0,  9, 10,  7, 0x0),
    gsSP2Triangles(11,  8,  7, 0x0,  3, 11,  7, 0x0),
    gsSP2Triangles( 7, 10,  5, 0x0, 10,  9, 12, 0x0),
    gsSP2Triangles(10, 13, 14, 0x0, 12, 13, 10, 0x0),
    gsSP2Triangles( 5, 10, 14, 0x0,  9,  8, 15, 0x0),
    gsSPVertex(mario_seg4_vertex_04016598, 13, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  4,  3, 0x0,  6,  3,  7, 0x0),
    gsSP2Triangles( 8,  9,  6, 0x0,  6,  7,  8, 0x0),
    gsSP2Triangles( 9,  8, 10, 0x0, 11, 10, 12, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016800 - 0x040168A0
const Gfx mario_medium_poly_tshirt_shared_dl[] = {
    gsSPVertex(mario_seg4_vertex_04016208, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 1,  0,  4, 0x0,  0,  5,  4, 0x0),
    gsSP2Triangles( 6,  4,  5, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 9, 10,  7, 0x0,  7, 10, 11, 0x0),
    gsSP2Triangles( 7, 12,  8, 0x0, 11, 12,  7, 0x0),
    gsSP1Triangle(13, 14, 15, 0x0),
    gsSPVertex(mario_seg4_vertex_04016308, 9, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 1,  4,  2, 0x0,  2,  4,  5, 0x0),
    gsSP2Triangles( 5,  3,  2, 0x0,  6,  7,  8, 0x0),
    gsSPEndDisplayList(),
};

// 0x040168A0 - 0x040168C8
const Gfx mario_medium_poly_torso_dl[] = {
    gsSPDisplayList(mario_medium_poly_pants_overalls_shared_dl),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_medium_poly_tshirt_shared_dl),
    gsSPEndDisplayList(),
};

// 0x040168C8 - 0x04016948
const Gfx mario_medium_poly_torso[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_yellow_button),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_medium_poly_yellow_button_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_medium_poly_torso_dl),
    gsSPEndDisplayList(),
};

// 0x04016948 - 0x04016968
const Gfx mario_metal_medium_poly_torso[] = {
    gsSPDisplayList(mario_medium_poly_yellow_button_dl),
    gsSPDisplayList(mario_medium_poly_pants_overalls_shared_dl),
    gsSPDisplayList(mario_medium_poly_tshirt_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04016968
static const Vtx mario_low_poly_butt_dl_vertex[] = {
    {{{   -37,    -37,      0}, 0, {     0,      0}, {0x82, 0xf5, 0x00, 0x00}}},
    {{{    -2,     52,     92}, 0, {     0,      0}, {0xb1, 0x3c, 0x4e, 0x00}}},
    {{{   -35,     55,      0}, 0, {     0,      0}, {0x97, 0x45, 0x00, 0x00}}},
    {{{    -7,    -86,     85}, 0, {     0,      0}, {0xbf, 0xc4, 0x5a, 0x00}}},
    {{{    49,     46,     96}, 0, {     0,      0}, {0x4b, 0x1d, 0x61, 0x00}}},
    {{{    -7,    -86,    -85}, 0, {     0,      0}, {0xcf, 0xaa, 0xb2, 0x00}}},
    {{{    -2,     52,    -92}, 0, {     0,      0}, {0xb0, 0x3b, 0xb2, 0x00}}},
    {{{    48,     44,    -98}, 0, {     0,      0}, {0x29, 0x22, 0x8e, 0x00}}},
    {{{    46,    -71,    -89}, 0, {     0,      0}, {0x73, 0xd9, 0xdd, 0x00}}},
    {{{    46,    -71,     89}, 0, {     0,      0}, {0x44, 0xa1, 0x2f, 0x00}}},
    {{{    49,     96,      0}, 0, {     0,      0}, {0x2b, 0x77, 0x00, 0x00}}},
};

// 0x04016A18 - 0x04016AB8
const Gfx mario_low_poly_butt_dl[] = {
    gsSPVertex(mario_low_poly_butt_dl_vertex, 11, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  4, 0x0),
    gsSP2Triangles( 5,  6,  7, 0x0,  0,  2,  6, 0x0),
    gsSP2Triangles( 6,  5,  0, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 7,  8,  5, 0x0,  3,  9,  4, 0x0),
    gsSP2Triangles( 8,  7, 10, 0x0,  4,  9,  8, 0x0),
    gsSP2Triangles( 5,  9,  3, 0x0,  3,  0,  5, 0x0),
    gsSP2Triangles( 5,  8,  9, 0x0, 10,  7,  6, 0x0),
    gsSP2Triangles(10,  4,  8, 0x0,  2,  1, 10, 0x0),
    gsSP2Triangles( 6,  2, 10, 0x0,  1,  4, 10, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016AB8 - 0x04016AE8
const Gfx mario_low_poly_butt[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_butt_dl),
    gsSPEndDisplayList(),
};

// 0x04016AE8 - 0x04016B60
const Gfx mario_metal_low_poly_butt[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_butt_dl),
    gsSPEndDisplayList(),
};

// 0x04016B60
static const Vtx mario_low_poly_left_arm_shared_dl_vertex[] = {
    {{{    -6,     28,     10}, 0, {     0,      0}, {0x09, 0x65, 0xb5, 0x00}}},
    {{{    72,     21,      8}, 0, {     0,      0}, {0x44, 0x4d, 0x48, 0x00}}},
    {{{    71,    -11,    -34}, 0, {     0,      0}, {0x3f, 0x57, 0xbe, 0x00}}},
    {{{    -8,    -30,     31}, 0, {     0,      0}, {0x09, 0x26, 0x78, 0x00}}},
    {{{    71,    -30,     23}, 0, {     0,      0}, {0x5e, 0x15, 0x51, 0x00}}},
    {{{    -6,     28,     10}, 0, {     0,      0}, {0x07, 0x29, 0x77, 0x00}}},
    {{{    -8,     -7,    -41}, 0, {     0,      0}, {0x0b, 0x67, 0xb8, 0x00}}},
    {{{    -8,    -30,     31}, 0, {     0,      0}, {0xa4, 0xad, 0xe5, 0x00}}},
    {{{    -6,     28,     10}, 0, {     0,      0}, {0x81, 0x02, 0x00, 0x00}}},
    {{{    -8,     -7,    -41}, 0, {     0,      0}, {0xa4, 0xad, 0xe5, 0x00}}},
    {{{    71,    -11,    -34}, 0, {     0,      0}, {0xfd, 0x88, 0xd9, 0x00}}},
    {{{    71,    -30,     23}, 0, {     0,      0}, {0xfd, 0x88, 0xd9, 0x00}}},
};

// 0x04016C20 - 0x04016C70
const Gfx mario_low_poly_left_arm_shared_dl[] = {
    gsSPVertex(mario_low_poly_left_arm_shared_dl_vertex, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 5,  3,  1, 0x0,  6,  0,  2, 0x0),
    gsSP2Triangles( 7,  8,  9, 0x0,  2,  1,  4, 0x0),
    gsSP2Triangles( 7,  9, 10, 0x0,  7, 10, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016C70 - 0x04016C90
const Gfx mario_low_poly_left_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_left_arm_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04016C90
static const Vtx mario_low_poly_left_forearm_shared_dl_vertex[] = {
    {{{    -5,     20,      6}, 0, {     0,      0}, {0x05, 0x62, 0xb0, 0x00}}},
    {{{    67,     16,      5}, 0, {     0,      0}, {0x43, 0x4b, 0x4c, 0x00}}},
    {{{    67,    -14,    -31}, 0, {     0,      0}, {0x3c, 0x55, 0xba, 0x00}}},
    {{{    -5,    -30,     21}, 0, {     0,      0}, {0x05, 0x20, 0x7a, 0x00}}},
    {{{    67,    -30,     17}, 0, {     0,      0}, {0x5c, 0x14, 0x54, 0x00}}},
    {{{    -5,     20,      6}, 0, {     0,      0}, {0x04, 0x22, 0x7a, 0x00}}},
    {{{    -5,    -12,    -35}, 0, {     0,      0}, {0x07, 0x63, 0xb2, 0x00}}},
    {{{    -5,    -30,     21}, 0, {     0,      0}, {0xa5, 0xad, 0xe5, 0x00}}},
    {{{    -5,     20,      6}, 0, {     0,      0}, {0x81, 0x01, 0x00, 0x00}}},
    {{{    -5,    -12,    -35}, 0, {     0,      0}, {0xa5, 0xad, 0xe5, 0x00}}},
    {{{    67,    -30,     17}, 0, {     0,      0}, {0xfe, 0x88, 0xd9, 0x00}}},
    {{{    67,    -14,    -31}, 0, {     0,      0}, {0xfe, 0x88, 0xd9, 0x00}}},
};

// 0x04016D50 - 0x04016DA0
const Gfx mario_low_poly_left_forearm_shared_dl[] = {
    gsSPVertex(mario_low_poly_left_forearm_shared_dl_vertex, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 5,  3,  1, 0x0,  6,  0,  2, 0x0),
    gsSP2Triangles( 7,  8,  9, 0x0,  2,  1,  4, 0x0),
    gsSP2Triangles(10,  7,  9, 0x0, 10,  9, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016DA0
static const Vtx mario_low_poly_left_hand_closed_shared_dl_vertex[] = {
    {{{    -6,     34,    -25}, 0, {     0,      0}, {0xa0, 0x13, 0xb0, 0x00}}},
    {{{    -9,     39,     24}, 0, {     0,      0}, {0xb3, 0x43, 0x4a, 0x00}}},
    {{{    91,     80,    -34}, 0, {     0,      0}, {0x13, 0x7c, 0xee, 0x00}}},
    {{{    90,     35,     33}, 0, {     0,      0}, {0x41, 0x14, 0x6b, 0x00}}},
    {{{    20,    -34,     21}, 0, {     0,      0}, {0xd4, 0x9a, 0x3c, 0x00}}},
    {{{   122,      4,    -45}, 0, {     0,      0}, {0x63, 0xbb, 0x25, 0x00}}},
    {{{   122,      4,    -45}, 0, {     0,      0}, {0xf2, 0x15, 0x84, 0x00}}},
    {{{    20,    -31,    -44}, 0, {     0,      0}, {0xcb, 0xae, 0xb1, 0x00}}},
};

// 0x04016E20 - 0x04016E80
const Gfx mario_low_poly_left_hand_closed_shared_dl[] = {
    gsSPVertex(mario_low_poly_left_hand_closed_shared_dl_vertex, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSP2Triangles( 4,  5,  3, 0x0,  0,  6,  7, 0x0),
    gsSP2Triangles( 0,  2,  6, 0x0,  4,  7,  5, 0x0),
    gsSP2Triangles( 3,  1,  4, 0x0,  2,  3,  5, 0x0),
    gsSP2Triangles( 0,  7,  4, 0x0,  4,  1,  0, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016E80 - 0x04016EA0
const Gfx mario_low_poly_left_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_left_hand_closed_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04016EA0
static const Vtx mario_low_poly_right_arm_shared_dl_vertex[] = {
    {{{    65,     30,     23}, 0, {     0,      0}, {0x5e, 0xeb, 0x51, 0x00}}},
    {{{    66,    -21,      8}, 0, {     0,      0}, {0x45, 0xb3, 0x49, 0x00}}},
    {{{    65,     11,    -34}, 0, {     0,      0}, {0x40, 0xa9, 0xbf, 0x00}}},
    {{{   -10,      7,    -41}, 0, {     0,      0}, {0xa4, 0x52, 0xe5, 0x00}}},
    {{{    -9,    -28,     10}, 0, {     0,      0}, {0x81, 0xfe, 0x00, 0x00}}},
    {{{   -10,     30,     30}, 0, {     0,      0}, {0xa4, 0x52, 0xe5, 0x00}}},
    {{{    -9,    -28,     10}, 0, {     0,      0}, {0x09, 0x9a, 0xb6, 0x00}}},
    {{{   -10,      7,    -41}, 0, {     0,      0}, {0x0c, 0x99, 0xb8, 0x00}}},
    {{{   -10,     30,     30}, 0, {     0,      0}, {0x0a, 0xdb, 0x78, 0x00}}},
    {{{    -9,    -28,     10}, 0, {     0,      0}, {0x07, 0xd8, 0x78, 0x00}}},
    {{{    65,     30,     23}, 0, {     0,      0}, {0xfc, 0x78, 0xd9, 0x00}}},
    {{{    65,     11,    -34}, 0, {     0,      0}, {0xfc, 0x78, 0xd9, 0x00}}},
};

// 0x04016F60 - 0x04016FB0
const Gfx mario_low_poly_right_arm_shared_dl[] = {
    gsSPVertex(mario_low_poly_right_arm_shared_dl_vertex, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 2,  6,  7, 0x0,  1,  8,  9, 0x0),
    gsSP2Triangles( 1,  0,  8, 0x0,  2,  1,  6, 0x0),
    gsSP2Triangles( 5, 10, 11, 0x0,  5, 11,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x04016FB0 - 0x04016FD0
const Gfx mario_low_poly_right_arm[] = {
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_right_arm_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04016FD0
static const Vtx mario_low_poly_right_forearm_shared_dl_vertex[] = {
    {{{   -13,     12,    -35}, 0, {     0,      0}, {0xa5, 0x53, 0xe5, 0x00}}},
    {{{   -13,    -20,      6}, 0, {     0,      0}, {0x81, 0xff, 0x00, 0x00}}},
    {{{   -13,     30,     21}, 0, {     0,      0}, {0xa5, 0x53, 0xe5, 0x00}}},
    {{{    54,     14,    -31}, 0, {     0,      0}, {0x3d, 0xaa, 0xba, 0x00}}},
    {{{   -13,    -20,      6}, 0, {     0,      0}, {0x05, 0x9e, 0xb1, 0x00}}},
    {{{   -13,     12,    -35}, 0, {     0,      0}, {0x07, 0x9c, 0xb3, 0x00}}},
    {{{    55,    -16,      5}, 0, {     0,      0}, {0x43, 0xb5, 0x4c, 0x00}}},
    {{{   -13,     30,     21}, 0, {     0,      0}, {0x05, 0xe0, 0x7a, 0x00}}},
    {{{   -13,    -20,      6}, 0, {     0,      0}, {0x04, 0xde, 0x7a, 0x00}}},
    {{{    54,     30,     17}, 0, {     0,      0}, {0x5c, 0xed, 0x54, 0x00}}},
    {{{    54,     30,     17}, 0, {     0,      0}, {0xfe, 0x78, 0xd8, 0x00}}},
    {{{    54,     14,    -31}, 0, {     0,      0}, {0xfe, 0x78, 0xd8, 0x00}}},
};

// 0x04017090 - 0x040170E0
const Gfx mario_low_poly_right_forearm_shared_dl[] = {
    gsSPVertex(mario_low_poly_right_forearm_shared_dl_vertex, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  6,  9,  7, 0x0),
    gsSP2Triangles( 3,  6,  4, 0x0,  2, 10, 11, 0x0),
    gsSP2Triangles( 2, 11,  0, 0x0,  9,  6,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x040170E0
static const Vtx mario_low_poly_right_hand_closed_dl_vertex[] = {
    {{{    85,    -38,    -32}, 0, {     0,      0}, {0x3d, 0xe3, 0x96, 0x00}}},
    {{{   -15,    -35,    -22}, 0, {     0,      0}, {0x99, 0xdc, 0xc1, 0x00}}},
    {{{    17,     37,    -22}, 0, {     0,      0}, {0xfe, 0x69, 0xb9, 0x00}}},
    {{{   116,    -10,     36}, 0, {     0,      0}, {0x66, 0x47, 0x16, 0x00}}},
    {{{    82,    -85,     44}, 0, {     0,      0}, {0x13, 0x8a, 0xd8, 0x00}}},
    {{{   -15,    -35,     43}, 0, {     0,      0}, {0x9d, 0xec, 0x4c, 0x00}}},
    {{{    82,    -85,     44}, 0, {     0,      0}, {0x02, 0x15, 0x7d, 0x00}}},
    {{{    14,     30,     26}, 0, {     0,      0}, {0xca, 0x50, 0x51, 0x00}}},
};

// 0x04017160 - 0x040171C0
const Gfx mario_low_poly_right_hand_closed_dl[] = {
    gsSPVertex(mario_low_poly_right_hand_closed_dl_vertex, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  0,  3, 0x0,  4,  5,  1, 0x0),
    gsSP2Triangles( 6,  3,  7, 0x0,  5,  6,  7, 0x0),
    gsSP2Triangles( 0,  4,  1, 0x0,  3,  2,  7, 0x0),
    gsSP2Triangles( 1,  5,  7, 0x0,  7,  2,  1, 0x0),
    gsSPEndDisplayList(),
};

// 0x040171C0 - 0x040171E0
const Gfx mario_low_poly_right_hand_closed[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_right_hand_closed_dl),
    gsSPEndDisplayList(),
};

// 0x040171E0 - 0x04017210
const Gfx mario_metal_low_poly_right_hand_closed[] = {
    gsSPDisplayList(mario_low_poly_right_hand_closed_dl),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

// 0x04017210
static const Vtx mario_low_poly_left_thigh_dl_vertex[] = {
    {{{    10,     51,     45}, 0, {     0,      0}, {0x08, 0x73, 0x34, 0x00}}},
    {{{    17,    -44,     58}, 0, {     0,      0}, {0x0a, 0x11, 0x7d, 0x00}}},
    {{{    94,     48,     38}, 0, {     0,      0}, {0x38, 0x40, 0x5d, 0x00}}},
    {{{    11,     51,    -27}, 0, {     0,      0}, {0x0b, 0x5e, 0xad, 0x00}}},
    {{{    95,     48,    -19}, 0, {     0,      0}, {0x4a, 0x4f, 0xbf, 0x00}}},
    {{{    18,    -45,    -38}, 0, {     0,      0}, {0x0c, 0x0f, 0x83, 0x00}}},
    {{{   101,    -28,    -28}, 0, {     0,      0}, {0x5b, 0xca, 0xbc, 0x00}}},
    {{{   100,    -28,     48}, 0, {     0,      0}, {0x63, 0xbd, 0x29, 0x00}}},
    {{{    17,    -44,     58}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    10,     51,     45}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    18,    -45,    -38}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    11,     51,    -27}, 0, {     0,      0}, {0x82, 0xf7, 0xff, 0x00}}},
    {{{    18,    -45,    -38}, 0, {     0,      0}, {0x18, 0x84, 0x01, 0x00}}},
    {{{    17,    -44,     58}, 0, {     0,      0}, {0x18, 0x84, 0x01, 0x00}}},
};

// 0x040172F0 - 0x04017360
const Gfx mario_low_poly_left_thigh_dl[] = {
    gsSPVertex(mario_low_poly_left_thigh_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles( 5,  3,  4, 0x0,  4,  6,  5, 0x0),
    gsSP2Triangles( 0,  2,  4, 0x0,  1,  7,  2, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  9, 11, 10, 0x0),
    gsSP2Triangles( 6,  4,  7, 0x0,  4,  2,  7, 0x0),
    gsSP2Triangles(12,  7, 13, 0x0, 12,  6,  7, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017360 - 0x04017390
const Gfx mario_low_poly_left_thigh[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_left_thigh_dl),
    gsSPEndDisplayList(),
};

// 0x04017390 - 0x04017408
const Gfx mario_metal_low_poly_left_thigh[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_left_thigh_dl),
    gsSPEndDisplayList(),
};

// 0x04017408
static const Vtx mario_low_poly_left_leg_shared_dl_vertex[] = {
    {{{     7,     47,     38}, 0, {     0,      0}, {0xcf, 0x59, 0x4b, 0x00}}},
    {{{    70,    -39,     53}, 0, {     0,      0}, {0xf8, 0x10, 0x7d, 0x00}}},
    {{{    75,     52,     42}, 0, {     0,      0}, {0xf4, 0x5e, 0x53, 0x00}}},
    {{{    75,     52,    -23}, 0, {     0,      0}, {0xf5, 0x72, 0xca, 0x00}}},
    {{{     7,     47,    -20}, 0, {     0,      0}, {0xab, 0x34, 0xb2, 0x00}}},
    {{{    71,    -39,    -34}, 0, {     0,      0}, {0xfa, 0x0f, 0x83, 0x00}}},
    {{{     3,    -29,    -29}, 0, {     0,      0}, {0xbb, 0xa4, 0xcd, 0x00}}},
    {{{     2,    -29,     48}, 0, {     0,      0}, {0x92, 0xdb, 0x31, 0x00}}},
    {{{    71,    -39,    -34}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    75,     52,    -23}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    70,    -39,     53}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    75,     52,     42}, 0, {     0,      0}, {0x7e, 0xfa, 0x01, 0x00}}},
    {{{    71,    -39,    -34}, 0, {     0,      0}, {0xed, 0x83, 0x00, 0x00}}},
    {{{    70,    -39,     53}, 0, {     0,      0}, {0xed, 0x83, 0x00, 0x00}}},
};

// 0x040174E8 - 0x04017558
const Gfx mario_low_poly_left_leg_shared_dl[] = {
    gsSPVertex(mario_low_poly_left_leg_shared_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  3,  5, 0x0,  5,  6,  4, 0x0),
    gsSP2Triangles( 3,  4,  0, 0x0,  0,  7,  1, 0x0),
    gsSP2Triangles( 7,  4,  6, 0x0,  7,  0,  4, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  9, 11, 10, 0x0),
    gsSP2Triangles( 6, 12, 13, 0x0, 13,  7,  6, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017558
static const Vtx mario_low_poly_left_foot_shared_dl_vertex[] = {
    {{{   110,     11,     56}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   109,     10,    -33}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   -50,     69,    -36}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{   -49,     70,     63}, 0, {     0,      0}, {0x2b, 0x77, 0xff, 0x00}}},
    {{{    74,    -39,     51}, 0, {     0,      0}, {0x13, 0xb0, 0x60, 0x00}}},
    {{{   110,     11,     56}, 0, {     0,      0}, {0x5b, 0xbb, 0x36, 0x00}}},
    {{{   -49,     70,     63}, 0, {     0,      0}, {0x00, 0xf4, 0x7e, 0x00}}},
    {{{    73,    -40,    -25}, 0, {     0,      0}, {0x18, 0x96, 0xc0, 0x00}}},
    {{{   -56,     20,    -30}, 0, {     0,      0}, {0xa4, 0xc5, 0xc2, 0x00}}},
    {{{   -50,     69,    -36}, 0, {     0,      0}, {0xfe, 0xf0, 0x83, 0x00}}},
    {{{   -54,     20,     58}, 0, {     0,      0}, {0x99, 0xc2, 0x26, 0x00}}},
    {{{   109,     10,    -33}, 0, {     0,      0}, {0x44, 0xc2, 0xaa, 0x00}}},
    {{{   -50,     69,    -36}, 0, {     0,      0}, {0x82, 0x0e, 0x01, 0x00}}},
    {{{   -49,     70,     63}, 0, {     0,      0}, {0x82, 0x0e, 0x01, 0x00}}},
};

// 0x04017638 - 0x040176A8
const Gfx mario_low_poly_left_foot_shared_dl[] = {
    gsSPVertex(mario_low_poly_left_foot_shared_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles(10,  4,  6, 0x0,  7,  9, 11, 0x0),
    gsSP2Triangles(12, 10, 13, 0x0,  7, 10,  8, 0x0),
    gsSP2Triangles( 7, 11,  5, 0x0,  5,  4,  7, 0x0),
    gsSP2Triangles( 7,  4, 10, 0x0, 12,  8, 10, 0x0),
    gsSPEndDisplayList(),
};

// 0x040176A8 - 0x040176C8
const Gfx mario_low_poly_left_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_left_foot_shared_dl),
    gsSPEndDisplayList(),
};

// 0x040176C8
static const Vtx mario_low_poly_right_thigh_shared_dl_vertex[] = {
    {{{   102,    -25,    -48}, 0, {     0,      0}, {0x64, 0xbf, 0xd5, 0x00}}},
    {{{   103,    -27,     25}, 0, {     0,      0}, {0x5c, 0xc9, 0x42, 0x00}}},
    {{{    25,    -45,     35}, 0, {     0,      0}, {0x1b, 0x85, 0xfd, 0x00}}},
    {{{    24,    -42,    -56}, 0, {     0,      0}, {0x1b, 0x85, 0xfd, 0x00}}},
    {{{    95,     50,    -36}, 0, {     0,      0}, {0x37, 0x42, 0xa3, 0x00}}},
    {{{    96,     49,     18}, 0, {     0,      0}, {0x4a, 0x4e, 0x41, 0x00}}},
    {{{    25,    -45,     35}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    17,     51,     27}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    15,     53,    -42}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    24,    -42,    -56}, 0, {     0,      0}, {0x82, 0xf5, 0x02, 0x00}}},
    {{{    24,    -42,    -56}, 0, {     0,      0}, {0x09, 0x13, 0x83, 0x00}}},
    {{{    15,     53,    -42}, 0, {     0,      0}, {0x07, 0x74, 0xce, 0x00}}},
    {{{    25,    -45,     35}, 0, {     0,      0}, {0x0d, 0x0c, 0x7d, 0x00}}},
    {{{    17,     51,     27}, 0, {     0,      0}, {0x0b, 0x5c, 0x55, 0x00}}},
};

// 0x040177A8 - 0x04017818
const Gfx mario_low_poly_right_thigh_shared_dl[] = {
    gsSPVertex(mario_low_poly_right_thigh_shared_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSP2Triangles( 0,  4,  5, 0x0,  0,  5,  1, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  6,  8,  9, 0x0),
    gsSP2Triangles( 4,  0, 10, 0x0,  5,  4, 11, 0x0),
    gsSP2Triangles(12,  1,  5, 0x0,  5, 13, 12, 0x0),
    gsSP2Triangles( 5, 11, 13, 0x0,  4, 10, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017818 - 0x04017838
const Gfx mario_low_poly_right_thigh[] = {
    gsSPLight(&mario_blue_lights_group.l, 1),
    gsSPLight(&mario_blue_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_right_thigh_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04017838
static const Vtx mario_low_poly_right_leg_shared_dl_vertex[] = {
    {{{     2,    -29,     27}, 0, {     0,      0}, {0xba, 0xa3, 0x31, 0x00}}},
    {{{     1,    -26,    -50}, 0, {     0,      0}, {0x91, 0xdd, 0xcf, 0x00}}},
    {{{    68,    -37,    -56}, 0, {     0,      0}, {0xec, 0x83, 0xfd, 0x00}}},
    {{{    70,    -40,     30}, 0, {     0,      0}, {0xec, 0x83, 0xfd, 0x00}}},
    {{{    68,    -37,    -56}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    74,     54,    -43}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    75,     52,     21}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{    70,    -40,     30}, 0, {     0,      0}, {0x7e, 0xf9, 0xfe, 0x00}}},
    {{{     6,     47,     19}, 0, {     0,      0}, {0xad, 0x33, 0x50, 0x00}}},
    {{{     6,     49,    -38}, 0, {     0,      0}, {0xcf, 0x5b, 0xb7, 0x00}}},
    {{{    68,    -37,    -56}, 0, {     0,      0}, {0xf8, 0x13, 0x83, 0x00}}},
    {{{    75,     52,     21}, 0, {     0,      0}, {0xf7, 0x71, 0x38, 0x00}}},
    {{{    70,    -40,     30}, 0, {     0,      0}, {0xfb, 0x0c, 0x7e, 0x00}}},
    {{{    74,     54,    -43}, 0, {     0,      0}, {0xf4, 0x60, 0xaf, 0x00}}},
};

// 0x04017918 - 0x04017988
const Gfx mario_low_poly_right_leg_shared_dl[] = {
    gsSPVertex(mario_low_poly_right_leg_shared_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  6,  7, 0x0),
    gsSP2Triangles( 8,  9,  1, 0x0,  0,  8,  1, 0x0),
    gsSP2Triangles(10,  1,  9, 0x0,  9,  8, 11, 0x0),
    gsSP2Triangles( 8,  0, 12, 0x0, 12, 11,  8, 0x0),
    gsSP2Triangles(11, 13,  9, 0x0, 13, 10,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017988
static const Vtx mario_low_poly_right_foot_dl_vertex[] = {
    {{{   -55,     19,    -59}, 0, {     0,      0}, {0x9a, 0xc0, 0xda, 0x00}}},
    {{{   -57,     20,     28}, 0, {     0,      0}, {0xa4, 0xc5, 0x3e, 0x00}}},
    {{{   -52,     69,     34}, 0, {     0,      0}, {0x82, 0x0c, 0xfd, 0x00}}},
    {{{    73,    -38,    -50}, 0, {     0,      0}, {0x15, 0xae, 0xa2, 0x00}}},
    {{{    71,    -37,     25}, 0, {     0,      0}, {0x19, 0x98, 0x42, 0x00}}},
    {{{   108,     12,    -55}, 0, {     0,      0}, {0x5c, 0xbc, 0xcc, 0x00}}},
    {{{   106,     13,     33}, 0, {     0,      0}, {0x44, 0xc5, 0x58, 0x00}}},
    {{{   -50,     68,    -65}, 0, {     0,      0}, {0x82, 0x0c, 0xfd, 0x00}}},
    {{{   -52,     69,     34}, 0, {     0,      0}, {0xfd, 0xf2, 0x7e, 0x00}}},
    {{{   -50,     68,    -65}, 0, {     0,      0}, {0x02, 0xf2, 0x82, 0x00}}},
    {{{   -52,     69,     34}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   108,     12,    -55}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   -50,     68,    -65}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
    {{{   106,     13,     33}, 0, {     0,      0}, {0x29, 0x77, 0x00, 0x00}}},
};

// 0x04017A68 - 0x04017AD8
const Gfx mario_low_poly_right_foot_dl[] = {
    gsSPVertex(mario_low_poly_right_foot_dl_vertex, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  4, 0x0),
    gsSP2Triangles( 4,  3,  5, 0x0,  5,  6,  4, 0x0),
    gsSP2Triangles( 1,  0,  4, 0x0,  7,  0,  2, 0x0),
    gsSP2Triangles( 6,  8,  4, 0x0,  9,  3,  0, 0x0),
    gsSP2Triangles( 8,  1,  4, 0x0,  9,  5,  3, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0, 10, 13, 11, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017AD8 - 0x04017B18
const Gfx mario_low_poly_right_foot[] = {
    gsSPLight(&mario_brown1_lights_group.l, 1),
    gsSPLight(&mario_brown1_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_right_foot_dl),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

Gfx mat_mario_wing_2_v3_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mario_wing_2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

// 0x04017B58
static const Vtx mario_seg4_vertex_04017B58[] = {
    {{{   -28,     41,    -88}, 0, {  -396,   1646}, {0xb7, 0x31, 0xa5, 0xff}}},
    {{{     0,     98,      0}, 0, {  1968,    722}, {0xf0, 0x7d, 0x00, 0xff}}},
    {{{    35,     64,    -82}, 0, {  -390,    132}, {0x29, 0x4b, 0xa3, 0xff}}},
    {{{    39,     90,      0}, 0, {  1698,   -280}, {0x4a, 0x67, 0x00, 0xff}}},
    {{{   -28,     41,     89}, 0, {  1610,   1512}, {0xd1, 0x37, 0x67, 0xff}}},
    {{{    35,     64,     83}, 0, {  1070,    -68}, {0x29, 0x4b, 0x5d, 0xff}}},
    {{{     0,     98,      0}, 0, { -1064,    968}, {0xf0, 0x7d, 0x00, 0xff}}},
    {{{    39,     90,      0}, 0, { -1146,   -124}, {0x4a, 0x67, 0x00, 0xff}}},
};

// 0x04017BD8
static const Vtx mario_seg4_vertex_04017BD8[] = {
    {{{   -28,    -71,     81}, 0, {     0,      0}, {0x9a, 0xbd, 0x20, 0xff}}},
    {{{   -28,     41,    -88}, 0, {     0,      0}, {0xb7, 0x31, 0xa5, 0xff}}},
    {{{   -28,    -71,    -80}, 0, {     0,      0}, {0xb7, 0xb5, 0xba, 0xff}}},
    {{{    39,    -79,    -73}, 0, {     0,      0}, {0x27, 0xb3, 0xa4, 0xff}}},
    {{{   -28,     41,     89}, 0, {     0,      0}, {0xd1, 0x37, 0x67, 0xff}}},
    {{{   -28,     89,      0}, 0, {     0,      0}, {0x97, 0x46, 0x00, 0xff}}},
    {{{    39,    -79,     74}, 0, {     0,      0}, {0x37, 0xba, 0x59, 0xff}}},
    {{{    35,     64,     83}, 0, {     0,      0}, {0x29, 0x4b, 0x5d, 0xff}}},
    {{{     0,     98,      0}, 0, {     0,      0}, {0xf0, 0x7d, 0x00, 0xff}}},
    {{{    35,     64,    -82}, 0, {     0,      0}, {0x29, 0x4b, 0xa3, 0xff}}},
    {{{    89,    -45,    -42}, 0, {     0,      0}, {0x70, 0xd0, 0xdf, 0xff}}},
    {{{    89,    -45,     43}, 0, {     0,      0}, {0x75, 0xe4, 0x28, 0xff}}},
    {{{    74,     26,    -59}, 0, {     0,      0}, {0x61, 0x25, 0xb9, 0xff}}},
    {{{    39,     90,      0}, 0, {     0,      0}, {0x4a, 0x67, 0x00, 0xff}}},
    {{{    74,     26,     60}, 0, {     0,      0}, {0x61, 0x25, 0x47, 0xff}}},
};

// 0x04017CC8
static const Vtx mario_seg4_vertex_04017CC8[] = {
    {{{    74,     26,     60}, 0, {     0,      0}, {0x61, 0x25, 0x47, 0xff}}},
    {{{    87,     42,      0}, 0, {     0,      0}, {0x76, 0x2d, 0x00, 0xff}}},
    {{{    39,     90,      0}, 0, {     0,      0}, {0x4a, 0x67, 0x00, 0xff}}},
    {{{    39,    -79,    -73}, 0, {     0,      0}, {0x27, 0xb3, 0xa4, 0xff}}},
    {{{    35,     64,    -82}, 0, {     0,      0}, {0x29, 0x4b, 0xa3, 0xff}}},
    {{{    74,     26,    -59}, 0, {     0,      0}, {0x61, 0x25, 0xb9, 0xff}}},
    {{{    89,    -45,    -42}, 0, {     0,      0}, {0x70, 0xd0, 0xdf, 0xff}}},
    {{{    39,    -79,     74}, 0, {     0,      0}, {0x37, 0xba, 0x59, 0xff}}},
    {{{    89,    -45,     43}, 0, {     0,      0}, {0x75, 0xe4, 0x28, 0xff}}},
    {{{    35,     64,     83}, 0, {     0,      0}, {0x29, 0x4b, 0x5d, 0xff}}},
};

// 0x04017D68 - 0x04017D98
const Gfx mario_low_poly_yellow_button_dl[] = {
    gsSPVertex(mario_seg4_vertex_04017B58, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  2,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  6,  5,  7, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017D98 - 0x04017E20
const Gfx mario_low_poly_pants_overalls_shared_dl[] = {
    gsSPVertex(mario_seg4_vertex_04017BD8, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 0,  4,  5, 0x0,  3,  6,  0, 0x0),
    gsSP2Triangles( 4,  0,  6, 0x0,  0,  5,  1, 0x0),
    gsSP2Triangles( 7,  4,  6, 0x0,  5,  4,  8, 0x0),
    gsSP2Triangles( 8,  1,  5, 0x0,  3,  1,  9, 0x0),
    gsSP2Triangles( 3,  2,  1, 0x0,  6,  3, 10, 0x0),
    gsSP2Triangles(10, 11,  6, 0x0, 12,  9, 13, 0x0),
    gsSP1Triangle(13,  7, 14, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017E20 - 0x04017E78
const Gfx mario_low_poly_tshirt_shared_dl[] = {
    gsSPVertex(mario_seg4_vertex_04017CC8, 10, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 5,  6,  3, 0x0,  2,  1,  5, 0x0),
    gsSP2Triangles( 6,  5,  1, 0x0,  7,  8,  0, 0x0),
    gsSP2Triangles( 7,  0,  9, 0x0,  8,  6,  1, 0x0),
    gsSP1Triangle( 1,  0,  8, 0x0),
    gsSPEndDisplayList(),
};

// 0x04017E78 - 0x04017EA0
const Gfx mario_low_poly_torso_dl[] = {
    gsSPDisplayList(mario_low_poly_pants_overalls_shared_dl),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_tshirt_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04017EA0 - 0x04017F20
const Gfx mario_low_poly_torso[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_yellow_button),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_yellow_button_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_torso_dl),
    gsSPEndDisplayList(),
};

// 0x04017F20 - 0x04017F40
const Gfx mario_metal_low_poly_torso[] = {
    gsSPDisplayList(mario_low_poly_yellow_button_dl),
    gsSPDisplayList(mario_low_poly_pants_overalls_shared_dl),
    gsSPDisplayList(mario_low_poly_tshirt_shared_dl),
    gsSPEndDisplayList(),
};

// 0x04017F40
static const Vtx mario_low_poly_mario_m_logo_dl_vertex[] = {
    {{{   272,     48,     53}, 0, {   904,      0}, {0x42, 0x51, 0x47, 0xff}}},
    {{{   174,     79,     -9}, 0, {   452,    816}, {0x51, 0x61, 0xfa, 0xff}}},
    {{{   146,     27,     92}, 0, {  1238,    962}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{   272,     48,    -52}, 0, {    -2,      0}, {0x62, 0x27, 0xba, 0xff}}},
    {{{   146,     27,    -91}, 0, {  -334,    962}, {0x03, 0x39, 0x8f, 0xff}}},
};

// 0x04017F90
static const Vtx mario_low_poly_eyes_cap_on_dl_vertex[] = {
    {{{   146,     27,     92}, 0, {  1316,    212}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{   168,     79,      0}, 0, {   458,     68}, {0xd9, 0x78, 0x00, 0xff}}},
    {{{    88,    101,     33}, 0, {   762,    990}, {0x38, 0x55, 0x4b, 0xff}}},
    {{{    88,    101,    -32}, 0, {   154,    990}, {0x1e, 0x5d, 0xb1, 0xff}}},
    {{{   146,     27,    -91}, 0, {  -398,    212}, {0x03, 0x39, 0x8f, 0xff}}},
};

// 0x04017FE0
static const Vtx mario_low_poly_mustache_cap_on_dl_vertex[] = {
    {{{    88,    101,    -32}, 0, {   398,    214}, {0x1e, 0x5d, 0xb1, 0xff}}},
    {{{   146,     27,    -91}, 0, {  1408,   -550}, {0x03, 0x39, 0x8f, 0xff}}},
    {{{    34,     39,    -98}, 0, {  1306,    732}, {0xcd, 0x40, 0xa0, 0xff}}},
    {{{    44,    113,      0}, 0, {    10,    800}, {0x9c, 0x4d, 0x00, 0xff}}},
    {{{    -5,     58,      0}, 0, {   300,   1456}, {0x88, 0x28, 0x00, 0xff}}},
    {{{    88,    101,     33}, 0, {   294,    258}, {0x38, 0x55, 0x4b, 0xff}}},
    {{{    44,    113,      0}, 0, {    34,    840}, {0x9c, 0x4d, 0x00, 0xff}}},
    {{{    34,     39,     99}, 0, {  1314,    634}, {0xcd, 0x40, 0x60, 0xff}}},
    {{{   146,     27,     92}, 0, {  1132,   -556}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{    -5,     58,      0}, 0, {   470,   1412}, {0x88, 0x28, 0x00, 0xff}}},
};

// 0x04018080
static const Vtx mario_low_poly_face_cap_dl_vertex[] = {
    {{{   272,     48,    -52}, 0, {     0,      0}, {0x62, 0x27, 0xba, 0xff}}},
    {{{   272,     48,     53}, 0, {     0,      0}, {0x42, 0x51, 0x47, 0xff}}},
    {{{   149,    -87,    138}, 0, {     0,      0}, {0x43, 0xb6, 0x4d, 0xff}}},
    {{{   146,     27,    -91}, 0, {     0,      0}, {0x03, 0x39, 0x8f, 0xff}}},
    {{{   149,    -87,   -137}, 0, {     0,      0}, {0x33, 0xc2, 0x9f, 0xff}}},
    {{{   146,     27,     92}, 0, {     0,      0}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{    58,   -114,     81}, 0, {     0,      0}, {0xba, 0xad, 0x40, 0xff}}},
    {{{    98,   -165,      0}, 0, {     0,      0}, {0xfd, 0x82, 0x00, 0xff}}},
    {{{    58,   -114,    -80}, 0, {     0,      0}, {0xbc, 0xb8, 0xb2, 0xff}}},
    {{{   168,     79,      0}, 0, {     0,      0}, {0xd9, 0x78, 0x00, 0xff}}},
    {{{   175,    154,      0}, 0, {     0,      0}, {0xe1, 0x6c, 0xc6, 0xff}}},
    {{{   174,     79,     -9}, 0, {     0,      0}, {0x51, 0x61, 0xfa, 0xff}}},
};

// 0x04018140
static const Vtx mario_low_poly_face_part_cap_on_dl_vertex[] = {
    {{{    94,    146,     33}, 0, {     0,      0}, {0xff, 0x44, 0x6b, 0xff}}},
    {{{    50,    153,      0}, 0, {     0,      0}, {0xad, 0x5f, 0x00, 0xff}}},
    {{{    44,    113,      0}, 0, {     0,      0}, {0x9c, 0x4d, 0x00, 0xff}}},
    {{{    88,    101,     33}, 0, {     0,      0}, {0x38, 0x55, 0x4b, 0xff}}},
    {{{    94,    146,    -32}, 0, {     0,      0}, {0x3b, 0x35, 0x9e, 0xff}}},
    {{{    88,    101,    -32}, 0, {     0,      0}, {0x1e, 0x5d, 0xb1, 0xff}}},
    {{{    34,     39,     99}, 0, {     0,      0}, {0xcd, 0x40, 0x60, 0xff}}},
    {{{    -5,     58,      0}, 0, {     0,      0}, {0x88, 0x28, 0x00, 0xff}}},
    {{{     7,    -85,     79}, 0, {     0,      0}, {0xaa, 0xdc, 0x54, 0xff}}},
    {{{   146,     27,     92}, 0, {     0,      0}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{     7,    -85,    -78}, 0, {     0,      0}, {0xa9, 0xc7, 0xb9, 0xff}}},
    {{{    34,     39,    -98}, 0, {     0,      0}, {0xcd, 0x40, 0xa0, 0xff}}},
    {{{   146,     27,    -91}, 0, {     0,      0}, {0x03, 0x39, 0x8f, 0xff}}},
};

// 0x04018210
static const Vtx mario_low_poly_face_back_hair_cap_on_dl_vertex[] = {
    {{{    58,   -114,     81}, 0, {     0,      0}, {0xba, 0xad, 0x40, 0xff}}},
    {{{     7,    -85,     79}, 0, {     0,      0}, {0xaa, 0xdc, 0x54, 0xff}}},
    {{{     7,    -85,    -78}, 0, {     0,      0}, {0xa9, 0xc7, 0xb9, 0xff}}},
    {{{    58,   -114,    -80}, 0, {     0,      0}, {0xbc, 0xb8, 0xb2, 0xff}}},
    {{{   146,     27,     92}, 0, {     0,      0}, {0x03, 0x3a, 0x70, 0xff}}},
    {{{   146,     27,    -91}, 0, {     0,      0}, {0x03, 0x39, 0x8f, 0xff}}},
};

// 0x04018270 - 0x04018298
const Gfx mario_low_poly_mario_m_logo_dl[] = {
    gsSPVertex(mario_low_poly_mario_m_logo_dl_vertex, 5, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP1Triangle( 3,  1,  0, 0x0),
    gsSPEndDisplayList(),
};

// 0x04018298 - 0x040182C0
const Gfx mario_low_poly_eyes_cap_on_dl[] = {
    gsSPVertex(mario_low_poly_eyes_cap_on_dl_vertex, 5, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  1,  4, 0x0),
    gsSP1Triangle( 3,  2,  1, 0x0),
    gsSPEndDisplayList(),
};

// 0x040182C0 - 0x04018300
const Gfx mario_low_poly_mustache_cap_on_dl[] = {
    gsSPVertex(mario_low_poly_mustache_cap_on_dl_vertex, 10, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 2,  4,  3, 0x0,  5,  6,  7, 0x0),
    gsSP2Triangles( 7,  8,  5, 0x0,  6,  9,  7, 0x0),
    gsSPEndDisplayList(),
};

// 0x04018300 - 0x04018370
const Gfx mario_low_poly_face_part_cap_on_dl[] = {
    gsSPVertex(mario_low_poly_face_part_cap_on_dl_vertex, 13, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
    gsSP2Triangles( 2,  1,  4, 0x0,  2,  4,  5, 0x0),
    gsSP2Triangles( 4,  1,  0, 0x0,  4,  0,  3, 0x0),
    gsSP2Triangles( 5,  4,  3, 0x0,  6,  7,  8, 0x0),
    gsSP2Triangles( 9,  6,  8, 0x0,  8,  7, 10, 0x0),
    gsSP2Triangles(10,  7, 11, 0x0, 10, 11, 12, 0x0),
    gsSPEndDisplayList(),
};

// 0x04018370 - 0x040183F0
const Gfx mario_low_poly_face_cap_dl[] = {
    gsSPVertex(mario_low_poly_face_cap_dl_vertex, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles( 4,  0,  2, 0x0,  2,  1,  5, 0x0),
    gsSP2Triangles( 6,  2,  5, 0x0,  6,  7,  2, 0x0),
    gsSP2Triangles( 7,  4,  2, 0x0,  3,  4,  8, 0x0),
    gsSP2Triangles( 4,  7,  8, 0x0,  9, 10,  3, 0x0),
    gsSP2Triangles(10, 11,  3, 0x0,  8,  7,  6, 0x0),
    gsSP2Triangles(10,  5, 11, 0x0, 10,  9,  5, 0x0),
    gsSPEndDisplayList(),
};

// 0x040183F0 - 0x04018420
const Gfx mario_low_poly_face_back_hair_cap_on_dl[] = {
    gsSPVertex(mario_low_poly_face_back_hair_cap_on_dl_vertex, 6, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  1,  0, 0x0,  3,  2,  5, 0x0),
    gsSPEndDisplayList(),
};

// 0x04018420 - 0x04018460
const Gfx mario_low_poly_face_cap_on_dl[] = {
    gsSPDisplayList(mario_low_poly_face_part_cap_on_dl),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_face_cap_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_face_back_hair_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018460 - 0x04018530
const Gfx mario_low_poly_cap_on_eyes_front[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_front),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018530 - 0x04018600
const Gfx mario_low_poly_cap_on_eyes_half_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_half_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018600 - 0x040186D0
const Gfx mario_low_poly_cap_on_eyes_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x040186D0 - 0x040187A0
const Gfx mario_low_poly_cap_on_eyes_right[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_right),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x040187A0 - 0x04018870
const Gfx mario_low_poly_cap_on_eyes_left[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_left),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018870 - 0x04018940
const Gfx mario_low_poly_cap_on_eyes_up[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_up),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018940 - 0x04018A10
const Gfx mario_low_poly_cap_on_eyes_down[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_down),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

// 0x04018A10 - 0x04018AE0
const Gfx mario_low_poly_cap_on_eyes_dead[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mario_m_logo_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_dead),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_eyes_cap_on_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_on_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_on_dl),
    gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_face_0___eye_open_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_mario_mustache_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_mario_hair_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_mario_sideburns_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_4),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_2),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_3),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_4),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_mesh_layer_1_mat_override_face_1___eye_half_v3_001_1[] = {
	gsSPDisplayList(mat_mario_face_1___eye_half_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_mario_mustache_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_mario_hair_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_mario_sideburns_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_4),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_mesh_layer_1_mat_override_face_2___eye_closed_v3_001_2[] = {
	gsSPDisplayList(mat_mario_face_2___eye_closed_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_mario_mustache_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_mario_hair_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_mario_sideburns_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_4),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_mesh_layer_1_mat_override_face_7___eye_X_v3_001_3[] = {
	gsSPDisplayList(mat_mario_face_7___eye_X_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_mario_mustache_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_mario_hair_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_mario_sideburns_v3_001),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_000_displaylist_mesh_layer_1_tri_4),
	gsSPEndDisplayList(),
};

// 0x04018F68 - 0x04018F90
const Gfx mario_low_poly_face_cap_off_dl[] = {
    gsSPDisplayList(mario_low_poly_face_part_cap_off_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_face_hair_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04018F90 - 0x04019040
const Gfx mario_low_poly_cap_off_eyes_front[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_front),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04019040 - 0x040190F0
const Gfx mario_low_poly_cap_off_eyes_half_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_half_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x040190F0 - 0x040191A0
const Gfx mario_low_poly_cap_off_eyes_closed[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_closed),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x040191A0 - 0x04019250
const Gfx mario_low_poly_cap_off_eyes_right[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_right),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04019250 - 0x04019300
const Gfx mario_low_poly_cap_off_eyes_left[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_left),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04019300 - 0x040193B0
const Gfx mario_low_poly_cap_off_eyes_up[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_up),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x040193B0 - 0x04019460
const Gfx mario_low_poly_cap_off_eyes_down[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_down),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

// 0x04019460 - 0x04019510
const Gfx mario_low_poly_cap_off_eyes_dead[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBFADEA, G_CC_BLENDRGBFADEA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_eyes_dead),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_beige_lights_group.l, 1),
    gsSPLight(&mario_beige_lights_group.a, 2),
    gsSPDisplayList(mario_low_poly_mario_eyes_cap_off_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_mustache),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_low_poly_mustache_cap_off_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPDisplayList(mario_low_poly_face_cap_off_dl),
    gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_002_mesh_layer_4[] = {
	gsSPDisplayList(mat_mario_wing_2_v3_001),
	gsSPDisplayList(mario_000_displaylist_002_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mario_wing_2_v3_001),
	gsSPDisplayList(mat_mario_wing_1_v3_001),
	gsSPDisplayList(mario_000_displaylist_002_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mario_wing_1_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_002_mesh_layer_4_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_wing_2_v3_001),
	gsSPDisplayList(mario_000_displaylist_002_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mario_wing_2_v3_001),
	gsSPDisplayList(mat_mario_wing_1_v3_001),
	gsSPDisplayList(mario_000_displaylist_002_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mario_wing_1_v3_001),
	gsSPEndDisplayList(),
};

// 0x04019CA0 - 0x04019CC0
const Gfx mario_left_hand_open[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_left_hand_open_shared_dl),
    gsSPEndDisplayList(),
};

Gfx mario_000_offset_003_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_offset_003_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

// 0x0401A428 - 0x0401A448
const Gfx mario_right_hand_open[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_right_hand_open_dl),
    gsSPEndDisplayList(),
};

Gfx mario_000_offset_004_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_offset_004_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_003_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_000_displaylist_003_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_003_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_displaylist_003_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_002_switch_option_right_hand_open_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_002_switch_option_right_hand_open_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_002_switch_option_right_hand_open_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_002_switch_option_right_hand_open_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

// 0x0401AF20 - 0x0401AF60
const Gfx mario_right_hand_cap_dl[] = {
    gsSPDisplayList(mario_right_hand_cap_top_dl),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_right_hand_cap_hand_position_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_right_hand_cap_bottom_dl),
    gsSPEndDisplayList(),
};

Gfx mario_000_offset_006_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_offset_006_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_offset_007_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_000_offset_007_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

// 0x0401B0E0 - 0x0401B138
const Gfx mario_right_hand_cap_wings_initial_dl[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_004_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_000_displaylist_004_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_000_displaylist_004_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_displaylist_004_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_002_switch_option_left_hand_open_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_002_switch_option_left_hand_open_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_002_switch_option_left_hand_open_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_002_switch_option_left_hand_open_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_004_switch_option_left_hand_peace_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_004_switch_option_left_hand_peace_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_004_switch_option_left_hand_peace_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_004_switch_option_left_hand_peace_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

// 0x0401BF30 - 0x0401BF50
const Gfx mario_right_hand_peace[] = {
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_right_hand_peace_shared_dl),
    gsSPEndDisplayList(),
};

Gfx mario_005_switch_option_left_hand_cap_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_005_switch_option_left_hand_cap_mesh_layer_1_tri_0),
	gsSPDisplayList(mario_005_switch_option_left_hand_cap_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_006_switch_option_left_hand_wing_cap_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_cap_v3),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_mario_gloves_v3_001),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_tri_0),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

// 0x0401C510 - 0x0401C538
const Gfx mario_cap_unused_base_dl[] = {
    gsSPDisplayList(mario_cap_unused_base_top_dl),
    gsSPLight(&mario_brown2_lights_group.l, 1),
    gsSPLight(&mario_brown2_lights_group.a, 2),
    gsSPDisplayList(mario_cap_unused_base_bottom_dl),
    gsSPEndDisplayList(),
};

Gfx mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_wing_2_v3_001),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mario_wing_2_v3_001),
	gsSPDisplayList(mat_mario_wing_1_v3_001),
	gsSPDisplayList(mario_006_switch_option_left_hand_wing_cap_wings_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mario_wing_1_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_offset_009_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_body_v3),
	gsSPDisplayList(mario_000_offset_009_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

// 0x0401C6D8 - 0x0401C730
const Gfx mario_cap_wings_unused_initial_dl[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPEndDisplayList(),
};

Gfx mario_000_offset_010_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_body_v3),
	gsSPDisplayList(mario_000_offset_010_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

// 0x0401C758 - 0x0401C7E8 # Unreferenced, possibly a early duplicate of the cap object used in segment 03
const Gfx mario_cap_unused_dl[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_BLENDRGBA, G_CC_BLENDRGBA),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_m_logo),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&mario_red_lights_group.l, 1),
    gsSPLight(&mario_red_lights_group.a, 2),
    gsSPDisplayList(mario_cap_unused_m_logo_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPDisplayList(mario_cap_unused_base_dl),
    gsSPEndDisplayList(),
};

// 0x0401C7E8 - 0x0401C890 # Unreferenced, possibly an early duplicate of the cap object used in segment 03
const Gfx mario_metal_cap_unused_dl[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsSPDisplayList(mario_cap_unused_m_logo_dl),
    gsSPDisplayList(mario_cap_unused_base_top_dl),
    gsSPDisplayList(mario_cap_unused_base_bottom_dl),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

Gfx mario_000_offset_011_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_offset_011_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_offset_012_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_body_v3),
	gsSPDisplayList(mario_000_offset_012_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx mario_000_offset_012_mesh_layer_1_mat_override_metal_v3_001_0[] = {
	gsSPDisplayList(mat_mario_metal_v3_001),
	gsSPDisplayList(mario_000_offset_012_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_mario_metal_v3_001),
	gsSPEndDisplayList(),
};

Gfx mario_000_offset_013_mesh_layer_1[] = {
	gsSPDisplayList(mat_mario_body_v3),
	gsSPDisplayList(mario_000_offset_013_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

// 0x0401CA00 - 0x0401CAB8
const Gfx mario_cap_wings[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x0401CAB8 - 0x0401CB70
const Gfx mario_cap_wings_transparent[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALFADEA, G_CC_DECALFADEA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x0401CB70 - 0x0401CC28
const Gfx mario_metal_cap_wings[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPLight(&mario_white_lights_group.l, 1),
    gsSPLight(&mario_white_lights_group.a, 2),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_metal_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_metal_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x0401CC28 - 0x0401CD20
const Gfx mario_metal_cap_wings_transparent[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_DECALFADEA, G_CC_DECALFADEA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_metal_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mario_texture_metal_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN | G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(mario_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};


Gfx ring_fragment_fragment_ci8_aligner[] = {gsSPEndDisplayList()};
u8 ring_fragment_fragment_ci8[] = {
	0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 
	0x00, 0x02, 0x03, 0x04, 0x02, 0x00, 0x00, 0x00, 
	0x05, 0x06, 0x07, 0x02, 0x02, 0x01, 0x00, 0x02, 
	0x02, 0x04, 0x03, 0x03, 0x04, 0x02, 0x04, 0x02, 
	0x03, 0x04, 0x04, 0x08, 0x04, 0x09, 0x0a, 0x0a, 
	0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0b, 0x0b, 0x09, 
	0x03, 0x03, 0x03, 0x04, 0x0b, 0x0e, 0x0f, 0x10, 
	0x0d, 0x0b, 0x03, 0x11, 0x0b, 0x0b, 0x0b, 0x03, 
	0x09, 0x0b, 0x03, 0x12, 0x04, 0x0b, 0x0b, 0x03, 
	0x03, 0x12, 0x12, 0x12, 0x12, 0x12, 0x03, 0x03, 
	0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x12, 0x12, 
	0x04, 0x03, 0x03, 0x03, 0x11, 0x0b, 0x0d, 0x09, 
	0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x02, 
	0x04, 0x09, 0x0a, 0x0d, 0x0b, 0x0b, 0x0a, 0x04, 
	0x03, 0x03, 0x09, 0x13, 0x04, 0x04, 0x02, 0x02, 
	0x02, 0x13, 0x13, 0x13, 0x04, 0x12, 0x04, 0x02, 
	
};

Gfx ring_fragment_fragment_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 ring_fragment_fragment_pal_rgba16[] = {
	0x9d, 0x3f, 0x9c, 0xff, 0xa5, 0x3f, 0xb5, 0x3f, 
	0xad, 0x3f, 0xb5, 0xbf, 0xad, 0xbf, 0xa5, 0x7f, 
	0xa4, 0xff, 0xb5, 0x7f, 0xbd, 0xbf, 0xbd, 0x7f, 
	0xc5, 0x7f, 0xc5, 0xbf, 0xd5, 0xff, 0xd6, 0x3f, 
	0xcd, 0xff, 0xbd, 0x3f, 0xac, 0xff, 0xad, 0x7f, 
	
};

Vtx ring_fragment_Plane_mesh_layer_1_vtx_0[6] = {
	{{ {0, -106, 0}, 0, {240, 240}, {0, 0, 127, 255} }},
	{{ {4, -100, 0}, 0, {496, 240}, {0, 0, 127, 255} }},
	{{ {4, 100, 0}, 0, {496, -16}, {0, 0, 127, 255} }},
	{{ {0, 106, 0}, 0, {240, -16}, {0, 0, 127, 255} }},
	{{ {-4, -100, 0}, 0, {-16, 240}, {0, 0, 127, 255} }},
	{{ {-4, 100, 0}, 0, {-16, -16}, {0, 0, 127, 255} }},
};

Gfx ring_fragment_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(ring_fragment_Plane_mesh_layer_1_vtx_0 + 0, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_ring_fragment_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ring_fragment_fragment_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 19),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, ring_fragment_fragment_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 63, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 3, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 28),
	gsSPEndDisplayList(),
};

Gfx mat_revert_ring_fragment_f3dlite_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx ring_fragment_Plane_mesh_layer_1[] = {
	gsSPDisplayList(mat_ring_fragment_f3dlite_material),
	gsSPDisplayList(ring_fragment_Plane_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_ring_fragment_f3dlite_material),
	gsSPEndDisplayList(),
};

Gfx ring_fragment_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


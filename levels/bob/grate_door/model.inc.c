// 0x0700E810 - 0x0700E860
static const Vtx bob_seg7_vertex_0700E810[] = {
    {{{     0,    384,      0}, 0, { -1956,  -2076}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   320,    640,      0}, 0, {   598,  -4120}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   128,    640,      0}, 0, {  -934,  -4120}, {0xff, 0xff, 0xff, 0xff}}},
    {{{     0,      0,      0}, 0, { -1956,    990}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   320,      0,      0}, 0, {   598,    990}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x0700E860 - 0x0700E8A0
static const Gfx bob_seg7_dl_0700E860[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, generic_09008800),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(bob_seg7_vertex_0700E810, 5, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  4, 0x0),
    gsSP1Triangle( 0,  4,  1, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700E8A0 - 0x0700E958
const Gfx bob_seg7_dl_0700E8A0[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPClearGeometryMode(G_LIGHTING | G_CULL_BACK),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(bob_seg7_dl_0700E860),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
    gsSPSetGeometryMode(G_LIGHTING | G_CULL_BACK),
    gsSPEndDisplayList(),
};

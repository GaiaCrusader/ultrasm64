// 0x0700AEF0 - 0x0700AF08

// 0x0700AF08 - 0x0700AF58
static const Vtx jrb_seg7_vertex_0700AF08[] = {
    {{{   102,      0,   -101}, 0, {  2012,  -1054}, {0x33, 0x67, 0xcc, 0xff}}},
    {{{     0,    102,      0}, 0, {   992,      0}, {0x00, 0x7e, 0x00, 0xff}}},
    {{{   102,      0,    102}, 0, {  2012,    990}, {0x33, 0x67, 0x33, 0xff}}},
    {{{  -101,      0,   -101}, 0, {     0,  -1054}, {0xcc, 0x67, 0xcc, 0xff}}},
    {{{  -101,      0,    102}, 0, {     0,    990}, {0xcc, 0x67, 0x33, 0xff}}},
};

// 0x0700AF58 - 0x0700AFB0
static const Gfx jrb_seg7_dl_0700AF58[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, water_09001800),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x3f3f3fff),
    gsSPVertex(jrb_seg7_vertex_0700AF08, 5, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  1, 0x0),
    gsSP2Triangles( 2,  1,  4, 0x0,  1,  0,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700AFB0 - 0x0700B058
const Gfx jrb_seg7_dl_0700AFB0[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(jrb_seg7_dl_0700AF58),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
    gsSPEndDisplayList(),
};

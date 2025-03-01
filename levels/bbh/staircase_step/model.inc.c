// 0x0701F0E0 - 0x0701F0F8

// 0x0701F0F8 - 0x0701F138
static const Vtx bbh_seg7_vertex_0701F0F8[] = {
    {{{   154,    614,   -101}, 0, {  3034,   2010}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -153,    614,   -101}, 0, { -3096,   2010}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -153,    614,    102}, 0, { -3096,   6098}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   154,    614,    102}, 0, {  3034,   6098}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0701F138 - 0x0701F238
static const Vtx bbh_seg7_vertex_0701F138[] = {
    {{{   154,      0,   -101}, 0, {   990,   2012}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -153,      0,   -101}, 0, {     0,   2012}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   154,    614,   -101}, 0, {   990,      0}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   154,    614,    102}, 0, {   990,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -153,      0,    102}, 0, {     0,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   154,      0,    102}, 0, {   990,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -153,    614,    102}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -153,      0,   -101}, 0, {   308,   2012}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,    614,    102}, 0, {   990,      0}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,    614,   -101}, 0, {   308,      0}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,      0,    102}, 0, {   990,   2012}, {0x81, 0x00, 0x00, 0xff}}},
    {{{   154,      0,   -101}, 0, {   308,   2012}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,    614,   -101}, 0, {   308,      0}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,    614,    102}, 0, {   990,      0}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,      0,    102}, 0, {   990,   2012}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{  -153,    614,   -101}, 0, {     0,      0}, {0x00, 0x00, 0x81, 0xff}}},
};

// 0x0701F238 - 0x0701F280
static const Gfx bbh_seg7_dl_0701F238[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, spooky_0900A000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x666666ff),
    gsSPVertex(bbh_seg7_vertex_0701F0F8, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x0701F280 - 0x0701F2E8
static const Gfx bbh_seg7_dl_0701F280[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, spooky_09005000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(bbh_seg7_vertex_0701F138, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 3,  6,  4, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 7, 10,  8, 0x0, 11, 12, 13, 0x0),
    gsSP2Triangles(11, 13, 14, 0x0,  1, 15,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x0701F2E8 - 0x0701F378
const Gfx bbh_seg7_dl_0701F2E8[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(bbh_seg7_dl_0701F238),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(bbh_seg7_dl_0701F280),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
